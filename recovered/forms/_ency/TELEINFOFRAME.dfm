object eleinfoFrame: TeleinfoFrame
  Left = 0
  Top = 0
  Width = 436
  Height = 411
  Font.Charset = GB2312_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = #23435#20307
  Font.Style = []
  ParentFont = False
  TabOrder = 0
  object Label1: TLabel
    Left = 16
    Top = 16
    Width = 52
    Height = 13
    Caption = #20803#32032#24207#21495
  end
  object SpeedButton1: TSpeedButton
    Left = 264
    Top = 1
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #177
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton2: TSpeedButton
    Left = 288
    Top = 1
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #8451
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton3: TSpeedButton
    Left = 312
    Top = 1
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #945
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton4: TSpeedButton
    Left = 336
    Top = 1
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #946
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton5: TSpeedButton
    Left = 360
    Top = 1
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #947
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton6: TSpeedButton
    Left = 384
    Top = 1
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #948
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton7: TSpeedButton
    Left = 408
    Top = 1
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #963
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton8: TSpeedButton
    Left = 288
    Top = 23
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #8593
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton9: TSpeedButton
    Left = 312
    Top = 23
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #8595
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton10: TSpeedButton
    Left = 264
    Top = 23
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #183
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton11: TSpeedButton
    Left = 336
    Top = 23
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = #215
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object SpeedButton12: TSpeedButton
    Left = 360
    Top = 23
    Width = 23
    Height = 22
    AllowAllUp = True
    Caption = 'p'
    Flat = True
    OnClick = MySpeedButtonClick
  end
  object GroupBox1: TGroupBox
    Left = 16
    Top = 261
    Width = 401
    Height = 142
    Caption = #20803#32032#30340#21457#29616
    TabOrder = 1
    object Label2: TLabel
      Left = 24
      Top = 22
      Width = 39
      Height = 13
      Caption = #21457#29616#20154
    end
    object Label3: TLabel
      Left = 220
      Top = 22
      Width = 52
      Height = 13
      Caption = #21457#29616#26102#38388
    end
    object Label4: TLabel
      Left = 24
      Top = 49
      Width = 52
      Height = 13
      Caption = #21457#29616#36807#31243
    end
    object Label8: TLabel
      Left = 24
      Top = 111
      Width = 52
      Height = 13
      Caption = #21629#21517#30001#26469
    end
    object Edit1: TEdit
      Left = 69
      Top = 18
      Width = 140
      Height = 21
      MaxLength = 80
      TabOrder = 0
      OnEnter = ComboBox1Enter
    end
    object Edit2: TEdit
      Left = 278
      Top = 18
      Width = 115
      Height = 21
      MaxLength = 40
      TabOrder = 1
      OnEnter = ComboBox1Enter
    end
    object Memo3: TMemo
      Left = 80
      Top = 45
      Width = 313
      Height = 54
      ScrollBars = ssVertical
      TabOrder = 2
      OnEnter = Memo4Enter
      OnKeyPress = MyMemoKeyPress
    end
    object Edit3: TEdit
      Left = 80
      Top = 109
      Width = 313
      Height = 21
      MaxLength = 80
      TabOrder = 3
      OnEnter = ComboBox1Enter
    end
  end
  object ComboBox1: TComboBox
    Left = 72
    Top = 12
    Width = 121
    Height = 21
    Style = csDropDownList
    ItemHeight = 13
    TabOrder = 0
    OnChange = ComboBox1Change
    OnEnter = ComboBox1Enter
  end
  object GroupBox2: TGroupBox
    Left = 16
    Top = 45
    Width = 401
    Height = 208
    Caption = #20803#32032#30340#22522#26412#20449#24687
    TabOrder = 2
    object Label5: TLabel
      Left = 24
      Top = 22
      Width = 26
      Height = 13
      Caption = #25551#36848
    end
    object Label6: TLabel
      Left = 24
      Top = 83
      Width = 52
      Height = 13
      Caption = #20803#32032#26469#28304
    end
    object Label7: TLabel
      Left = 24
      Top = 144
      Width = 52
      Height = 13
      Caption = #20803#32032#29992#36884
    end
    object Memo1: TMemo
      Left = 80
      Top = 82
      Width = 313
      Height = 54
      ScrollBars = ssVertical
      TabOrder = 0
      OnEnter = Memo4Enter
      OnKeyPress = MyMemoKeyPress
    end
    object Memo2: TMemo
      Left = 80
      Top = 143
      Width = 313
      Height = 54
      ScrollBars = ssVertical
      TabOrder = 1
      OnEnter = Memo4Enter
      OnKeyPress = MyMemoKeyPress
    end
    object Memo4: TMemo
      Left = 80
      Top = 21
      Width = 313
      Height = 54
      ScrollBars = ssVertical
      TabOrder = 2
      OnEnter = Memo4Enter
      OnKeyPress = MyMemoKeyPress
    end
  end
  object Button1: TButton
    Left = 201
    Top = 10
    Width = 56
    Height = 25
    Caption = #28155#21152
    TabOrder = 3
    OnClick = Button1Click
    OnEnter = ComboBox1Enter
  end
  object OpenPictureDialog1: TOpenPictureDialog
    Left = 39
    Top = 92
  end
end
