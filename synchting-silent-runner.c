/* Syncthing Silent Runner - v1.0
 * Run Syncthing at MS Windows without the console's window
 * Copyright (c) 2014, Petros Kyladitis <http://www.multipetros.gr/>
 * This is free software distributed under the terms of the FreeBSD License
 */

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR szCmdLine, int iCmdShow){
	int execResult = WinExec("syncthing.exe" , SW_HIDE) ;
	if(execResult == ERROR_BAD_FORMAT || execResult == ERROR_FILE_NOT_FOUND || execResult == ERROR_PATH_NOT_FOUND){
		MessageBoxA(NULL, "Syncthing executable didn\'t found. Please put the \'Syncthing Silent Runner\' in the same folder where the Syncthing executable is placed.", "Syncthing Silent Runner", MB_ICONERROR | MB_OK);
	}
	else if(execResult == 0){
		MessageBoxA(NULL, "Out of memory or system resources. Close some windows or programs and try again.", "Syncthing Silent Runner", MB_ICONERROR | MB_OK);
	}
	exit(0);
}
