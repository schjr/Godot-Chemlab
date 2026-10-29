object DataModule1: TDataModule1
  OldCreateOrder = False
  OnCreate = DataModuleCreate
  Left = 192
  Top = 107
  Height = 375
  Width = 544
  object ADOConnection1: TADOConnection
    LoginPrompt = False
    Mode = cmShareDenyNone
    Provider = 'Microsoft.Jet.OLEDB.4.0'
    Left = 32
    Top = 16
  end
  object ADOQuery1: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    Prepared = True
    SQL.Strings = (
      'select * from eleinfo'
    )
    Left = 32
    Top = 72
    object ADOQuery1elenum: TSmallintField
      FieldName = 'elenum'
      OnGetText = ADOQuery1elenumGetText
    end
    object ADOQuery1finder: TWideStringField
      FieldName = 'finder'
      Size = 80
    end
    object ADOQuery1findtime: TWideStringField
      FieldName = 'findtime'
      Size = 40
    end
    object ADOQuery1howtofind: TWideStringField
      FieldName = 'howtofind'
      Size = 255
    end
    object ADOQuery1nameby: TWideStringField
      FieldName = 'nameby'
      Size = 80
    end
    object ADOQuery1describe1: TMemoField
      FieldName = 'describe1'
      BlobType = ftMemo
    end
    object ADOQuery1source: TMemoField
      FieldName = 'source'
      BlobType = ftMemo
    end
    object ADOQuery1use: TMemoField
      FieldName = 'use'
      BlobType = ftMemo
    end
    object ADOQuery1zhhtest: TAggregateField
      FieldName = 'zhhtest'
      Visible = True
      Active = True
      Expression = 'count(elenum)'
    end
  end
  object ADOQuery2: TADOQuery
    Connection = ADOConnection1
    Parameters = <
      item
        Name = 'finder'
        DataType = ftString
        Size = 1
        Value = '1'
      end
      item
        Name = 'findtime'
        DataType = ftString
        Size = 1
        Value = '1'
      end
      item
        Name = 'howtofind'
        DataType = ftString
        Size = 1
        Value = '1'
      end
      item
        Name = 'nameby'
        DataType = ftString
        Size = 1
        Value = '1'
      end
      item
        Name = 'describe'
        DataType = ftString
        Size = 1
        Value = '1'
      end
      item
        Name = 'source'
        DataType = ftString
        Size = 1
        Value = '1'
      end
      item
        Name = 'use'
        DataType = ftString
        Size = 1
        Value = '1'
      end
      item
        Name = 'elenum'
        DataType = ftString
        Size = 1
        Value = '2'
      end>
    SQL.Strings = (
      'Update eleinfo Set'
      '    finder=:finder, findtime=:findtime, howtofind=:howtofind,'
      '    nameby=:nameby, describe=:describe, source=:source, '
      '    use=:use '
      'where elenum=:elenum'
    )
    Left = 32
    Top = 120
  end
  object ADOQuery3: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    LockType = ltReadOnly
    Parameters = <>
    SQL.Strings = (
      'select * from elements'
    )
    Left = 96
    Top = 16
  end
  object ADOQuery4: TADOQuery
    Connection = ADOConnection1
    Parameters = <>
    SQL.Strings = (
      'select '
    )
    Left = 96
    Top = 72
  end
  object links: TADOQuery
    Connection = ADOConnection1
    CursorType = ctStatic
    Parameters = <>
    SQL.Strings = (
      'select * from linkslib'
    )
    Left = 96
    Top = 128
    object linksid: TAutoIncField
      FieldName = 'id'
    end
    object linkslinkname: TWideStringField
      FieldName = 'linkname'
    end
    object linksmastertable: TWideStringField
      FieldName = 'mastertable'
      Size = 50
    end
    object linksmasterfield: TWideStringField
      FieldName = 'masterfield'
      Size = 50
    end
    object linksmastervalue: TWideStringField
      FieldName = 'mastervalue'
      OnGetText = linksmastervalueGetText
      Size = 100
    end
    object linksslavertable: TWideStringField
      FieldName = 'slavertable'
      Size = 50
    end
    object linksslaverfield: TWideStringField
      FieldName = 'slaverfield'
      Size = 50
    end
    object linksslavervalue: TWideStringField
      FieldName = 'slavervalue'
      OnGetText = linksslavervalueGetText
      Size = 100
    end
  end
  object links_ds: TDataSource
    DataSet = links
    Left = 144
    Top = 128
  end
end
