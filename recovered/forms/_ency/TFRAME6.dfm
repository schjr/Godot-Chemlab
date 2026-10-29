object Frame6: TFrame6
  Left = 0
  Top = 0
  Width = 293
  Height = 361
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 293
    Height = 113
    Align = alTop
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 8
      Top = 6
      Width = 60
      Height = 12
      Caption = #26816#32034#33539#22260#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object Label3: TLabel
      Left = 8
      Top = 32
      Width = 60
      Height = 12
      Caption = #26816#32034#26465#20214#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 8
      Top = 59
      Width = 60
      Height = 12
      Caption = #26816#32034#20869#23481#65306
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object ComboBox1: TComboBox
      Left = 66
      Top = 2
      Width = 127
      Height = 20
      Style = csDropDownList
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ItemHeight = 12
      ParentFont = False
      TabOrder = 0
      Items.Strings = (
        #25152#26377#33539#22260
        #20803#32032#24207#21495
        #20803#32032#21457#29616#20154
        #20803#32032#21457#29616#26102#38388
        #20803#32032#25551#36848
        #20803#32032#26469#28304
        #20803#32032#29992#36884
        #20803#32032#36741#21161#36164#26009
      )
    end
    object ComboBox2: TComboBox
      Left = 66
      Top = 28
      Width = 103
      Height = 20
      Style = csDropDownList
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ItemHeight = 12
      ParentFont = False
      TabOrder = 1
      Items.Strings = (
        #23436#20840#21305#37197
        #27169#31946#21305#37197
      )
    end
    object Edit1: TEdit
      Left = 66
      Top = 54
      Width = 127
      Height = 20
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 2
    end
    object Button1: TButton
      Left = 7
      Top = 81
      Width = 60
      Height = 21
      Caption = #26816#32034
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
      TabOrder = 3
      OnClick = Button1Click
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 113
    Width = 293
    Height = 229
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 1
    object ListBox1: TListBox
      Left = 0
      Top = 0
      Width = 293
      Height = 229
      Align = alClient
      Font.Charset = GB2312_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = #23435#20307
      Font.Style = []
      ItemHeight = 13
      ParentFont = False
      TabOrder = 0
      OnClick = ListBox1Click
      OnMouseMove = ListBox1MouseMove
    end
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 342
    Width = 293
    Height = 19
    Panels = <>
    SimplePanel = True
  end
end
