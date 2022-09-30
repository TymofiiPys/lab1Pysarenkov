#include "Header.h"
#include <fstream>
#include <iostream>
#include <cmath>
#include <vector>

void mtr::mtr::initMatrix(int inittype, int eltype, std::string filename) {
	if (inittype == 2)
	{
		//Ввід із файлу
		std::ifstream file(filename);
		if (!file)
		{
			std::cout << "Файл \"matr.txt\" не знайдено\n\n";
			return;
		}
		std::string ms, ns;
		std::getline(file, ms);
		std::getline(file, ns);
		std::string row, s;
		int i, j, x;
		m = std::stoi(ms);
		n = std::stoi(ns);
		mainMatrix = new MatrixElt * [m];
		for (i = 0; i < m; i++) {
			mainMatrix[i] = new MatrixElt[n];
		}
		i = 0, j = 0;
		while (!file.eof()) {
			std::string row;
			std::getline(file, row);
			if (i >= m) {
				std::cout << "У файлі більше рядків, ніж Вами вказано!";
				return;
			}
			if (row == "")
			{
				i++;
				j = 0;
			}
			else {
				if (j >= n) {
					std::cout << "У рядку " << i << " більше елементів, ніж Вами вказано!";
					return;
				}
				switch (eltype)
				{
				case 0:
					mainMatrix[i][j].mei = std::stoi(row);
					break;
				case 1:
					mainMatrix[i][j].med = std::stod(row);
					break;
				case 2:
					if (row != "0")
						mainMatrix[i][j].mes = s;
					else
						mainMatrix[i][j].mes = "";
					break;
				case 3:
					if (row != "0")
						mainMatrix[i][j].f.function = s;
					else
						mainMatrix[i][j].f.function = "";
					break;
				}
				j++;
			}
		}
	}
	else if (inittype == 1) {
		//Введення вручну
		std::cout << "Введіть кількість рядків матриці\n";
		std::cin >> m;
		std::cout << "Введіть кількість стовпців матриці\n";
		std::cin >> n;
		mainMatrix = new MatrixElt * [m];
		for (int i = 0; i < m; i++) {
			mainMatrix[i] = new MatrixElt[n];
		}
		std::cout << "Введіть рядки матриці, записуючи ";
		switch (eltype)
		{
		case 0:
			std::cout << "числа ";
			break;
		case 1:
			std::cout << "числа, розділені крапкою ";
			break;
		case 2:
			std::cout << "слова ";
			break;
		case 3:
			std::cout << "функції ";
			break;
		}
		std::cout << "через пробіл\n";
		std::string row, s;
		int i, j;
		for (i = 0; i < m; i++) {
			std::cin >> row;
			int rl = row.length();
			j = 0;
			for (int k = 0; k < rl; k++) {
				if (row[k] != ' ')
					s += row[k];
				if (row[k] == ' ' || k == rl - 1) {
					switch (eltype)
					{
					case 0:
						mainMatrix[i][j].mei = std::stoi(s);
						break;
					case 1:
						mainMatrix[i][j].med = std::stod(s);
						break;
					case 2:
						mainMatrix[i][j].mes = s;
						break;
					}
					j++;
					s = "";
				}
			}
			row = "";
		}
	}
	else {
		//Випадкова генерація
		if (eltype >= 2)
			std::cout << "Випадкова генерація працює лише для масивів із чисельним типом елементів.\n";
		else {
			std::cout << "Введіть кількість рядків матриці\n";
			std::cin >> m;
			std::cout << "Введіть кількість стовпців матриці\n";
			std::cin >> n;
			mainMatrix = new MatrixElt * [m];
			for (int i = 0; i < m; i++) {
				mainMatrix[i] = new MatrixElt[n];
			}
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if(eltype == 0)
						mainMatrix[i][j].mei = (int)(rand() / 100);
					else
						mainMatrix[i][j].med = (rand() / 100);
				}
			}
		}
	}
}

