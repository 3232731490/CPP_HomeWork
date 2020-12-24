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
	cout << "������ " << name << "�Ա� " << ((sex == 0) ? "Ů" : "��") << "���䣺 " << age;
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
	cout << "ѧ�ţ� " << no << " ϵ�� " << xi;
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
	cout << "ְλ�� " << position << " �ڿογ̣� " << classname << endl;
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
	cout << "��ʦ�� " << teature << endl;
}
int main() {
	cout << "����ѧ������,�Ա����䣬ѧ�ţ�ϵ��" << endl;
	string name;
	int sex;
	int age;
	string teature;
	string position;
	string classname;

	string no;
	string xi;
	cout << "������" << endl;
	cin >> name;
	cout << "�Ա� (1--��  0--Ů)" << endl;
	cin >> sex;
	cout << "���䣺" << endl;
	cin >> age;
	cout << "ѧ�ţ�" << endl;
	cin >> no;
	cout << "ϵ��" << endl;
	cin >> xi;
	Student S1(name,sex,age,no,xi);
	cout << "ѧ����ϢΪ�� ";
	S1.display_s();
	cout << endl;
	cout << "������ʦ����,�Ա����䣬ְ�ƣ����ογ̣�" << endl;

	cout << "������" << endl;
	cin >> name;
	cout << "�Ա� (1--��  0--Ů)" << endl;
	cin >> sex;
	cout << "���䣺" << endl;
	cin >> age;
	cout << "ְ�ƣ�" << endl;
	cin >> position;
	cout << "���ογ̣�" << endl;
	cin >> classname;
	Teture T(name,sex,age,position,classname);
	cout << "��ʦ��ϢΪ�� ";
	T.display_t();

	cout << "�����о�������,�Ա����䣬ѧ�ţ�ϵ�𣬵�ʦ��" << endl;
	cout << "������" << endl;
	cin >> name;
	cout << "�Ա� (1--��  0--Ů)" << endl;
	cin >> sex;
	cout << "���䣺" << endl;
	cin >> age;
	cout << "ѧ�ţ�" << endl;
	cin >> no;
	cout << "ϵ��" << endl;
	cin >> xi;
	cout << "��ʦ" << endl;
	cin >> teature;
	Gradstudent G(name,sex,age,no,xi,teature);
	cout << "�о�����ϢΪ�� ";
	G.display_g();
	system("pause");
	return 0;
}