object inputForm: TinputForm
  Left = 195
  Top = 102
  Width = 447
  Height = 466
  Caption = 'inputForm'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  KeyPreview = True
  OldCreateOrder = False
  Position = poDesktopCenter
  OnCreate = FormCreate
  OnShow = FormShow
  PixelsPerInch = 96
  TextHeight = 13
  object PageControl1: TPageControl
    Left = 0
    Top = 0
    Width = 439
    Height = 439
    ActivePage = TabSheet1
    Align = alClient
    Font.Charset = GB2312_CHARSET
    Font.Color = clWindowText
    Font.Height = -14
    Font.Name = #23435#20307
    Font.Style = []
    ParentFont = False
    Style = tsFlatButtons
    TabOrder = 0
    object TabSheet1: TTabSheet
      Caption = #20803#32032#20449#24687
      inline eleinfoFrame1: TeleinfoFrame
        Width = 431
        Height = 407
        Align = alClient
      end
    end
    object TabSheet2: TTabSheet
      Caption = #21270#23398#33647#21697
      ImageIndex = 1
      inline cheminfoFrame1: TcheminfoFrame
        Width = 431
        Height = 407
        Align = alClient
      end
    end
    object TabSheet3: TTabSheet
      Caption = #20851#32852#35774#32622
      ImageIndex = 2
      object PageControl2: TPageControl
        Left = 0
        Top = 0
        Width = 431
        Height = 407
        ActivePage = TabSheet4
        Align = alClient
        BiDiMode = bdLeftToRight
        MultiLine = True
        ParentBiDiMode = False
        TabOrder = 0
        TabPosition = tpBottom
        OnChange = PageControl2Change
        object TabSheet4: TTabSheet
          Caption = #21019#24314#20851#32852
          inline ele2chemFrame1: Tele2chemFrame
            Width = 423
            Height = 378
            Align = alClient
            inherited ComboBox1: TComboBox
              Items.Strings = (
                #30456#20851#21270#21512#29289
              )
            end
            inherited StatusBar1: TStatusBar
              Top = 359
              Width = 423
            end
          end
        end
        object TabSheet5: TTabSheet
          Caption = #31649#29702#20851#32852
          ImageIndex = 1
          inline linksmanagerFrame1: TlinksmanagerFrame
            Width = 423
            Height = 378
            Align = alClient
            inherited DBGrid1: TDBGrid
              Columns = <
                item
                  Expanded = False
                  FieldName = 'id'
                  PickList.Strings = (

                  )
                  Visible = False
                end
                item
                  Expanded = False
                  FieldName = 'linkname'
                  PickList.Strings = (

                  )
                  Title.Caption = #38142#25509#21517#31216
                  Width = 120
                  Visible = True
                end
                item
                  Expanded = False
                  FieldName = 'mastertable'
                  PickList.Strings = (

                  )
                  Title.Caption = #20027#34920#21517#31216
                  Visible = False
                end
                item
                  Expanded = False
                  FieldName = 'masterfield'
                  PickList.Strings = (

                  )
                  Visible = False
                end
                item
                  Expanded = False
                  FieldName = 'mastervalue'
                  PickList.Strings = (

                  )
                  Title.Caption = #34987#38142#25509#23383
                  Width = 120
                  Visible = True
                end
                item
                  Expanded = False
                  FieldName = 'slavertable'
                  PickList.Strings = (

                  )
                  Title.Caption = #20174#34920#21517#31216
                  Visible = False
                end
                item
                  Expanded = False
                  FieldName = 'slaverfield'
                  PickList.Strings = (

                  )
                  Visible = False
                end
                item
                  Expanded = False
                  FieldName = 'slavervalue'
                  PickList.Strings = (

                  )
                  Title.Caption = #38142#25509#23383
                  Width = 120
                  Visible = True
                end>
            end
          end
        end
      end
    end
  end
end