void mtr::mtr::initAddMatrix(int inittype, int eltype, std::string filename) {
	if (inittype == 2)
	{
		std::ifstream file(filename);
		if (!file)
		{
			std::cout << "Файл \"matr.txt\" не знайдено\n\n";
			return;
		}
		std::string ms, ns;
		std::getline(file, ms);
		std::getline(file, ns);
		std::string row, s;
		int i, j, x;
		m = std::stoi(ms);
		n = std::stoi(ns);
		additMatrix = new MatrixElt * [m];
		for (i = 0; i < m; i++) {
			additMatrix[i] = new MatrixElt[n];
		}
		i = 0, j = 0;
		while (!file.eof()) {
			std::string row;
			std::getline(file, row);
			if (i >= m) {
				std::cout << "У файлі більше рядків, ніж Вами вказано!";
				return;
			}
			if (row == "")
			{
				i++;
				j = 0;
			}
			else {
				if (j >= n) {
					std::cout << "У рядку " << i << " більше елементів, ніж Вами вказано!";
					return;
				}
				switch (eltype)
				{
				case 0:
					additMatrix[i][j].mei = std::stoi(row);
					break;
				case 1:
					additMatrix[i][j].med = std::stod(row);
					break;
				case 2:
					if (row != "0")
						additMatrix[i][j].mes = s;
					else
						additMatrix[i][j].mes = "";
					break;
				case 3:
					if (row != "0")
						additMatrix[i][j].f.function = s;
					else
						additMatrix[i][j].f.function = "";
					break;
				}
				j++;
			}
		}
	}
	else if (inittype == 1) {
		std::cout << "Введіть кількість рядків матриці\n";
		std::cin >> m;
		std::cout << "Введіть кількість стовпців матриці\n";
		std::cin >> n;
		additMatrix = new MatrixElt * [m];
		for (int i = 0; i < m; i++) {
			additMatrix[i] = new MatrixElt[n];
		}
		std::cout << "Введіть рядки матриці, записуючи ";
		switch (eltype)
		{
		case 0:
			std::cout << "числа ";
			break;
		case 1:
			std::cout << "числа, розділені крапкою ";
			break;
		case 2:
			std::cout << "слова ";
			break;
		case 3:
			std::cout << "функції ";
			break;
		}
		std::cout << "через пробіл\n";
		std::string row, s;
		int i, j;
		for (i = 0; i < m; i++) {
			std::cin >> row;
			int rl = row.length();
			j = 0;
			for (int k = 0; k < rl; k++) {
				if (row[k] != ' ')
					s += row[k];
				if (row[k] == ' ' || k == rl - 1) {
					switch (eltype)
					{
					case 0:
						additMatrix[i][j].mei = std::stoi(s);
						break;
					case 1:
						additMatrix[i][j].med = std::stod(s);
						break;
					case 2:
						additMatrix[i][j].mes = s;
						break;
					}
					j++;
					s = "";
				}
			}
			row = "";
		}
	}
	else {
	if (eltype >= 2)
		std::cout << "Випадкова генерація працює лише для масивів із чисельним типом елементів.\n";
	else {
		std::cout << "Введіть кількість рядків матриці\n";
		std::cin >> m;
		std::cout << "Введіть кількість стовпців матриці\n";
		std::cin >> n;
		additMatrix = new MatrixElt * [m];
		for (int i = 0; i < m; i++) {
			additMatrix[i] = new MatrixElt[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (eltype == 0)
					additMatrix[i][j].mei = (int)(rand() / 100);
				else
					additMatrix[i][j].med = (rand() / 100);
			}
		}
	}
	}
}

void mtr::mtr::addMatrices(int eltype) {
	if (m != m1 || n != n1) {
		std::cout << "Виміри матриць не співпадають!\n";
	}
	else {
		if (eltype == 0) {
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					mainMatrix[i][j].mei += additMatrix[i][j].mei;
		}
		else if (eltype == 1) {
			for (int i = 0; i < m; i++)
				for (int j = 0; j < n; j++)
					mainMatrix[i][j].med += additMatrix[i][j].med;
		}
		else
		{
			std::cout << "Матриці з елементами, що не являють собою числа, не додаються\n";
		}
	}
}

