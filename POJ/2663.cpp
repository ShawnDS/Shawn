/*						Tri Tiling
Time Limit: 1000MS		Memory Limit: 65536K
Total Submissions: 7988		Accepted: 4179
Description

In how many ways can you tile a 3xn rectangle with 2x1 dominoes? 
Here is a sample tiling of a 3x12 rectangle. 

Input

Input consists of several test cases followed by a line containing -1. 
Each test case is a line containing an integer 0 <= n <= 30.

Output

For each test case, output one integer number giving the number of possible tilings.

Sample Input

2
8
12
-1

Sample Output

3
153
2131
此题的关键在于递推公式a[i] = 4 * a[i - 2] - a[i - 4]
*/
#include <iostream>
using namespace std;

int a[31] = {1,0,3};

int main(int argc, char const *argv[])
{
	int input;
	while(cin >> input)
	{
		if (input == -1)
		{
			return 0;
		}
		for (int i = 4; i <= input; ++i)
		{
			a[i] = 4 * a[i - 2] - a[i - 4];
		}
		cout << a[input] << endl;
	}
	return 0;
}