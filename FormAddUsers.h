//---------------------------------------------------------------------------

#ifndef FormAddUsersH
#define FormAddUsersH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFAddUser : public TForm
{
__published:	// IDE-managed Components
	TEdit *NameBox;
	TEdit *SurnameBox;
	TEdit *GroupBox;
	TButton *AddButton;
	TLabel *NameLabel;
	TLabel *SurnameLabel;
	TLabel *GroupLabel;
	TButton *ReturnButton;
	void __fastcall AddButtonClick(TObject *Sender);
	void __fastcall NameBoxChange(TObject *Sender);
	void __fastcall SurnameBoxChange(TObject *Sender);
	void __fastcall GroupBoxChange(TObject *Sender);
	void __fastcall ReturnButtonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFAddUser(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFAddUser *FAddUser;
//---------------------------------------------------------------------------
#endif
