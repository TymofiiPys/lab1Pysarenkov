#include <iostream>
#include "Header.h"
#include <Windows.h>
//#include "doctest.h"

void matrEntry() {
	mtr::mtr m;
	std::cout << "Оберіть спосіб зчитування додаткової матриці:\n";
	std::cout << "0 - випадкова генерація\n";
	std::cout << "1 - введення вручну\n";
	std::cout << "2 - зчитування з файлу\n";
	int op1;
	std::cin >> op1;
	int eltype = 0;
	switch (op1) {
	case 0:
		std::cout << "Оберіть тип елементів матриці:\n";
		std::cout << "0 - цілі числа\n";
		std::cout << "1 - дійсні числа\n";
		std::cout << "2 - рядки\n";
		std::cout << "3 - функції\n";
		std::cin >> eltype;
		m.initMatrix(0, eltype, "");
		break;
	case 1:
		std::cout << "Оберіть тип елементів матриці:\n";
		std::cout << "0 - цілі числа\n";
		std::cout << "1 - дійсні числа\n";
		std::cout << "2 - рядки\n";
		std::cout << "3 - функції\n";
		std::cin >> eltype;
		m.initMatrix(1, eltype, "");
		break;
	case 2:
		std::cout << "Введіть назву файлу:";
		std::string filename;
		std::cin >> filename;
		std::cout << "Оберіть тип елементів матриці:\n";
		std::cout << "0 - цілі числа\n";
		std::cout << "1 - дійсні числа\n";
		std::cout << "2 - рядки\n";
		std::cout << "3 - функції\n";
		std::cin >> eltype;
		m.initMatrix(2, eltype, filename);
		break;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "ЛР №1. Розріджені матриці, операції над ними. Фігури, задані невід'ємними функціями, обчислення площ їх перетину/об'єднання\n";
	std::cout << std::endl;
	std::cout << "Оберіть спосіб зчитування матриці:\n";
	std::cout << "1 - введення вручну\n";
	std::cout << "2 - зчитування з файлу\n";
	int op1;
	std::cin >> op1;
	mtr::mtr m;
	int eltype = 0;
	switch (op1) {
	case 0:
		std::cout << "Оберіть тип елементів матриці:\n";
		std::cout << "0 - цілі числа\n";
		std::cout << "1 - дійсні числа\n";
		std::cout << "2 - рядки\n";
		std::cout << "3 - функції\n";
		std::cin >> eltype;
		m.initMatrix(0, eltype, "");
		break;
	case 1:
		std::cout << "Оберіть тип елементів матриці:\n";
		std::cout << "0 - цілі числа\n";
		std::cout << "1 - дійсні числа\n";
		std::cout << "2 - рядки\n";
		std::cout << "3 - функції\n";
		std::cin >> eltype;
		m.initMatrix(1, eltype, "");
		break;
	case 2:
		std::cout << "Введіть назву файлу:";
		std::string filename;
		std::cin >> filename;
		std::cout << "Оберіть тип елементів матриці:\n";
		std::cout << "0 - цілі числа\n";
		std::cout << "1 - дійсні числа\n";
		std::cout << "2 - рядки\n";
		std::cout << "3 - функції\n";
		std::cin >> eltype;
		m.initMatrix(2, eltype, filename);
		break;
	}
	std::cout << "Оберіть дію над матрицею або функціями, що входять до неї:\n";
	std::cout << "0 - виведення матриці\n";
	std::cout << "1 - додавання двох матриць\n";
	std::cout << "2 - множення двох матриць\n";
	std::cout << "3 - множення на вектор\n";
	std::cout << "4 - транспонування матриці\n";
	std::cout << "5 - порівняти ефективність способів збереження матриці\n\n";

	std::cout << "6 - знайти площу фігури\n";
	std::cout << "7 - знайти периметр фігури\n";
	std::cout << "8 - знайти площу та периметр фігури-перетину двох фігур\n";
	std::cout << "9 - знайти площу та периметр фігури-об'єднання двох фігур\n\n";

	std::cout << "10 - вийти з програми\n";
	int i, j, i1, j1;
	bool addit = false;
	while (true) {
		std::cin >> op1;
		std::cout << std::endl;
		switch (op1) {
		case 0:
			break;
		case 1:
			if (addit)
				m.addMatrices(eltype);
			else
				matrEntry();
			break;
		case 2:
			if (addit)
				m.addMatrices(eltype);
			else
				matrEntry();
			break;
		case 3:
			if (addit)
				m.addMatrices(eltype);
			else
				matrEntry();
			break;
		case 4:
			m.transpMatrix(eltype);
			break;
		case 5:
			m.saveMatrix(eltype);
			break;
		case 6:
			std::cout << "Введіть індекси елемента матриці, в якому зберігається функція:\n";
			std::cin >> i;
			std::cin >> j;
			m.calcArea(i, j);
			break;
		case 7:
			std::cout << "Введіть індекси елемента матриці, в якому зберігається функція:\n";
			std::cin >> i;
			std::cin >> j;
			m.calcPerimeter(i, j);
			break;
		case 8:
			std::cout << "Введіть індекси елементів матриці, в яких зберігаються функції:\n";
			std::cin >> i;
			std::cin >> j;
			std::cin >> i1;
			std::cin >> j1;
			m.calcIntersection(i, j, i1, j1);
			break;
		case 9:
			std::cout << "Введіть індекси елементів матриці, в яких зберігаються функції:\n";
			std::cin >> i;
			std::cin >> j;
			std::cin >> i1;
			std::cin >> j1;
			m.calcUnion(i, j, i1, j1);
			break;
		case 10:
			return 0;
			break;
		}
	}
}

//TEST_CASE("testing functionValue") {
//	CHECK(testfunctionValue(1, "x * x" == 1);
//	CHECK(testfunctionValue(2, "x * x" == 4);
//	CHECK(testfunctionValue(2, "x - 1" == 1);
//	CHECK(testfunctionValue(5, "x / 5" == 1);
//}