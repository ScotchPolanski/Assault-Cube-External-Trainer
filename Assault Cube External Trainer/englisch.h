/*#ifndef ENGLISCH_H
#define ENGLISCH_H

#include <iostream>
#include <Windows.h>
#include <conio.h>

#include <Urlmon.h>

using namespace std;
void ClearEnter();
void PID();
void OpenProcess();
void SimulateEnter();




void englisch()
{
	SetConsoleTitleA("AC External Menu made by Scotch#5627");

	// === PID finden ===
	DWORD ProcessID;
	HWND hwnd = FindWindowA(0, ("AssaultCube"));
	GetWindowThreadProcessId(hwnd, &ProcessID);
	if (hwnd)
	{
		cout << "Assault Cube found...\n";
		Sleep(561);
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
		if (hProcess == NULL)
		{
			cout << "OpenProcess failed. GetLastError: " << GetLastError();
			cout << "ENTER to exit...." << endl;
			ClearEnter();
			getchar();
			return exit(1);
		}
		else
		{
			cout << "Injection starts\n";

			bool Check1 = ReadProcessMemory(hProcess, (LPCVOID)(off.Localplayer), &off.Base, sizeof(int), NULL);
			if (Check1 == true)
			{
				cout << "Base Offset found....\n";
				Sleep(1234);
				system("cls");
			}
			do {
				system("cls");
				cout << "===  AC External Cheat   ===\n";
				cout << "===  Made by Scotch#5627 ===\n";
				cout << endl;
				WriteProcessMemory(hProcess, (LPVOID)(off.Localplayer + off.Speed), &off.SetSpeed, sizeof(int), NULL);
				cout << "Num1 = Set Health\n";
				cout << "Num2 = Set Armor\n";
				cout << "Num3 = Set Ammo SMG\n";
				cout << "Num4 = Set reserve Ammo SMG\n";
				cout << "Num5 = Set Granate\n";
				cout << "Num6 = Unload Menu\n";


				if (GetAsyncKeyState(VK_NUMPAD1))																									// Set Health
				{
					cout << endl;
					cout << "Number of lives: ";
					cin >> off.SetHealth;
					WriteProcessMemory(hProcess, (LPVOID)(off.Base + off.Health), &off.SetHealth, sizeof(int), NULL);
					system("cls");
					SimulateEnter();
				}

				if (GetAsyncKeyState(VK_NUMPAD2))
				{
					cout << endl;
					cout << "Number of armor: ";
					cin >> off.SetRüstung;
					WriteProcessMemory(hProcess, (LPVOID)(off.Base + off.Rüstung), &off.SetRüstung, sizeof(int), NULL);
					system("cls");
					SimulateEnter();
				}

				if (GetAsyncKeyState(VK_NUMPAD3))
				{
					cout << endl;
					cout << "Number of ammo: ";
					cin >> off.SetMuniMagazinSMG;
					WriteProcessMemory(hProcess, (LPVOID)(off.Base + off.MuniMagazinSMG), &off.SetMuniMagazinSMG, sizeof(int), NULL);
					system("cls");
					SimulateEnter();
				}

				if (GetAsyncKeyState(VK_NUMPAD4))
				{
					cout << endl;
					cout << "Number of reserve ammo: ";
					cin >> off.SetResMuniSMG;
					WriteProcessMemory(hProcess, (LPVOID)(off.Base + off.ResMuniSMG), &off.SetResMuniSMG, sizeof(int), NULL);
					system("cls");
					SimulateEnter();
				}

				if (GetAsyncKeyState(VK_NUMPAD5))
				{
					cout << endl;
					cout << "Number of granates: ";
					cin >> off.SetFlashbang;
					WriteProcessMemory(hProcess, (LPVOID)(off.Base + off.Flashbang), &off.SetFlashbang, sizeof(int), NULL);
					system("cls");
					SimulateEnter();
				}

				if (GetAsyncKeyState(VK_NUMPAD6))
				{
					CloseHandle(hProcess);
					return exit(0);
				}

				do {
					HANDLE Check = FindWindowA(0, ("AssaultCube"));
					{
						if (!Check)
						{
							CloseHandle(hProcess);
							exit(0);
						}
					}
				} while (true);

			} while (_getch() != VK_NUMPAD8);
		}
	}
	else
	{
		cout << "AssaultCube not found!\n";
		cout << "Press Enter to exit!\n";
	}
}
#endif*/