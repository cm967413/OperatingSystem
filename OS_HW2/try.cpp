#include<bits/stdc++.h>
using namespace std;
struct process
{
    int arrive;
    int burst;
};
bool compare(process a, process b)
{
    return a.burst > b.burst;
}
int main()
{
    process p1;
    p1.arrive = 0;
    p1.burst = 100;
    process p2;
    p2.arrive = 3;
    p2.burst = 4;
    process p3;
    p3.arrive=5;
    p3.burst=7;
    priority_queue<process,vector<process>,decltype(&compare)> pq(compare);
    pq.push(p1);
    pq.push(p2);
    pq.push(p3);
    cout << pq.size()<<endl;
    while(!pq.empty())
    {
        process tmp = pq.top();
        pq.pop();
        cout << tmp.arrive << "  "<< tmp.burst<<endl;
    }
    return 0;
}