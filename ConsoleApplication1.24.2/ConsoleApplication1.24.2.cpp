// ConsoleApplication1.24.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 21. Задача 2. Модель данных для посёлка!

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#define str0  ".";
#define str1  "\nPlot area (Sq m): "
#define str2  "\nNumber of buildings: "
#define str3  "\nNames of buildings: "
#define str4  "\nNumber of floors in the house: "
#define str5  "\nNumber of rooms per floor: "
#define str6  "\nCeiling height on the floor (m): "
#define str7  "\nNames of rooms and rooms area (Sq m): "
#define str8  "\nFloor "
#define str9  "\n\nplotLand # "
#define str11  "\nThe area for individual housing construction is (Sq m): "
#define whitespace " "
#define semicolon ";"
using namespace std;

struct room {
	string roomType;
	float roomSquare;
};
room chamber[9];

struct floors {
	int  quantityRooms;
	float ceillingHeight;
	struct room chamber[9];
	vector<room>roomS;
};
floors houseFloor[3];

struct outbuildings {
	vector<string> nameBuilding;
};
outbuildings  outbuildingsType[10];

struct village {
	string namePlot;
	float square;
	int quantityBuilding;
	string nameBuilding;
	int quantityFloor;
	struct floors houseFloor[3];
	struct outbuildings  outbuildingsType[6];
	int sqR;
	vector<floors>floor;
};
village plotLand[10];  

