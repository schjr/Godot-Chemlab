class_name OriginalX87
extends RefCounted
## x87 precision-control=64 arithmetic for the original finite thermal operands.
## A high/low binary64 expansion retains the extra 11 significand bits until a
## native qword store. This is arithmetic compatibility, not replacement physics.
## Scaled expansions retain subnormal binary64 operands without premature underflow.
## Unsupported extended overflow/range returns an empty result.

const SPLITTER: float = 134217729.0 # 2^27 + 1, error-free binary64 product split.

static func _sum(a: float, b: float) -> Array:
	var value: float = a + b
	if not is_finite(value): return []
	var virtual_b: float = value - a
	var error: float = (a - (value - virtual_b)) + (b - virtual_b)
	return [value, error]

static func _split(value: float) -> Array:
	var expanded: float = SPLITTER * value
	if not is_finite(expanded): return []
	var high: float = expanded - (expanded - value)
	return [high, value - high]

static func _product(a: float, b: float) -> Array:
	var value: float = a * b
	if not is_finite(value): return []
	if value == 0.0 and a != 0.0 and b != 0.0: return []
	var aa: Array = _split(a)
	var bb: Array = _split(b)
	if aa.is_empty() or bb.is_empty(): return []
	var error: float = ((float(aa[0]) * float(bb[0]) - value) + float(aa[0]) * float(bb[1]) + float(aa[1]) * float(bb[0])) + float(aa[1]) * float(bb[1])
	return [value, error]

static func _round64(pair: Array) -> Array:
	if pair.is_empty(): return []
	var high: float = float(pair[0])
	var low: float = float(pair[1])
	if high == 0.0: return [high, low]
	var bits: PackedByteArray = PackedFloat64Array([absf(high)]).to_byte_array()
	var encoded_exponent: int = ((int(bits[7]) & 127) << 4) | (int(bits[6]) >> 4)
	if encoded_exponent == 0: return []
	var exponent: int = encoded_exponent - 1023
	var mantissa_zero: bool = (int(bits[6]) & 15) == 0
	for i in 6:
		if bits[i] != 0: mantissa_zero = false
	if mantissa_zero and ((high > 0.0 and low < 0.0) or (high < 0.0 and low > 0.0)): exponent -= 1
	var quantum: float = pow(2.0, exponent - 63)
	if quantum == 0.0 or not is_finite(quantum): return []
	var residual_units: float = low / quantum
	var integer_units: int = int(floor(residual_units))
	var fraction: float = residual_units - float(integer_units)
	if fraction > 0.5 or (fraction == 0.5 and (integer_units & 1) != 0): integer_units += 1
	return _sum(high, float(integer_units) * quantum)

static func _core_multiply(pair: Array, value: float) -> Array:
	if pair.is_empty(): return []
	var p: Array = _product(float(pair[0]), value)
	if p.is_empty(): return []
	return _round64(_sum(float(p[0]), float(p[1]) + float(pair[1]) * value))

static func _core_add(pair: Array, value: float) -> Array:
	if pair.is_empty(): return []
	var sum: Array = _sum(float(pair[0]), value)
	if sum.is_empty(): return []
	return _round64(_sum(float(sum[0]), float(sum[1]) + float(pair[1])))

