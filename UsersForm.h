//---------------------------------------------------------------------------

#ifndef UsersFormH
#define UsersFormH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TUsersF : public TForm
{
__published:	// IDE-managed Components
	TLabel *WelkomeLabel;
	TButton *LastResultButton;
	TButton *AllTestsButton;
	TButton *AverageScoreButton;
	TButton *InformationButton;
	TButton *BackToTestButton;
	void __fastcall LastResultButtonClick(TObject *Sender);
	void __fastcall BackToTestButtonClick(TObject *Sender);
	void __fastcall AllTestsButtonClick(TObject *Sender);
	void __fastcall AverageScoreButtonClick(TObject *Sender);
	void __fastcall InformationButtonClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TUsersF(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TUsersF *UsersF;
//---------------------------------------------------------------------------
#endif
