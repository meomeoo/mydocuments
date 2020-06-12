#include <iostream>
#include <new>
#include <algorithm>
#include <stdio.h>
#include <cstring>


using namespace std;
long long result = 0;
char buff[1005];
int len = 0, numOf = 0, *arrTry, num1Now = 0, num2Now = 0;
bool check(char *x)
{
    char Stack[10000];
    int T=-1;
    for(;*x;x++)
    {
        if(*x=='(' ) {T++; Stack[T]=*x;}
        else if(*x==')') 
        {
            if(T<0) return false;
            if(Stack[T]!='(') return false;
            T--;
        }  
    }
    if(T==-1) return true;
    return false;
}


void Try(int key){
    for(int i = 40; i < 42; ++i){
        buff[arrTry[key]] = i;
        if(i == 40)
            num1Now += 1;
        else
            num2Now += 1;
        if(key == (numOf-1)){
            if (check(buff) == true)
                result += 1;
        }else if ( num1Now <= len/2 && num2Now <= len/2){
            Try(key + 1);
        }
        buff[arrTry[key]] = 63;
        if(i == 40)
            num1Now -= 1;
        else
            num2Now -= 1;

    }

}

int main(){
   
   cin >> buff;
   len = strlen(buff);
   for(int i = 0; i < len; ++i){
       if(buff[i] == '?'){
           numOf += 1;
       }
   }
   arrTry = new int[numOf];
   int j = 0;
   for(int i = 0; i < len; ++i){
       if(buff[i] == '?'){
           arrTry[j] = i;
           j+=1;
       }else if(buff[i] == '('){
           num1Now += 1;
       }else
            num2Now +=1;
   }

   if (num1Now <= len/2 && num2Now <= len/2 && (len%2 == 0))
        Try(0);

   cout << result;
   return 0;


}