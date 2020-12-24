#include<iostream>
using namespace std;

class Complex {
public:
	Complex() {
		real = 0;
		vtu = 0;
	};
	Complex(float r, float v) {
		real = r;
		vtu = v;
	}
	void display() {
		cout << real << " + " << vtu << " i" << endl;
	}
	Complex operator +(Complex& C) {
		Complex c;
		c.real = this->real + C.real;
		c.vtu = this->vtu + C.vtu;
		return c;
	}
	Complex operator -(Complex& C) {
		Complex c;
		c.real = this->real - C.real;
		c.vtu = this->vtu - C.vtu;
		return c;
	}
	Complex operator *(Complex& C) {
		Complex c;
		c.real = this->real*C.real-this->vtu*C.vtu;
		c.vtu = this->vtu *C.real+ C.vtu*this->real;
		return c;
	}
	Complex operator /(Complex& C) {
		Complex c;
		float temp_r = 0;
		float temp_v = 0;
		temp_r = C.real * C.real + C.vtu * C.vtu;
		temp_v= this->real * C.real + this->vtu * C.vtu;
		c.real = temp_v/temp_r;
		temp_v = this->vtu * C.real - this->real * C.vtu;
		c.vtu = temp_v/temp_r;
		return c;
	}
	int operator <(Complex& C) {
		if (this->vtu != 0 || C.vtu != 0)
		{
			cout << "�����鲿��Ϊ0���޷��Ƚϴ�С��" << endl;
			return -1;
		}
		else
		{
			return this->real < C.real;
		}
	}
	int operator >(Complex& C) {
		if (this->vtu != 0 || C.vtu != 0)
		{
			cout << "�����鲿��Ϊ0���޷��Ƚϴ�С��" << endl;
			return -1;
		}
		else
		{
			return this->real > C.real;
		}
	}
	Complex operator++()   //ǰ���Լ�
	{
		this->real++;
		return *this;
	}
	Complex operator++(int)  //�����Լ�
	{
		Complex C;
		C = *this;
		this->real++;
		this->vtu;
		return C;
	}
	Complex operator--()   //ǰ���Լ�
	{
		this->real--;
		return *this;
	}
	Complex operator--(int)  //�����Լ�
	{
		Complex C;
		C = *this;
		this->real--;
		this->vtu;
		return C;
	}
private:
	float real;
	float vtu;
};

int main()
{
  A:	
	cout << "�������һ��������ʵ�����鲿��" << endl;
	float r, v;
	cin >> r>> v;
	Complex C1(r, v);
	cout << "������ڶ���������ʵ�����鲿��" << endl;
	cin >> r>>v;
	Complex C2(r, v);
	while (1)
	{
		cout << "��ѡ����Ҫ���е����������" << endl;
		cout << "1���ӷ�" << endl;
		cout << "2������" << endl;
		cout << "3���˷�" << endl;
		cout << "4������" << endl;
		cout << "5���Ƚϴ�С" << endl;
		cout << "6����������" << endl;
		cout << "7���Լ�����" << endl;
		cout << "8���������븴��" << endl;
		cout << "0���˳�" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "������ӽ��Ϊ��" << endl;
			(C1 + C2).display();
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "����������Ϊ��" << endl;
			(C1 - C2).display();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "������˽��Ϊ��" << endl;
			(C1 * C2).display();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "����������Ϊ��" << endl;
			(C1 / C2).display();
			system("pause");
			system("cls");
			break;
		case 5:
			if (C1 > C2!=-1)
			{
				if (C1 > C2)
				{
					cout << "C1 > C2" << endl;
				}
				else
				{
					cout << "C1 < C2" << endl;
				}
			}
			system("pause");
			system("cls");
			break;
		case 6:
			cout << "C1 ǰ���Լ� ��" << endl;
			(++C1).display();
			cout << "C1 �����Լ� ��" << endl;
			C1++.display();
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "C1 ǰ���Լ� ��" << endl;
			(--C1).display();
			cout << "C1 �����Լ� ��" << endl;
			C1--.display();
			system("pause");
			system("cls");
			break;
		case 8:
			system("cls");
			goto A;
		case 0:
			return 0;
		}
	}
	system("pause");
	return 0;
}