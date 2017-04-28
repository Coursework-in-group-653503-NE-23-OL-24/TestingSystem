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
#include <Vcl.Imaging.pngimage.hpp>
#include <Vcl.Buttons.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.MPlayer.hpp>
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
	TProgressBar *ProgressBar1;
	TButton *ButtonCreateDocument;
	TButton *ButtonSaveTest;
	TSaveDialog *SaveDialog1;
	TEdit *EditAnswer;
	TLabel *LabelEnterAnswer;
	TLabel *LabelMark;
	TBitBtn *ButtonUp;
	TBitBtn *ButtonDown;
	TBitBtn *ButtonUpGeneral;
	TBitBtn *ButtonDownGeneral;
	TBitBtn *ButtonLeft;
	TBitBtn *ButtonRight;
	TBitBtn *ButtonLeftGeneral;
	TBitBtn *ButtonRightGeneral;
	TPopupMenu *PopupMenu1;
	TMenuItem *MenuArrow;
	TMenuItem *MenuDropDown;
	TStringGrid *StringGridResults;
	TBitBtn *ButtonPreviousQuestion;
	TBitBtn *ButtonNextQuestion;
	TLabel *LabelBottomLine;
	TImage *Image1;
	TMediaPlayer *MediaPlayer1;
	TTimer *TimerForMusic;
	TScrollBar *ScrollBar1;
	TPanel *PanelVideo;
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall ButtonAnswerClick(TObject *Sender);
	void __fastcall ButtonGoBackClick(TObject *Sender);
	void __fastcall ButtonCreateDocumentClick(TObject *Sender);
	void __fastcall ButtonSaveTestClick(TObject *Sender);
	void __fastcall ButtonDownGeneralClick(TObject *Sender);
	void __fastcall ButtonUpGeneralClick(TObject *Sender);
	void __fastcall ButtonUpClick(TObject *Sender);
	void __fastcall ButtonDownClick(TObject *Sender);
	void __fastcall ButtonLeftGeneralClick(TObject *Sender);
	void __fastcall ButtonRightGeneralClick(TObject *Sender);
	void __fastcall MemoQuestionTextClick(TObject *Sender);
	void __fastcall MenuArrowClick(TObject *Sender);
	void __fastcall MenuDropDownClick(TObject *Sender);
	void __fastcall StringGridResultsSelectCell(TObject *Sender, int ACol, int ARow,
		  bool &CanSelect);
	void __fastcall ButtonPreviousQuestionClick(TObject *Sender);
	void __fastcall ButtonNextQuestionClick(TObject *Sender);
	void __fastcall Image1Click(TObject *Sender);
	void __fastcall TimerForMusicTimer(TObject *Sender);
	void __fastcall MediaPlayer1Click(TObject *Sender, TMPBtnType Button, bool &DoDefault);
	void __fastcall ScrollBar1Scroll(TObject *Sender, TScrollCode ScrollCode, int &ScrollPos);
private:	// User declarations
public:		// User declarations
	__fastcall TFTest(TComponent* Owner);
};

void screenParametres();
int generateRandomNumber(int* arrayOfUsedElements, int arraySize, int range);
void zeroingArray(int* array,int size);
void setVariants(Question* TestQuestions,int i, int* usedVariants, int question, Variant Sheet);
void makingTest();
bool changeToNotAnsweredQuestion();
void changeQuestion(int index);
void deleteTest();
AnsiString dateNow();
void creatingDocument();
void addParagraph(int* paragraphCounter,Variant Paragraphs,AnsiString text);
void saveTest();
void addToCell(Variant Sheet,int row,int col,AnsiString value);
void upDown();
void leftRight();
void changing(int changingPosition);
void changingVisibilityOfComponents(bool value,TImage* image);
//---------------------------------------------------------------------------
extern PACKAGE TFTest *FTest;
//---------------------------------------------------------------------------
#endif
