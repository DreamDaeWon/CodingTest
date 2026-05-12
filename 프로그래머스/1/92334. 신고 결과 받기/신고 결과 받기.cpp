#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, set<string>> m{};
    vector<pair<string, int>> m_num(id_list.size());
    answer.resize(id_list.size(),0);
    for (int i = 0; i < id_list.size(); ++i)
    {
        m_num[i] = { id_list[i], 0 };
    }

    // 중복 신고 추리기 -> 중복 신고 제외하고 어떤 유저가 어떤 유저 신고했는지 추림
    for (auto& id : report)
    {
        string report_user{};
        string reported_user{};

        for (int i = 0; i < id.size(); ++i)
        {
            if (id[i] == ' ')
            {
                report_user = id.substr(0,i);
                reported_user = id.substr(i + 1);
                m[report_user].insert(reported_user);
                break;
            }
        }
    }
  

    // 각 유저당 신고당한 횟수 세기
    for (auto& all_map : m)
    {
       /* auto iter = find(m_num.begin(), m_num.end(), all_map.first);
        ++(*iter).second;*/

        for (int i = 0; i < m_num.size(); ++i)
        {
            if (all_map.second.count(m_num[i].first))
            {
                ++m_num[i].second;
                //break;
            }
        }

    }


    // 신고당한 횟수가 k번을 넘겼는지?
    for (auto& num : m_num)
    {
        if (num.second >= k)
        {
            num.second = 1;
        }
        else
        {
            num.second = 0;
        }
    }


    int index{};
    // 각 유저가 신고한 유저가 정지 먹은 횟수 세기
    for (auto& user : id_list)
    {
        for (auto& reportesuser : m[user])
        {
            //auto iter = find(m_num.begin(), m_num.end(), reportesuser);

            //if ((*iter).second > 0)
            //{
            //    ++answer[index];
            //}

            for (int i = 0; i < m_num.size(); ++i)
            {
                if (m_num[i].first == reportesuser && m_num[i].second > 0)
                {
                    ++answer[index];
                    break;
                }
            }
        }
        ++index;
    }


    return answer;
}