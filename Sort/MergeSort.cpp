//未知的bug: 中文多行注释结尾的汉字与 */ 之间要有空格

/* 归并排序，其的基本思路就是将数组分成二组A，B，如果这二组组内的数据都是有序的，
那么就可以很方便的将这二组数据进行排序。如何让这二组组内数据有序？可以将A，B组
各自再分成二组。依次类推，当分出来的小组只有一个数据时，可以认为这个小组组内已经
达到了有序，然后再合并相邻的二个小组就可以了。这样通过先递归的分解数列，再合并数
列就完成了归并排序。这里待排序数列是a[],中间用temp[]转存,最后排好序的数列还是a[],
每次的二分只是将a[]分为两部分,并没有分别放入两个数组中,这样节约空间,不必开辟多个
数组来存放 */

#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;


void sort(int a[], int first, int mid, int last, int temp[])//将有序的两个数列合并到一个数列
{
	int i = first, j = mid + 1;
	int m = mid, n = last;
	int k = 0;

	while(i <= m && j <=n)
	{
		if (a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];
		}
	}
	while(i <= m)
	{
		temp[k++] = a[i++];
	}
	while(j <= n)
	{
		temp[k++] = a[j++];
	}
	for (i = 0; i < k; ++i)//将已排好序的数列放回a[]中
	{
		a[first + i] = temp[i];//原来的待排序数列是从从first开始的
	}
}

void merge(int a[], int first, int last, int temp[])
{
	if (first < last)
	{
		int mid = (first + last) / 2;
		merge(a, first, mid, temp);//前半部分递归
		merge(a, mid + 1, last, temp);//后半部分递归
		sort(a, first, mid, last, temp);
	}
}

bool MergeSort(int a[], int n)
{
	int *temp = new int[n];
	if (temp == 0)
	{
		return false;
	}
	merge(a, 0, n - 1, temp);
	delete [] temp;
	return true;
}

int main()
{
	int a[100];
	srand((unsigned)time(NULL));  
	for(int i = 0;i < 100;++ i) 
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";// 输出0 ~ 99 的随机数字 
	}
	cout << endl;

	MergeSort(a, 100);
	for (i = 0; i < 100; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}
