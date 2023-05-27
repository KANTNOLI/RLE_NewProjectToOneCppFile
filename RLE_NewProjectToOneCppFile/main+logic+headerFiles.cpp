#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

string output_choose_language(int point) {
	string msg = "";

	switch (point)
	{
	case 0: msg += "Введите размер изображение по координатам X: "; break;
	case 1: msg += "Введите размер изображение по координатам Y: "; break;
	case 2: msg += "Введите данные изображения (w / b): "; break;
	case 3: msg += "преобразование в RLE: \n"; break;
	case 4: msg += "Ошибка ввода!!! Возможно вы перепутали координаты!"; break;

	case 5: msg += "Choose language (Key 1 - Russian; Others - English): \nВыберете язык (Клавиша 1 - Русский; Другие - Английский): "; break;

	case 10: msg += "Input size picture coordinate X: "; break;
	case 11: msg += "Input size picture coordinate Y: "; break;
	case 12: msg += "Input your picture(w / b): "; break;
	case 13: msg += "Converting to RLE: \n"; break;
	case 14: msg += "Input error!!! Perhaps you mixed up the coordinates!"; break;
	}

	return msg;
}

string converting_to_zip(string convert, int sizex, int sizey, bool choose_language) {
	char w = 'w', b = ' b';
	int count = 1, count2 = 1;
	char char1, char2;
	bool flag = true;
	string msg = "";
	int all_size = sizex * sizey;

	for (int i = 0; i < all_size; i++)
	{
		char1 = convert[i];
		char2 = convert[i + 1];


		if (char1 != w and char1 != b)
		{
			int point = choose_language ? 4 : 14;
			return output_choose_language(point);
		}

		if (char1 == char2)
		{
			count++;
		}
		else if (count != 1) {
			msg += to_string(count);
			msg += char1;
			flag = false;
			count = 1;
		}
		else {
			msg += char1;
			flag = false;
			count = 1;
		}


		if (count2 == sizex)
		{
			if (sizex - count < sizex and count > 2)
			{

				msg += to_string(count - 1);
				msg += char1;
			}
			else if (flag) {
				msg += char1;
				count = 1;
			}
			msg += "\n";
			count = 1;
			count2 = 0;
		}
		flag = true;
		count2++;
	}

	return msg;
}

int main() {
	string convetirng_string, string;
	int sizex, sizey, point = 0;
	bool choose_language;
	setlocale(LC_ALL, "RUS");
	cout << output_choose_language(5) << endl;
	choose_language = _getch() == '1';
	system("cls");

	point = choose_language ? 0 : 10;
	cout << output_choose_language(point);
	cin >> sizex;
	point = choose_language ? 1: 11;
	cout << output_choose_language(point);
	cin >> sizey;
	getchar();

	point = choose_language ? 2 : 12;
	cout << output_choose_language(point) << endl;
	for (int i = 0; i < sizey; i++)
	{
		getline(cin, string);
		convetirng_string += string;
	}

	system("cls");
	point = choose_language ? 3 : 13;
	cout << output_choose_language(point) << converting_to_zip(convetirng_string, sizex, sizey, choose_language);

	return 0;
}