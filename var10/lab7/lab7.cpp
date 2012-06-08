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
5. +������ ��������� ��������� � �������� �������. ��������� �������� � ������� ��� �������� � ������� ���������.


+������� � ������������� �����������
+������� � ���������� ������ ����������
+������������� ������� � ������ �������
+�������� ������� ��� ��������� ������ ������� � ������� ���������

*/

using namespace std;

/** ������� � ������������� ����������� */
void functionDefaultParameters(int x1 = 5, int y1 = 5) {
    cout<<">>functionDefaultParameters"<<endl;

    float dl = sqrt(pow(0 - x1, 2) + pow(0 - y1, 2));
    cout<<"dl="<<dl;
}

/** ������� � ���������� ������ ����������, ������� �������������� �� ��������� � ������ ����������, ������� �� �������� ������ */
float variableFunction(int k, ...) {
     cout<<"Function this variable parameters"<<endl;

     int count = 0, countChet = 0;
     int sum = 0;
     int* p = &k;
     while (*p != 0) { //���� ������������ ���� �� �������� ������� = 0
        count++;
        if (count % 2 == 1) {
            countChet++;
            sum += *p;
            cout<<"p="<<*p<<endl;
        }
        p++;
     }
     cout<<"sum="<<sum<<"; count="<<countChet<<endl;

     return (float)sum / countChet;
}

/** ���������� ������� */
template<class T>
void printArray(T a[], int n) {
  if (false) cout<<">>Print array"<<endl;

   for(int i=0; i<n; i++) {
      cout<<a[i]<<"; ";
   }
   cout<<endl;
}

/** �������� �������� � �������� ������� �� ������������� ������� ��� int */
int* deleteRowById(int* array, int n, int id) {
       cout<<">>Peregrujenaya func (int)"<<endl;

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

/** �������� �������� � �������� ������� �� ������������� ������� ��� float */
float* deleteRowById(float* array, int n, int id) {
       cout<<">>Peregrujenaya func (float)"<<endl;

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
T* deleteElTemplate(T* array, int n, int id) {
    cout<<">>Shablon func"<<endl;

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

typedef float(*fptr)(float, bool);//���-��������� �� ������� ���������

float methodIterator(fptr f, float a, float b, float e); //��������� ��� ������� � ����� (transfer.cpp)
float methodBisection(fptr f, float a, float b, float e); //��������� ��� ������� � ����� (transfer.cpp)
float var10Func(float x, bool std); //��������� ��� ������� � ����� (transfer.cpp)

/** ������� ����������� ������� */
int main(int argc, char *argv[]) {
    int k;
    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Func umalch parameters"<<endl;
        cout<<"2. Func umalch parameters 2"<<endl;
        cout<<"3. Func umalch parameters 3"<<endl;
        cout<<"4. Func s peremen chislom parametrov"<<endl;
        cout<<"5. Peregrujenaya func"<<endl;
        cout<<"6. Peredacha func kak parametra"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            //������ �����. � �����. ����������� (��� ��������� ������� ����)
            case 1: functionDefaultParameters(4, 6); break;
            //������ �����. � �����. ����������� (����� ���������� ������� ����)
            case 2: functionDefaultParameters(4); break;
            //������ �����. � �����. ����������� (��������� �� �������)
            case 3: functionDefaultParameters(); break;
            //������ �����. � ���������� ������ ����������
            case 4: cout<<"Sr: "<<variableFunction(4, 3, -12, 8, -1, 20, 0)<<endl; break;
            //������������� ������� � ������ �������
            case 5: {
                 int k;
                 cout<<"Enter k: ";
                 cin>>k;

                 int a[] = {-11, 92, -58, 23, 91, 912};
                 int n = 6;
                 cout<<"Nachalnii massiv:"<<endl;
                 printArray(a, n);

                 deleteRowById(a, n, k-1); //������ ������������� ������� ��� int
                 deleteElTemplate(a, n, k-1); //������ ��������� ������� ��� int
                 cout<<endl;

                 float f[] = {43.23, -23.1, -58.21, 34.34, -91.2, 912.3};
                 n = 6;
                 cout<<"Nachalnii massiv:"<<endl;
                 printArray(f, n);

                 deleteRowById(f, n, k-1); //������ ������������� ������� ��� float
                 deleteElTemplate(f, n, k-1); //������ ��������� ������� ��� float

                 break;
            }
            //�������� ������� ��� ��������� ������ ������� � ������� ���������
            case 6:
                 float res = methodIterator(var10Func, 1, 2, 0.0001);
                 cout<<"x="<<res<<endl;
                 res = methodBisection(var10Func, 1, 2, 0.0001);
                 cout<<"x="<<res<<endl;
                 break;
        }
    } while (k!=7);//�����
}
