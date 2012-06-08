#include <iostream>
#include <math.h>
#include <stdio.h>

typedef float(*fptr)(float, bool);//���-��������� �� ������� ��������� c 2 �����������

const bool debug = false;

/** ������ ��������� � ��������� ����� */
void printX(char* methodName, int count, float x, float y) {
    printf("[%s]\t Result(%d):: x=%.10f\t y=%.5f\n", methodName, count, x, y);
}

/** ����� �������� */
float methodIterator(fptr f, float a, float b, float e) {
      char* methodName = "Iterator";
      float x, xNext = b;
      int count = 0;
      bool exit = false;
      do {
          count++;
          x = xNext;
          xNext = fabs((*f)(x, false));

          if (count % 10 == 0 && debug) {
             printf("%d: x(%d)=%.5f, x(%d)=%.5f\n", count, count-1, x, count, xNext);
          }

          exit = xNext < e;

      } while(fabs(xNext - x) > e && !exit);

      if (exit) {
        printX(methodName, count, x, (*f)(x, true));
        return x;
      } else {
        if (debug) printf("X Not found!\n");
        printX(methodName, count, x, (*f)(x, true));
        return x;
      }
}

/** ����� ����������� ������� */
float methodBisection(fptr f, float a, float b, float e) {
    char* methodName = "Bisection";
    float x;
    int count = 0;
    do {
        count++;
        x=(a+b)/2;			//������� �������� �������
        if ( (*f)(a, true) * (*f)(x, true) < 0 ) {		//�������� �������
           b=x;
        } else {
          a=x;
        }
        if (count % 100 == 0 && debug) printf("%d: (*f)(a)=%.5f, (*f)(a) * (*f)(x)=%.10f, a=%f, b=%f\n", count, (*f)(a, true), (*f)(a, true) * (*f)(x, true), a, b);
    } while(fabs((*f)(x, true))>e && fabs(a-b)>e);

    printX(methodName, count, x, (*f)(x, true));

    return x;
}

/** ������� 10 �������� */
float var10Func(float x, bool std) {
    if (std) {
        //����������� �������
        return 0.1 * pow(x,2) - x * log(x);
    } else {
        //���������� X �� ������� ��� ������ ��������
        return pow(10*x*log(x), 0.5);
    }

}
