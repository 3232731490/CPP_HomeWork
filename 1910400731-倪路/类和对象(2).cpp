#include<iostream>
using namespace std;
#define maximum 100
class Student {
public:
	Student() {}
	Student(string name ,int no) {
		this->grade = 0;
		this->score = 0;
		this->name = name;
		this->no = no;
	}
	void Show() {
		cout <<"姓名： "<<this->name<<"学号： "<<this->no<< "总学分： " << score << "平均成绩： " << grade<<endl;
	}
	int getno()
	{
		return this->no;
	}
	void set(float score, float grade) {
		this->score = score;
		this->grade = grade;
	}
private:
	string name;
	int no;
	float score;
	float grade;
};
class Class {
public:
	Class(int stunum, Student *stu)
	{
		for (int i = 0; i < stunum; i++)
		{
			this->stu[i] = stu[i];
		}
		this->stunum = stunum;
	}
	void ShowStudentMessage();
	
	void Find(int no);
	
	void addStudent();
	
	void fillMessage();
	
	void modifyMessage();
	
private :
	Student stu[maximum];
	int stunum;
};
void Class::ShowStudentMessage() {
	for (int i = 0; i < this->stunum; i++) {
		this->stu[i].Show();
	}
}
void Class::Find(int no) {
	int i = 0;
	for (; i < this->stunum; i++)
	{
		if (this->stu[i].getno() == no)
		{
			this->stu[i].Show();
			break;
		}
	}
	if (i >= this->stunum)
	{
		cout << "未找到该学生..." << endl;
	}
}
void Class::addStudent()
{
	cout << "您想添加几个学生信息？" << endl;
	int n;
	cin >> n;
	string name;
	int no;
	float score;
	float grade;
	for (int i = 0; i < n; i++)
	{
		if (this->stunum >= maximum)
		{
			cout << "该班级已经满员..." << endl;
			return;
		}
		cout << "请依次输入学生姓名、学号";
		cin >> name >> no;
		Student s(name, no);
		this->stu[this->stunum] = s;
		this->stunum++;
	}
}
void Class::fillMessage() {
	cout << "请输入您要添加信息的学生学号：" << endl;
	int no;
	cin >> no;
	int i = 0;
	for (; i < this->stunum; i++)
	{
		if (this->stu[i].getno() == no)
		{
			cout << "请输入该学生的学分和平均成绩：" << endl;
			float score, grade;
			cin >> score >> grade;
			this->stu[i].set(score, grade);
			break;
		}
	}
	if (i >= this->stunum)
	{
		cout << "未找到该学生..." << endl;
	}
}
void Class::modifyMessage() {
	cout << "请输入您要修改信息的学生学号：" << endl;
	int no;
	cin >> no;
	int i = 0;
	for (; i < this->stunum; i++)
	{
		if (this->stu[i].getno() == no)
		{
			cout << "请输入修改后的该学生的学分和平均成绩：" << endl;
			float score, grade;
			cin >> score >> grade;
			this->stu[i].set(score, grade);
			break;
		}
	}
	if (i >= this->stunum)
	{
		cout << "未找到该学生..." << endl;
	}
}

int main()
{
	Student S[maximum];
	cout << "初始化班级信息..." << endl;
	cout << "请输入班级的学生总数：" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "请输入第" << i + 1 << "个学生姓名和学号";
		string name;
		int no;
		cin >> name >> no;
		Student ts(name, no);
		S[i] = ts;
	}
	Class C1(3, S);
	cout << "初始化完毕！" << endl;
	system("pause");
	system("cls");
	while (1) {
		cout << "请选择您要进行的操作：" << endl;
		cout << "1、显示学生信息" << endl;
		cout << "2、查找学生信息" << endl;
		cout << "3、增加学生信息" << endl;
		cout << "4、添加学生信息" << endl;
		cout << "5、修改学生信息" << endl;
		cout << "0、退出系统" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1: {
			C1.ShowStudentMessage();
			system("pause");
			system("cls");
			break;
		}
		case 2: {
			int no;
			cout << "输入您要查找的学生学号：" << endl;
			cin >> no;
			C1.Find(no);
			system("pause");
			system("cls");
			break;
		}
		case 3: {
			C1.addStudent();
			system("pause");
			system("cls");
			break;
		}
		case 4: {
			C1.fillMessage();
			system("pause");
			system("cls");
			break;
		}
		case 5: {
			C1.modifyMessage();
			system("pause");
			system("cls");
			break;
		}
		case 0:
		{
			cout << "欢迎您的下次使用..." << endl;
			return 0;
		}
		default: {
			cout << "您的输入有误，请重新输入..." << endl;
			system("pause");
			system("cls");
		}
		}
	}
	system("pause");
	return 0;
}
