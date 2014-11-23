/*求高精度幂 Time Limit: 500MS Memory Limit: 10000K

Description
对数值很大、精度很高的数进行高精度计算是一类十分常见的问题。比如，对国债进行计算就是属于这类问题。
现在要解决的问题是：对一个实数R( 0.0 < R < 99.999 )，要求写程序精确计算 R 的 n 次方(R^n)，其中n 是整数并且 0 < n <= 25。 

Input
T输入包括多组 R 和 n。 R 的值占第 1 到第 6 列，n 的值占第 8 和第 9 列。
 
Output
对于每组输入，要求输出一行，该行包含精确的 R 的 n 次方。输出需要去掉前导的 0 后不要的 0 。如果输出是整数，不要输出小数点。 
Sample Input

95.123 12 0.4321 20 5.1234 15 6.7592 9 98.999 10 1.0100 12

Sample Output

548815620517731830194541.899025343415715973535967221869852721

.00000005148554641076956121994511276767154838481760200726351203835429763013462401

43992025569.928573701266488041146654993318703707511666295476720493953024

29448126.764121021618164430206909037173276672

90429072743629540498.107596019456651774561044010001

1.126825030131969720661201*/

#include <iostream>
#include <string>
using namespace std;

int main(){
	string R; //底数
	int n = 1; //指数
	string str[10]; //存放输入的一组底数
	string _str;//存放输入的临时底数
	int ns[10];//存放输入的一组指数
	int _n;//存放输入的临时指数
	int count = 0;
	while(cin >> _str >> _n)
	{
		str[count] = _str;
		ns[count] = _n;
		//cout << str[count] << " " << n[count] << endl;
		count++;
	}


	//对每组数据分别处理后输出
	for(int z = 0; z < count; ++z)
	{
		R = str[z];
		n = ns[z];
		char r[6] = {'a','a','a','a','a','a'};//string底数转存在r[6]中,初始全部置为'a',记得结束符
		int m[250] = {0};//存放最终的结果
		int b[6] = {0};//存放string底数转化为int后的每一位
		int m_i = -1; //m_i记录小数点的位置
		int m_mumber = 0,m_data = 0;//小数部分总共位数,每次相乘的数
		for (string::size_type ix = 0; ix != R.size(); ++ix) // 找到小数点的位置
		{

			if (R[ix] == '.')
			{
				m_i = ix;
				break;
			}
		}

		//下面将string转存到char[]中
		if (m_i == -1)//说明没有小数点(R为1位或者2位的整数)
		{
			if (R.size() == 2)
			{
				r[0] = R[0];
				r[1] = R[1];
			}
			else
			{
				r[1] = R[0];
			}


		}
		else//说明有小数点
		{
			r[m_i] = '.';
			if (m_i == 2)//整数部分有两位
			{
				r[0] = R[0];
				r[1] = R[1];
				/*for (int a = 3, b = m_i + 1; b < R.size(); ++a, ++b)//小数部分的处理
				{
					r[a] = R[b];
				}*/

			}
			else//整数部分有一位
			{
				if (R[0] != '0')//整数部分不为0
				{
					r[0] = R[0];
				}
				/*for (int a = 2, b = m_i + 1; b < R.size(); ++a, ++b)//小数部分的处理
				{
					r[a] = R[b];
				}*/
			}
			for (int a = m_i + 1, b = m_i + 1; b < R.size(); ++a, ++b)//小数部分的处理
				{
					r[a] = R[b];
				}


			//将小数部分后面无用的0置为a,便于"有效部分"放入b[6]中
			int x = 5;
			while(r[x] == '0' || r[x] == 'a')
			{
				x--;
			}
			for (int v = 5; v > x; --v)//把本来为'a'的也重新置为'a'了,有待改进
			{
				r[v] = 'a';
			}

			for (int c = 5; c >= 0; --c)//判断有效的小数位
			{
				if(r[c] == 'a') continue;
				if(r[c] == '.') break;
				m_mumber++;

			}
			m_mumber = m_mumber * n;//总共小数的位数
		}





		int i,j;
		for (i = 0, j = 0; i < 6; ++i)//将R转换为int
		{
			if (r[i] == 'a' || r[i] == '.')
				continue;
			b[j] = (int)(r[i] - '0');
			j++;
		}
		while(j < 6){//把b[6]后面的0置为-1
			b[j] = -1;
			j++;
		}


		
		for (i = 0; i < 6; ++i)
		{
			if (b[i] == -1) continue;
			
			m_data = m_data * 10 + b[i];//每一步相乘的数
		}
		


		for (j = 5, i = 250 - 1; j >= 0 && i >=0; --j)//b[]的有效部分放入m[]中(最后面)
		{
			if (b[j] == -1) continue;
			m[i] = b[j];
			i--;
		}
		

		
		
		
		n--;//即用R乘以 n - 1 次 R
		while(n-- && i != 249)
		{
				//下面for循环相当于模拟列竖式乘法
			for (j = i + 1; j < 250; j++)//m[]中有这么多位有效数字
			{
				int temp = m[j] * m_data;//m[]每一位与m_data的乘积
				m[j] = 0;
				int t = j;//转存j到t,因为后面有进位,但是j在此次循环中不能改变
				while(temp / 10 != 0 || temp % 10 != 0)//如果temp不为0
				{
					m[t] = m[t] + temp % 10;
					//cout << m[t] << " ";
					int temp_j = t;//同理,转存一下t,因为在此次循环中t不能变
					while(m[temp_j] > 9)//如果大于9则要进位
					{
						int temp2 = m[temp_j];
						m[temp_j] = temp2 % 10;
						temp_j--;//进位
						m[temp_j] = m[temp_j] + temp2 / 10;
					}
					t--;
				
					temp = temp / 10;
					//cout << temp << " ";					
				
				}

			}

			i = 0;
			while(m[i] == 0)//找到m中第一个非零的数
				i++;
			i--;//对应前面的for中的j = i + 1;
		}




		// 下面开始输出
		i = 0;
		while(i < 250 && m[i] == 0)//找到第一个非0
		{
			i++;
		}

		if (m_mumber == 0)//如果没有小数点
		{
			if (i == 250)
			{
				cout << 0 << endl;
			}
			else
			{
				for (; i < 250; ++i)
				{
					cout << m[i];
				}
				cout << endl;
			}
		}
		else//如果有小数点
		{
			if (m_mumber > 250 - i)//小数位超过"有效部分",需要补0
			{
				cout << ".";
				while(m_mumber-- > 250 - i)//补0
				{
					cout << 0;
				}
				for (; i < 250; ++i)
				{
					cout << m[i];
				}
				cout << endl;

			}
			else
			{
				for (; i < 250; ++i)
				{
					
					if (250 - i == m_mumber)
					{
						cout << ".";
					}
					cout << m[i];
				}
				cout << endl;
			}
		}
		

	}
	

	return 0;
}