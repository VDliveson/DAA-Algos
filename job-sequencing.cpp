#include <iostream>
#include <algorithm>
using namespace std;

class Job
{
public:
    char name;
    int deadline;
    int profit;

    Job(){};

    Job(char n, int d, int p)
    {
        this->name = n;
        this->deadline = d;
        this->profit = p;
    }
};

bool sorter(Job a, Job b){
    return a.profit > b.profit;
}

void jobSequencing(Job arr[],int n){
    sort(arr,arr+n,sorter);

    int result[n],slot[n];

    for(int i = 0; i < n; i++){
        slot[i] = false;
    }

    for(int i=0;i< n;i++){
        for(int j=min(arr[i].deadline,n)-1;j>=0;j--){
            if(slot[j] == false){
                slot[j] = true;
                result[j] = i;
                break;
            }
        }
    }

    for(int i=0;i< n;i++){
        if(slot[i] == true){
            cout<<arr[result[i]].name<<" ";
        }
    }
}

int main()
{
    Job arr[] = {{'a', 2, 100},
                 {'b', 1, 19},
                 {'c', 2, 27},
                 {'d', 1, 25},
                 {'e', 3, 15}};

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Following is maximum profit job sequence of jobs" << endl;
    jobSequencing(arr, n);
}