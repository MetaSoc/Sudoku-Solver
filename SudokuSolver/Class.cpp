#include "Class.h"

Menu::Menu()
{
	/* Ustawienie wielkoœci i po³o¿enia konsoli */
	CenterConsole();
	SetFontSize();
	SetConsoleSize();
	CenterConsole();

	/* Okno ³adowania */
	loading();
	/* Ustawienie pêtli dla Menu, pêtla koñczy siê, kiedy funkcja menu() zwróci 1, czyli u¿ytkownik wybierze rozwi¹zanie sudoku */
	int Menu = menu();
	while (Menu != 1)
		Menu = menu();
}
void Menu::ShowConsoleCursor(bool showFlag) /* Wy³¹czenie wyœwietlania kursora w konsoli */
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void Menu::CursPos(int x, int y)	/* Ustawienie pozycji kursora */
{
	COORD c{};
	c.X = x - 1; c.Y = y - 1;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Menu::SetConsoleSize()	/* Ustawienie rozmiaru okna konsoli */
{
	HWND console = GetConsoleWindow();
	RECT ConsoleRect;
	GetWindowRect(console, &ConsoleRect);

	MoveWindow(console, ConsoleRect.left, ConsoleRect.top, 1140, 800, TRUE);
}
void Menu::SetFontSize()	/* Ustawienie rozmiaru czcionki */
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 1000;	//bold (default: 700)
	fontex.dwFontSize.X = 28;	//size
	fontex.dwFontSize.Y = 28;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}
