#include <iostream>
#include <algorithm>
#include <new>

using namespace std;

int numOfCourse = 6, numOfPeriod = 2, *credits,   *load, *periodOfCourse, minLoad = INT32_MAX;
bool  **prerequisites; 

int minLoadNow (){

    int minLoadNow = INT32_MAX; 

    for (int i = 0; i < numOfPeriod; ++i){
        minLoadNow = min(minLoadNow, load[i]);
    }
    
    return minLoadNow;

}

int maxLoadNow (){

    int maxLoadNow = INT32_MIN; 

    for (int i = 0; i < numOfPeriod; ++i){
        maxLoadNow = max(maxLoadNow, load[i]);
    }
    
    return maxLoadNow;

}

bool checkPrerequisite(int course, int period){
    for (int i = 0; i < numOfCourse; ++i){
        if (prerequisites[course][i] == true && periodOfCourse[i] <= period && periodOfCourse[i] != -1)
            return true;
        if (prerequisites[i][course] == true && periodOfCourse[i] >= period && periodOfCourse[i] != -1) 
            return true;
    }

    return false;
}

void Try (int course){
    for (int period = 0; period < numOfPeriod; ++period){
        if (checkPrerequisite(course, period) == false){
            // cout << "course: " << course << " period:" << period << "load:" << load[course] << " maxLoad:" << maxLoadNow() << " minLoad:" << minLoad << endl;
            load[period] += credits[course];
            periodOfCourse[course] = period;
            if (course == (numOfCourse -1)){
                minLoad = min(minLoad, maxLoadNow());
            }else if (maxLoadNow() <= minLoad){
                Try(course + 1);
            }

            load[period] -= credits[course];
            periodOfCourse[course] = -1;
        }

    }
}
int main(){

    cin >> numOfCourse >> numOfPeriod ;
    
    credits = new int[numOfCourse];
    load = new int[numOfPeriod];
    prerequisites = new bool*[numOfCourse];
    periodOfCourse = new int[numOfCourse];

    for (int i = 0; i < numOfCourse; ++i){

        cin >> credits[i];

        periodOfCourse[i] = -1;
        prerequisites[i] = new bool[numOfCourse];

    }

    for (int i = 0; i < numOfCourse; ++i){
        for (int j = 0; j < numOfCourse; ++j){
            cin >> prerequisites[i][j];
        }
    }

    for (int i = 0; i < numOfPeriod; ++i){
        load[i] = 0;
    }

    // int c[] = {4, 4, 4, 4, 2, 4}; 

    // bool conflict0[] = {0, 0, 0, 0, 0, 0};
    // bool conflict1[] = {0, 0, 0, 0, 0, 0};
    // bool conflict2[] = {0, 0, 0, 0, 0, 0};
    // bool conflict3[] = {0, 0, 1, 0, 0, 0};
    // bool conflict4[] = {0, 0, 1, 0, 0, 0};
    // bool conflict5[] = {1, 0, 0, 0, 0, 0};

    // credits = &(c[0]);
    // prerequisites[0] = &(conflict0[0]);
    // prerequisites[1] = &(conflict1[0]);
    // prerequisites[2] = &(conflict2[0]);
    // prerequisites[3] = &(conflict3[0]);
    // prerequisites[4] = &(conflict4[0]);
    // prerequisites[5] = &(conflict5[0]);

    Try(0);

    cout << minLoad;
}