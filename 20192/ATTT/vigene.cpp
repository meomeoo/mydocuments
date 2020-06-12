#include <iostream>
#include <string>
#include <stdio.h>


using namespace std;

int main(){

    char m[100];
    char k[100];
    cout << "Nhap vao ban ro:" << endl;
    cin >> m;
    char* arr = new char[strlen(m)];
    m = strupr(m);
    cout << "Nhap vao khoa k:" << endl;
    cin >> k;
    m = strupr(k);
    for( int i = 0; i < strlen(m); i++){
        arr[i] = (m[i]- 'A') - (k[(m[i]%(strlen(k)))] - 'A')%26 + 'A';
    }

    cout << arr <<endl;
    return 0;


}