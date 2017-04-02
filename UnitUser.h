//---------------------------------------------------------------------------

#ifndef UnitUserH
#define UnitUserH
//---------------------------------------------------------------------------
#endif
#include <vcl.h>
class User{
	private:
		AnsiString name;
	public:
		User();

		AnsiString getName();
		void setName(AnsiString Name);
};