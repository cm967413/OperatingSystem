//execvp_test.cpp
#include <iostream>
#include <unistd.h>
#include<sys/wait.h>
#include <string>
#include <cstring>
#include <sstream>
#define MAX_LINE 80
using namespace std;
int main(){
        char* arg[MAX_LINE/2+1];
        int run = 1;
        while(run == 1)
        {
            printf("osh>");
            fflush(stdout);

            string str;
            getline(cin,str);
            stringstream ss(str);
            string tmp="";
            int idx = 0;
            while(ss >> tmp)
            {
                arg[idx] = strdup(tmp.c_str());
                idx++;
            }
            arg[idx] = NULL;
            pid_t  pid;
            pid = fork();
            if(pid == 0)
            {
                execvp(arg[0],arg);  //works
            }
            else if(pid > 0)
            {
                wait(NULL);
            }
            if(str == "exit")
            {
                run = 0;
            }
        }
}