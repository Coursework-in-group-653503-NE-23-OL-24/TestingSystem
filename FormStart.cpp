//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitQuestion.h"
#include "FormStart.h"
#include "FormCharacteristics.h"
#include "FormTest.h"
#include "FormAddUsers.h"
#include "RecordsForm.h"
#include "RatingForm.h"
#include "UnitTest.h"
#include "UnitUser.h"
#include <ComObj.hpp>
#include <utilcls.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFStart *FStart;

//---------------------------------------------------------------------------
__fastcall TFStart::TFStart(TComponent* Owner)
	: TForm(Owner)
{
}

int resolutionX,resolutionY;

bool isRandomTest;
AnsiString username;
AnsiString usersurname;
AnsiString usergroup;

AnsiString CURRENT_DIRECTORY;

void open(){
	FStart->Hide();
	FTest->Show();
	FTest->Visible=true;
	FTest->OnActivate;
}

void __fastcall TFStart::ButtonStartRandomTestClick(TObject *Sender)
{
	username = ComboBoxUsers->Text;


	isRandomTest=true;
	open();
}
//---------------------------------------------------------------------------

void __fastcall TFStart::ButtonSettingsClick(TObject *Sender)
{
	FCharacteristics->Show();
	FStart->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TFStart::ButtonStartCreatedTestClick(TObject *Sender)
{
	FStart->OpenDialog1->InitialDir=CURRENT_DIRECTORY+"\\тестирования";
	if (OpenDialog1->Execute()) {
		isRandomTest=false;
		open();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFStart::FormActivate(TObject *Sender)
{
	ComboBoxUsers->Clear();
	resolutionX=GetSystemMetrics(SM_CXSCREEN);
	resolutionY=GetSystemMetrics(SM_CYSCREEN);

	AnsiString temp;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	wchar_t buffer[200];
	GetCurrentDirectory(sizeof(buffer),buffer);
	CURRENT_DIRECTORY=(AnsiString)buffer;
	int rowsCount,i;
	User *usersArray;

	try{
		ExcelApplication=CreateOleObject("Excel.Application");
		ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(CURRENT_DIRECTORY+"\\Users.xlsx"));
		Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
		rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
	}
	catch(...){
		Application->Title="Ошибка";
		ShowMessage("Ошибка при открытии файла\n"+CURRENT_DIRECTORY+"\\Пользователи.xlsx"+"\nПроверьте наличие файла \"Users.xlsx\" в директории\n"+CURRENT_DIRECTORY);
		ExcelApplication.OleProcedure("Quit");
		FStart->Close();
	}

	usersArray=new User[rowsCount];     //дин. массив пользователей

	try{
		for (int i=1; i <= rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,1);//Текст клетки А1
			usersArray[i-1].setName(temp); //считывание имени пользователя с таблицы
		   /*	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,5);
			usersArray[i-1].setSurname(temp); //считывание фамилии пользователя с таблицы
			usersurname = temp;
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,6);
			usersArray[i-1].setGroup(temp); //считывание группы пользователя с таблицы
			usergroup = temp; */
		}
		for (i = 0; i < rowsCount; i++) {
			ComboBoxUsers->Items->Add(usersArray[i].getName()/*+ " " + usersArray[i].getSurname() + " " + usersArray[i].getGroup()*/);
			//ComboBoxUsers->Items->Add(usersArray[i].getSurname());
			//ComboBoxUsers->Items->Add(usersArray[i].getGroup());

		}
	}
	catch(...){
		Application->Title="Ошибка";
		ShowMessage("Ошибка при считывании данных из файла\n"+CURRENT_DIRECTORY+"\\Users.xlsx");
		ExcelApplication.OleProcedure("Quit");
	}

	ComboBoxUsers->ItemIndex=0;//выбор первого пользователя по умолчанию
	//ComboBoxUsers->Text=Utf8ToAnsi("а б в");

	ExcelApplication.OleProcedure("Quit");
	delete []usersArray;
}
//---------------------------------------------------------------------------

void __fastcall TFStart::ComboBoxUsersChange(TObject *Sender)
{
	WelkomeLabel->Caption = "Добро пожаловать, " + ComboBoxUsers->Text ;
}
//---------------------------------------------------------------------------


void __fastcall TFStart::AddButtonClick(TObject *Sender)
{
	FStart->Visible = false;
	FAddUser->Show();
	//NameBox->Visible = true;
	//OKButton->Visible = true;
}
//---------------------------------------------------------------------------

void addToCell(Variant Sheet,int row,int col,AnsiString value){
	Variant Cell;
	Cell=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",row,col);
	Cell.OlePropertySet("Value",StringToOleStr(value));
}

void __fastcall TFStart::OKButtonClick(TObject *Sender)
{
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
		ComboBoxUsers->Items->Add(Name);

		addToCell(Sheet,rowsCount+1,1,Name);

		NameBox->Visible = false;
		OKButton->Visible = false;
		ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
	}
	catch(...){
		Application->Title="Ошибка";
		ShowMessage("Ошибка при записи данных в файл\n"+CURRENT_DIRECTORY+"\\Users.xlsx");
	}

	ExcelApplication.OleProcedure("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TFStart::NameBoxClick(TObject *Sender)
{
	NameBox->Clear();
}
//---------------------------------------------------------------------------


void __fastcall TFStart::ButtonOfUsersClick(TObject *Sender)
{
	User user;

	UsersF->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFStart::TableOfRecordsButtonClick(TObject *Sender)
{
	FStart->Visible = false;
	FormRecords->Show();
}
//---------------------------------------------------------------------------

