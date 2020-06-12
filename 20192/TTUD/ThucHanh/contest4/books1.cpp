#include <iostream>
#include <vector>
#include <new>

using namespace std;


bool check( long long max_val, int* a, int n, int k)
{
    int size = 0;
    long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (( long long)(sum + a[i]) <= max_val)
        {
            sum += ( long long)a[i];
        }
        else
        {
            sum = ( long long)a[i];
            if (( long long)a[i] > max_val)
            {
                return false;
            }
            ++size; // cac phan tu ngan cach
        }
    }
    if (size >= k)
    {
        return false;
    }
    return true;
}

// ham in ra ket qua
void print(  long long max_val, int* a, int n, int k)
{
    vector<int> pos;
     long long sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (( long long)(sum + a[i]) <= max_val)
        {
            sum += ( long long)a[i];
        }
        else
        {
            sum = ( long long)a[i];
            pos.push_back(i); // cac phan tu ngan cach
        } 
    }
    int more = k - (pos.size() + 1);

    int j = 0;
    auto index = pos.rbegin();
    for (int i = 0; i < n; ++i){
        if (i == int(*index)  ){
            if(i != 0) cout << ' ';
            cout << a[i] << ' ' << '/';
            ++index;
        }else{
            if(more > 0){
                if(i != 0) cout << ' ';
                cout << a[i] << ' ' << '/';
                --more;
            }else{
                if(i != 0) cout << ' ';
                cout << a[i] ;
            }
        }
    }
    cout << "\n";
    return;

}

void test()
{
    long long MAX = 0;
    int n,k;
    cin >> n >> k;
    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];;
        MAX += ( long long)a[i];
    }
    
      long long l = 0, r = MAX, mid;
    while (r > l)
    {
        
        mid = (l + r) >> 1;

        if (check(mid, &(a[0]), n, k))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    print(r, &(a[0]), n, k);
    delete(a);
    return;
}


int main()
{
    long long numOfTest;
    cin >> numOfTest;
    for(int i = 0; i < numOfTest; ++i){
        test();
    }

    return 0;
    
}