object ChemicalSort: TChemicalSort
  Left = 0
  Top = 0
  Width = 181
  Height = 386
  TabOrder = 0
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 181
    Height = 386
    Align = alClient
    BevelOuter = bvNone
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 16
      Width = 48
      Height = 12
      Caption = #33647#21697#21517#31216
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object Label2: TLabel
      Left = 16
      Top = 35
      Width = 48
      Height = 12
      Caption = #21487#36873#33647#21697
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ParentFont = False
    end
    object Edit1: TEdit
      Left = 70
      Top = 12
      Width = 99
      Height = 20
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      MaxLength = 80
      ParentFont = False
      TabOrder = 0
      OnChange = Edit1Change
    end
    object ListBox1: TListBox
      Left = 15
      Top = 50
      Width = 154
      Height = 327
      Font.Charset = ANSI_CHARSET
      Font.Color = clWindowText
      Font.Height = -12
      Font.Name = #23435#20307
      Font.Style = []
      ItemHeight = 12
      ParentFont = False
      TabOrder = 1
      OnClick = ListBox1Click
    end
  end
  object ADOQuery1: TADOQuery
    Connection = DataModule1.ADOConnection1
    LockType = ltReadOnly
    Parameters = <>
    Left = 32
  end
  object ADOQuery2: TADOQuery
    Connection = DataModule1.ADOConnection1
    Parameters = <>
    Left = 64
  end
end
