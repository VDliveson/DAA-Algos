#include <iostream>
#include <algorithm>
using namespace std;

class Bag
{
public:
    int weight;
    int profit;
    Bag() {}

    Bag(int p, int w)
    {
        this->weight = w;
        this->profit = p;
    }
};

bool sorter(Bag a, Bag b)
{
    double d1 = double(a.weight) / double(a.profit);
    double d2 = double(b.weight) / double(b.profit);
    return d1 < d2;
}


void fractionalKnapsack(Bag arr[],int n,int W){
    sort(arr,arr+n,sorter);
    double finalValue=0;
    for(int i=0;i<n;i++){
        if(arr[i].weight<=W){
            finalValue+=arr[i].profit;
            W-=arr[i].weight;
        }else{
            double val=double(W)/double(arr[i].weight);
            finalValue+=arr[i].profit*val;
            break;
        }
    }

    cout<<" Final value: "<<finalValue<<endl;
}
int main()
{
    int W = 50;
    Bag items[] = {{60, 10}, {100, 20}, {120, 30}}; // Value, weight pair;
    int n = sizeof(items) / sizeof(items[0]);
    fractionalKnapsack(items, n, W);
}
