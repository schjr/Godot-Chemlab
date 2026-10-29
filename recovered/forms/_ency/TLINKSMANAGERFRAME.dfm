object linksmanagerFrame: TlinksmanagerFrame
  Left = 0
  Top = 0
  Width = 429
  Height = 372
  TabOrder = 0
  object Label1: TLabel
    Left = 10
    Top = 16
    Width = 52
    Height = 13
    Caption = #38142#25509#21517#31216
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
  end
  object DBGrid1: TDBGrid
    Left = 8
    Top = 72
    Width = 409
    Height = 289
    DataSource = DataModule1.links_ds
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    TitleFont.Charset = GB2312_CHARSET
    TitleFont.Color = clWindowText
    TitleFont.Height = -13
    TitleFont.Name = #23435#20307
    TitleFont.Style = []
    OnDblClick = DBGrid1DblClick
    Columns = <
      item
        Expanded = False
        FieldName = 'id'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'linkname'
        Title.Caption = #38142#25509#21517#31216
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'mastertable'
        Title.Caption = #20027#34920#21517#31216
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'masterfield'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'mastervalue'
        Title.Caption = #34987#38142#25509#23383
        Width = 120
        Visible = True
      end
      item
        Expanded = False
        FieldName = 'slavertable'
        Title.Caption = #20174#34920#21517#31216
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'slaverfield'
        Visible = False
      end
      item
        Expanded = False
        FieldName = 'slavervalue'
        Title.Caption = #38142#25509#23383
        Width = 120
        Visible = True
      end>
  end
  object Edit1: TEdit
    Left = 71
    Top = 13
    Width = 338
    Height = 21
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 1
  end
  object Button1: TButton
    Left = 43
    Top = 43
    Width = 97
    Height = 25
    Caption = #20462#25913#38142#25509#21517#31216
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 164
    Top = 43
    Width = 97
    Height = 25
    Caption = #21024#38500#24403#21069#35760#24405
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 285
    Top = 43
    Width = 97
    Height = 25
    Caption = #26816#32034#38142#25509#21517#31216
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    TabOrder = 4
    OnClick = Button3Click
  end
end
