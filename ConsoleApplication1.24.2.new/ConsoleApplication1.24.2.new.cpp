// ConsoleApplication1.24.2.new.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 21. Задача 2. Модель данных для посёлка.


#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct room {
	enum rooms { SLEEPING, LIVING, DINING, CHILDREN, OFFICE, LIBRARY, LAUNDRY, WORKROOM, GUEST };
	float roomSquare[9];
};
room chamber[12];

struct floors {
	int  quantityRooms;
	float ceillingHeight;
	struct room chamber;
	vector <int>  nameR;
};
floors houseFloor[3];

struct village {
	string namePlot;
	float square;
	int quantityBuilding;
	enum bilding { COTTAGE, STOVECOT, GARAGE, BARN, BATHHOUSE, STOVEBATH };
	int quantityFloor;
	struct floors houseFloor[3];
	vector <string> plotLands;
	vector <int> state;
};
village plotLand[10];

void  record_individualHousingConstruction() {
	string name[] = { "sleeping", "living", "dining", "children", "office", "librory", "laundry", "workroom", "guest" };
	string outbuilding[] = { "cottage", "stovecot", "garage", "barn", "bathhouse", "stovebath" };
	string str0 = ".";
	string str1 = "\nPlot area (Sq m): ";
	string str2 = "\nNumber of buildings: ";
	string str3 = "\nNames of buildings: ";
	string str4 = "\nNumber of floors in the house: ";
	string str5 = "\nNumber of rooms per floor: ";
	string str6 = "\nCeiling height on the floor (m): ";
	string str7 = "\nNames of rooms and rooms area (Sq m): ";
	string str8 = "\nFloor ";
	string str9 = "\n\nplotLand # ";
	string  str10[10];
	string str11 = "\nThe area for individual housing construction is (Sq m): ";
	string str = "";
	char whitespace = ' ', semicolon = ';';
	int plot = 0, countC=0, sqPlot = 0, sqR[10], count=0;
	ifstream cfile("village.txt");
	while (!cfile.eof()) {
		cfile >> str;
		if (str.substr(0,8)=="plotLand") {
			count++;	
		}
		str = "";
	}
	cfile.close();
	ofstream file("village.txt", ios::app);
	cout << "\nEnter the number of plotlands.";
	do {
		cin >> plot;
		if (plot+count <= 0 || plot + count > 10) {
			cout << "Enter right the number of plotlands";
		}
	} while (plot + count <= 0 || plot + count > 10);
	for (int i = count; i < plot+count; i++) {
		sqR[i] = 0;
		cout << "\nPlot name: ";
		cout << "\nplotLand #" + to_string(i + 1);
		str10[i] = "\nThe living area of the house #" + to_string(i + 1) + " is (Sq m): ";
		plotLand[i].plotLands.push_back("\nplotLand #" + to_string(i + 1));
		cout << "\nEnter the square of  plotLand: ";
		cin >> plotLand[i].square;
		sqPlot += plotLand[i].square;
		cout << "\nEnter the number of facility ";
		do {
			cin >> plotLand[i].quantityBuilding;
			if (plotLand[i].quantityBuilding <= 0 || plotLand[i].quantityBuilding > 6) {
				cout << "Enter right the number of facility. ";
			}
		} while (plotLand[i].quantityBuilding <= 0 || plotLand[i].quantityBuilding > 6);
		cout << "\nSpecify available buildings on the plotLand (if no, enter 0, if yes, enter any other number): ";
		int status = 0;
		plotLand[i].state.push_back(status);
		plotLand[i].state.push_back(status);
		for (int j = 0; j < 6; j++) {// 6 - количество построек вместе с печью в доме и в бане 
			cout << "\n" << outbuilding[j];
			cin >> status;		
			if (status != 0) {
				if (j == 0) {
					plotLand[i].state[i-count] |= plotLand[i].COTTAGE;
				}
				else if (j == 1) {
					plotLand[i].state[i - count] |= plotLand[i].STOVECOT;
				}
				else if (j == 2) {
					plotLand[i].state[i - count] |= plotLand[i].GARAGE;
				}
				else if (j == 3) {
					plotLand[i].state[i - count+1] |= plotLand[i].BARN;
				}
				else if (j == 4) {
					plotLand[i].state[i - count+1] |= plotLand[i].BATHHOUSE;
				}
				else if (j == 5) {
					plotLand[i].state[i - count+1] |= plotLand[i].STOVEBATH;
				}
			}
		}
		cout << "\nSpecify the number of floors: ";
		do {
			cin >> plotLand[i].quantityFloor;
			if (plotLand[i].quantityFloor <= 0 || plotLand[i].quantityFloor > 3) {
				cout << "Enter right the number of floors: ";
			}
		} while (plotLand[i].quantityFloor <= 0 || plotLand[i].quantityFloor > 3);
		int countF = plotLand[i].quantityFloor;
		for (int j = 0; j < 3 * countF; j++) {    //один этаж обслуживают 3 переменные
			int nameRs = 0;
			houseFloor[j].nameR.push_back(nameRs);
		}
		for (int j = 0; j < countF; j++) {
			cout << "\nFloor " << j + 1 << " specify the number of rooms on the floor: ";
			do {
				cin >> plotLand[i].houseFloor[j].quantityRooms;
				if (plotLand[i].houseFloor[j].quantityRooms <= 0 || plotLand[i].houseFloor[j].quantityRooms > 5) {
					cout << "Enter right the number of rooms.";
				}
			} while (plotLand[i].houseFloor[j].quantityRooms <= 0 || plotLand[i].houseFloor[j].quantityRooms > 5);
			cout << "\nspecify the ceiling height: ";
			cin >> plotLand[i].houseFloor[j].ceillingHeight;
			int countR = plotLand[i].houseFloor[j].quantityRooms;
			cout << "\nspecify the type of rooms(if no, enter 0, if yes, enter any other number):\n";
			int status = 0;
			plotLand[i].houseFloor[j].nameR.push_back(status);
			plotLand[i].houseFloor[j].nameR.push_back(status);
			plotLand[i].houseFloor[j].nameR.push_back(status);
			for (int l = 0; l < 9; l++) {
				cout << name[l];
				cin >> status;  //указывает на наличие или отсутствие комнаты
				if (status != 0) {
					if (l == 0) {
						plotLand[i].houseFloor[j].nameR[countC] |= plotLand[i].houseFloor[j].chamber.SLEEPING;
					}
					else if (l == 1) {
						plotLand[i].houseFloor[j].nameR[countC] |= plotLand[i].houseFloor[j].chamber.LIVING;
					}
					else if (l == 2) {
						plotLand[i].houseFloor[j].nameR[countC] |= plotLand[i].houseFloor[j].chamber.DINING;
					}
					else if (l == 3) {
						plotLand[i].houseFloor[j].nameR[countC+1] |= plotLand[i].houseFloor[j].chamber.CHILDREN;
					}
					else if (l == 4) {
						plotLand[i].houseFloor[j].nameR[countC+1] |= plotLand[i].houseFloor[j].chamber.OFFICE;
					}
					else if (l == 5) {
						plotLand[i].houseFloor[j].nameR[countC+1] |= plotLand[i].houseFloor[j].chamber.LIBRARY;
					}
					else if (l == 6) {
						plotLand[i].houseFloor[j].nameR[countC+2] |= plotLand[i].houseFloor[j].chamber.LAUNDRY;
					}
					else if (l == 7) {
						plotLand[i].houseFloor[j].nameR[countC+2] |= plotLand[i].houseFloor[j].chamber.WORKROOM;
					}
					else if (l == 8) {
						plotLand[i].houseFloor[j].nameR[countC+2] |= plotLand[i].houseFloor[j].chamber.GUEST;
					}
					cout << "\nSpecify the area of the room: ";
					cin >> plotLand[i].houseFloor[j].chamber.roomSquare[l];
					sqR[i] += plotLand[i].houseFloor[j].chamber.roomSquare[l];
				}
			}countC += 3;
		}
		cout << str10[i] << sqR[i] << semicolon;
	}
	cout << str11 << sqPlot << semicolon;
	countC = 0;
	for (int i = count; i < plot+count; i++) {
		file << plotLand[i].plotLands[0] << whitespace << str0 << str1<< plotLand[i].square << whitespace << str0;
		file << str2 << plotLand[i].quantityBuilding << whitespace << str0 << str3;
		if (plotLand[i].state[i - count] & plotLand[i].COTTAGE) {
			file << outbuilding[0] << semicolon << whitespace;
		}
		if (plotLand[i].state[i-count] & plotLand[i].STOVECOT) {
			file << outbuilding[1] << semicolon << whitespace;
		}
		if (plotLand[i].state[i-count] & plotLand[i].GARAGE) {
			file << outbuilding[2] << semicolon << whitespace;
		}
		if (plotLand[i].state[i - count+1] & plotLand[i].BARN) {
			file << outbuilding[3] << semicolon << whitespace;
		}
		if (plotLand[i].state[i - count+1] & plotLand[i].BATHHOUSE) {
			file << outbuilding[4] << semicolon << whitespace;
		}
		if (plotLand[i].state[i - count+1] & plotLand[i].STOVEBATH) {
			file << outbuilding[5] << semicolon << whitespace;
		}
		file << str0 << str4 << plotLand[i].quantityFloor << whitespace << str0;
		for (int j = 0; j < plotLand[i].quantityFloor; j++) {
			int numF = j + 1;
			file << str8 << to_string(numF) << str5 << plotLand[i].houseFloor[j].quantityRooms << whitespace << str0;//numF привёл к str
			file << str6 << plotLand[i].houseFloor[j].ceillingHeight << whitespace << str0;
			file << str7;
			if (plotLand[i].houseFloor[j].nameR[countC] & plotLand[i].houseFloor[j].chamber.SLEEPING) {
				file << name[0] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[0] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC] & plotLand[i].houseFloor[j].chamber.LIVING) {
				file << whitespace << name[1] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[1] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC] & plotLand[i].houseFloor[j].chamber.DINING) {
				file << whitespace << name[2] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[2] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC + 1] & plotLand[i].houseFloor[j].chamber.CHILDREN) {
				file << whitespace << name[3] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[3] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC + 1] & plotLand[i].houseFloor[j].chamber.OFFICE) {
				file << whitespace << name[4] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[4] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC + 1] & plotLand[i].houseFloor[j].chamber.LIBRARY) {
				file << whitespace << name[5] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[5] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC + 2] & plotLand[i].houseFloor[j].chamber.LAUNDRY) {
				file << whitespace << name[6] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[6] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC + 2] & plotLand[i].houseFloor[j].chamber.WORKROOM) {
				file << whitespace << name[7] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[7] << semicolon;
			}
			if (plotLand[i].houseFloor[j].nameR[countC + 2] & plotLand[i].houseFloor[j].chamber.GUEST) {
				file << whitespace << name[8] << whitespace << plotLand[i].houseFloor[j].chamber.roomSquare[8] << semicolon;
			}
			countC += 3;
			file << whitespace << str0;
		}
		file<< str10[i] << sqR[i] << whitespace << str0;
	}
	file << str11 << sqPlot << whitespace << str0;
}

