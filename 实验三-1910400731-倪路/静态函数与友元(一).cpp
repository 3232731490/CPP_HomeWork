#include<iostream>
using namespace std;
#define Maxmize 100
class Student {
public:
	void scoretotalcount(float s);
	static float sum();
	static float average();
private:
	float score;  //����
	static float total;  //�ܷ�
	static int count;  //����
};
float Student::total = 0;
int Student::count = 0;
void Student::scoretotalcount(float s) {
	this->score = s;
	this->total += score;
	this->count++;
}
float Student::sum() {
	return Student::total;
}
float Student::average() {
	if (Student::count == 0)
		return 0;
	return Student::total / Student::count;
}
int main()
{
	cout << "�����������ڰ༶��������(������100)��" << endl;
	Student stu[Maxmize];
	int n;
	cin >> n;
	if (n > 100||n<=0)
	{
		cout << "��������������Ϸ�" << endl;
		return 0;
	}
	for (int i = 0; i < n ; i++)
	{
		cout << "�������" << (i + 1) << "��ѧ���ĳɼ���" << endl;
		float score;
		cin >> score;
		stu[i].scoretotalcount(score);
	}
	cout << "�ð��ܳɼ�Ϊ��" << Student::sum() << endl;
	cout << "�ð�ƽ����Ϊ��" << Student::average() << endl;

	system("pause");
	return 0;
}