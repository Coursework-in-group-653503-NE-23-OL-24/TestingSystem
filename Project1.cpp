//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <tchar.h>
//---------------------------------------------------------------------------
USEFORM("D:\�������� ������\UsersForm.cpp", UsersF);
USEFORM("D:\�������� ������\FormStart.cpp", FStart);
USEFORM("D:\�������� ������\FormCharacteristics.cpp", FCharacteristics);
USEFORM("D:\�������� ������\FormTest.cpp", FTest);
USEFORM("FormAddUsers.cpp", FAddUser);
//---------------------------------------------------------------------------
int WINAPI _tWinMain(HINSTANCE, HINSTANCE, LPTSTR, int)
{
	try
	{
		Application->Initialize();
		Application->MainFormOnTaskBar = true;
		Application->CreateForm(__classid(TFStart), &FStart);
		Application->CreateForm(__classid(TFCharacteristics), &FCharacteristics);
		Application->CreateForm(__classid(TFTest), &FTest);
		Application->CreateForm(__classid(TUsersF), &UsersF);
		Application->CreateForm(__classid(TFAddUser), &FAddUser);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
