#include <iostream>
#include <new>
#include <algorithm>

using namespace std;

int numOfTeacher, numOfCourse, numCourseCanTeacher, numOfConflict,  *load;
int minLoad = INT32_MAX;
bool **conflict, **courseCanTeacher, **courseOfTeacherNow;

int minLoadNow(){
    int minLoadNow = INT32_MAX;

    for (int i = 0; i < numOfTeacher; ++i){
        minLoadNow = min(minLoadNow, load[i]);
    }
    return minLoadNow;
}

int maxLoadNow(){
    int maxLoadNow = INT32_MIN;

    for (int i = 0; i < numOfTeacher; ++i){
        maxLoadNow = max(maxLoadNow, load[i]);
    }

    return maxLoadNow;
}

bool checkConflict(int teacher, int course){
    for (int i = 0; i < course; ++i){
        if (courseOfTeacherNow[teacher][i] == true && conflict[i][course] == true)    
            return true;
        
    }

    return false;
}



void Try(int course){

    for ( int teacher = 0; teacher < numOfTeacher; ++teacher){
    //     if ( course == 4){
    //     cout  << " course: " << course + 1  << " teacher: " << teacher + 1 << " load: " << load[teacher] <<  " minLoadNow: " << minLoadNow() << " maxLoadNow: " << maxLoadNow() << " minLoad: " << minLoad << endl; 
    //     cout << "checconflict: " << checkConflict(teacher, course) << " can teacher: " << courseCanTeacher[teacher][course] << endl;
    // }
        if(checkConflict(teacher, course) == false && courseCanTeacher[teacher][course] == true){
            
            // cout  << " course: " << course + 1  << " teacher: " << teacher + 1 << " load: " << load[teacher] <<  " minLoadNow: " << minLoadNow() << " maxLoadNow: " << maxLoadNow() << " minLoad: " << minLoad << endl; 
             
            courseOfTeacherNow[teacher][course] = true;
            load[teacher] += 1;

            //    for (int i = 0; i < numOfTeacher; ++i){
            //         for (int j = 0; j < numOfCourse; ++j){
            //             cout << courseOfTeacherNow[i][j] << " ";
            //          }
            //           cout << "\n";
            //      }

            // cout  << " course: " << course + 1  << " teacher: " << teacher + 1  << " load: " << load[teacher] << " minLoadNow: " << minLoadNow() << " maxLoadNow: " << maxLoadNow() << " minLoad: " << minLoad << endl; 
            // cout << "\n\n" ;
            if (course == (numOfCourse - 1)){
                minLoad = min(minLoad, maxLoadNow());
            }else if(maxLoadNow() <= minLoad){
                Try(course + 1);
            }

            load[teacher] -= 1;
            courseOfTeacherNow[teacher][course] = false;

        }
    }
}


int main(){

    cin >> numOfTeacher >> numOfCourse;
    courseOfTeacherNow = new bool*[numOfTeacher];
    courseCanTeacher = new bool*[numOfTeacher];
    conflict = new bool*[numOfCourse];
    load = new int[numOfTeacher];

    for (int i = 0; i < numOfTeacher; ++i){
        courseOfTeacherNow[i] = new bool[numOfCourse];
        for (int j = 0; j < numOfCourse; ++j){
            courseOfTeacherNow[i][j] = false;
        }
    }


    for (int i = 0; i < numOfTeacher; ++i){

        load[i] = 0;
        courseCanTeacher[i] = new bool[numOfCourse];
        
        for (int j = 0; j < numOfCourse; ++j){
            courseCanTeacher[i][j] = false;
        }
    }

    for (int i = 0; i < numOfTeacher; ++i){

        int index;       
        cin >> numCourseCanTeacher ;
        
        for (int j = 0; j < numCourseCanTeacher; ++j){
            cin >> index;
            courseCanTeacher[i][index - 1] = true;
        }
    }


    for (int i = 0; i < numOfCourse; ++i){
        conflict[i] = new bool[numOfCourse];
        for (int j = 0; j < numOfCourse; ++j){
            conflict[i][j] = false;
        }
    }

    int index1 = 0, index2 = 0;
    cin >> numOfConflict;
    for (int i = 0; i < numOfConflict; ++i){
        cin >> index1 >> index2;
        conflict[index1 - 1][index2 - 1] = true;
    }

    // bool canteacher0[] = {1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1};
    // bool canteacher1[] = {0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1};
    // bool canteacher2[] = {1, 1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0};
    // bool canteacher3[] = {1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0};

    // courseCanTeacher[0] = &(canteacher0[0]);
    // courseCanTeacher[1] = &(canteacher1[0]);
    // courseCanTeacher[2] = &(canteacher2[0]);
    // courseCanTeacher[3] = &(canteacher3[0]);

    // bool conflict0[] = {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0};
    // bool conflict1[] = {0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0};
    // bool conflict2[] = {0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0};
    // bool conflict3[] = {0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0};
    // bool conflict4[] = {0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0};
    // bool conflict5[] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0};
    // bool conflict6[] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0};
    // bool conflict7[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1};
    // bool conflict8[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    // bool conflict9[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0};
    // bool conflict10[] = {0, 0, 0, 0, 0 ,0 ,0 ,0, 0, 0, 0, 1};
    // bool conflict11[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

    // conflict[0] = &(conflict0[0]);
    // conflict[1] = &(conflict1[0]);
    // conflict[2] = &(conflict2[0]);
    // conflict[3] = &(conflict3[0]);
    // conflict[4] = &(conflict4[0]);
    // conflict[5] = &(conflict5[0]);
    // conflict[6] = &(conflict6[0]);
    // conflict[7] = &(conflict7[0]);
    // conflict[8] = &(conflict8[0]);
    // conflict[9] = &(conflict9[0]);
    // conflict[10] = &(conflict10[0]);
    // conflict[11] = &(conflict11[0]);

    // for (int i = 0; i < numOfTeacher; ++i){
    //     for (int j = 0; j < numOfCourse; ++j){
    //     cout << courseCanTeacher[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < numOfTeacher; ++i){
    //     for (int j = 0; j < numOfCourse; ++j){
    //     cout << courseOfTeacherNow[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    // for (int i = 0; i < numOfCourse; ++i){
    //     for (int j = 0; j < numOfCourse; ++j){
    //     cout << conflict[i][j] << " ";
    //     }
    //     cout << "\n";
    // }



    Try(0);

    if (minLoad == INT32_MAX)
        cout << -1 ;
    else 
        cout << minLoad;



}