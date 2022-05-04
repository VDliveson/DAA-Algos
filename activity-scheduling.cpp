#include<iostream>
#include <algorithm>
using namespace std;

class Activity{
    public:
     int start;
    int end;
    Activity(){}
    Activity(int start,int end){
        this->start = start;
        this->end = end;
    }

};

bool sorter(Activity a, Activity b){
    return a.end < b.end;
}

void activityScheduling(Activity arr[], int n){
    int i=0;
    sort(arr,arr+n,sorter);
    cout<< " Start time "<<" End Time "<<endl;
    cout<<arr[0].start<<" "<<arr[0].end<<endl;
    for(int j=1; j<n; j++){
        if(arr[j].start>=arr[i].end){
            cout<<arr[j].start<<" "<<arr[j].end<<endl;
            i=j;
        }
    }

}

int main(){
    Activity arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]);
    activityScheduling(arr,n);
    return 0;
}