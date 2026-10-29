class_name OriginalMath
extends RefCounted
## Compatibility for the CRT's x87 logarithm instructions. Chemical algorithms
## remain in their original callers. Series evaluate the transcendental in a
## binary64 expansion before the native 64-significand-bit instruction rounding.
const X87 = preload("res://scripts/original/original_x87.gd")
const LN2 = [0.6931471805599453, 2.3190468138462996e-17]
const LG2_HEX = "99f7cffb849a209afd3f"
const LN2_HEX = "ac79cfd1f71772b1fe3f"
const L2E_HEX = "bcf0175c293baab8ff3f"
const SQRT2_HEX = "8564def933f304b5ff3f"
# Original x87 instruction reduction constant, retained beyond FLDPI's PC64
# rounding. Verified by the near-pi native FSIN reference operands.
const HALF_PI = [1.5707963267948966,6.123031769111886e-17]

static func trig_compatible(value: float, kind: String) -> Array:
	# CRT intrinsic compatibility for the source particle FLOAT32 angle path.
	# Preserve an extended result for subsequent original FMUL/FADD/FSTP;
	# callers verify their stored records against the original instruction oracle.
	if kind not in ["sin","cos"] or not is_finite(value) or absf(value) > 1048576.0: return []
	if value == 0.0: return [value,0.0] if kind == "sin" else [1.0,0.0]
	var quadrant := int(floor(value/float(HALF_PI[0])+0.5))
	var reduced := _add([value,0.0],_mul([-float(quadrant),0.0],HALF_PI))
	var square := _mul(reduced,reduced)
	var sine := reduced.duplicate(); var cosine := [1.0,0.0]
	var sine_term := reduced.duplicate(); var cosine_term := [1.0,0.0]
	for i in range(1,24):
		if absf(float(sine_term[0])) > absf(float(sine[0]))*1e-34:
			sine_term = _div(_mul(sine_term,[-float(square[0]),-float(square[1])]),[float((2*i)*(2*i+1)),0.0])
			sine = _add(sine,sine_term)
		if absf(float(cosine_term[0])) > absf(float(cosine[0]))*1e-34:
			cosine_term = _div(_mul(cosine_term,[-float(square[0]),-float(square[1])]),[float((2*i-1)*(2*i)),0.0])
			cosine = _add(cosine,cosine_term)
	var result: Array
	match quadrant & 3:
		0: result = sine if kind == "sin" else cosine
		1: result = cosine if kind == "sin" else [-float(sine[0]),-float(sine[1])]
		2: result = [-float(sine[0]),-float(sine[1])] if kind == "sin" else [-float(cosine[0]),-float(cosine[1])]
		3: result = [-float(cosine[0]),-float(cosine[1])] if kind == "sin" else sine
	return X87._round64(result)

static func sqrt_native(value: float) -> Array:
	# FSQRT is correctly rounded. Newton refinement keeps a 106-bit expansion
	# until its one PC64 result rounding; the host sqrt is only an initial seed.
	if not is_finite(value) or value < 0.0: return []
	if value == 0.0: return [value,0.0]
	var scaled := X87._scaled([value,0.0])
	var exponent := int(scaled[2])
	var mantissa := [float(scaled[0]),float(scaled[1])]
	if (exponent & 1) != 0:
		mantissa = _mul(mantissa,[2.0,0.0]); exponent -= 1
	var root := [sqrt(float(mantissa[0])),0.0]
	for _i in range(4): root = _mul(_add(root,_div(mantissa,root)),[0.5,0.0])
	return X87._pack(X87._round64(root),int(exponent/2))

