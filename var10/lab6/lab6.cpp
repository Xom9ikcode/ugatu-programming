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
float rating
}


+�������, � ������� ������� �������

+������� � ����� �� ������ �������

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
    float rating;
};

/** ������������ ������� �������� */
Person* formedListStructure(int n) {
         cout<<">>Formed array structure type"<<endl;

         srand(time(0));
         Person* personList = new Person[n];
         for(int i=0;i<n;i++) {
             if (rand() % 3 == 0) {
                 strcpy(personList[i].name, "Ivanov");
             } else {
                sprintf(personList[i].name, "Name%d", i);
             }
             personList[i].age = rand() % 30;
             personList[i].rating = (float)(rand() % 100) / 100;
         }

         return personList;
}

/** ������ ��������� */
void printPerson(Person e) {
     cout<<"name: "<<e.name<<"; age="<<e.age<<";\traiting="<<e.rating<<endl;
}

/** ������ ������ �������� */
void printListStructure(Person* personList, int n) {
     cout<<">>Print array structure"<<endl;

     if (n == 0) {
           cout<<"Array is empty!"<<endl;
     }

     for(int i=0;i<n;i++) {
          printPerson(personList[i]);
     }
}

/** ����� �������� � ������� ������� �Ivanov� */
void findPerson(Person* e, int n) {
     cout<<">>Poisk uchenikov s fam Ivanov"<<endl;

     if (n == 0) {
           cout<<"Array is empty!"<<endl;
     }

     for(int i=0;i<n;i++) {
             if (strcmp(e[i].name, "Ivanov") == 0) {
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

/** �������� K ����� �� ������ ������� */
char** deleteRows(char** array, int* n, int k) {
       cout<<">>Udalenie strok iz nachala massiva"<<endl;

       if (*n == 0) {
           cout<<"Array is empty!"<<endl;
           return array;
       }
       if (k > *n) {
           cout<<"K > N"<<endl;
           return array;
       }

       for (int i=0; i<*n-k; i++) {
           strcpy(array[i], array[i+k]);
       }

       *n -= k;
       return array;
}

/** ������� ����������� ������� */
int main(int argc, char *argv[]) {

    cout << "Var 10 Lab 6" << endl;

    int k;
    int nStructure = 0, nDynArray = 0;
    const int age = 18;
    Person* personList;
    char** array;

    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Formirovanit massiva struktur"<<endl;
        cout<<"2. Vivod massiva struktur"<<endl;
        cout<<"3. Poisk Ivanovih"<<endl;
        cout<<"4. Formirovanit dinamich massiva strok"<<endl;
        cout<<"5. Vivod dinamich massiva strok"<<endl;
        cout<<"6. Udalenie strok iz nachala massiva"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            case 1: //������������ ������ ��������
                nStructure = 10;
                personList = formedListStructure(nStructure);
                printListStructure(personList, nStructure);
                break;
            case 2: //���������� ������ ��������
                printListStructure(personList, nStructure);
                break;
            case 3: //����� �������� � ������� ������� �Ivanov�
                findPerson(personList, nStructure);
                break;
            case 4: //������������ ������������� �������, ������������ �����
                nDynArray = 10;
                array = formedDynArrayDynStrings(nDynArray);
                printDynArrayDynStrings(array, nDynArray);
                break;
            case 5: //������ ������������� �������, ������������ �����
                printDynArrayDynStrings(array, nDynArray);
                break;
            case 6: //�������� K ����� �� ������ �������
                int k;
                cout<<"Enter k: ";
                cin>>k;
                deleteRows(array, &nDynArray, k);
                printDynArrayDynStrings(array, nDynArray);
                break;
        }
    } while (k!=7);//�����
}
