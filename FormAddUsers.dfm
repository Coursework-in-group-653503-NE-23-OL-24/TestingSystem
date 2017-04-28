object FAddUser: TFAddUser
  Left = 0
  Top = 0
  Caption = #1044#1086#1073#1072#1074#1083#1077#1085#1080#1077' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
  ClientHeight = 415
  ClientWidth = 740
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object NameLabel: TLabel
    Left = 24
    Top = 112
    Width = 118
    Height = 22
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1080#1084#1103':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object SurnameLabel: TLabel
    Left = 24
    Top = 168
    Width = 167
    Height = 22
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1092#1072#1084#1080#1083#1080#1102':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object GroupLabel: TLabel
    Left = 24
    Top = 224
    Width = 125
    Height = 22
    Caption = #1053#1086#1084#1077#1088' '#1075#1088#1091#1087#1087#1099':'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object NameBox: TEdit
    Left = 248
    Top = 109
    Width = 217
    Height = 33
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
    Text = #1048#1084#1103
    OnChange = NameBoxChange
  end
  object SurnameBox: TEdit
    Left = 248
    Top = 165
    Width = 217
    Height = 33
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 1
    Text = #1060#1072#1084#1080#1083#1080#1103
    OnChange = SurnameBoxChange
  end
  object GroupBox: TEdit
    Left = 248
    Top = 224
    Width = 217
    Height = 33
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 2
    Text = #1053#1086#1084#1077#1088' '#1075#1088#1091#1087#1087#1099
    OnChange = GroupBoxChange
  end
  object AddButton: TButton
    Left = 48
    Top = 336
    Width = 273
    Height = 41
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = AddButtonClick
  end
  object ReturnButton: TButton
    Left = 392
    Top = 336
    Width = 289
    Height = 41
    Caption = #1042#1077#1088#1085#1091#1090#1100#1089#1103' '#1082' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1102
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 4
    OnClick = ReturnButtonClick
  end
end
