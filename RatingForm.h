//---------------------------------------------------------------------------

#ifndef RatingFormH
#define RatingFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFormRating : public TForm
{
__published:	// IDE-managed Components
	TButton *BackButton;
	TButton *RatingLastTestButton;
	TButton *RatingQantityButton;
	TButton *RatingAllTestsButton;
	TLabel *RatingLastTestLabel;
	TLabel *RatingAllTestsLabel;
	TLabel *RatingQantityLabel;
	TMemo *ExitMemo;
	TLabel *NoteLabel;
	TMemo *ExitUsersMemo;
	void __fastcall BackButtonClick(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall RatingLastTestButtonClick(TObject *Sender);
	void __fastcall RatingAllTestsButtonClick(TObject *Sender);
	void __fastcall RatingQantityButtonClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);


private:	// User declarations
public:		// User declarations
	__fastcall TFormRating(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRating *FormRating;
//---------------------------------------------------------------------------
#endif
