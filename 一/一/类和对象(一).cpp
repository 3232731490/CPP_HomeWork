#include<iostream>
using namespace std;
class MyDate {
public:
	MyDate(){
		this->day = 1;
		this->year = 1970;
		this->month = 1;
	}
	void setDate();
	void plusOneDay();
	bool isLeap(int tyear);
	bool islegal(int tmonth ,int tday);
	void dispalyDate();
private:
	int day, month, year;
};
void MyDate::setDate()
{
	A:
	cout << "请输入时间：(年/月/日)" << endl;
	int year, month, day;
	cin >> year >> month >> day;
	if (month <= 0 || month>12 || day <= 0 || day>31)
	{
		system("cls");
		cout << "您输入的数据不合法" << endl;
		cout << "请检查后重新输入..." << endl;
		goto A;
	}
	if (month == 2) {
		if (isLeap(year)) {
			if (day <= 29)
			{
				this->day = day;
				this->month = month;
				this->year = year;
			}
			else {
				system("cls");
				cout << "您输入的数据不合法" << endl;
				cout << "请检查后重新输入..." << endl;
				goto A;
			}
		}
		else {
			if (day <= 28)
			{
				this->day = day;
				this->month = month;
				this->year = year;
			}
			else {
				system("cls");
				cout << "您输入的数据不合法" << endl;
				cout << "请检查后重新输入..." << endl;
				goto A;
			}
		}
	}else{
		if (islegal(month, day)) {
			this->day = day;
			this->month = month;
			this->year = year;
		}
		else {
			system("cls");
			cout << "您输入的数据不合法" << endl;
			cout << "请检查后重新输入..." << endl;
			goto A;
			}
	}
}
bool MyDate::isLeap(int tyear)
{
	if (tyear % 4 == 0 && tyear % 100 != 0 ||tyear%400==0){
		return true;
	}
	else {
		return false;
	}
}
bool MyDate::islegal(int tmonth ,int tday)
{
	switch (tmonth) {
		case 1:
		{
			if (tday <= 31){
				return true;
			}
			else {
				return false;
			}
		}
		case 3:
		{
			if (tday <= 31) {
				return true;
			}
			else {
				return false;
			}
		}
		case 4:
		{
			if (tday <= 30) {
				return true;
			}
			else {
				return false;
			}
		}
		case 5:
		{
			if (tday <= 31) {
				return true;
			}
			else {
				return false;
			}
		}
		case 6:
		{
			if (tday <= 30) {
				return true;
			}
			else {
				return false;
			}
		}
		case 7:
		{
			if (tday <= 31) {
				return true;
			}
			else {
				return false;
			}
		}case 8:
		{
			if (tday <= 31) {
				return true;
			}
			else {
				return false;
			}
		}
		case 9:
		{
			if (tday <= 30) {
				return true;
			}
			else {
				return false;
			}
		case 10:
		{
			if (tday <= 31) {
				return true;
			}
			else {
				return false;
			}
		}
		case 11:
		{
			if (tday <= 30) {
				return true;
			}
			else {
				return false;
			}
		}case 12:
		{
			if (tday <= 31) {
				return true;
			}
			else {
				return false;
			}
		}
		}
	}
}
void MyDate::dispalyDate() {
	cout << this->year << "/" << this->month << "/" << this->day<<endl;
}
void MyDate::plusOneDay() {
	if (this->month == 2)
	{
		if (isLeap(this->year)) {
			if (this->day + 1 > 29) {
				this->month++;
				this->day = 1;
			}
			else {
				this->day++;
			}
		}
		else {
			if (this->day + 1 > 28) {
				this->month++;
				this->day = 1;
			}
			else {
				this->day++;
			}
		}
	}
	else if(this->month==12){
		if (this->day + 1 > 31)
		{
			this->year++;
			this->month = 1;
			this->day = 1;
		}
		else {
			this->day++;
		}
	}
	else
	{
		if (islegal(this->month, this->day + 1))
		{
			this->day++;
		}
		else {
			this->month++;
			this->day = 1;
		}
	}
}
int main()
{
	MyDate D1;
	D1.setDate();
	D1.dispalyDate();
	D1.plusOneDay();
	D1.dispalyDate();
	system("pause");
	return 0;
}