static func _add(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty(): return []
	var s: Array = X87._sum(float(a[0]),float(b[0]))
	return X87._sum(float(s[0]),float(s[1])+float(a[1])+float(b[1]))

static func _mul(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty(): return []
	var p: Array = X87._product(float(a[0]),float(b[0]))
	if p.is_empty(): return []
	return X87._sum(float(p[0]),float(p[1])+float(a[0])*float(b[1])+float(a[1])*float(b[0])+float(a[1])*float(b[1]))

static func _div(a: Array, b: Array) -> Array:
	if a.is_empty() or b.is_empty() or float(b[0]) == 0.0: return []
	var q: float = float(a[0])/float(b[0])
	var residual := _add(a,_mul([-q,0.0],b))
	if residual.is_empty(): return []
	return X87._sum(q,(float(residual[0])+float(residual[1]))/float(b[0]))

static func _log2(value: float) -> Array:
	if value <= 0.0 or not is_finite(value): return []
	var bits := PackedFloat64Array([value]).to_byte_array()
	var exponent := ((bits[7]&127)<<4 | (bits[6]>>4))-1023
	if exponent == -1023: return []
	bits[7] = 63
	bits[6] = (bits[6]&15)|240
	var mantissa := bits.decode_double(0)
	if mantissa > 1.4142135623730951: mantissa *= 0.5; exponent += 1
	var t := _div(_add([mantissa,0.0],[-1.0,0.0]),_add([mantissa,0.0],[1.0,0.0]))
	var square := _mul(t,t)
	var term := t
	var series := t
	# |t| <= .172; 48 odd terms exceed the binary64 expansion's precision.
	for i in range(1,48):
		if absf(float(term[0])) < absf(float(series[0]))*1e-34: break
		term = _mul(term,square)
		if term.is_empty(): return []
		series = _add(series,_div(term,[float(2*i+1),0.0]))
	var ln_mantissa := _mul(series,[2.0,0.0])
	return _add(_div(ln_mantissa,LN2),[float(exponent),0.0])

static func log10_native(value: float) -> Array:
	var log2 := _log2(value)
	if log2.is_empty(): return []
	# FLDLG2; FYL2X has one final 64-bit rounding, not a stored log2 double.
	return X87._round64(_mul(log2,X87.from_extended80_hex(LG2_HEX)))

static func _exp2m1(fraction: Array) -> Array:
	# Software implementation of F2XM1 with a high-precision expansion, followed
	# by its single native instruction rounding. This is not a chemistry solver.
	var x := _mul(fraction,LN2)
	var term := x
	var series := x
	for i in range(2,48):
		if absf(float(term[0])) < absf(float(series[0]))*1e-34: break
		term = _div(_mul(term,x),[float(i),0.0])
		if term.is_empty(): return []
		series = _add(series,term)
	return X87._round64(series)

static func _exp_native(value: Array) -> Array:
	# 0x5393C9..488: FLDL2E/FMUL, fabs, doubled-exponent split, F2XM1,
	# optional sqrt(2) and FSCALE, then reciprocal for negative arguments.
	var z := X87.multiply_pair(value,X87.from_extended80_hex(L2E_HEX))
	if z.is_empty(): return []
	var negative: bool = float(z[0]) < 0.0
	if negative: z = [-float(z[0]),-float(z[1])]
	if float(z[0]) > 1023.0: return []
	var out: Array
	if X87.compare_to_double(z,1.0) <= 0:
		out = X87.add(_exp2m1(z),1.0)
	else:
		var doubled := X87.multiply(z,2.0)
		var integral := int(doubled[0])
		if float(integral) == float(doubled[0]) and float(doubled[1]) < 0.0: integral -= 1
		var fractional := X87.add(z,-float(integral)*0.5)
		out = X87.add(_exp2m1(fractional),1.0)
		if (integral&1) != 0: out = X87.multiply_pair(out,X87.from_extended80_hex(SQRT2_HEX))
		out = X87.multiply(out,pow(2.0,integral>>1))
	return X87.divide_pair([1.0,0.0],out) if negative else out

static func pow_native(base: float, exponent: float) -> Array:
	# Main CRT 0x5399D8 handles zero, integer small powers, then log/exp.
	if not is_finite(base) or not is_finite(exponent): return []
	if base == 0.0: return [0.0,0.0] if exponent > 0.0 else []
	if exponent == 0.0: return [1.0,0.0]
	var integral := int(exponent)
	if exponent == float(integral) and absi(integral) < 4096:
		var magnitude := absi(integral)
		var out := [base,0.0]
		var bit := 1
		while (bit<<1) <= magnitude: bit <<= 1
		bit >>= 1
		while bit > 0:
			out = X87.multiply_pair(out,out)
			if (magnitude&bit) != 0: out = X87.multiply(out,base)
			bit >>= 1
		return X87.divide_pair([1.0,0.0],out) if integral < 0 else out
	if base < 0.0: return []
	var natural_log := X87._round64(_mul(_log2(base),X87.from_extended80_hex(LN2_HEX)))
	var argument := X87.multiply(natural_log,exponent)
	return _exp_native(argument)
