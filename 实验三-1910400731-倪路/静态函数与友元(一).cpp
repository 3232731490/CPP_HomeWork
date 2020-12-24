#include<iostream>
using namespace std;
#define Maxmize 100
class Student {
public:
	void scoretotalcount(float s);
	static float sum();
	static float average();
private:
	float score;  //分数
	static float total;  //总分
	static int count;  //人数
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
	cout << "请输入您所在班级的总人数(不多于100)：" << endl;
	Student stu[Maxmize];
	int n;
	cin >> n;
	if (n > 100||n<=0)
	{
		cout << "您输入的人数不合法" << endl;
		return 0;
	}
	for (int i = 0; i < n ; i++)
	{
		cout << "请输入第" << (i + 1) << "个学生的成绩：" << endl;
		float score;
		cin >> score;
		stu[i].scoretotalcount(score);
	}
	cout << "该班总成绩为：" << Student::sum() << endl;
	cout << "该班平均分为：" << Student::average() << endl;

	system("pause");
	return 0;
}