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
	cout << " ������� 1 - ��� ����� \n������� 2 - ��� ������ \n������� 3 - ��� ����\n������� 4 - �����\n��� �����:> ";
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
			cout << " \n������� ��������" << endl;
			material = writeWord();
			cout << endl;
			cout << "������� ����" << endl;
			cost = writeNumbers();
			cout << endl;
			cout << "������� ����" << endl;
			color = writeWord();
			cout << endl;
			cout << "������� ���" << endl;
			sex = writeWord();
			cout << endl;
			int ch;
			cout << "������� ������" << endl;
			ch = writeNumbers();
			cout << endl;
			string s;
			cout << "������� �����: " << endl;
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
			cout << "\n������� ��������" << endl;
			material = writeWord();
			cout << endl;
			cout << "������� ����" << endl;
			cost = writeNumbers();
			cout << endl;
			cout << "������� ����" << endl;
			color = writeWord();
			cout << endl;
			cout << "������� ���" << endl;
			sex = writeWord();
			cout << endl;
			int ch, width;
			string m;
			cout << "������� ��� �������������: " << endl;
			m = writeWord();
			cout << endl;
			cout << "������� ������: " << endl;
			ch = writeNumbers();
			cout << endl;
			cout << "������� ������" << endl;
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
			cout << " \n������� ��������" << endl;
			material = writeWord();
			cout << endl;
			cout << " ������� ����" << endl;
			cost = writeNumbers();
			cout << endl;
			cout << " ������� ����" << endl;
			color = writeWord();
			cout << endl;
			cout << " ������� ���" << endl;
			sex = writeWord();
			cout << endl;

			string t, a;
			cout << " ������� �����: " << endl;
			t = writeWord();
			cout << endl;
			cout << " ������� ������: " << endl;
			a = writeWord();
			cout << endl;
			HAT = new Hat(cost, material, color, sex, a, t);
			HAT->show();
			break;
		}
		case 4:
			return 0;
		default:
			cout << endl << "������! �������� ��������" << endl;
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
	cout << "��������: " << this->material << endl << "����: " << this->color << endl << "����: " << this->cost<<endl << "���: " << this->sex << endl;;
}
void Shoes::show()
{
	Clothes::show();
	cout << "������: " << this->size << endl << "�����: " << this->firm << endl;
}

void Trousers::show()
{
	cout << "��� �������������: " << this->vidIspolzovaniya << endl << "������: " << this->width<<endl << "������: " << this->height << endl;
	Clothes::show();
}

void Hat::show()
{
	cout << "�����: " << this->model << endl << "������: " << this->season << endl;
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