void  record_individualHousingConstruction() {
	string name[] = { "sleeping", "living", "dining", "children", "office", "librory", "laundry", "workroom", "guest" };
	string outbuilding[] = { "cottage", "stovecot", "garage", "barn", "bathhouse", "stovebath" };
    string  str10[10];
    string str = "";
	int plot = 0, sqPlot = 0,  count = 0;
	ifstream cfile("village.txt");
	while (!cfile.eof()) {
		cfile >> str;
		if (str.substr(0, 8) == "plotLand") {
			count++;
		}
		str = "";
	}
	cfile.close();
	ofstream file("village.txt", ios::app);
	cout << "\nEnter the number of plotlands.";
	do {
		cin >> plot;
		if (plot + count <= 0 || plot + count > 10) {
			cout << "Enter right the number of plotlands";
		}
	} while (plot + count <= 0 || plot + count > 10);
	for (int i = count; i < plot + count; i++) {
		cout << "\nPlot name: ";
		cout << "\nplotLand #" + to_string(i + 1);
		str10[i] = "\nThe living area of the house #" + to_string(i + 1) + " is (Sq m): ";
		plotLand[i].namePlot= "\nplotLand #" + to_string(i + 1);
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
		int status = 0, countBuilding=0;
		while (countBuilding != plotLand[i].quantityBuilding) {
			for (int j = 0; j < 6; j++) {// 6 - количество построек вместе с печью в доме и в бане 
				cout << "\n" << outbuilding[j];
				cin >> status;
				if (status != 0) {
					if (j == 0) {
						plotLand[i].outbuildingsType[i].nameBuilding.push_back(outbuilding[j]);
						countBuilding++;
					}
					else if (j == 1) {
						plotLand[i].nameBuilding = outbuilding[j];
						plotLand[i].outbuildingsType[i].nameBuilding.push_back(outbuilding[j]);
						countBuilding++;
					}
					else if (j == 2) {
						plotLand[i].nameBuilding = outbuilding[j];
						plotLand[i].outbuildingsType[i].nameBuilding.push_back(outbuilding[j]);
						countBuilding++;
					}
					else if (j == 3) {
						plotLand[i].nameBuilding = outbuilding[j];
						plotLand[i].outbuildingsType[i].nameBuilding.push_back(outbuilding[j]);
						countBuilding++;
					}
					else if (j == 4) {
						plotLand[i].nameBuilding = outbuilding[j];
						plotLand[i].outbuildingsType[i].nameBuilding.push_back(outbuilding[j]);
						countBuilding++;
					}
					else if (j == 5) {
						plotLand[i].nameBuilding = outbuilding[j];
						plotLand[i].outbuildingsType[i].nameBuilding.push_back(outbuilding[j]);
						countBuilding++;
					}
				}
			}
			if (countBuilding > plotLand[i].quantityBuilding) {
				cout << "\nError: quantity building > "<< plotLand[i].quantityBuilding<<". Restart the program.";
			}
			else if (countBuilding > plotLand[i].quantityBuilding) {
				cout << "\nQuantity building > " << plotLand[i].quantityBuilding << ". Enter building name.";
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
		for (int j = 0; j < countF; j++) {
			cout << "\nFloor " << j + 1 << " specify the number of rooms on the floor: ";
			do {
				cin >> plotLand[i].houseFloor[j].quantityRooms;
				if (plotLand[i].houseFloor[j].quantityRooms <= 0 || plotLand[i].houseFloor[j].quantityRooms > 9) {
					cout << "Enter right the number of rooms.";
				}
			} while (plotLand[i].houseFloor[j].quantityRooms <= 0 || plotLand[i].houseFloor[j].quantityRooms > 9);
			cout << "\nspecify the ceiling height: ";
			cin >> plotLand[i].houseFloor[j].ceillingHeight;
			cout << "\nspecify the type of rooms(if no, enter 0, if yes, enter any other number):\n";
			int status = 0;
			int countRoom = 0;
			while(countRoom != plotLand[i].houseFloor[j].quantityRooms) {
				for (int l = 0; l < 9; l++) {
					cout << name[l];
					cin >> status;  //указывает на наличие или отсутствие комнаты
					if (status != 0) {
						if (l == 0) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin>> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 1) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >>  plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 2) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 3) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 4) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 5) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 6) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 7) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						else if (l == 8) {
							plotLand[i].houseFloor[j].chamber[countRoom].roomType = name[l];
							cout << "\nSpecify the area of the room: ";
							cin >> plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].sqR += plotLand[i].houseFloor[j].chamber[countRoom].roomSquare;
							plotLand[i].houseFloor[j].roomS.push_back(chamber[countRoom]);
							countRoom++;
						}
						if (countRoom > plotLand[i].houseFloor[j].quantityRooms) {
							cout << "\nError: countRoom >9. Restart the program.";
						}
					}
				}
		   }
		} 
		cout << str10[i] << plotLand[i].sqR << semicolon;
	}
	cout << str11;
	cout<< sqPlot << semicolon;
	for (int i = count; i < plot + count; i++) {
		file << plotLand[i].namePlot << whitespace;
		file << str0;
		file<< str1;
		file<< plotLand[i].square << whitespace << str0;
		file << str2 << plotLand[i].quantityBuilding << whitespace << str0;
		file<< str3;
		file << "\n ";
		for (int l = 0; l < plotLand[i].outbuildingsType[i].nameBuilding.size(); l++) {
			file << plotLand[i].outbuildingsType[i].nameBuilding[l] << " ";
		}
		file << str0;
		file<< str4 << plotLand[i].quantityFloor << whitespace << str0;
		for (int j = 0; j < plotLand[i].quantityFloor; j++) {
			int numF = j + 1;
			file << str8 << to_string(numF) << str5 << plotLand[i].houseFloor[j].quantityRooms << whitespace << str0;//numF привёл к str
			file << str6 << plotLand[i].houseFloor[j].ceillingHeight << whitespace << str0;
			file << str7;
			for(int k=0;k< plotLand[i].houseFloor[j].quantityRooms;k++){
				file << plotLand[i].houseFloor[j].chamber[k].roomType << whitespace;
				file<< plotLand[i].houseFloor[j].chamber[k].roomSquare << semicolon;
			}
			file << whitespace << str0;
		}
		file << str10[i] << plotLand[i].sqR << whitespace << str0;
        file<<"\n";
	}
	 file << str11 <<sqPlot << whitespace << str0;
}

void  load_individualHousingConstruction() {
	string name[] = { "sleeping", "living", "dining", "children", "office", "librory", "laundry", "workroom", "guest" };
	string outbuilding[] = { "cottage", "stovecot", "garage", "barn", "bathhouse", "stovebath" };
    string  str = "";
    vector <string> state;
	ifstream file("village.txt");
	while (!file.eof()) {
		file >> str;
		state.push_back(str);
		str = "";
	}
	for (int i = 0; i < state.size(); i++) {
		cout << state[i] << whitespace;
		string s = str0;
		if (state[i] == s) {
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
