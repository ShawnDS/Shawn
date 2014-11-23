/*1001. Alphacode

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description

Alice and Bob need to send secret messages to each other and are discussing ways to 
encode their messages: Alice: "Let's just use a very simple code: We'll assign `A' 
the code word 1, `B' will be 2, and so on down to `Z' being assigned 26." 
Bob: "That's a stupid code, Alice. Suppose I send you the word `BEAN' encoded as 
25114. You could decode that in many different ways!" Alice: "Sure you could, but
 what words would you get? Other than `BEAN', you'd get `BEAAD', `YAAD', `YAN', `YKD' 
 and `BEKD'. I think you would be able to figure out the correct decoding. And why 
 would you send me the word `BEAN' anyway?" Bob: "OK, maybe that's a bad example, but
  I bet you that if you got a string of length 500 there would be tons of different 
  decodings and with that many you would find at least two different ones that would 
  make sense." Alice: "How many different decodings?" Bob: "Jillions!" For some reason, 
  Alice is still unconvinced by Bob's argument, so she requires a program that will 
  determine how many decodings there can be for a given string using her code.

Input

Input will consist of multiple input sets. Each set will consist of a single line 
of digits representing a valid encryption (for example, no line will begin with a 0). 
There will be no spaces between the digits. An input line of `0' will terminate the input
 and should not be processed

Output

For each input set, output the number of possible decodings for the input string. All 
answers will be within the range of a long variable.

Sample Input

25114
1111111111
3333333333
0
Sample Output

6
89
1 */

/*dp方程为 a[n] = a[n-1]+a[n-2]，输入的字符串一次为X1X2X3…Xn…

        当Xn = 0时，a[n] = a[n-2]

        当Xn != 0时，

               若X(n-1)与X(n)组成的数大于26， a[n] = a[n-1].

               若X(n-1)与X(n)组成的数<=26,

                      x(n-1) != 0时, a[n] = a[n-1] + a[n-2]

                      x(n-1) = 0时，  a[n] = a[n-1]
*/
#include <iostream>
#include <string>
#define MAX 100000//尽量大一点
using namespace std;
 
int main()
{
    string num;//输入的数字字符串
    int a[MAX];//加码方案数,a[i]表示前i个数的方案数(从0开始),0表示1个数,1表示2个数
    int size;//输入字符串的数字数目
    int n;//组成的两位数的大小
    while (cin >> num && num != "0")
    {
        size = num.size();
        a[0] = 1;//1个数1种解码方案
        a[1] = 1;//默认两个数1种解码方案
 
        if (size == 1)//只输入了1个数,1种解码方案
        {
            cout << a[0] << endl;
            continue;
        }
         
        //对第二位处理    
        n = (int)(num[0]-'0')*10 + (int)(num[1]- '0');
        if (n <= 26 && num[1] != '0')//两位数有效,且第二位非零,2个数则有2种解码方案
            a[1] = 2;
             
        for (int i = 2; i < size; i++)//超过2个数的判断
        {
            if (num[i] == '0')//如果第i位为0,则第 i - 1 位一定要与第 i 位组成两位数
                a[i] = a[i-2];
            else
            {
                a[i] = a[i-1];
                n = (int)(num[i-1]-'0')*10 + (int)(num[i]-'0');
 
                if (n <= 26 && num[i-1] != '0')
                    a[i] = a[i-1] + a[i-2];
            }
             
        }
        cout << a[size-1] << endl;
    }
 
    return 0;
}