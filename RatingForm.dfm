object FormRating: TFormRating
  Left = 0
  Top = 0
  Caption = #1056#1077#1081#1090#1080#1085#1075
  ClientHeight = 432
  ClientWidth = 783
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
  object RatingLastTestLabel: TLabel
    Left = 171
    Top = 59
    Width = 114
    Height = 18
    Caption = #1055#1086#1089#1083#1077#1076#1085#1080#1081' '#1090#1077#1089#1090
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object RatingAllTestsLabel: TLabel
    Left = 160
    Top = 238
    Width = 125
    Height = 18
    Caption = #1042#1089#1077' '#1089#1088#1077#1076#1085#1080#1077' '#1073#1072#1083#1083#1099
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object RatingQantityLabel: TLabel
    Left = 184
    Top = 144
    Width = 76
    Height = 18
    Caption = #1042#1089#1077' '#1090#1077#1089#1090#1099
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -15
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
  end
  object NoteLabel: TLabel
    Left = 56
    Top = 288
    Width = 297
    Height = 33
    AutoSize = False
    Caption = 
      #1056#1077#1081#1090#1080#1085#1075' '#1085#1077' '#1087#1086#1082#1072#1079#1099#1074#1072#1077#1090' '#1089#1072#1084#1086#1075#1086' '#1089#1083#1072#1073#1086#1075#1086' '#1088#1077#1079#1091#1083#1100#1090#1072#1090#1072' - '#1086#1085' '#1085#1077' '#1076#1086#1089#1090#1086#1080#1085' ' +
      #1073#1099#1090#1100' '#1090#1072#1084
    EllipsisPosition = epEndEllipsis
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -13
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    Layout = tlCenter
    WordWrap = True
  end
  object BackButton: TButton
    Left = 138
    Top = 344
    Width = 159
    Height = 56
    Caption = #1053#1072#1079#1072#1076
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 0
    OnClick = BackButtonClick
  end
  object RatingLastTestButton: TButton
    Left = 24
    Top = 21
    Width = 393
    Height = 37
    Caption = #1050#1072#1088#1084#1072
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 1
    OnClick = RatingLastTestButtonClick
  end
  object RatingQantityButton: TButton
    Left = 24
    Top = 200
    Width = 393
    Height = 40
    Caption = #1059#1087#1086#1088#1089#1090#1074#1086
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 2
    OnClick = RatingQantityButtonClick
  end
  object RatingAllTestsButton: TButton
    Left = 24
    Top = 104
    Width = 393
    Height = 42
    Caption = #1053#1072#1089#1090#1086#1081#1095#1080#1074#1086#1089#1090#1100
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 3
    OnClick = RatingAllTestsButtonClick
  end
  object ExitMemo: TMemo
    Left = 496
    Top = 8
    Width = 193
    Height = 400
    Alignment = taCenter
    Font.Charset = RUSSIAN_CHARSET
    Font.Color = clWindowText
    Font.Height = -19
    Font.Name = 'Times New Roman'
    Font.Style = [fsBold, fsItalic]
    ParentFont = False
    TabOrder = 4
  end
end
