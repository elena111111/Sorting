#Сортировка

В данной программе написана функция 

*template <class T>
void qsort(vector<T>& a, int left, int right, function<bool(T, T)> compare)* , где

*data* - данные произвольной природы (в нашем случае *vector \< Student \> *, в классе определена операция сравнения по оценке),

*left* - начальный индекс,
*right* - конечный индекс,

*comparator* - булевая функция, позволяющая сравнить 2 элемента, или лямбда-выражение.

*qsort* использует алгоритм быстрой сортироовки.

Пример работы програмы (сортировка студентов по оценке):
```C++
qsort<Student>(students, 0, students.size() - 1, [](Student a, Student b) -> bool { return (a <= b); });
```

Вход (фамилия, оценка):
S 4
X 8
P 4
E 10
B 6
Y 3
C 4
C 3
U 6
K 7

Выход:
Y 3
C 3
S 4
C 4
P 4
B 6
U 6
K 7
X 8
E 10