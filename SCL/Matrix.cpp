#include <iostream>
using namespace std;

const int MAXM = 1010;//����������
const int MAXN = 1010;//����������
struct Matrix
{
	int m,n;//�����ʵ�ʴ�С,�ֱ��ʾ�к���
	int mar[101][101];//�����������Χ
	void clear()
	{
		n = m = 0;
		memset(mar, 0 ,sizeof(mar));
	}
	//���ز�����,��Ϊ�ṹ��ĳ�Ա����
	Matrix operator + (const Matrix &b) const//����+
	{
		Matrix temp;
		temp.m = m;
		temp.n = n;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				temp.mar[i][j] = mar[i][j] + b.mar[i][j];
			}
		}
		return temp;
	}
	Matrix operator - (const Matrix &b) const//����-
	{
		Matrix temp;
		temp.m = m;
		temp.n = n;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				temp.mar[i][j] = mar[i][j] - b.mar[i][j];
			}
		}
		return temp;
	}
	Matrix operator * (const Matrix &b) const//����*
	{
		Matrix temp;
		temp.clear();//����
		temp.m = m;//�¾�����е���*��߾������
		temp.n = b.n;//�¾�����е���*�ұ߾������
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < b.n; ++j)
			{
				for (int k = 0; k < b.m; ++k)
				{
					temp.mar[i][j] += mar[i][k] * b.mar[k][j];//ǰ�������������Ƚ�temp[i][j] ����
				}
			}
		}
		return temp;
	}


};


int main(int argc, char *argv[])
{
	Matrix mar1,mar2;
	mar1.m = 3;
	mar1.n = 2;
	mar2.m = 2;
	mar2.n = 3;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << (mar1.mar[i][j] = i + j + 1) << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cout << (mar2.mar[i][j] = i + j + 1) << " ";
		}
		cout << endl;
	}
	


	return 0;
}