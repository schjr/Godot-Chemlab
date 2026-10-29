object ressetup: Tressetup
  Left = 253
  Top = 171
  BorderStyle = bsDialog
  Caption = #36164#28304#25991#20214#35774#32622
  ClientHeight = 108
  ClientWidth = 439
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  Icon.Data = {
    0000010001002020100000000000E80200001600000028000000200000004000
    0000010004000000000080020000000000000000000000000000000000000000
    0000000080000080000000808000800000008000800080800000C0C0C0008080
    80000000FF0000FF000000FFFF00FF000000FF00FF00FFFF0000FFFFFF000000
    0000000000000000000000000000111111111111111111100000000000001A37
    A37A37A37A37A3100000000000001AA7AA7AA7AA7AA7AA100000000000001777
    77777777777777711111111111101A37A37A37A37A37A37A37A37A37B3101AA7
    AA7AA7AA7AA7AA7AA7AA7AA7BB10177777777777777777777777777777101A37
    A37A37A37A37A37A37A37B37B3101AA7AA7AA7AA7AA7AA7AA7AA7BB7BB101777
    77777777777777777777777777101A37A37A37A37A37A37A37B37B37B3101AA7
    AA7AA7AA7AA7AA7AA7BB7BB7BB10177777111111111111177777777777101A37
    A31000000000001B37B37B37B3101AA7AA1000000000001BB7BB7BB7BB101771
    11100000000000111111111177101B3100000000C0C0000000000001B3101BB1
    000000CC0F0C000000000001BB10111100000C30F0F0C0000000000111100000
    0000C00FFF0F0C00000000000000000000CC0FFFF7F0F0C00000000000000000
    0C30F0FF7FF70F0C0000000000000000000FFF07FF7FF0F0C000000000000000
    00FFF7F0F7FF7F0F0000000000000000000F7FFF0FF7FFF00000000000000000
    0000FFF7F07FF000000000000000000000000F7FFF0000000000000000000000
    000000FFF0000000000000000000000000000000000000000000000000000000
    000000000000000000000000000000000000000000000000000000000000FFFF
    FFFF00001FFF00001FFF00001FFF000000010000000100000001000000010000
    0001000000010000000100000001000000010000000101FFC00101FFC00101FF
    C0010FF1FFE10FC0FFE10F807FE1FF003FFFFC001FFFF8000FFFF80007FFF800
    07FFFC000FFFFE001FFFFF007FFFFF83FFFFFFC7FFFFFFFFFFFFFFFFFFFF}
  OldCreateOrder = False
  Position = poScreenCenter
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 13
    Top = 13
    Width = 90
    Height = 15
    Caption = #36164#28304#25991#20214#26631#39064
    Color = clInfoBk
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object Label2: TLabel
    Left = 13
    Top = 45
    Width = 90
    Height = 15
    Caption = #36873#25321#36164#28304#25991#20214
    Color = clInfoBk
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentColor = False
    ParentFont = False
  end
  object SpeedButton1: TSpeedButton
    Left = 402
    Top = 43
    Width = 23
    Height = 22
    Caption = '...'
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -20
    Font.Name = 'Microsoft Sans Serif'
    Font.Style = [fsBold]
    ParentFont = False
    OnClick = SpeedButton1Click
  end
  object Edit1: TEdit
    Left = 110
    Top = 10
    Width = 211
    Height = 23
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 0
  end
  object CheckBox1: TCheckBox
    Left = 328
    Top = 14
    Width = 97
    Height = 17
    Caption = #20351#29992#33258#21160#21629#21517
    Color = clInfoBk
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentColor = False
    ParentFont = False
    TabOrder = 1
    OnClick = CheckBox1Click
  end
  object Edit2: TEdit
    Left = 110
    Top = 42
    Width = 286
    Height = 23
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 2
  end
  object Button1: TButton
    Left = 104
    Top = 75
    Width = 75
    Height = 25
    Caption = #30830#23450
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 264
    Top = 75
    Width = 75
    Height = 25
    Caption = #21462#28040
    Font.Charset = ANSI_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button2Click
  end
  object OpenDialog1: TOpenDialog
    Filter = #32593#39029#25991#20214'|*.html;*.htm|'#25991#26412#12289#25991#26723#25991#20214'|*.txt;*.doc|'#22270#29255#25991#20214'|*.bmp;*.gif;*.jpg;*.jpeg|'#25152#26377#25991#20214'|*.*'
    Left = 368
    Top = 67
  end
end
