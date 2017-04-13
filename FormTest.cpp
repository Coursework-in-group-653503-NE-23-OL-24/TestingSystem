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
#include <JPEG.hpp>
#include <stdlib.h>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFTest *FTest;
//---------------------------------------------------------------------------
__fastcall TFTest::TFTest(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

Question* TestQuestions;
const int FALSE_VARIANTS_AMOUNT=9;
const int LINE_LENGTH=50;
const int IMAGES_AMOUNT=4;
int globalCounter=-1;
Test testStatistics;
TImage* images[IMAGES_AMOUNT];
int variantsAmount;
int questionsAmount;
extern bool isRandomTest;
extern AnsiString username;

int generateRandomNumber(int* arrayOfUsedElements, int arraySize, int range){
	int i,number;
	do {
		number=random(range+1);
		for (i = 0; i < arraySize; i++) {
			if (number == arrayOfUsedElements[i]) {
				number=0;
				break;
			}
		}
	} while (number == 0);
	return number;
}

void zeroingArray(int* array,int size){
	int i;
	for (i = 0; i < size; i++) {
		array[i]=0;
	}
}

void makingTest(){
	int rowsCount,i,j;
	AnsiString temp;
	int* usedQuestions;
	int* usedVariants;
	AnsiString WayToFile,WayToPicture;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;

	if (isRandomTest==true){
		questionsAmount=FCharacteristics->EditQuestionsAmount->Text.ToInt();
		variantsAmount=FCharacteristics->EditVariantsAmount->Text.ToInt()-1;
		WayToFile="d:\\курсовой проект\\Вопросы.xlsx";
		WayToPicture="d:\\курсовой проект\\изображения\\";
	}
	else {
		WayToFile=FStart->OpenDialog1->FileName;
	}

	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");

	if (isRandomTest==false) {
		questionsAmount=StrToInt(Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,18));
		variantsAmount= StrToInt(Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",1,19))-1;
	}

    TestQuestions=new Question[questionsAmount];
	usedQuestions=new int[questionsAmount];
	usedVariants=new int[variantsAmount];
	for (i = 0; i < IMAGES_AMOUNT; i++) {
		images[i]=new TImage(FTest);
	}

	for (i = 0; i < IMAGES_AMOUNT; i++) {
		images[i]->Visible=false;
	}

	zeroingArray(usedQuestions,questionsAmount);
	zeroingArray(usedVariants,variantsAmount);

	for (i = 0; i < questionsAmount; i++) {

		int j,question;
		if (isRandomTest==true) {
			question=generateRandomNumber(usedQuestions, questionsAmount, rowsCount);
		}
		else question=i+1;
		usedQuestions[i]=question;

		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",question,20);//Текст клетки T"question" с типом вопроса
		TestQuestions[i].setQuestionType(temp);

		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",question,1);//Текст клетки А"question" с текстом вопроса
		TestQuestions[i].setText(temp);

		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",question,2);//Текст клетки B"question"  с правильным ответом
		TestQuestions[i].setRightVariant(temp);

		temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",question,13);//Текст клетки M"question" со сложностью вопроса
		TestQuestions[i].setDifficulty(temp.ToInt());
		testStatistics.addMaxPoints(temp.ToInt());

		for (j=0; j<IMAGES_AMOUNT; j++) {
			temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",question,j+14);//Текст клеток N O P R "question"  с именем изображений
			if (temp!="-") {
				if (isRandomTest==true) TestQuestions[i].setPicture(WayToPicture+temp,j);
				else  TestQuestions[i].setPicture(temp,j);
			}
			else TestQuestions[i].setPicture(temp,j);                //choose-выбор вариантов ответа
		}                                                            //write-вписать ответ
		if (TestQuestions[i].getQuestionType()=="choose") {
			for (j = 0; j < variantsAmount; j++){
				int variant;
				if (isRandomTest==true) {
					variant=generateRandomNumber(usedVariants, variantsAmount, FALSE_VARIANTS_AMOUNT);
				}
				else variant=j+1;
				usedVariants[j]=variant;
				variant+=2;   //смещение вправо, т.к. в А и В не то, что нужно
				temp=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",question,variant);//Текст клетки с вариантом ответа
				TestQuestions[i].setVariant(temp,j);
			}
		}
	}
	ExcelApplication.OleProcedure("Quit");
	delete []usedVariants;
	delete []usedQuestions;
}

void __fastcall TFTest::FormActivate(TObject *Sender)
{
	LabelEnd->Visible=false;;
	LabelResult->Visible=false;
	LabelWrongAnswers->Visible=false;
	ButtonGoBack->Visible=false;
	MemoQuestionText->Visible=false;
	RadioGroupVariants->Visible=false;
	ButtonAnswer->Visible=false;
	ButtonCreateDocument->Visible=false;
	ButtonSaveTest->Visible=false;
	LabelMark->Visible=false;
	LabelEnterAnswer->Visible=false;

	makingTest();

	ProgressBar1->Max=(MemoQuestionText->Width/questionsAmount)*questionsAmount;
	ProgressBar1->Step=ProgressBar1->Max/questionsAmount;
	ButtonAnswer->Visible=true;

	changeQuestion();
}
//---------------------------------------------------------------------------
void __fastcall TFTest::FormClose(TObject *Sender, TCloseAction &Action)
{
	deleteTest();
	FStart->Close();
}
//---------------------------------------------------------------------------
void __fastcall TFTest::FormCreate(TObject *Sender)
{
	randomize();
}
//---------------------------------------------------------------------------
void __fastcall TFTest::ButtonAnswerClick(TObject *Sender)
{
	bool wasAnswered=false;
	AnsiString answer;

	if (TestQuestions[globalCounter].getQuestionType()=="choose" && RadioGroupVariants->ItemIndex != -1) {
		FTest->MemoQuestionText->Visible=false;
		FTest->RadioGroupVariants->Visible=false;
		int choosedVariant=RadioGroupVariants->ItemIndex;
		answer=RadioGroupVariants->Items->Strings[choosedVariant];
		wasAnswered=true;
	}
	else if (TestQuestions[globalCounter].getQuestionType()=="write" && EditAnswer->Text!="") {
		EditAnswer->Visible=false;
		answer=EditAnswer->Text;
		answer.Trim();
		answer.LowerCase();
		wasAnswered=true;
	}
	else ShowMessage("Необходимо ответить, прежде чем переходить к следующему вопросу.");

	if (wasAnswered==true) {
		int result;
		TestQuestions[globalCounter].setUserAnswer(answer);
		if (answer == TestQuestions[globalCounter].getRightVariant()) {
			testStatistics.addCollectedPoints(TestQuestions[globalCounter].getDifficulty());
		}
		else testStatistics.addWrongAnswers(IntToStr(globalCounter+1));

		if (globalCounter < questionsAmount-1) changeQuestion();
		else {
			MemoQuestionText->Visible=false;
			RadioGroupVariants->Visible=false;
			ButtonAnswer->Visible=false;
			EditAnswer->Visible=false;
			LabelEnterAnswer->Visible=false;
			//LabelWrongAnswers->Visible=false;
			for (int i = 0; i < IMAGES_AMOUNT; i++) {
				images[i]->Visible=false;
			}

			LabelEnd->Left=200;
			LabelEnd->Top=200;
			LabelResult->Left=LabelEnd->Left;
			LabelResult->Top=LabelEnd->Top+LabelEnd->Height+30;
			LabelWrongAnswers->Left=LabelEnd->Left;
			LabelWrongAnswers->Top=LabelResult->Top+LabelResult->Height+30;
			LabelMark->Left=LabelEnd->Left;
			LabelMark->Top=LabelWrongAnswers->Top+LabelWrongAnswers->Height+30;
			ButtonGoBack->Left=LabelEnd->Left;
			ButtonGoBack->Top=LabelMark->Top+LabelMark->Height+30;
			ButtonCreateDocument->Left=ButtonGoBack->Left+ButtonGoBack->Width+30;
			ButtonCreateDocument->Top=ButtonGoBack->Top;
			ButtonSaveTest->Top=ButtonGoBack->Top;
			ButtonSaveTest->Left=ButtonCreateDocument->Left+ButtonCreateDocument->Width+30;

			result=testStatistics.getCollectedPoints();
			int residue;
			AnsiString temp;
			if (result<11 || result>14) {    //11-14 очков, а не 1 очко, 2-4 очка
				residue=result%10;
			}
			else residue=5; // 5 очков
			switch (residue) {
				case 1: temp=" очко "; break;
				case 2:
				case 3:
				case 4: temp=" очка "; break;
				default: temp=" очков "; break;
			}



	AnsiString WayToFile;
	AnsiString username,cellb, cellc,celld;
	Variant ExcelApplication,ExcelBooks,Sheet,Cell;
	WayToFile="d:\\курсовой проект\\Пользователи.xlsx";
	int i,all;
	int position = FStart->ComboBoxUsers->ItemIndex+1;
	const int COLS_AMOUNT = 4;



	ExcelApplication=CreateOleObject("Excel.Application");
	ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Open",StringToOleStr(WayToFile));
	Sheet=ExcelBooks.OlePropertyGet("Worksheets",1);
	int rowsCount=Sheet.OlePropertyGet("UsedRange").OlePropertyGet("Rows").OlePropertyGet("Count");



	for (i = 0; i < rowsCount; i++) {
		cellb=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,1);//Текст клетки B
		cellc=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,3);//Текст клетки C
		celld=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",i+1,4);//Текст клетки D

		celld = IntToStr(StrToInt(celld)*StrToInt(cellc));

		cellc = IntToStr(StrToInt(cellc)+1);

		celld = IntToStr(StrToInt(celld)+testStatistics.testResult());

		celld=FloatToStr((float)StrToInt(celld)/StrToInt(cellc));

		if (FStart->ComboBoxUsers->Text==cellb) {
			addToCell(Sheet,i+1,2,IntToStr(testStatistics.testResult()));

			addToCell(Sheet,i+1,3,cellc);

			addToCell(Sheet,i+1,4,celld);

		}
	}


	ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("Save");

	ExcelApplication.OleProcedure("Quit");

	FStart->ComboBoxUsers->ItemIndex=0;//выбор первого пользователя по умолчанию



			// Открыть эксель пользователи
			// Записать testStatistics.testResult()    в поле В


			// Считать количество пройденных тестов
			// увеличить его на 1
			// записать новое значение в соответствующую ячейку


			// считать средний балл
			// умножить на количество пройденных тестов(до увелич. на 1)
			// прибавить оценку за текущий тест //получаем сумму баллов
			// получить новый средний балл: разделить сумму на увеличенное количество пройденных тестов
			// записать в ячейку новый средний балл

			AnsiString text="Вы набрали "+IntToStr(result)+temp+"из "+IntToStr(testStatistics.getMaxPoints());
			LabelResult->Caption=text;

			LabelWrongAnswers->Caption="Неправильно отвечены вопросы: "+testStatistics.getWrongAnswers();
			LabelMark->Caption="Оценка: "+IntToStr(testStatistics.testResult());









			LabelEnd->Visible=true;
			LabelResult->Visible=true;
			ButtonGoBack->Visible=true;
			ButtonCreateDocument->Visible=true;
			ButtonSaveTest->Visible=true;
			LabelWrongAnswers->Visible=true;
			LabelMark->Visible=true;
			globalCounter=-1;
		}
	}
}
//---------------------------------------------------------------------------
void changeQuestion(){
	int i, imagesAmount=0;
	const int IMAGE_WIDTH=350,IMAGE_HEIGHT=250, INDENTION=10;
	globalCounter++;

	FTest->MemoQuestionText->Lines->Clear();
	FTest->RadioGroupVariants->Items->Clear();
	FTest->EditAnswer->Clear();
	FTest->MemoQuestionText->Visible=false;
	FTest->RadioGroupVariants->Visible=false;
	FTest->EditAnswer->Visible=false;
	FTest->LabelEnterAnswer->Visible=false;
	for (i = 0; i < IMAGES_AMOUNT; i++) {
		images[i]->Visible=false;
	}

	FTest->MemoQuestionText->Lines->Add(TestQuestions[globalCounter].getText());
	for (i = 0; i < variantsAmount; i++) {
		FTest->RadioGroupVariants->Items->Add(TestQuestions[globalCounter].getVariant(i));
	}
	FTest->RadioGroupVariants->Items->Insert(random(variantsAmount),TestQuestions[globalCounter].getRightVariant());

	FTest->MemoQuestionText->Height=(FTest->MemoQuestionText->Lines->Count+1)*50;

	if (TestQuestions[globalCounter].getPicture(0)!="-"){
		for (i = 0; i < IMAGES_AMOUNT; i++) {
			if (TestQuestions[globalCounter].getPicture(i)!="-") {
				images[i]->Top=FTest->MemoQuestionText->Height+FTest->MemoQuestionText->Top+3*INDENTION;
				images[i]->Height=IMAGE_HEIGHT;
				images[i]->Width=IMAGE_WIDTH;
				images[i]->Picture->LoadFromFile(TestQuestions[globalCounter].getPicture(i));
				images[i]->Visible=true;
				images[i]->Parent=FTest;
				imagesAmount++;
			}
		}
		FTest->RadioGroupVariants->Top=images[0]->Top+IMAGE_HEIGHT+3*INDENTION;
	}
	else {
		FTest->RadioGroupVariants->Top=FTest->MemoQuestionText->Top+FTest->MemoQuestionText->Height+3*INDENTION;
	}
	if (variantsAmount%2==0) { //в начале variantsAmount-1!
		FTest->RadioGroupVariants->Height=INDENTION*5*(((variantsAmount+2)/2)+1);
	}
	else FTest->RadioGroupVariants->Height=INDENTION*5*(((variantsAmount+1)/2)+1);
	FTest->ButtonAnswer->Top=FTest->RadioGroupVariants->Height+FTest->RadioGroupVariants->Top+3*INDENTION;

	int distanceBetweenPictures=(FTest->MemoQuestionText->Width-IMAGE_WIDTH*imagesAmount)/(imagesAmount+1);
	for (i = 0; i < imagesAmount; i++) {
		images[i]->Left=distanceBetweenPictures + FTest->MemoQuestionText->Left + i*(IMAGE_WIDTH+distanceBetweenPictures);
	}

	FTest->ProgressBar1->StepIt();
	FTest->MemoQuestionText->Visible=true;
	if (TestQuestions[globalCounter].getQuestionType()=="choose") {
		FTest->RadioGroupVariants->Visible=true;
	}
	else if(TestQuestions[globalCounter].getQuestionType()=="write"){
        FTest->LabelEnterAnswer->Left=FTest->MemoQuestionText->Left;
		FTest->LabelEnterAnswer->Top=FTest->RadioGroupVariants->Top;
		FTest->EditAnswer->Left=FTest->LabelEnterAnswer->Left+FTest->LabelEnterAnswer->Width+2*INDENTION;
		FTest->EditAnswer->Top=FTest->LabelEnterAnswer->Top;

		FTest->LabelEnterAnswer->Visible=true;
		FTest->EditAnswer->Visible=true;
	}
}

