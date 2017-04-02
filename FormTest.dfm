object FTest: TFTest
  Left = 55
  Top = 0
  Caption = 'FTest'
  ClientHeight = 739
  ClientWidth = 1366
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesigned
  OnActivate = FormActivate
  OnClose = FormClose
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 23
  object LabelEnd: TLabel
    Left = 162
    Top = 696
    Width = 269
    Height = 29
    Caption = #1058#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1077' '#1086#1082#1086#1085#1095#1077#1085#1086
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object LabelResult: TLabel
    Left = 378
    Top = 696
    Width = 140
    Height = 29
    Caption = #1042#1099' '#1085#1072#1073#1088#1072#1083#1080' '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object LabelWrongAnswers: TLabel
    Left = 504
    Top = 696
    Width = 215
    Height = 29
    Caption = 'LabelWrongAnswers'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object LabelEnterAnswer: TLabel
    Left = 120
    Top = 347
    Width = 168
    Height = 29
    Caption = #1042#1074#1077#1076#1080#1090#1077' '#1086#1090#1074#1077#1090':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object LabelMark: TLabel
    Left = 32
    Top = 691
    Width = 99
    Height = 29
    Caption = #1054#1094#1077#1085#1082#1072': '
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    Visible = False
  end
  object RadioGroupVariants: TRadioGroup
    Left = 8
    Top = 425
    Width = 1430
    Height = 105
    Caption = #1042#1072#1088#1080#1072#1085#1090#1099' '#1086#1090#1074#1077#1090#1086#1074
    Columns = 2
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    Visible = False
  end
  object MemoQuestionText: TMemo
    Left = 20
    Top = 48
    Width = 1430
    Height = 91
    TabStop = False
    Color = clBtnFace
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    ReadOnly = True
    TabOrder = 1
    Visible = False
  end
  object ButtonAnswer: TButton
    Left = 400
    Top = 576
    Width = 193
    Height = 41
    Cursor = crHandPoint
    Caption = #1054#1090#1074#1077#1090#1080#1090#1100
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -27
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 2
    Visible = False
    OnClick = ButtonAnswerClick
  end
  object ButtonGoBack: TButton
    Left = 696
    Top = 663
    Width = 209
    Height = 51
    Caption = #1042#1086#1079#1074#1088#1072#1090' '#1074' '#1084#1077#1085#1102
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 3
    Visible = False
    WordWrap = True
    OnClick = ButtonGoBackClick
  end
  object ProgressBar1: TProgressBar
    Left = 20
    Top = 8
    Width = 1430
    Height = 25
    BarColor = clLime
    TabOrder = 4
  end
  object StatusBar1: TStatusBar
    Left = 0
    Top = 720
    Width = 1366
    Height = 19
    Color = clPurple
    Panels = <
      item
        Style = psOwnerDraw
        Width = 50
      end>
  end
  object ButtonCreateDocument: TButton
    Left = 911
    Top = 663
    Width = 242
    Height = 51
    Caption = #1054#1092#1086#1088#1084#1080#1090#1100' '#1076#1086#1082#1091#1084#1077#1085#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 6
    Visible = False
    OnClick = ButtonCreateDocumentClick
  end
  object ButtonSaveTest: TButton
    Left = 1159
    Top = 663
    Width = 242
    Height = 51
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1090#1077#1089#1090
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 7
    Visible = False
    OnClick = ButtonSaveTestClick
  end
  object EditAnswer: TEdit
    Left = 378
    Top = 344
    Width = 140
    Height = 37
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -24
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
    TabOrder = 8
    Visible = False
  end
  object SaveDialog1: TSaveDialog
    InitialDir = 'd:\\'#1082#1091#1088#1089#1086#1074#1086#1081' '#1087#1088#1086#1077#1082#1090'\\'#1090#1077#1089#1090#1080#1088#1086#1074#1072#1085#1080#1103
    Title = #1042#1099#1073#1077#1088#1080#1090#1077' '#1088#1072#1089#1087#1086#1083#1086#1078#1077#1085#1080#1077' '#1092#1072#1081#1083#1072
    Left = 1312
    Top = 368
  end
end
