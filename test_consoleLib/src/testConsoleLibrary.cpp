//============================================================================
// Name        : testConsoleLibrary.cpp
// Author      : Daniel
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>

#include "lib/Console.h"
#include "lib/MenuCreator.h"

using namespace std;


int main() {

	BlackLibrary::Console cons;
	BlackLibrary::MenuCreator menu;
	menu.x=10;
	menu.y=10;
	menu.title_color=BlackLibrary::red;
	menu.menu_color=BlackLibrary::blue;

	menu.title="Menu prueba";
	menu.Add("unoasdft");
	menu.Add("dos");

	menu.Show();

	return 0;
}
