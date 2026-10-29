object Form1: TForm1
  Left = 169
  Top = 146
  Width = 606
  Height = 395
  Caption = #19977#32500#20998#23376#27169#22411
  Color = clBtnFace
  Font.Charset = ANSI_CHARSET
  Font.Color = clBlack
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  WindowState = wsMaximized
  OnClose = FormClose
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseUp = FormMouseUp
  OnMouseWheelDown = FormMouseWheelDown
  OnMouseWheelUp = FormMouseWheelUp
  OnPaint = FormPaint
  OnResize = FormResize
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 224
    Top = 32
    Width = 52
    Height = 16
    Caption = #23383#20307#36873#25321
    Font.Charset = ANSI_CHARSET
    Font.Color = clAqua
    Font.Height = -13
    Font.Name = 'Arial Narrow'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Label2: TLabel
    Left = 232
    Top = 88
    Width = 38
    Height = 16
    Caption = 'Label2'
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlue
    Font.Height = -13
    Font.Name = 'Arial'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object Edit1: TEdit
    Left = -30
    Top = 344
    Width = 25
    Height = 21
    Font.Charset = ANSI_CHARSET
    Font.Color = clBlue
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Text = 'Edit1'
    OnKeyDown = Edit1KeyDown
  end
  object ScrollBar1: TScrollBar
    Left = 582
    Top = 0
    Width = 16
    Height = 368
    Align = alRight
    Enabled = False
    Kind = sbVertical
    Max = 360
    PageSize = 0
    TabOrder = 1
    Visible = False
    OnChange = ScrollBar1Change
  end
  object Timer1: TTimer
    Enabled = False
    Interval = 50
    OnTimer = Timer1Timer
    Left = 112
    Top = 64
  end
  object FontDialog1: TFontDialog
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -11
    Font.Name = 'MS Sans Serif'
    Font.Style = []
    MinFontSize = 0
    MaxFontSize = 0
    Options = [fdTrueTypeOnly, fdEffects]
    Left = 112
    Top = 32
  end
  object OpenDialog1: TOpenDialog
    DefaultExt = '*.cl3'
    Filter = '*.cl3|*.cl3|*.cl3'
    Left = 80
    Top = 64
  end
  object PopupMenu1: TPopupMenu
    AutoPopup = False
    MenuAnimation = [maLeftToRight]
    OnPopup = PopupMenu1Popup
    Left = 144
    Top = 64
    object N54: TMenuItem
      Caption = #36873#21462
      OnClick = N54Click
    end
    object N53: TMenuItem
      Caption = '-'
    end
    object N43: TMenuItem
      Caption = #25918#22823
      OnClick = N43Click
    end
    object N44: TMenuItem
      Caption = #32553#23567
      OnClick = N44Click
    end
    object N45: TMenuItem
      Caption = '-'
    end
    object Z1: TMenuItem
      Caption = #26059#36716
      object Y1: TMenuItem
        Caption = #32469'Y'#36724
        OnClick = Y1Click
      end
      object X1: TMenuItem
        Caption = #32469'X'#36724
        OnClick = X1Click
      end
      object Z2: TMenuItem
        Caption = #32469'Z'#36724
        OnClick = Z2Click
      end
      object N65: TMenuItem
        Caption = #20572#27490
        OnClick = N65Click
      end
    end
    object N5: TMenuItem
      Caption = #29305#27530#26059#36716
      OnClick = N5Click
    end
    object N6: TMenuItem
      Caption = #25972#20307#31227#21160
      OnClick = N6Click
    end
    object N46: TMenuItem
      Caption = '-'
    end
    object N64: TMenuItem
      Caption = #24674#22797#21021#22987#29366#24577
      OnClick = N64Click
    end
    object N29: TMenuItem
      Caption = '-'
    end
    object N49: TMenuItem
      Caption = #27169#22411
      object N50: TMenuItem
        Caption = #29699#26829#27169#22411
        object N3: TMenuItem
          Caption = #8544#22411
          OnClick = N3Click
        end
        object N4: TMenuItem
          Caption = #8545#22411
          OnClick = N4Click
        end
      end
      object N51: TMenuItem
        Caption = #27604#20363#27169#22411
        OnClick = N51Click
      end
      object N76: TMenuItem
        Caption = #26694#26550#27169#22411
        OnClick = N76Click
      end
      object N47: TMenuItem
        Caption = #23383#31526#27169#22411
        object N48: TMenuItem
          Caption = #19977#32500#23383#31526
          OnClick = N48Click
        end
        object N58: TMenuItem
          Caption = #24179#38754#23383#31526
          OnClick = N58Click
        end
      end
    end
    object N52: TMenuItem
      Caption = '-'
    end
    object N55: TMenuItem
      Caption = #21024#38500#30899#21407#23376
      OnClick = N55Click
    end
    object N56: TMenuItem
      Caption = '-'
    end
    object N61: TMenuItem
      Caption = #29615#22659#35774#32622
      OnClick = N61Click
    end
    object N7: TMenuItem
      Caption = #23383#20307#35774#32622
      OnClick = N7Click
    end
    object N1: TMenuItem
      Caption = #31934#24230#35774#32622
      OnClick = N1Click
    end
    object N2: TMenuItem
      Caption = #20851#20110#20223#30495#21270#23398#23454#39564#23460
      OnClick = N2Click
    end
    object N95: TMenuItem
      Caption = #36864#20986
      OnClick = N95Click
    end
  end
end
