//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitQuestion.h"
#include "FormStart.h"
#include "FormCharacteristics.h"
#include "FormTest.h"
#include "UnitTest.h"

#include <vcl.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)

Question::Question(){
	difficulty=1;
	text="";
}

int   	   Question::getDifficulty()						{ return difficulty; 			}
void  	   Question::setDifficulty(int Difficulty)         	{ difficulty=Difficulty;			}
int Question::getQuestionNumber(){ return questionNumber; }
void Question::setQuestionNumber(int number){ questionNumber=number; }
AnsiString Question::getText(){ return text; }
void Question::setText(AnsiString Text){ text=Text; }
AnsiString Question::getRightVariant(){ return rightVariant; }
void Question::setRightVariant(AnsiString Text){ rightVariant=Text; }
AnsiString Question::getPicture(int number){ return picture[number];}
void Question::setPicture(AnsiString way,int number){ picture[number]=way;}
AnsiString Question::getUserAnswer(){return userAnswer;}
void Question::setUserAnswer(AnsiString answer){ userAnswer=answer;}
AnsiString Question::getQuestionType(){return questionType;}
void Question::setQuestionType(AnsiString type){ questionType=type;}

AnsiString Question::getVariant(int i){
	if (i >= 0 && i < 9) {  //MAX_VARIANTS_AMOUNT
		return variants[i];
	}
	else return 0;
}

void Question::setVariant(AnsiString Text,int i){
	if (i >= 0 && i < 9) { //MAX_VARIANTS_AMOUNT
		variants[i]=Text;
	}
}
