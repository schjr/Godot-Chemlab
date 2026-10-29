object lookupConcepts: TlookupConcepts
  Left = 0
  Top = 0
  Width = 213
  Height = 432
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 213
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
        #27010#24565#21517#31216
        #27010#24565#23450#20041
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
  object StatusBar1: TStatusBar
    Left = 0
    Top = 413
    Width = 213
    Height = 19
    Panels = <>
    SimplePanel = True
  end
  object ListBox1: TListBox
    Left = 0
    Top = 113
    Width = 213
    Height = 300
    Align = alClient
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ItemHeight = 13
    ParentFont = False
    TabOrder = 2
  end
  object ADOQuery1: TADOQuery
    Connection = DataModule1.ADOConnection1
    Parameters = <>
    Left = 112
    Top = 80
  end
end
