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
    bool push_again=false;
    int push_again_id=-1;
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
        if(push_again==true)
        {
            q.push_back(pro[push_again_id]);
        }
        int current_pid = q.front().id;
        q.pop_front();
        if(pro[current_pid].remain > quantum)
        {
            pro[current_pid].remain -= quantum;
            pro[current_pid].wait += curtime - pro[current_pid].arrival;
            pro[current_pid].arrival = curtime+quantum; //next arrival time
            curtime+=quantum;
            push_again=true;
            push_again_id=current_pid;
        }
        // if the process did not finish in the quantum time
        else
        {
            pro[current_pid].wait += curtime - pro[current_pid].arrival;
            curtime += pro[current_pid].remain;
            pro[current_pid].remain = 0;
            push_again=false;
            pro[current_pid].sent=true;
        }

        bool all_sent=true;
        for(int i = 0; i < pro.size(); i++)
        {
            if(pro[i].sent == false)
            {
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