void Menu::CenterConsole()	/* Zcentrowanie konsoli na ekranie */
{
	RECT rectClient, rectWindow;
	HWND hWnd = GetConsoleWindow();
	GetClientRect(hWnd, &rectClient);
	GetWindowRect(hWnd, &rectWindow);
	int posx, posy;
	posx = GetSystemMetrics(SM_CXSCREEN) / 2 - (rectWindow.right - rectWindow.left) / 2;
	posy = GetSystemMetrics(SM_CYSCREEN) / 2 - (rectWindow.bottom - rectWindow.top) / 2;

	MoveWindow(hWnd, posx, posy, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE);
}
void Menu::sudoku_solver_txt(bool isLoading)	/* Wielki napis SUDOKU SOLVER */
{
	if (!isLoading) // sta³y tekst
	{
		CursPos(16, 3); cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
		CursPos(16, 4); cout << "°°ÛÛÛÛÛÛ»ÛÛ»°°°ÛÛ»ÛÛÛÛÛÛ»°°ÛÛÛÛÛ»°ÛÛ»°°ÛÛ»ÛÛ»°°°ÛÛ»°";
		CursPos(16, 5); cout << "°ÛÛÉÍÍÍÍ¼ÛÛº°°°ÛÛºÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛº°ÛÛÉ¼ÛÛº°°°ÛÛº°";
		CursPos(16, 6); cout << "°ÈÛÛÛÛÛ»°ÛÛº°°°ÛÛºÛÛº°°ÛÛºÛÛº°°ÛÛºÛÛÛÛÛÍ¼°ÛÛº°°°ÛÛº°";
		CursPos(16, 7); cout << "°°ÈÍÍÍÛÛ»ÛÛº°°°ÛÛºÛÛº°°ÛÛºÛÛº°°ÛÛºÛÛÉÍÛÛ»°ÛÛº°°°ÛÛº°";
		CursPos(16, 8); cout << "°ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÉ¼ÛÛº°ÈÛÛ»ÈÛÛÛÛÛÛÉ¼°";
		CursPos(16, 9); cout << "°ÈÍÍÍÍÍ¼°°ÈÍÍÍÍÍ¼°ÈÍÍÍÍÍ¼°°ÈÍÍÍÍ¼°ÈÍ¼°°ÈÍ¼°ÈÍÍÍÍÍ¼°°";
		CursPos(16, 10); cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°";
		CursPos(16, 11); cout << "°°ÛÛÛÛÛÛ»°ÛÛÛÛÛ»°ÛÛ»°°°°°ÛÛ»°°°ÛÛ»ÛÛÛÛÛÛÛ»ÛÛÛÛÛÛ»°°°";
		CursPos(16, 12); cout << "°ÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»ÛÛº°°°°°ÛÛº°°°ÛÛºÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»°°";
		CursPos(16, 13); cout << "°ÈÛÛÛÛÛ»°ÛÛº°°ÛÛºÛÛº°°°°°ÈÛÛ»°ÛÛÉ¼ÛÛÛÛÛ»°°ÛÛÛÛÛÛÉ¼°°";
		CursPos(16, 14); cout << "°°ÈÍÍÍÛÛ»ÛÛº°°ÛÛºÛÛº°°°°°°ÈÛÛÛÛÉ¼°ÛÛÉÍÍ¼°°ÛÛÉÍÍÛÛ»°°";
		CursPos(16, 15); cout << "°ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛ»°°ÈÛÛÉ¼°°ÛÛÛÛÛÛÛ»ÛÛº°°ÛÛº°°";
		CursPos(16, 16); cout << "°ÈÍÍÍÍÍ¼°°ÈÍÍÍÍ¼°ÈÍÍÍÍÍÍ¼°°°ÈÍ¼°°°ÈÍÍÍÍÍÍ¼ÈÍ¼°°ÈÍ¼°°";
		CursPos(16, 17); cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
	}
	else // animowany tekst
	{
		//	tekst SUDOKU SOLVER
		CursPos(16, 4); cout << "  ÛÛÛÛÛÛ»ÛÛ»   ÛÛ»ÛÛÛÛÛÛ»  ÛÛÛÛÛ» ÛÛ»  ÛÛ»ÛÛ»   ÛÛ» "; Sleep(10);
		CursPos(16, 5); cout << " ÛÛÉÍÍÍÍ¼ÛÛº   ÛÛºÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛº ÛÛÉ¼ÛÛº   ÛÛº "; Sleep(10);
		CursPos(16, 6); cout << " ÈÛÛÛÛÛ» ÛÛº   ÛÛºÛÛº  ÛÛºÛÛº  ÛÛºÛÛÛÛÛÍ¼ ÛÛº   ÛÛº "; Sleep(10);
		CursPos(16, 7); cout << "  ÈÍÍÍÛÛ»ÛÛº   ÛÛºÛÛº  ÛÛºÛÛº  ÛÛºÛÛÉÍÛÛ» ÛÛº   ÛÛº "; Sleep(10);
		CursPos(16, 8); cout << " ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÉ¼ÛÛº ÈÛÛ»ÈÛÛÛÛÛÛÉ¼ "; Sleep(10);
		CursPos(16, 9); cout << " ÈÍÍÍÍÍ¼  ÈÍÍÍÍÍ¼ ÈÍÍÍÍÍ¼  ÈÍÍÍÍ¼ ÈÍ¼  ÈÍ¼ ÈÍÍÍÍÍ¼  "; Sleep(20);

		CursPos(16, 11); cout << "  ÛÛÛÛÛÛ» ÛÛÛÛÛ» ÛÛ»     ÛÛ»   ÛÛ»ÛÛÛÛÛÛÛ»ÛÛÛÛÛÛ»   "; Sleep(10);
		CursPos(16, 12); cout << " ÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»ÛÛº     ÛÛº   ÛÛºÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»  "; Sleep(10);
		CursPos(16, 13); cout << " ÈÛÛÛÛÛ» ÛÛº  ÛÛºÛÛº     ÈÛÛ» ÛÛÉ¼ÛÛÛÛÛ»  ÛÛÛÛÛÛÉ¼  "; Sleep(10);
		CursPos(16, 14); cout << "  ÈÍÍÍÛÛ»ÛÛº  ÛÛºÛÛº      ÈÛÛÛÛÉ¼ ÛÛÉÍÍ¼  ÛÛÉÍÍÛÛ»  "; Sleep(10);
		CursPos(16, 15); cout << " ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛ»  ÈÛÛÉ¼  ÛÛÛÛÛÛÛ»ÛÛº  ÛÛº  "; Sleep(10);
		CursPos(16, 16); cout << " ÈÍÍÍÍÍ¼  ÈÍÍÍÍ¼ ÈÍÍÍÍÍÍ¼   ÈÍ¼   ÈÍÍÍÍÍÍ¼ÈÍ¼  ÈÍ¼  "; Sleep(800);


		//	background
		CursPos(16, 17); cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"; Sleep(10);
		CursPos(16, 16); cout << "°ÈÍÍÍÍÍ¼°°ÈÍÍÍÍ¼°ÈÍÍÍÍÍÍ¼°°°ÈÍ¼°°°ÈÍÍÍÍÍÍ¼ÈÍ¼°°ÈÍ¼°°"; Sleep(10);
		CursPos(16, 15); cout << "°ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÉ¼ÛÛÛÛÛÛÛ»°°ÈÛÛÉ¼°°ÛÛÛÛÛÛÛ»ÛÛº°°ÛÛº°°"; Sleep(10);
		CursPos(16, 14); cout << "°°ÈÍÍÍÛÛ»ÛÛº°°ÛÛºÛÛº°°°°°°ÈÛÛÛÛÉ¼°ÛÛÉÍÍ¼°°ÛÛÉÍÍÛÛ»°°"; Sleep(10);
		CursPos(16, 13); cout << "°ÈÛÛÛÛÛ»°ÛÛº°°ÛÛºÛÛº°°°°°ÈÛÛ»°ÛÛÉ¼ÛÛÛÛÛ»°°ÛÛÛÛÛÛÉ¼°°"; Sleep(10);
		CursPos(16, 12); cout << "°ÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»ÛÛº°°°°°ÛÛº°°°ÛÛºÛÛÉÍÍÍÍ¼ÛÛÉÍÍÛÛ»°°"; Sleep(10);
		CursPos(16, 11); cout << "°°ÛÛÛÛÛÛ»°ÛÛÛÛÛ»°ÛÛ»°°°°°ÛÛ»°°°ÛÛ»ÛÛÛÛÛÛÛ»ÛÛÛÛÛÛ»°°°"; Sleep(10);
		CursPos(16, 10); cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"; Sleep(10);
		CursPos(16, 9); cout << "°ÈÍÍÍÍÍ¼°°ÈÍÍÍÍÍ¼°ÈÍÍÍÍÍ¼°°ÈÍÍÍÍ¼°ÈÍ¼°°ÈÍ¼°ÈÍÍÍÍÍ¼°°"; Sleep(10);
		CursPos(16, 8); cout << "°ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÛÉ¼ÛÛÛÛÛÛÉ¼ÈÛÛÛÛÛÉ¼ÛÛº°ÈÛÛ»ÈÛÛÛÛÛÛÉ¼°"; Sleep(10);
		CursPos(16, 7); cout << "°°ÈÍÍÍÛÛ»ÛÛº°°°ÛÛºÛÛº°°ÛÛºÛÛº°°ÛÛºÛÛÉÍÛÛ»°ÛÛº°°°ÛÛº°"; Sleep(10);
		CursPos(16, 6); cout << "°ÈÛÛÛÛÛ»°ÛÛº°°°ÛÛºÛÛº°°ÛÛºÛÛº°°ÛÛºÛÛÛÛÛÍ¼°ÛÛº°°°ÛÛº°"; Sleep(10);
		CursPos(16, 5); cout << "°ÛÛÉÍÍÍÍ¼ÛÛº°°°ÛÛºÛÛÉÍÍÛÛ»ÛÛÉÍÍÛÛ»ÛÛº°ÛÛÉ¼ÛÛº°°°ÛÛº°"; Sleep(10);
		CursPos(16, 4); cout << "°°ÛÛÛÛÛÛ»ÛÛ»°°°ÛÛ»ÛÛÛÛÛÛ»°°ÛÛÛÛÛ»°ÛÛ»°°ÛÛ»ÛÛ»°°°ÛÛ»°"; Sleep(10);
		CursPos(16, 3); cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"; Sleep(700);
	}
}
void Menu::loading()	/* Ekran ³adowania */
{
	unsigned char kr = 0x16;
	ShowConsoleCursor(0);

	Sleep(700);
	sudoku_solver_txt(1);

	system("cls");
	Sleep(50);

	sudoku_solver_txt(0);
	Sleep(400);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 50; i++)
		cout << " ";
	cout << "]";
	Sleep(780);
	system("cls");

	sudoku_solver_txt(0);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 6; i++)
		cout << kr;
	for (int i = 0; i < 44; i++)
		cout << " ";
	cout << "]";
	Sleep(336);
	system("cls");

	sudoku_solver_txt(0);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 18; i++)
		cout << kr;
	for (int i = 0; i < 32; i++)
		cout << " ";
	cout << "]";
	Sleep(192);
	system("cls");

	sudoku_solver_txt(0);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 25; i++)
		cout << kr;
	for (int i = 0; i < 25; i++)
		cout << " ";
	cout << "]";
	Sleep(576);
	system("cls");

	sudoku_solver_txt(0);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 35; i++)
		cout << kr;
	cout << "               ]";
	Sleep(240);
	system("cls");

	sudoku_solver_txt(0);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 39; i++)
		cout << kr;
	cout << "           ]";
	Sleep(96);
	system("cls");

	sudoku_solver_txt(0);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 49; i++)
		cout << kr;
	cout << " ]";
	Sleep(720);
	system("cls");

	sudoku_solver_txt(0);
	CursPos(49, 21); cout << "by Michal Soboszek";
	CursPos(49, 22); cout << "& Pawel Kasztura";

	CursPos(16, 19); cout << "[";
	for (int i = 0; i < 50; i++)
		cout << kr;
	cout << "]";
	Sleep(1000);
}
int Menu::menu()	/* Menu */
{
	int menu_choice{};
	ShowConsoleCursor(0);
	system("cls");
	Sleep(600);

	// background
	CursPos(28, 3); cout << "Ü"; CursPos(28, 4); cout << "Û"; CursPos(28, 5); cout << "Û"; CursPos(28, 6); cout << "Û"; Sleep(1);
	CursPos(29, 3); cout << "Ü"; CursPos(29, 4); cout << "Û"; CursPos(29, 5); cout << "Û"; CursPos(29, 6); cout << "Û"; Sleep(1);
	CursPos(30, 3); cout << "Ü"; CursPos(30, 4); cout << "Û"; CursPos(30, 5); cout << "Û"; CursPos(30, 6); cout << "Û"; Sleep(1);
	CursPos(31, 3); cout << "Ü"; CursPos(31, 4); cout << "Û"; CursPos(31, 5); cout << "Û"; CursPos(31, 6); cout << "Û"; Sleep(1);
	CursPos(32, 3); cout << "Ü"; CursPos(32, 4); cout << "Û"; CursPos(32, 5); cout << "Û"; CursPos(32, 6); cout << "Û"; Sleep(1);
	CursPos(33, 3); cout << "Ü"; CursPos(33, 4); cout << "Û"; CursPos(33, 5); cout << "Û"; CursPos(33, 6); cout << "Û"; Sleep(1);
	CursPos(34, 3); cout << "Ü"; CursPos(34, 4); cout << "Û"; CursPos(34, 5); cout << "Û"; CursPos(34, 6); cout << "Û"; Sleep(1);
	CursPos(35, 3); cout << "Ü"; CursPos(35, 4); cout << "Û"; CursPos(35, 5); cout << "Û"; CursPos(35, 6); cout << "Û"; Sleep(1);
	CursPos(36, 3); cout << "Ü"; CursPos(36, 4); cout << "Û"; CursPos(36, 5); cout << "Û"; CursPos(36, 6); cout << "Û"; Sleep(1);
	CursPos(37, 3); cout << "Ü"; CursPos(37, 4); cout << "Û"; CursPos(37, 5); cout << "Û"; CursPos(37, 6); cout << "Û"; Sleep(1);
	CursPos(38, 3); cout << "Ü"; CursPos(38, 4); cout << "Û"; CursPos(38, 5); cout << "Û"; CursPos(38, 6); cout << "Û"; Sleep(1);
	CursPos(39, 3); cout << "Ü"; CursPos(39, 4); cout << "Û"; CursPos(39, 5); cout << "Û"; CursPos(39, 6); cout << "Û"; Sleep(1);
	CursPos(40, 3); cout << "Ü"; CursPos(40, 4); cout << "Û"; CursPos(40, 5); cout << "Û"; CursPos(40, 6); cout << "Û"; Sleep(1);
	CursPos(41, 3); cout << "Ü"; CursPos(41, 4); cout << "Û"; CursPos(41, 5); cout << "Û"; CursPos(41, 6); cout << "Û"; Sleep(1);
	CursPos(42, 3); cout << "Ü"; CursPos(42, 4); cout << "Û"; CursPos(42, 5); cout << "Û"; CursPos(42, 6); cout << "Û"; Sleep(1);
	CursPos(43, 3); cout << "Ü"; CursPos(43, 4); cout << "Û"; CursPos(43, 5); cout << "Û"; CursPos(43, 6); cout << "Û"; Sleep(1);
	CursPos(44, 3); cout << "Ü"; CursPos(44, 4); cout << "Û"; CursPos(44, 5); cout << "Û"; CursPos(44, 6); cout << "Û"; Sleep(1);
	CursPos(45, 3); cout << "Ü"; CursPos(45, 4); cout << "Û"; CursPos(45, 5); cout << "Û"; CursPos(45, 6); cout << "Û"; Sleep(1);
	CursPos(46, 3); cout << "Ü"; CursPos(46, 4); cout << "Û"; CursPos(46, 5); cout << "Û"; CursPos(46, 6); cout << "Û"; Sleep(1);
	CursPos(47, 3); cout << "Ü"; CursPos(47, 4); cout << "Û"; CursPos(47, 5); cout << "Û"; CursPos(47, 6); cout << "Û"; Sleep(1);
	CursPos(48, 3); cout << "Ü"; CursPos(48, 4); cout << "Û"; CursPos(48, 5); cout << "Û"; CursPos(48, 6); cout << "Û"; Sleep(1);
	CursPos(49, 3); cout << "Ü"; CursPos(49, 4); cout << "Û"; CursPos(49, 5); cout << "Û"; CursPos(49, 6); cout << "Û"; Sleep(1);
	CursPos(50, 3); cout << "Ü"; CursPos(50, 4); cout << "Û"; CursPos(50, 5); cout << "Û"; CursPos(50, 6); cout << "Û"; Sleep(1);
	CursPos(51, 3); cout << "Ü"; CursPos(51, 4); cout << "Û"; CursPos(51, 5); cout << "Û"; CursPos(51, 6); cout << "Û"; Sleep(1);
	CursPos(52, 3); cout << "Ü"; CursPos(52, 4); cout << "Û"; CursPos(52, 5); cout << "Û"; CursPos(52, 6); cout << "Û"; Sleep(1);
	CursPos(53, 3); cout << "Ü"; CursPos(53, 4); cout << "Û"; CursPos(53, 5); cout << "Û"; CursPos(53, 6); cout << "Û"; Sleep(1);
	CursPos(54, 3); cout << "Ü"; CursPos(54, 4); cout << "Û"; CursPos(54, 5); cout << "Û"; CursPos(54, 6); cout << "Û"; Sleep(1);
	CursPos(55, 3); cout << "Ü"; CursPos(55, 4); cout << "Û"; CursPos(55, 5); cout << "Û"; CursPos(55, 6); cout << "Û"; Sleep(1);
	CursPos(56, 3); cout << "Ü"; CursPos(56, 4); cout << "Û"; CursPos(56, 5); cout << "Û"; CursPos(56, 6); cout << "Û"; Sleep(1);
	CursPos(57, 3); cout << "Ü"; CursPos(57, 4); cout << "Û"; CursPos(57, 5); cout << "Û"; CursPos(57, 6); cout << "Û"; Sleep(500);


	// tekst MENU
	CursPos(28, 3); cout << "Ü"; CursPos(28, 4); cout << "Û"; CursPos(28, 5); cout << "Û"; CursPos(28, 6); cout << "Û"; Sleep(1);
	CursPos(29, 3); cout << "Ü"; CursPos(29, 4); cout << "Ü"; CursPos(29, 5); cout << "Û"; CursPos(29, 6); cout << "Ü"; Sleep(1);
	CursPos(30, 3); cout << "Ü"; CursPos(30, 4); cout << "Ä"; CursPos(30, 5); cout << "Ä"; CursPos(30, 6); cout << "Ü"; Sleep(1);
	CursPos(31, 3); cout << "Ü"; CursPos(31, 4); cout << "ß"; CursPos(31, 5); cout << "Û"; CursPos(31, 6); cout << "Ü"; Sleep(1);
	CursPos(32, 3); cout << "Ü"; CursPos(32, 4); cout << "Û"; CursPos(32, 5); cout << "Ü"; CursPos(32, 6); cout << "Û"; Sleep(1);
	CursPos(33, 3); cout << "Ü"; CursPos(33, 4); cout << "ß"; CursPos(33, 5); cout << "Û"; CursPos(33, 6); cout << "Ü"; Sleep(1);
	CursPos(34, 3); cout << "Ü"; CursPos(34, 4); cout << "Ä"; CursPos(34, 5); cout << "Ä"; CursPos(34, 6); cout << "Ü"; Sleep(1);
	CursPos(35, 3); cout << "Ü"; CursPos(35, 4); cout << "Ü"; CursPos(35, 5); cout << "Û"; CursPos(35, 6); cout << "Ü"; Sleep(1);
	CursPos(36, 3); cout << "Ü"; CursPos(36, 4); cout << "Û"; CursPos(36, 5); cout << "Û"; CursPos(36, 6); cout << "Û"; Sleep(1);
	CursPos(37, 3); cout << "Ü"; CursPos(37, 4); cout << "Ü"; CursPos(37, 5); cout << "Û"; CursPos(37, 6); cout << "Ü"; Sleep(1);
	CursPos(38, 3); cout << "Ü"; CursPos(38, 4); cout << "Ä"; CursPos(38, 5); cout << "Ä"; CursPos(38, 6); cout << "Ü"; Sleep(1);
	CursPos(39, 3); cout << "Ü"; CursPos(39, 4); cout << "Ü"; CursPos(39, 5); cout << "Ü"; CursPos(39, 6); cout << "Ü"; Sleep(1);
	CursPos(40, 3); cout << "Ü"; CursPos(40, 4); cout << "Ü"; CursPos(40, 5); cout << "Û"; CursPos(40, 6); cout << "Ü"; Sleep(1);
	CursPos(41, 3); cout << "Ü"; CursPos(41, 4); cout << "Ä"; CursPos(41, 5); cout << "ß"; CursPos(41, 6); cout << "Ü"; Sleep(1);
	CursPos(42, 3); cout << "Ü"; CursPos(42, 4); cout << "Û"; CursPos(42, 5); cout << "Û"; CursPos(42, 6); cout << "Û"; Sleep(1);
	CursPos(43, 3); cout << "Ü"; CursPos(43, 4); cout << "Ü"; CursPos(43, 5); cout << "Û"; CursPos(43, 6); cout << "Ü"; Sleep(1);
	CursPos(44, 3); cout << "Ü"; CursPos(44, 4); cout << "Ä"; CursPos(44, 5); cout << "Ä"; CursPos(44, 6); cout << "Ü"; Sleep(1);
	CursPos(45, 3); cout << "Ü"; CursPos(45, 4); cout << "ß"; CursPos(45, 5); cout << "Û"; CursPos(45, 6); cout << "Ü"; Sleep(1);
	CursPos(46, 3); cout << "Ü"; CursPos(46, 4); cout << "Û"; CursPos(46, 5); cout << "Ü"; CursPos(46, 6); cout << "Û"; Sleep(1);
	CursPos(47, 3); cout << "Ü"; CursPos(47, 4); cout << "Ü"; CursPos(47, 5); cout << "ß"; CursPos(47, 6); cout << "Û"; Sleep(1);
	CursPos(48, 3); cout << "Ü"; CursPos(48, 4); cout << "Ä"; CursPos(48, 5); cout << "Ä"; CursPos(48, 6); cout << "Ü"; Sleep(1);
	CursPos(49, 3); cout << "Ü"; CursPos(49, 4); cout << "Ü"; CursPos(49, 5); cout << "Û"; CursPos(49, 6); cout << "Ü"; Sleep(1);
	CursPos(50, 3); cout << "Ü"; CursPos(50, 4); cout << "Û"; CursPos(50, 5); cout << "Û"; CursPos(50, 6); cout << "Û"; Sleep(1);
	CursPos(51, 3); cout << "Ü"; CursPos(51, 4); cout << "Ü"; CursPos(51, 5); cout << "Û"; CursPos(51, 6); cout << "Û"; Sleep(1);
	CursPos(52, 3); cout << "Ü"; CursPos(52, 4); cout << "Ä"; CursPos(52, 5); cout << "Ä"; CursPos(52, 6); cout << "Ü"; Sleep(1);
	CursPos(53, 3); cout << "Ü"; CursPos(53, 4); cout << "Û"; CursPos(53, 5); cout << "Û"; CursPos(53, 6); cout << "Ü"; Sleep(1);
	CursPos(54, 3); cout << "Ü"; CursPos(54, 4); cout << "Û"; CursPos(54, 5); cout << "Û"; CursPos(54, 6); cout << "Ü"; Sleep(1);
	CursPos(55, 3); cout << "Ü"; CursPos(55, 4); cout << "Ä"; CursPos(55, 5); cout << "Ä"; CursPos(55, 6); cout << "Ü"; Sleep(1);
	CursPos(56, 3); cout << "Ü"; CursPos(56, 4); cout << "Ü"; CursPos(56, 5); cout << "Û"; CursPos(56, 6); cout << "Û"; Sleep(1);
	CursPos(57, 3); cout << "Ü"; CursPos(57, 4); cout << "Û"; CursPos(57, 5); cout << "Û"; CursPos(57, 6); cout << "Û"; Sleep(700);

	//	tekst "Welcome to Sudoku Solver!"
	cout << "\n\n W"; Sleep(10); cout << "e"; Sleep(10); cout << "l"; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "m"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "S"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "S"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "!\n"; Sleep(1000);
	//	tekst "What do you want to do? Chose one of the options below by typing a number:"
	cout << " W"; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "y"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "?"; Sleep(500); cout << " "; Sleep(10); cout << "C"; Sleep(10); cout << "h"; Sleep(10); cout << "o"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "f"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << "l"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << " "; Sleep(10); cout << "b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "y"; Sleep(10); cout << "p"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "g"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << ":";

	Sleep(500);
	//	tekst "1. Solve sudoku 2. How to use an app 3. What is a sudoku? 4. Exit"
	CursPos(2, 11); cout << "1"; CursPos(2, 13); cout << "2"; CursPos(2, 15); cout << "3"; CursPos(2, 17); cout << "4"; Sleep(10);
	CursPos(3, 11); cout << "."; CursPos(3, 13); cout << "."; CursPos(3, 15); cout << "."; CursPos(3, 17); cout << "."; Sleep(10);
	CursPos(4, 11); cout << " "; CursPos(4, 13); cout << " "; CursPos(4, 15); cout << " "; CursPos(4, 17); cout << " "; Sleep(10);
	CursPos(5, 11); cout << "S"; CursPos(5, 13); cout << "H"; CursPos(5, 15); cout << "W"; CursPos(5, 17); cout << "E"; Sleep(10);
	CursPos(6, 11); cout << "o"; CursPos(6, 13); cout << "o"; CursPos(6, 15); cout << "h"; CursPos(6, 17); cout << "x"; Sleep(10);
	CursPos(7, 11); cout << "l"; CursPos(7, 13); cout << "w"; CursPos(7, 15); cout << "a"; CursPos(7, 17); cout << "i"; Sleep(10);
	CursPos(8, 11); cout << "v"; CursPos(8, 13); cout << " "; CursPos(8, 15); cout << "t"; CursPos(8, 17); cout << "t"; Sleep(10);
	CursPos(9, 11); cout << "e"; CursPos(9, 13); cout << "t"; CursPos(9, 15); cout << " "; Sleep(10);
	CursPos(10, 11); cout << " "; CursPos(10, 13); cout << "o"; CursPos(10, 15); cout << "i"; Sleep(10);
	CursPos(11, 11); cout << "S"; CursPos(11, 13); cout << " "; CursPos(11, 15); cout << "s"; Sleep(10);
	CursPos(12, 11); cout << "u"; CursPos(12, 13); cout << "u"; CursPos(12, 15); cout << " "; Sleep(10);
	CursPos(13, 11); cout << "d"; CursPos(13, 13); cout << "s"; CursPos(13, 15); cout << "a"; Sleep(10);
	CursPos(14, 11); cout << "o"; CursPos(14, 13); cout << "e"; CursPos(14, 15); cout << " "; Sleep(10);
	CursPos(15, 11); cout << "k"; CursPos(15, 13); cout << " "; CursPos(15, 15); cout << "s"; Sleep(10);
	CursPos(16, 11); cout << "u"; CursPos(16, 13); cout << "t"; CursPos(16, 15); cout << "u"; Sleep(10);
	CursPos(17, 13); cout << "h"; CursPos(17, 15); cout << "d"; Sleep(10);
	CursPos(18, 13); cout << "e"; CursPos(18, 15); cout << "o"; Sleep(10);
	CursPos(19, 13); cout << " "; CursPos(19, 15); cout << "k"; Sleep(10);
	CursPos(20, 13); cout << "a"; CursPos(20, 15); cout << "u"; Sleep(10);
	CursPos(21, 13); cout << "p"; CursPos(21, 15); cout << "?"; Sleep(10);
	CursPos(22, 13); cout << "p"; Sleep(10);

	Sleep(500);
choice:
	/* Pobranie wyboru od u¿ytkownika */
	CursPos(2, 19);
	ShowConsoleCursor(1);
	menu_choice = _getch();
	ShowConsoleCursor(0);
	if (menu_choice >= 48 && menu_choice <= 57)
		cout << menu_choice - '0';
	else
		cout << "0";
	Sleep(100);

	switch (menu_choice)
	{
	case 49: Sleep(500);	/* Funkcja zwróci 1, wiêc zacznie siê proces wpisywania sudoku */
		break;	// 1
	case 50: Sleep(500); rules();	/* Wyœwietlenie zasad programu, jego dzia³anie */
		break;	// 2
	case 51: Sleep(500); whatIsSudoku();	/* Wyjaœnienie, czym jest sudoku */
		break;	// 3
	case 52: Sleep(500); system("cls"); Sleep(500); cout << "\n E"; Sleep(10); cout << "x"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "g"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "p"; Sleep(10); cout << "p"; Sleep(10); cout << "."; Sleep(20); cout << "."; Sleep(20); cout << "."; for (int i = 0; i < 2; i++) { CursPos(16, 2); Sleep(800); cout << "   "; CursPos(16, 2); Sleep(200); cout << "."; Sleep(20); cout << "."; Sleep(20); cout << "."; } Sleep(500); exit(0);
		break;	// 4 - tekst "Exiting an app..."
	default: CursPos(2, 21); for (int i = 0; i < 37; i++) cout << " "; Sleep(200); CursPos(2, 21); cout << "S"; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "I"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "'"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "u"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << "."; Sleep(10); cout << " "; Sleep(10); cout << "T"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "g"; Sleep(10); cout << "a"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "."; Sleep(500); CursPos(2, 19); cout << " "; goto choice;
		break;	// inne - tekst "Sorry, I don't understand. Try again."
	}
	return menu_choice - '0';	/* Zwrócenie wartoœci */
}
void Menu::rules()
{
	system("cls"); Sleep(500);
	//	tekst "This app is supposed to solve any kind of sudoku with more than 25 given numbers (relatively advanced ones). Instead of using backtracking, it solves the sudoku the way a human would. This causes problems when given sudoku is too difficult. The reason for that is the algorithm uses the simplest 2 ways - which cell can contain only one number and which number fits only one cell. How to use the app: Choose the 'Solve' option and insert your sudoku by using arrow - keys and numpad - keys. Once you're done, press spacebar."
	cout << "\n T"; Sleep(10); cout << "h"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "p"; Sleep(10); cout << "p"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "p"; Sleep(10); cout << "p"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "f"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << " "; Sleep(10); cout << "m"; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << "5"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "i"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << " "; Sleep(10); cout << "("; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "l"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "d"; Sleep(10); cout << "v"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << ")"; Sleep(10); cout << ".";
	cout << "\n I"; Sleep(10); cout << "n"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "a"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "f"; Sleep(10); cout << " "; Sleep(10); cout << "u"; Sleep(10); cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "g"; Sleep(10); cout << " "; Sleep(10); cout << "b"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "k"; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "k"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "g"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "h"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "l"; Sleep(10); cout << "d"; Sleep(10); cout << "."; Sleep(10); cout << "\n T"; Sleep(10); cout << "h"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "a"; Sleep(10); cout << "u"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "b"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << "m"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "i"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "i"; Sleep(10); cout << "f"; Sleep(10); cout << "f"; Sleep(10); cout << "i"; Sleep(10); cout << "c"; Sleep(10); cout << "u"; Sleep(10); cout << "l"; Sleep(10); cout << "t"; Sleep(10); cout << ".";
	cout << "\n T"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "f"; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "l"; Sleep(10); cout << "g"; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "m"; Sleep(10); cout << " "; Sleep(10); cout << "u"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "m"; Sleep(10); cout << "p"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "a"; Sleep(10); cout << "y"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "-"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "h"; Sleep(10); cout << "i"; Sleep(10); cout << "c"; Sleep(10); cout << "h"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "l"; Sleep(10); cout << "l"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "\n "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "h"; Sleep(10); cout << "i"; Sleep(10); cout << "c"; Sleep(10); cout << "h"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "f"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "l"; Sleep(10); cout << "l"; Sleep(10); cout << ".\n\n";
	Sleep(500); cout << " H"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "u"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "p"; Sleep(10); cout << "p"; Sleep(10); cout << ":"; Sleep(10); cout << " "; Sleep(10); cout << " "; Sleep(300); cout << "C"; Sleep(10); cout << "h"; Sleep(10); cout << "o"; Sleep(10); cout << "o"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "'"; Sleep(10); cout << "S"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "'"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "y"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << "\n b"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "u"; Sleep(10); cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "g"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "r"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << "-"; Sleep(10); cout << "k"; Sleep(10); cout << "e"; Sleep(10); cout << "y"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "p"; Sleep(10); cout << "a"; Sleep(10); cout << "d"; Sleep(10); cout << "-"; Sleep(10); cout << "k"; Sleep(10); cout << "e"; Sleep(10); cout << "y"; Sleep(10); cout << "s"; Sleep(10); cout << "."; Sleep(10); cout << " "; Sleep(500); cout << "O"; Sleep(10); cout << "n"; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "y"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "'"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "p"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "e"; Sleep(10); cout << "b"; Sleep(10); cout << "a"; Sleep(10); cout << "r"; Sleep(10); cout << ".\n\n";

	//	tekst "Note that our program considers a proper sudoku to have only one solution and it has to be solved logically, without guessing."
	Sleep(500);
	cout << " N"; Sleep(10); cout << "o"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "m"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "d"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "u"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n\n "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "l"; Sleep(10); cout << "o"; Sleep(10); cout << "g"; Sleep(10); cout << "i"; Sleep(10); cout << "c"; Sleep(10); cout << "a"; Sleep(10); cout << "l"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "u"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "g"; Sleep(10); cout << ".\n";

	//	tekst "Press any key to continue."
	Sleep(1000);
	cout << "\n\n P"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "e"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "e"; Sleep(10); cout << ". ";
	while (_kbhit())
		_nothing = _getch();
	ShowConsoleCursor(1);
	_nothing = _getch();
}
void Menu::whatIsSudoku()
{
	system("cls"); Sleep(500);
	//	tekst "Sudoku is a logic-based puzzle. The objective is to fill a 9x9 square with numbers from 1 to 9, so that each column, row and 3x3 square contains only one of them(so there are nine 1s, nine 2s and so on)."
	cout << "\n S"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "l"; Sleep(10); cout << "o"; Sleep(10); cout << "g"; Sleep(10); cout << "i"; Sleep(10); cout << "c"; Sleep(10); cout << "-"; Sleep(10); cout << "b"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "u"; Sleep(10); cout << "z"; Sleep(10); cout << "z"; Sleep(10); cout << "l"; Sleep(10); cout << "e"; Sleep(10); cout << "."; Sleep(10); cout << " "; Sleep(10); cout << "T"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "b"; Sleep(10); cout << "j"; Sleep(10); cout << "e"; Sleep(10); cout << "c"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "f"; Sleep(10); cout << "i"; Sleep(10); cout << "l"; Sleep(10); cout << "l"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "9"; Sleep(10); cout << "x"; Sleep(10); cout << "9"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "q"; Sleep(10); cout << "u"; Sleep(10); cout << "a"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "\n w"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "f"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "m"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "9"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "e"; Sleep(10); cout << "a"; Sleep(10); cout << "c"; Sleep(10); cout << "h"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "u"; Sleep(10); cout << "m"; Sleep(10); cout << "n"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "w"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "3"; Sleep(10); cout << "x"; Sleep(10); cout << "3"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "q"; Sleep(10); cout << "u"; Sleep(10); cout << "a"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "a"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "s"; Sleep(10); cout << "\n o"; Sleep(10); cout << "n"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "f"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << "m"; Sleep(10); cout << " "; Sleep(10); cout << "("; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "1"; Sleep(10); cout << "s"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "n"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "2"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << ")"; Sleep(10); cout << ".\n\n";

	//	tekst "Note that our program considers a proper sudoku to have only one solution and it has to be solved logically, without guessing."
	Sleep(500);
	cout << " N"; Sleep(10); cout << "o"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "m"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "d"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "p"; Sleep(10); cout << "e"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "u"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "o"; Sleep(10); cout << "n\n "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "l"; Sleep(10); cout << "o"; Sleep(10); cout << "g"; Sleep(10); cout << "i"; Sleep(10); cout << "c"; Sleep(10); cout << "a"; Sleep(10); cout << "l"; Sleep(10); cout << "l"; Sleep(10); cout << "y"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "w"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "u"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "s"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "g"; Sleep(10); cout << ".\n";

	//	tekst "Press any key to continue."
	Sleep(1000);
	cout << "\n\n P"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "n"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "k"; Sleep(10); cout << "e"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "n"; Sleep(10); cout << "t"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "u"; Sleep(10); cout << "e"; Sleep(10); cout << ". ";
	while (_kbhit())
		_nothing = _getch();
	ShowConsoleCursor(1);
	_nothing = _getch();
}


