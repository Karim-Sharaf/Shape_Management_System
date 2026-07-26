#pragma once

#include <string>
#include <array>

class UI {
	private:
		string userName;
		string password;
		string userType;
		
		void ClearScreen();
		
		bool ValidateInput(int input, int min, int max);
	
	public:
		int MainMenu();

		//		tuple<string, string, string> GetShapeInput();
		array<string, 3> GetShapeInput();
		
		void PrintResult(string msg);
};
