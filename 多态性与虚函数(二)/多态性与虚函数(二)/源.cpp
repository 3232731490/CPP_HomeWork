#include<iostream>
using namespace std;

class teature {
public:
	virtual float getwages() = 0;

	float  wage;
	float worktime;
};

class professor :public teature {

public:
	professor(float wage,float time)
	{
		this->wage = wage;
		this->worktime = time;
	}
	float getwages() {
		return wage + 50 * worktime;
	}
};


class fuprofessor :public teature {

public:
	fuprofessor(float wage,float time)
	{
		this->wage = wage;
		this->worktime = time;
	}
	float getwages() {
		return wage + 30 * worktime;
	}
};

class jiangshi :public teature {

public:
	jiangshi(float wage,float time)
	{
		this->wage = wage;
		this->worktime = time;
	}
	float getwages() {
		return wage + 20 * worktime;
	}
};

int main() {

	float time;
	cout << "请输入教授的工作时间：" << endl;
	cin >> time;
	teature* t = new professor(5000,time);
	cout << "教授的工资为： "<<t->getwages() << endl;

	cout << "请输入副教授的工作时间：" << endl;
	cin >> time;
	t = new fuprofessor(3000,time);
	cout << "副教授的工资为：" <<t->getwages()<< endl;

	cout << "请输入讲师的工作时间：" << endl;
	cin >> time;
	t = new jiangshi(2000,time);
	cout << "讲师的工资为：" <<t->getwages()<< endl;

	system("pause");
	return 0;
}