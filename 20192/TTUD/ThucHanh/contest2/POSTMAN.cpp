#include <iostream>
#include <algorithm>
#include <new>

using namespace std;

void sort(int* a, int n){
    for (int i = 2; i < (2*n); i += 2){
        int j = i - 2, t1, t2;

        for (j; j >= 0; j -= 2){
            if (a[j] >= a[j+2]){
                t1 = a[j];
                t2 = a[j+1];
                a[j] = a[j + 2];
                a[j + 1] = a[j + 3];
                a[j + 2] = t1;
                a[j + 3] = t2; 
            }
        }

    }

}

long long calculator(int* a, int n, int k){
    long long result = 0, time = 0;
    int du = 0;
    for (n = 2*n -1 ; n >=1; n -= 2){
        if (du > 0){
            if(a[n] > du){ 
                a[n] -= du;
                du = 0;
            }else{
                du -= a[n];
                a[n] = 0;


            } 
                
        }
        if ((a[n]%k) > 0){
            time = a[n]/k + 1;
            du = k - (a[n]%k);
            result += 2*time*((long long)a[n - 1]);
        }else{
            time = a[n]/k;
            result += 2*time*((long long)a[n - 1]);
        }
    }
    return result;

}

int main()
{
    int *input, *xP, *xN;
    long long result;
    int n, k, pos = 0;
    cin >> n >> k;
    input = new int[2*n];
    for(int i = 0; i < (2*n); i = i + 2){
        cin >> input[i];
        if(input[i] >= 0)
            ++pos;
        cin >> input[i+1];
    }
    int j = 0, f = 0;
    xP = new int[2*pos];
    xN = new int[2*(n - pos)];
    for(int i = 0; i < (2*n); i = i + 2){
        if(input[i] >= 0){
            xP[j] = input[i];
            xP[j+1] = input[i + 1];
            j = j+2;
        }else{
            xN[f] = input[i];
            xN[f] = xN[f]*(-1);
            xN[f+1] = input[i+1];
            f = f + 2;
        }
    }

    sort(&(xP[0]), pos);
    sort(&(xN[0]), (n - pos));

    result = calculator(&(xP[0]), pos, k)  + calculator(&(xN[0]), n -pos, k);

    cout << result;
    
    return 0;
}
