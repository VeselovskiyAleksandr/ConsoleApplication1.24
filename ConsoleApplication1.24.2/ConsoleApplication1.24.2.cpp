// ConsoleApplication1.24.2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 21. Задача 2. Модель данных для посёлка.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>


using namespace std;

struct room {
	string roomType;
	string roomSquare;
	
};
struct floors {
	string  quantityRooms;
	string ceillingHeight;

	struct room rooms;
};


struct cottage {
	string stove;
	string  quantityFloor;
	

	struct floors houseFloor;
};

struct village {
	
	string square, quantityBuilding;
	string garage, barn, bathhouse;

	struct cottage privateCottage;
};




int main()
{

	village plotLand;
	cottage privateCottage;
	floors houseFloor1;
	floors houseFloor2;
	room rooms1;
	room rooms2;
	room rooms3;
	room rooms4;
vector < village> plotLands;
	string str, st, s;
	vector <floors> houseFloors;
	vector <room> chamber;
	fstream file("C:\\Users\\Александр\\Documents\\text for program\\village.txt", ios::app);
	if (file.is_open()) {
		cout << "\nThe accounting statement is open for recording.";
	}
	else {
		cerr << "\nThe file is not found. ";
		return 1;
	}
	int action = 0;
	cout << "\nTo make entry, enter 1; to read the contents enter 2";
	cin >> action;
	if (action == 1) {
		ofstream file("C:\\Users\\Александр\\Documents\\text for program\\village.txt", ios::app);
	
		int counter = 0;
		cout << "\nEnter the number of objects.";
		cin >> counter;
		for (int i = 0; i < counter; i++) {
			cout << "\nEnter the square of  plotLand: ";
			cin >>plotLand.square;
			cout << "\n:Enter the number of facility ";
			cin >> plotLand.quantityBuilding;
			cout << "\nSpecify whether there is a garage on the plotLand: ";
			cin >> plotLand.garage;
			cout << "\n:Specify whether there is a barn on the plotLand ";
			cin >> plotLand.barn;
			cout << "\n:Specify whether there is a bathhouse on the plotLand ";
			cin >> plotLand.bathhouse;

			cout << "\nSpecify whether there is a stove in the house:";
			cin>> plotLand.privateCottage.stove;
			cout << "\nSpecify the number of floors: ";
			cin >> plotLand.privateCottage.quantityFloor;
             str= plotLand.privateCottage.quantityFloor;

		//	int countF= plotLand.privateCottage.quantityFloor;
         int countF = stoi(str);
		
			for (int j = 0; j < countF; j++) {
				
			cout << "\nspecify the number of rooms on the floor: ";
	          cin>> plotLand.privateCottage.houseFloor.quantityRooms;
		//cout<< houseFloor.quantityRooms;
				st= plotLand.privateCottage.houseFloor.quantityRooms;
			//	int countR= plotLand.privateCottage.houseFloor.quantityRooms;
				int countR =stoi(st);
		
				for (int k = 0; k < countR; k++){
					cout << "\nspecify the type of rooms: ";
              cin>> plotLand.privateCottage.houseFloor.rooms.roomType;
		//	  cout << houseFloor[j].rooms.roomType;
			  plotLands.push_back(plotLand);
		
			//  chamber.push_back(rooms);
          //   str= plotLand.privateCottage.houseFloor.rooms.roomType;
           
					cout << "\nspecify the area of the room: ";
				cin >> plotLand.privateCottage.houseFloor.rooms.roomSquare;
					
				chamber.push_back(rooms[k]);
				

			//	cout<< chamber[k].roomType<<" ";
				}
houseFloors.push_back(houseFloor1);



				
			}
plotLands.push_back(plotLand);
		}
		
		
		for (int i = 0; i < plotLands.size(); i++) {
		
			file << plotLands[i].square << " " << plotLands[i].quantityBuilding << " " << plotLands[i].garage << " " << plotLands[i].barn;
	//		file <<" "<< plotLands[i].bathhouse<<" "<< plotLand[i].privateCottage.stove; 
			for (int j = 0; j < houseFloors.size(); j++) {
				file<< houseFloors[j].quantityRooms<<" "<< houseFloors[j].ceillingHeight<<"\n";
				for (int k = 0; k < chamber.size(); k++) {
					file << chamber[k].roomType << " " << chamber[k].roomSquare << "\n";
				}
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
