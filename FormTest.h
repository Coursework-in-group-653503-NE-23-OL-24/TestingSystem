//---------------------------------------------------------------------------

#ifndef FormTestH
#define FormTestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFTest : public TForm
{
__published:	// IDE-managed Components
	TRadioGroup *RadioGroupVariants;
	TMemo *MemoQuestionText;
	TButton *ButtonAnswer;
	TLabel *LabelEnd;
	TButton *ButtonGoBack;
	TLabel *LabelResult;
	TLabel *LabelWrongAnswers;
	TProgressBar *ProgressBar1;
	TStatusBar *StatusBar1;
	TButton *ButtonCreateDocument;
	TButton *ButtonSaveTest;
	TSaveDialog *SaveDialog1;
	TEdit *EditAnswer;
	TLabel *LabelEnterAnswer;
	TLabel *LabelMark;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonAnswerClick(TObject *Sender);
	void __fastcall ButtonGoBackClick(TObject *Sender);
	void __fastcall ButtonCreateDocumentClick(TObject *Sender);
	void __fastcall ButtonSaveTestClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFTest(TComponent* Owner);
};

int generateRandomNumber(int* arrayOfUsedElements, int arraySize, int range);
void zeroingArray(int* array,int size);
void makingTest();
void changeQuestion();
void deleteTest();
AnsiString dateNow();
void creatingDocument();
void addParagraph(int* paragraphCounter,Variant Paragraphs,AnsiString text);
void saveTest();
void addToCell(Variant Sheet,int row,int col,AnsiString value);
//---------------------------------------------------------------------------
extern PACKAGE TFTest *FTest;
//---------------------------------------------------------------------------
#endif
