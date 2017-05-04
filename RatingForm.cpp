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
TFormRating *FormRating;
extern AnsiString  CURRENT_DIRECTORY;
//---------------------------------------------------------------------------
__fastcall TFormRating::TFormRating(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFormRating::BackButtonClick(TObject *Sender)
{
FormRating->Close();
FormRecords->Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall TFormRating::FormClose(TObject *Sender, TCloseAction &Action)
{
FormRecords->Visible = true;

}
//---------------------------------------------------------------------------

void __fastcall TFormRating::RatingLastTestButtonClick(TObject *Sender)
{
			AnsiString temp;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			int min, max;
			int mas[1000];
			AnsiString name[1000];
			AnsiString surname[1000];
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
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,2);//Текст клетки C (Количество пройденных тестов)
			 mas[i] = StrToInt(temp);
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
			 name[i] = temp;
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			 surname[i] = temp;
			}

		  ExitMemo->Clear();
		  ExitUsersMemo->Clear();

  {
		int kol=0;
		AnsiString kolname = "nothing";
		AnsiString kolsurname = "nothing";
		  for(int i = 0; i < rowsCount; i++)
	{
	   for(int j = i + 1; j < rowsCount; j++)
	  {
		if (mas[i] <mas[j])
		{
			kol=mas[i];
			kolname = name[i] ;
			kolsurname = surname[i] ;

			mas[i]=mas[j];
			name[i] = name[j];
			surname[i] = surname[j];

			mas[j]=kol;
			name[j] = kolname;
			surname[j] = kolsurname;
		}

	  }
	  ExitMemo->Lines->Add(mas[i]);
	  ExitUsersMemo->Lines->Add(name[i] + " " + surname[i]);
	}

  }


				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TFormRating::RatingAllTestsButtonClick(TObject *Sender)
{
AnsiString temp;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			int min, max;
			int mas[1000];
			AnsiString name[1000];
			AnsiString surname[1000];
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
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//Текст клетки C (Количество пройденных тестов)
			 mas[i] = StrToInt(temp);
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
			 name[i] = temp;
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			 surname[i] = temp;

			}

		  ExitMemo->Clear();
		  ExitUsersMemo->Clear();

  {
		int kol=0;
		AnsiString kolname = "nothing";
		AnsiString kolsurname = "nothing";
		  for(int i = 0; i < rowsCount; i++)
	{
	   for(int j = i + 1; j < rowsCount; j++)
	  {
		if (mas[i] <mas[j])
		{
			kol=mas[i];
			kolname = name[i] ;
			kolsurname = surname[i] ;

			mas[i]=mas[j];
			name[i] = name[j];
			surname[i] = surname[j];

			mas[j]=kol;
			name[j] = kolname;
			surname[j] = kolsurname;
		}

	  }
	  ExitMemo->Lines->Add(mas[i]);
	  ExitUsersMemo->Lines->Add(name[i] + " " + surname[i]);
	}
  }


				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");
}
//---------------------------------------------------------------------------

void __fastcall TFormRating::RatingQantityButtonClick(TObject *Sender)
{
AnsiString temp;
			AnsiString WayToFile;
			Variant ExcelApplication,ExcelBooks,Sheet,Cell;
			WayToFile=CURRENT_DIRECTORY+"\\Users.xlsx";
			int rowsCount;
			int min, max;
			float mas[1000];
			AnsiString name[1000];
			AnsiString surname[1000];
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
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,4);//Текст клетки C (Количество пройденных тестов)
			 mas[i] = StrToFloat(temp);
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);
			 name[i] = temp;
			 temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,5);
			 surname[i] = temp;

			}

		  ExitMemo->Clear();
		  ExitUsersMemo->Clear();

  {
		float kol=0;
		AnsiString kolname = "nothing";
		AnsiString kolsurname = "nothing";
		  for(int i = 0; i < rowsCount; i++)
	{
	   for(int j = i + 1; j < rowsCount; j++)
	  {
		if (mas[i] <mas[j])
		{
			kol=mas[i];
			kolname = name[i] ;
			kolsurname = surname[i] ;

			mas[i]=mas[j];
			name[i] = name[j];
			surname[i] = surname[j];

			mas[j]=kol;
			name[j] = kolname;
			surname[j] = kolsurname;
		}

	  }
	  ExitMemo->Lines->Add(float(int(mas[i]*1000+0.5))/1000);
	  ExitUsersMemo->Lines->Add(name[i] + " " + surname[i]);
	}
  }


				ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");
				ExcelApplication.OleProcedure("Quit");
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------

void __fastcall TFormRating::FormActivate(TObject *Sender)
{
	  ExitMemo->Clear();
	  ExitUsersMemo->Clear();
}
//---------------------------------------------------------------------------

