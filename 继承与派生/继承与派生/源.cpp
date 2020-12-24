#include<iostream>
using namespace std;

class Person {
public:
	Person();
	Person(string name, int sex, int age);
	void dispaly();
protected:
	string name;
	int sex; 
	int age;
};
Person::Person() {
	this->name = "NULL";
	this->age = -1;
	this->sex = 1;
}
Person::Person(string name, int sex, int age)
{
	this->age = age;
	this->name = name;
	this->sex = sex;
}
void Person:: dispaly() {
	cout << "姓名： " << name << "性别： " << ((sex == 0) ? "女" : "男") << "年龄： " << age;
}
class Student :public Person{
public:
	Student();
	Student(string name, int sex, int age, string no, string xi);
	void display_s();
protected:
	string no;
	string xi;
};
void Student::display_s() {
	dispaly();
	cout << "学号： " << no << " 系别： " << xi;
}
Student::Student(string name, int sex, int age, string no, string xi):Person(name, sex, age) {
	this->no = no;
	this->xi = xi;
}
Student::Student() {
	this->name = "NULL";
	this->age = -1;
	this->sex = 1;
	this->no = "NULL";
	this->xi = "NULL";
}
class Teture : public Person {
public:
	Teture();
	Teture(string name, int sex, int age, string pos, string clsname);
	void display_t();
private:
	string position;
	string classname;
};
Teture::Teture(string name, int sex, int age, string no, string xi):Person(name, sex, age) {
	this->position = no;
	this->classname = xi;
}
Teture::Teture() {
	this->name = "NULL";
	this->age = -1;
	this->sex = 1;
	this->position = "NULL";
	this->classname = "NULL";
}
void Teture::display_t() {
	dispaly();
	cout << "职位： " << position << " 授课课程： " << classname << endl;
}
class Gradstudent : public Student {
public:
	Gradstudent();
	Gradstudent(string name, int sex, int age, string no, string xi, string teature) :Student(name, sex, age, no, xi) {
		this->teature = teature;
	}
	void display_g();
private:
	string teature;
};
void Gradstudent::display_g()
{
	dispaly();
	display_s();
	cout << "导师： " << teature << endl;
}
int main() {
	cout << "输入学生姓名,性别，年龄，学号，系别：" << endl;
	string name;
	int sex;
	int age;
	string teature;
	string position;
	string classname;

	string no;
	string xi;
	cout << "姓名：" << endl;
	cin >> name;
	cout << "性别： (1--男  0--女)" << endl;
	cin >> sex;
	cout << "年龄：" << endl;
	cin >> age;
	cout << "学号：" << endl;
	cin >> no;
	cout << "系别：" << endl;
	cin >> xi;
	Student S1(name,sex,age,no,xi);
	cout << "学生信息为： ";
	S1.display_s();
	cout << endl;
	cout << "输入老师姓名,性别，年龄，职称，担任课程：" << endl;

	cout << "姓名：" << endl;
	cin >> name;
	cout << "性别： (1--男  0--女)" << endl;
	cin >> sex;
	cout << "年龄：" << endl;
	cin >> age;
	cout << "职称：" << endl;
	cin >> position;
	cout << "担任课程：" << endl;
	cin >> classname;
	Teture T(name,sex,age,position,classname);
	cout << "教师信息为： ";
	T.display_t();

	cout << "输入研究生姓名,性别，年龄，学号，系别，导师：" << endl;
	cout << "姓名：" << endl;
	cin >> name;
	cout << "性别： (1--男  0--女)" << endl;
	cin >> sex;
	cout << "年龄：" << endl;
	cin >> age;
	cout << "学号：" << endl;
	cin >> no;
	cout << "系别：" << endl;
	cin >> xi;
	cout << "导师" << endl;
	cin >> teature;
	Gradstudent G(name,sex,age,no,xi,teature);
	cout << "研究生信息为： ";
	G.display_g();
	system("pause");
	return 0;
}