// var10
/*
1.	��������� ������� ������������ � ������� ��� ���������� ������ � ������� ��� �� ������.
2.	��������� ��������� ����������� ������� � ������������ � ���������, ��������� �������, ��������� ������� �� ������.
3.	��������� ������� ������������ � ������� ��� ��������� ������ � ������� ��� �� ������.
4.	��������� ��������� ���������� ������� � ������������ � ���������, ��������� �������, ��������� ������� �� ������.
5.	������ � ���������� ������ �������� � ���������� �� � ������������ �� ����� ���������, ��������� �������.

���������� ������	��������� ������	������
������� �� ������� ��� �������� ������ min(a[1],a[3],�a[2n-1]).	��� �������� ������ ������� �������� ���������� �� � ��������� �����.	����������� ������ ������ ����� � ������.
*/


#include <iostream>
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string.h>


using namespace std;


void print(int *a, int n);
void print2(int **a, int n);
int* deleteEl(int* a, int* n);
void changeEl(int** a, int n, int k);
void stringChange(char* s);


int main(){

    cout << "Var 10 Lab 3" << endl;
    int k;

    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Udalenie"<<endl;
        cout<<"2. Sdvinut stroki matrix"<<endl;
        cout<<"3. Stroki"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"======================="<<endl;

        cin>>k;
        switch (k) {
            case 1: //�������� �� ������� ��� �������� ������ min(a[1],a[3],�a[2n-1])
                int n,*a;

                cout<<"Enter n = ";
                cin>>n;
                cout<<"\n";

                a=new int[n+10];

                //����������
                srand(time(0));
                for(int i=0;i<n;i++){
                    a[i]=rand() % 10;
                }

                print(a,n);
                a = deleteEl(a, &n);
                print(a, n);
                break;

            case 2:  //��� �������� ������ ������� �������� ���������� �� � ��������� �����.
                int n2, **a2, k2;
                cout<<"\n\nEnter n = ";
                cin>>n2;
                cout<<"\n\nEnter k = ";
                cin>>k2;
                cout<<"\n";

                a2 = new int*[n2];

                //����������
                srand(time(0));
                for(int i=0;i<n2;i++){
                    a2[i] = new int[n2];
                    for(int j=0;j<n2;j++){
                        a2[i][j] = rand() % 100;
                    }
                }
                print2(a2, n2);

                changeEl(a2, n2, k2);
                print2(a2, n2);
                break;

            case 3: //����������� ������ ������ ����� � ������
                char s[100];
                cout<<"Vvedit stroku:"<<endl;
                fflush(stdin);
                gets(s);

                stringChange(s);
                cout<<endl<<"Resultat: "<<endl;
                cout<<s;
                break;
        }
    } while (k!=4);//�����
}

void func() {
    char s[100];
    fflush(stdin);
    gets(s);
    puts(s);
}

/**
* ����� ����������� �������
*/
void print(int *a, int n){
	cout<<"\nArray: ";
	for(int i=0; i<n; i++){
		cout<<a[i]<<"; ";
	}
	cout<<"\n\n";
}

/**
* ����� ���������� �������
*/
void print2(int** a, int n){
	std::cout<<"\nArray: \n";
	for(int i=0; i<n; i++){
		for(int j=0;j<n;j++){
			cout<<a[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n\n";
}


/**
* ������� �� ������� ��� �������� ������ min(a[1],a[3],�a[2n-1])
*/
int* deleteEl(int* a, int* n) {

    //����������� ���������� �������� �����
	int count = round((float)*n / 2);

    //���������� �������� �� �������� �����
    int min = a[0];
	for (int i=1; i<count; i++) {
	    if (a[2*i] < min) min = a[i];
	}
	cout<<"min: "<<min;

	int* tmp = new int[100], k=0;
	for(int i=0; i<*n; i++) {
	    if (a[i] != min) {
	        tmp[k++] = a[i];
	    }
	}

	*n = k;
	return tmp;
}

/**
* ��� �������� ������ ������� �������� ���������� �� � ��������� �����
*/
void changeEl(int** a, int n, int k) {
    //����������� ���������� �������� �����
	int count = round((float)n / 2);

    //����������� ����� ����� �������� �����
    for(int i=0; i<count; i++) {
        for(int s=0; s<k; s++) {
            int tmp = a[2*i][0];
	        for(int j=0; j<n-1; j++) {
	            a[2*i][j] = a[2*i][j+1];
	        }
	        a[2*i][n-1] = tmp;
	    }

	}
}

/**
* ����������� ������ ������ ����� � ������
*/
void stringChange(char* s) {
    char tmp[100][100];
    strcat(s, " ");

    int sizeArray = 0, sizeWord = 0, length = strlen(s);
    for(int i=0; i<length; i++) {
        //���� ������ ������ ����� �����������, �������� ����������� �����
        if (s[i] == ' ') {
            tmp[sizeArray][sizeWord] = '\0';
            //�������������� ������ ������
            if (sizeArray % 2 == 1) {
                strrev(tmp[sizeArray]);
            }

            sizeWord = 0;
            sizeArray++;
        } else {
            tmp[sizeArray][sizeWord++] = s[i];
        }
    }

    //�������� ����� ������ �� ���� � �������
    strcpy(s, "");
    for(int i=0; i<sizeArray; i++) {
        strcat(s, tmp[i]);
        strcat(s, " ");
    }
}
