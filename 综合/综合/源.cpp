#include<iostream>
#include<stack>
using namespace std;

class Calculator {
public:
	Calculator operator+(Calculator C) {
		Calculator c;
		c.real = this->real + C.real;
		return c;
	}
	Calculator operator-(Calculator C) {
		Calculator c;
		c.real = this->real - C.real;
		return c;
	}
	Calculator operator*(Calculator C) {
		Calculator c;
		c.real = this->real * C.real;
		return c;
	}
	Calculator operator/(Calculator C) {
		if (C.real == 0)
		{
			cout << "�������ֵ���Ϸ�" << endl;
			return *this;
		}
		Calculator c;
		c.real = this->real/ C.real;
		return c;
	}

	void caculation( string str)
	{
		Calculator conclusion;
		Calculator C1, C2;
		stack<double> S;
		int i = 0;
		while (str[i] != '\0')
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				S.push(str[i]-'0');
				i++;
			}
			else
			{
				double c1, c2;
				c1 = S.top();
				S.pop();
				c2 = S.top();
				S.pop();
				C1.set_real(c1);
				C2.set_real(c2);
				if (str[i] == '+')
				{
					conclusion = C1 + C2;
					S.push(conclusion.get_real());
				}
				else if (str[i] == '-')
				{
					conclusion = C2 - C1;
					S.push(conclusion.get_real());
				}
				else if (str[i] == '*')
				{
					conclusion = C1 * C2;
					S.push(conclusion.get_real());
				}
				else if (str[i] == '/')
				{
					conclusion = C2 / C1;
					S.push(conclusion.get_real());
				}
				i++;
			}
		}
		cout <<"������Ϊ�� "<< S.top() << endl;
	}
	void set_real(int real)
	{
		this->real = real;
	}
	void set_real(Calculator c)
	{
		this->real = c.get_real();
	}
	double get_real()
	{
		return real;
	}
private:
	double real;
};
int GetPriority(char c)
{
		switch (c)
		{
		case '#':
			return 0;
		case '(':
			return 1;
		case '+':
		case '-':
			return 3;
		case '*':
		case '/':
			return 5;
		case ')':
			return 6;
		default:
			return -1;
		}
	}
void InPut(char*& str)
{
	cout << "��������Ҫ����ı��ʽ:" << endl;
	while (1)
	{
		cin >> str;

		if (str[0]<='9'&&str[0]>='0')
		{
			break;
		}
		else
		{
			cout << "�������벻�Ϸ���:";
			delete[] str;
		}
	}
}

char * get_back()
{

	char* middle = new char[30];
	char* back = new char[30];
	char* backend = back;
	InPut(middle);
	stack<char> s;
	s.push('#');
	while (*middle)
	{
		if (*middle<='9' && *middle>= '0')
		{
			*back = *middle;
			back++, middle++;
		}
		else
		{
			
			if (*middle == ')')
			{
				while (s.top() != '(')
				{
					*back = s.top();
					s.pop();
					back++;
					
				}
				middle++;
				s.pop();
			}
			else if (*middle == '(')
			{
				s.push(*middle); middle++;
			}
			else if (GetPriority(*middle) > GetPriority(s.top()))
			{
				s.push(*middle); middle++;
			}
			else if (GetPriority(*middle) <= GetPriority(s.top()))
			{
				*back = s.top();

				s.pop();
				s.push(*middle);
				back++; middle++;
			}
		}
	}
	while (s.top() != '#')
	{
		*back = s.top();
		s.pop(); back++;
	}
	*back = '\0';
	return backend;

}
int main() {
	int choice;
	Calculator c1, c2,conclusion;
	conclusion.set_real(0);
	string str;
	while (1)
	{
		cout << "��ӭʹ�ñ�������" << endl;
		str = get_back();
		conclusion.caculation(str);
		cout << "��������Ҫ���������𣿣�Y/N��" << endl;
		char choice;
	A:	cin >> choice;
		if (choice == 'Y' || choice=='y')
		{
			continue;
		}
		else if(choice=='N'||choice=='n')
		{
			cout << "��ӭ�´�ʹ�ã�" << endl;
			return 0;
		}
		else
		{
			cout << "�����������" << endl;
			cout << "���������룡" << endl;
			goto A;
		}
	}
	system("pause");
	return 0;
}