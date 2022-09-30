#pragma once
#include <string>
#include <vector>

namespace mtr {
	struct mtr
	{
	private:
		struct Figure {
			std::string function; //Функція, записана рядком
			//Приклади: y = x ^ 2
			//y = 2 * x + 1
			//y = cos( x )
			//y = 1 / x
			double a{};//Ліва межа інтегрування функції
			double b{};//Права межа інтегрування функції

			double area{}; //Площа фігури, утвореної функцією, заданої у function, прямими x = a, x = b та віссю абсцис
			double per{}; //Периметр цієї ж фігури

			Figure(std::string function, double a, double b, double area, double per) {
				this->function = function;
				this->a = a;
				this->b = b;
				this->area = area;
				this->per = per;
			};
			Figure() {};
		};

		struct MatrixElt {										//Елемент матриці може являти собою:
			int mei{};											//ціле число,
			double med{};										//дійсне число 
			std::string mes;									//рядок типу string
			Figure f;											//структура Figure
			std::vector<int> v;									//vector з елементів int
			MatrixElt(int mei, double med, std::string mes, Figure f) {
				this->mei = mei;
				this->med = med;
				this->mes = mes;
				this->f = f;
			}
			MatrixElt() {};
		};
	public:
		MatrixElt** mainMatrix; //основна матриця розміру m*n
		MatrixElt** additMatrix;//матриця (вектор) розміру m1*n1, застосовується для множення або додавання матриць
		int m, n, m1, n1;
		void initMatrix(int inittype, int eltype, std::string filename); //Ініціалізація матриці шляхом зчитування її з файлу або введення вручну
		void initAddMatrix(int inittype, int eltype, std::string filename); //Ініціалізація додаткової матриці
		void addMatrices(int eltype); //Додавання двох матриць
		void multMatrices(int eltype); //Множення двох матриць
		void transpMatrix(int eltype); //Транспонування матриці mainMatrix
		void searchByVal(std::string, int eltype);
		void searchByInd(int iq, int jq, int eltype);
		void searchByCriteria(std::string query, int eltype);
		void saveMatrix(int eltype);

		void calcArea(int i, int j);		//Пошук площіз індексом (i; j) у mainMatrix
		double calcArea(int i, int j, double a, double b);		//Пошук площі частини фігури від a до b
		void calcPerimeter(int i, int j);	//Пошук периметра фігури 
		double calcPerimeter(int i, int j, double a, double b);	//Пошук периметра частини фігури від a до b
		void calcIntersection(int i1, int j1, int i2, int j2); //Обчислення фігури-перетину двох фігур з індексами (i1; j1) та (i2; j2) у mainMatrix
		void calcUnion(int i1, int j1, int i2, int j2);//Обчислення фігури-об'єднання двох фігур
		double functionValue(double x, int i, int j); //Пошук значення функції в точці x
		//double testfunctionValue(double x, std::string s);
	};
}