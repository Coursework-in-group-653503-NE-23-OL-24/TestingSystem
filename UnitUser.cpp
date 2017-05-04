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

AnsiString User::getSurname(){ return surname;}
void User::setSurname(AnsiString Surname){ surname=Surname; }

AnsiString User::getGroup(){ return group;}
void User::setGroup(AnsiString Group){ group=Group; }


int User::getLastMark(){return lastMark;}
void User::setLastMark(int mark){lastMark = mark;}

int User::getAllTestsResult(){return allTestsResult;}
void User::setAllTestsResult(int result){allTestsResult = result;}

float User::getAverageScore(){return averageScore;}
void User::setAverageScore(float score){averageScore = score;}

