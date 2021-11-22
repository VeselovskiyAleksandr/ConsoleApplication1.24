// ConsoleApplication1.24.2.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 21. Задача 2. Модель данных для посёлка.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct room {
	enum rooms { SLEEPING = 1, LIVING = 2, DINING = 4, CHILDREN = 8, OFFICE = 16, LIBRARY = 32, LAUNDRY = 64, WORKROOM = 132, GUEST = 264 };
	float roomSquare = 0;
};
room chamber[5];

struct floors {
	int  quantityRooms = 0;
	float ceillingHeight = 0;
	struct room chamber;
	//vector <room> rooms;
};
floors houseFloor[3];

struct village {
	float square = 0;
	string namePlot;
	int quantityBuilding = 0;
	enum bilding { COTTAGE = 1, STOVECOT = 2, GARAGE = 4, BARN = 8, BATHHOUSE = 16, STOVEBATH = 32 };
	float quantityFloor = 0;
	struct floors houseFloor[3];
};
village plotLand[1];

int main()
{
	string name[] = { "sleeping", "living", "dining", "children", "office", "librory", "laundry", "workroom", "guest" };
	string outbuilding[] = { "cottage", "stovecot", "garage", "barn", "bathhouse", "stovebath" };
	int state = 0, plot = 0, action = 0;
	vector <int>  nameR;
	vector < village> plotLands;
	fstream file("C:\\Users\\Александр\\Documents\\text for program\\village.txt", ios::app);
	if (file.is_open()) {
		cout << "\nThe accounting statement is open for recording.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 1;
	}
	cout << "\nEnter the number of plotlend.";
	cin >> plot;
	cout << "\nTo make entry, enter 1; to read the contents enter 2";
	cin >> action;
	if (action == 1) {
		ofstream file("C:\\Users\\Александр\\Documents\\text for program\\village.txt", ios::app);
		for (int i = 0; i < plot; i++) {
			cout << "\nPlot name: ";
			cout << "\nplotLand #" + to_string(i + 1);
			plotLand[i].namePlot = "plotLand #" + to_string(i + 1);
			cout << "\nEnter the square of  plotLand: ";
			cin >> plotLand[i].square;
			cout << "\nEnter the number of facility ";
			cin >> plotLand[i].quantityBuilding;
			plotLands.push_back(plotLand[i]);
			cout << "\nSpecify available buildings on the plotLand (if no, enter 0, if yes, enter any other number): ";

			for (int j = 0; j < plotLand[i].quantityBuilding + 2; j++) {//к количеству построек прибавляем печи в доме и бане.
				int status = 0;
				cout << "\n" << outbuilding[j];
				cin >> status;
				if (status != 0) {
					if (j == 0) {
						state |= plotLand[i].COTTAGE;
					}
					else if (j == 1) {
						state |= plotLand[i].STOVECOT;
					}
					else if (j == 2) {
						state |= plotLand[i].GARAGE;
					}
					else if (j == 3) {
						state |= plotLand[i].BARN;
					}
					else if (j == 4) {
						state |= plotLand[i].BATHHOUSE;
					}
					else if (j == 5) {
						state |= plotLand[i].STOVEBATH;
					}
					plotLands.push_back(plotLand[i]);
				}
				else {};
			}

			cout << "\nSpecify the number of floors: ";
			cin >> plotLand[i].quantityFloor;
			int countF = plotLand[i].quantityFloor;

			for (int j = 0; j < countF; j++) {
				int nameRs = 0;
				nameR.push_back(nameRs);

			}
			for (int j = 0; j < countF; j++) {

				cout << nameR[j] << "! ";

			}
			for (int j = 0; j < countF; j++) {

				cout << "\nFloor " << j + 1 << " specify the number of rooms on the floor: ";
				cin >> plotLand[i].houseFloor[j].quantityRooms;
				plotLands.push_back(plotLand[i]);
				int countR = plotLand[i].houseFloor[j].quantityRooms;
				cout << "\nspecify the type of rooms(if no, enter 0, if yes, enter any other number):\n";
				int status = 0;
				for (int l = 0; l < 9; l++) {
					cout << name[l];
					cin >> status;
					if (status != 0) {
						if (l == 0) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.SLEEPING;

						}
						else if (l == 1) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.LIVING;

						}
						else if (l == 2) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.DINING;

						}
						else if (l == 3) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.CHILDREN;

						}
						else if (l == 4) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.OFFICE;

						}
						else if (l == 5) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.LIBRARY;
						}
						else if (l == 6) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.LAUNDRY;
						}
						else if (l == 7) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.WORKROOM;
						}
						else if (l == 8) {
							nameR[j] |= plotLand[i].houseFloor[j].chamber.GUEST;
						}
						cout << "\nspecify the area of the room: ";
						cin >> plotLand[i].houseFloor[j].chamber.roomSquare;
					}
					else {};
				}
				plotLands.push_back(plotLand[i]);
			}
			plotLands.push_back(plotLand[i]);
		}
		//if (nameR[j] |= plotLand[0].houseFloor[0].chamber.LIVING) {
			//		cout <<  "(yes )";
				//		}
		  //if (nameR[j] |= plotLand[0].houseFloor[1].chamber.LIBRARY) {
			// cout << "yes ";
		// }
		for (int i = 0; i < plot; i++) {
			file << plotLands[i].namePlot << "\n" << plotLands[i].square << " " << plotLands[i].quantityBuilding << ":\n ";

			if (state & plotLand[i].COTTAGE) {
				file << outbuilding[0] << " ";
			}
			if (state & plotLand[i].STOVECOT) {
				file << outbuilding[1] << " ";
			}
			if (state & plotLand[i].GARAGE) {
				file << outbuilding[2] << " ";
			}
			if (state & plotLand[i].BARN) {
				file << outbuilding[3] << " ";
			}
			if (state & plotLand[i].BATHHOUSE) {
				file << outbuilding[4] << " ";
			}
			if (state & plotLand[i].STOVEBATH) {
				file << outbuilding[5] << " ";
			}

			file << "\n" << plotLand[i].quantityFloor << " ";
			for (int j = 0; j < plotLand[i].quantityFloor; j++) {
				cout << plotLand[i].houseFloor[j].chamber.SLEEPING << " ";
			}
			for (int j = 0; j < plotLand[i].quantityFloor; j++) {
				file << "\nFloor " << j + 1 << plotLand[i].houseFloor[j].quantityRooms << " ";
				//	for (int l = 0; l < 9; l++) {
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.SLEEPING) {
					file << name[0] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.LIVING) {
					file << name[1] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.DINING) {
					file << name[2] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.CHILDREN) {
					file << name[3] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.OFFICE) {
					file << name[4] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.LIBRARY) {
					file << name[5] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.LAUNDRY) {
					file << name[6] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.WORKROOM) {
					file << name[7] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				if (nameR[j] & plotLand[i].houseFloor[j].chamber.GUEST) {
					file << name[8] << " " << plotLand[i].houseFloor[j].chamber.roomSquare;
				}
				//}
			}
		}
	}
	else if (action == 2) {
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
