#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "DoubleLinkedList.h"

using namespace std;

/**
1 - ��������� �� ���������� Creating, Adding, Deleting
2 - 1 � ������� ����� ������� create*, add*, del*
3 - 2 � ������� print*
*/
int debugDouble = 0;

/** ������� ��� ������ � �������� ������� */
void printFunNameDouble(char* name) {
    printf("[DoubleLinkedList] >>%s :: \n", name);
}

/** �������� ��������� */
void printDub(int i, Dub* dub) {
    if (debugDouble > 2) printFunNameDouble("Print Dub");

    printf("%d: id: %d\t data: %s\t prev: %d\t next: %d\n", i, dub, dub->data, dub->prev, dub->next);
}

/** ������� ��������� */
Dub* createDub(char* data) {
    if (debugDouble > 1) printFunNameDouble("Create Dub");
    if (debugDouble > 1) cout<<"data="<<data<<endl;

    Dub* dub = new Dub();
    dub->data = data;
    dub->prev = 0;
    dub->next = 0;
    if (debugDouble) {
        cout<<"Creating:\t";
        printDub(0, dub);
    }

    return dub;
}

/** ������� ��������� */
Dub* createDub() {
    char* data = new char[20];
    sprintf(data, "data_%d", rand() % 100);
    return createDub(data);
}

/** ��������� ��������� � ������ */
Dub* addDub(Dub* beg, Dub* dub, int pos) {
    if (debugDouble > 1) printFunNameDouble("Add Dub");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        delete dub;
        return beg;
    }

    if (pos == 0) {
        dub->prev = 0;
        dub->next = beg;
        beg->prev = dub;
        if (debugDouble) {
            cout<<"Adding to the top: ";
            printDub(0, dub);
        }
        return dub;
    }

    Dub* cur = beg;
    int i = 0;
    while (cur != 0 && i < pos) {
        if (i == pos - 1) {
            dub->prev = cur;
            dub->next = cur->next;

            if (cur->next != 0) cur->next->prev = dub;
            cur->next = dub;
            if (debugDouble) {
                cout<<"Adding:\t\t";
                printDub(i+1, dub);
            }
        } else {
            cur = cur->next;
        }
        i++;
    }

    if (i < pos) {
        cout<<"Position "<<pos<<" not found!";
    }

    return beg;
}

/** ������� ������ */
Dub* createListDouble(int n) {
    printFunNameDouble("Create List");

    Dub* beg;
    beg = createDub("ROOT");

    srand(time(0));
    for(int i=0;i<n-1;i++) {
        addDub(beg, createDub(), i+1);
    }

    cout<<"List creating!"<<endl;

    return beg;
}

/** �������� ������ */
void printListDouble(Dub* beg) {
    printFunNameDouble("Print List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        return;
    }

    Dub* cur = beg;
    int count = 0;
    while (cur !=0) {
        printDub(count, cur);
        cur = cur->next;
        count++;
    }
}

/** ��������� ������ (��������� ��������� � �������� ������ � ������) */
Dub* processingListDouble(Dub* beg, Dub* dub) {
    printFunNameDouble("Processing List");

    int pos;
    cout<<"Enter position for insert: ";

    cin>>pos;
    if (pos < 0) {
        cout<<"Wrong position!"<<endl;
        // TODO (phpusr#1#): �������� �������� �� �� �����
        delete dub;
        return beg;
    }

    cout<<"Insert: "; printDub(pos, dub);

    return addDub(beg, dub, pos);
}

/** ������� ������ */
Dub* delListDouble(Dub* beg) {
    printFunNameDouble("Delete List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        return beg;
    }

    Dub* cur = 0;
    int count = 0;
    while (beg != 0) {
        cur = beg;
        if (debugDouble) {
            cout<<"Deleting: ";
            printDub(count, cur);
        }
        beg = beg->next;
        delete cur;
        count++;
    }

    cout<<"List deleting!";

    return beg;
}
