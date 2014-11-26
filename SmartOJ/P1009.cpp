/*
��Ŀ
Problem

����������
Time Limit: 1000ms    Memory Limit: 65536KB

����
Descript.

ʾ����һ�����������Ρ� ���һ���������Ӷ����׵�ĳ����һ��·����
ʹ��·�������������ֵ��ܺ����ÿһ��������б�����»���б�������ߣ�1<����������<25���������е�����Ϊ����<1000��

����
Input

��һ��ΪN����ʾ��N��
����N�б�ʾ������ÿ��·��·��Ȩ

���
Output

·�������������ֵ��ܺ����Ĵ�
����

Sample
��������

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
�������
30
*/

#include <iostream>
using namespace std;

#ifndef MAX
#define MAX 20 //�����С
#endif
int a[MAX][MAX] = {0};//��ʼ�����洢�����ÿһλ��ֵ,�����洢����ǰλ�������������ܺ�����ֵ

int max_route;//�洢���յ���ǰ�е�����·��ֵ

//�����Ե����ϵĶ�̬�滮(dp)
void makeMax(int n)//���ڼ��㵽��ǰ���������������ܺ͵����·����ֵ,��max_rount,����n�����n��
{

    int temp1, temp2;
    for (int line = 1; line <= n; ++line)
    {
        for (int column = 1; column <= line; ++column)
        {
            temp1 = a[line][column] + a[line - 1][column - 1];
            temp2 = a[line][column] + a[line - 1][column];
            a[line][column] = (temp1 > temp2) ? temp1 : temp2;
            if (a[line][column] > max_route)
            {
                max_route = a[line][column];
            }
        }
    }

}


int main(int argc, char const *argv[])
{
    int count;//�ܹ��Ĳ���
    cin >> count;
    //��������,��ά�����0�±�δʹ��
    for (int i = 1; i <= count; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    }
    //max_route = a[1][1];
    makeMax(count);
    cout << max_route << endl;

    return 0;
}