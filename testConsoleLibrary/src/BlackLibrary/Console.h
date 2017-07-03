/*
 * Console.h
 *
 *  Created on: 29 may. 2017
 *      Author: dani
 */

#ifndef CONSOLE_H_
#define CONSOLE_H_

#include <iostream>

namespace BlackLibrary {

enum ColorFont{
	black=30,
	red=31,
	blue=34,
	grey=90,
	lightred=91,
	white=97
};

enum BackgroundColor
{
	fondo_rojo=41,
	fondo_verde=42,
	fondo_amarillo=43,
	fondo_azul=44,
	fondo_magenta=45,
	fondo_cyan=46,
	fondo_gris=47,
	fondo_gris_oscuro=100,
	fondo_rojo_claro=101,
	fondo_verde_claro=102,
	fondo_amarillo_claro=103,
	fondo_azul_claro=104,
	fondo_magenta_claro=105,
	fondo_cyan_claro=106,
	fondo_blanco=107,
	fondo_defecto=49
};


class Console {
public:

	Console();

	virtual ~Console();

	void WriteLine(std::string msg);

	void SetBackgroundColor(BackgroundColor color);

	void SetColor(ColorFont color);

	void UnSetColor();

	int Getch(void);

	void Clean();

	void GotoXY(int x,int y);

};

} /* namespace BlackLibrary */

#endif /* CONSOLE_H_ */
