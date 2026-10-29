object testsql: Ttestsql
  Left = 192
  Top = 107
  Width = 537
  Height = 375
  Caption = 'testsql'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Memo1: TMemo
    Left = 16
    Top = 16
    Width = 497
    Height = 137
    ScrollBars = ssVertical
    TabOrder = 0
  end
  object DBGrid1: TDBGrid
    Left = 16
    Top = 192
    Width = 497
    Height = 145
    DataSource = DataSource1
    TabOrder = 1
    TitleFont.Charset = DEFAULT_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -11
    TitleFont.Name = 'MS Sans Serif'
    TitleFont.Style = []
  end
  object Button1: TButton
    Left = 131
    Top = 160
    Width = 75
    Height = 25
    Caption = #36816#34892
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 234
    Top = 160
    Width = 75
    Height = 25
    Caption = #20445#23384
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 336
    Top = 160
    Width = 75
    Height = 25
    Caption = #36733#20837
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 440
    Top = 160
    Width = 75
    Height = 25
    Caption = 'Button4'
    TabOrder = 5
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 248
    Top = 0
    Width = 75
    Height = 25
    Caption = 'Button5'
    TabOrder = 6
    OnClick = Button5Click
  end
  object DataSource1: TDataSource
    DataSet = ADOQuery1
    Left = 16
    Top = 160
  end
  object OpenDialog1: TOpenDialog
    Filter = 'Txt File|*.txt'
    Left = 72
    Top = 144
  end
  object SaveDialog1: TSaveDialog
    Filter = 'Txt File|*.txt'
    Left = 104
    Top = 144
  end
  object ADOQuery1: TADOQuery
    Connection = DataModule1.ADOConnection1
    Parameters = <>
    Left = 48
    Top = 160
  end
end
