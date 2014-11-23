#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin>>t;
	for(int z=1;z<=t;z++)
	{
		int num;
		cin>>num;
		queue<short> deck[11];
		short result[11],temp;
		for(int i=0;i<52;i++)     //初始化
		{
			cin>>temp;
			deck[0].push(temp);
		}
		bool win=false;
		short totalsteps[11]={0};     //记录总数以便判断是否出现死循环（lose）
		short count[11]={0};        //记录人数的数
		short j=0;   //遍历每个人
		short totalcard=52;     //判断牌是否全部丢弃，为0则是
		while(!win)
		{
			if(deck[j].empty())
			{
				j++;
				if(j>=num) j=0;
				continue;
			}
			totalsteps[j]++;
			count[j]++;
			if(count[j]==deck[j].front())
			{
				deck[j+1].push(deck[j].front());
				totalsteps[j]=0;
				if(j+1==num) totalcard--;    //j+1==num时牌被放在假想人手上，总牌数减一
				result[j]=deck[j].front();
				deck[j].pop();
			}
			else 
			{
				deck[j].push(deck[j].front());
				deck[j].pop();
			}
			if(totalsteps[j]>(int)deck[j].size()*13)
			{
				win=false; break;
			}
			if(totalcard==0) win=true;
			if(count[j]==13) count[j]=0;
			j++;
			if(j>=num) j=0;
		}
		if(win)
		{
			cout<<"Case "<<z<<":";
			for(int i=0;i<num;i++)
				cout<<" "<<result[i];
			cout<<endl;
		}
		else cout<<"Case "<<z<<": unwinnable"<<endl;
	}
	return 0;
}