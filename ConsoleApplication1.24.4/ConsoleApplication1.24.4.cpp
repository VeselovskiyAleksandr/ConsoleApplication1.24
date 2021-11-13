// ConsoleApplication1.24.4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 21. Задача 4. Реализация ролевой пошаговой игры.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h> 
#include <time.h>
using namespace std;

struct enemy {
	string appellation;
	int health=0, armor=0, damage=0;
	int x = 0, y = 0;
};
enemy foe[5];

struct player {
	string name;
	int health =0, armor=0, damage=0;
	int x = 0, y = 0;
};
player bettor;

struct battles{
	struct player bettor;
	struct enemy foe[5];
};
battles wildWorld;

void takeDamageEn(enemy& person, int damage) {
	person.armor -= damage;
	if (person.armor < 0) {
		person.health += person.armor;
		person.armor = 0;
	}
}

void takeDamagePl(player&character, int damage) {
	character.armor -= damage;
	if (character.armor < 0) {
		character.health += character.armor;
		character.armor = 0;
	}
}

void save_battle(ofstream& file, battles& wildWorld) {
	int lenP = wildWorld. bettor.name.length();
	file.write((char*)&lenP, sizeof(lenP));
	file.write((char*)wildWorld.bettor.name.c_str(), lenP);
	file.write((char*)&wildWorld.bettor.health, sizeof(wildWorld.bettor.health));
	file.write((char*)&wildWorld.bettor.armor, sizeof(wildWorld.bettor.armor));
	file.write((char*)&wildWorld.bettor.damage, sizeof(wildWorld.bettor.damage));
	file.write((char*)&wildWorld.bettor.x, sizeof(wildWorld.bettor.x));
	file.write((char*)&wildWorld.bettor.y, sizeof(wildWorld.bettor.y));
	int lenEn[5];
	for (int i = 0; i < 5; i++) {
		lenEn[i] = wildWorld.foe[i].appellation.length();
		file.write((char*)& lenEn[i], sizeof(lenEn[i]));
		file.write((char*)wildWorld.foe[i].appellation.c_str(), lenEn[i]);
		file.write((char*)&wildWorld.foe[i].health, sizeof(wildWorld.foe[i].health));
		file.write((char*)&wildWorld.foe[i].armor, sizeof(wildWorld.foe[i].armor));
		file.write((char*)&wildWorld.foe[i].damage, sizeof(wildWorld.foe[i].damage));
		file.write((char*)&wildWorld.foe[i].x, sizeof(wildWorld.foe[i].x));
		file.write((char*)&wildWorld.foe[i].y, sizeof(wildWorld.foe[i].y));		
	}
}

  void load_battle(ifstream& file, battles &wildWorld) {
		int lenP= wildWorld.bettor .name.length();
		file.read((char*)&lenP, sizeof(lenP));
		wildWorld.bettor.name.resize(lenP);
		file.read((char*)wildWorld.bettor.name.c_str(), lenP);
		file.read((char*)&wildWorld.bettor.health, sizeof(wildWorld.bettor.health));
		file.read((char*)&wildWorld.bettor.armor, sizeof(wildWorld.bettor.armor));
		file.read((char*)&wildWorld.bettor.damage, sizeof(wildWorld.bettor.damage));
		file.read((char*)&wildWorld.bettor.x, sizeof(wildWorld.bettor.x));
		file.read((char*)&wildWorld.bettor.y, sizeof(wildWorld.bettor.y));
		int lenEn[5];
		for (int i = 0; i < 5; i++) {
			file.read((char*)&lenEn[i], sizeof(lenEn[i]));
			wildWorld.foe[i].appellation.resize(lenEn[i]);
			file.read((char*)wildWorld.foe[i].appellation.c_str(), lenEn[i]);
			file.read((char*)&wildWorld.foe[i].health, sizeof(wildWorld.foe[i].health));
			file.read((char*)&wildWorld.foe[i].armor, sizeof(wildWorld.foe[i].armor));
			file.read((char*)&wildWorld.foe[i].damage, sizeof(wildWorld.foe[i].damage));
			file.read((char*)&wildWorld.foe[i].x, sizeof(wildWorld.foe[i].x));
			file.read((char*)&wildWorld.foe[i].y, sizeof(wildWorld.foe[i].y));			
	}
}
int main()
{
	enemy foe[5];
	player bettor;
	int counter = 0, play = 1;
	srand(time(NULL));
	 ifstream file("C:\\Users\\Александр\\Documents\\text for program\\battle", ios::binary);
	int start = 0;
	cout << "To start a new game put 1, to continue - put 2";
	cin >> start;
	if (start == 1) {
		wildWorld.bettor.name = "Mighty Beer";
		wildWorld.bettor.health = 150;
		wildWorld.bettor.armor = 100;
		wildWorld.bettor.damage = 30;
		wildWorld.bettor.x = rand() % 39;
		wildWorld.bettor.y = rand() % 39;
	for (int i = 0; i < 5; i++) {
		wildWorld.foe[i].appellation = "foe #" + to_string(i + 1);
		wildWorld.foe[i].health = rand() % 100 + 50;
		wildWorld.foe[i].armor = rand() % 50;
		wildWorld.foe[i].damage = rand() % 15 + 15;
		wildWorld.foe[i].x = rand() % 39;
		wildWorld.foe[i].y = rand() % 39;
	}
}
	else if (start == 2) { 
		
		 load_battle( file, wildWorld);
	}
	do {

		cout << "\n                      The wild world of nature\n";
		for (int i = 0; i < 40; i++) {
			for (int j = 0; j < 40; j++) {			
				if (wildWorld.bettor.x == j && wildWorld.bettor.y == i) {
					cout << "B";			
						j++;				
				}
				if (j > 39) {
					break;
				}
				for (int k = 0; k < 5; k++) {
					if (wildWorld.foe[k].x == j && wildWorld.foe[k].y == i&& wildWorld.foe[k].health>0) {
						cout << k + 1;
							j++;
					}
				}
				if (j > 39) {
					break;
				}
               cout << ".";
			}
			cout << "\n";
		}
	cout << "\n To exit the game put 0, to continue - put any other number.";
		cin >> play;
		if (play == 0) {
			ofstream file("C:\\Users\\Александр\\Documents\\text for program\\battle", ios::binary);
			 save_battle( file, wildWorld);
			file.close();
			break;
		}
		else {
		}
		char ch = 'a';
		bool rightMove;
		do {
	         rightMove = true;
			cout << "\nMake a move (left - enter l, right - enter r, bottom - enter b, top - enter t)";
			cin >> ch;
			if (ch == 'l' && wildWorld.bettor.x > 0) {
				wildWorld.bettor.x -= 1;
			}
			else if (ch == 'r' && wildWorld.bettor.x < 39) {
				wildWorld.bettor.x += 1;
			}
			else if (ch == 'b' && wildWorld.bettor.y < 39) {
				wildWorld.bettor.y += 1;
			}
			else if (ch == 't' && wildWorld.bettor.y > 0) {
				wildWorld.bettor.y -= 1;
			}
			else  {
				cout << "\nMake a right move.";
				rightMove = false;
			}
		} while (rightMove != true);
		for (int i = 0; i < 5; i++) {
			if (wildWorld.bettor.x == wildWorld.foe[i].x && wildWorld.bettor.y == wildWorld.foe[i].y) {
				takeDamageEn(wildWorld.foe[i], wildWorld.bettor.damage);
				if (wildWorld.foe[i].health > 0 && ch == 'l') {
					wildWorld.bettor.x += 1;
				}
				else if(wildWorld.foe[i].health > 0 && ch == 'r') {
					wildWorld.bettor.x -= 1;
				}
				 else if (wildWorld.foe[i].health>0&&ch == 'b') {
					wildWorld.bettor.y -= 1;
				}
				 else if (wildWorld.foe[i].health > 0 && ch == 't') {
					wildWorld.bettor.y += 1;
				}
			}
			else if (wildWorld.foe[i].health <= 0) {
				cout << "\n" << wildWorld.foe[i].appellation << " is destroyed";
				counter++;
			}
		}
		if (counter == 5) {
			cout << "\n	Mighty Beer won the victory!";
			break;
		}
		for (int i = 0; i < 5; i++) {
			int dir = rand() % 4;
			if (dir == 0 && wildWorld.foe[i].x > 0) {
				wildWorld.foe[i].x -= 1;
			}
			else if (dir == 1 && wildWorld.foe[i].y > 0) {
				wildWorld.foe[i].y -= 1;
			}
			else if (dir == 2 && wildWorld.foe[i].x < 39) {
				wildWorld.foe[i].x += 1;
			}
			else if (dir == 3 && wildWorld.foe[i].y < 39) {
				wildWorld.foe[i].y += 1;
			}
			if (wildWorld.foe[i].x == wildWorld.bettor.x && wildWorld.foe[i].y == wildWorld.bettor.y) {
				takeDamagePl(wildWorld.bettor, wildWorld.foe[i].damage);
				if (wildWorld.bettor.health > 0&& wildWorld.foe[i].x<39) {
					wildWorld.foe[i].x += 1;
				}
				else if (wildWorld.bettor.health > 0 && wildWorld.foe[i].x == 39) {
					wildWorld.foe[i].x -= 1;
				}
				else if (wildWorld.bettor.health <= 0) {
					cout << "\n" << wildWorld.bettor.name << " was destroyed.";
					break;
				}
			}
		}
		cout << "\n" << wildWorld.bettor.name << " " << "coordinates: " << "(" << wildWorld.bettor.x << "," ;
		cout<< wildWorld.bettor.y << ")" << "   health: " << wildWorld.bettor.health << " " << "  armor: " << wildWorld.bettor.armor;
		for (int i = 0; i < 5; i++) {
			cout << "\n     " << wildWorld.foe[i].appellation << " " << "coordinates: " << "(" << wildWorld.foe[i].x << "," ;
			cout<< wildWorld.foe[i].y << ")" << "   health: " << wildWorld.foe[i].health << " " << "  armor: " << wildWorld.foe[i].armor;
		}	
	} while (true);
	file.close();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