Sudoku::Sudoku()
{
	reset(sudoku);	/* Wyzerowanie sudoku */
	insertSudoku(sudoku);	/* Wpisanie sudoku przez u¿ytkownika */
	while (!checkSudoku())		/* checkSudoku() sprawdza, czy wprowadzone sudoku jest poprawne, jeœli nie, to u¿tkownik proszony jest o poprawê */
	{
		showSudokuGrid(sudoku);
		//	tekst "Invalid input, try again."
		cout << "\n\n I"; Sleep(10); cout << "n"; Sleep(10); cout << "v"; Sleep(10); cout << "a"; Sleep(10); cout << "l"; Sleep(10); cout << "i"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "p"; Sleep(10); cout << "u"; Sleep(10); cout << "t"; Sleep(10); cout << ","; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "r"; Sleep(10); cout << "y"; Sleep(10); cout << " "; Sleep(10); cout << "a"; Sleep(10); cout << "g"; Sleep(10); cout << "a"; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << ".";
		Sleep(2000);
		insertSudoku(sudoku);
	}
}
void Sudoku::showSudokuGrid(int sudo[9][9])		/* Wyœwietlenie sudoku */
{
	cout << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sudo[i][j] == 10)	/* U¿ywane przy wpisywaniu sudoku */
				cout << " X";
			else
				cout << " " << sudo[i][j];
			if (j == 2 || j == 5)
				cout << " |";
		}
		cout << endl;
		if (i == 2 || i == 5)
			cout << " ---------------------\n";
	}
}
void Sudoku::insertSudoku(int sudo[9][9])		/* Proces wpisywania sudoku przez u¿ytkownika */
{
	system("cls");
	sudoku[0][0] = 10;
	ShowConsoleCursor(0);
	int a{}, x{}, y{}, swap{};
	showSudokuGrid(sudo);
	cout << "\n\n Press spacebar to finish.";
	while (!GetAsyncKeyState(0x20))	// spacja
	{
		if (GetAsyncKeyState(0x25))	// Przesuniêcie X w lewo
		{
			if (y != 0)
			{
				sudo[x][y] = a;		// Wpisanie wartoœci 'a' w pole, na pocz¹tku jest 0
				y--;
				a = sudo[x][y];		// Zapisanie w 'a' wartoœci w kratce po lewej

				sudo[x][y] = 10;	// Zamiana tej wartoœci na 10, w celu wyœwietlenia X
			}
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x26))	// Przesuniêcie X w gorê
		{
			if (x != 0)
			{
				sudo[x][y] = a;
				x--;
				a = sudo[x][y];

				sudo[x][y] = 10;
			}
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x27))	// Przesuniêcie X w prawo
		{
			if (y != 8)
			{
				sudo[x][y] = a;
				y++;
				a = sudo[x][y];

				sudo[x][y] = 10;
			}
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x28))	// Przesuniêcie X w dó³
		{
			if (x != 8)
			{
				sudo[x][y] = a;
				x++;
				a = sudo[x][y];

				sudo[x][y] = 10;
			}
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}

		if (GetAsyncKeyState(0x30) || GetAsyncKeyState(0x60))	// 0
		{
			a = 0;					// Ustawienie wartoœci 'a'
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x31) || GetAsyncKeyState(0x61))	// 1
		{
			a = 1;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x32) || GetAsyncKeyState(0x62))	// 2
		{
			a = 2;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x33) || GetAsyncKeyState(0x63))	// 3
		{
			a = 3;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x34) || GetAsyncKeyState(0x64))	// 4
		{
			a = 4;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x35) || GetAsyncKeyState(0x65))	// 5
		{
			a = 5;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x36) || GetAsyncKeyState(0x66))	// 6
		{
			a = 6;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x37) || GetAsyncKeyState(0x67))	// 7
		{
			a = 7;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x38) || GetAsyncKeyState(0x68))	// 8
		{
			a = 8;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (GetAsyncKeyState(0x39) || GetAsyncKeyState(0x69))	// 9
		{
			a = 9;
			system("cls");
			showSudokuGrid(sudo);
			cout << "\n\n Press spacebar to finish.";
		}
		if (swap == 0)	// Pozbycie siê jednej wartoœci z bufora
		{
			swap++;
			a = 0;
		}
		Sleep(100);
	}
	sudo[x][y] = a;		// Zapisanie kratki, na której by³ X w chwili zakoñczenia
	system("cls");
}
void Sudoku::reset(int sudo[9][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			sudo[i][j] = 0;
}
bool Sudoku::checkSudoku()
{
	for (int k = 1; k < 10; k++)
	{
		int countwhole{};		/* Liczy, ile razy powtórzy³a siê cyfra w ca³ym sudoku */
		for (int i = 0; i < 9; i++)
		{
			int countrow{};		/* Liczy, ile razy powtórzy³a siê cyfra w wierszu */
			int countcol{};		/* Liczy, ile razy powtórzy³a siê cyfra w kolumnie */
			for (int j = 0; j < 9; j++)
				if (sudoku[i][j] == k)
				{
					countwhole++;
					countrow++;
				}
			if (countrow > 1)
				return false;
			for (int j = 0; j < 9; j++)
				if (sudoku[j][i] == k)
					countcol++;
			if (countcol > 1)
				return false;
		}
		if (countwhole > 9)		/* Nie mo¿e byæ wiêcej ni¿ 9 tych samych cyfr */
			return false;
	}

	for (int k = 1; k < 10; k++)
		for (int i = 0; i < 9; i = i + 3)
			for (int j = 0; j < 9; j = j + 3)
			{
				int countsq{};		/* Liczy, ile razy powtórzy³a siê cyfra w ca³ym kwadracie 3x3 */
				for (int x = i; x < i + 3; x++)
					for (int y = j; y < j + 3; y++)
						if (sudoku[x][y] == k)
							countsq++;
				if (countsq > 1)	/* Nie mo¿e byæ wiêcej ni¿ 2 te same cyfry */
					return false;
			}
	return true;
}


Solution::Solution()
{
	showSudokuGrid(sudoku);
	solve(sudoku);

	system("cls");
	Sleep(500);
	if (isSolutionValid())
	{
		showSudokuGrid(sudoku);
		// text "Press ENTER to exit."
		cout << "\n\n P"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "E"; Sleep(10); cout << "N"; Sleep(10); cout << "T"; Sleep(10); cout << "E"; Sleep(10); cout << "R"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "e"; Sleep(10); cout << "x"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << ".";
	}
	else	// tekst "Our program couldn't solve this sudoku. It could be because you have given an invalid sudoku or it is too complicated. Press ENTER to exit."
		cout << "\n O"; Sleep(10); cout << "u"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "p"; Sleep(10); cout << "r"; Sleep(10); cout << "o"; Sleep(10); cout << "g"; Sleep(10); cout << "r"; Sleep(10); cout << "a"; Sleep(10); cout << "m"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "l"; Sleep(10); cout << "d"; Sleep(10); cout << "n"; Sleep(10); cout << "'"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "o"; Sleep(10); cout << "l"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "h"; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << "."; Sleep(10); cout << " "; Sleep(500); cout << "I"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << "l"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "b"; Sleep(10); cout << "e"; Sleep(10); cout << "c"; Sleep(10); cout << "a"; Sleep(10); cout << "u"; Sleep(10); cout << "s"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "y"; Sleep(10); cout << "o"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "h"; Sleep(10); cout << "a"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << " "; Sleep(10); cout << "g"; Sleep(10); cout << "i"; Sleep(10); cout << "v"; Sleep(10); cout << "e"; Sleep(10); cout << "n"; Sleep(10); cout << "\n a"; Sleep(10); cout << "n"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "n"; Sleep(10); cout << "v"; Sleep(10); cout << "a"; Sleep(10); cout << "l"; Sleep(10); cout << "i"; Sleep(10); cout << "d"; Sleep(10); cout << " "; Sleep(10); cout << "s"; Sleep(10); cout << "u"; Sleep(10); cout << "d"; Sleep(10); cout << "o"; Sleep(10); cout << "k"; Sleep(10); cout << "u"; Sleep(10); cout << " "; Sleep(10); cout << "o"; Sleep(10); cout << "r"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << " "; Sleep(10); cout << "i"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "c"; Sleep(10); cout << "o"; Sleep(10); cout << "m"; Sleep(10); cout << "p"; Sleep(10); cout << "l"; Sleep(10); cout << "i"; Sleep(10); cout << "c"; Sleep(10); cout << "a"; Sleep(10); cout << "t"; Sleep(10); cout << "e"; Sleep(10); cout << "d"; Sleep(10); cout << "."; Sleep(500); cout << "\n\n P"; Sleep(10); cout << "r"; Sleep(10); cout << "e"; Sleep(10); cout << "s"; Sleep(10); cout << "s"; Sleep(10); cout << " "; Sleep(10); cout << "E"; Sleep(10); cout << "N"; Sleep(10); cout << "T"; Sleep(10); cout << "E"; Sleep(10); cout << "R"; Sleep(10); cout << " "; Sleep(10); cout << "t"; Sleep(10); cout << "o"; Sleep(10); cout << " "; Sleep(10); cout << "e"; Sleep(10); cout << "x"; Sleep(10); cout << "i"; Sleep(10); cout << "t"; Sleep(10); cout << ".";
	while (true)
		if (GetAsyncKeyState(0x0D))
			exit(0);
}
void Solution::solve(int sudo[9][9])
{
	bool IsSolved = false;
	vector<int> Missing, Fitting, FittingIndex;


	while (IsSolved == false)	/* Jeœli gdzieœ jest 0, sudoku nie jest rozwi¹zane */
	{
		IsSolved = true;
		for (int x = 0; x < 9; x++)		/* Pêtla sprawdza po kolei ka¿d¹ kratkê */
		{
			for (int y = 0; y < 9; y++)
			{
				Missing.clear(); Fitting.clear();
				if (sudoku[x][y] == 0)
				{
					Missing = checkCol(y);	/* Ile jest brakuj¹cych w kolumnie */

					for (int i = 0; i < Missing.size(); i++)
					{

						if (isValid(Missing[i], x, y) == true)	/* Czy pasuje jedna z brakuj¹cych, jeœli tak, zostaje zapisana */
							Fitting.push_back(Missing[i]);

					}
					if (Fitting.size() == 1)	/* Jeœli pasuj¹ca w danej kratce jest tylko 1, to zostaje wpisana */
					{
						sudoku[x][y] = Fitting[0];
						IsSolved = false;
					}
				}
				Missing.clear(); Fitting.clear();
				if (sudoku[x][y] == 0)
				{
					Missing = checkRow(x);		/* Podobnie, z tym, ¿e sprawdza brakuj¹ce w wierszu */

					for (int i = 0; i < Missing.size(); i++)
					{
						if (isValid(Missing[i], x, y) == true)
							Fitting.push_back(Missing[i]);
					}
					if (Fitting.size() == 1)
					{
						sudoku[x][y] = Fitting[0];
						IsSolved = false;
					}
				}
				Missing.clear(); Fitting.clear();
				if (sudoku[x][y] == 0)
				{
					Missing = checkSquare(x, y);	/* Podobnie, z tym, ¿e sprawdza brakuj¹ce w kwadracie 3x3 */

					for (int i = 0; i < Missing.size(); i++)
					{
						if (isValid(Missing[i], x, y) == true)
							Fitting.push_back(Missing[i]);
					}

					if (Fitting.size() == 1)
					{
						sudoku[x][y] = Fitting[0];

						IsSolved = false;
					}
				}

				Missing.clear(); Fitting.clear(); FittingIndex.clear();

				Missing = checkCol(y);	/* Sprawdza brakuj¹ce w kolumnie */

				for (int i = 0; i < Missing.size(); i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (sudoku[j][y] == 0)
						{
							if (isValid(Missing[i], j, y) == true)	/* Dla ka¿dej brakuj¹cej liczby sprawdza, do ilu kratek mo¿na j¹ wpisaæ */
								FittingIndex.push_back(j);			/* Zapisuje, gdzie pasowa³a */
						}
					}
					if (FittingIndex.size() == 1)	/* Jeœli pasuje tylko do 1 kratki, wpisauje j¹ tam */
					{
						if (sudoku[FittingIndex[0]][y] == 0)
						{
							sudoku[FittingIndex[0]][y] = Missing[i];
							IsSolved = false;
						}
					}
				}

				Missing.clear(); Fitting.clear(); FittingIndex.clear();

				Missing = checkRow(x);		/* Podobnie, z tym, ¿e sprawdza brakuj¹ce w wierszu */

				for (int i = 0; i < Missing.size(); i++)
				{
					for (int j = 0; j < 9; j++)
					{
						if (sudoku[x][j] == 0)
						{
							if (isValid(Missing[i], x, j) == true)
								FittingIndex.push_back(j);
						}
					}

					if (FittingIndex.size() == 1)
					{
						if (sudoku[x][FittingIndex[0]] == 0)
						{
							sudoku[x][FittingIndex[0]] = Missing[i];
							IsSolved = false;
						}
					}
				}

				Missing.clear(); Fitting.clear(); FittingIndex.clear();

				Missing = checkSquare(x, y);		/* Podobnie, z tym, ¿e sprawdza brakuj¹ce w kwadracie 3x3 */

				for (int i = 0; i < Missing.size(); i++)
				{
					FittingIndex.clear();
					for (int j = (x / 3) * 3; j < ((x / 3) * 3) + 3; j++)
					{
						for (int k = (y / 3) * 3; k < ((y / 3) * 3) + 3; k++)
						{
							if (sudoku[j][k] == 0)
							{
								if (isValid(Missing[i], j, k) == true)	/* Ró¿nica tu polega na tym, ¿e zapisuj¹ siê dwa koordynaty kratki */
								{
									FittingIndex.push_back(j);
									FittingIndex.push_back(k);
								}
							}
						}
					}

					if (FittingIndex.size() == 2)	/* Rozmiar 2 oznacza jedn¹ kratkê */
					{
						if (sudoku[FittingIndex[0]][FittingIndex[1]] == 0)
						{
							sudoku[FittingIndex[0]][FittingIndex[1]] = Missing[i];
							IsSolved = false;
						}
					}
				}
			}
		}
	}
}
vector<int> Solution::checkCol(int y)		/* Sprawdzenie brakuj¹cych w kolumnie */
{	/* Sprawdza liczby 1-9, jeœli pojawi siê w kolumnie, pomija sprawdza nastêpn¹.
	Jeœli pêtla przejdzie do koñca, wpisuje liczbê, poniewa¿ siê nie pojawi³a */
	vector<int> Missing;
	for (int i = 1; i < 10; i++)
	{
	next:
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[j][y] == i)
			{
				i++;
				goto next;
			}
		}
		if (i != 10)
			Missing.push_back(i);
	}
	return Missing;
}
vector<int> Solution::checkRow(int x)	/* Sprawdzenie brakuj¹cych w wierszu */
{
	vector<int> Missing;
	for (int i = 1; i < 10; i++)
	{
	next:
		for (int j = 0; j < 9; j++)
		{
			if (sudoku[x][j] == i)
			{
				i++;
				goto next;
			}
		}
		if (i != 10)
			Missing.push_back(i);
	}
	return Missing;
}
vector<int> Solution::checkSquare(int x, int y)		/* Sprawdzenie brakuj¹cych w kwadracie 3x3 */
{
	int xx = (x / 3) * 3;
	int yy = (y / 3) * 3;
	vector<int> Missing;
	for (int k = 1; k < 10; k++)
	{
	next:
		for (int i = xx; i < xx + 3; i++)
		{
			for (int j = yy; j < yy + 3; j++)
			{
				if (sudoku[i][j] == k)
				{
					k++;
					goto next;
				}
			}
		}
		if (k != 10)
			Missing.push_back(k);
	}
	return Missing;
}
bool Solution::isValid(int a, int x, int y)
{	/* Sprawdza, czy dana liczba pasuje w danej kratce */
	for (int i = 0; i < 9; i++)
		if (sudoku[i][y] == a)
			return false;
	for (int i = 0; i < 9; i++)
		if (sudoku[x][i] == a)
			return false;
	int xx = (x / 3) * 3;
	int yy = (y / 3) * 3;
	for (int i = xx; i < xx + 3; i++)
		for (int j = yy; j < yy + 3; j++)
			if (sudoku[i][j] == a)
				return false;
	return true;
}
bool Solution::isSolutionValid()
{	/* Jeœli gdzieœ w sudoku jest 0, zróci fa³sz */
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (sudoku[i][j] == 0)
				return false;
	return true;
}

