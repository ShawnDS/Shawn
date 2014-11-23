/*��С��������*/
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

#ifndef MAX
#define MAX 100
#endif

int array[MAX + 1];//������������С,��0λ��Ч
int divider;//"�ָ�Ԫ��",ǰ���Ԫ�ض�����С�����,�����Ԫ�ض������
int temp;//������ʱ�洢һЩ����

int partition(int array[], int first, int last)
{
	divider = array[last];//��ʼ��Ϊ���һλԪ��
	int i = first - 1;//i���Ǵ���"�ָ�Ԫ��"ǰ����������һλԪ�ص�����
	for (int j = first; j < last; ++j)
	{
		if (array[j] <= divider)//��С������"�ָ�Ԫ��",��ôarray[j]Ӧ����"�ָ�Ԫ��"ǰ����������
		{
			i = i + 1;//"�ָ�Ԫ��"ǰ���������һλԪ�ص����� + 1
			temp = array[j];
			array[i] = array[j];
			array[j] = temp;
		}		
	}
	//����Ĳ����Ѿ������б�"�ָ�Ԫ��"С(�����)��Ԫ������ǰ��,i�����һλ������,���潫"�ָ�Ԫ��"�ŵ���ȷ�ĵط�
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
		cout << array[i] << " ";// ���0 ~ 99 ��������� 
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