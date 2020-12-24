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
	cout << "姓名： " << name << " 年龄： " << age << " 性别： " << ((sex == 0) ? " 女" : " 男") << " 职称： " << m_title << " 地址： " << adds << " 电话： " << p_num;
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
	cout << "职务： " << m_post << "工资： " << m_wages << endl;
}
int main() {

	cout << "请输入教师兼干部的姓名，年龄，性别，地址，电话，职称，职务，工资：" << endl;
	
	string name, adds, p_num, title,post;
	float wages;
	int age, sex;
	cout << "姓名：" << endl;
	cin >> name;
	cout << "年龄：" << endl;
	cin >> age;
	cout << "性别：(0-女  其他-男)" << endl;
	cin >> sex;
	cout << "地址：" << endl;
	cin >> adds;
	cout << "电话：" << endl;
	cin >> p_num;
	cout << "职称：" << endl;
	cin >> title;
	cout << "职务：" << endl;
	cin >> post;
	cout << "工资：" << endl;
	cin >> wages;

	Teacher_Cadre TC(name, age, sex, adds, p_num, post, title, wages);
	TC.show();
	system("pause");
	return 0;
}