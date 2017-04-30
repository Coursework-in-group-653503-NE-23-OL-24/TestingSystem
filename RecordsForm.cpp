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

TFormRecords *FormRecords;
extern AnsiString CURRENT_DIRECTORY;
extern	User user;
//---------------------------------------------------------------------------
__fastcall TFormRecords::TFormRecords(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRecords::BackButtonClick(TObject *Sender)
{
ExitMemo->Visible = false;
FormRecords->Close();
FStart->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TFormRecords::RatingButtonClick(TObject *Sender)
{
FormRecords->Visible = false;
FormRating->Show();
}
//---------------------------------------------------------------------------

void __fastcall TFormRecords::SumOfResultsButtonClick(TObject *Sender)
{
			ExitMemo->Visible = false;
			AnsiString temp;
			AnsiString sum;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			sum = IntToStr(0);

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//����� ������ C (���������� ���������� ������)
			 sum = StrToInt(sum) + StrToInt(temp);

			}

				ShowMessage (" ��������� ������, ���������� �������������� ����� " + sum  );
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");



}
//---------------------------------------------------------------------------

void __fastcall TFormRecords::AverageScoreButtonClick(TObject *Sender)
{
			ExitMemo->Visible = false;
			AnsiString temp;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			float sum = 0;
			float counter = 0;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,4);//����� ������ D (���������� ���������� ������)

			 sum = sum + StrToFloat(temp);
			 counter++;
			}
				sum = sum /  counter;

				ShowMessage (" ������������ ������������� �����  " + FloatToStr(sum) );
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");



}
//---------------------------------------------------------------------------


void __fastcall TFormRecords::BestResultButtonClick(TObject *Sender)
{
		   /*	ExitMemo->Visible = false;
			AnsiString temp;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Amounts.xlsx";
			int rowsCount;
			int maxAmount = 0;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);//����� ������ C (���������� ���������� ������)

			  if (maxAmount < StrToInt(temp)) {
				  maxAmount = StrToInt(temp);
			  }


			}

				ShowMessage("������������ ���� =  " + IntToStr(maxAmount));
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");
}            */


 	ExitMemo->Visible = false;
			AnsiString temp;
			AnsiString winnerName, winnerSurname;
			AnsiString sum;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			int maxAmount = 0;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,2);//����� ������ B (���������� ���������� ������)

			  if (maxAmount < StrToInt(temp)) {
				  maxAmount = StrToInt(temp);
				  winnerName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  winnerSurname = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }


			}

				ShowMessage("����������� ������ � " + IntToStr(maxAmount) + " ������ ���������(�) " + winnerName + " " + winnerSurname );
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");
}




//---------------------------------------------------------------------------

void __fastcall TFormRecords::WarseResultButtonClick(TObject *Sender)
{
	/*ExitMemo->Visible = false;
	AnsiString temp;
			AnsiString sum;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Amounts.xlsx";
			int rowsCount;
			int minAmount = 10;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);//����� ������ C (���������� ���������� ������)

			  if (minAmount > StrToInt(temp)) {
				  minAmount = StrToInt(temp);
			  }


			}

				ShowMessage("����������� ���� =  " + IntToStr(minAmount));
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");   */

                ExitMemo->Visible = false;
			AnsiString temp;
			AnsiString loserName, loserSurmame;
			AnsiString sum;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			int minAmount = 1000;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,2);//����� ������ B (���������� ���������� ������)

			  if (minAmount > StrToInt(temp)) {
				  minAmount = StrToInt(temp);
				  loserName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  loserSurmame = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }

			}
				ShowMessage("������ ��������� � "  + IntToStr(minAmount) + " �����(��) �������(�) " + loserName + " " + loserSurmame );
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");



}
//---------------------------------------------------------------------------

void __fastcall TFormRecords::MoreResultsButtonClick(TObject *Sender)
{
			ExitMemo->Visible = false;
			AnsiString temp;
			AnsiString winnerName, winnerSurname;
			AnsiString sum;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			int maxAmount = 0;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//����� ������ C (���������� ���������� ������)

			  if (maxAmount < StrToInt(temp)) {
				  maxAmount = StrToInt(temp);
				  winnerName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  winnerSurname = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }


			}

				ShowMessage("����� ������� ���������� " + winnerName + " " + winnerSurname + "\n"  + "��������� ������, ���������� ������������� -  " + IntToStr(maxAmount));
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TFormRecords::LessResultsButtonClick(TObject *Sender)
{
			ExitMemo->Visible = false;
			AnsiString temp;
			AnsiString loserName, loserSurmame;
			AnsiString sum;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			int minAmount = 1000;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//����� ������ C (���������� ���������� ������)

			  if (minAmount > StrToInt(temp)) {
				  minAmount = StrToInt(temp);
				  loserName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  loserSurmame = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }

			}
				ShowMessage("����� ������� ���������� " + loserName + " " + loserSurmame +  "\n"  + "��������� ������, ���������� ������������� -  " + IntToStr(minAmount));
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TFormRecords::FormClose(TObject *Sender, TCloseAction &Action)
{
FStart->Visible = true;
	ExitMemo->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFormRecords::AllGroupsButtonClick(TObject *Sender)
{
			AnsiString temp;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			//int min, max;
			float mas[1000];
			int masGroup[1000];
			int i;

			try{
				ExcelApplication=CreateOleObject("Excel.Application");
				ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
				Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
				rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");
			}
			catch(...){
				ShowMessage("������ ��� ��������� � �����\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,6);
			 masGroup[i] = StrToInt(temp);


			}
			  ExitMemo->Visible = true;
			  ExitMemo->Clear();


  {
		float kol=0;
		  for(int i = 0; i < rowsCount - 1; i++)
	{
	   for(int j = i + 1; j < rowsCount; j++)
	  {
		if (masGroup[i] <masGroup[j])
		{
			kol=masGroup[i];
			masGroup[i]=masGroup[j];
			masGroup[j]=kol;
		}

	  }



		 /*


			 int count=1;
			 int tempo=masGroup[0];  // ����� ������ ��������� ������� ����� ��������
			 for (i=1; i<rowsCount; i++)  // ������� ����� ������� ��� �������
			{
			   if(masGroup[i]!=tempo)     // ���� ������ �� ����� �������
							{
							  for (int j=i+1; j<rowsCount; j++)  // ������� �� ���������� �� ��������. ��������
							if(masGroup[i]==masGroup[j])     // ���� ������� �������
							 masGroup[j]=tempo;       // ��������� �������������
								count++;            // ����������� �������
							   }
			}



			 count=0;
			// ������ ������� ��� ������������� ��������
			 for (i=1; i<rowsCount; i++)
		  {
			if (masGroup[i]!=masGroup[0])     masGroup[++count]=masGroup[i];
		  }

         */





	  ExitMemo->Lines->Add(masGroup[i]);//ShowMessage(masGroup[i]);
	}
  }

			   //	ShowMessage("� ������������ ������� ������� ������: " + masGroup[i]);
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");


}
//---------------------------------------------------------------------------

