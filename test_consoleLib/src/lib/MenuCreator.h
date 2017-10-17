/*
 * MenuCreator.h
 *
 *  Created on: 29 may. 2017
 *      Author: dani
 */

#ifndef LIB_MENUCREATOR_H_
#define LIB_MENUCREATOR_H_

#include <vector>
#include <iostream>

#include "Console.h"

namespace BlackLibrary {

using namespace std;

class MenuItem{
public:
	MenuItem(short ident,string item_name);
	virtual ~MenuItem();
private:
	string _item_name;
	short _ident;
};


class MenuCreator {
public:
	vector<string> itemList;
	Console console;
	string title;
	ColorFont title_color;
	ColorFont menu_color;
	char icon='=';

	unsigned int x;
	unsigned int y;

	MenuCreator();
	virtual ~MenuCreator();

	size_t GetLength();

	void WriteLine(size_t frame_long,string msg);

	void DrawLine(unsigned int frame_long);

	void Add(string item_name);

	void Show();
};

} /* namespace BlackLibrary */

#endif /* LIB_MENUCREATOR_H_ */
