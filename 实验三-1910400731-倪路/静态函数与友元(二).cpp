#include<iostream>
using namespace std;
class Ruler;
class Book {

public:
	float totalWeight(Ruler &R);
	Book(float w)
	{
		weight = w;
	}
private:
	float weight;
};
class Ruler {
	friend float Book::totalWeight(Ruler &r);
public:
	Ruler(float w)
	{
		weight = w;
	}
private:
	float weight;
};
float Book::totalWeight(Ruler &r) {
	return this->weight + r.weight;
}
int main() {
	cout << "请输入 Book 的weight：" << endl;
	float w1;
	cin >> w1;
	cout << "请输入 Ruler 的weight：" << endl;
	float w2;
	cin >> w2;

	Book b(w1);
	Ruler r(w2);

	float total=b.totalWeight(r);
	cout << "Book & Ruler 总重量：" << total << endl;
	system("pause");
	return 0;
}