static func _core_add_pair(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty(): return []
	var sum: Array = _sum(float(a[0]), float(b[0]))
	if sum.is_empty(): return []
	return _round64(_sum(float(sum[0]), (float(sum[1]) + float(a[1])) + float(b[1])))

static func _core_multiply_pair(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty(): return []
	var p: Array = _product(float(a[0]), float(b[0]))
	if p.is_empty(): return []
	var low: float = ((float(p[1]) + float(a[0]) * float(b[1])) + float(a[1]) * float(b[0])) + float(a[1]) * float(b[1])
	return _round64(_sum(float(p[0]), low))

static func divide(pair: Array, denominator: float) -> Array:
	return divide_pair(pair, [denominator, 0.0])

static func _core_divide_pair(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty() or float(b[0]) == 0.0: return []
	var quotient: float = float(a[0]) / float(b[0])
	if not is_finite(quotient): return []
	var product: Array = _product(quotient, float(b[0]))
	if product.is_empty(): return []
	var residual: Array = _sum(float(a[0]), -float(product[0]))
	if residual.is_empty(): return []
	var residual_low: float = ((float(residual[1]) - float(product[1])) + float(a[1])) - quotient * float(b[1])
	var corrected_residual: Array = _sum(float(residual[0]), residual_low)
	if corrected_residual.is_empty(): return []
	var correction: float = (float(corrected_residual[0]) + float(corrected_residual[1])) / float(b[0])
	return _round64(_sum(quotient, correction))

static func from_extended80_hex(hex: String) -> Array:
	var bits: PackedByteArray = hex.hex_decode()
	if bits.size() != 10: return []
	var sign_exponent: int = bits.decode_u16(8)
	var exponent: int = sign_exponent & 0x7fff
	if exponent == 0 and bits.slice(0,8) == PackedByteArray([0,0,0,0,0,0,0,0]):
		# Preserve the source sign bit without a folded GDScript zero literal.
		return [PackedByteArray([0,0,0,0,0,0,0,int(bits[9]) & 128]).decode_double(0),0.0]
	if exponent == 0 or exponent == 0x7fff: return []
	# Split the significand before applying the exponent. Applying it to each
	# chunk first would discard normal extended values below binary64's range.
	var upper: float = float(bits.decode_u32(4)) * pow(2.0, -31)
	var lower: float = float(bits.decode_u32(0)) * pow(2.0, -63)
	var result: Array = _sum(upper, lower)
	if (sign_exponent & 0x8000) != 0: result = [-float(result[0]), -float(result[1])]
	return _pack(result, exponent - 16383)

static func stored_double(pair: Array) -> float:
	if pair.size() < 3:
		if float(pair[0]) == 0.0 and float(pair[1]) == 0.0: return float(pair[0])
		return float(pair[0]) + float(pair[1])
	var high := float(pair[0])
	var low := float(pair[1])
	var negative := high < 0.0
	if negative:
		high = -high
		low = -low
	if high == 0.0: return _scale(low, int(pair[2]))
	var exponent := _exponent(high) + int(pair[2])
	if low < 0.0 and high == pow(2.0, _exponent(high)): exponent -= 1
	var quantum := maxi(-1074, exponent - 52)
	var units := _sum(_scale(high, int(pair[2]) - quantum), _scale(low, int(pair[2]) - quantum))
	var integer_units := _rounded_integer(units)
	var value := _scale(float(integer_units), quantum)
	return -value if negative else value

static func stored_float32(pair: Array) -> float:
	# FSTP dword rounds the extended operand directly; storing qword first
	# can introduce a double-rounding error at a binary32 halfway boundary.
	var high := float(pair[0])
	var low := float(pair[1])
	var negative := high < 0.0
	if negative:
		high = -high
		low = -low
	var scale := int(pair[2]) if pair.size() > 2 else 0
	if high == 0.0: return PackedFloat32Array([high if low == 0.0 else _scale(low, scale)]).to_byte_array().decode_float(0)
	var exponent := _exponent(high) + scale
	if low < 0.0 and high == pow(2.0, _exponent(high)): exponent -= 1
	var quantum := maxi(-149, exponent - 23)
	var units := _sum(_scale(high, scale - quantum), _scale(low, scale - quantum))
	var integer_units := _rounded_integer(units)
	var value := _scale(float(integer_units), quantum)
	return PackedFloat32Array([-value if negative else value]).to_byte_array().decode_float(0)

static func _rounded_integer(units: Array) -> int:
	var integer_units := int(floor(float(units[0])))
	# Keep the residual during the halfway comparison. Adding it to 0.5 first
	# can erase the deciding extended bit when storing a binary64 subnormal.
	var halfway := _sum((float(units[0]) - float(integer_units)) - 0.5, float(units[1]))
	var above := float(halfway[0]) > 0.0 or (float(halfway[0]) == 0.0 and float(halfway[1]) > 0.0)
	var tied := float(halfway[0]) == 0.0 and float(halfway[1]) == 0.0
	if above or (tied and (integer_units & 1) != 0): integer_units += 1
	return integer_units

static func compare_to_double(pair: Array, value: float) -> int:
	if pair.size() > 2:
		var difference := add_pair(pair, [-value, 0.0])
		if float(difference[0]) < 0.0: return -1
		if float(difference[0]) > 0.0: return 1
		if float(difference[1]) < 0.0: return -1
		if float(difference[1]) > 0.0: return 1
		return 0
	if float(pair[0]) < value: return -1
	if float(pair[0]) > value: return 1
	if float(pair[1]) < 0.0: return -1
	if float(pair[1]) > 0.0: return 1
	return 0

static func thermal_store(rate: float, dt: float, multiplier: float, temperature: float, cooling: bool) -> Array:
	# 0x48E529/587/5F6: FLD rate; FMUL dt; FMUL multiplier; FADD/FSUBR temp; FSTP qword.
	var value: Array = multiply([rate, 0.0], dt)
	value = multiply(value, multiplier)
	if value.is_empty(): return []
	if cooling: value = [-float(value[0]), -float(value[1])]
	value = add(value, temperature)
	return [] if value.is_empty() else [stored_double(value)]

# A third element is an exact power-of-two scale, used only when a binary64
# expansion cannot retain all 64 significand bits in the subnormal range.
static func _exponent(value: float) -> int:
	if value == 0.0: return 0
	var bytes := PackedFloat64Array([absf(value)]).to_byte_array()
	var encoded := ((int(bytes[7]) & 127) << 4) | (int(bytes[6]) >> 4)
	if encoded != 0: return encoded - 1023
	return _exponent(value * pow(2.0, 512)) - 512

static func _scale(value: float, exponent: int) -> float:
	while exponent > 512:
		value *= pow(2.0, 512)
		exponent -= 512
	while exponent < -512:
		value *= pow(2.0, -512)
		exponent += 512
	return value * pow(2.0, exponent)

static func _scaled(pair: Array) -> Array:
	if pair.is_empty(): return []
	var shift := _exponent(float(pair[0]))
	return [_scale(float(pair[0]), -shift), _scale(float(pair[1]), -shift), shift + (int(pair[2]) if pair.size() > 2 else 0)]

static func _pack(pair: Array, exponent: int) -> Array:
	if pair.is_empty(): return []
	if float(pair[0]) == 0.0 and float(pair[1]) == 0.0: return pair
	var effective := _exponent(float(pair[0])) + exponent
	if effective > 16383 or effective < -16382: return []
	if effective >= -900 and effective <= 900:
		return [_scale(float(pair[0]), exponent), _scale(float(pair[1]), exponent)]
	return [float(pair[0]), float(pair[1]), exponent]

static func _requires_scale(pair: Array) -> bool:
	return pair.size() > 2 or (not pair.is_empty() and float(pair[0]) != 0.0 and absf(float(pair[0])) < pow(2.0, -450))

static func multiply(pair: Array, value: float) -> Array:
	return multiply_pair(pair, [value, 0.0])

static func multiply_pair(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty(): return []
	if not _requires_scale(a) and not _requires_scale(b): return _core_multiply_pair(a, b)
	var aa := _scaled(a)
	var bb := _scaled(b)
	return _pack(_core_multiply_pair(aa, bb), int(aa[2]) + int(bb[2]))

static func add(pair: Array, value: float) -> Array:
	return add_pair(pair, [value, 0.0])

static func add_pair(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty(): return []
	# Under native round-to-nearest, opposite signed zeros add to +0;
	# -0 + -0 remains -0. Returning either operand loses this FADD rule.
	if float(a[0]) == 0.0 and float(a[1]) == 0.0 and float(b[0]) == 0.0 and float(b[1]) == 0.0:
		return [float(a[0])+float(b[0]),0.0]
	if float(a[0]) == 0.0 and float(a[1]) == 0.0: return b.duplicate()
	if float(b[0]) == 0.0 and float(b[1]) == 0.0: return a.duplicate()
	if not _requires_scale(a) and not _requires_scale(b): return _core_add_pair(a, b)
	var aa := _scaled(a)
	var bb := _scaled(b)
	var common := maxi(int(aa[2]), int(bb[2]))
	var delta_a := int(aa[2]) - common
	var delta_b := int(bb[2]) - common
	# Below 2^-128 relative magnitude cannot change a PC64-rounded sum.
	if delta_a < -128: return b.duplicate()
	if delta_b < -128: return a.duplicate()
	var aligned_a := [_scale(float(aa[0]), delta_a), _scale(float(aa[1]), delta_a)]
	var aligned_b := [_scale(float(bb[0]), delta_b), _scale(float(bb[1]), delta_b)]
	return _pack(_core_add_pair(aligned_a, aligned_b), common)

static func divide_pair(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty(): return []
	if not _requires_scale(a) and not _requires_scale(b): return _core_divide_pair(a, b)
	var aa := _scaled(a)
	var bb := _scaled(b)
	return _pack(_core_divide_pair(aa, bb), int(aa[2]) - int(bb[2]))
