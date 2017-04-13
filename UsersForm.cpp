//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UsersForm.h"
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
TUsersF *UsersF;
//---------------------------------------------------------------------------
__fastcall TUsersF::TUsersF(TComponent* Owner)
	: TForm(Owner)
{
}
	User user;
//---------------------------------------------------------------------------
void __fastcall TUsersF::LastResultButtonClick(TObject *Sender)
{

	ShowMessage("Результат последнего тестирования: " + IntToStr(user.getLastMark()));

   /*
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

	usersArray=new User[rowsCount];

   /*	switch(i){
	  case 1:	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,2);//Текст клетки В1
	  break;
	  case 2: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",2,2);//Текст клетки В2
	  break;
	  case 3: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",3,2);//Текст клетки В3
	  break;
	  case 4: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",4,2);//Текст клетки В4
	  break;
	  case 5: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,2);//Текст клетки В5
	  break;
	  case 6: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,2);//Текст клетки В6
	  break;
	  case 7: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",7,2);//Текст клетки В7
	  break;
	  case 8: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,2);//Текст клетки В8
	  break;
	} //


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,2);//Текст клетки В1
	}
	ShowMessage(temp);

	ExcelApplication.OleProcedure("Quit");
	delete []usersArray; */
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::BackToTestButtonClick(TObject *Sender)
{
	UsersF->Close();
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::AllTestsButtonClick(TObject *Sender)
{

	ShowMessage("Количество пройденных тестов: " + IntToStr(user.getAllTestsResult()));

   /*	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\курсовой проект\\Пользователи.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,3);//Текст клетки C1

	}
	ShowMessage(temp);

	ExcelApplication.OleProcedure("Quit");
	delete []usersArray;  */
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::AverageScoreButtonClick(TObject *Sender)
{
	 ShowMessage("Средний балл пользователя: " + IntToStr(user.getAverageScore()));
	/*AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\курсовой проект\\Пользователи.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,4);//Текст клетки D1

	}
	ShowMessage(temp);

	ExcelApplication.OleProcedure("Quit");
	delete []usersArray; */
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::InformationButtonClick(TObject *Sender)
{
		ShowMessage("Результат последнего тестирования: " + IntToStr(user.getLastMark()) + "\n" + "Количество пройденных тестов: " + IntToStr(user.getAllTestsResult()) + "\n" + "Средний балл пользователя: " + IntToStr(user.getAverageScore()));
	/*
	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\курсовой проект\\Информация в соответствии со средним баллом.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,5);//Текст клетки E1 - средний балл - 6

	}
	ShowMessage(temp);

	ExcelApplication.OleProcedure("Quit");
	delete []usersArray; */
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::FormActivate(TObject *Sender)
{

	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\курсовой проект\\Пользователи.xlsx";
	int i;
	int position = FStart->ComboBoxUsers->ItemIndex+1;
	const int COLS_AMOUNT = 4;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);


	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,1);//Текст клетки А((Имя пользователя)
	user.setName(temp);

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,2);//Текст клетки В (Последняя оценка)
	user.setLastMark(StrToInt(temp));

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,3);//Текст клетки C (Последняя оценка)
	user.setAllTestsResult(StrToInt(temp));

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,4);//Текст клетки d (Последняя оценка)
	user.setAverageScore(StrToInt(temp));




}
//---------------------------------------------------------------------------

