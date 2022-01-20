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

    // ifstream inputFile("Activity.txt");
    // inputFile >> n;
    // node a[n];
    // int i=0;
    // while(!inputFile.eof()){
    //     inputFile >> a[i].starting_time;
    //     inputFile >> a[i].finishing_time;
    //     if(i<n)
    //         i++;
    //     else 
    //         break;
    // }
    // inputFile.close();

    cout<<"Enter the number of activities: ";
    cin>>n;
    node a[n];
    cout<<"\nEnter starting and finishing time of each activity: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i].starting_time>>a[i].finishing_time;
    }

    maxActivity(a,n);

    return 0;
}