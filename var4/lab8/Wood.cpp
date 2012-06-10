#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Wood.h"

using namespace std;

/**
1 - ��������� �� ���������� Creating, Adding
2 - 1 � ������� ������������ ������� create*, add*
3 - 2 � ������� print*
*/
int debugWood = 0;

/** ������� ��� ������ � �������� ������� */
void printFunNameWood(char* name) {
    printf("[Wood] >>%s :: \n", name);
}

/** �������� ���� ������ */
void printNode(Wood* wood) {
    if (debugWood > 2) printFunNameWood("Print node");

    printf("id=%d\t data=%.3f\t left=%7d\t right=%7d\n", wood, wood->data, wood->left, wood->right);
}

/** ������� ��������� ������ ���������� */
Wood* createIdealWoodRecourse(Wood* wood, int count) {
    if (debugWood > 1) printFunNameWood("Create ideal wood recourse");

    if (count == 0) {
        return 0;
    }

    int countLeft = count / 2;
    int countRight = count - countLeft - 1;

    wood = new Wood();
    wood->data = rand() / 3.4;

    if (debugWood) {
        if (debugWood > 1) printf("count=%d\t countLeft=%d\t countRight=%d\n", count, countLeft, countRight);
        cout<<"Creating: "; printNode(wood);
    }

    wood->left = createIdealWoodRecourse(wood->left, countLeft);
    wood->right = createIdealWoodRecourse(wood->right, countRight);

    return wood;
}

/** �������� ������ ���������� */
void printWoodRecourse(Wood* wood) {
    if (debugWood > 1) printFunNameWood("Print wood recourse");

    if (wood) {
        printNode(wood);

        printWoodRecourse(wood->left);
        printWoodRecourse(wood->right);
    }
}

/** ������� ��������� ������ */
Wood* createIdealWood(int count) {
    printFunNameWood("Create ideal wood");

    srand(time(0));
    Wood* wood = createIdealWoodRecourse(new Wood(), count);
    cout<<"Wood created!";

    return wood;
}

/** �������� ������ */
void printWood(Wood* wood) {
    printFunNameWood("Print wood");

    if (wood == 0) {
        cout<<"Wood is empty!";
        return;
    }

    printWoodRecourse(wood);
}

/** ���� ������� � ������ ���������� */
Wood* findMinRecourse(Wood* wood, Wood* min) {
    if (debugWood > 1) printFunNameWood("Find min recourse");

    if (!wood || !min) {
        if (!min) cout<<"min == 0"<<endl;
        return min;
    }

    if (wood->data < min->data) {
        min = wood;
    }

    if (debugWood) {
        cout<<"wood="; printNode(wood);
        cout<<"min="; printNode(min);
    }

    min = findMinRecourse(wood->left, min);
    min = findMinRecourse(wood->right, min);

    return min;
}

/** ��������� ������ (����� ��������) */
void processingWood(Wood* wood) {
    printFunNameWood("Processing wood");

    if (wood == 0) {
        cout<<"Wood is empty!";
        return;
    }

    Wood* min = findMinRecourse(wood, wood);

    cout<<"Minimum is "; printNode(min);
}

/** ��������� ���� � ��������� ������ (���� ��� ��� ������ ��������) */
Wood* addNodeToSearchWood(Wood* searchWood, Wood* el) {
    if (debugWood) printFunNameWood("Add node");

    if (!searchWood || !el) {
        if (!el) cout<<"el == 0"<<endl;
        if (!searchWood) cout<<"searchWood == 0"<<endl;
        return el;
    }

    bool isset = false;
    Wood *cur = searchWood, *endNode;

    while (!isset && cur) {
        if (el->data == cur->data) {
            isset = true;
            if (debugWood) {
                cout<<"el="; printNode(el);
                cout<<"cur="; printNode(cur);
            }
        } else {
            endNode = cur;
            if (el->data < cur->data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }

    if (isset) {
        cout<<"Already have: "; printNode(cur);
        return cur;
    }

    Wood* newWood = new Wood();
    newWood->data = el->data;
    if (el->data < endNode->data) {
        endNode->left = newWood;
    } else {
        endNode->right = newWood;
    }
    if (debugWood) {
        cout<<"Adding: ";
        printWood(newWood);
    }

    return newWood;
}

/** ������������ ��������� ������ � (��������� ����������) */
Wood* convertIdealWoodToSearchWoodRecurse(Wood* wood, Wood* searchWood) {
    if (debugWood) printFunNameWood("Convert to Search wood recourse");

    if (wood) {
        addNodeToSearchWood(searchWood, wood);

        convertIdealWoodToSearchWoodRecurse(wood->left, searchWood);
        convertIdealWoodToSearchWoodRecurse(wood->right, searchWood);
    }

    return searchWood;
}

/** ������� ����� � ���� ������ ��� 90�� (������� ��������) */
void printTree(Wood *q, int n) {
   if (q) {
      printTree(q->right, n+5);
      for (int i = 0; i < n; i++) {
         printf(" ");
      }
      printf("%.3f\n", q->data);
      printTree(q->left, n+5);
   }
}

/** ������������ ��������� ������ � ��������� */
Wood* convertIdealWoodToSearchWood(Wood* wood) {
    printFunNameWood("Convert to Search wood");

    if (wood == 0) {
        cout<<"Wood is empty!";
        return wood;
    }

    Wood* searchWood = new Wood();
    searchWood->data = wood->data;
    convertIdealWoodToSearchWoodRecurse(wood, searchWood);

    cout<<"Wood converted to Search wood!"<<endl;

    if (debugWood) printTree(searchWood, 0);

    return searchWood;
}
