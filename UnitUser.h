//---------------------------------------------------------------------------

#ifndef UnitUserH
#define UnitUserH
//---------------------------------------------------------------------------
#endif
#include <vcl.h>
class User{
	private:
		AnsiString name;
		int lastMark;
		int allTestsResult;
		int averageScore;
	public:
		User();

		int getLastMark();
		void setLastMark(int mark);

		AnsiString getName();
		void setName(AnsiString Name);

		int getAllTestsResult();
		void setAllTestsResult(int result);

		int getAverageScore();
		void setAverageScore(int score);

};