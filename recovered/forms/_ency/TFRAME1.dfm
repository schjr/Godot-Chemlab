object Frame1: TFrame1
  Left = 0
  Top = 0
  Width = 443
  Height = 277
  Align = alClient
  TabOrder = 0
  object CppWebBrowser1: TCppWebBrowser
    Left = 0
    Top = 0
    Width = 443
    Height = 277
    TabStop = True
    Align = alClient
    TabOrder = 0
    OnBeforeNavigate2 = CppWebBrowser1BeforeNavigate2
    ControlData = {
      4C000000C92D0000A11C00000000000000000000000000000000000000000000
      000000004C000000000000000000000001000000E0D057007335CF11AE690800
      2B2E126208000000000000004C0000000114020000000000C000000000000046
      8000000000000000000000000000000000000000000000000000000000000000
      00000000000000000100000000000000000000000000000000000000}
  end
  object ADOQuery1: TADOQuery
    Connection = DataModule1.ADOConnection1
    LockType = ltReadOnly
    Parameters = <>
    Left = 232
    Top = 16
  end
end
