// ConsoleApplication1.24.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 21. Задача 1. Реализация ведомости учёта

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct statement {
  string name, family, date, payouts;
};

void save_statement(fstream file, statement person) {
	
}

int main() {
	int action = 0, counter = 0;
	statement person;
	
//	fstream file("C:\\Users\\Александр\\Documents\\text for program\\payment statement. bin", ios::binary);

//	if (file.is_open()) {
	//	cout << "\nThe accounting statement is open for recording.";
	//}
	//else {
	//	cerr << "\nThe file is not found. ";
	//	return 1;
//	}
	cout << "To make entry, enter 1; to read the contents enter 2";
	cin >> action;
	if (action == 1) {
		int counter = 0;
ofstream file("C:\\Users\\Александр\\Documents\\text for program\\payment statement.bin", ios::binary | ios::app);
	if (file.is_open()) {
				cout << "\nThe accounting statement is open for recording.";
			}
			else {
				cerr << "\nThe file is not found. ";

			}
		cout << "Specify the numder of objects to enter";
		cin >> counter;
		for (int i = 0; i < counter; i++) {
			string pName, pFamily;
			string pDate, pPayouts;
			
		
			cout << "Enter the name of person.";
			cin >> pName;
			person.name = pName;
			cout << "Enter second name.";
			cin >> pFamily;
			person.family = pFamily;
			cout << "Enter date of payments";
			cin >> pDate;
			person.date = pDate;
			cout << "Enter sum of payments";
			cin >> pPayouts;
			person.payouts = pPayouts;
			int lenn = person.name.length();
			int lenf = person.family.length();

			file.write((char*)&lenn, sizeof(lenn));
			file.write((char*)&lenf, sizeof(lenf));
			file.write(person.name.c_str(), lenn);
			file.write(person.family.c_str(), lenf);
			file.write((char*)&person.date, sizeof(person.date));
			file.write((char*)&person.payouts, sizeof(person.payouts));
			cout << person.name << " " << person.family << " " << person.date << " " << person.payouts << "\n";
		}
		file.close();
	}
	
	else if (action == 2) {
ifstream file("C:\\Users\\Александр\\Documents\\text for program\\payment statement.bin",ios::binary);
		if (file.is_open()) {
			cout << "\nThe accounting statement is open for reading.\n";
		}
		else {
			cerr << "\nThe file is not found. ";
			return 1;
		}
		vector <statement> persons;
		int count = 0;
		while (!file.eof()) {	
			int lenn;
			int lenf;		
			file.read((char*)&lenn, sizeof(lenn));
			person.name.resize(lenn);
			file.read((char*)&lenf, sizeof(lenf));			
			person.family.resize(lenf);
			file.read((char*)person.name.c_str(), lenn);	
			file.read((char*)person.family.c_str(), lenf);		
			file.read((char*)&person.date, sizeof(person.date));
			file.read((char*)&person.payouts, sizeof(person.payouts));
			persons.push_back(person);
			count++;
		}//file.close();
		for (int i = 0; i < count-1; i++) {
			cout << persons[i].name << " " << persons[i].family << " " << persons[i].date << " " << persons[i].payouts << "\n";
		}
		file.close();
	 }
//	file.close();
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
