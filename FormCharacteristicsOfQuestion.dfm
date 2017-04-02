object FAddingQuestion: TFAddingQuestion
  Left = 0
  Top = 0
  Caption = 'FAddingQuestion'
  ClientHeight = 498
  ClientWidth = 891
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -19
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 23
  object LabelVariants: TLabel
    Left = 48
    Top = 151
    Width = 157
    Height = 23
    Caption = #1042#1072#1088#1080#1072#1085#1090#1099' '#1086#1090#1074#1077#1090#1072':'
  end
  object LabelDifficulty: TLabel
    Left = 48
    Top = 409
    Width = 179
    Height = 23
    Caption = #1057#1083#1086#1078#1085#1086#1089#1090#1100' '#1074#1086#1087#1088#1086#1089#1072':'
  end
  object AddingQuestion: TButton
    Left = 490
    Top = 409
    Width = 169
    Height = 57
    Caption = #1044#1086#1073#1072#1074#1080#1090#1100' '#1074#1086#1087#1088#1086#1089
    TabOrder = 0
  end
  object ChoosingTypeOfQuestion: TComboBox
    Left = 168
    Top = 8
    Width = 457
    Height = 31
    TabOrder = 1
    Text = #1058#1080#1087' '#1074#1086#1087#1088#1086#1089#1072
    Items.Strings = (
      '1.'#1055#1088#1086#1089#1090#1086#1081' (2 '#1074#1072#1088#1080#1072#1085#1090#1072' ('#1076#1072','#1085#1077#1090') )'
      '2.'#1057#1090#1072#1085#1076#1072#1088#1090#1085#1099#1081' (4 '#1074#1072#1088#1080#1072#1085#1090#1072', 1 '#1074#1077#1088#1085#1099#1081')'
      '3.'#1057#1083#1086#1078#1085#1099#1081' (6 '#1074#1072#1088#1080#1072#1085#1090#1086#1074', 1 '#1074#1077#1088#1085#1099#1081')')
  end
  object QuestionText: TMemo
    Left = 48
    Top = 45
    Width = 721
    Height = 100
    Lines.Strings = (
      #1060#1086#1088#1084#1091#1083#1080#1088#1086#1074#1082#1072' '#1074#1086#1087#1088#1086#1089#1072)
    MaxLength = 600
    TabOrder = 2
  end
  object Variant1: TEdit
    Left = 48
    Top = 183
    Width = 329
    Height = 31
    TabOrder = 3
    Text = '1.'
  end
  object Variant2: TEdit
    Left = 48
    Top = 220
    Width = 329
    Height = 31
    TabOrder = 4
    Text = '2.'
  end
  object Variant3: TEdit
    Left = 48
    Top = 257
    Width = 329
    Height = 31
    TabOrder = 5
    Text = '3.'
    Visible = False
  end
  object Variant4: TEdit
    Left = 48
    Top = 294
    Width = 329
    Height = 31
    TabOrder = 6
    Text = '4.'
    Visible = False
  end
  object Variant5: TEdit
    Left = 48
    Top = 331
    Width = 329
    Height = 31
    TabOrder = 7
    Text = '5.'
    Visible = False
  end
  object Variant6: TEdit
    Left = 48
    Top = 368
    Width = 329
    Height = 31
    TabOrder = 8
    Text = '6.'
    Visible = False
  end
  object Difficulty: TEdit
    Left = 48
    Top = 438
    Width = 179
    Height = 31
    TabOrder = 9
    Text = '1'
  end
end
