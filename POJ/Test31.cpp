#include <iostream>
#include <string>
using namespace std;

int decode_num(int a[], int pos, int m, int n)//a[]是两位数数组,size是最后一个两位数的下一位置,m是两位数的个数,n是解码方案中需要包含的两位数的个数
{
	int temp[100];
	int num_code = 0;//解码方案个数
	if (n == 0)
	{
		return 1;//方案中没有两位数,只有1种解码方案
	}
	if (n == 1)
	{
		return m;//取1个两位数,有m种方案
	}


	int i,j = 0;
	while(a[i++] != -1) break;
	i++;
	while(j != pos) temp[j++] = a[i++];
	


	return num_code + decode_num(temp, j, m - 1, n - 1);
}

//从这里开始看起
int main()
{
	int count = 0;//记录数据的行数
	string line;//用来临时装载每一行的输入
	string str[5];//用来装载每一行临时的line,这里定义了5行
	while(cin >> line)//先把每一行统一装载str[5]中,最后再统一处理,统一输出
	{
		if(line == "0") break;
		str[count] = line;//每输入一行的数据都装入str[]中,遇0结束
		count++;
	}
	/*for (int i = 0; i < count; ++i)
	{
		cout << str[i] << endl;
	}*/

	//接下来解析每一行
	
	for (int i = 0; i < count; ++i)
	{
		int data[100];//用来装每一行的数据
		int data_2[100];//用来装有效的两位数
		
		for (int d = 0; d < 100; ++d)//全部初始化为-1,便于后面判断数据的结尾
		{
			data_2[d] = -1;
		}
		line = str[i];
		//cout << line << endl;
		int data_count = 0;//记录数据行中数字的个数
		for (data_count = 0; data_count < line.size(); ++data_count)//将line的每一位字符转为int存储在数组data中
		{
			data[data_count] = (int)(line[data_count] - '0');
			//cout << data[j];
		}

		//找出两个数的组合,如果组合连在一起(例如123,其中12和23连在一起),那么在data_2[]中就存为相邻的两项
		int data_count_2 = 0;//记录两位数的个数
		int pos;//两位数在数组中的位置
		for (pos = 0; pos < data_count - 1; ++pos)
		{
			if (data_2[pos] > 2) continue;//如果当前的数大于2,不能组成有效的两位数
		
			int temp = data[pos] * 10 + data[pos + 1];
			if (temp > 26) continue;//与下一位组成的数大于26也无效

			data_2[pos] = temp;
			data_count_2 ++;

		}

		//接下来计算解码方案的个数
		int sum = 0;
		for (int t = 0; t <= data_count_2; ++t)
		{
			sum += decode_num(data_2, pos, data_count_2, t);
		}
		
		cout << sum << endl;	

	}

	return 0;
}