void deleteTest(){
	int i;
	for (i = 0; i < IMAGES_AMOUNT; i++) {
		images[i]->Free();
	}
	testStatistics.clearing();
	delete []TestQuestions;
}

void __fastcall TFTest::ButtonGoBackClick(TObject *Sender)
{
	deleteTest();
	FTest->Hide();
	FStart->Show();
}
//---------------------------------------------------------------------------

void addParagraph(int* paragraphCounter,Variant* Paragraphs,AnsiString text){
	Variant Paragraph;
	(*Paragraphs).OleProcedure("Add");
	Paragraph=(*Paragraphs).OleFunction("Item",*paragraphCounter);
	Paragraph.OlePropertyGet("Range").OlePropertySet("Text",StringToOleStr(text));
	(*paragraphCounter)++;
}

AnsiString dateNow(){
	TDateTime Date;
	AnsiString date=FormatDateTime("d m y",Date.CurrentDateTime());
	int length=date.Length();
	for (int i = 1; i <= length; i++) {
		if (date[i]==' ') {
			date[i]='.';
		}
	}
	return date;
}

void creatingDocument(){
	Variant WordApplication,WordDocuments,Document,Paragraphs,Paragraph;
	TDateTime Date;
	int i,j,paragraphsCounter=1;										//
	AnsiString title="Тестирование "+dateNow()+" \t\t\t\tТестируемый: " + username;  //   имя
																		 //  пользователя
	try{                                                                //
		WordApplication=CreateOleObject("Word.Application");
	}
	catch(...){
		ShowMessage("Ошибка открытия Word");
	}

	WordApplication.OlePropertySet("Visible",true);
	WordDocuments=WordApplication.OlePropertyGet("Documents");
	WordDocuments.OleProcedure("Add");
	Document=WordDocuments.OleFunction("Item",paragraphsCounter);
	paragraphsCounter++;
	Document.OleProcedure("Activate");
	Paragraphs=Document.OlePropertyGet("Paragraphs");

	addParagraph(&paragraphsCounter,&Paragraphs,title);

	for (i = 0; i <questionsAmount ; i++) {
		addParagraph(&paragraphsCounter,&Paragraphs,"");
		addParagraph(&paragraphsCounter,&Paragraphs,"Вопрос "+IntToStr(i+1)+": "+TestQuestions[i].getText());
		if (TestQuestions[i].getQuestionType()=="choose"){
			addParagraph(&paragraphsCounter,&Paragraphs,"Варианты ответов: ");
			for (j=0; j < variantsAmount; j++) {
				addParagraph(&paragraphsCounter,&Paragraphs,"\t"+IntToStr(j+1)+"."+TestQuestions[i].getVariant(j));
			}
		}
		addParagraph(&paragraphsCounter,&Paragraphs,"Ответ тестируемого: "+TestQuestions[i].getUserAnswer());
		addParagraph(&paragraphsCounter,&Paragraphs,"Правильный ответ: "+TestQuestions[i].getRightVariant());
	}
	addParagraph(&paragraphsCounter,&Paragraphs,"");
	addParagraph(&paragraphsCounter,&Paragraphs,"");
	addParagraph(&paragraphsCounter,&Paragraphs,"Результат: "+IntToStr(testStatistics.getCollectedPoints())+" из " +IntToStr(questionsAmount)+" вопросов отвечены верно");
	addParagraph(&paragraphsCounter,&Paragraphs,"Оценка: " + IntToStr(testStatistics.testResult()));
}

