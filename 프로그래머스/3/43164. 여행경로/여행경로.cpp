#include <stack>
#include <vector>
#include <list>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool recv_DFS(string& current ,vector<vector<string>>& tickets, vector<string>& answer, int& useticket, vector<bool>& visited)
{
	if (useticket == tickets.size()) // 다 썼다!
	{
		return true;
	}	

	for(int i = 0; i< tickets.size(); ++i) // 방문 인덱스 찾기
	{
		if (current == tickets[i][0] && !visited[i]) // 출발지 현재와 같고 아직 안썼다면?
		{
			
			visited[i] = true;
			answer.push_back(tickets[i][1]); // 도착지를 정답에 넣음
			++useticket;
		
			// 다음 공항(tickets[i][1])으로 이동하고, 티켓 사용량을 넘김
			if (recv_DFS(tickets[i][1], tickets, answer, useticket, visited))
			{
				return true; // 끝까지 성공했으면 그대로 종료
			}

			
			// 위 재귀에서 막혀서 false가 돌아왔다면? 이 길은 틀린 길
			// 방금 썼던 티켓과 경로를 다시 빼서 원상복구
			visited[i] = false;
			answer.pop_back();
            --useticket;
		}
	}

	// 만약 다 돌았는데 없다면?
	return false;
}

vector<string> solution(vector<vector<string>> tickets) {      
   vector<string> answer;
string current;
vector<bool> visited(tickets.size(), false);
int useticket = 0;

sort(tickets.begin(), tickets.end());

string start = "ICN";

answer.push_back(start);

recv_DFS(start, tickets, answer, useticket, visited);

   return answer;
}