#include<bits/stdc++.h>
using namespace std;
struct process
{
    int arrival=0;
    int burst=0;
    int wait=0;
    int turnaround=0;
};
int main()
{
    int num;
    cin >> num;
    vector<process> pro;
    pro.resize(num);
    int tmp;
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        pro[i].arrival = tmp;
    }
    for(int i = 0; i < num; i++)
    {
        cin >> tmp;
        pro[i].burst = tmp;
    }
    int curtime=0;
    int totalwait=0;
    int totalturnaround=0;
    for(int i = 0; i < pro.size(); i++)
    {
        if(pro[i].arrival <= curtime)   //the process is arrived
        {
            pro[i].wait = curtime-pro[i].arrival;
            pro[i].turnaround = pro[i].wait+pro[i].burst;
            curtime += pro[i].burst;
            totalwait += pro[i].wait;
            totalturnaround += pro[i].turnaround;
        }
    }
    
    for(int i = 0; i < pro.size(); i++)
    {
        cout << pro[i].wait << " "<<pro[i].turnaround<<endl;
    }
    cout << totalwait << endl;
    cout << totalturnaround << endl;


    return 0;
}