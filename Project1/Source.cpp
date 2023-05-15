#include"data.h"
#include"helperfile.h"
#include"Functions.h"
#include"Header.h"
#include"UI.h"


int main() {
	StartShow();


	srand(time(NULL));
	h = GetStdHandle(STD_OUTPUT_HANDLE);

	short c{ 2 };
	ushort game_field[4][4]{};
	ushort menuItem = 0;


	const char* startMenu[] = {
	"Start game",
	"Load game ",
	"   Exit   "
	};

	const char* levelMenu[] = {
	" Easy ",
	"Medium",
	" Hard "
	};


	menuItem = menu(startMenu, 3);


	switch (menuItem)
	{
	case 1:
		cout << "\t\t\tWELCOME" << endl;
		system("cls");
		menuItem = menu(levelMenu, 3);
		fill_game(game_field);
		c = menuItem;
		startPosition(game_field, levelArray[menuItem - 1]);
		break;
	case 2:
		load(game_field);
		break;
	case 3:
		SetConsoleTextAttribute(h, 15);
		return 0;
	}

	system("cls");


	SetConsoleTextAttribute(h, 15);
	show(c);


	show_game(game_field);

	game(game_field, c);
	 
	Winanymation();


}