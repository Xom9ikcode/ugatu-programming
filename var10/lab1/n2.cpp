#include <iostream>
#include <math.h>
#include "n2.h"

using namespace std;

/**
* ���� 1: ������� 2
* �������� ���������, ��������� �� ��������� ����� X � Y � ����������� �������� TRUE, ���� ����� ����������� �������������� �������, � FALSE, ���� �� �����������.
*/
int n2(){
	/** ����� ����� */
	float x,y;

	/** ��� ����� ������������ */
	int x1 = -7, y1 = 0;
	int x2 = 0, y2 = -1;

	cout<<endl<<"Enter x,y"<<endl;
	cin>>x>>y;


	bool ok = (x<=x2 && x>=x1 && y<=y1 && y>=y2) && ((y - y1) / (y2 - y1) <= (x - x1) / (x2 - x1));
	if (ok){
		cout<<"Tocka popadaet!"<<endl;
	}else{
		cout<<"Tocka Ne popadaet."<<endl;
	}
}

/*
��������� ������: (y - y1)/(y2 - y1) = (x - x1)/(x2 - x1)
*/