void mtr::mtr::multMatrices(int eltype) {
	if (eltype == 0 || eltype == 1) {
		MatrixElt** product = new MatrixElt * [m];
		for (int i = 0; i < m; i++) {
			product[i] = new MatrixElt[n];
		}
		int i, j, y, m2 = m, n2 = n, c;
		if (m == n1)
		{
			product = new MatrixElt * [n];
			for (i = 0; i < n; i++) {
				product[i] = new MatrixElt[m1];
			}
			m2 = n;
			n2 = m1;
			c = m;
		}
		else if (m1 == n) {
			product = new MatrixElt * [m];
			for (i = 0; i < m; i++) {
				product[i] = new MatrixElt[n1];
			}
			m2 = m;
			n2 = n1;
			c = n;
		}
		else {
			std::cout << "Неприпустимі виміри матриць!\n";
		}
		double x;
		for (i = 0; i < m2; i++)
		{
			for (j = 0; j < n2; j++) {
				x = 0;
				for (y = 0; y < c; y++) {
					if (!eltype)
						x += mainMatrix[i][y].mei + additMatrix[y][j].mei;
					else
						x += mainMatrix[i][y].med + additMatrix[y][j].med;
				}
				if (!eltype)
					product[i][j].mei = (int)x;
				else
					product[i][j].med = round(x);
			}
		}
		mainMatrix = new MatrixElt * [m2];
		for (i = 0; i < m2; i++) {
			mainMatrix[i] = new MatrixElt[n2];
		}
		if (!eltype)
			for (i = 0; i < m2; i++)
			{
				for (j = 0; j < n2; j++) {
					mainMatrix[i][j].mei = product[i][j].mei;
				}
			}
		else
			for (i = 0; i < m2; i++)
			{
				for (j = 0; j < n2; j++) {
					mainMatrix[i][j].med = product[i][j].med;
				}
			}
	}
	else {
		std::cout << "Матриці з елементами, що не являють собою числа, не множаться\n";
	}
}

void mtr::mtr::transpMatrix(int eltype) {
	MatrixElt** transp = new MatrixElt * [n];
	int i, j, x;
	for (i = 0; i < n; i++) {
		transp[i] = new MatrixElt[m];
	}
	switch (eltype)
	{
	case 0:
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				transp[j][i].mei = mainMatrix[i][j].mei;
			}
		}
		x = m;
		m = n;
		n = x;
		mainMatrix = new MatrixElt * [m];
		for (i = 0; i < m; i++) {
			mainMatrix[i] = new MatrixElt[n];
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				mainMatrix[i][j].mei = transp[i][j].mei;
			}
		}
		break;
	case 1:
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				transp[j][i].med = mainMatrix[i][j].med;
			}
		}
		x = m;
		m = n;
		n = x;
		mainMatrix = new MatrixElt * [m];
		for (i = 0; i < m; i++) {
			mainMatrix[i] = new MatrixElt[n];
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				mainMatrix[i][j].med = transp[i][j].med;
			}
		}
		break;
	case 2:
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				transp[j][i].mes = mainMatrix[i][j].mes;
			}
		}
		x = m;
		m = n;
		n = x;
		mainMatrix = new MatrixElt * [m];
		for (i = 0; i < m; i++) {
			mainMatrix[i] = new MatrixElt[n];
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				mainMatrix[i][j].mes = transp[i][j].mes;
			}
		}
		break;
	}


}

void mtr::mtr::searchByVal(std::string query, int eltype) {
	int i, j;
	for (i = 0; i < 100; i++)
	{
		for (j = 0; j < 100; j++) {
			switch (eltype)
			{
			case 0:
				if (mainMatrix[i][j].mei == std::stoi(query))
					std::cout << "Елемент за Вашим запитом має індекс " << i << ", " << j << std::endl;
				break;
			case 1:
				if (mainMatrix[i][j].med == std::stod(query))
					std::cout << "Елемент за Вашим запитом має індекс " << i << ", " << j << std::endl;
				break;
			case 2:
				if (mainMatrix[i][j].mes == query)
					std::cout << "Елемент за Вашим запитом має індекс " << i << ", " << j << std::endl;
				break;
			case 3:
				if (mainMatrix[i][j].f.function == query)
					std::cout << "Елемент за Вашим запитом має індекс " << i << ", " << j << std::endl;
				break;
			}
		}
	}
};

