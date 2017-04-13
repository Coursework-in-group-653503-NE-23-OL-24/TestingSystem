object FStart: TFStart
  Left = 0
  Top = 0
  Caption = #1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1087#1086' '#1080#1089#1090#1086#1088#1080#1080
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
  object WelkomeLabel: TLabel
    Left = 256
    Top = 32
    Width = 189
    Height = 25
    Caption = #1044#1086#1073#1088#1086' '#1087#1086#1078#1072#1083#1086#1074#1072#1090#1100'!'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -21
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object ChooseLabel: TLabel
    Left = 8
    Top = 91
    Width = 219
    Height = 23
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103':'
  end
  object ButtonStartRandomTest: TButton
    Left = 320
    Top = 312
    Width = 145
    Height = 73
    Caption = #1057#1083#1091#1095#1072#1081#1085#1086#1077' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 0
    WordWrap = True
    OnClick = ButtonStartRandomTestClick
  end
  object ButtonSettings: TButton
    Left = 118
    Top = 312
    Width = 145
    Height = 73
    Caption = #1053#1072#1089#1090#1088#1086#1081#1082#1080
    TabOrder = 1
    OnClick = ButtonSettingsClick
  end
  object ButtonStartCreatedTest: TButton
    Left = 516
    Top = 312
    Width = 145
    Height = 73
    Caption = #1057#1086#1093#1088#1072#1085#1077#1085#1085#1086#1077' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077
    TabOrder = 2
    WordWrap = True
    OnClick = ButtonStartCreatedTestClick
  end
  object ComboBoxUsers: TComboBox
    Left = 233
    Top = 88
    Width = 344
    Height = 31
    TabOrder = 3
    OnChange = ComboBoxUsersChange
  end
  object AddButton: TButton
    Left = 618
    Top = 65
    Width = 143
    Height = 78
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1103
    TabOrder = 4
    WordWrap = True
    OnClick = AddButtonClick
  end
  object NameBox: TEdit
    Left = 320
    Top = 184
    Width = 370
    Height = 31
    BiDiMode = bdLeftToRight
    ParentBiDiMode = False
    TabOrder = 5
    Text = #1042#1074#1077#1076#1080#1090#1077' '#1080#1084#1103', '#1092#1072#1084#1080#1083#1080#1102' '#1080' '#1075#1088#1091#1087#1087#1091
    Visible = False
    OnClick = NameBoxClick
  end
  object OKButton: TButton
    Left = 696
    Top = 187
    Width = 65
    Height = 25
    Caption = 'OK'
    TabOrder = 6
    Visible = False
    OnClick = OKButtonClick
  end
  object ButtonOfUsers: TButton
    Left = 8
    Top = 167
    Width = 289
    Height = 66
    Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077
    TabOrder = 7
    OnClick = ButtonOfUsersClick
  end
  object OpenDialog1: TOpenDialog
    Left = 544
    Top = 496
  end
end
