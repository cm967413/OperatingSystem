#include<bits/stdc++.h>
using namespace std;
struct process
{
    int arrival=0;
    int id=0;
    int burst=0;
    int wait=0;
    int turnaround=0;
    int remain=0;
    bool first_arrive=false;
    bool sent=false;
};
bool compare(process a, process b)
{
    return a.remain > b.remain;
}
int main()
{
    int num;
    int quantum;
    cin >> num;
    vector<process> pro;
    pro.resize(num);
    int tmp;
    int total_time=0;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        pro[i].arrival = tmp;
        pro[i].id = i;
    }
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        pro[i].burst = tmp;
        pro[i].remain = tmp;
        total_time += tmp;
    }
    cin >> quantum;
    int curtime=0;
    list<process> q;
    priority_queue<process,vector<process>,decltype(&compare)> pq(compare);
    while(true)
    {
        for(int i = 0; i < pro.size(); i++)
        {
            if(pro[i].arrival <= curtime && pro[i].first_arrive==false)
            {
                q.push_back(pro[i]);
                pro[i].first_arrive=true;
            }
        }
        while(!q.empty())
        {
            int current_pid = q.front().id;
            q.pop_front();
            if(pro[current_pid].remain > quantum)
            {
                pro[current_pid].remain -= quantum;
                pro[current_pid].wait += curtime - pro[current_pid].arrival;
                pro[current_pid].arrival = curtime+quantum; //next arrival time
                curtime+=quantum;
                pq.push(pro[current_pid]);
                cout << pq.top().id << endl;
            }
            else
            {
                pro[current_pid].wait += curtime - pro[current_pid].arrival;
                curtime += pro[current_pid].remain;
                pro[current_pid].remain = 0;
                pro[current_pid].sent=true;
            }
        }
        int upcomming_time;
        for(int i = 0; i < pro.size(); i++)
        {
            if(pro[i].arrival >= curtime && pro[i].first_arrive==false)
            {
                upcomming_time = pro[i].arrival;
                break;
            }
        }
        cout<<"current time:" << curtime <<endl;
        cout<<"upcomming_time"<<upcomming_time << endl;
        //if(q.empty())   break;
        // bool all_sent=true;
        // for(int i = 0; i < pro.size(); i++)
        // {
        //     if(pro[i].sent == false)
        //     {
        //         all_sent = false;
        //         break;
        //     }
        // }
        // if(all_sent==true)  break;
    }
    // int total_wait=0;
    // int total_turn_around=0;
    // for(int i = 0; i < pro.size(); i++)
    // {
    //     pro[i].turnaround = pro[i].wait + pro[i].burst;
    //     cout << pro[i].wait << " " << pro[i].turnaround<<endl;
    //     total_wait += pro[i].wait;
    //     total_turn_around += pro[i].turnaround;
    // }
    // cout << total_wait << endl;
    // cout << total_turn_around << endl;
    
    
    return 0;
}