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

	ShowMessage("��������� ���������� ������������: " + IntToStr(user.getLastMark()));

   /*
	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\�������� ������\\������������.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];

   /*	switch(i){
	  case 1:	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,2);//����� ������ �1
	  break;
	  case 2: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",2,2);//����� ������ �2
	  break;
	  case 3: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",3,2);//����� ������ �3
	  break;
	  case 4: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",4,2);//����� ������ �4
	  break;
	  case 5: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",5,2);//����� ������ �5
	  break;
	  case 6: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",6,2);//����� ������ �6
	  break;
	  case 7: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",7,2);//����� ������ �7
	  break;
	  case 8: 	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",8,2);//����� ������ �8
	  break;
	} //


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,2);//����� ������ �1
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

	ShowMessage("���������� ���������� ������: " + IntToStr(user.getAllTestsResult()));

   /*	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\�������� ������\\������������.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,3);//����� ������ C1

	}
	ShowMessage(temp);

	ExcelApplication.OleProcedure("Quit");
	delete []usersArray;  */
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::AverageScoreButtonClick(TObject *Sender)
{
	 ShowMessage("������� ���� ������������: " + IntToStr(user.getAverageScore()));
	/*AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\�������� ������\\������������.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,4);//����� ������ D1

	}
	ShowMessage(temp);

	ExcelApplication.OleProcedure("Quit");
	delete []usersArray; */
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::InformationButtonClick(TObject *Sender)
{
		ShowMessage("��������� ���������� ������������: " + IntToStr(user.getLastMark()) + "\n" + "���������� ���������� ������: " + IntToStr(user.getAllTestsResult()) + "\n" + "������� ���� ������������: " + IntToStr(user.getAverageScore()));
	/*
	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\�������� ������\\���������� � ������������ �� ������� ������.xlsx";
	int rowsCount,i;
	User *usersArray;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	usersArray=new User[rowsCount];


	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,5);//����� ������ E1 - ������� ���� - 6

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
	WayToFile="d:\\�������� ������\\������������.xlsx";
	int i;
	int position = FStart->ComboBoxUsers->ItemIndex+1;
	const int COLS_AMOUNT = 4;

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);


	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,1);//����� ������ �((��� ������������)
	user.setName(temp);

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,2);//����� ������ � (��������� ������)
	user.setLastMark(StrToInt(temp));

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,3);//����� ������ C (��������� ������)
	user.setAllTestsResult(StrToInt(temp));

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,4);//����� ������ d (��������� ������)
	user.setAverageScore(StrToInt(temp));




}
//---------------------------------------------------------------------------

