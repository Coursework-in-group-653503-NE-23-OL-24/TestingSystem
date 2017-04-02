//---------------------------------------------------------------------------

#ifndef UnitQuestionH
#define UnitQuestionH
//---------------------------------------------------------------------------
#endif
#include <vcl.h>
#define MAXIMAL_VARIANTS_AMOUNT 9
#define MAXIMAL_PICTURES_AMOUNT 4
class Question{
	private:
		int difficulty;
		int questionNumber;
		AnsiString text;
		AnsiString picture[MAXIMAL_PICTURES_AMOUNT];
		AnsiString rightVariant;
		AnsiString variants[MAXIMAL_VARIANTS_AMOUNT];
		AnsiString userAnswer;
		AnsiString questionType;

	public:
		Question();

		int getDifficulty();
		void setDifficulty(int Difficulty);
		int getQuestionNumber();
		void setQuestionNumber(int number);
		AnsiString getUserAnswer();
		void setUserAnswer(AnsiString answer);
		AnsiString getText();
		void setText(AnsiString Text);
		AnsiString getRightVariant();
		void setRightVariant(AnsiString Text);
		AnsiString getVariant(int i);
		void setVariant(AnsiString Text,int i);
		AnsiString getPicture(int number);
		void setPicture(AnsiString way,int number);
		AnsiString getQuestionType();
		void setQuestionType(AnsiString type);
};

