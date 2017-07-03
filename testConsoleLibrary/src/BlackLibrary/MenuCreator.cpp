/*
 * MenuCreator.cpp
 *
 *  Created on: 29 may. 2017
 *      Author: dani
 */

#include "MenuCreator.h"

namespace BlackLibrary {

MenuItem::MenuItem(short ident,string item_name):
		_ident(ident),
		_item_name(item_name)
{

}



MenuCreator::MenuCreator() {
	// TODO Auto-generated constructor stub
	title = "";
	x = 0;
	y = 0;
}

MenuCreator::~MenuCreator() {
	// TODO Auto-generated destructor stub
}

void MenuCreator::Add(string item_name) {
	itemList.push_back(item_name);
}

size_t MenuCreator::GetLength() {
	unsigned int lng = 0;

	for (vector<string>::iterator it = itemList.begin(); it != itemList.end();
			++it) {

		unsigned int lng_tmp;

		string tmp = *it;
		lng_tmp = tmp.length();

		if (lng_tmp > lng) {
			lng = lng_tmp;
		}

	}

	return lng;
}

void MenuCreator::DrawLine(unsigned int frame_long) {
	for (int i = 0; i < (frame_long + 10); i++) {
		cout << '=';
	}

	cout << endl;
}

void MenuCreator::WriteLine(size_t frame_long,string msg) {

	size_t txt_lng=msg.length();
	unsigned int excesed=0;
	unsigned int frame_tmp=frame_long+5;

	if(frame_tmp>txt_lng)
	{
		excesed=frame_tmp-txt_lng;
	}

	cout << "||  ";
	cout << msg;
	for (unsigned int i=0;i<excesed;i++)
	{
		cout <<" ";
	}
	cout << "||" << endl;
}

void MenuCreator::Show() {

	int i;
	char value = 0;
	unsigned int x = this->x;
	unsigned int y = this->y;
short prom_postion_x=0;
short prom_postion_y=0;
	size_t text_long = GetLength();

	do {
		console.Clean();
		console.GotoXY(x, y);
		DrawLine(text_long);
		y++;
		console.GotoXY(x, y);
		console.SetColor(title_color);
		WriteLine(text_long,title);
		console.UnSetColor();
		y++;
		console.GotoXY(x, y);
		DrawLine(text_long);

		console.SetColor(menu_color);
		i = 1;
		for (vector<string>::iterator it = itemList.begin();
				it != itemList.end(); ++it) {
			console.GotoXY(x, y + i);
			WriteLine(text_long,*it);
			//cout << "   " << i << "-";
			//cout << *it << endl;
			i++;
		}
		console.GotoXY(x, y + i);
		WriteLine(text_long,"option:");
		prom_postion_x=x;
		prom_postion_y=y+i;
		y++;
		console.GotoXY(x, y + i);
		DrawLine(text_long);
		//value = console.Getch();
		console.GotoXY(prom_postion_x, prom_postion_y);
		cin >> value;

	} while (value != 'x');
	console.UnSetColor();

}

} /* namespace BlackLibrary */
