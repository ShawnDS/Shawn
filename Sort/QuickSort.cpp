/*由小到大排列*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#ifndef MAX
#define MAX 100
#endif

int array[MAX + 1];//待排序的数组大小,第0位无效
int divider;//"分割元素",前面的元素都比其小或相等,后面的元素都比其大
int temp;//用来临时存储一些数据

int partition(int array[], int first, int last)
{
	divider = array[last];//初始化为最后一位元素
	int i = first - 1;//i总是代表"分割元素"前的数组的最后一位元素的索引
	for (int j = first; j < last; ++j)
	{
		if (array[j] <= divider)//大小不超过"分割元素",那么array[j]应该在"分割元素"前的子数组中
		{
			i = i + 1;//"分割元素"前的数组最后一位元素的索引 + 1
			temp = array[j];
			array[i] = array[j];
			array[j] = temp;
		}		
	}
	//上面的步骤已经将所有比"分割元素"小(或等于)的元素排在前面,i是最后一位的索引,下面将"分割元素"放到正确的地方
	int t = array[i + 1];
	array[i + 1] = array[last];
	array[last] = t;
	return i + 1;
}

void qiuckSort(int array[], int first, int last)
{
	if (first < last)
	{
		int q = partition(array, first, last);
		qiuckSort(array, first, q - 1);
		qiuckSort(array, q + 1, last);
	}
}

int main(int argc, char const *argv[])
{
	srand((unsigned)time(NULL));  
	for(int i = 1;i <= MAX; ++i) 
	{
		array[i] = rand() % MAX;
		cout << array[i] << " ";// 输出0 ~ 99 的随机数字 
	}
	cout << endl;

	qiuckSort(array,1,MAX);
	for (int i = 1; i <= MAX; ++i)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}