object FStart: TFStart
  Left = 0
  Top = 0
  Caption = 'FStart'
  ClientHeight = 600
  ClientWidth = 800
  Color = clBtnFace
  UseDockManager = True
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 23
  object Label1: TLabel
    Left = 288
    Top = 32
    Width = 222
    Height = 23
    Caption = #1044#1086#1073#1088#1086' '#1087#1086#1078#1072#1083#1086#1074#1072#1090#1100'!'
  end
  object Label2: TLabel
    Left = 44
    Top = 123
    Width = 219
    Height = 23
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103':'
  end
  object ButtonStartRandomTest: TButton
    Left = 269
    Top = 248
    Width = 145
    Height = 73
    Caption = #1057#1083#1091#1095#1072#1081#1085#1086#1077' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 0
    WordWrap = True
    OnClick = ButtonStartRandomTestClick
  end
  object ButtonSettings: TButton
    Left = 118
    Top = 248
    Width = 145
    Height = 73
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
    TabOrder = 1
    OnClick = ButtonSettingsClick
  end
  object ButtonStartCreatedTest: TButton
    Left = 420
    Top = 248
    Width = 145
    Height = 73
    Caption = #1057#1086#1093#1088#1072#1085#1077#1085#1085#1086#1077' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 2
    WordWrap = True
    OnClick = ButtonStartCreatedTestClick
  end
  object ComboBoxUsers: TComboBox
    Left = 288
    Top = 120
    Width = 145
    Height = 31
    TabOrder = 3
    OnChange = ComboBoxUsersChange
  end
  object Button1: TButton
    Left = 474
    Top = 97
    Width = 143
    Height = 78
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    TabOrder = 4
    WordWrap = True
    OnClick = Button1Click
  end
  object NameBox: TEdit
    Left = 474
    Top = 200
    Width = 143
    Height = 31
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    TabOrder = 5
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1080#1084#1103
    Visible = False
    OnClick = NameBoxClick
  end
  object OKButton: TButton
    Left = 632
    Top = 203
    Width = 65
    Height = 25
    Caption = 'OK'
    TabOrder = 6
    Visible = False
    OnClick = OKButtonClick
  end
  object OpenDialog1: TOpenDialog
    Left = 544
    Top = 496
  end
end
