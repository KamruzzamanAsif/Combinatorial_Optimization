#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
    int starting_time;
    int finishing_time;
};

bool compare(node x, node y){
    return x.finishing_time < y.finishing_time;
}

void maxActivity(node a[], int n){
    sort(a, a+n, compare);

    int i = 0, x=1;
    cout<<"The activities are:\n";
    cout<<"Activity no."<<x<<" :: start at: "<<a[i].starting_time<<" finish at:" <<a[i].finishing_time;
    for(int j=1; j<n; j++){
        if(a[j].starting_time >= a[i].finishing_time){
            x++;
            cout<<"\nActivity no."<<x<<" :: start at: "<<a[j].starting_time<<" finish at:" <<a[j].finishing_time;
            i = j;
        }
    }
    cout<<"\nMaximum number of Activities are: "<<x<<endl;
}

int main(void){
    int n;

/* Note: txt file and terminal input rules: 
                            first line: number of activities n
                            then n lines: starting time and finishing time */

    //freopen("Activity.txt", "r", stdin);
    cin>>n;
    node a[n];
    for(int i=0; i<n; i++){
        cin>>a[i].starting_time>>a[i].finishing_time;
    }

    maxActivity(a,n);

    return 0;
}