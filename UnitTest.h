//---------------------------------------------------------------------------

#ifndef UnitTestH
#define UnitTestH
//---------------------------------------------------------------------------
#endif
#include <vcl.h>
class Test{
	private:
		int maxPoints;
		int collectedPoints;
		AnsiString wrongAnswers;
		int questionsAmount;

	public:
		Test();
		int getMaxPoints();
		void addMaxPoints(int points);
		int getCollectedPoints();
		void addCollectedPoints(int points);
		AnsiString getWrongAnswers();
		void addWrongAnswers(AnsiString answer);
		int testResult();
		void clearing();
		int getQuestionsAmount();
		void addQuestionsAmount();
};