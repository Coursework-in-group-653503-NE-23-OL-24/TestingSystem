//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UsersForm.h"
#include "UnitQuestion.h"
#include "FormStart.h"
#include "FormCharacteristics.h"
#include "FormTest.h"
#include "RecordsForm.h"
#include "RatingForm.h"
#include "UnitTest.h"
#include "UnitUser.h"
#include <ComObj.hpp>
#include <utilcls.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TUsersF *UsersF;
//AnsiString CURRENT_DIRECTORY;
 extern AnsiString CURRENT_DIRECTORY;
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


}
//---------------------------------------------------------------------------

void __fastcall TUsersF::BackToTestButtonClick(TObject *Sender)
{
	UsersF->Close();
	FStart->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::AllTestsButtonClick(TObject *Sender)
{

	ShowMessage("���������� ���������� ������: " + IntToStr(user.getAllTestsResult()));


}
//---------------------------------------------------------------------------

void __fastcall TUsersF::AverageScoreButtonClick(TObject *Sender)
{
	 ShowMessage("������� ���� ������������: " + FloatToStr(user.getAverageScore()));

}
//---------------------------------------------------------------------------

void __fastcall TUsersF::InformationButtonClick(TObject *Sender)
{
		ShowMessage("���: " + user.getName() + "\n" + "�������: " + 	user.getSurname() + "\n" + "������: " + user.getGroup() + "\n" + "��������� ���������� ������������: " + IntToStr(user.getLastMark()) + "\n" + "���������� ���������� ������: " + IntToStr(user.getAllTestsResult()) + "\n" + "������� ���� ������������: " + FloatToStr(user.getAverageScore()));

}
//---------------------------------------------------------------------------

void __fastcall TUsersF::FormActivate(TObject *Sender)
{
	FStart->Visible = false;
	AnsiString temp;
	AnsiString WayToFile;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	wchar_t buffer[200];
	GetCurrentDirectory(sizeof(buffer),buffer);
	CURRENT_DIRECTORY=(AnsiString)buffer;
	//WayToFile="d:\\�������� ������\\������������.xlsx";
	int i;
	int position = FStart->ComboBoxUsers->ItemIndex+1;
	//const int COLS_AMOUNT = 6;
	//Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	int rowsCount;

	try{
		ExcelApplication=CreateOleObject("Excel.Application");
		ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(CURRENT_DIRECTORY+"\\Users.xlsx"));
		Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
		rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
	}
	catch(...){
		Application->Title="������";
		ShowMessage("������ ��� �������� �����\n"+CURRENT_DIRECTORY+"\\Users.xlsx"+"\n��������� ������� ����� \"Users.xlsx\" � ����������\n"+CURRENT_DIRECTORY);
		ExcelApplication.OleProcedure("Quit");
	}


	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,1);//����� ������ �((��� ������������)
	user.setName(temp);

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,2);//����� ������ � (��������� ������)
	user.setLastMark(StrToInt(temp));

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,3);//����� ������ C (���������� ���������� ������)
	user.setAllTestsResult(StrToInt(temp));

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,4);//����� ������ D (������� ����)
	user.setAverageScore(StrToFloat(temp));

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,5);//����� ������ E (������� ������������)
	user.setSurname(temp);

	temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",position,6);//����� ������ F (������ ������������)
	user.setGroup(temp);


	ExcelApplication.OleProcedure("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TUsersF::FormClose(TObject *Sender, TCloseAction &Action)
{
FStart->Visible = true;
}
//---------------------------------------------------------------------------