void __fastcall TFTest::ButtonCreateDocumentClick(TObject *Sender)
{
	creatingDocument();
}
//---------------------------------------------------------------------------
void addToCell(Variant Sheet,int row,int col,AnsiString value){
	Variant Cell;
	Cell=Sheet.OlePropertyGet("Cells").OlePropertyGet("Item",row,col);
	Cell.OlePropertySet("Value",StringToOleStr(value));
}

void saveTest(){
	FTest->SaveDialog1->FileName="Тестирование "+dateNow();
	if (FTest->SaveDialog1->Execute()){
		int i,j;
		Variant ExcelApplication,ExcelBooks,Book,Sheet,Sheets,Cell;
		ExcelApplication=CreateOleObject("Excel.Application");
		//ExcelApplication.OlePropertySet("Visible",true);
		ExcelBooks=ExcelApplication.OlePropertyGet("Workbooks");
		ExcelBooks.OleProcedure("Add");
		Book=ExcelBooks.OlePropertyGet("Item",1);
		Sheets=Book.OlePropertyGet("Worksheets");
		Sheet=Sheets.OlePropertyGet("Item",1);
		Sheet.OlePropertySet("Name",StringToOleStr("Тестирование "+dateNow()));

		for (i=0; i < questionsAmount; i++) {
			addToCell(Sheet,i+1,1,TestQuestions[i].getText());  //A
			addToCell(Sheet,i+1,2,TestQuestions[i].getRightVariant()); //B
			for (j=0; j < variantsAmount; j++) {
				addToCell(Sheet,i+1,3+j,TestQuestions[i].getVariant(j)); //от C до K
			}
			addToCell(Sheet,i+1,13,IntToStr(TestQuestions[i].getDifficulty()));//M
			addToCell(Sheet,i+1,1,TestQuestions[i].getText());
			for (j=0; j < IMAGES_AMOUNT; j++) {
				addToCell(Sheet,i+1,14+j,TestQuestions[i].getPicture(j));  //N-Q
			}
		}
		addToCell(Sheet,1,18,questionsAmount);//R
		addToCell(Sheet,1,19,variantsAmount+1);//S
		ExcelApplication.OlePropertyGet("Workbooks").OlePropertyGet("Item",1).OleProcedure("SaveAs",StringToOleStr(FTest->SaveDialog1->FileName+".xlsx"));
		ExcelApplication.OleProcedure("Quit");
	}
}
void __fastcall TFTest::ButtonSaveTestClick(TObject *Sender)
{
	saveTest();
}
//---------------------------------------------------------------------------

