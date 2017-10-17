/*
 * Console.cpp
 *
 *  Created on: 29 may. 2017
 *      Author: dani
 */

#include "Console.h"

#include <iostream>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
#include <stdio.h>


namespace BlackLibrary {

Console::Console() {
	// TODO Auto-generated constructor stub

}

Console::~Console() {
	// TODO Auto-generated destructor stub
}

void Console::WriteLine(std::string msg)
{
	std::cout << msg << std::endl;
}

void Console::SetColor(ColorFont color)
{
	std::string color_form="\033["+std::to_string(color)+"m";

	//color_form=color_form+texto;

	//color_form=color_form+"\033[0m";

	std::cout << color_form;
}

void Console::SetBackgroundColor(BackgroundColor color)
{
	std::string color_form="\033["+std::to_string(color)+"m";

	//color_form=color_form+texto;

	//color_form=color_form+"\033[0m";

	std::cout << color_form;
}

void Console::UnSetColor()
{
	//std::string color_form="\033["+std::to_string(color)+"m";

	//color_form=color_form+texto;

	std::string color_form="\033[0m";

	std::cout << color_form;
}

void Console::Clean()
{
	system("clear"); //clears the screen
}

void Console::GotoXY(int x,int y)
 {
 printf("%c[%d;%df",0x1B,y,x);
 }


int Console::Getch(void)
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

} /* namespace BlackLibrary */
