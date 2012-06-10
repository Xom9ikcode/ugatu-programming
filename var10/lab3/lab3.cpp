//��������	����������	������������	�����	����������
//������������ �������	� ��������� � ����� �������	�������� ���������� �� M ��������� �����	������ �������������	������� �����



#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void print(int *a, int n);
void deleteEl(int* a, int* n);
void insertEl(int* a, int* n);
void findEl(int* a, int n);
void sortEl(int* a, int n);
void changeEl(int* a, int n, int m);

int main(){
	int n=7,*a;
	a=new int[100];

	//=============================
	//���������� ������� ����. �������
	//=============================
	srand(time(0));
	for(int i=0;i<n;i++){
		a[i] = rand()%100 - 25;
	}
	print(a,n);

    cout << "Var 10 Lab 2" << endl;
    int k;

    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Udalenie"<<endl;
        cout<<"2. Dobavlenit"<<endl;
        cout<<"3. Perestanovka"<<endl;
        cout<<"4. Poisk"<<endl;
        cout<<"5. Sortirovka"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"======================="<<endl;

        cin>>k;
        switch (k) {
            case 1: deleteEl(a, &n); break;//�������� (������������ �������)
            case 2: insertEl(a, &n); break;//������� (� ��������� � ����� �������)
            case 3:
                int m;
                cout<<"m=";
                cin>>m;
                changeEl(a, n, m);
                break;//������������ (�������� ���������� �� M ��������� �����) !!!
            case 4: findEl(a, n); break;//����� (������ �������������)
            case 5: sortEl(a, n); break;//���������� (������� �����)
        }
    } while (k!=6);//�����

}

/**
* ����� �������
*/
void print(int *a, int n){
	std::cout<<"\nArray: ";
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<"; ";
	}
	std::cout<<"\n\n";
}

/**
* �������� (������������ �������)
*/
void deleteEl(int* a, int* n) {

	//���������� ������� ���� ��������
	int maxN=0;
	for(int i=1; i<*(n); i++){
		if (a[i] > a[maxN]) {
			maxN = i;
		}
	}
	cout<<"\n\nmax="<<a[maxN]<<"; maxN="<<(maxN+1);

	//����� ��������� ������� ����� ������ ������������� �� 1 ������� �����
	for(int i=maxN; i<*n-1; i++) {
		a[i] = a[i+1];
	}
	*n -= 1;
	print(a,*n);
}


/**
* ������� (� ��������� � ����� �������)
*/
void insertEl(int* a, int* n) {
	int insK, el = 777;
	std::cout<<"Enter k = ";
	std::cin>>insK;
	std::cout<<"\n";

	//������� (� ��������� � ����� �������)
	for(int i=*n; i<*n+insK; i++){
		a[i] = el;
	}

	*n += insK;
	print(a, *n);
}

/**
* ������������ (�������� ���������� �� M ��������� �����)
*/
void changeEl(int* a, int n, int m) {
    //���� ����� ������ �� m ��������� (��������)
	int tmp;
	if (false)
	for(int j=0; j<m; j++) {
	    tmp = a[n-1];
	    for(int i=n-1;i>0;i--){
            a[i]=a[i-1];
        }
        a[0] = tmp;
	}

    //���� ����� ����� �� m ���������
	for(int j=0; j<m; j++) {
	    a[n] = a[0];
	    for(int i=0; i<n; i++) {
	        a[i] = a[i+1];
	    }
	}

	print(a,n);
}

/**
* ����� (������ �������������)
*/
void findEl(int* a, int n) {
	bool find=false;

	//����� (������ �������������)
	int i = 0;
	while (!find && i < n) {
		if (a[i] < 0) {
			std::cout<<"\n"<<a[i]<<"["<<i+1<<"] - naiden!;";
			find = true;
		}
		i++;
	}

	if (!find){
		std::cout<<"\nElement ne naiden\n";
	} else {
		std::cout<<"\n";
	}
}


/**
* ���������� (������� �����)
*/
void sortEl(int* a, int n) {
	int tmp;

	for(int i=1; i<n-1; i++){
		for(int j=n-1; j>=i; j--){
			if(a[j] < a[j-1]){
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}
	}

	print(a,n);
}
