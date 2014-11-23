/*在堆的数据结构中，堆中的最大值总是位于根节点。堆中定义以下几种操作：
最大堆调整（Max_Heapify）：将堆的末端子节点作调整，使得子节点永远小于父节点
创建最大堆（Build_Max_Heap）：将堆所有数据重新排序
堆排序（HeapSort）：移除位在第一个数据的根节点，并做最大堆调整的递归运算
堆排序的平均时间复杂度为O(nlog(n))，空间复杂度为Θ(1)*/

#include <iostream>
using namespace std;

const int length = 10;//用来装堆的数组大小
int heap[length] = {0};//数组的第0个位置不使用
int largest;//记录最大结点在数组中的序号
int heap_size = length - 1;//记录最大堆的范围,开始默认等于数组大小减一,因为堆的结点从1开始

int left(int i)//获得左边结点的序号
{
	return 2*i;
}

int right(int i)//获得右边结点的序号
{
	return 2*i + 1;
}

void maxHeapify(int heap[], int i)//维持最大堆的性质:左右子结点比其父结点小
{
	if (left(i) < heap_size && heap[left(i)] > heap[i])
	{
		largest = left(i);
	}
	else
	{
		largest = i;
	}
	if (right(i) < heap_size && heap[right(i)] > heap[largest])
	{
		largest = right(i);
	}
	if (largest != i)
	{
		int temp = heap[i];
		heap[i] = heap[largest];
		heap[largest] = temp;
	}
}

void buildMaxHeap(int heap[])//构造最大堆
{
	for (int i = heap_size / 2; i >= 1; --i)
	{
		maxHeapify(heap, i);
	}
}

void heapSort(int heap[])//堆排序
{
	buildMaxHeap(heap);
	int temp;
	for (int i = length - 1; i > 1; --i)//倒序遍历到heap[1],然后与heap[0]交换值,不断丢弃堆最后面的结点,不断构造新的最大堆
	{
		temp = heap[1];
		heap[1] =  heap[i];
		heap[i] = temp;
		heap_size--;
		maxHeapify(heap, 1);
	}
}


int main(int argc, char const *argv[])
{
	for (int i = 1; i <= heap_size; ++i)
	{
		cin >> heap[i];
	}
	cout << endl;
	heapSort(heap);

	for (int i = 1; i < length ; ++i)
	{
		cout << heap[i] << " ";
	}
	cout << endl;
	return 0;
}