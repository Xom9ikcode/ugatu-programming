#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Helper.h"

using namespace std;

/** ������ ��� ��������� */
const int SIZE_MESSAGE = 100;

/** ����������� */
char* getSeparator() {
    return "========================";
}

/** ������� ������ */
void clrscr(bool isClearScreen) {
    if (isClearScreen) system("cls");
}

/** ������� ��������� ���� */
void printMenuHeader(char* title) {
    cout<<getSeparator()<<endl;
    cout<<"== "<<title<<" =="<<endl;
    cout<<getSeparator()<<endl;
}

/** ������� � � ��������� ���� */
void printMenuHeader(int num, char* title) {
    cout<<getSeparator()<<endl;
    cout<<"== "<<num<<". "<<title<<" =="<<endl;
    cout<<getSeparator()<<endl;
}

/** ������� ������� ���� */
void printMenuItem(int num, char* title) {
    cout<<num<<". "<<title<<endl;
}

/** ������� �������������� ��������� */
void info(char* message) {
    cout<<">>"<<message<<endl;
}

/** ������� �������������� ��������� � ��������� */
void info(char* prefix, char* message) {
    printf("[%s] >>%s\n", prefix, message);
}

/** ��������������� ��������� */
void warn(char* message) {
    cout<<"[WARN:] "<<message<<"!"<<endl;
}

/** ����������� ������ ��������� �� ������ */
char* getErrorString(char* message) {
    char* result = new char[SIZE_MESSAGE];
    sprintf(result, "[ERROR:] %s\n", message);

    return result;
}

/** ������� ��������� �� ������ */
void error(char* message) {
    cout<<getErrorString(message);
}

/** ������� �������� ������� */
void printFuncName(char* title) {
    printf("%s\n[ %s ]\n%s\n\n", getSeparator(), title, getSeparator());
}

/** ������� ��� �������� ��������� */
void testMessages() {
    printFuncName("Test messages");

    info("Info message");
    info("Prefix","Info message");
    warn("Warning message");
    error("Error message");
}
