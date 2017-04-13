object UsersF: TUsersF
  Left = 0
  Top = 0
  Caption = #1048#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077
  ClientHeight = 472
  ClientWidth = 671
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnActivate = FormActivate
  PixelsPerInch = 96
  TextHeight = 13
  object WelkomeLabel: TLabel
    Left = 112
    Top = 24
    Width = 436
    Height = 24
    Caption = #1042#1099#1073#1077#1088#1080#1090#1077', '#1095#1090#1086' '#1093#1086#1090#1080#1090#1077' '#1091#1079#1085#1072#1090#1100' '#1086' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clNavy
    Font.Height = -21
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object LastResultButton: TButton
    Left = 40
    Top = 96
    Width = 585
    Height = 49
    Caption = #1056#1077#1079#1091#1083#1100#1090#1072#1090' '#1087#1086#1089#1083#1077#1076#1085#1077#1075#1086' '#1087#1088#1086#1081#1076#1077#1085#1085#1086#1075#1086' '#1090#1077#1089#1090#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clRed
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = LastResultButtonClick
  end
  object AllTestsButton: TButton
    Left = 40
    Top = 168
    Width = 585
    Height = 49
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1087#1088#1086#1081#1076#1077#1085#1085#1099#1093' '#1090#1077#1089#1090#1086#1074
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clBlack
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = AllTestsButtonClick
  end
  object AverageScoreButton: TButton
    Left = 40
    Top = 240
    Width = 585
    Height = 49
    Caption = #1057#1088#1077#1076#1085#1080#1081' '#1073#1072#1083#1083' '#1079#1072' '#1074#1089#1077' '#1090#1077#1089#1090#1099
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = AverageScoreButtonClick
  end
  object InformationButton: TButton
    Left = 40
    Top = 312
    Width = 585
    Height = 49
    Caption = #1042#1089#1103' '#1080#1085#1092#1086#1088#1084#1072#1094#1080#1103' '#1086' '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = InformationButtonClick
  end
  object BackToTestButton: TButton
    Left = 40
    Top = 392
    Width = 585
    Height = 49
    Caption = #1042#1077#1088#1085#1091#1090#1100#1089#1103' '#1082' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1102
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 4
    OnClick = BackToTestButtonClick
  end
end
