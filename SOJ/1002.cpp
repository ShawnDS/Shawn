/*1002. Anti-prime Sequences

Constraints

Time Limit: 3 secs, Memory Limit: 32 MB

Description

Given a sequence of consecutive integers n,n+1,n+2,...,m, an anti-prime sequence 
is a rearrangement of these integers so that each adjacent pair of integers sums 
to a composite (non-prime) number. For example, if n = 1 and m = 10, one such 
anti-prime sequence is 1,3,5,4,2,6,9,7,8,10. This is also the lexicographically 
first such sequence. We can extend the definition by defining a degree danti-prime 
sequence as one where all consecutive subsequences of length 2,3,...,d sum to a 
composite number. The sequence above is a degree 2 anti-prime sequence, but not a 
degree 3, since the subsequence 5, 4, 2 sums to 11. The lexicographically .rst 
degree 3 anti-prime sequence for these numbers is 1,3,5,4,6,2,10,8,7,9.

Input

Input will consist of multiple input sets. Each set will consist of three integers, 
n, m, and d on a single line. The values of n, m and d will satisfy 1 <= n < m <= 1000, 
and 2 <= d <= 10. The line 0 0 0 will indicate end of input and should not be processed.

Output

For each input set, output a single line consisting of a comma-separated list of integers 
forming a degree danti-prime sequence (do not insert any spaces and do not split the output 
over multiple lines). In the case where more than one anti-prime sequence exists, print the 
lexicographically first one (i.e., output the one with the lowest first value; in case of a 
tie, the lowest second value, etc.). In the case where no anti-prime sequence exists, output 
No anti-prime sequence exists.

Sample Input

1 10 2
1 10 3
1 10 5
40 60 7
0 0 0
Sample Output

1,3,5,4,2,6,9,7,8,10
1,3,5,4,6,2,10,8,7,9
No anti-prime sequence exists.
40,41,43,42,44,46,45,47,48,50,55,53,52,60,56,49,51,59,58,57,54*/

#include <iostream>
#include <cstring>

using namespace std;

//定义所需的全局变量
int seq[1000];//用来装最后答案序列,题目要求最多1~1000的数,所以这里至少1000
int exc[1001];//用来标记序列中的数是否已经使用过,1表示使用过,默认为0,特别要注意,后面代码exc[i] = 1,没有使用exc[0],这里要多开一位,不然测试1~1000的数据没有结果,严重超时
int begin,end,degree;
bool hasAnswer;//最终序列是否存在



//判断是否素数
bool isPrimer(int a)
{
	for (int i = 2; i * i <= a; ++i)//这里i * i <= a可以提高效率
	{
		if (a % i == 0)
		{
			return false;
		}
	}
	return true;
}


//判断数字a是否可以装入最终序列seq[]中
bool check(int index, int a)
{
	for (int i = index - 1; i >= 0 && i >= index - degree + 1; --i)//a是检测的数字,看是否能放在seq[index]位置上
	{
		a += seq[i];
		if (isPrimer(a))//不是合数,返回false
		{
			return false;
		}
	}
	return true;
}

/* 构造满足条件的最终序列(回溯法),判断当前index位放哪个数,从小到大遍历,如果发现剩下的数(exc[i] = 0)都不合适,则要回到上一个位置重新放一个数,依此类推 */
void makeSeq(int index)
{
	for (int i = begin; i <= end; ++i)//从begin到end的顺序序列
	{
		if (exc[i] == 0 && check(index, i))//数字i可以放入seq[index]
		{
			seq[index] = i;
			exc[i] = 1;//数字i已经使用了

			if (index == end - begin)//如果index已经是最后一位,相当于全部数字都已经排好
			{
				hasAnswer = 1;

				return ;
			}
			//如果不是最后一位,放下一位置的数字
			makeSeq(index + 1);

			//能执行到这一句,说明makeSeq(index + 1)没有成功放置数字,要回溯到index重新放一个数,for循环会进入下次,检测一下hasAnswer,如果
			//已经有答案了,就不用再进行了,直接返回.
			if (hasAnswer)
			{
				return;//递归逐层返回
			}
			exc[i] = 0;//进入下次for循环之前,刚才index位置放的数以后还可以使用,要置零

		}
	}
}
 

int main()
{
	

	while(cin >> begin >> end >> degree)
	{
		if (begin == 0 && end == 0 && degree == 0)//遇输入0 0 0结束
		{
			break;
		}
		hasAnswer = 0;
		memset(exc, 0, sizeof(exc));//每次输入都要对exc[]重新归零
		

		makeSeq(0);//从index = 0开始放
		
		if (hasAnswer)
		{
			cout << seq[0];
			for (int i = 1; i <= end - begin; ++i)
			{
				cout << ',' << seq[i];
			}
			cout << endl;
		}
		else
		{
			cout << "No anti-prime sequence exists." << endl;
		}

	}
	return 0;
}