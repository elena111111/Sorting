#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <ctime>

using namespace std;

class Student {
private:
	string name = "";
	int mark = 0;
public:
	Student(string newName, int newMark) {
		name = newName;
		mark = newMark;
	}

	const string getName() {
		return name;
	}

	const int getMark() {
		return mark;
	}

	bool operator<= (Student &st) { 
		return mark <= st.mark; 
	}
};


template <class T>
int partition(vector<T>& a, int left, int right, function<bool(T, T)> compare) {
	T x = a[right];	//элемент, с которым будем сравнивать все остальные
	int i = left - 1;
	for (int j = left; j < right; ++j) {
		if (compare(a[j], x)) {
			++i;
			T tmp = a[j]; a[j] = a[i]; a[i] = tmp;
		}
	}
	T tmp = a[i + 1]; a[i + 1] = a[right]; a[right] = tmp;
	return i + 1;
}

template <class T>
void qsort(vector<T>& a, int left, int right, function<bool(T, T)> compare) {
	if (left < right) {	//индексы
		int q = partition(a, left, right, compare);	//элементы слева <= a[q] <= элементы справа
		qsort(a, left, q - 1, compare);
		qsort(a, q + 1, right, compare);
	}
}

template <class T>
bool compare(T a, T b) {
	return (a <= b);
}

int main() {
	vector<Student> students;
	int N = 10;
	//случайно заполним исходные данные
	srand(time(0));
	for (int i = 0; i < N; ++i) {
		char name[2] = { (char)('A' + rand() % ('Z' - 'A')) };
		name[1] = '\0';
		int mark = 1 + rand() % 10;
		students.push_back(Student(name, mark));
	}
	for (int i = 0; i < students.size(); ++i) {
		cout << students[i].getName() << " " << students[i].getMark() << endl;
	}
	cout << endl;

	//qsort<Student>(students, 0, students.size() - 1, compare<Student>);
	qsort<Student>(students, 0, students.size() - 1, [](Student a, Student b) -> bool { return (a <= b); });
	for (int i = 0; i < students.size(); ++i) {
		cout << students[i].getName() << " " << students[i].getMark() << endl;
	}
	cout << endl;

	vector<int> v = { 1, -7, 2, 3, 5, 4, -8 };
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	//qsort<int>(v, 0, v.size() - 1, compare<int>);
	qsort<int>(v, 0, v.size() - 1, [](int a, int b) -> bool { return (a <= b); });
	for (int i = 0; i < v.size(); ++i) {
		cout << v[i] << " ";
	}
	cout << endl;
	return 0;
}