void  load_individualHousingConstruction() {
	string name[] = { "sleeping", "living", "dining", "children", "office", "librory", "laundry", "workroom", "guest" };
	string outbuilding[] = { "cottage", "stovecot", "garage", "barn", "bathhouse", "stovebath" };
	string str0 = ".";
	string str1 = "\nPlot area (Sq m): ";
	string str2 = "\nNumber of buildings: ";
	string str3 = "\nNames of buildings: ";
	string str4 = "\nNumber of floors in the house: ";
	string str5 = "\nNumber of rooms per floor: ";
	string str6 = "\nCeiling height on the floor (m): ";
	string str7 = "\nNames of rooms and rooms area (Sq m): ";
	string str8 = "\nFloor ";
	string str9 = "\n\nplotLand # ";
	string  str10[10], str = "";
	string str11 = "\nThe area for individual housing construction is (Sq m): ";
	string str12 = "\n";
	string nameBuilding = "", nameRoom = "";
	char whitespace = ' ', semicolon = ';';
	int plot = 0, countC[10], countR[10], sqPlot = 0, sqR[10];
	vector <string> state;
	vector <string>  nameR;
	int num = 0;
	ifstream file("village.txt");
	while (!file.eof()) {
		file >> str;
		state.push_back(str);
		str = "";
	}
	for (int i = 0; i < state.size(); i++) {
		cout << state[i] << whitespace;
		if (state[i] == str0) {
			cout << "\n";
		}
	}
}

int main()
{
	fstream file("village.txt", ios::app);
	if (file.is_open()) {
		cout << "\nThe file is open.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 1;
	}
	int action = 0;
	cout << "\nTo make entry, enter 1; to read the contents enter 2";
	cin >> action;
	if (action == 1) {
		record_individualHousingConstruction();
	}
	else if (action == 2) {
		load_individualHousingConstruction();
	}
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
