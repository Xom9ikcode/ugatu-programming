//var4
//(���������� ������)�������� ������� � ������ �������
//(��������� ������)������� ������ � ������� �

#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;

int* form_mas(int size);
int** form_mas_x2(int str, int stl);
void input_mas(int* mas, int size);
void input_mas_x2(int** mas, int str, int stl);
void print_mas(int* mas, int size);
void print_mas_x2(int** mas, int str, int stl);


/** ���������� �������� � ������ ������� */
int* addToBegin(int* mas, int* size, int el) {
    cout<<">>Add to begin\n";

    *size += 1;
    int* a = new int[*size];
    a[0] = el;

    for(int i=1; i<*size; i++) {
        a[i] = mas[i-1];
    }

    return a;
}

/** �������� ������ �� �� ������ � ��������� ������� */
int** deleteRowById(int** mas, int* str, int stl, int id) {
    if (str == 0 || stl == 0) {
        cout<<">>Array is empty!"<<endl;
        return mas;
    }

    int** a = new int*[*str];
    int curRow = 0;

    for(int i=0; i<*str; i++) {
        if (i != id) {
            a[curRow] = new int[stl];
            for(int j=0; j<stl; j++) {
                a[curRow][j] = mas[i][j];
            }
            curRow++;
        }
    }

    *str = curRow;
    return a;
}

/** ��������� ����������� ������ */
int main(int argc, char *argv[]) {
    int k;
    int* mas;
    int** mas2;
    int SIZE = 10;
    int size=0, str=0, stl=0;
    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Formed arrays"<<endl;
        cout<<"2. Print array"<<endl;
        cout<<"3. Print array x2"<<endl;
        cout<<"4. Add element to begin array"<<endl;
        cout<<"5. Delete row from array"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            case 1://��������� ������ � ���������� ����������� � ���������� ��������
                size = SIZE;
                mas = form_mas(size);
                input_mas(mas,size);

                str = SIZE; stl = size;
                mas2 = form_mas_x2(str, stl);
                input_mas_x2(mas2, str, stl);
                break;
            case 2: print_mas(mas, size); break;//������ ����������� �������
            case 3: print_mas_x2(mas2, str, stl); break;//������ ���������� �������
            case 4://���������� �������� � ������ ����������� �������
                mas = addToBegin(mas, &size, 777);
                print_mas(mas, size);
                break;
            case 5://�������� ������ ��� ������� � � ��������� �������
                int k;
                cout<<"Enter k: ";
                cin>>k;
                mas2 = deleteRowById(mas2, &str, stl, k-1);
                break;
        }
    } while (k!=6);//�����

}

/** ������������ ����������� ������� */
int* form_mas(int size) {
    cout<<">>Formed array\n";
    int* a = new int[size];
    return a;
}

/** ������������ ���������� ������� */
int** form_mas_x2(int str, int stl) {
    cout<<">>Formed array x2\n";
    int** a = new int*[str];

    for(int i=0;i<str;i++) {
        a[i] = new int[stl];
    }
    return a;
}

/** ������������ ������ ��� ����������� ������� */
void input_mas(int* mas, int size) {
    cout<<">>Input array\n";

    srand(time(0));
    for(int i=0;i<size;i++) {
        mas[i] = rand()%10;
    }
}

/** ������������ ���������� ������� */
void input_mas_x2(int** mas, int str, int stl) {
    cout<<">>Input array x2\n";

    srand(time(0));
    for(int i=0;i<str;i++) {
        for (int j=0;j<stl;j++){
            mas[i][j] = rand()%100;
        }
    }
}

/** ���������� ����������� ������� */
void print_mas(int* mas, int size) {
    cout<<">>Print array\n";

    for (int i=0;i<size;i++) {
        cout<<mas[i]<<", ";
    }
}

/** ���������� ���������� ������� */
void print_mas_x2(int** mas, int str, int stl) {
    cout<<">>Print array x2\n";

    for (int i=0;i<str;i++) {
        for (int j=0;j<stl;j++) {
            cout<<mas[i][j]<<", ";
        }
        cout<<"\n";
    }
}

