//������� ����� ������ �� ������� ���������, �������� ������� ����� 0.
//����������� ��� ������ ������ �������.	
//������� ������ ������ ����� �� ������.

#include <iostream>
#include <math.h>
#include <ctime>
#include <iostream>

void todo(char *s);

void print(int *a, int n){
	std::cout<<"\nArray: ";
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<"; ";
	}
	std::cout<<"\n\n";
}

void main(){	
	//=============================
	//������� ����� ������ �� ������� ���������, �������� ������� ����� 0
	//=============================
	
	int n,*a;
	
	std::cout<<"Enter n = ";
	std::cin>>n;
	std::cout<<"\n";

	a=new int[100];
	
	//����������	
	srand(time(0));
	for(int i=0;i<n;i++){
		a[i]=rand()%2;
	}
	//�����
	print(a,n);

	int *b, count=0;
	b = new int[100];

	//�������� ������ �������
	for (int i=0;i<n;i++) {
		if (a[i] == 0) {			
			b[count] = i+1;
			count++;
		}
	}
	print(b,count);
	



	//=============================
	//����������� ��� ������ ������ �������
	//=============================
	/*
	int n;
	
	std::cout<<"Enter n = ";
	std::cin>>n;
	std::cout<<"\n";

	int b[100][100], tmp;

	//�������� �������
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			b[i][j] = rand()%100;
			std::cout<<b[i][j]<<" ";
		}
		std::cout<<"\n";
	}

	//��������� ������ �����
	for (int i=0;i<n/2;i++) {
		for (int j=0;j<n/2;j++) {
			tmp = b[2*i+1][j];
			b[2*i+1][j] = b[2*i+1][n-1-j];
			b[2*i+1][n-1-j] = tmp;
		}
	}

	//����� �������
	std::cout<<"\n\n";
	for (int i=0;i<n;i++) {
		for (int j=0;j<n;j++) {
			std::cout<<b[i][j]<<" ";
		}
		std::cout<<"\n";
	}
	*/



	//=============================
	//������� ������ ������ ����� �� ������
	//=============================
	/*
	char s[100];

	std::cout<<"\n\nEnter s = ";
	//���� ������
	gets(s);	

	todo(s);	
	*/
}

void todo(char *s){
	
	int len=strlen(s),countWord=1,lenSC=0;
	char sc[100];

	//������������ ����� ������ �� �������� ����
	for(int i=0;i<len;i++){
		//���� ������ ������, ������ ����� �����
		if(s[i]==' '){
			countWord++;
		}
		//���� ����� �������� ������, ���� ��� �������� � ����� ������
		if(countWord%2==1){			
			sc[lenSC]=s[i];
			lenSC++;
		}
	}
	//���������� ���� ������� � ����� ������
	sc[lenSC]='\0';

	//����� �������������� ������
	puts(sc);	
}