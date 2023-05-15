#pragma once
#include <iostream>
#include<iomanip>
#include<conio.h>
#include<time.h>
#include<Windows.h>

HANDLE h;

FILE* file;

using namespace std;


typedef unsigned short ushort;


enum controller { LEFT = 'a', RIGHT = 'd', UP = 'w', DOWN = 's' };


struct cordinate {
	ushort x : 3;
	ushort y : 3;

} cord;


enum levels
{
	EASY = 100,
	NORMAL = 250,
	HARD = 700
};


const levels levelArray[3]{ EASY, NORMAL, HARD };