void mtr::mtr::searchByInd(int iq, int jq, int eltype) {
	switch (eltype)
	{
	case 0:
		std::cout << "Елемент за Вашим запитом - " << mainMatrix[iq][jq].mei << std::endl;
		break;
	case 1:
		std::cout << "Елемент за Вашим запитом - " << mainMatrix[iq][jq].med << std::endl;
		break;
	case 2:
		std::cout << "Елемент за Вашим запитом - " << mainMatrix[iq][jq].mes << std::endl;
		break;
	case 3:
		std::cout << "Елемент за Вашим запитом - " << mainMatrix[iq][jq].f.function << std::endl;
		break;
	}
};

void  mtr::mtr::searchByCriteria(std::string query, int eltype) {
	int i, j;
	std::string comp;
	for (i = 1; i < query.length(); i++) {
		comp += query[i];
	}
	if (query[0] == '<') {
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++) {
				switch (eltype)
				{
				case 0:
					if (mainMatrix[i][j].mei < std::stoi(comp))
						std::cout << "Елемент за Вашим запитом - " << mainMatrix[i][j].mei << ", має індекс " << i << ", " << j << std::endl;
					break;
				case 1:
					if (mainMatrix[i][j].med < std::stod(comp))
						std::cout << "Елемент за Вашим запитом - " << mainMatrix[i][j].med << ", має індекс " << i << ", " << j << std::endl;
					break;
				case 2:
					if (mainMatrix[i][j].mes < comp)
						std::cout << "Елемент за Вашим запитом - " << mainMatrix[i][j].mes << ", має індекс " << i << ", " << j << std::endl;
					break;
				}
			}
		}
	}
	if (query[0] == '>') {
		for (i = 0; i < 100; i++)
		{
			for (j = 0; j < 100; j++) {
				switch (eltype)
				{
				case 0:
					if (mainMatrix[i][j].mei > std::stoi(comp))
						std::cout << "Елемент за Вашим запитом - " << mainMatrix[i][j].mei << ", має індекс " << i << ", " << j << std::endl;
					break;
				case 1:
					if (mainMatrix[i][j].med > std::stod(comp))
						std::cout << "Елемент за Вашим запитом - " << mainMatrix[i][j].med << ", має індекс " << i << ", " << j << std::endl;
					break;
				case 2:
					if (mainMatrix[i][j].mes > comp)
						std::cout << "Елемент за Вашим запитом - " << mainMatrix[i][j].mes << ", має індекс " << i << ", " << j << std::endl;
					break;
				}
			}
		}
	}
	if (query[0] == '=') {
		searchByVal(comp, eltype);
	}
}

