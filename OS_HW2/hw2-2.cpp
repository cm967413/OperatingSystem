#include<bits/stdc++.h>
using namespace std;
struct process
{
    int arrival=0;
    int burst=0;
    int wait=0;
    int turnaround=0;
    bool sent=false;
};
int main()
{
    int num;
    cin >> num;
    vector<process> pro;
    pro.resize(num);
    int tmp;
    int total_time=0;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        pro[i].arrival = tmp;
    }
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        pro[i].burst = tmp;
        total_time += tmp;
    }

    int curtime=0;
    int index; //not found
    int current_shortest_burst = 21;
    int totalturnaround=0;
    int totalwait=0;
    while(true)
    {
        index; //not found
        current_shortest_burst = 21;
        for(int i = 0; i < pro.size(); i++)
        {
            if(pro[i].arrival <= curtime && pro[i].sent == false)   //the process is arrived
            {
                if(pro[i].burst < current_shortest_burst)
                {
                    current_shortest_burst = pro[i].burst;
                    index = i;
                }
                //cout << current_shortest_burst<<endl;
            }
        }
        cout << current_shortest_burst << "  " << index <<endl;
        pro[index].wait = curtime - pro[index].arrival;
        pro[index].turnaround = pro[index].wait + pro[index].burst;
        pro[index].sent=true;
        curtime+=current_shortest_burst;
        totalwait += pro[index].wait;
        totalturnaround += pro[index].turnaround;

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
    for(int i = 0; i < pro.size(); i++)
    {
        cout << pro[i].wait << " " << pro[i].turnaround << endl;
    }
    cout << totalwait << endl;
    cout << totalturnaround << endl;
    return 0;
}