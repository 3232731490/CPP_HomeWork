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
			cout << "复数虚部不为0，无法比较大小！" << endl;
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
			cout << "复数虚部不为0，无法比较大小！" << endl;
			return -1;
		}
		else
		{
			return this->real > C.real;
		}
	}
	Complex operator++()   //前置自加
	{
		this->real++;
		return *this;
	}
	Complex operator++(int)  //后置自加
	{
		Complex C;
		C = *this;
		this->real++;
		this->vtu;
		return C;
	}
	Complex operator--()   //前置自减
	{
		this->real--;
		return *this;
	}
	Complex operator--(int)  //后置自减
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
	cout << "请输入第一个复数的实部和虚部：" << endl;
	float r, v;
	cin >> r>> v;
	Complex C1(r, v);
	cout << "请输入第二个复数的实部和虚部：" << endl;
	cin >> r>>v;
	Complex C2(r, v);
	while (1)
	{
		cout << "请选择您要进行的运算操作：" << endl;
		cout << "1、加法" << endl;
		cout << "2、减法" << endl;
		cout << "3、乘法" << endl;
		cout << "4、除法" << endl;
		cout << "5、比较大小" << endl;
		cout << "6、自增运算" << endl;
		cout << "7、自减运算" << endl;
		cout << "8、重新输入复数" << endl;
		cout << "0、退出" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << "复数相加结果为：" << endl;
			(C1 + C2).display();
			system("pause");
			system("cls");
			break;
		case 2:
			cout << "复数相减结果为：" << endl;
			(C1 - C2).display();
			system("pause");
			system("cls");
			break;
		case 3:
			cout << "复数相乘结果为：" << endl;
			(C1 * C2).display();
			system("pause");
			system("cls");
			break;
		case 4:
			cout << "复数相除结果为：" << endl;
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
			cout << "C1 前置自加 ：" << endl;
			(++C1).display();
			cout << "C1 后置自加 ：" << endl;
			C1++.display();
			system("pause");
			system("cls");
			break;
		case 7:
			cout << "C1 前置自减 ：" << endl;
			(--C1).display();
			cout << "C1 后置自减 ：" << endl;
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