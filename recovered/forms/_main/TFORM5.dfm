object Form5: TForm5
  Left = 398
  Top = 113
  BorderStyle = bsDialog
  Caption = #28155#21152#33647#21697
  ClientHeight = 356
  ClientWidth = 336
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clBlack
  Font.Height = -13
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 2
    Top = 2
    Width = 331
    Height = 315
    ActivePage = TabSheet1
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #22266#20307
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      object Label6: TLabel
        Left = 188
        Top = 210
        Width = 21
        Height = 13
        Caption = 'mol'
      end
      object Label1: TLabel
        Left = 188
        Top = 236
        Width = 7
        Height = 13
        Caption = 'g'
      end
      object Label12: TLabel
        Left = 6
        Top = 186
        Width = 52
        Height = 13
        Caption = #33647#21697#21517#31216
      end
      object SpeedButton1: TSpeedButton
        Left = 188
        Top = 180
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333300000000
          0000333377777777777733330FFFFFFFFFF033337F3FFF3F3FF733330F000F0F
          00F033337F777373773733330FFFFFFFFFF033337F3FF3FF3FF733330F00F00F
          00F033337F773773773733330FFFFFFFFFF033337FF3333FF3F7333300FFFF00
          F0F03333773FF377F7373330FB00F0F0FFF0333733773737F3F7330FB0BF0FB0
          F0F0337337337337373730FBFBF0FB0FFFF037F333373373333730BFBF0FB0FF
          FFF037F3337337333FF700FBFBFB0FFF000077F333337FF37777E0BFBFB000FF
          0FF077FF3337773F7F37EE0BFB0BFB0F0F03777FF3733F737F73EEE0BFBF00FF
          00337777FFFF77FF7733EEEE0000000003337777777777777333}
        NumGlyphs = 2
        OnClick = SpeedButton1Click
      end
      object RadioButton1: TRadioButton
        Left = 2
        Top = 210
        Width = 75
        Height = 17
        Caption = #29289#36136#30340#37327
        Checked = True
        TabOrder = 1
        TabStop = True
        OnClick = RadioButton1Click
      end
      object Edit1: TEdit
        Left = 78
        Top = 206
        Width = 107
        Height = 21
        TabOrder = 0
        Text = 'Edit1'
      end
      object RadioButton2: TRadioButton
        Left = 2
        Top = 236
        Width = 61
        Height = 17
        Caption = #36136#37327
        TabOrder = 2
        OnClick = RadioButton2Click
      end
      object Edit2: TEdit
        Left = 78
        Top = 232
        Width = 107
        Height = 21
        TabOrder = 3
        Text = 'Edit2'
      end
      object StringGrid1: TStringGrid
        Left = 2
        Top = 2
        Width = 318
        Height = 171
        Color = clWhite
        ColCount = 3
        DefaultColWidth = 35
        DefaultRowHeight = 20
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
        ParentFont = False
        TabOrder = 4
        OnSelectCell = StringGrid1SelectCell
        ColWidths = (
          35
          150
          107
        )
        RowHeights = (
          20
          20
          20
          20
          20
        )
      end
      object Edit12: TEdit
        Left = 78
        Top = 180
        Width = 107
        Height = 21
        AutoSize = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clWindowText
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        Text = 'Edit12'
        OnKeyPress = Edit12KeyPress
      end
    end
    object TabSheet2: TTabSheet
      Caption = #28082#20307
      ImageIndex = 1
      object Label2: TLabel
        Left = 188
        Top = 210
        Width = 21
        Height = 13
        Caption = 'mol'
      end
      object Label3: TLabel
        Left = 188
        Top = 236
        Width = 7
        Height = 13
        Caption = 'g'
      end
      object Label11: TLabel
        Left = 190
        Top = 264
        Width = 14
        Height = 13
        Caption = 'ml'
      end
      object Label13: TLabel
        Left = 6
        Top = 186
        Width = 52
        Height = 13
        Caption = #33647#21697#21517#31216
      end
      object SpeedButton2: TSpeedButton
        Left = 188
        Top = 180
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333300000000
          0000333377777777777733330FFFFFFFFFF033337F3FFF3F3FF733330F000F0F
          00F033337F777373773733330FFFFFFFFFF033337F3FF3FF3FF733330F00F00F
          00F033337F773773773733330FFFFFFFFFF033337FF3333FF3F7333300FFFF00
          F0F03333773FF377F7373330FB00F0F0FFF0333733773737F3F7330FB0BF0FB0
          F0F0337337337337373730FBFBF0FB0FFFF037F333373373333730BFBF0FB0FF
          FFF037F3337337333FF700FBFBFB0FFF000077F333337FF37777E0BFBFB000FF
          0FF077FF3337773F7F37EE0BFB0BFB0F0F03777FF3733F737F73EEE0BFBF00FF
          00337777FFFF77FF7733EEEE0000000003337777777777777333}
        NumGlyphs = 2
        OnClick = SpeedButton2Click
      end
      object RadioButton3: TRadioButton
        Left = 2
        Top = 210
        Width = 75
        Height = 17
        Caption = #29289#36136#30340#37327
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton3Click
      end
      object Edit3: TEdit
        Left = 78
        Top = 206
        Width = 107
        Height = 21
        TabOrder = 1
        Text = 'Edit3'
      end
      object RadioButton4: TRadioButton
        Left = 2
        Top = 236
        Width = 61
        Height = 17
        Caption = #36136#37327
        TabOrder = 2
        OnClick = RadioButton4Click
      end
      object Edit4: TEdit
        Left = 78
        Top = 232
        Width = 107
        Height = 21
        TabOrder = 3
        Text = 'Edit4'
      end
      object RadioButton5: TRadioButton
        Left = 2
        Top = 262
        Width = 61
        Height = 17
        Caption = #20307#31215
        TabOrder = 4
        OnClick = RadioButton5Click
      end
      object Edit5: TEdit
        Left = 78
        Top = 258
        Width = 107
        Height = 21
        TabOrder = 5
        Text = 'Edit5'
      end
      object StringGrid2: TStringGrid
        Left = 2
        Top = 2
        Width = 318
        Height = 171
        Color = clWhite
        ColCount = 3
        DefaultColWidth = 35
        DefaultRowHeight = 20
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
        ParentFont = False
        TabOrder = 6
        OnSelectCell = StringGrid2SelectCell
        ColWidths = (
          35
          150
          107
        )
      end
      object Edit13: TEdit
        Left = 78
        Top = 180
        Width = 107
        Height = 21
        AutoSize = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 7
        Text = 'Edit13'
        OnKeyPress = Edit13KeyPress
      end
    end
    object TabSheet3: TTabSheet
      Caption = #27668#20307
      ImageIndex = 2
      object Label4: TLabel
        Left = 188
        Top = 210
        Width = 21
        Height = 13
        Caption = 'mol'
      end
      object Label5: TLabel
        Left = 188
        Top = 236
        Width = 7
        Height = 13
        Caption = 'g'
      end
      object Label14: TLabel
        Left = 6
        Top = 186
        Width = 52
        Height = 13
        Caption = #33647#21697#21517#31216
      end
      object SpeedButton3: TSpeedButton
        Left = 188
        Top = 180
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333300000000
          0000333377777777777733330FFFFFFFFFF033337F3FFF3F3FF733330F000F0F
          00F033337F777373773733330FFFFFFFFFF033337F3FF3FF3FF733330F00F00F
          00F033337F773773773733330FFFFFFFFFF033337FF3333FF3F7333300FFFF00
          F0F03333773FF377F7373330FB00F0F0FFF0333733773737F3F7330FB0BF0FB0
          F0F0337337337337373730FBFBF0FB0FFFF037F333373373333730BFBF0FB0FF
          FFF037F3337337333FF700FBFBFB0FFF000077F333337FF37777E0BFBFB000FF
          0FF077FF3337773F7F37EE0BFB0BFB0F0F03777FF3733F737F73EEE0BFBF00FF
          00337777FFFF77FF7733EEEE0000000003337777777777777333}
        NumGlyphs = 2
        OnClick = SpeedButton3Click
      end
      object RadioButton6: TRadioButton
        Left = 2
        Top = 210
        Width = 71
        Height = 17
        Caption = #29289#36136#30340#37327
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton6Click
      end
      object Edit6: TEdit
        Left = 78
        Top = 206
        Width = 107
        Height = 21
        TabOrder = 1
        Text = 'Edit6'
      end
      object RadioButton7: TRadioButton
        Left = 2
        Top = 236
        Width = 61
        Height = 17
        Caption = #36136#37327
        TabOrder = 2
        OnClick = RadioButton7Click
      end
      object Edit7: TEdit
        Left = 78
        Top = 232
        Width = 107
        Height = 21
        TabOrder = 3
        Text = 'Edit7'
      end
      object StringGrid3: TStringGrid
        Left = 2
        Top = 2
        Width = 318
        Height = 171
        Color = clWhite
        ColCount = 3
        DefaultColWidth = 35
        DefaultRowHeight = 20
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
        ParentFont = False
        TabOrder = 4
        OnSelectCell = StringGrid3SelectCell
        ColWidths = (
          35
          150
          107
        )
      end
      object Edit14: TEdit
        Left = 78
        Top = 180
        Width = 107
        Height = 21
        AutoSize = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        Text = 'Edit14'
        OnKeyPress = Edit14KeyPress
      end
    end
    object TabSheet4: TTabSheet
      Caption = #28342#36136
      ImageIndex = 3
      object Label7: TLabel
        Left = 188
        Top = 210
        Width = 21
        Height = 13
        Caption = 'mol'
      end
      object Label8: TLabel
        Left = 188
        Top = 236
        Width = 7
        Height = 13
        Caption = 'g'
      end
      object Label15: TLabel
        Left = 6
        Top = 186
        Width = 52
        Height = 13
        Caption = #33647#21697#21517#31216
      end
      object SpeedButton4: TSpeedButton
        Left = 188
        Top = 180
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333300000000
          0000333377777777777733330FFFFFFFFFF033337F3FFF3F3FF733330F000F0F
          00F033337F777373773733330FFFFFFFFFF033337F3FF3FF3FF733330F00F00F
          00F033337F773773773733330FFFFFFFFFF033337FF3333FF3F7333300FFFF00
          F0F03333773FF377F7373330FB00F0F0FFF0333733773737F3F7330FB0BF0FB0
          F0F0337337337337373730FBFBF0FB0FFFF037F333373373333730BFBF0FB0FF
          FFF037F3337337333FF700FBFBFB0FFF000077F333337FF37777E0BFBFB000FF
          0FF077FF3337773F7F37EE0BFB0BFB0F0F03777FF3733F737F73EEE0BFBF00FF
          00337777FFFF77FF7733EEEE0000000003337777777777777333}
        NumGlyphs = 2
        OnClick = SpeedButton4Click
      end
      object RadioButton8: TRadioButton
        Left = 2
        Top = 210
        Width = 75
        Height = 17
        Caption = #29289#36136#30340#37327
        Checked = True
        TabOrder = 0
        TabStop = True
        OnClick = RadioButton8Click
      end
      object Edit8: TEdit
        Left = 78
        Top = 206
        Width = 107
        Height = 21
        TabOrder = 1
        Text = 'Edit8'
      end
      object RadioButton9: TRadioButton
        Left = 2
        Top = 236
        Width = 61
        Height = 17
        Caption = #36136#37327
        TabOrder = 2
        OnClick = RadioButton9Click
      end
      object Edit9: TEdit
        Left = 78
        Top = 232
        Width = 107
        Height = 21
        TabOrder = 3
        Text = 'Edit9'
      end
      object StringGrid4: TStringGrid
        Left = 2
        Top = 2
        Width = 318
        Height = 171
        Color = clWhite
        ColCount = 3
        DefaultColWidth = 35
        DefaultRowHeight = 20
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
        ParentFont = False
        TabOrder = 4
        OnSelectCell = StringGrid4SelectCell
        ColWidths = (
          35
          150
          107
        )
      end
      object Edit15: TEdit
        Left = 78
        Top = 180
        Width = 107
        Height = 21
        AutoSize = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 5
        Text = 'Edit15'
        OnKeyPress = Edit15KeyPress
      end
    end
    object TabSheet5: TTabSheet
      Caption = #28342#28082
      ImageIndex = 4
      object Label17: TLabel
        Left = 6
        Top = 186
        Width = 52
        Height = 13
        Caption = #33647#21697#21517#31216
      end
      object SpeedButton6: TSpeedButton
        Left = 196
        Top = 180
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333300000000
          0000333377777777777733330FFFFFFFFFF033337F3FFF3F3FF733330F000F0F
          00F033337F777373773733330FFFFFFFFFF033337F3FF3FF3FF733330F00F00F
          00F033337F773773773733330FFFFFFFFFF033337FF3333FF3F7333300FFFF00
          F0F03333773FF377F7373330FB00F0F0FFF0333733773737F3F7330FB0BF0FB0
          F0F0337337337337373730FBFBF0FB0FFFF037F333373373333730BFBF0FB0FF
          FFF037F3337337333FF700FBFBFB0FFF000077F333337FF37777E0BFBFB000FF
          0FF077FF3337773F7F37EE0BFB0BFB0F0F03777FF3733F737F73EEE0BFBF00FF
          00337777FFFF77FF7733EEEE0000000003337777777777777333}
        NumGlyphs = 2
        OnClick = SpeedButton6Click
      end
      object Label18: TLabel
        Left = 198
        Top = 264
        Width = 14
        Height = 13
        Caption = 'ml'
      end
      object Label19: TLabel
        Left = 6
        Top = 238
        Width = 78
        Height = 13
        Caption = #29289#36136#30340#37327#27987#24230
      end
      object Label20: TLabel
        Left = 198
        Top = 238
        Width = 35
        Height = 13
        Caption = 'mol/L'
      end
      object StringGrid6: TStringGrid
        Left = 2
        Top = 2
        Width = 318
        Height = 171
        Color = clWhite
        ColCount = 3
        DefaultColWidth = 35
        DefaultRowHeight = 20
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
        ParentFont = False
        TabOrder = 0
        OnSelectCell = StringGrid6SelectCell
        ColWidths = (
          35
          150
          107
        )
        RowHeights = (
          20
          20
          20
          20
          20
        )
      end
      object Edit17: TEdit
        Left = 86
        Top = 180
        Width = 107
        Height = 21
        AutoSize = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = 'Edit17'
        OnKeyPress = Edit17KeyPress
      end
      object RadioButton12: TRadioButton
        Left = 2
        Top = 262
        Width = 61
        Height = 17
        Caption = #20307#31215
        Checked = True
        TabOrder = 2
        TabStop = True
        OnClick = RadioButton5Click
      end
      object Edit18: TEdit
        Left = 86
        Top = 258
        Width = 107
        Height = 21
        TabOrder = 3
        Text = 'Edit18'
      end
      object Edit19: TEdit
        Left = 86
        Top = 232
        Width = 107
        Height = 21
        AutoSize = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 4
        Text = 'Edit19'
        OnKeyPress = Edit15KeyPress
      end
    end
    object TabSheet6: TTabSheet
      Caption = #31163#23376
      ImageIndex = 5
      object Label16: TLabel
        Left = 6
        Top = 186
        Width = 52
        Height = 13
        Caption = #33647#21697#21517#31216
      end
      object Label9: TLabel
        Left = 188
        Top = 210
        Width = 21
        Height = 13
        Caption = 'mol'
      end
      object Label10: TLabel
        Left = 188
        Top = 236
        Width = 7
        Height = 13
        Caption = 'g'
      end
      object SpeedButton5: TSpeedButton
        Left = 188
        Top = 180
        Width = 23
        Height = 22
        Flat = True
        Glyph.Data = {
          76010000424D7601000000000000760000002800000020000000100000000100
          04000000000000010000120B0000120B00001000000000000000000000000000
          800000800000008080008000000080008000808000007F7F7F00BFBFBF000000
          FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF00333300000000
          0000333377777777777733330FFFFFFFFFF033337F3FFF3F3FF733330F000F0F
          00F033337F777373773733330FFFFFFFFFF033337F3FF3FF3FF733330F00F00F
          00F033337F773773773733330FFFFFFFFFF033337FF3333FF3F7333300FFFF00
          F0F03333773FF377F7373330FB00F0F0FFF0333733773737F3F7330FB0BF0FB0
          F0F0337337337337373730FBFBF0FB0FFFF037F333373373333730BFBF0FB0FF
          FFF037F3337337333FF700FBFBFB0FFF000077F333337FF37777E0BFBFB000FF
          0FF077FF3337773F7F37EE0BFB0BFB0F0F03777FF3733F737F73EEE0BFBF00FF
          00337777FFFF77FF7733EEEE0000000003337777777777777333}
        NumGlyphs = 2
        OnClick = SpeedButton5Click
      end
      object StringGrid5: TStringGrid
        Left = 2
        Top = 2
        Width = 318
        Height = 171
        Color = clWhite
        ColCount = 3
        DefaultColWidth = 35
        DefaultRowHeight = 20
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRowSelect]
        ParentFont = False
        TabOrder = 0
        OnSelectCell = StringGrid5SelectCell
        ColWidths = (
          35
          150
          107
        )
      end
      object Edit16: TEdit
        Left = 78
        Top = 180
        Width = 107
        Height = 21
        AutoSize = False
        Font.Charset = GB2312_CHARSET
        Font.Color = clBlack
        Font.Height = -12
        Font.Name = #23435#20307
        Font.Style = []
        ParentFont = False
        TabOrder = 1
        Text = 'Edit16'
        OnKeyPress = Edit16KeyPress
      end
      object RadioButton10: TRadioButton
        Left = 2
        Top = 210
        Width = 71
        Height = 17
        Caption = #29289#36136#30340#37327
        Checked = True
        TabOrder = 2
        TabStop = True
        OnClick = RadioButton10Click
      end
      object Edit10: TEdit
        Left = 78
        Top = 206
        Width = 107
        Height = 21
        TabOrder = 3
        Text = 'Edit10'
      end
      object RadioButton11: TRadioButton
        Left = 2
        Top = 236
        Width = 61
        Height = 17
        Caption = #36136#37327
        TabOrder = 4
        OnClick = RadioButton11Click
      end
      object Edit11: TEdit
        Left = 78
        Top = 232
        Width = 107
        Height = 21
        TabOrder = 5
        Text = 'Edit11'
      end
    end
  end
  object BitBtn1: TBitBtn
    Left = 178
    Top = 326
    Width = 75
    Height = 25
    Caption = #28155#21152
    TabOrder = 1
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
    Left = 256
    Top = 326
    Width = 75
    Height = 25
    Caption = #20851#38381
    TabOrder = 2
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
end
