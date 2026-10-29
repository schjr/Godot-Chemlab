class_name OriginalPortableRaster
extends RefCounted
## Portable non-antialiased boundary for the original drawing operations.
## Recipes and pixel composition are source code ports. Curve edge coverage is
## portable rasterization, and is never labelled a verified Windows GDI frame.
static func color_word(colorref:int)->int:
	return ((colorref&255)<<16)|(colorref&0xff00)|((colorref>>16)&255)
static func pixel(words:Array,w:int,h:int,x:int,y:int,color:int)->void:
	if x>=0 and y>=0 and x<w and y<h:words[y*w+x]=color
static func line(words:Array,w:int,h:int,a:Vector2i,b:Vector2i,color:int)->void:
	var x:=a.x;var y:=a.y;var dx:=absi(b.x-x);var sx:=1 if x<b.x else -1
	var dy:=-absi(b.y-y);var sy:=1 if y<b.y else -1;var error:=dx+dy
	# GDI LineTo excludes the final endpoint.
	while x!=b.x or y!=b.y:
		pixel(words,w,h,x,y,color)
		var twice:=2*error
		if twice>=dy:error+=dy;x+=sx
		if twice<=dx:error+=dx;y+=sy
static func triangle(words:Array,w:int,h:int,points:Array,color:int)->void:
	var lo:=h;var hi:=0
	for point in points:lo=mini(lo,int(point[1]));hi=maxi(hi,int(point[1]))
	for y in range(maxi(0,lo),mini(h,hi)):
		var intersections:Array=[]
		for i in points.size():
			var a:Array=points[i];var b:Array=points[(i+1)%points.size()]
			if (float(a[1])<=y+0.5 and float(b[1])>y+0.5) or (float(b[1])<=y+0.5 and float(a[1])>y+0.5):
				intersections.append(float(a[0])+(y+0.5-float(a[1]))*(float(b[0])-float(a[0]))/(float(b[1])-float(a[1])))
		intersections.sort()
		for i in range(0,intersections.size()-1,2):
			for x in range(maxi(0,int(ceil(intersections[i]-0.5))),mini(w,int(ceil(intersections[i+1]-0.5)))):pixel(words,w,h,x,y,color)
static func operations(words:Array,w:int,h:int,ops:Array)->Dictionary:
	for op in ops:
		var l:=int(op.get("left",0));var t:=int(op.get("top",0));var r:=int(op.get("right",0));var b:=int(op.get("bottom",0))
		var pen:=color_word(int(op.get("pen_color",0)));var brush:=color_word(int(op.get("brush_color",0)));var hollow:=int(op.get("brush_style",0))==1
		match str(op.get("op","")):
			"rectangle":
				if r<=l or b<=t:continue
				for y in range(maxi(0,t),mini(h,b)):
					for x in range(maxi(0,l),mini(w,r)):
						if x==l or x==r-1 or y==t or y==b-1:words[y*w+x]=pen
						elif not hollow:words[y*w+x]=brush
			"ellipse","arc":
				if r<=l or b<=t:continue
				var rx:=(r-l-1)*0.5;var ry:=(b-t-1)*0.5;var cx:=l+rx;var cy:=t+ry
				if rx<=0 or ry<=0:continue
				if op.op=="ellipse" and not hollow:
					for y in range(maxi(0,t),mini(h,b)):
						var normalized:=(y-cy)/ry
						if absf(normalized)>1:continue
						var span:=rx*sqrt(maxf(0.0,1.0-normalized*normalized))
						for x in range(maxi(0,int(ceil(cx-span))),mini(w,int(floor(cx+span))+1)):words[y*w+x]=brush
				var first:=0.0;var sweep:=TAU
				if op.op=="arc":
					first=atan2(-(float(op.start_y)-cy)/ry,(float(op.start_x)-cx)/rx)
					var end:=atan2(-(float(op.end_y)-cy)/ry,(float(op.end_x)-cx)/rx)
					sweep=fposmod(end-first,TAU)
					if is_zero_approx(sweep):sweep=TAU
				var steps:=maxi(8,int(ceil(maxf(rx,ry)*sweep*2.0)))
				var previous:=Vector2i(roundi(cx+rx*cos(first)),roundi(cy-ry*sin(first)))
				for i in range(1,steps+1):
					var angle:=first+sweep*i/steps;var current:=Vector2i(roundi(cx+rx*cos(angle)),roundi(cy-ry*sin(angle)))
					line(words,w,h,previous,current,pen);pixel(words,w,h,current.x,current.y,pen);previous=current
			_:return {"ok":false,"error":"Unsupported original portable primitive: "+str(op.get("op"))}
	return {"ok":true}
