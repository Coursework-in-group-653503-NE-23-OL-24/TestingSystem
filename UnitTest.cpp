//---------------------------------------------------------------------------

#pragma hdrstop

#include "UnitQuestion.h"
#include "FormStart.h"
#include "FormCharacteristics.h"
#include "FormTest.h"
#include "UnitTest.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
Test::Test(){
	maxPoints=0;
	collectedPoints=0;
	wrongAnswers="";
}

int Test::getMaxPoints() { return maxPoints;}
void Test::addMaxPoints(int points) { maxPoints+=points;}
int Test::getCollectedPoints() { return collectedPoints;}
void Test::addCollectedPoints(int points) { collectedPoints+=points;}
AnsiString Test::getWrongAnswers(){return wrongAnswers;}
void Test::addWrongAnswers(AnsiString answer){ wrongAnswers+=answer+", "; }
int Test::getQuestionsAmount(){ return questionsAmount;}
void Test::addQuestionsAmount(){questionsAmount++;}

int Test::testResult(){
	double result=(double)(10*collectedPoints)/maxPoints;
	if (result-(int)result>=0.5) {
		return ((int)result)+1;
	}
	else return (int)result;
}

void Test::clearing(){
    maxPoints=0;
	collectedPoints=0;
	wrongAnswers="";
	questionsAmount=0;
}
