/* Variable Sized Arrays from hackerrank.com
* 15.02.2020
* Razvan Mazilu
*/
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <ostream>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n,q;
    stringstream ss;
    string str;

//read n and q
    getline(cin, str);
    ss<<str;
    ss>>n;
    ss>>q;
    vector<int> arr[n];
    //cout<<"n = "<<n<<endl;
    //cout<<"q = "<<n<<endl;

//read arrays
    for(int i = 0; i < n; i++)
    {
        int elem;
        //cout<<"i = "<<i<<endl;
        getline(cin, str);
        //cout<<str<<endl;
        ss.clear();
        ss<<str;
        while (ss>>elem)
        {
            //cout<<"el:"<<elem<<" ";
            arr[i].push_back(elem);
        }
        //cout<<endl;
    }
    ss.clear();

//read querries and print element
    int qa, qb;
    for (int i = 0; i < q; i++)
    {

        cin>>qa;
        cin>>qb;
        cout<<arr[qa].at(qb+1)<<endl;
    }
    //print arrays --> debug
    // for(int i = 0; i < n; i++)
    // {
    //     for(auto it = arr[i].begin(); it !=arr[i].end(); it++)
    //     {
    //         cout<<*it<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}
