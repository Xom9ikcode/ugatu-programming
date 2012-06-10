#include <cstdlib>
#include <iostream>
#include <stdio.h>
/*
+1.�������� ������� � ������������� ����������� � ������������ � ���������, ������������������ ��������� ������� ������ �������:
	+� ����������� ��������� ����,
	+� ���������� �����������
	+����� ���������� ������ ����, � ����� �������.
2. +�������� ������� � ���������� ������ ���������� � ������������ � ���������, ������������������ ����� ������� � ��������� ������ ����������.
3. +�������� ������������� ������� � ������������ � ���������. �������� ���������������� ��������� ��� ������ ���� �������.
4. +�������� ������ ������� ������ ������������� ������� �� ������� 3. �������� ���������������� ��������� ��� ������ ���� �������. ������ ����������
5. ������ ��������� ��������� � �������� �������. ��������� �������� � ������� ��� �������� � ������� ���������.


+������� � ������������� �����������
+������� � ���������� ������ ����������
+������������� ������� � ������ �������
+�������� ������� ��� ��������� ������ ������� � ������� ���������


+������ �������, ����� � ��������
+������� �������������� ��������� � ������ ����������
+����������� ������� � �������
����� ��������
0,25x3 + x - 1,2502 = 0
�������, ���������� ������: [0;2]
������ ��������: 1,0001

*/

using namespace std;

void functionDefaultParameters(char* surname = "Default surname", char* name = "Default name", int ratio = 50) {
     cout<<">>functionDefaultParameters"<<endl;

     cout<<"surname: "<<surname<<"; name: "<<name<<"; ratio="<<ratio;
}

int variableFunction(int k, ...) {
     cout<<"Function this variable parameters"<<endl;

     int* p = &k;
     int sum = 0;
     int count = 0;
     while (*p != 0) {
           count++;
           //cout<<"count="<<count<<endl; //��� �������
           sum += *(p++);
           //cout<<"sum="<<sum<<endl; //��� �������
     }

     return sum / count;
}

int minInArray(int a[], int n) {
    cout<<"Overloaded function int"<<endl;

    int min = 0;
    for (int i=1;i<n;i++) {
        if (a[i] < a[min]) {
                 min = i;
        }
    }

    return a[min];
}

float minInArray(float a[], int n) {
    cout<<"Overloaded function float"<<endl;

    int min = 0;
    for (int i=1;i<n;i++) {
        if (a[i] < a[min]) {
                 min = i;
        }
    }

    return a[min];
}

template<class T>
T minInArrayTemplate(T a[], int n) {
  cout<<"Template function"<<endl;

    int min = 0;
    for (int i=1;i<n;i++) {
        if (a[i] < a[min]) {
                 min = i;
        }
    }

    return a[min];
}

typedef float(*fptr)(float);//���-��������� �� ������� ���������

float methodBisection(fptr f, float a, float b, float e);
float methodIterator(fptr f, float a, float b, float e);
float methodIteratorMy(fptr f, float a, float b, float e);
float testf(float x);
float myFunc(float x);


int main(int argc, char *argv[]) {
    int k;
    do {
        cout<<"\n=======================\n";
        cout<<"1. Function default parameters\n";
        cout<<"2. Function default parameters 2\n";
        cout<<"3. Function default parameters 3\n";
        cout<<"4. Function this variable parameters\n";
        cout<<"5. Overloaded & template function\n";
        cout<<"6. Transfer function\n";
        cout<<"7. Exit\n";
        cout<<"=======================\n";
        cin>>k;
        switch (k) {
            case 1: functionDefaultParameters("Urmanov", "Ibragim", 22); break;
            case 2: functionDefaultParameters("Kozlyatkin", "Stepan"); break;
            case 3: functionDefaultParameters(); break;
            case 4: cout<<"avg: "<<variableFunction(4, 3, 8, 0)<<endl; break;
            case 5: {
                 int a[] = {-11, 92, -58, 23, 91, 912};
                 cout<<"min: "<<minInArray(a, 6)<<endl;
                 cout<<"min: "<<minInArrayTemplate(a, 6)<<endl;
                 cout<<endl;

                 float f[] = {43.23, -23.1, -58.21, 34.34, -91.2, 912.3};
                 cout<<"min: "<<minInArray(f, 6)<<endl;
                 cout<<"min: "<<minInArrayTemplate(f, 6)<<endl;

                 break;
            }
            case 6:
                 float res = 0;
                 res = methodIterator(myFunc, 0, 2, 0.0001);
                 methodIteratorMy(myFunc, 0, 2, 0.0001);
                 methodBisection(myFunc, 0, 2, 0.0001);
                 if (res == 777) {
                    cout<<"X Not found!";
                 } else {
                   printf("x=%.10f\t y=%.5f\n", res, myFunc(res));
                 }
                 break;
        }
    } while (k!=7);//�����
}
