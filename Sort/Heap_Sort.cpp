/*�ڶѵ����ݽṹ�У����е����ֵ����λ�ڸ��ڵ㡣���ж������¼��ֲ�����
���ѵ�����Max_Heapify�������ѵ�ĩ���ӽڵ���������ʹ���ӽڵ���ԶС�ڸ��ڵ�
�������ѣ�Build_Max_Heap������������������������
������HeapSort�����Ƴ�λ�ڵ�һ�����ݵĸ��ڵ㣬�������ѵ����ĵݹ�����
�������ƽ��ʱ�临�Ӷ�ΪO(nlog(n))���ռ临�Ӷ�Ϊ��(1)*/

#include <iostream>
using namespace std;

const int length = 10;//����װ�ѵ������С
int heap[length] = {0};//����ĵ�0��λ�ò�ʹ��
int largest;//��¼������������е����
int heap_size = length - 1;//��¼���ѵķ�Χ,��ʼĬ�ϵ��������С��һ,��Ϊ�ѵĽ���1��ʼ

int left(int i)//�����߽������
{
	return 2*i;
}

int right(int i)//����ұ߽������
{
	return 2*i + 1;
}

void maxHeapify(int heap[], int i)//ά�����ѵ�����:�����ӽ����丸���С
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

void buildMaxHeap(int heap[])//��������
{
	for (int i = heap_size / 2; i >= 1; --i)
	{
		maxHeapify(heap, i);
	}
}

void heapSort(int heap[])//������
{
	buildMaxHeap(heap);
	int temp;
	for (int i = length - 1; i > 1; --i)//���������heap[1],Ȼ����heap[0]����ֵ,���϶����������Ľ��,���Ϲ����µ�����
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