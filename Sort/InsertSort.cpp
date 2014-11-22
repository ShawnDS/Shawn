#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

void InsertSort(int a[], int n)//n is the number of elements in a[]
{
    int i,j;
    int temp;
    for(i = 1; i != n; ++i)//the a[0] is ordered
    {
        j = i; 
        if(a[j] < a[j - 1])
        {
            temp = a[j];
            while(j > 0 && a[j - 1] > temp)
            {
                a[j] = a[j - 1];
                j--;
            }
            a[j] = temp;
        }  
    }
} 

int main()
{

    int a[1000];
    srand((unsigned)time(NULL));  
    for(int i = 0;i < 1000;++ i) 
    {
        a[i] = rand() % 1000;//generate 1000 integers randomly
        cout << a[i] << " ";
    }
    cout << endl;
    InsertSort(a, 1000);
    for (int i = 0; i < 1000; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}
