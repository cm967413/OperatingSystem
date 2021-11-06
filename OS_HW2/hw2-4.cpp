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
    if(a.remain == b.remain)
    {
        return a.id > b.id;
    }
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
        //cout << curtime << endl;
        for(int i = 0; i < pro.size(); i++)
        {
            if(pro[i].arrival <= curtime && pro[i].first_arrive==false)
            {
                //cout << curtime << endl;
                q.push_back(pro[i]);
                pro[i].first_arrive=true;
            }
        }

        bool found_upcoming_process=false;
        int upcoming_time;
        for(int i = 0; i < pro.size(); i++)
        {
            if(pro[i].arrival >= curtime && pro[i].first_arrive==false)
            {
                upcoming_time = pro[i].arrival;
                found_upcoming_process=true;
                break;
            }
        }
        if(found_upcoming_process==false)
        {
            int sum=0;
            for(auto tmp : pro)
            {
                sum+= tmp.burst;
            }
            upcoming_time=sum;
        }
        // if(push_again==true)
        // {
        //     q.push_back(pro[push_again_id]);
        // }
        if(!q.empty())
        {
            int current_pid = q.front().id;
            q.pop_front();

            if(pro[current_pid].remain > quantum)   // if the process did not finish in the quantum time
            {
                pro[current_pid].remain -= quantum;
                pro[current_pid].wait += curtime - pro[current_pid].arrival;
                pro[current_pid].arrival = curtime+quantum; //next arrival time
                curtime+=quantum;
                pq.push(pro[current_pid]); //push it into the second queue
            }

            else
            {
                pro[current_pid].wait += curtime - pro[current_pid].arrival;
                curtime += pro[current_pid].remain;
                pro[current_pid].remain = 0;
                pro[current_pid].sent=true;
            }
        }
        
        //cout << curtime << endl;
        else
        {
            while(true)
            {
                
                //cout << curtime << endl;
                if(upcoming_time <= curtime)    break;
                if(!pq.empty())
                {
                    int pid;
                    int shortest_remain;
                    pid = pq.top().id;
                    shortest_remain=pq.top().remain;
                    
                    pq.pop();
                    //cout << pid << "  "<<shortest_remain <<endl;
                    if(shortest_remain <= (upcoming_time - curtime))
                    {
                        pro[pid].wait += (curtime - pro[pid].arrival);
                        curtime += shortest_remain;
                        pro[pid].remain=0;
                        pro[pid].sent = true;
                        //cout << pid << endl;
                    }

                    else
                    {
                        //cout << pid << endl;
                        pro[pid].remain -= (upcoming_time - curtime);
                        pro[pid].wait += (curtime - pro[pid].arrival);
                        curtime += (upcoming_time - curtime);
                        pro[pid].arrival = upcoming_time; //next arrival time
                        pq.push(pro[pid]); //push it into the second queue
                    }
                }
            }
        }
        bool all_sent=true;
        for(int i = 0; i < pro.size(); i++)
        {
            if(pro[i].sent == false)
            {
                //cout << i << endl;
                all_sent = false;
                break;
            }
        }
        if(all_sent==true)  break;
    }
    int total_wait=0;
    int total_turn_around=0;
    for(int i = 0; i < pro.size(); i++)
    {
        pro[i].turnaround = pro[i].wait + pro[i].burst;
        cout << pro[i].wait << " " << pro[i].turnaround<<endl;
        total_wait += pro[i].wait;
        total_turn_around += pro[i].turnaround;
    }
    cout << total_wait << endl;
    cout << total_turn_around << endl;
    return 0;
}