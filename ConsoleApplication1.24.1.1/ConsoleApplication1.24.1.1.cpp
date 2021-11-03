// ConsoleApplication1.24.1.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Реализация ведомости учёта. Текстовый файл.

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

struct statement {
	string name, family, date, payouts;
};

void save_statement() {
	    statement person;
		ofstream file("C:\\Users\\Александр\\Documents\\text for program\\payment statement.txt", ios::app);
		vector < statement> persons;
		int counter = 0;
		cout << "Specify the numder of objects to enter";
		cin >> counter;
		for (int i = 0; i < counter; i++) {          
			cout << "Enter the name of person.";
			cin >> person.name;			
			cout << "Enter second name.";
			cin >> person.family;			
			cout << "Enter date of payments";
			cin >> person.date;			
			cout << "Enter sum of payments";
			cin >> person.payouts;
			persons.push_back(person);
		}
		for (int i = 0; i < persons.size(); i++) {
			file << persons[i].name << " " << persons[i].family << " " << persons[i].date << " " << persons[i].payouts << "\n";
		}
	
}

void load_statement() {
         statement person;	
	    ifstream file("C:\\Users\\Александр\\Documents\\text for program\\payment statement.txt");
		vector < statement> persons;	
		int count = 0;
		while (!file.eof()) {			
			file >> person.name >> person.family >> person.date >> person.payouts;	
			persons.push_back(person); 
			count++;
            }
		cout << "\n";
		for (int i = 0; i < count-1; i++) {
			cout<< persons[i].name << " " << persons[i].family << " " << persons[i].date << " " << persons[i].payouts << "\n";
		}
		file.close();
}

int main()
{
fstream file("C:\\Users\\Александр\\Documents\\text for program\\payment statement.txt", ios::app);
if (file.is_open()) {
			cout << "\nThe accounting statement is open for recording.";
		}
		else {
			cerr << "\nThe file is not found. ";
			return 1;
		}
int action = 0;
	cout << "To make entry, enter 1; to read the contents enter 2";
	cin >> action;
	if (action == 1) {
		save_statement();
	}
	else if (action == 2) {		
		load_statement();
	}
	file.close();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
