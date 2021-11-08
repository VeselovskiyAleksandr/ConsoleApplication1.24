// ConsoleApplication1.24.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//Урок 21. Задача 3.Реализация математического вектора. 

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct vect {
	float x, y;
};
vect vect1, vect2;

void add(vect vect1,vect vect2) {
	cout << "Enter the beginning of the first vector";
	cin >> vect1.x;
	cout << "Enter the end of the first vector";
	cin >> vect1.y;
	cout << "Enter the beginning of the second vector";
	cin >> vect2.x;
	cout << "Enter the end of the second vector";
	cin >> vect2.y;
	cout << "The sum vector has coordinates: (" << vect1.x + vect2.x << ";" << vect1.y + vect2.y << ")\n";
}

void subtract(vect vect1, vect vect2) {
	cout << "Enter the beginning of the first vector";
	cin >> vect1.x;
	cout << "Enter the end of the first vector";
	cin >> vect1.y;
	cout << "Enter the beginning of the second vector";
	cin >> vect2.x;
	cout << "Enter the end of the second vector";
	cin >> vect2.y;
	cout<<"The difference vector: vector2- vector1, has coordinates: (" << vect2.x + vect1.x << ";" << vect2.y + vect1.y << ")\n";
}

void scale(vect vect1) {
	float k;
	cout << "\nEnter the scale: ";
	cin >> k;
	cout << "Enter the beginning of the  vector";
	cin >> vect1.x;
	cout << "Enter the end of the  vector";
	cin >> vect1.y;
	cout << "\nMultiplying the vector by the scalar has coordinates: ";
	cout << "(" << k * vect1.x << ";" << k * vect1.y << ")";
}

float length(vect vect1) {
	float length;
	cout << "Enter the beginning of the  vector";
	cin >> vect1.x;
	cout << "Enter the end of the  vector";
	cin >> vect1.y;
	length = sqrt(vect1.x * vect1.x + vect1.y * vect1.y);
	cout << "\nThe length of the vector is " << length;
	return length;
}

void normalize(vect vect1) {
	float length;
	cout << "Enter the beginning of the  vector";
	cin>> vect1.x;
	cout << "Enter the end of the  vector";
	cin >> vect1.y;
	length = sqrt(vect1.x * vect1.x + vect1.y * vect1.y);
//	cout << "\nThe length of the vector " << length;
	cout << "\nCoordinates of the normalized vector: ";
	cout << "\nX=" << vect1.x / length << "\n";
	cout << "Y=" << vect1.y / length;
}

int main()
{
	int n;
	cout << "\n                 The program for performing action with vectors.";
	cout << "\n For addition of vectors enter 1";
	cout << "\n For subtracting of vectors enter 2";
	cout << "\n For multiplying a vector by a scalar enter 3";	
	cout << "\n For finding the length of the vector  enter 4";
    cout << "\n Normalization of the vector enter 5";
	cout << "\nSelect an action.";
	cin >> n;
	if (n == 1) {

		add(vect1, vect2);
	}
	else if(n==2){
		subtract(vect1, vect2);
	}
	else if (n == 3) {
		scale(vect1);
	}
	else if (n == 4) {
		length(vect1);
	}
	else if (n == 5) {
		normalize(vect1);
	}
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
