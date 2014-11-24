/*���������ܴ���������ĺ�*/
#include <iostream>
#include <string>
using namespace std;
#ifndef MAX
#define MAX 100000
#endif
string str1, str2;
int sum[MAX];//���ս��
int index = MAX - 1;

void bigIntegerAdd(string str1, string str2)
{
    int count_smaller = (str1.size() < str2.size()) ? str1.size() : str2.size();//�϶��ַ����ĳ���
    int count_bigger = (str1.size() > str2.size()) ? str1.size() : str2.size();//�ϳ��ַ����ĳ���
    count_smaller--;
    count_bigger--;
    if (str1.size() <= str2.size())
    {
        sum[index] = ((int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) % 10;//�ȼ���͵����һλ
        int carry = ((int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) / 10;//��λ
        count_smaller--;
        count_bigger--;
        index--;
        while (count_smaller + 1) //�ѽ϶̵�ȫ��������,һֱ���϶̵ĵ�0λ,ע�⵱ǰλ�ļ������λ
        {
            sum[index] = (carry + (int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) % 10;
            carry = (carry + (int)(str1[count_smaller] - '0') + (int)(str2[count_bigger] - '0')) / 10;
            index--;
            count_smaller--;
            count_bigger--;

        }
        while (count_bigger + 1)//�Խϳ����ַ��������϶��ַ������ֵĴ���
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
        while (count_bigger + 1)//�Խϳ����ַ��������϶��ַ������ֵĴ���
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
    for (i = 0; i < MAX - 1; ++i)//�ҵ������е�һ����0,ֻ�����������ڶ�λ,��Ϊ���ȫ������0���Ҫ���0
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