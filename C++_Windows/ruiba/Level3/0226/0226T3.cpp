#include <bits/stdc++.h>
using namespace std;

struct student
{
    char name[10];
    int sex;
    int score;
    string Sclass;
};

student stu[2];
student *p = stu;

int main()
{
    strcpy (stu[0].name, "小张");
    stu[0].sex = 1;
    stu[0].Sclass = "六班";
    stu[0].score = 60;

    strcpy (stu[1].name, "小王");
    stu[1].sex = 1;
    stu[1].Sclass = "三班";
    stu[1].score = 60;

    cout << p << endl;
    cout << p -> name << endl;
    cout << stu[0].Sclass << endl;
    cout << "-------------------" << endl;
    cout << (p + 1) -> name << endl;
    cout << stu[1].Sclass << endl;
    cout << "-------------------" << endl;
    
    for (int i = 0; i < 2; i++)
    {
        cout << (p + i) -> name << endl;
    }
    return 0;
}