//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitQuestion.h"
#include "FormQuestion.h"
#include "FormCharacteristicsOfQuestion.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFAddingQuestion *FAddingQuestion;
//---------------------------------------------------------------------------
__fastcall TFAddingQuestion::TFAddingQuestion(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
/*
void __fastcall TFAddingQuestion::QuestionTextClick(TObject *Sender)
{
	QuestionText->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFAddingQuestion::QuestionTextEnter(TObject *Sender)
{
	QuestionText->Lines->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFAddingQuestion::ChoosingTypeOfQuestionExit(TObject *Sender)
{
	switch (ChoosingTypeOfQuestion->ItemIndex) {
		case 0:
			if (Variant3->Visible == true) Variant3->Visible =false;
			if (Variant4->Visible == true) Variant4->Visible =false;
			if (Variant5->Visible == true) Variant5->Visible =false;
			if (Variant6->Visible == true) Variant6->Visible =false;
		case 1:
			Variant3->Visible=true;
			Variant4->Visible=true;
			if (Variant5->Visible == true) Variant5->Visible =false;
			if (Variant6->Visible == true) Variant6->Visible =false;
			break;
		case 2:
			Variant3->Visible=true;
			Variant4->Visible=true;
			Variant5->Visible=true;
			Variant6->Visible=true;
			break;
	}
}
//---------------------------------------------------------------------------
void __fastcall TFAddingQuestion::DifficultyClick(TObject *Sender)
{
	Difficulty->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFAddingQuestion::DifficultyEnter(TObject *Sender)
{
	Difficulty->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFAddingQuestion::DifficultyExit(TObject *Sender)
{
	if (Difficulty->Text == "") {
		Difficulty->Text = "1";
	}
}
//---------------------------------------------------------------------------
bool isDataEntered(){
	bool isRight=true;
	switch (FAddingQuestion->ChoosingTypeOfQuestion->ItemIndex) {
		case 0:
			if (FAddingQuestion->Variant1->Text == "") isRight=false;
			if (FAddingQuestion->Variant2->Text == "") isRight=false;
			break;
		case 1:
			if (FAddingQuestion->Variant1->Text == "") isRight=false;
			if (FAddingQuestion->Variant2->Text == "") isRight=false;
			if (FAddingQuestion->Variant3->Text == "") isRight=false;
			if (FAddingQuestion->Variant4->Text == "") isRight=false;
			break;
		case 2:
			if (FAddingQuestion->Variant1->Text == "") isRight=false;
			if (FAddingQuestion->Variant2->Text == "") isRight=false;
			if (FAddingQuestion->Variant3->Text == "") isRight=false;
			if (FAddingQuestion->Variant4->Text == "") isRight=false;
			if (FAddingQuestion->Variant5->Text == "") isRight=false;
			if (FAddingQuestion->Variant6->Text == "") isRight=false;
			break;
	}
	if (FAddingQuestion->ChoosingTypeOfQuestion->ItemIndex == -1) isRight=false;
	if (FAddingQuestion->QuestionText->Lines->Strings[0] == "") isRight=false;
	return isRight;
}

void __fastcall TFAddingQuestion::AddingQuestionClick(TObject *Sender)
{
	/*switch (ChoosingTypeOfQuestion->ItemIndex) {
		case 0:
			if (Variant3->Visible == true) Variant3->Visible =false;
			if (Variant4->Visible == true) Variant4->Visible =false;
			if (Variant5->Visible == true) Variant5->Visible =false;
			if (Variant6->Visible == true) Variant6->Visible =false;
		case 1:
			Variant3->Visible=true;
			Variant4->Visible=true;
			if (Variant5->Visible == true) Variant5->Visible =false;
			if (Variant6->Visible == true) Variant6->Visible =false;
			break;
		case 2:
			Variant3->Visible=true;
			Variant4->Visible=true;
			Variant5->Visible=true;
			Variant6->Visible=true;
			break;
	}
	AnsiString fileEasyQuestions="d:\\курсовой проект\\questions\\easyQuestions.txt";
	AnsiString fileMiddleQuestions="d:\\курсовой проект\\questions\\middleQuestions.txt";
	AnsiString fileHardQuestions="d:\\курсовой проект\\questions\\hardQuestions.txt";
	bool isEntered=isDataEntered();
	if (isEntered == true) {
		TFileStream* File;
		int i,j;
		if (!FileExists(fileEasyQuestions))   File=new TFileStream(fileEasyQuestions,fmCreate); delete File;
		if (!FileExists(fileMiddleQuestions)) File=new TFileStream(fileMiddleQuestions,fmCreate);  delete File;
		if (!FileExists(fileHardQuestions))   File=new TFileStream(fileHardQuestions,fmCreate);  delete File;
		switch (ChoosingTypeOfQuestion->ItemIndex) {
			case 0:
				EasyQuestion tempQuestion();
				tempQuestion.setAmountOfVariants(2);
				wchar_t type[50]="Легкий вопрос";
				tempQuestion.setType(type);
				wchar_t** textArray=new wchar_t*[8];
				for (i = 0; i < 8; i++) {
					textArray[i]=new wchar_t[75];
				}
				for (i = 0; i < 8; i++){
					strcpy(textArray[i],QuestionText->Lines->Strings[i].c_str());
				}
				tempQuestion.copyText(textArray);
				wchar_t variant1[50],variant2[50];
				strcpy(variant1,Variant1->Text.c_str());
				strcpy(variant2,Variant2->Text.c_str());
				tempQuestion.setVariant(variant1,1);
				tempQuestion.setVariant(variant2,2);
				tempQuestion.setDifficulty(StrToInt(Difficulty->Text));
				File=new TFileStream(fileEasyQuestion,fmOpenReadWrite);
				File->Seek(0,soFromEnd);
				File->Write(&tempQuestion,sizeof(class EasyQuestion));
				delete File;
		}
	}
}
//---------------------------------------------------------------------------
int counter=0;
void __fastcall TFAddingQuestion::QuestionTextKeyPress(TObject *Sender, System::WideChar &Key)
{
	counter++;
	if (counter == 75) {
		QuestionText->Lines->Add("\n");
		counter=0;
	}
}                                                                                     */
//---------------------------------------------------------------------------
