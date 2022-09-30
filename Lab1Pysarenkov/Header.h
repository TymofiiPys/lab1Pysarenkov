#pragma once
#include <string>
#include <vector>

namespace mtr {
	struct mtr
	{
	private:
		struct Figure {
			std::string function; //�������, �������� ������
			//��������: y = x ^ 2
			//y = 2 * x + 1
			//y = cos( x )
			//y = 1 / x
			double a{};//˳�� ���� ������������ �������
			double b{};//����� ���� ������������ �������

			double area{}; //����� ������, �������� ��������, ������ � function, ������� x = a, x = b �� ���� ������
			double per{}; //�������� ���� � ������

			Figure(std::string function, double a, double b, double area, double per) {
				this->function = function;
				this->a = a;
				this->b = b;
				this->area = area;
				this->per = per;
			};
			Figure() {};
		};

		struct MatrixElt {										//������� ������� ���� ������ �����:
			int mei{};											//���� �����,
			double med{};										//����� ����� 
			std::string mes;									//����� ���� string
			Figure f;											//��������� Figure
			std::vector<int> v;									//vector � �������� int
			MatrixElt(int mei, double med, std::string mes, Figure f) {
				this->mei = mei;
				this->med = med;
				this->mes = mes;
				this->f = f;
			}
			MatrixElt() {};
		};
	public:
		MatrixElt** mainMatrix; //������� ������� ������ m*n
		MatrixElt** additMatrix;//������� (������) ������ m1*n1, ������������� ��� �������� ��� ��������� �������
		int m, n, m1, n1;
		void initMatrix(int inittype, int eltype, std::string filename); //����������� ������� ������ ���������� �� � ����� ��� �������� ������
		void initAddMatrix(int inittype, int eltype, std::string filename); //����������� ��������� �������
		void addMatrices(int eltype); //��������� ���� �������
		void multMatrices(int eltype); //�������� ���� �������
		void transpMatrix(int eltype); //�������������� ������� mainMatrix
		void searchByVal(std::string, int eltype);
		void searchByInd(int iq, int jq, int eltype);
		void searchByCriteria(std::string query, int eltype);
		void saveMatrix(int eltype);

		void calcArea(int i, int j);		//����� ������ �������� (i; j) � mainMatrix
		double calcArea(int i, int j, double a, double b);		//����� ����� ������� ������ �� a �� b
		void calcPerimeter(int i, int j);	//����� ��������� ������ 
		double calcPerimeter(int i, int j, double a, double b);	//����� ��������� ������� ������ �� a �� b
		void calcIntersection(int i1, int j1, int i2, int j2); //���������� ������-�������� ���� ����� � ��������� (i1; j1) �� (i2; j2) � mainMatrix
		void calcUnion(int i1, int j1, int i2, int j2);//���������� ������-��'������� ���� �����
		double functionValue(double x, int i, int j); //����� �������� ������� � ����� x
		//double testfunctionValue(double x, std::string s);
	};
}