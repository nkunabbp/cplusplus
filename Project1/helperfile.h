#pragma once
#pragma once
#pragma once
#include"data.h"


bool isRightPosition(ushort game_field[][4], cordinate coord) {
	return game_field[coord.x][coord.y] == coord.x * 4 + coord.y + 1;
}


cordinate findemptyCell(ushort game[][4]) {
	for (ushort i = 0; i < 4; i++)
	{
		for (ushort j = 0; j < 4; j++) {

			if (game[i][j] == 16)
			{
				return cordinate{ i, j };
			}


		}
	}
}


void Winanymation() {
	system("cls");
	int tmp{ 0 };
	while (tmp < 10)
	{
		for (size_t i = 1; i <= 15; i++)
		{
			Sleep(200);
			system("cls");
			SetConsoleTextAttribute(h, i);
			cout << "!!YOU WIN!!" << endl;
		}
            Beep(330, 100); Sleep(100);
            Beep(330, 100); Sleep(300);
            Beep(330, 100); Sleep(300);
            Beep(262, 100); Sleep(100);
            Beep(330, 100); Sleep(300);
            Beep(392, 100); Sleep(700);
            Beep(196, 100); Sleep(700);
            Beep(262, 300); Sleep(300);
            Beep(196, 300); Sleep(300);
            Beep(164, 300); Sleep(300);
            Beep(220, 300); Sleep(100);
            Beep(246, 100); Sleep(300);
            Beep(233, 200);


	}

}