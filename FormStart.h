//---------------------------------------------------------------------------

#ifndef FormStartH
#define FormStartH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Dialogs.hpp>
//---------------------------------------------------------------------------
class TFStart : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonStartRandomTest;
	TButton *ButtonSettings;
	TButton *ButtonStartCreatedTest;
	TOpenDialog *OpenDialog1;
	TComboBox *ComboBoxUsers;
	TLabel *Label1;
	TLabel *Label2;
	TButton *Button1;
	TEdit *NameBox;
	TButton *OKButton;
	void __fastcall ButtonStartRandomTestClick(TObject *Sender);
	void __fastcall ButtonSettingsClick(TObject *Sender);
	void __fastcall ButtonStartCreatedTestClick(TObject *Sender);
	void __fastcall FormActivate(TObject *Sender);
	void __fastcall ComboBoxUsersChange(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall OKButtonClick(TObject *Sender);
	void __fastcall NameBoxClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFStart(TComponent* Owner);
};
void open();
//---------------------------------------------------------------------------
extern PACKAGE TFStart *FStart;
//---------------------------------------------------------------------------
#endif
