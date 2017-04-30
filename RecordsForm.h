//---------------------------------------------------------------------------

#ifndef RecordsFormH
#define RecordsFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormRecords : public TForm
{
__published:	// IDE-managed Components
	TButton *BackButton;
	TButton *BestResultButton;
	TButton *WarseResultButton;
	TButton *MoreResultsButton;
	TLabel *MoreResultsLabel;
	TButton *LessResultsButton;
	TLabel *LessResultsLabel;
	TButton *SumOfResultsButton;
	TButton *AverageScoreButton;
	TButton *RatingButton;
	TLabel *TheMostLabel;
	TButton *AllGroupsButton;
	TMemo *ExitMemo;
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall RatingButtonClick(TObject *Sender);
	void __fastcall SumOfResultsButtonClick(TObject *Sender);
	void __fastcall AverageScoreButtonClick(TObject *Sender);
	void __fastcall BestResultButtonClick(TObject *Sender);
	void __fastcall WarseResultButtonClick(TObject *Sender);
	void __fastcall MoreResultsButtonClick(TObject *Sender);
	void __fastcall LessResultsButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall AllGroupsButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFormRecords(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRecords *FormRecords;
//---------------------------------------------------------------------------
#endif
