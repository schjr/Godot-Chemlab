object netbuilder_set: Tnetbuilder_set
  Left = 196
  Top = 133
  BorderStyle = bsDialog
  Caption = #32593#32476#35838#20214#35774#32622
  ClientHeight = 325
  ClientWidth = 423
  Color = clBtnFace
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -15
  Font.Name = #23435#20307
  Font.Style = []
  OldCreateOrder = False
  Position = poScreenCenter
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 15
  object Label1: TLabel
    Left = 8
    Top = 8
    Width = 68
    Height = 15
    Caption = #32593#39029#26631#39064':'
  end
  object Label2: TLabel
    Left = 8
    Top = 36
    Width = 68
    Height = 15
    Caption = #35838#20214#31616#20171':'
  end
  object Label3: TLabel
    Left = 8
    Top = 188
    Width = 68
    Height = 15
    Caption = #35838#20214#20316#32773':'
  end
  object Bevel1: TBevel
    Left = 0
    Top = 216
    Width = 421
    Height = 9
    Shape = bsTopLine
    Style = bsRaised
  end
  object Label4: TLabel
    Left = 8
    Top = 228
    Width = 68
    Height = 15
    Caption = #35838#20214#23610#23544':'
  end
  object Label5: TLabel
    Left = 84
    Top = 228
    Width = 38
    Height = 15
    Caption = #23485#24230':'
  end
  object Label6: TLabel
    Left = 196
    Top = 228
    Width = 30
    Height = 15
    Caption = #20687#32032
  end
  object Label7: TLabel
    Left = 84
    Top = 256
    Width = 38
    Height = 15
    Caption = #39640#24230':'
  end
  object Label8: TLabel
    Left = 196
    Top = 256
    Width = 30
    Height = 15
    Caption = #20687#32032
  end
  object Bevel2: TBevel
    Left = 232
    Top = 220
    Width = 9
    Height = 57
    Shape = bsLeftLine
    Style = bsRaised
  end
  object Bevel3: TBevel
    Left = 2
    Top = 280
    Width = 421
    Height = 9
    Shape = bsTopLine
    Style = bsRaised
  end
  object Edit1: TEdit
    Left = 80
    Top = 4
    Width = 337
    Height = 23
    TabOrder = 0
    Text = #20223#30495#21270#23398#23454#39564#23460' '#32593#32476#35838#20214
  end
  object Memo1: TMemo
    Left = 80
    Top = 32
    Width = 337
    Height = 145
    Lines.Strings = (
      #35838#20214#31616#20171':'
    )
    TabOrder = 1
  end
  object Edit2: TEdit
    Left = 80
    Top = 184
    Width = 337
    Height = 23
    TabOrder = 2
    Text = #21046#20316':'
  end
  object Edit3: TEdit
    Left = 124
    Top = 224
    Width = 69
    Height = 23
    TabOrder = 3
    Text = '700'
  end
  object Edit4: TEdit
    Left = 124
    Top = 252
    Width = 69
    Height = 23
    TabOrder = 4
    Text = '500'
  end
  object RadioButton2: TRadioButton
    Left = 252
    Top = 228
    Width = 85
    Height = 17
    Caption = #20840#23631#26041#24335
    TabOrder = 5
  end
  object RadioButton1: TRadioButton
    Left = 252
    Top = 252
    Width = 97
    Height = 17
    Caption = #24102#26377#24037#20855#26639
    Checked = True
    TabOrder = 6
    TabStop = True
  end
  object Button1: TButton
    Left = 240
    Top = 296
    Width = 75
    Height = 25
    Caption = #30830#23450
    TabOrder = 7
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 340
    Top = 296
    Width = 75
    Height = 25
    Caption = #21462#28040
    ModalResult = 2
    TabOrder = 8
  end
end
