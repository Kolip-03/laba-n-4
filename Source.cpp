#include <iomanip>
#include <iostream>
#include<Windows.h>
#include <conio.h>
#include <string>

using namespace std;

void showMenu();
int mainMenu();
int writeNumbers();
string writeWord();



class Clothes
{
private:
	int cost;
	string material;
	string color;
	string sex;
public:
	Clothes()
	{
	};
	Clothes(int cost, string material, string color, string sex);
	void show();
};

class Shoes :public Clothes
{
private:
	int size;
	string firm;
public:
	Shoes(int cost, string material, string color, string sex, int size, string firm);
	void show();
};

class Trousers :public Clothes
{
private:
	string vidIspolzovaniya;
	int height;
	int width;
public:
	Trousers(int cost, string material, string color, string sex, string vidIspolzovaniya, int height, int width);
	void show();
};

class Hat :public Clothes
{
private:
	string season;
	string model;
public:
	Hat(int cost, string material, string color, string sex, string season, string model);
	void show();
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(0, "");
	
	mainMenu();
	return 0;
}

void showMenu()
{
	cout << " Нажмите 1 - для обуви \nНажмите 2 - для штанов \nНажмите 3 - для шляп\nНажмите 4 - выход\nВаш выбор:> ";
}

int mainMenu()
{
	Shoes* Size = NULL;
	Trousers* Shtan = NULL;
	Hat* HAT = NULL;

	int choice;
	while (true)
	{
		showMenu();
		choice = writeNumbers();
		switch (choice)
		{
		case 1:
		{
			string material, color, sex;
			int cost;
			cout << " \nВведите материал" << endl;
			material = writeWord();
			cout << endl;
			cout << "Введите цену" << endl;
			cost = writeNumbers();
			cout << endl;
			cout << "Введите цвет" << endl;
			color = writeWord();
			cout << endl;
			cout << "Введите пол" << endl;
			sex = writeWord();
			cout << endl;
			int ch;
			cout << "Введите размер" << endl;
			ch = writeNumbers();
			cout << endl;
			string s;
			cout << "Введите фирму: " << endl;
			s = writeWord();
			cout << endl;
			Size = new Shoes(cost, material, color, sex, ch, s);
			Size->show();
			break;
		}
		case 2:
		{
			string material, color, sex;
			int cost;
			cout << "\nВведите материал" << endl;
			material = writeWord();
			cout << endl;
			cout << "Введите цену" << endl;
			cost = writeNumbers();
			cout << endl;
			cout << "Введите цвет" << endl;
			color = writeWord();
			cout << endl;
			cout << "Введите пол" << endl;
			sex = writeWord();
			cout << endl;
			int ch, width;
			string m;
			cout << "Введите вид использования: " << endl;
			m = writeWord();
			cout << endl;
			cout << "Введите длинну: " << endl;
			ch = writeNumbers();
			cout << endl;
			cout << "Введите ширину" << endl;
			width = writeNumbers();
			cout << endl;
			Shtan = new Trousers(cost, material, color, sex, m, ch, width);
			Shtan->show();
			break;
		}
		case 3:
		{
			string material, color, sex;
			int cost;
			cout << " \nВведите материал" << endl;
			material = writeWord();
			cout << endl;
			cout << " Введите цену" << endl;
			cost = writeNumbers();
			cout << endl;
			cout << " Введите цвет" << endl;
			color = writeWord();
			cout << endl;
			cout << " Введите пол" << endl;
			sex = writeWord();
			cout << endl;

			string t, a;
			cout << " Введите сезон: " << endl;
			t = writeWord();
			cout << endl;
			cout << " Введите модель: " << endl;
			a = writeWord();
			cout << endl;
			HAT = new Hat(cost, material, color, sex, a, t);
			HAT->show();
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "Ошибка! Неверное действие" << endl;
		}
	}
	if (Size != NULL) delete Size;
	if (Shtan != NULL) delete Shtan;
	if (HAT != NULL) delete HAT;
}

Clothes::Clothes(int cost, string material, string color, string sex)
{
	this->cost = cost;
	this->material = material;
	this->color = color;
	this->sex = sex;
}

Shoes::Shoes(int cost, string material, string color, string sex, int size, string firm)
{
	this->Clothes::Clothes(cost, material, color, sex);
	this->size = size;
	this->firm = firm;
}

Trousers::Trousers(int cost, string material, string color, string sex, string vidIspolzovaniya, int height, int width)
{
	this->Clothes::Clothes(cost, material, color, sex);
	this->vidIspolzovaniya = vidIspolzovaniya;
	this->height = height;
	this->width = width;
}

Hat::Hat(int cost, string material, string color, string sex, string season, string model)
{
	this->Clothes::Clothes(cost, material, color, sex);
	this->season = season;
	this->model = model;
}

void Clothes::show()
{
	cout << "Материал: " << this->material << endl << "Цвет: " << this->color << endl << "Цена: " << this->cost<<endl << "Пол: " << this->sex << endl;;
}
void Shoes::show()
{
	Clothes::show();
	cout << "Размер: " << this->size << endl << "Фирма: " << this->firm << endl;
}

void Trousers::show()
{
	cout << "Вид использования: " << this->vidIspolzovaniya << endl << "Ширина: " << this->width<<endl << "Длинна: " << this->height << endl;
	Clothes::show();
}

void Hat::show()
{
	cout << "Сезон: " << this->model << endl << "Модель: " << this->season << endl;
	Clothes::show();
}

int writeNumbers()
{
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

string writeWord()
{
	string slovo;
	while (true) {
		int Knopka;
		char sumbol;
		Knopka = _getch();
		if (Knopka == 224) {
			Knopka = _getch();
		}
		else
			if (Knopka == 8) {
				if (slovo.length() != 0) {
					cout << '\b' << " " << '\b';
					slovo.erase(slovo.length() - 1);
				}
			}
			else
				if (Knopka == 13) {
					break;
				}
				else {
					sumbol = (char)Knopka;
					if ((sumbol >= 'a' && sumbol <= 'z') || (sumbol >= 'A' && sumbol <= 'Z')) {
						slovo = slovo + sumbol;
						cout << sumbol;
					}
				}
	}
	return slovo;
}
