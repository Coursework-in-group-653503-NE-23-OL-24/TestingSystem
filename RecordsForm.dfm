object FormRecords: TFormRecords
  Left = 0
  Top = 0
  Caption = #1056#1077#1082#1086#1088#1076#1099
  ClientHeight = 532
  ClientWidth = 861
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object MoreResultsLabel: TLabel
    Left = 40
    Top = 239
    Width = 207
    Height = 15
    Caption = '('#1055#1088#1086#1096#1077#1083' '#1085#1072#1080#1073#1086#1083#1100#1096#1077#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1090#1077#1089#1090#1086#1074')'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object LessResultsLabel: TLabel
    Left = 324
    Top = 239
    Width = 207
    Height = 15
    Caption = '('#1055#1088#1086#1096#1077#1083' '#1085#1072#1080#1084#1077#1085#1100#1096#1077#1077' '#1082#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1090#1077#1089#1090#1086#1074')'
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -12
    Font.Name = 'Times New Roman'
    Font.Style = []
    ParentFont = False
  end
  object TheMostLabel: TLabel
    Left = 200
    Top = 34
    Width = 146
    Height = 28
    Caption = #1057#1072#1084#1099#1077'-'#1089#1072#1084#1099#1077
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object BackButton: TButton
    Left = 440
    Top = 491
    Width = 411
    Height = 33
    Caption = #1042#1077#1088#1085#1091#1090#1100#1089#1103' '#1082' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1102
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = BackButtonClick
  end
  object BestResultButton: TButton
    Left = 22
    Top = 96
    Width = 233
    Height = 57
    Caption = #1051#1091#1095#1096#1080#1081' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = BestResultButtonClick
  end
  object WarseResultButton: TButton
    Left = 306
    Top = 96
    Width = 233
    Height = 57
    Caption = #1061#1091#1076#1096#1080#1081' '#1088#1077#1079#1091#1083#1100#1090#1072#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = WarseResultButtonClick
  end
  object MoreResultsButton: TButton
    Left = 22
    Top = 184
    Width = 233
    Height = 49
    Caption = #1059#1087#1086#1088#1085#1099#1081' '#1095#1077#1083#1086#1074#1077#1082
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = MoreResultsButtonClick
  end
  object LessResultsButton: TButton
    Left = 306
    Top = 184
    Width = 233
    Height = 49
    Caption = #1051#1077#1085#1080#1074#1099#1081' '#1095#1077#1083#1086#1074#1077#1082
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 4
    OnClick = LessResultsButtonClick
  end
  object SumOfResultsButton: TButton
    Left = 96
    Top = 304
    Width = 417
    Height = 41
    Caption = #1054#1073#1097#1072#1103' '#1089#1091#1084#1084#1072' '#1087#1088#1086#1081#1076#1077#1085#1085#1099#1093' '#1090#1077#1089#1090#1086#1074
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 5
    OnClick = SumOfResultsButtonClick
  end
  object AverageScoreButton: TButton
    Left = 96
    Top = 367
    Width = 417
    Height = 42
    Caption = #1059#1089#1087#1077#1074#1072#1077#1084#1086#1089#1090#1100' ('#1089#1088#1077#1076#1085#1080#1081' '#1073#1072#1083#1083') '#1087#1086#1083#1100#1079#1086#1074#1072#1090#1077#1083#1077#1081
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 6
    OnClick = AverageScoreButtonClick
  end
  object RatingButton: TButton
    Left = 616
    Top = 112
    Width = 137
    Height = 97
    Caption = #1056#1077#1081#1090#1080#1085#1075
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 7
    OnClick = RatingButtonClick
  end
  object AllGroupsButton: TButton
    Left = 96
    Top = 432
    Width = 417
    Height = 41
    Caption = #1043#1088#1091#1087#1087#1099', '#1087#1088#1080#1085#1103#1074#1096#1080#1077' '#1091#1095#1072#1089#1090#1080#1077' '#1074' '#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1080
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 8
    OnClick = AllGroupsButtonClick
  end
  object ExitMemo: TMemo
    Left = 640
    Top = 312
    Width = 185
    Height = 137
    Lines.Strings = (
      'ExitMemo')
    TabOrder = 9
    Visible = False
  end
end
