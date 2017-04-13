//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UnitQuestion.h"
#include "FormStart.h"
#include "FormCharacteristics.h"
#include "FormTest.h"
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

bool isRandomTest;
AnsiString username;

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
	if (OpenDialog1->Execute()) {
		isRandomTest=false;
		open();
	}
}
//---------------------------------------------------------------------------

void __fastcall TFStart::FormActivate(TObject *Sender)
{
	ComboBoxUsers->Clear();

	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\курсовой проект\\Пользователи.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];     //дин. массив пользователей


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,1);//Текст клетки А1
		usersArray[i-1].setName(temp); //считывание имени пользователя с таблицы
	}
	for (i = 0; i < rowsCount; i++) {
		ComboBoxUsers->Items->Add(usersArray[i].getName());   /*Items - массив обьектов компонента combobox
														т.е. строк.
														add - добавление строки в конец массива
															 */
	}

	ComboBoxUsers->ItemIndex=0;//выбор первого пользователя по умолчанию

	/*1.Добавить приветственные надписи типа "Добро пожаловать"
	  2.Добавить к этой надриси обращение по имени пользователя ( "Добро пожаловать, Люба ")
	  3.Надпись  "если это не вы , то выберите соответст. пользователя
	  4.Открывается combobox (скрыть combobox с помощью visible=false)
	  5.в Formtest в 380 строке добавить имя пользователя в оформляемый документ
	  6.по окончании теста заносить статистику в таблицу
	  7.воскресение 17-00
	*/
	ExcelApplication.OleProcedure("Quit");
	delete []usersArray;
	//delete []usersSurnameArray;
	//delete []usersGroupArray;
}
//---------------------------------------------------------------------------

void __fastcall TFStart::ComboBoxUsersChange(TObject *Sender)
{
	WelkomeLabel->Caption = "Добро пожаловать, " + ComboBoxUsers->Text;
}
//---------------------------------------------------------------------------


void __fastcall TFStart::AddButtonClick(TObject *Sender)
{
	NameBox->Visible = true;
	OKButton->Visible = true;
}
//---------------------------------------------------------------------------

void addToCell(Variant Sheet,int row,int col,AnsiString value){
	Variant Cell;
	Cell=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",row,col);
	Cell.OlePropertySet("Value",StringToOleStr(value));
}

void __fastcall TFStart::OKButtonClick(TObject *Sender)
{
	AnsiString WayToFile="d:\\курсовой проект\\Пользователи.xlsx";
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	int rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	AnsiString Name=NameBox->Text;
	ComboBoxUsers->Items->Add(Name);

	addToCell(Sheet,rowsCount+1,1,Name);

	NameBox->Visible = false;
	OKButton->Visible = false;
	ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");

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

