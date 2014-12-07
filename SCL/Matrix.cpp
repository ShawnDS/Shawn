#include <iostream>
using namespace std;

const int MAXM = 1010;//矩阵的最大行
const int MAXN = 1010;//矩阵的最大列
struct Matrix
{
	int m,n;//矩阵的实际大小,分别表示行和列
	int mar[101][101];//定义矩阵的最大范围
	void clear()
	{
		n = m = 0;
		memset(mar, 0 ,sizeof(mar));
	}
	//重载操作符,作为结构体的成员函数
	Matrix operator + (const Matrix &b) const//重载+
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
	Matrix operator - (const Matrix &b) const//重载-
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
	Matrix operator * (const Matrix &b) const//重载*
	{
		Matrix temp;
		temp.clear();//清零
		temp.m = m;//新矩阵的行等于*左边矩阵的行
		temp.n = b.n;//新矩阵的列等于*右边矩阵的列
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < b.n; ++j)
			{
				for (int k = 0; k < b.m; ++k)
				{
					temp.mar[i][j] += mar[i][k] * b.mar[k][j];//前面的清零操作即先将temp[i][j] 清零
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