void mtr::mtr::saveMatrix(int eltype) {
	//FILE* f1 = fopen("f1.dat", "w+b");//Для представлення масиву у вигляді списку вузлів (два індекси і ненульове значення)
	//FILE* f2 = fopen("f2.dat", "w+b");//Для представлення масиву у вигляді масиву списків вузлів (індекс стовпця і ненульове значення)

	struct INode {//Вузол списку для f1
		int i, j;
		std::string value;
		INode* next;
		INode(int i, int j, std::string value) {
			this->i = i;
			this->j = j;
			this->value = value;
			this->next = nullptr;
		};
	};
	struct SNode {//Елемент масиву і вузол списку для f2
		int j;
		std::string value;
		SNode* next;
		SNode(int j, std::string value) {
			this->j = j;
			this->value = value;
			this->next = nullptr;
		};
	};

	INode* ihead = nullptr;
	INode* itail = nullptr;

	SNode** slist = new SNode * [n];
	for (int i = 0; i < m; i++) {
		slist[i] = nullptr;
	}

	switch (eltype) {
	case 0:
		for (int i = 0; i < m; i++)
		{
			SNode* shead = nullptr;
			SNode* stail = nullptr;
			for (int j = 0; j < n; j++) {
				if (mainMatrix[i][j].mei != 0)
				{
					INode* in = new INode(i, j, std::to_string(mainMatrix[i][j].mei));
					if (!ihead)
					{
						ihead = in;
						itail = in;
					}
					else {
						itail->next = in;
						itail = in;
					}
					SNode* sn = new SNode(j, std::to_string(mainMatrix[i][j].mei));
					if (!shead) {
						shead = sn;
						stail = sn;
					}
					else {
						stail->next = sn;
						stail = sn;
					}
				}
			}
			slist[i] = shead;
		}
		break;
	case 1:
		for (int i = 0; i < m; i++)
		{
			SNode* shead = nullptr;
			SNode* stail = nullptr;
			for (int j = 0; j < n; j++) {
				if (mainMatrix[i][j].med != 0)
				{
					INode* in = new INode(i, j, std::to_string(round(mainMatrix[i][j].med)));
					if (!ihead)
					{
						ihead = in;
						itail = in;
					}
					else {
						itail->next = in;
						itail = in;
					}
					SNode* sn = new SNode(j, std::to_string(round(mainMatrix[i][j].med)));
					if (!shead) {
						shead = sn;
						stail = sn;
					}
					else {
						stail->next = sn;
						stail = sn;
					}
				}
			}
			slist[i] = shead;
		}
		break;
	case 2:
		for (int i = 0; i < m; i++)
		{
			SNode* shead = nullptr;
			SNode* stail = nullptr;
			for (int j = 0; j < n; j++) {
				if (mainMatrix[i][j].mes != "")
				{
					INode* in = new INode(i, j, mainMatrix[i][j].mes);
					if (!ihead)
					{
						ihead = in;
						itail = in;
					}
					else {
						itail->next = in;
						itail = in;
					}
					SNode* sn = new SNode(j, mainMatrix[i][j].mes);
					if (!shead) {
						shead = sn;
						stail = sn;
					}
					else {
						stail->next = sn;
						stail = sn;
					}
				}
			}
			slist[i] = shead;
		}
		break;
	case 3:
		for (int i = 0; i < m; i++) {
			SNode* shead = nullptr;
			SNode* stail = nullptr;
			for (int j = 0; j < n; j++) {
				if (mainMatrix[i][j].f.function != "")
				{
					INode* in = new INode(i, j, mainMatrix[i][j].f.function);
					if (!ihead)
					{
						ihead = in;
						itail = in;
					}
					else {
						itail->next = in;
						itail = in;
					}
					SNode* sn = new SNode(j, mainMatrix[i][j].f.function);
					if (!shead) {
						shead = sn;
						stail = sn;
					}
					else {
						stail->next = sn;
						stail = sn;
					}
				}
			}
			slist[i] = shead;
		}
		break;
	}
	//fwrite(ihead, sizeof(ihead), 1, f1);
	////Записали список у файл
	//fwrite(slist, sizeof(slist), 1, f1);
	////Записали масив списків у файл
	if (sizeof(ihead) < sizeof(slist))
		std::cout << "Зв'язано-стисле зберігання є більш ефективним\n";
	else if (sizeof(ihead) > sizeof(slist))
		std::cout << "Послідовно-зв'язане індексне зберігання є більш ефективним\n";
	else
		std::cout << "Послідовно-зв'язане індексне зберігання і зв'язано-стисле зберігання є однаково ефективними\n";
}

void mtr::mtr::calcArea(int i, int j) {
	double a = mainMatrix[i][j].f.a;
	double b = mainMatrix[i][j].f.b;
	double step = (b - a) / 100000;  // крок
	double area = 0.0;
	for (int k = 0; k < 100000; k++) {
		area += functionValue(a + (k + 0.5) * step, i, j) * step; // додаємо з кожною ітерацією площу маленького прямокутника шириною step,
		//висотою, що рівна величині функції у точці a + (i + 0.5)*step
	}
	mainMatrix[i][j].f.area = area;
}

