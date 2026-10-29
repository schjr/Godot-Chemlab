extends Control
## Draw original graph commands inside a240×240 clipping parent.
var chart: Dictionary={}
func _ready() -> void:
	mouse_filter=Control.MOUSE_FILTER_IGNORE
func _draw() -> void:
	if not chart.has("native_chart_grid"):return
	var grid:Dictionary=chart.native_chart_grid
	draw_rect(Rect2(Vector2.ZERO,Vector2(240,240)),_color(int(grid.background_color_integer)))
	for line in grid.lines:draw_line(Vector2(line.a[0],line.a[1]),Vector2(line.b[0],line.b[1]),_color(int(line.color_integer)),float(line.width),false)
	for text in grid.texts:
		var font:=get_theme_default_font();var font_size:=get_theme_default_font_size()
		draw_string(font,Vector2(text.position[0],text.position[1]+font.get_ascent(font_size)),str(text.text),HORIZONTAL_ALIGNMENT_LEFT,-1,font_size,_color(int(text.color_integer)))
	for line in chart.get("native_chart_segments",[]):draw_line(Vector2(line.a[0],line.a[1]),Vector2(line.b[0],line.b[1]),_color(int(line.color_integer)),float(line.width),false)
func _color(value:int)->Color:
	return Color(float(value&255)/255.0,float((value>>8)&255)/255.0,float((value>>16)&255)/255.0)
