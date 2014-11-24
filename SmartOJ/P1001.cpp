/*计算两个很大的正整数的和*/
#include <iostream>
#include <string>
using namespace std;
#ifndef MAX
#define MAX 100000
#endif
string str1, str2;
int sum[MAX];//最终结果
int index = MAX - 1;

void bigIntegerAdd(string str1, string str2)
{
    int count_smaller = (str1.size() < str2.size()) ? str1.size() : str2.size();//较短字符串的长度
    int count_bigger = (str1.size() > str2.size()) ? str1.size() : str2.size();//较长字符串的长度
    count_smaller--;
    count_bigger--;
    if (str1.size() <= str2.size())
    {
        sum[index] = ((int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) % 10;//先计算和的最后一位
        int carry = ((int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) / 10;//进位
        count_smaller--;
        count_bigger--;
        index--;
        while (count_smaller + 1) //把较短的全部计算完,一直到较短的第0位,注意当前位的计算与进位
        {
            sum[index] = (carry + (int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) % 10;
            carry = (carry + (int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) / 10;
            index--;
            count_smaller--;
            count_bigger--;

        }
        while (count_bigger + 1)//对较长的字符串超出较短字符串部分的处理
        {
            sum[index] = ((int)(str2[count_bigger] - '0') + carry) % 10;
            carry = ((int)(str2[count_bigger] - '0') + carry) / 10;
            count_bigger--;
            index--;
        }
    } 
    else
    {
        sum[index] = ((int)(str2[count_smaller] - '0') + (int)(str1[count_bigger] - '0')) % 10;
        int carry = ((int)(str2[count_smaller] - '0') + (int)(str1[count_bigger] - '0')) / 10;
        count_smaller--;
        count_bigger--;
        index--;
        while (count_smaller + 1) 
        {
            sum[index] = (carry + (int)(str2[count_smaller] - '0') + (int)(str1[count_bigger] - '0')) % 10;
            carry = (carry + (int)(str2[count_smaller] - '0') + (int)(str1[count_bigger] - '0')) / 10;
            index--;
            count_smaller--;
            count_bigger--;

        }
        while (count_bigger + 1)//对较长的字符串超出较短字符串部分的处理
        {
            sum[index] = ((int)(str1[count_bigger] - '0') + carry) % 10;
            carry = ((int)(str1[count_bigger] - '0') + carry) / 10;
            count_bigger--;
            index--;
        }
    }



}

int main(int argc, char const *argv[])
{
    cin >> str1 >> str2;
    bigIntegerAdd(str1, str2);
    int i;
    for (i = 0; i < MAX - 1; ++i)//找到数组中第一个非0,只遍历到倒数第二位,因为如果全部都是0结果要输出0
    {
        if (sum[i] != 0)
        {
            break;
        }
    }
    for (int j = i; j < MAX; j++)
    {
        cout << sum[j];
    }
    //cout << endl;
    return 0;
}