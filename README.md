# ����������

� ������ ��������� �������� �������  
*template\< class T\>  
void qsort(vector\<T\> & data, int left, int right, function\<bool(T, T)\> compare)* , ���  
*data* - ������ ������������ ������� (� ����� ������ *vector\<Student\>*, � ������ ���������� �������� ��������� �� ������),  
*left* - ��������� ������,  
*right* - �������� ������,  
*comparator* - ������� �������, ����������� �������� 2 ��������, ��� ������-���������.  
*qsort* ���������� �������� ������� �����������.

������ 1 (���������� ��������� �� ������):
```C++
qsort<Student>(students, 0, students.size() - 1, [](Student a, Student b) -> bool { return (a <= b); });
```

���� (�������, ������):  
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

�����:  
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


������ 2 (���������� ������� ����� �����):
```C++
qsort<int>(v, 0, v.size() - 1, [](int a, int b) -> bool { return (a <= b); });
```

����:  
1 -7 2 3 5 4 -8

�����:  
-8 -7 1 2 3 4 5
