#include<iostream>
#include<windows.h>
#include<vector>
#include<conio.h>
#include<string>

using std::cout;
using std::endl;
using std::vector;

class Menu
{
public:
	int _nothing;
	Menu();
	void ShowConsoleCursor(bool), CursPos(int, int), SetConsoleSize(), SetFontSize(), CenterConsole();
	void loading(), sudoku_solver_txt(bool), rules(), whatIsSudoku();
	int menu();
};


class Sudoku : Menu
{
public:
	int sudoku[9][9];

	Sudoku();
	void reset(int[9][9]), showSudokuGrid(int[9][9]), insertSudoku(int[9][9]);
	bool checkSudoku();
};


class Solution : Sudoku
{
public:
	Solution();
	void solve(int[9][9]);
	vector<int> checkCol(int), checkRow(int), checkSquare(int, int);
	bool isValid(int, int, int);
	bool isSolutionValid();
};
