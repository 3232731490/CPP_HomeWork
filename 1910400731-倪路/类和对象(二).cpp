#include<iostream>
using namespace std;
class Rectangle {
public:
	Rectangle() {
		this->wid = 0;
		this->len = 0;
	}
	Rectangle(double wid, double len) {
		this->len = len;
		this->wid = wid;
	}
	double CRec() {
		return this->len + this->wid;
	}
	double SRec() {
		return this->len * this->wid;
	}
	void displayRec() {
		cout << "width: " << this->wid <<"    "<< "lenth: " << this->len << endl;
	}
	void modRec(double len, double wid) {
		this->len = len;
		this->wid = wid;
	}
private:
	double len;
	double wid;
};

int main() {
	Rectangle R(10,20);
	cout << "修改前：" << endl;
	R.displayRec();
	cout << "周长：" << R.CRec() << endl;
	cout << "面积： " << R.SRec() << endl;
	R.modRec(20, 20);
	cout << "修改前：" << endl;
	R.displayRec();
	cout << "周长：" << R.CRec() << endl;
	cout << "面积： " << R.SRec() << endl;
	system("pause");
	return 0;
}