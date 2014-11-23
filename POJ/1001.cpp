#include <iostream>
using namespace std;
int main()
{
    char r[6]={'0'};//底数 
    int n=1;//指数 
    while(cin>>r>>n)
    {
        int m[250]={0};
        int b[6]={0};
        int i,j,m_i;
        int m_number=0,m_data=0;//小数点个数，每次相乘的数据 
        for(i=0;i<6;i++)//找到小数点的位置 
        {
            if(r[i]=='.')
            {
                m_i=i;
                break;
            }
        }
        if(i==6)//说明没有小数点
        {
            j=0;
            while(r[j]=='0')
            {
                r[j]='a';
                j++;
            }
            m_number=0;
        }
        else//说明有小数点 
        {
            i=0;
            while(i<m_i&&r[i]=='0')//小数点之前前导0处理为-1
            {
                r[i]='a';//这里不是应该赋值为'-1'吗?
                i++;
            }
            i=5;
            while(i>m_i&&(!r[i]||r[i]=='0'))//小数点之后的后缀零处理 
            {
                r[i]='a';//赋值为a 
                i--;
            }
            for(i=5;i>=0;--i)
            {
                             if(!r[i]||r[i]=='a')continue;
                             if(r[i]=='.')break;
                             m_number++;//判断有多少小数
            }
        }
        for(i=0,j=0;i<6;++i)
        {
            if(r[i]=='a')continue;
            if(r[i]=='.')continue;
            if(!r[i])continue;
            b[j]=(int)(r[i]-'0');//转成int的b 
            j++;
        }
        while(j<6)
        {
            b[j]=-1;
            j++;
        }//b可以弄出实数来了
        for(i=0;i<6;++i)
        {
                        if(b[i]==-1)continue;
                        m_data=m_data*10+b[i];//相乘的大数 
        } 
        for(j=5,i=250-1;j>=0&&i>=0;--j)
        {
                         if(b[j]==-1)continue;
                         else
                         {
                             m[i]=b[j];//赋值给m 
                             i--;
                         }
        }
        m_number=m_number*n; //总共小数的位数
        n--;	//这里不理解
        while(n--&&i!=249)//如果出现输入都是0   ???  不理解
        {
                  for(j=i+1;j<250;j++)//有这么多位 
                        {
                                  int tem=m[j]*m_data;//每一位与数相乘 
                                  m[j]=0;
                                  if(tem==0)m[j]=0;
                                  else
                                  {
                                      int t=j;
                                      while(tem/10!=0||tem%10!=0)
                                      {
                                             m[t]=m[t]+tem%10;//将每一位都分离出来存放在不同的单元 
                                             int tt1=t;
                                             while(m[tt1]>9)//对超过9的处理 
                                             {
                                                 int tem2=m[tt1];
                                                 m[tt1]=tem2%10;//得到这位的数据 
                                                 tt1--;
                                                 m[tt1]=m[tt1]+tem2/10;//往前加进的位数 
                                             }
                                             t--; 
                                             tem=tem/10;        
                                      }
                                  }
                        }
                        i=0;
                        while(m[i]==0)i++;//找到m中第一个非零的位置 
                        i--;
        }       
              
              i=0;
              while(i<250&&m[i]==0)
                i++;
              if(m_number==0)//对没有小数点的处理 
              {
                             if(i==250)cout<<0<<endl;
                             else
                             {
                                 for(;i<250;++i)cout<<m[i];
                                 cout<<endl;
                             }
              }
              else//有小数点的处理 
              {
                  if(m_number>250-i)//250-i表示在i之前有i个零，有250-i个非零  
                  {//小数点超过相乘得到的实数，则补零 
                    cout<<".";
                    while(m_number-->250-i)
                        cout<<0;
                    for(;i<250;i++)
                        cout<<m[i];
                    cout<<endl; 
                  }
                  else 
                  {
                       for(;i<250;++i)
                       {
                                      if(m_number==250-i)cout<<".";//包含处理等于 
                                      cout<<m[i];
                       }
                       cout<<endl;
                  }
              }
    }
    return 0;
}