#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct Song
{
	string genres{};
	int index{};
	int plays{};
};

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> song_map{}; // 노래의 테마와 총 들은 값

	vector<Song> all_songs(plays.size()); // 모든 노래의 장르, 인덱스, 들은 횟수 매핑

	for (int i = 0; i < genres.size(); ++i)
	{
		song_map[genres[i]] += plays[i];

		all_songs[i].genres = genres[i];
		all_songs[i].index = i;
		all_songs[i].plays = plays[i];
	}


	vector<pair<string, int>> song_vec{};
	for (const auto& iter : song_map)
	{
		song_vec.emplace_back(iter.first, iter.second);
	}
	
	song_map.clear();

	// 장르 별 정렬
	sort(song_vec.begin(), song_vec.end(), [](const pair<string, int>& a, const pair<string, int>& b) {
		return a.second > b.second; // 내림 차순
		});

	// 각 곡 별 정렬
	sort(all_songs.begin(), all_songs.end(), [](const Song& a, const Song& b) {
		if (a.plays == b.plays) // 같다면?
		{
			return a.index < b.index; // 인덱스 빠른 순으로
		}
		return a.plays > b.plays; // 내림차순
		});

	for (int i = 0; i < song_vec.size(); ++i)
	{
		int check = 0;
		for (int j = 0; j < all_songs.size(); ++j)
		{
			if (all_songs[j].genres == song_vec[i].first)
			{
				answer.push_back(all_songs[j].index);
				++check;
			}
			if (check >= 2)
			{
				break;
			}
		}
	}

	return answer;
}