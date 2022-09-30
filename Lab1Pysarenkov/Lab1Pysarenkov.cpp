#include <iostream>
#include "Header.h"
#include <Windows.h>
//#include "doctest.h"

void matrEntry() {
	mtr::mtr m;
	std::cout << "������ ����� ���������� ��������� �������:\n";
	std::cout << "0 - ��������� ���������\n";
	std::cout << "1 - �������� ������\n";
	std::cout << "2 - ���������� � �����\n";
	int op1;
	std::cin >> op1;
	int eltype = 0;
	switch (op1) {
	case 0:
		std::cout << "������ ��� �������� �������:\n";
		std::cout << "0 - ��� �����\n";
		std::cout << "1 - ���� �����\n";
		std::cout << "2 - �����\n";
		std::cout << "3 - �������\n";
		std::cin >> eltype;
		m.initMatrix(0, eltype, "");
		break;
	case 1:
		std::cout << "������ ��� �������� �������:\n";
		std::cout << "0 - ��� �����\n";
		std::cout << "1 - ���� �����\n";
		std::cout << "2 - �����\n";
		std::cout << "3 - �������\n";
		std::cin >> eltype;
		m.initMatrix(1, eltype, "");
		break;
	case 2:
		std::cout << "������ ����� �����:";
		std::string filename;
		std::cin >> filename;
		std::cout << "������ ��� �������� �������:\n";
		std::cout << "0 - ��� �����\n";
		std::cout << "1 - ���� �����\n";
		std::cout << "2 - �����\n";
		std::cout << "3 - �������\n";
		std::cin >> eltype;
		m.initMatrix(2, eltype, filename);
		break;
	}
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	std::cout << "�� �1. �������� �������, �������� ��� ����. Գ����, ����� ����'������ ���������, ���������� ���� �� ��������/��'�������\n";
	std::cout << std::endl;
	std::cout << "������ ����� ���������� �������:\n";
	std::cout << "1 - �������� ������\n";
	std::cout << "2 - ���������� � �����\n";
	int op1;
	std::cin >> op1;
	mtr::mtr m;
	int eltype = 0;
	switch (op1) {
	case 0:
		std::cout << "������ ��� �������� �������:\n";
		std::cout << "0 - ��� �����\n";
		std::cout << "1 - ���� �����\n";
		std::cout << "2 - �����\n";
		std::cout << "3 - �������\n";
		std::cin >> eltype;
		m.initMatrix(0, eltype, "");
		break;
	case 1:
		std::cout << "������ ��� �������� �������:\n";
		std::cout << "0 - ��� �����\n";
		std::cout << "1 - ���� �����\n";
		std::cout << "2 - �����\n";
		std::cout << "3 - �������\n";
		std::cin >> eltype;
		m.initMatrix(1, eltype, "");
		break;
	case 2:
		std::cout << "������ ����� �����:";
		std::string filename;
		std::cin >> filename;
		std::cout << "������ ��� �������� �������:\n";
		std::cout << "0 - ��� �����\n";
		std::cout << "1 - ���� �����\n";
		std::cout << "2 - �����\n";
		std::cout << "3 - �������\n";
		std::cin >> eltype;
		m.initMatrix(2, eltype, filename);
		break;
	}
	std::cout << "������ �� ��� �������� ��� ���������, �� ������� �� ��:\n";
	std::cout << "0 - ��������� �������\n";
	std::cout << "1 - ��������� ���� �������\n";
	std::cout << "2 - �������� ���� �������\n";
	std::cout << "3 - �������� �� ������\n";
	std::cout << "4 - �������������� �������\n";
	std::cout << "5 - �������� ����������� ������� ���������� �������\n\n";

	std::cout << "6 - ������ ����� ������\n";
	std::cout << "7 - ������ �������� ������\n";
	std::cout << "8 - ������ ����� �� �������� ������-�������� ���� �����\n";
	std::cout << "9 - ������ ����� �� �������� ������-��'������� ���� �����\n\n";

	std::cout << "10 - ����� � ��������\n";
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
			std::cout << "������ ������� �������� �������, � ����� ���������� �������:\n";
			std::cin >> i;
			std::cin >> j;
			m.calcArea(i, j);
			break;
		case 7:
			std::cout << "������ ������� �������� �������, � ����� ���������� �������:\n";
			std::cin >> i;
			std::cin >> j;
			m.calcPerimeter(i, j);
			break;
		case 8:
			std::cout << "������ ������� �������� �������, � ���� ����������� �������:\n";
			std::cin >> i;
			std::cin >> j;
			std::cin >> i1;
			std::cin >> j1;
			m.calcIntersection(i, j, i1, j1);
			break;
		case 9:
			std::cout << "������ ������� �������� �������, � ���� ����������� �������:\n";
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