double mtr::mtr::calcArea(int i, int j, double a, double b) {
	double step = (b - a) / 100000;  // крок
	double area = 0.0;
	for (int k = 0; k < 100000; k++) {
		area += functionValue(a + (k + 0.5) * step, i, j) * step; // додаємо з кожною ітерацією площу маленького прямокутника шириною step,
		//висотою, що рівна величині функції у точці a + (i + 0.5)*step
	}
	return area;
}

void mtr::mtr::calcPerimeter(int i, int j) {
	double a = mainMatrix[i][j].f.a;
	double b = mainMatrix[i][j].f.b;
	double step = (b - a) / 100000;  // крок
	double per = 0.0;
	double y1, y2;
	for (int k = 0; k < 100000; k++) {
		y1 = functionValue(a + k * step, i, j);
		y2 = functionValue(a + (k + 1) * step, i, j);
		per += pow(y2 - y1, 2) + pow(step, 2); // додаємо з кожною ітерацією відстань від точки (a + k*step, f(a + k*step)) 
		//до точки  (a + (k+1)*step, f(a + (k+1)*step)). Тобто (х2 - х1)^2 + (y2 - y1)^2 (перший доданок зрозуміло, що рівний step^2)
	}
	per += functionValue(a, i, j) + functionValue(b, i, j) + b - a; //не забуваємо, що фігура також обмежена прямими x = a, x = b та віссю абсцис
	mainMatrix[i][j].f.per = per;
}

double mtr::mtr::calcPerimeter(int i, int j, double a, double b) {
	double step = (b - a) / 100000;  // крок
	double per = 0.0;
	double y1, y2;
	for (int k = 0; k < 100000; k++) {
		y1 = functionValue(a + k * step, i, j);
		y2 = functionValue(a + (k + 1) * step, i, j);
		per += pow(y2 - y1, 2) + pow(step, 2); // додаємо з кожною ітерацією відстань від точки (a + k*step, f(a + k*step)) 
		//до точки  (a + (k+1)*step, f(a + (k+1)*step)). Тобто (х2 - х1)^2 + (y2 - y1)^2 (перший доданок зрозуміло, що рівний step^2)
	}

	return per;
}

void mtr::mtr::calcIntersection(int i1, int j1, int i2, int j2) {
	Figure f1 = mainMatrix[i1][j1].f;
	Figure f2 = mainMatrix[i2][j2].f;
	if (f1.b <= f2.a || f2.b <= f1.a)
		std::cout << "Фігури не мають перетину\n";
	else {
		double a, b, per = 0.0;
		//Знаходимо межі фігури-перетину двох фігур
		if (f2.a > f1.a)
		{
			a = f2.a;
			per += functionValue(a, i2, j2);
		}
		else
		{
			a = f1.a;
			per += functionValue(a, i1, j1);
		}
		if (f2.b > f1.b)
		{
			b = f1.b;
			per += functionValue(b, i1, j1);
		}
		else
		{
			b = f2.b;
			per += functionValue(b, i2, j2);
		}
		per += b - a;
		double step = (b - a) / 100000;  // крок
		double area = 0.0;
		double f1y1, f2y1, y1, y2;
		for (int k = 0; k < 100000; k++) {
			f1y1 = functionValue(a + k * step, i1, j1);
			f2y1 = functionValue(a + k * step, i2, j2);
			if (f2y1 < f1y1) {
				y1 = f2y1;
				y2 = functionValue(a + (k + 1) * step, i2, j2);
			}
			else {
				y1 = f1y1;
				y2 = functionValue(a + (k + 1) * step, i1, j1);
			}
			per += pow(y2 - y1, 2) + pow(step, 2);
			area += (y2 + y1) * 0.5 * step;
		}
	}
}

