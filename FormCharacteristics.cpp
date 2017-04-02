//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitQuestion.h"
#include "FormStart.h"
#include "FormCharacteristics.h"
#include "FormTest.h"
#include "UnitTest.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFCharacteristics *FCharacteristics;
//---------------------------------------------------------------------------
__fastcall TFCharacteristics::TFCharacteristics(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFCharacteristics::EditQuestionsAmountClick(TObject *Sender)
{
	EditQuestionsAmount->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFCharacteristics::EditQuestionsAmountEnter(TObject *Sender)
{
	EditQuestionsAmount->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFCharacteristics::EditQuestionsAmountExit(TObject *Sender)
{
	if (EditQuestionsAmount->Text == "") {
		EditQuestionsAmount->Text="3";
	}
}
//---------------------------------------------------------------------------
void __fastcall TFCharacteristics::EditVariantsAmountClick(TObject *Sender)
{
	EditVariantsAmount->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFCharacteristics::EditVariantsAmountEnter(TObject *Sender)
{
	EditVariantsAmount->Text="";
}
//---------------------------------------------------------------------------
void __fastcall TFCharacteristics::EditVariantsAmountExit(TObject *Sender)
{
	if (EditVariantsAmount->Text == "") {
		EditVariantsAmount->Text="4";
	}
}
//---------------------------------------------------------------------------
bool isRightData(AnsiString data,int maxValue){
	int i,length=data.Length();
	bool isRight=true;
	for (i = 1; i <= length; i++) {
		if (data[i] > 57 || data[i]<48) {
			isRight=false;
			break;
		}
	}
	if (isRight == true) {
		int value=data.ToInt();
		if (value <= maxValue &&value > 0) {
			return true;
		}
		else return false;
	}
	else return false;
}

void __fastcall TFCharacteristics::ButtonGoBackClick(TObject *Sender)
{
	const int MAX_QUESTIONS_AMOUNT=10;
	const int MAX_VARIANTS_AMOUNT=8;

	if (isRightData(EditQuestionsAmount->Text,MAX_QUESTIONS_AMOUNT) == true) {
		if (isRightData(EditVariantsAmount->Text,MAX_VARIANTS_AMOUNT) == true) {
			FCharacteristics->Close();
			FStart->Show();
		}
		else {
			EditVariantsAmount->Text="";
			ShowMessage("Неверное значение");
        }
	}
	else {
		EditQuestionsAmount->Text="";
		ShowMessage("Неверное значение");
    }
}
//---------------------------------------------------------------------------


