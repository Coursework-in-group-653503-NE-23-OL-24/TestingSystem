//---------------------------------------------------------------------------

#ifndef FormCharacteristicsOfQuestionH
#define FormCharacteristicsOfQuestionH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFAddingQuestion : public TForm
{
__published:	// IDE-managed Components
	TButton *AddingQuestion;
	TComboBox *ChoosingTypeOfQuestion;
	TEdit *Variant1;
	TEdit *Variant2;
	TEdit *Variant3;
	TEdit *Variant4;
	TEdit *Variant5;
	TEdit *Variant6;
	TEdit *Difficulty;
	TMemo *QuestionText;
	TLabel *LabelVariants;
	TLabel *LabelDifficulty;         /*
	void __fastcall QuestionTextClick(TObject *Sender);
	void __fastcall QuestionTextEnter(TObject *Sender);
	void __fastcall ChoosingTypeOfQuestionExit(TObject *Sender);
	void __fastcall DifficultyClick(TObject *Sender);
	void __fastcall DifficultyEnter(TObject *Sender);
	void __fastcall DifficultyExit(TObject *Sender);
	void __fastcall AddingQuestionClick(TObject *Sender);
	void __fastcall QuestionTextKeyPress(TObject *Sender, System::WideChar &Key);      */
private:	// User declarations
public:		// User declarations
	__fastcall TFAddingQuestion(TComponent* Owner);
};
bool isDataEntered();
//---------------------------------------------------------------------------
extern PACKAGE TFAddingQuestion *FAddingQuestion;
//---------------------------------------------------------------------------
#endif
