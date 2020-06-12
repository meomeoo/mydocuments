#include <vector>
#include<iostream>

using namespace std;

int main()
{
    vector<int> pos;
    pos.push_back(1);
    pos.push_back(2);
        pos.push_back(3);

    auto a = pos.rend();
    cout << *a << endl;

}