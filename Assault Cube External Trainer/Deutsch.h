#ifndef DEUTSCH_H
#define DEUTSCH_H

#include <iostream>
#include <Windows.h>


using namespace std;
void ClearEnter();
void SimulateEnter();

struct offsets
{
	int Localplayer = 0x0051E20C;	// für Player Sachen benutzen (Health, Rüsstung, etc.)
	int Base;

	// === Health ===
	int Health = 0xF8;
	
	int SetHealth = 100;

	// === Rüstung ===
	int Rüstung = 0xFC;
	int SetRüstung = 100;
	

	// === Reserve Muni ===
	int ResMuniSMG = 0x128;
	int SetResMuniSMG;
	

	// === Muni MagazinSMG ===
	int MuniMagazinSMG = 0x150;
	int SetMuniMagazinSMG;
	

	// === Flashbang ===
	int Flashbang = 0x0158;
	int SetFlashbang;

}off;


void start()
{
	system("COLOR A");
	SetConsoleTitleA("AC External Menu made by Scotch#5627");

	// === PID finden ===
	DWORD ProcessID;
	HWND hwnd = FindWindowA(0, ("AssaultCube"));
	GetWindowThreadProcessId(hwnd, &ProcessID);
	if (hwnd)
	{
		cout << "Assault Cube gefunden...\n";
		Sleep(561);
		HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
		if (hProcess == NULL)
		{
			cout << "OpenProcess fehlgeschlagen. GetLastError: " << GetLastError();
			cout << "ENTER zum Beenden...." << endl;
			ClearEnter();
			getchar();
			return exit(1);
		}
		else
		{
			cout << "Injection startet\n";
			
			bool Check1 = ReadProcessMemory(hProcess, (LPCVOID)(off.Localplayer), &off.Base, sizeof(int), NULL);
			if (Check1 == true)
			{
				cout << "Base Offset gefunden....\n";
				Sleep(1234);
				system("cls");
			}
			do {
				system("cls");
				cout << "===  AC External Cheat   ===\n";
				cout << "===  Made by Scotch#5627 ===\n";
				cout << endl;
				cout << "Num1 = Set Health\n";
				cout << "Num2 = Set Armor\n";
				cout << "Num3 = Set Ammo SMG\n";
				cout << "Num4 = Set reserve Ammo SMG\n";
				cout << "Num5 = Set Granate\n";
				cout << "Num6 = Unload Menu\n";

				if(GetAsyncKeyState(VK_NUMPAD1))
				{
					/*cout << endl;
					cout << "Number of lives: ";
					cin >> off.SetHealth;
					WriteProcessMemory(hProcess, (LPVOID)(off.Base + off.Health), &off.SetHealth, sizeof(int), NULL);
					system("cls");
					SimulateEnter();*/
					cout << "Numpad gedrueckt!\n";
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
							system("cls");
							cout << "Assault Cube wurde beendet.\n";
							Sleep(2500);
							CloseHandle(hProcess);
							exit(0);
						}
					}
				} while (true);

			} while (!VK_NUMPAD6);
		}
	}
	else
	{
		MessageBoxA(NULL, "AssaultCube nicht gefunden!\nBitte AssaultCube starten...", "FEHLER", CB_OKAY | MB_ICONERROR);
	}
}

void ClearEnter()
{
	cin.ignore(cin.rdbuf()->in_avail());
}

void SimulateEnter()
{
	keybd_event(VK_RETURN, 0x9C, 0, 0);
}

#endif