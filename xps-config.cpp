#include "xps-config.h"

using namespace std;

int main(int argc, char const *argv[]){

	char PEACE_Input = ' ';
	char CVC_Input = ' ';
	int E_Flag = -1;

	cout << "Due to technical issues, control of ThrottleStop has been disabled.\n";
	cout << "Initialize microphone? [Y/N]\n";

	while(E_Flag != 0){
		cout << "\n";
		cin >> PEACE_Input;
		cout << "\n";

		if(!(PEACE_Input == 'y' || PEACE_Input == 'n')){
			cout << "Error: Invalid input. Try again.\n";
			E_Flag = 1;
		}
		else{
			E_Flag =  0;
		}
	}

	if(PEACE_Input == 'y'){
		E_Flag = 1;

		cout << "Execution of CVC without a valid input device will generate errors.\nExecute CVC? [Y/N]\n";

		while(E_Flag != 0){
			cout << "\n";
			cin >> CVC_Input;
			cout << "\n";

			if(!(CVC_Input == 'y' || CVC_Input == 'n')){
				cout << "Error: Invalid input. Try again.\n";
				E_Flag = 1;
			}
			else{
				E_Flag =  0;
			}
		}
	}

	if(CVC_Input == 'n'){
		cout << "CVC Disabled.\n";
	}

	//system("taskkill /F /T /IM ThrottleStop.exe");

	if(!ShellExecuteA(NULL, "open", PATH_01, NULL, NULL, SW_HIDE)){
		cout << "Error: Could not open BNET.\n";
	}

	if(!ShellExecuteA(NULL, "open", PATH_03, NULL, NULL, SW_HIDE)){
		cout << "Error: Could not open MSI.\n";
	}
	
	/*
	if(!ShellExecuteA(NULL, "open", PATH_04, NULL, NULL, SW_HIDE)){
		cout << "Error: Could not open TS.\n";
	}
	*/
	
	if(PEACE_Input == 'y'){
		if(!ShellExecuteA(NULL, "open", PATH_05, NULL, NULL, SW_HIDE)){
			cout << "Error: Could not open PEACE.\n";
		}

		if(CVC_Input == 'y'){
			if(!ShellExecuteA(NULL, "open", PATH_02, NULL, NULL, SW_HIDE)){
				cout << "Error: Could not open CVC.\n";
			}
		}
	}

	cout << "Execution complete. Press any key to exit.\n";

	_getch();

	return 0;
}