void mtr::mtr::calcUnion(int i1, int j1, int i2, int j2) {
	Figure f1 = mainMatrix[i1][j1].f;
	Figure f2 = mainMatrix[i2][j2].f;
	double per = 0.0, area = 0.0;
	if (f1.b <= f2.a || f2.b <= f1.a)
	{
		per = f1.per + f2.per;
		area = f1.area + f2.area;
	}
	else {
		double a, b;
		per = 0.0;
		//Знаходимо межі фігури-об'єднання двох фігур
		if (f2.a > f1.a)
		{
			a = f2.a;
			per += functionValue(f1.a, i1, j1) + calcPerimeter(i1, j1, f1.a, f2.a) + abs(functionValue(a, i1, j1) - functionValue(a, i2, j2));
			area += calcArea(i1, j1, f1.a, f2.a);
		}
		else
		{
			a = f1.a;
			per += functionValue(f2.a, i2, j2) + calcPerimeter(i2, j2, f2.a, f1.a) + abs(functionValue(a, i1, j1) - functionValue(a, i2, j2));
			area += calcArea(i2, j2, f2.a, f1.a);
		}
		if (f2.b > f1.b)
		{
			b = f1.b;
			per += functionValue(f2.b, i2, j2) + calcPerimeter(i2, j2, f1.b, f2.b) + abs(functionValue(b, i1, j1) - functionValue(b, i2, j2));
			area += calcArea(i2, j2, f1.b, f2.b);
		}
		else
		{
			b = f2.b;
			per += functionValue(f1.b, i1, j1) + calcPerimeter(i1, j1, f2.b, f1.b) + abs(functionValue(b, i1, j1) - functionValue(b, i2, j2));
			area += calcArea(i1, j1, f2.b, f1.b);
		}
		per += b - a;
		double step = (b - a) / 100000;  // крок
		double f1y1, f2y1, y1, y2;
		for (int k = 0; k < 100000; k++) {
			f1y1 = functionValue(a + k * step, i1, j1);
			f2y1 = functionValue(a + k * step, i2, j2);
			if (f2y1 > f1y1) {
				y1 = f2y1;
				y2 = functionValue(a + (k + 1) * step, i2, j2);
			}
			else {
				y1 = f1y1;
				y2 = functionValue(a + (k + 1) * step, i1, j1);
			}
			per += pow(y2 - y1, 2) + pow(step, 2);
			area += (y2 + y1) * 0.5 * step;
		}
	}
}

//Функція записується у вигляді дерева, дії у функції відбуваються в порядку
struct Node {
	double val; // >= 0 - дійсне число, -1 - додавання, -2 - множення, -3 - віднімання, -4 - ділення, -5/-6 - синус/косинус, -120 - змінна х
	Node* left;
	Node* right;
	Node* next;
	Node(int val) {
		this->val = val;
		this->next = nullptr;
		this->left = nullptr;
		this->right = nullptr;
	}
};

void push(Node* n, Node** Top) {
	if (!Top)
		*Top = n;
	else {
		n->next = *Top;
		*Top = n;
	}
}

Node* pop(Node** Top) {
	Node* p = *Top;
	*Top = (*Top)->next;
	return p;
}

Node* simpl(Node* n) {//Спрощення виразу: видалення зайвих нулів при додаванні, одиниць при множенні
	Node* nl, * nr;
	if (!n) return n; //Якщо у попереднього вузла нема дітей і
	if (n->val > 0) return n; //якщо у вузлі записане дійсне число, спрощення не відбувається
	nl = n->left = simpl(n->left);
	nr = n->right = simpl(n->right);
	if (nl->val > 0 || nr->val > 0)
	{
		if (n->val == -1)
			n->val = nl->val + nr->val;
		if (n->val == -2)
			n->val = nl->val * nr->val;
		if (n->val == -3)
			n->val = nl->val - nr->val;
		if (n->val == -4)
		{
			if (nr->val == 0)
			{
				std::cout << "Помилка ділення на нуль";
				system("pause");
			}
			n->val = nl->val / nr->val;
		}
		if (n->val == -5)
			n->val = sin(nr->val);
		if (n->val == -6)
			n->val = cos(nr->val);
	}
	return n;
}

void subst(Node* n, double x) {
	//Підстановка переданого в functionValue() значення замість змінної x
	if (!n)
		return;
	else {
		subst(n->left, x);
		if (n->val == -120)
			n->val = x;
		subst(n->right, x);
	}
}

