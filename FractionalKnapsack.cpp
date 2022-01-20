#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node{
    int item_no;
    int benifit;
    int weight;
};

bool compare(struct node x, struct node y){
    return float(x.benifit)/float(x.weight) > float(y.benifit)/float(y.weight);
}

void fractionalKnapsack(node a[], int n, int w){
    int currentWeight = 0, r;
    float totalBenefit = 0.00;
    sort(a, a+n, compare);

    cout<<"Solution: "<<endl;
    for(int i=0; i<n; i++){
        if(currentWeight+a[i].weight <= w){
            currentWeight += a[i].weight;
            totalBenefit += a[i].benifit;
            cout<<a[i].weight<<" ml of "<<a[i].item_no<<": "<<a[i].benifit<<endl;
        }
        else{
            r = w - currentWeight;
            totalBenefit += a[i].benifit * float(r)/float(a[i].weight); 
            cout<<r<<" ml of "<<a[i].item_no<<": "<<a[i].benifit * float(r)/float(a[i].weight)<<endl;
            break;
        }
    }

    cout<<"Total Profit: "<<totalBenefit<<endl;
}


int main(void){
    int n, w;

    // ifstream inputFile("Knapsack.txt");
    // inputFile >> n;
    // inputFile >> w;
    // node a[n];
    // int i=0;
    // while(!inputFile.eof()){
    //     inputFile >> a[i].benifit;
    //     inputFile >> a[i].weight;
    //     a[i].item_no = i+1;
    //     if(i<n)
    //         i++;
    //     else 
    //         break;
    // }
    // inputFile.close();

    cout<<"Enter the number of items: ";
    cin>>n;
    cout<<"\nEnter the weight of knapsack: ";
    cin>>w;
    node a[n];
    cout<<"\nEnter the benifit and weight of each item: "<<endl;
    for(int i=0; i<n; i++){
        cin>>a[i].benifit>>a[i].weight;
        a[i].item_no = i+1;
    }

    fractionalKnapsack(a,n,w);

    return 0;
}