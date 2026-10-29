object ele2chemFrame: Tele2chemFrame
  Left = 0
  Top = 0
  Width = 375
  Height = 371
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #23435#20307
  Font.Style = []
  ParentFont = False
  TabOrder = 0
  object SpeedButton1: TSpeedButton
    Left = 148
    Top = 137
    Width = 81
    Height = 22
    Caption = #24314#31435#21333#21521#38142#25509
    Flat = True
    OnClick = SpeedButton1Click
  end
  object Label3: TLabel
    Left = 143
    Top = 7
    Width = 52
    Height = 13
    Caption = #38142#25509#21517#31216
  end
  object Label1: TLabel
    Left = 8
    Top = 7
    Width = 52
    Height = 13
    Caption = #34987#38142#25509#23383
  end
  object Label2: TLabel
    Left = 240
    Top = 7
    Width = 39
    Height = 13
    Caption = #38142#25509#23383
  end
  object SpeedButton2: TSpeedButton
    Left = 148
    Top = 159
    Width = 81
    Height = 22
    Caption = #24314#31435#21452#21521#38142#25509
    Flat = True
    OnClick = SpeedButton2Click
  end
  object SpeedButton3: TSpeedButton
    Left = 148
    Top = 49
    Width = 81
    Height = 22
    Caption = #24120#29992#38142#25509#21517#31216
    Flat = True
    OnClick = SpeedButton3Click
  end
  object StringGrid1: TStringGrid
    Left = 8
    Top = 47
    Width = 129
    Height = 290
    ColCount = 1
    FixedCols = 0
    RowCount = 10
    FixedRows = 0
    Options = [goDrawFocusSelected]
    ScrollBars = ssVertical
    TabOrder = 0
    OnClick = StringGrid1Click
  end
  object StringGrid2: TStringGrid
    Left = 239
    Top = 47
    Width = 129
    Height = 290
    ColCount = 1
    FixedCols = 0
    RowCount = 8
    FixedRows = 0
    Options = [goDrawFocusSelected]
    ScrollBars = ssVertical
    TabOrder = 1
    OnClick = StringGrid2Click
  end
  object ComboBox1: TComboBox
    Left = 143
    Top = 23
    Width = 90
    Height = 21
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 2
  end
  object ComboBox2: TComboBox
    Left = 8
    Top = 23
    Width = 129
    Height = 21
    ItemHeight = 13
    TabOrder = 3
    OnChange = ComboBox2Change
    Items.Strings = (
      #21270#23398#20803#32032#21015#34920
      #21270#23398#33647#21697#21015#34920
    )
  end
  object ComboBox3: TComboBox
    Left = 239
    Top = 23
    Width = 129
    Height = 21
    ItemHeight = 13
    TabOrder = 4
    OnChange = ComboBox3Change
    Items.Strings = (
      #21270#23398#20803#32032#21015#34920
      #21270#23398#33647#21697#21015#34920
    )
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 352
    Width = 375
    Height = 19
    Panels = <
      item
        Width = 50
      end>
    SimplePanel = False
  end
end
