extends SceneTree
## Native mask arithmetic reads RGB even where the display sprite has alpha0.
const Renderer=preload("res://scripts/original/original_source_renderer.gd")
func _initialize()->void:
	var fixture_path:="res://tests/fixtures/original_bitmap_rgb.json"
	for argument in OS.get_cmdline_user_args():
		if argument.begins_with("--bitmap-fixture="):fixture_path=argument.trim_prefix("--bitmap-fixture=")
	var fixture:Dictionary=JSON.parse_string(FileAccess.get_file_as_string(fixture_path))
	var renderer=Renderer.new();var failures:Array=[];var pixels:=0
	for reference in fixture.images:
		var actual:Dictionary=renderer._asset(reference.name)
		if not actual.ok:
			failures.append([reference.name,actual.get("error")]);continue
		if actual.width!=reference.width or actual.height!=reference.height:
			failures.append([reference.name,"Original bitmap dimensions changed"]);continue
		var hash_context:=HashingContext.new();hash_context.start(HashingContext.HASH_SHA256)
		hash_context.update(PackedInt32Array(actual.words).to_byte_array())
		var digest:=hash_context.finish().hex_encode()
		if digest!=reference.native_rgb_words_sha256:failures.append([reference.name,"Imported native RGB differs from original BMP",digest])
		pixels+=actual.words.size()
	if pixels!=int(fixture.pixels):failures.append(["Incomplete pixel comparison",pixels,fixture.pixels])
	print(JSON.stringify({"images_checked":fixture.images.size(),"pixels_checked":pixels,"failures":failures}))
	if failures.is_empty():print("PASS imported source-renderer RGB matches every original apparatus bitmap pixel, including transparent borders")
	quit(0 if failures.is_empty() else 1)
