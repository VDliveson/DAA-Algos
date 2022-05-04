#include <iostream>
using namespace std;
class BinarySearch
{
public:
    void binarySearch_iterative(int arr[], int n, int el)
    {
        int low = 0, high = n - 1;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (el == arr[mid])
            {

                cout << "Element found at index : " << mid << endl;
                break;
            }
            else if (el < arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return;
    }

    int binarySearch_recursive(int arr[], int l, int h, int el)
    {
        if (h >= l)
        {
            int mid = (l + h) / 2;

            if (arr[mid] == el)
            {
                return mid;
            }
            else if (arr[mid] > el)
            {
                return binarySearch_recursive(arr, l, mid - 1, el);
            }
            else if (arr[mid] < el)
            {
                return binarySearch_recursive(arr, mid + 1, h, el);
            }
        }
        return -1;
    }
};
int main()
{
    int array[] = {1, 2, 2, 3, 5, 7};
    int n = sizeof(array) / sizeof(array[0]);
    BinarySearch bs;
    bs.binarySearch_iterative(array, n, 5);
    cout << "From recursion,element found at index : "<<bs.binarySearch_recursive(array, 0, n - 1, 5);
}