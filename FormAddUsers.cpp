//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UsersForm.h"
#include "UnitQuestion.h"
#include "FormStart.h"
#include "FormCharacteristics.h"
#include "FormTest.h"
#include "FormAddUsers.h"
#include "UnitTest.h"
#include "UnitUser.h"
#include <ComObj.hpp>
#include <utilcls.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFAddUser *FAddUser;

extern AnsiString username;
//AnsiString CURRENT_DIRECTORY;
//username = ComboBoxUsers->Text;


//---------------------------------------------------------------------------
__fastcall TFAddUser::TFAddUser(TComponent* Owner)
	: TForm(Owner)
{
}
 extern AnsiString CURRENT_DIRECTORY;



void addToCell(Variant Sheet,int row,int col,AnsiString value){
	Variant Cell;
	Cell=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",row,col);
	Cell.OlePropertySet("Value",StringToOleStr(value));
}


//---------------------------------------------------------------------------
void __fastcall TFAddUser::AddButtonClick(TObject *Sender)
{

	/*wchar_t buffer[200];
	GetCurrentDirectory(sizeof(buffer),buffer);
	CURRENT_DIRECTORY=(AnsiString)buffer;*/
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	int rowsCount;

	try{
		ExcelApplication=CreateOleObject("Excel.Application");
		ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(CURRENT_DIRECTORY+"\\Users.xlsx"));
		Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
		rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
	}
	catch(...){
		Application->Title="Ошибка";
		ShowMessage("Ошибка при открытии файла\n"+CURRENT_DIRECTORY+"\\Users.xlsx"+"\nПроверьте наличие файла \"Users.xlsx\" в директории\n"+CURRENT_DIRECTORY);
		ExcelApplication.OleProcedure("Quit");
	}

	try{

		AnsiString Name=NameBox->Text;
		AnsiString Surname=SurnameBox->Text;
		AnsiString Group=GroupBox->Text;
		FStart->ComboBoxUsers->Items->Add(Name);
		FStart->ComboBoxUsers->Items->Add(Surname);
		FStart->ComboBoxUsers->Items->Add(Group);

		addToCell(Sheet,rowsCount+1,1,Name);
		addToCell(Sheet,rowsCount+1,5,Surname);
		addToCell(Sheet,rowsCount+1,6,Group);
		addToCell(Sheet,rowsCount+1,2,0);
		addToCell(Sheet,rowsCount+1,3,0);
		addToCell(Sheet,rowsCount+1,4,0);

		//NameBox->Visible = false;
		//OKButton->Visible = false;
		ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
	}
	catch(...){
		Application->Title="Ошибка";
		ShowMessage("Ошибка при записи данных в файл\n"+CURRENT_DIRECTORY+"\\Users.xlsx");
	}

	ExcelApplication.OleProcedure("Quit");



	/*AnsiString WayToFile="d:\\курсовой проект\\Пользователи.xlsx";
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	int rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	AnsiString Name=NameBox->Text;
	AnsiString Surname=SurnameBox->Text;
	AnsiString Group=GroupBox->Text;
	FStart->ComboBoxUsers->Items->Add(Name);
	FStart->ComboBoxUsers->Items->Add(Surname);
	FStart->ComboBoxUsers->Items->Add(Group);

	addToCell(Sheet,rowsCount+1,1,Name);
	addToCell(Sheet,rowsCount+1,5,Surname);
	addToCell(Sheet,rowsCount+1,6,Group);


	ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");

	ExcelApplication.OleProcedure("Quit");*/
	ShowMessage("Пользователь добавлен. Если хотите, можете добавить еще одного пользователя");
	NameBox->Clear();
	SurnameBox->Clear();
	GroupBox->Clear();
}

//---------------------------------------------------------------------------
void __fastcall TFAddUser::NameBoxChange(TObject *Sender)
{
//NameBox->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFAddUser::SurnameBoxChange(TObject *Sender)
{
//SurnameBox->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFAddUser::GroupBoxChange(TObject *Sender)
{
//GroupBox->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TFAddUser::ReturnButtonClick(TObject *Sender)
{
	FAddUser->Close();
	FStart->Visible = true;

}
//---------------------------------------------------------------------------
void __fastcall TFAddUser::FormClose(TObject *Sender, TCloseAction &Action)
{
FStart->Visible = true;
}
//---------------------------------------------------------------------------

