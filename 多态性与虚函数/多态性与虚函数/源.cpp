#include<iostream>
using namespace std;
#define PI 3.1415926
class Shape {
public:
	virtual float getS() {
		return 0;
	};
};

class Circle : public  Shape {
public:
	Circle(float r) {
		this->r = r;
	}
	float getS() {
		return r * PI * r;
	}

private:
	float r;
};

class Square : public  Shape {
public:
	Square(float a) {
		this->a = a;
	}
	float getS() {
		return a * a;
	}

private:
	float a;
};

class Rectangle : public   Shape {
public:
	Rectangle(float a, float b)
	{
		this->a = a;
		this->b = b;
	}
	float getS() {
		return a * b;
	}

private:
	float a;
	float b;
};

class Tranpezoid : public  Shape {
public:
	Tranpezoid(float a, float b, float c) {
		this->a = a;
		this->b = b;
		this->h = c;
	}
	float getS() {
		return (a + b) * h / 2;
	}
private:
	float a;
	float b;
	float h;
};
class Triangle : public  Shape {
public:
	Triangle(float a, float b) {
		this->a = a;
		this->b = b;
	}
	float getS() {
		return a * b / 2;
	}
private:
	float a;
	float b;
};
int main() {

	float r, a, b, s;
	float sum = 0;
	cout << "������Բ�İ뾶��" << endl;
	cin >> r;
	Shape* S = new Circle(r);
	sum += S->getS();
	cout << "Բ�����Ϊ��" << S->getS() << endl;

	cout << "�����������εı߳���" << endl;
	cin >> a;
	S = new Square(a);
	sum += S->getS();
	cout << "�����ε����Ϊ��" << S->getS() << endl;

	cout << "�����볤���ε����߳���" << endl;
	cin >> a >> b;
	S = new Rectangle(a, b);
	sum += S->getS();
	cout << "�����ε����Ϊ��" << S->getS() << endl;

	cout << "���������ε��ϱߣ��±ߣ��͸ߣ�" << endl;
	cin >> a >> b >> s;
	S = new Tranpezoid(a, b, s);
	sum += S->getS();
	cout << "���ε����Ϊ��" << S->getS() << endl;

	cout << "�����������εĵ׺͸ߣ�" << endl;
	cin >> a >> s;
	S = new Triangle(a, s);
	sum += S->getS();
	cout << "�����ε����Ϊ��" << S->getS() << endl;

	cout << "���ͼ�ε������Ϊ��" << sum << endl;
	system("pause");
	return 0;
}
