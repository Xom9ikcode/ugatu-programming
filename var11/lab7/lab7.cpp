#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <Math.h>
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

/** ������� � ������������� ����������� */
void functionDefaultParameters(int x1 = 4, int y1 = 3, int x2 = 5, int y2 = 7) {
    cout<<">>functionDefaultParameters"<<endl;

    float dl = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout<<"dl="<<dl;
}

/** ������� � ���������� ������ ����������, ����� �������� */
int variableFunction(int k, ...) {
     cout<<"Function this variable parameters"<<endl;

     int min = k;
     int* p = &k;
     while (*p != 0) { //���� ������������ ���� �� �������� ������� = 0
           p++;
           if (*p < min) min = *p;
           //cout<<"min="<<min<<endl; //��� �������
     }

     return min;
}

/** ���������� ������� */
template<class T>
void printArray(T a[], int n) {
  cout<<">>Print array"<<endl;

   for(int i=0; i<n; i++) {
      cout<<a[i]<<endl;
   }
}

/** �������� �������� � �������� ������ �� ������������� ������� ��� int */
int* deleteRowById(int* array, int n, int id) {
       cout<<">>Delete row by id (int)"<<endl;

       if (n == 0) {
           cout<<"Array is empty!";
           return array;
       }

       int* a = new int[n];
       int curRow = 0;

       for (int i=0; i<n; i++) {
           if (i != id) {
               a[curRow] = array[i];
               curRow++;
           }
       }
       n = curRow;

       printArray(a, n);

       return a;
}

/** �������� �������� � �������� ������ �� ������������� ������� ��� float */
float* deleteRowById(float* array, int n, int id) {
       cout<<">>Delete row by id (float)"<<endl;

       if (n == 0) {
           cout<<"Array is empty!";
           return array;
       }

       float* a = new float[n];
       int curRow = 0;

       for (int i=0; i<n; i++) {
           if (i != id) {
               a[curRow] = array[i];
               curRow++;
           }
       }
       n = curRow;

       printArray(a, n);

       return a;
}

/** ������ ������� ��� �������� ��������� �������� �� ������� */
template<class T>
T* minInArrayTemplate(T* array, int n, int id) {
    cout<<"Template function"<<endl;

    if (n == 0) {
       cout<<"Array is empty!";
       return array;
   }

   T* a = new T[n];
   int curRow = 0;

   for (int i=0; i<n; i++) {
       if (i != id) {
           a[curRow] = array[i];
           curRow++;
       }
   }
   n = curRow;

   printArray(a, n);

   return a;
}

typedef float(*fptr)(float);//���-��������� �� ������� ���������
typedef float(*fptr2args)(float, bool);//���-��������� �� ������� ��������� c 2 �����������

float methodNewton(fptr2args f, float a, float b, float e); //��������� ��� ������� � ����� (transfer.cpp)
float var11Func(float x, bool proizvod); //��������� ��� ������� � ����� (transfer.cpp)

/** ������� ����������� ������� */
int main(int argc, char *argv[]) {
    int k;
    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Function default parameters"<<endl;
        cout<<"2. Function default parameters 2"<<endl;
        cout<<"3. Function default parameters 3"<<endl;
        cout<<"4. Function this variable parameters"<<endl;
        cout<<"5. Overloaded & template function"<<endl;
        cout<<"6. Transfer function"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            //������ �����. � �����. ����������� (��� ��������� ������� ����)
            case 1: functionDefaultParameters(9,2,6,8); break;
            //������ �����. � �����. ����������� (����� ���������� ������� ����)
            case 2: functionDefaultParameters(4,6,2); break;
            //������ �����. � �����. ����������� (��������� �� �������)
            case 3: functionDefaultParameters(); break;
            //������ �����. � ���������� ������ ����������
            case 4: cout<<"min: "<<variableFunction(4, 3, -12, 8, -1, 20, 0)<<endl; break;
            //������������� ������� � ������ �������
            case 5: {
                 int k;
                 cout<<"Enter k: ";
                 cin>>k;

                 int a[] = {-11, 92, -58, 23, 91, 912};
                 int n = 6;
                 deleteRowById(a, n, k-1); //������ ������������� ������� ��� int
                 minInArrayTemplate(a, n, k-1); //������ ��������� ������� ��� int
                 cout<<endl;

                 float f[] = {43.23, -23.1, -58.21, 34.34, -91.2, 912.3};
                 n = 6;
                 deleteRowById(f, n, k-1); //������ ������������� ������� ��� float
                 minInArrayTemplate(f, n, k-1); //������ ��������� ������� ��� float

                 break;
            }
            //�������� ������� ��� ��������� ������ ������� � ������� ���������
            case 6:
                 float res = 0;
                 res = methodNewton(var11Func, 1, 2, 0.0001);
                 break;
        }
    } while (k!=7);//�����
}
