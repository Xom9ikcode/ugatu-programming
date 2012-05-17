/*
����� ��������
0,25x3 + x - 1,2502 = 0
�������, ���������� ������: [0;2]
������ ��������: 1,0001
*/

#include <iostream>
#include <math.h>
#include <stdio.h>

typedef float(*fptr2args)(float, bool);//���-��������� �� ������� ��������� c 2 �����������

const bool debug = false;

/** ������ ��������� � ��������� ����� */
void printX(char* methodName, int count, float x, float y) {
    printf("[%s]\t Result(%d):: x=%.10f\t y=%.5f\n", methodName, count, x, y);
}

/** ����� ������� */
float methodNewton(fptr2args f, float a, float b, float e) {
    char* methodName = "Newton";
    float x = (a + b)/2, xPrev;
    int count = 0;

    do {
        xPrev = x;
        count++;
        x = xPrev - f(xPrev, false) / f(xPrev, true);
    } while(fabs(x - xPrev) > e);

    printX(methodName, count, x, (*f)(x, false));
}

/** ������� 11 �������� */
float var11Func(float x, bool proizvod) {
    //���� proizvod == false ����� ������������ �������� ������� �����., � ������ ������ - �����������
    if (!proizvod) {
        return 0.1 * pow(x,2) - x * log(x);
    } else {
        return 0.2 * x - log(x) + 1;
    }
}
