//---------------------------------------------------------------------------

#ifndef FormCharacteristicsH
#define FormCharacteristicsH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
//---------------------------------------------------------------------------
class TFCharacteristics : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *EditQuestionsAmount;
	TLabel *Label2;
	TEdit *EditVariantsAmount;
	TButton *ButtonGoBack;
	void __fastcall EditQuestionsAmountClick(TObject *Sender);
	void __fastcall EditQuestionsAmountEnter(TObject *Sender);
	void __fastcall EditQuestionsAmountExit(TObject *Sender);
	void __fastcall EditVariantsAmountClick(TObject *Sender);
	void __fastcall EditVariantsAmountEnter(TObject *Sender);
	void __fastcall EditVariantsAmountExit(TObject *Sender);
	void __fastcall ButtonGoBackClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TFCharacteristics(TComponent* Owner);
};

bool isRightData(AnsiString data,int maxValue);

//---------------------------------------------------------------------------
extern PACKAGE TFCharacteristics *FCharacteristics;
//---------------------------------------------------------------------------
#endif
