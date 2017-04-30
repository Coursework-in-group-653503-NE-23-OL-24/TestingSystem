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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//Текст клетки C (Количество пройденных тестов)
			 sum = StrToInt(sum) + StrToInt(temp);

			}

				ShowMessage (" Количесто тестов, пройденных пользователями равно " + sum  );
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,4);//Текст клетки D (Количество пройденных тестов)

			 sum = sum + StrToFloat(temp);
			 counter++;
			}
				sum = sum /  counter;

				ShowMessage (" Успеваемость пользователей равна  " + FloatToStr(sum) );
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);//Текст клетки C (Количество пройденных тестов)

			  if (maxAmount < StrToInt(temp)) {
				  maxAmount = StrToInt(temp);
			  }


			}

				ShowMessage("Максимальный балл =  " + IntToStr(maxAmount));
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,2);//Текст клетки B (Количество пройденных тестов)

			  if (maxAmount < StrToInt(temp)) {
				  maxAmount = StrToInt(temp);
				  winnerName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  winnerSurname = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }


			}

				ShowMessage("Действующий рекорд в " + IntToStr(maxAmount) + " баллов установил(а) " + winnerName + " " + winnerSurname );
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);//Текст клетки C (Количество пройденных тестов)

			  if (minAmount > StrToInt(temp)) {
				  minAmount = StrToInt(temp);
			  }


			}

				ShowMessage("Минимальный балл =  " + IntToStr(minAmount));
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,2);//Текст клетки B (Количество пройденных тестов)

			  if (minAmount > StrToInt(temp)) {
				  minAmount = StrToInt(temp);
				  loserName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  loserSurmame = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }

			}
				ShowMessage("Худший рузультат в "  + IntToStr(minAmount) + " балла(ов) показал(а) " + loserName + " " + loserSurmame );
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//Текст клетки C (Количество пройденных тестов)

			  if (maxAmount < StrToInt(temp)) {
				  maxAmount = StrToInt(temp);
				  winnerName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  winnerSurname = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }


			}

				ShowMessage("Самым упорным признается " + winnerName + " " + winnerSurname + "\n"  + "Количесво тестов, пройденных пользователем -  " + IntToStr(maxAmount));
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
				ExcelApplication.OleProcedure("Quit");
				return;
			}

			for (int i = 0; i < rowsCount; i++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//Текст клетки C (Количество пройденных тестов)

			  if (minAmount > StrToInt(temp)) {
				  minAmount = StrToInt(temp);
				  loserName=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
				  loserSurmame = Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			  }

			}
				ShowMessage("Самым ленивым признается " + loserName + " " + loserSurmame +  "\n"  + "Количесво тестов, пройденных пользователем -  " + IntToStr(minAmount));
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
				ShowMessage("Ошибка при обращении к файлу\n"+WayToFile);
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
			 int tempo=masGroup[0];  // певый символ исходного массива будет маркером
			 for (i=1; i<rowsCount; i++)  // перебор всего массива без первого
			{
			   if(masGroup[i]!=tempo)     // если символ не равен маркеру
							{
							  for (int j=i+1; j<rowsCount; j++)  // перебор от следующего за рассмотр. символом
							if(masGroup[i]==masGroup[j])     // если символы совпали
							 masGroup[j]=tempo;       // маркируем повторяющиеся
								count++;            // увеличиваем счётчик
							   }
			}



			 count=0;
			// теперь удаляем все маркированные элементы
			 for (i=1; i<rowsCount; i++)
		  {
			if (masGroup[i]!=masGroup[0])     masGroup[++count]=masGroup[i];
		  }

         */





	  ExitMemo->Lines->Add(masGroup[i]);//ShowMessage(masGroup[i]);
	}
  }

			   //	ShowMessage("В тестировании приняли участие группы: " + masGroup[i]);
				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");


}
//---------------------------------------------------------------------------

