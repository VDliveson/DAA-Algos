#include <iostream>
#include <stack>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

class Quicksort_recursive
{
public:
    int partition(int array[], int l, int h)
    {
        int x = array[h];
        int i = l - 1;
        for (int j = l; j < h; j++)
        {
            if (array[j] <= x)
            {
                i++;
                swap(&array[i], &array[j]);
            }
        }
        swap(&array[i + 1], &array[h]);
        return (i + 1);
    }
    void quicksort(int array[], int l, int h)
    {
        if (l < h)
        {
            int p = partition(array, l, h);
            quicksort(array, l, p - 1);
            quicksort(array, p + 1, h);
        }
    }
};

class Quicksort_iterative
{
public:
    int partition(int array[], int l, int h)
    {
        int x = array[h];
        int i = l - 1;
        for (int j = l; j < h; j++)
        {
            if (array[j] <= x)
            {
                i++;
                swap(&array[i], &array[j]);
            }
        }
        swap(&array[i + 1], &array[h]);
        return i+1;
    }

    void quicksort_iterative(int array[], int l, int h){
        stack<int> st;
        st.push(l);
        st.push(h);
        while(!st.empty()){
            h=st.top();
            st.pop();
            l=st.top();
            st.pop();
            int p=partition(array,l,h);
            if(p-1>l){
                st.push(l);
                st.push(p-1);
            }

            if(p+1<h){
                st.push(p+1);
                st.push(h);
            }
        }

    }
};

int main()
{
    int array1[] = {1, 24, 6, 14, 64, 98, 123, 0};
    int array2[]={1, 24, 6, 14, 64, 98, 123, 0};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    Quicksort_iterative qi;
    Quicksort_recursive qr;
    qr.quicksort(array1, 0, n1 - 1);
    qi.quicksort_iterative(array2,0,n2-1);

    for (int i = 0; i < n1; i++)
    {
        cout << array1[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n2; i++)
    {
        cout << array2[i] << " ";
    }

}
