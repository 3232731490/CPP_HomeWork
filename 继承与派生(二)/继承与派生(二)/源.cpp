#include<iostream>
using namespace std;

class  Person {
public:
	Person() {
		name = "NULL";
		age = -1;
		sex = 1;
		adds = "NULL";
		p_num = "NULL";
	}
	Person(string name, int age, int sex, string adds, string p_num);

	void setinfo(string name, int age, int sex, string adds, string p_num);
	
protected:
	string name;
	int age;
	int sex;
	string adds;
	string p_num;
};
void Person::setinfo(string name, int age, int sex, string adds, string p_num)
{
	this->name = name;
	this->age = age;
	this->sex = sex;
	this->adds = adds;
	this->p_num = p_num;
}
Person::Person(string name, int age, int sex, string adds, string p_num)
{
	this->name = name;
	this->age = age;
	this->sex = sex;
	this->adds = adds;
	this->p_num = p_num;
}
class Teacher :virtual public Person {
public:
	void display();
	Teacher(string name, int age, int sex, string adds, string p_num,string title):Person(name,age,sex,adds,p_num),m_title(title){}
protected:
	string m_title;

};
void Teacher::display() {
	cout << "������ " << name << " ���䣺 " << age << " �Ա� " << ((sex == 0) ? " Ů" : " ��") << " ְ�ƣ� " << m_title << " ��ַ�� " << adds << " �绰�� " << p_num;
}
class Cadre : virtual public Person {
public:
	Cadre(string name, int age, int sex, string adds, string p_num, string post) :Person(name, age, sex, adds, p_num), m_post(post) {}

protected:
	string m_post;
};

class Teacher_Cadre : public Teacher, public Cadre {
public:
	void show();
	Teacher_Cadre(string name, int age, int sex, string adds, string p_num, string post,string title,float wages):Person(name,age,sex,adds,p_num),Teacher(name,age,sex,adds,p_num,title),Cadre(name,age,sex,adds,p_num,post),m_wages(wages){}
private:
	float m_wages;

};

void Teacher_Cadre::show() {
	display();
	cout << "ְ�� " << m_post << "���ʣ� " << m_wages << endl;
}
int main() {

	cout << "�������ʦ��ɲ������������䣬�Ա𣬵�ַ���绰��ְ�ƣ�ְ�񣬹��ʣ�" << endl;
	
	string name, adds, p_num, title,post;
	float wages;
	int age, sex;
	cout << "������" << endl;
	cin >> name;
	cout << "���䣺" << endl;
	cin >> age;
	cout << "�Ա�(0-Ů  ����-��)" << endl;
	cin >> sex;
	cout << "��ַ��" << endl;
	cin >> adds;
	cout << "�绰��" << endl;
	cin >> p_num;
	cout << "ְ�ƣ�" << endl;
	cin >> title;
	cout << "ְ��" << endl;
	cin >> post;
	cout << "���ʣ�" << endl;
	cin >> wages;

	Teacher_Cadre TC(name, age, sex, adds, p_num, post, title, wages);
	TC.show();
	system("pause");
	return 0;
}