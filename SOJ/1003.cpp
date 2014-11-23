/*1003. Hit or Miss

Constraints

Time Limit: 1 secs, Memory Limit: 32 MB

Description

One very simple type of solitaire game known as "Hit or Miss" (also known as "Frustration," "Harvest," "Roll-Call," "Talkative", and "Treize") is played as follows: take a standard deck of 52 playing cards four sets of cards numbered 1 through 13 (suits do not matter in this game) which have been shuffled and start counting through the deck 1, 2, 3, . . . , and so on. When your count reaches 13, start over at 1. Each time you count, look at the top card of the deck and do one of two things: if the number you count matches the value of the top card, discard it from the deck; if it does not match it, move that card to the bottom of the deck. You win the game if you are able to remove all cards from the deck (which may take a very long time). A version of this game can be devised for two or more players. The first player starts as before with a 52 card deck, while the other players have no cards initially. As the first player removes cards from her deck, she gives them to the second player, who then starts playing the same game, starting at count 1. When that player gets a match, he passes his card to the third player, and so on. The last player discards matches rather than passing them to player 1. All players who have cards to play with perform the following 2-step cycle of moves in lockstep: 1. Each player says his or her current count value and checks for a match. If there is no match, the top card is moved to the bottom of the deck; otherwise it is passed to the next player (or discarded if this is the last player). 2. Each player except the first takes a passed card (if there is one) and places it at the bottom of his or her deck. These rules are repeated over and over until either the game is won (all the cards are discarded by the last player) or an unwinnable position is reached. If any player ever runs out of cards, he waits until he is passed a card and resumes his count from where he left off. (e.g., if player 3 passes his last card on a count of 7, he waits until he receives a card from player 2 and resumes his count with 8 at the beginning of the next 2-step cycle).

Input

Input will consist of multiple input sets. The first line of the file will contain a single positive integer nindicating the number of input sets in the file. Each input set will be a single line containing 53 integers: the first integer will indicate the number of players in the game and the remaining 52 values will be the initial layout of the cards in the deck, topmost card first. These values will all lie in the range 1 . . . 13, and the number of players will lie in the range 1. . . 10.

Output

For each input set, output the input set number (as shown below, starting with 1) and either the phrase "unwinnable" or a list showing the last card discarded by each player. Use a single blank to separate all outputs.

Sample Input

2
4 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 
4 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1 2 3 4 5 6 7 8 9 10 11 12 13 1
Sample Output

Case 1: 13 13 13 13
Case 2: unwinnable*/
#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;//记录游戏次数
	for (int x = 1; x <= t; ++x)
	{
		int count_player;
		cin >> count_player;//记录每次的玩家人数
		queue<short> deck[11];//记录每个玩家的牌序列,最多10个玩家,deck[0]是输入的第一个玩家的牌序,假设最后丢弃的排是传到假想的一个玩家手中
		short result[11];//记录每个玩家最后的结果
		short temp;
		for (int i = 0; i < 52; ++i) //初始化输入牌序
		{
			cin >> temp;
			deck[0].push(temp);
		}

		bool flag = false;//
		short totalsteps[11] = {0};//记录每个玩家数的总次数,超出一定范围认为无结果
		short count[11] = {0};//记录每个玩家数的当前数,1~13循环
		short j = 0;
		short totalcard = 52;//牌数,为0则有最终结果,所有玩家手中都没牌了,除了假想
		while(!flag)
		{
			if (deck[j].empty())//如果为空,则该玩家手中暂时没牌了
			{
				j++;
				if (j >= count_player)
				{
					j = 0;
				}
				continue;
			}

			totalsteps[j]++;
			count[j]++;
			if (count[j] == deck[j].front())//匹配
			{
				deck[j + 1].push(deck[j].front());//将牌放入下一位玩家的底部
				totalsteps[j] = 0;//每轮匹配成功后将总步数置0,
				if (j + 1 ==  count_player)//如果是最后一位玩家,总牌数减1
				{
					totalcard--;
				}
				result[j] = deck[j].front();//记录当前结果
				deck[j].pop();
			}
			else//不匹配
			{
				deck[j].push(deck[j].front());
				deck[j].pop();
			}
			if (totalsteps[j] > deck[j].size() * 13)//不匹配的次数太多认为无结果
			{
				flag = false;
				break;
			}
			if (totalcard == 0)
			{
				flag = true;
			}
			if (count[j] == 13)
			{
				count[j] = 0;
			}

			j++;

			if (j >= count_player)//遍历了所有玩家,再从第0个玩家开始遍历
			{
				j = 0;
			}

		}
		if (flag)
		{
			cout << "Case " << x << ":";
			for (int i = 0; i < count_player; ++i)
			{
				cout << " " << result[i];
			}
			cout << endl;
		}
		else
		{
			cout << "Case " << x << ": unwinnable" << endl;
		}

	}

	return 0;
}