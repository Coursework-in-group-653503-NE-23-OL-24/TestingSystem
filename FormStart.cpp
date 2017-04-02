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

	usersArray=new User[rowsCount];     //���. ������ �������������

	for (int i=1; i <= rowsCount; i++) {
		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i,1);//����� ������ �1
		usersArray[i-1].setName(temp); //���������� ����� ������������ � �������
	}
	for (i = 0; i < rowsCount; i++) {
		ComboBoxUsers->Items->Add(usersArray[i].getName());   /*Items - ������ �������� ���������� combobox
														�.�. �����.
														add - ���������� ������ � ����� �������
															 */
	}
	//ComboBoxUsers->ItemIndex=0;//����� ������� ������������ �� ���������
	/*1.�������� �������������� ������� ���� "����� ����������"
	  2.�������� � ���� ������� ��������� �� ����� ������������ ( "����� ����������, ���� ")
	  3.�������  "���� ��� �� �� , �� �������� ���������. ������������
	  4.����������� combobox (������ combobox � ������� visible=false)
	  5.� Formtest � 380 ������ �������� ��� ������������ � ����������� ��������
	  6.�� ��������� ����� �������� ���������� � �������
	  7.����������� 17-00
	*/
	delete []usersArray;
}
//---------------------------------------------------------------------------

void __fastcall TFStart::ComboBoxUsersChange(TObject *Sender)
{
	Label1->Caption = "����� ����������, " + ComboBoxUsers->Text;
}
//---------------------------------------------------------------------------


void __fastcall TFStart::Button1Click(TObject *Sender)
{
	NameBox->Visible = true;
	OKButton->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TFStart::OKButtonClick(TObject *Sender)
{
	ComboBoxUsers->Items->Add(NameBox->Text);
	NameBox->Visible = false;
	OKButton->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFStart::NameBoxClick(TObject *Sender)
{
	NameBox->Clear();
}
//---------------------------------------------------------------------------

