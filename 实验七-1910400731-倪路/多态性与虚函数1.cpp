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
	cout << "请输入圆的半径：" << endl;
	cin >> r;
	Shape* S = new Circle(r);
	sum += S->getS();
	cout << "圆的面积为：" << S->getS() << endl;

	cout << "请输入正方形的边长：" << endl;
	cin >> a;
	S = new Square(a);
	sum += S->getS();
	cout << "正方形的面积为：" << S->getS() << endl;

	cout << "请输入长方形的两边长：" << endl;
	cin >> a >> b;
	S = new Rectangle(a, b);
	sum += S->getS();
	cout << "长方形的面积为：" << S->getS() << endl;

	cout << "请输入梯形的上边，下边，和高：" << endl;
	cin >> a >> b >> s;
	S = new Tranpezoid(a, b, s);
	sum += S->getS();
	cout << "梯形的面积为：" << S->getS() << endl;

	cout << "请输入三角形的底和高：" << endl;
	cin >> a >> s;
	S = new Triangle(a, s);
	sum += S->getS();
	cout << "三角形的面积为：" << S->getS() << endl;

	cout << "五个图形的面积和为：" << sum << endl;
	system("pause");
	return 0;
}
