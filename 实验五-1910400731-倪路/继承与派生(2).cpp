#include<iostream>
using namespace std;
#define PI 3.1415926
class Circle {

protected:
	float radius;

};
class ball :public Circle {
public:
	ball(float r) {
		radius = r;
	}
	float GetS(){
		return 4 * PI * radius * radius;
	}
	float GetV() {
		return 4 * PI * radius * radius * radius / 3;
	}
};
class zhu :public Circle {

public:
	zhu(float r , float height) {
		radius = r;
		this->height = height;
	}

	
	float GetS() {
		return 2 * PI * radius * radius+2*PI*radius*height;
	}
	float GetV() {
		return PI * radius * radius * height;
	}
private:
	float height;
};

class zhui :public Circle {

public:
	zhui(float r, float height) {
		radius = r;
		this->height = height;
	}

	float GetS() {
		return  PI * radius * radius + PI*radius*sqrt(radius*radius+height*height);
	}
	float GetV() {
		return PI * radius * radius * height/3;
	}
private:
	float height;
};
int main() {
	float r, h;
	cout << "请输入球的半径：" << endl;

	cin >> r;
	ball b(r);
	cout << "球的体积为：" << b.GetV() << endl;

	cout << "请输入圆柱的半径和高：" << endl;

	cin >> r;
	cin >> h;
	zhu z1(r,h);
	cout << "圆柱的体积为：" << z1.GetV() << endl;

	cout << "请输入圆锥的半径和高：" << endl;

	cin >> r>>h;
	zhui z2(r,h);
	cout << "球的体积为：" << z2.GetV() << endl;


	system("pause");
	return 0;
}