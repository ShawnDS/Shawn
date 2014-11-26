/*
题目
Problem

数字三角形
Time Limit: 1000ms    Memory Limit: 65536KB

描述
Descript.

示出了一个数字三角形。 请编一个程序计算从顶至底的某处的一条路径，
使该路径所经过的数字的总和最大。每一步可沿左斜线向下或右斜线向下走；1<三角形行数<25；三角形中的数字为整数<1000；

输入
Input

第一行为N，表示有N行
后面N行表示三角形每条路的路径权

输出
Output

路径所经过的数字的总和最大的答案
样例

Sample
输入数据

5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
输出数据
30
*/

#include <iostream>
using namespace std;

#ifndef MAX
#define MAX 20 //数组大小
#endif
int a[MAX][MAX] = {0};//开始用来存储输入的每一位的值,后来存储到当前位所经过的数字总和最大的值

int max_route;//存储最终到当前行的最大的路径值

//采用自底向上的动态规划(dp)
void makeMax(int n)//用于计算到当前行所经过的数字总和的最大路径的值,即max_rount,其中n代表第n行
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
    int count;//总共的层数
    cin >> count;
    //输入数据,二维数组的0下标未使用
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