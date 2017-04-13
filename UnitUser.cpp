//---------------------------------------------------------------------------

#pragma hdrstop


#include "UnitUser.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#include <vcl.h>
User::User(){
	name="";
}

AnsiString User::getName(){ return name;}
void User::setName(AnsiString Name){ name=Name; }


int User::getLastMark(){return lastMark;}
void User::setLastMark(int mark){lastMark = mark;}

int User::getAllTestsResult(){return allTestsResult;}
void User::setAllTestsResult(int result){allTestsResult = result;}

int User::getAverageScore(){return averageScore;}
void User::setAverageScore(int score){averageScore = score;}
