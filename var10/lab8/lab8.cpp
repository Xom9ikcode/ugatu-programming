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
    cout<<"== Singly Linked List =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"1. Create list"<<endl;
    cout<<"2. Print list"<<endl;
    cout<<"3. Processing list"<<endl;
    cout<<"4. Delete List"<<endl;

    cout<<endl<<getSeparator()<<endl;
    cout<<"== Double Linked List =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"5. Create list double"<<endl;
    cout<<"6. Print list double"<<endl;
    cout<<"7. Processing list double"<<endl;
    cout<<"8. Delete list double"<<endl;

    cout<<endl<<getSeparator()<<endl;
    cout<<"==        Wood        =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"9. Create ideal wood"<<endl;
    cout<<"10. Print wood"<<endl;
    cout<<"11. Processing wood"<<endl;
    cout<<"12. Conver to Search wood"<<endl;

    cout<<endl<<getSeparator()<<endl;
    cout<<"13. Exit"<<endl;
    cout<<getSeparator()<<endl;
}

int main() {
    int k, count = 8;
    Hot* hot = 0;
    Dub* dub = 0;
    Wood* wood = 0;

    cout<<"Lab 8"<<endl;

    do {
        if (k!=0) cout<<endl<<"Press 0 to show menu or 13 to exit..."<<endl;

        cin>>k;
        switch (k) {
            case 0: clrscr(); printMenu(); break;
            case 1: clrscr(); hot = createList(count); break;
            case 2: clrscr(); printList(hot); break;
            case 3: clrscr(); hot = processingList(hot); break;
            case 4: clrscr(); hot = delList(hot); break;
            case 5: clrscr(); dub = createListDouble(count); break;
            case 6: clrscr(); printListDouble(dub); break;
            case 7: clrscr(); dub = processingListDouble(dub, createDub("INSERT")); break;
            case 8: clrscr(); dub = delListDouble(dub); break;
            case 9: clrscr(); wood = createIdealWood(count); break;
            case 10: clrscr(); printWood(wood); break;
            case 11: clrscr(); processingWood(wood); break;
            case 12: clrscr(); wood = convertIdealWoodToSearchWood(wood); break;
        }
    } while (k!=13);
}
