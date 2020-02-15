/* Attending Workshop.cpp from hackerrank.com
* 15.02.2020 -> draft
* Razvan Mazilu
*/
#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop
{
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops
{
    int n;
    Workshop* WrkspArr = new Workshop[n];
};


//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize (int start_time[], int duration[], int n)
{
    Available_Workshops* aw = new Available_Workshops;
    aw->n = n;
    for(auto i = 0; i < n; i++)
    {
        aw->WrkspArr[i].start_time = start_time[i];
        aw->WrkspArr[i].duration = duration[i];
        aw->WrkspArr[i].end_time = start_time[i] - duration[i];
    }
    return aw;
}
bool compareTwoWrksp(Workshop a, Workshop b)
{
    return a.start_time > b.start_time;
}
int CalculateMaxWorkshops(Available_Workshops* ptr)
{
    int retVal = 0;
    int nOfWorkshops = ptr->n;
    sort(ptr->WrkspArr, ptr->WrkspArr+nOfWorkshops,compareTwoWrksp);
    for(auto i = 0; i < nOfWorkshops-1; i++)
    {
        if(ptr->WrkspArr[i].end_time < ptr->WrkspArr[i+1].start_time)
         retVal++;
    }
    return retVal;
}
int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
