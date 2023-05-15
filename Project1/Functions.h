#pragma once
#include"data.h"
#include"Header.h"
#include"helperfile.h"

void fill_game(ushort game[][4]) {
	ushort c = 1;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++) {
			game[i][j] = c;
			c++;
		}

	}

}


void move_Cell(ushort game_field[][4], int side) {
	cord = findemptyCell(game_field);

	switch (side)
	{
	case LEFT:
	case 75:
	case 'A':
		if (cord.y + 1 <= 3) {
			swap(game_field[cord.x][cord.y], game_field[cord.x][cord.y + 1]);
		}
		break;

	case RIGHT:
	case 77:
	case 'D':
		if (cord.y - 1 >= 0) {
			swap(game_field[cord.x][cord.y], game_field[cord.x][cord.y - 1]);
		}
		break;

	case UP:
	case 72:
	case 'W':
		if (cord.x + 1 <= 3) {
			swap(game_field[cord.x][cord.y], game_field[cord.x + 1][cord.y]);
		}
		break;

	case DOWN:
	case 80:
	case 'S':
		if (cord.x - 1 >= 0) {
			swap(game_field[cord.x][cord.y], game_field[cord.x - 1][cord.y]);
		}
		break;
	}
	save(game_field);
}


void startPosition(ushort game_field[][4], levels level) {
	unsigned int random_side{};
	int sides[]{ LEFT, RIGHT, UP, DOWN };
	for (size_t i = 0; i < level; i++)
	{
		random_side = rand() % 4;
		move_Cell(game_field, sides[random_side]);
	}

}


bool isWIN(ushort game_field[][4]) {
	ushort cell_value = 1;
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (cell_value++ != game_field[i][j])return false;
		}
	}
	return true;
}


ushort menu(const char* Menu[], ushort length) {
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	unsigned char key{};
	short menuPos = 0;

	while (true)
	{
		menuPos %= length;
		if (menuPos < 0) menuPos = length - 1;
		for (size_t i = 0; i < length; i++)
		{
			SetConsoleTextAttribute(h, 79);
			if (i == menuPos) {
				SetConsoleTextAttribute(h, 240);
				cout << ">>" <<Menu[i] << "<<" << endl;
			}
			else
			{
				cout << "  " << Menu[i] << "  " << endl;
			}


		}
		SetConsoleTextAttribute(h, 0);
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else {
			if (key == 13)
			{
				return menuPos + 1;
			}
		}
		switch (key)
		{
		case UP:
			menuPos--;
			break;
		case DOWN:
			menuPos++;
			break;
		}
		system("cls");
	}
}


void show(ushort c) {

	if (c == 1) cout << "LEVEL : EASY\n" << endl;
	else if (c == 2) cout << "LEVEL : MEDIUM\n" << endl;
	else if (c == 3) cout << "LEVEL : HARD\n" << endl;
}


void game(ushort game_field[][4], ushort c) {
	unsigned char arrow{};
	while (!isWIN(game_field))
	{

		arrow = _getch();

		system("cls");
		SetConsoleTextAttribute(h, 15);
		show(c);

		move_Cell(game_field, arrow);
		show_game(game_field);

	}
}


void StartShow() {
	short i = 0;
	while (true)
	{

		cout << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl << endl;
		cout << "                        111     5555555            GGGGGGG      AAA        MM      MM      EEEEEEE" << endl;
		cout << "                        111     55                 GG         AA   AA      M M    M M      EE     " << endl;
		cout << "                        111     5555555            GG  GGG    AAAAAAA      M   MMM  M      EEEEEEE" << endl;
		cout << "                        111          55            GG   GG    AA   AA      M    M   M      EE     " << endl;
		cout << "                        111     5555555            GGGGGGG    AA   AA      M        M      EEEEEEE" << endl << endl;
		cout << "\t\t\t\t\t\tLOANDING..." << endl;
		cout << "\t\t\t\t\t   ";
		while (i < 20)
		{
			Sleep(420);
			cout << (char)220 << "";
			i++;
		}
		system("cls");
		break;
		i++;
	}

}