#pragma once
#include""
void show_game(ushort game[][4]) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++) {
			if (game[i][j] == 16) SetConsoleTextAttribute(h, 0);
			else if (IsRightPosition(game, cordinate{ ushort(i),ushort(j) }))SetConsoleTextAttribute(h, 10);
			else SetConsoleTextAttribute(h, 4);
			cout << setw(5) << game[i][j];
		}
		cout << '\n' << '\n';
	}
	SetConsoleTextAttribute(h, 0);
