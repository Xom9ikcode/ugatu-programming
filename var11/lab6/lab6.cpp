/*
1.	+������������ ������������ ������ �� ��������� ������������ ����. ����������� ��� ��������� � ��������.
2.	+����������� �������������� ������.
3.	+��������� ����� ��������� � �������, ��������������� ��������� � �������� ������� � ������������ �� ��� ����� ������.
4.	+����������� ���������� ������.
5.	+������������ ������������ ������, ��������� �� ������������ �����.
6.	+����������� �������������� ������.
7.	+��������� ��������� ����� �������.
8.	+����������� ���������� ������.

struct person
{
char*name;
int age;
}


+������� ������ 18

+������� ������ � ������� �

*/


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string.h>

using namespace std;

/** ��������� */
struct Person {
    char name[50];
    int age;
};

/** ������������ ������� �������� */
Person* formedListStructure(int n) {
         cout<<">>Formed array structure type"<<endl;

         srand(time(0));
         Person* personList = new Person[n];
         for(int i=0;i<n;i++) {
             sprintf(personList[i].name, "Name%d", i);
             personList[i].age = rand() % 30;
         }

         return personList;
}

/** ������ ��������� */
void printPerson(Person e) {
     cout<<"name: "<<e.name<<"; age="<<e.age<<endl;
}

/** ������ ������ �������� */
void printListStructure(Person* personList, int n) {
     cout<<">>Print array structure"<<endl;

     if (n == 0) {
           cout<<"Array is empty!";
     }

     for(int i=0;i<n;i++) {
          printPerson(personList[i]);
     }
}

/** ����� ����� � ������� ������� < 18 ��� */
void findPerson(Person* e, int n, int age) {
     cout<<">>Find person where age < "<<age<<""<<endl;

     if (n == 0) {
           cout<<"Array is empty!";
     }

     for(int i=0;i<n;i++) {
             if (e[i].age < age) {
                printPerson(e[i]);
             }
     }
}

/** ������������ ������������� �������, ������������ ����� */
char** formedDynArrayDynStrings(int n) {
       cout<<">>Formed dyn array dyn strings"<<endl;

       char** array = new char*[n];
       for(int i=0;i<n;i++) {
               array[i] = new char[20];
               sprintf(array[i], "DynString-%d", rand()%50);
       }

       return array;
}

/** ������ ������������� �������, ������������ ����� */
void printDynArrayDynStrings(char** array, int n) {
     cout<<">>Print dyn array dyn strings"<<endl;

     if (n == 0) {
           cout<<"Array is empty!";
     }

     for(int i=0;i<n;i++) {
             cout<<i+1<<": "<<array[i]<<endl;
     }
}

/** �������� ������ � �������� ������� �� ������������� ������� ����� */
char** deleteRowById(char** array, int* n, int id) {
       cout<<">>Delete row by id"<<endl;

       if (*n == 0) {
           cout<<"Array is empty!";
           return array;
       }

       char** a = new char*[20];
       int curRow = 0;

       for (int i=0; i<*n; i++) {
           if (i != id) {
               a[curRow] = new char[20];
               strcpy(a[curRow], array[i]);
               curRow++;
           }
       }

       *n = curRow;
       return a;
}

int main(int argc, char *argv[]) {
    int k;
    int nStructure = 0, nDynArray = 0;
    const int age = 18;
    Person* personList;
    char** array;

    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Formed array structure type"<<endl;
        cout<<"2. Print array structure"<<endl;
        cout<<"3. Find person where age < "<<age<<endl;
        cout<<"4. Formed dyn array dyn strings"<<endl;
        cout<<"5. Print dyn array dyn strings"<<endl;
        cout<<"6. Delete string from dyn array dyn strings"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            case 1: //������������ ������ ��������
                nStructure = 10;
                personList = formedListStructure(nStructure);
                break;
            case 2: //���������� ������ ��������
                printListStructure(personList, nStructure);
                break;
            case 3: //����� � ������ �������� ����� � ��������� ����� 18 ���
                findPerson(personList, nStructure, age);
                break;
            case 4: //������������ ������������� �������, ������������ �����
                nDynArray = 10;
                array = formedDynArrayDynStrings(nDynArray);
                break;
            case 5: //������ ������������� �������, ������������ �����
                printDynArrayDynStrings(array, nDynArray);
                break;
            case 6: //�������� ������ � �������� ������� �� ������������� ������� �����
                int k;
                cout<<"Enter k: ";
                cin>>k;
// TODO (sdoronin#1#): ������ �� ��������� ��������� �������
                array = deleteRowById(array, &nDynArray, k-1);
                break;
        }
    } while (k!=7);//�����
}
