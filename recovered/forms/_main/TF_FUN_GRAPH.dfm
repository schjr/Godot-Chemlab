object F_fun_graph: TF_fun_graph
  Left = 142
  Top = 158
  BorderIcons = [biMinimize, biMaximize]
  BorderStyle = bsDialog
  Caption = #20989#25968#23545#35937#35774#32622
  ClientHeight = 291
  ClientWidth = 506
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -14
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 14
  object Image1: TImage
    Left = 0
    Top = 0
    Width = 240
    Height = 240
    Cursor = crHandPoint
    AutoSize = True
    OnMouseDown = Image1MouseDown
    OnMouseMove = Image1MouseMove
    OnMouseUp = Image1MouseUp
  end
  object Label3: TLabel
    Left = 246
    Top = 12
    Width = 72
    Height = 12
    Caption = #27178#22352#26631#27604#20363#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 246
    Top = 40
    Width = 72
    Height = 12
    Caption = #32437#22352#26631#27604#20363#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Bevel1: TBevel
    Left = 242
    Top = 62
    Width = 263
    Height = 7
    Shape = bsTopLine
    Style = bsRaised
  end
  object Label5: TLabel
    Left = 248
    Top = 70
    Width = 70
    Height = 14
    Caption = #20851#32852#21464#37327#65306
  end
  object Label6: TLabel
    Left = 248
    Top = 96
    Width = 42
    Height = 12
    Caption = #26354#32447'1'#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 248
    Top = 125
    Width = 42
    Height = 12
    Caption = #26354#32447'2'#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 248
    Top = 153
    Width = 42
    Height = 12
    Caption = #26354#32447'3'#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label9: TLabel
    Left = 248
    Top = 180
    Width = 42
    Height = 12
    Caption = #26354#32447'4'#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label10: TLabel
    Left = 248
    Top = 208
    Width = 42
    Height = 12
    Caption = #26354#32447'5'#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Shape1: TShape
    Left = 288
    Top = 92
    Width = 35
    Height = 19
    Cursor = crHandPoint
    Brush.Color = clNavy
    OnMouseDown = Shape1MouseUp
  end
  object Shape2: TShape
    Left = 288
    Top = 120
    Width = 35
    Height = 19
    Cursor = crHandPoint
    Brush.Color = clNavy
    OnMouseDown = Shape2MouseUp
  end
  object Shape3: TShape
    Left = 288
    Top = 148
    Width = 35
    Height = 19
    Cursor = crHandPoint
    Brush.Color = clNavy
    OnMouseDown = Shape3MouseUp
  end
  object Shape4: TShape
    Left = 288
    Top = 176
    Width = 35
    Height = 19
    Cursor = crHandPoint
    Brush.Color = clNavy
    OnMouseDown = Shape4MouseUp
  end
  object Shape5: TShape
    Left = 288
    Top = 204
    Width = 35
    Height = 19
    Cursor = crHandPoint
    Brush.Color = clNavy
    OnMouseDown = Shape5MouseUp
  end
  object Label11: TLabel
    Left = 330
    Top = 94
    Width = 14
    Height = 14
    Caption = 'X:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label12: TLabel
    Left = 420
    Top = 94
    Width = 14
    Height = 14
    Caption = 'Y:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label13: TLabel
    Left = 330
    Top = 122
    Width = 14
    Height = 14
    Caption = 'X:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label14: TLabel
    Left = 420
    Top = 122
    Width = 14
    Height = 14
    Caption = 'Y:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label15: TLabel
    Left = 330
    Top = 150
    Width = 14
    Height = 14
    Caption = 'X:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label16: TLabel
    Left = 420
    Top = 150
    Width = 14
    Height = 14
    Caption = 'Y:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label17: TLabel
    Left = 330
    Top = 178
    Width = 14
    Height = 14
    Caption = 'X:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label18: TLabel
    Left = 420
    Top = 178
    Width = 14
    Height = 14
    Caption = 'Y:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label19: TLabel
    Left = 330
    Top = 206
    Width = 14
    Height = 14
    Caption = 'X:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label20: TLabel
    Left = 420
    Top = 206
    Width = 14
    Height = 14
    Caption = 'Y:'
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Bevel2: TBevel
    Left = 244
    Top = 238
    Width = 261
    Height = 7
    Shape = bsTopLine
    Style = bsRaised
  end
  object Label1: TLabel
    Left = 378
    Top = 12
    Width = 30
    Height = 12
    Caption = #20540'/'#26684
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 378
    Top = 40
    Width = 30
    Height = 12
    Caption = #20540'/'#26684
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Label21: TLabel
    Left = 2
    Top = 248
    Width = 60
    Height = 12
    Caption = #22352#26631#24213#33394#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Shape6: TShape
    Left = 72
    Top = 242
    Width = 35
    Height = 19
    Cursor = crHandPoint
    OnMouseDown = Shape6MouseDown
  end
  object Label22: TLabel
    Left = 2
    Top = 270
    Width = 72
    Height = 12
    Caption = #22352#26631#36724#39068#33394#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object Shape7: TShape
    Left = 72
    Top = 264
    Width = 35
    Height = 19
    Cursor = crHandPoint
    Brush.Color = clBlack
    OnMouseDown = Shape7MouseDown
  end
  object BitBtn1: TBitBtn
    Left = 353
    Top = 260
    Width = 73
    Height = 26
    Caption = #30830#23450
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = BitBtn1Click
    Glyph.Data = {
      6E040000424D6E04000000000000360000002800000014000000120000000100
      18000000000038040000C40E0000C40E00000000000000000000BFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBF7F7F7F7F7F7F7F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF7F7F
      7F7F7F7F7F7F7F7F7F7F7F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF7F7F7F7F00007F0000
      7F00007F00007F00007F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF7F0000007F00007F00007F0000
      7F007F00007F00007F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBF00FF00007F00007F00007F00007F00007F00007F
      007F00007F00007F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBF00FF00007F00007F00007F00007F00007F00007F00007F00007F00
      7F00007F00007F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BF00FF00007F00007F00007F0000FF0000FF0000FF00007F00007F00007F007F
      00007F00007F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF00FF00
      007F00007F007F00007F7F7F7F7F7F00FF0000FF00007F00007F00007F007F00
      007F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF00FF00007F0000
      7F007F00007F7F7FBFBFBFBFBFBF00FF0000FF00007F00007F007F00007F0000
      7F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF00FF00007F00007F007F00
      00BFBFBFBFBFBFBFBFBFBFBFBF00FF0000FF00007F00007F007F00007F00007F
      7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBF00FF0000FF0000FF00007F00BFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBF00FF0000FF00007F00007F007F00007F00007F7F
      7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBF00FF0000FF00007F00007F007F00007F00007F7F7F
      7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBF00FF0000FF00007F00007F007F00007F00007F7F7FBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBF00FF0000FF00007F00007F007F00007F7F7FBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBF00FF0000FF00007F007F0000BFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBF00FF0000FF00007F00BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF}
  end
  object BitBtn2: TBitBtn
    Left = 429
    Top = 260
    Width = 73
    Height = 26
    Caption = #21462#28040
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ModalResult = 2
    ParentFont = False
    TabOrder = 1
    OnClick = BitBtn2Click
    Glyph.Data = {
      6E040000424D6E04000000000000360000002800000014000000120000000100
      18000000000038040000C40E0000C40E00000000000000000000BFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBF7F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF0000000000
      007F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF7F7F7F7F7F7FBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF0000FF00007F00007F000000
      7F7F7F7F7F7FBFBFBFBFBFBFBFBFBF0000FF0000007F7F7F7F7F7FBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF0000FF00007F00007F00007F0000007F
      7F7F7F7F7FBFBFBF0000FF00007F00007F0000007F7F7F7F7F7FBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBF0000FF00007F00007F00007F00007F0000007F7F
      7F0000FF00007F00007F00007F00007F0000007F7F7FBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBF0000FF00007F00007F00007F00007F00000000007F
      00007F00007F00007F00007F000000BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBF0000FF00007F00007F00007F00007F00007F00007F00
      007F00007F000000BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBF0000FF00007F00007F00007F00007F00007F00007F0000
      00BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBF00007F00007F00007F00007F00007F0000007F7F7FBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBF0000FF00007F00007F00007F00007F0000007F7F7FBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF0000FF
      00007F00007F00007F00007F00007F0000007F7F7F7F7F7FBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF0000FF00007F00007F00
      007F00000000007F00007F00007F0000007F7F7F7F7F7FBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBF0000FF00007F00007F00007F000000BFBF
      BF0000FF00007F00007F00007F0000007F7F7F7F7F7FBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBF0000FF00007F00007F000000BFBFBFBFBFBFBFBFBF
      0000FF00007F00007F00007F0000007F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBF0000FF00007FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF00
      00FF00007F00007F0000007F7F7FBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF0000
      FF00007F0000FFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF
      BFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBFBF}
  end
  object Edit3: TEdit
    Left = 316
    Top = 6
    Width = 57
    Height = 20
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Text = 'Edit3'
    OnChange = Edit3Change
  end
  object Edit4: TEdit
    Left = 316
    Top = 34
    Width = 57
    Height = 20
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Text = 'Edit4'
    OnChange = Edit4Change
  end
  object ComboBox1: TComboBox
    Left = 346
    Top = 92
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 4
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox2: TComboBox
    Left = 436
    Top = 92
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 5
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox3: TComboBox
    Left = 346
    Top = 120
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 6
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox4: TComboBox
    Left = 436
    Top = 120
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 7
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox5: TComboBox
    Left = 346
    Top = 148
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 8
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox6: TComboBox
    Left = 436
    Top = 148
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 9
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox7: TComboBox
    Left = 346
    Top = 176
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 10
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox8: TComboBox
    Left = 436
    Top = 176
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 11
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox9: TComboBox
    Left = 346
    Top = 204
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 12
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object ComboBox10: TComboBox
    Left = 436
    Top = 204
    Width = 67
    Height = 20
    Style = csDropDownList
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 12
    ParentFont = False
    TabOrder = 13
    Items.Strings = (
      #25968#20540'0'
    )
  end
  object CheckBox1: TCheckBox
    Left = 118
    Top = 246
    Width = 97
    Height = 17
    Alignment = taLeftJustify
    Caption = #22352#26631#24213#33394#36879#26126#65306
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 14
  end
  object ColorDialog1: TColorDialog
    Ctl3D = True
    Left = 2
    Top = 2
  end
end
