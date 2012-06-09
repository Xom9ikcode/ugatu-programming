/*
+1.	������������ ���������������� ������, ��� ��������������� ���� ������ � ��������.
+2.	����������� ���������� ������.
+3.	��������� ��������� ������ � ������������ � ��������.
+4.	����������� ���������� ������.
+5.	������� ������ �� ������.
+6.	������������ ��������������� ������, ��� ��������������� ���� ������ � ��������.
+7.	����������� ���������� ������.
+8.	��������� ��������� ������ � ������������ � ��������.
+9.	����������� ���������� ������.
+10.	������� ������ �� ������.
+11.	������������ �������� ���������������� �������� ������, ��� ��������������� ���� ������ � ��������.
+12.	����������� ���������� ������.
+13.	��������� ��������� ������ � ������������ � ��������, ������� ���������� ���������.
+14.	������������� �������� ���������������� ������ � ������ ������.
+15.	����������� ���������� ������.
*/

#include <iostream>
#include <stdlib.h>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
#include "Wood.h"

using namespace std;

bool isClearScreen = true;

void clrscr() {
    if (isClearScreen) system("cls");
}

char* getSeparator() {
    return "========================";
}

void printMenu() {
    clrscr();
    cout<<getSeparator()<<endl;
    cout<<"== Odnonapravlenii spisok =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"1. Sozdat"<<endl;
    cout<<"2. Vivesti"<<endl;
    cout<<"3. Udalit s chetn nomerami"<<endl;
    cout<<"4. Udalit iz pamyati"<<endl;

    cout<<getSeparator()<<endl;
    cout<<"== Dvunapravlenii spisok =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"5. Sozdat"<<endl;
    cout<<"6. Vivesti"<<endl;
    cout<<"7. Dobavit element"<<endl;
    cout<<"8. Udalit iz pamyati"<<endl;

    cout<<getSeparator()<<endl;
    cout<<"==        Derevo        =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"9. Sozdat"<<endl;
    cout<<"10. Vivesti"<<endl;
    cout<<"11. Naite kol-vo listev"<<endl;
    cout<<"12. Preobrazovat v derevo poiska"<<endl;

    cout<<getSeparator()<<endl;
    cout<<"13. Exit"<<endl;
    cout<<getSeparator()<<endl;
}

int main() {
    int k = -1, count = 8;
    Hot* hot = 0;
    Dub* dub = 0;
    Wood* wood = 0;

    cout<<"Var10 Lab8"<<endl;

    printMenu();

    do {
        if (k != 0 && k != -1) cout<<endl<<"Nagmi [0] dly menu ili [13] dlya vihoda..."<<endl;

        cin>>k;
        switch (k) {
            case 0: clrscr(); printMenu(); break; //������� ����

            //������� ����������. ������ � ������� ���
            case 1: clrscr(); hot = createList(count); printList(hot); break;
            //������� ���������� ������
            case 2: clrscr(); printList(hot); break;
            //������� �� ����������. ������ ��� �������� � ������� �������� (0, 2, 4, ...)
            case 3: clrscr(); hot = processingList(hot); printList(hot); break;
            //������� ����������. ������ �� ������
            case 4: clrscr(); hot = delList(hot); printList(hot); break;

            //������� ���������. ������ � ������� ���
            case 5: clrscr(); dub = createListDouble(count); printListDouble(dub); break;
            //������� ���������. ������
            case 6: clrscr(); printListDouble(dub); break;
            //��������� � ���������. ������ ������ ����� ������� � �������� ���. �����
            case 7: clrscr(); dub = processingListDouble(dub, createDub("INSERT")); printListDouble(dub); break;
            //������� ���������. ������ �� ������
            case 8: clrscr(); dub = delListDouble(dub); printListDouble(dub); break;

            //������� �������� ���������������� �������� ������ � ������� ���
            case 9: clrscr(); wood = createIdealWood(count); printWood(wood); break;
            //������� ������
            case 10: clrscr(); printWood(wood); break;
            //������� ���������� ������� � ������
            case 11: clrscr(); processingWood(wood); printWood(wood); break;
            //��������������� ��������� ������ � ������ ������ � ������� ���
            case 12: clrscr(); wood = convertIdealWoodToSearchWood(wood); printWood(wood); break;
        }
    } while (k!=13);
}
