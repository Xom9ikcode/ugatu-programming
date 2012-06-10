/**
* 10	25	44
* Var 10: Lab 2
*/

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void task10();
void task25();
void task44();

int main() {
    cout << "Var 10 Lab 2" << endl;

    int k;

    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. 3aga4a 10"<<endl;
        cout<<"2. 3aga4a 25"<<endl;
        cout<<"3. 3aga4a 44"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"======================="<<endl;

        cin>>k;
        switch (k) {
            case 1: task10(); break;//������ 10
            case 2: task25(); break;//������ 25
            case 3: task44(); break;//������ 44
        }
    } while (k!=4);//�����
}

/**
* ������ 10
* ���� ������������������ �� n ����� �����. ����� ����� ������������ � ������������� ��������� � ���� ������������������.
*/
void task10(){
	int n=100, maxN=0, minN=0, A[100];

	std::cout<<"n=";
	std::cin>>n;

	//�������� ������������������ ��������� ����� � �� �����
	srand(time(0));
	for(int i=0; i<n; i++) {
	    A[i] = rand()%100;
	    cout<<A[i]<<", ";
	}

    //����� ��� � ����, ������ for
	for(int i=0;i<n;i++){
		if (A[i] < A[minN]) {
		    minN = i;
		}
		if (A[i] > A[maxN]) {
		    maxN = i;
		}
	}
	//�����
	cout<<endl<<"min="<<A[minN]<<"; max="<<A[maxN]<<";"<<endl;
	cout<<endl<<"[for]Sum = "<<A[minN] + A[maxN]<<endl;

    //����� ��� � ����, ������ while
	int i=0;
	while(i<n){
        if (A[i] < A[minN]) {
		    minN = i;
		}
		if (A[i] > A[maxN]) {
		    maxN = i;
		}
		i++;
	}
	//�����
	cout<<endl<<"[while]Sum = "<<A[minN] + A[maxN]<<endl;

    //����� ��� � ����, ������ do-while
	i=0;
	do{
		if (A[i] < A[minN]) {
		    minN = i;
		}
		if (A[i] > A[maxN]) {
		    maxN = i;
		}
		i++;
	}while(i<n);
	//�����
	cout<<endl<<"[do-while]Sum = "<<A[minN] + A[maxN]<<endl;
}

/**
* ������ 25
* ���� ������������������ ����� �����, �� ������� ������� 0.  �����  ����� ������������ �������� � ���� ������������������
*/
void task25() {
	int x=-1, min=1000, minN=0, i=0;

	cout<<"Vvodite chisla (v konce 0):\n";

	//���� � ���������� ��������
	while (x != 0) {
		std::cin>>x;
		i++;
		if (x != 0 && x < min) {
			min = x;
			minN = i;
		}
	}

    //�����
	cout<<"\n\nmin="<<min<<"; minN="<<minN<<"\n";
}

/**
* ������ 44
* ���������� �������� �� ����� k �������� 3.
*/
void task44() {
    const int step = 3;
    int k;

    //���� k
    cout<<"Vvedit k=";
    cin>>k;

    //����� �������
    int proizv = 1, count = 0;
    while (proizv < k) {
        count++;
        proizv *= step;
    }

    //�����
    if (proizv == k) {
        cout<<k<<" yavlyaetsya "<<count<<" step "<<step;
    } else {
        cout<<k<<" ne yavlyaetsya step "<<step;
    }
}

