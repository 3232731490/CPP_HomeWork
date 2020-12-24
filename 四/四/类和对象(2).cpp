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
		cout <<"������ "<<this->name<<"ѧ�ţ� "<<this->no<< "��ѧ�֣� " << score << "ƽ���ɼ��� " << grade<<endl;
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
		cout << "δ�ҵ���ѧ��..." << endl;
	}
}
void Class::addStudent()
{
	cout << "������Ӽ���ѧ����Ϣ��" << endl;
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
			cout << "�ð༶�Ѿ���Ա..." << endl;
			return;
		}
		cout << "����������ѧ��������ѧ��";
		cin >> name >> no;
		Student s(name, no);
		this->stu[this->stunum] = s;
		this->stunum++;
	}
}
void Class::fillMessage() {
	cout << "��������Ҫ�����Ϣ��ѧ��ѧ�ţ�" << endl;
	int no;
	cin >> no;
	int i = 0;
	for (; i < this->stunum; i++)
	{
		if (this->stu[i].getno() == no)
		{
			cout << "�������ѧ����ѧ�ֺ�ƽ���ɼ���" << endl;
			float score, grade;
			cin >> score >> grade;
			this->stu[i].set(score, grade);
			break;
		}
	}
	if (i >= this->stunum)
	{
		cout << "δ�ҵ���ѧ��..." << endl;
	}
}
void Class::modifyMessage() {
	cout << "��������Ҫ�޸���Ϣ��ѧ��ѧ�ţ�" << endl;
	int no;
	cin >> no;
	int i = 0;
	for (; i < this->stunum; i++)
	{
		if (this->stu[i].getno() == no)
		{
			cout << "�������޸ĺ�ĸ�ѧ����ѧ�ֺ�ƽ���ɼ���" << endl;
			float score, grade;
			cin >> score >> grade;
			this->stu[i].set(score, grade);
			break;
		}
	}
	if (i >= this->stunum)
	{
		cout << "δ�ҵ���ѧ��..." << endl;
	}
}

int main()
{
	Student S[maximum];
	cout << "��ʼ���༶��Ϣ..." << endl;
	cout << "������༶��ѧ��������" << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "�������" << i + 1 << "��ѧ��������ѧ��";
		string name;
		int no;
		cin >> name >> no;
		Student ts(name, no);
		S[i] = ts;
	}
	Class C1(3, S);
	cout << "��ʼ����ϣ�" << endl;
	system("pause");
	system("cls");
	while (1) {
		cout << "��ѡ����Ҫ���еĲ�����" << endl;
		cout << "1����ʾѧ����Ϣ" << endl;
		cout << "2������ѧ����Ϣ" << endl;
		cout << "3������ѧ����Ϣ" << endl;
		cout << "4�����ѧ����Ϣ" << endl;
		cout << "5���޸�ѧ����Ϣ" << endl;
		cout << "0���˳�ϵͳ" << endl;
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
			cout << "������Ҫ���ҵ�ѧ��ѧ�ţ�" << endl;
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
			cout << "��ӭ�����´�ʹ��..." << endl;
			return 0;
		}
		default: {
			cout << "����������������������..." << endl;
			system("pause");
			system("cls");
		}
		}
	}
	system("pause");
	return 0;
}