double mtr::mtr::functionValue(double x, int i, int j) {
	std::string function = mainMatrix[i][j].f.function,
		sval;
	int rl = function.length();
	Node* StackTop = nullptr;
	for (int k = 0; k < rl; k++) {
		if (function[k] != ' ')//sval - знак операції/змінна/дійсне число, яке буде занесено у вузол. Його зчитування продовжується
			//доти, доки у введеному рядку не буде досягнуто пробілу.
			sval += function[i];
		if (function[k] == ' ' || k == rl - 1)
		{
			int val;
			if (sval == "+")
				val = -1;
			else if (sval == "*")
				val = -2;
			else if (sval == "-")
				val = -3;
			else if (sval == "/")
				val = -4;
			else if (sval == "sin")
				val = -5;
			else if (sval == "cos")
				val = -6;
			else if (sval.length() == 1 && isalpha(sval[0])) //чи є змінною
				val = -1 * sval[0]; //змінна записується у вигляді числа, що помножене на -1 відповідно до таблиці ASCII
			else //в інших випадках вважаємо, що sval є числом
				val = std::stoi(sval);
			if (val < 0 && val > -4) //операції +, -, * потребують двох аргументів, тому у них буде дві "дитини" - ліва і права
			{
				Node* a, * b, * n;
				n = new Node(val);
				a = pop(&StackTop);
				b = pop(&StackTop);
				n->left = b;
				n->right = a;
				push(n, &StackTop);
			}
			else if (val == -5 || val == -4) { //операції sin і cos потребують лише одного аргумента, тому у них буде одна "дитина" - права
				Node* a, * n;
				n = new Node(val);
				a = pop(&StackTop);
				n->right = a;
				push(n, &StackTop);
			}
			else { //змінні і дійсні числа
				Node* n = new Node(val);
				push(n, &StackTop);
			}
			sval = "";
		}
	}
	//дії у функції відбуваються в порядку проходження дерева зліва направо
	subst(StackTop, x);
	StackTop = simpl(StackTop);
	return StackTop->val;
}


//double mtr::mtr::testfunctionValue(double x, std::string s) {
//	std::string function = s,
//		sval;
//	int rl = function.length();
//	Node* StackTop = nullptr;
//	for (int k = 0; k < rl; k++) {
//		if (function[k] != ' ')//sval - знак операції/змінна/дійсне число, яке буде занесено у вузол. Його зчитування продовжується
//			//доти, доки у введеному рядку не буде досягнуто пробілу.
//			sval += function[i];
//		if (function[k] == ' ' || k == rl - 1)
//		{
//			int val;
//			if (sval == "+")
//				val = -1;
//			else if (sval == "*")
//				val = -2;
//			else if (sval == "-")
//				val = -3;
//			else if (sval == "/")
//				val = -4;
//			else if (sval == "sin")
//				val = -5;
//			else if (sval == "cos")
//				val = -6;
//			else if (sval.length() == 1 && isalpha(sval[0])) //чи є змінною
//				val = -1 * sval[0]; //змінна записується у вигляді числа, що помножене на -1 відповідно до таблиці ASCII
//			else //в інших випадках вважаємо, що sval є числом
//				val = std::stoi(sval);
//			if (val < 0 && val > -4) //операції +, -, * потребують двох аргументів, тому у них буде дві "дитини" - ліва і права
//			{
//				Node* a, * b, * n;
//				n = new Node(val);
//				a = pop(&StackTop);
//				b = pop(&StackTop);
//				n->left = b;
//				n->right = a;
//				push(n, &StackTop);
//			}
//			else if (val == -5 || val == -4) { //операції sin і cos потребують лише одного аргумента, тому у них буде одна "дитина" - права
//				Node* a, * n;
//				n = new Node(val);
//				a = pop(&StackTop);
//				n->right = a;
//				push(n, &StackTop);
//			}
//			else { //змінні і дійсні числа
//				Node* n = new Node(val);
//				push(n, &StackTop);
//			}
//			sval = "";
//		}
//	}
//	//дії у функції відбуваються в порядку проходження дерева зліва направо
//	subst(StackTop, x);
//	StackTop = simpl(StackTop);
//	return StackTop->val;
//}