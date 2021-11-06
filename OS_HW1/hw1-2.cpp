#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    printf("Main Process ID : %d\n\n",getpid());
    pid_t pid;
    pid = fork();
    if(pid == 0)
    {
        printf("Fork 1. I'm the child %d, my parent is %d.\n",getpid(),getppid());
        pid = fork();
        if(pid == 0)
        {
            printf("Fork 4. I'm the child %d, my parent is %d.\n",getpid(),getppid());
            pid = fork();
            if(pid == 0)
            {
                printf("Fork 5. I'm the child %d, my parent is %d.\n",getpid(),getppid());
            }
            if(pid > 0)
            {
                wait(NULL);
            }
        }
        if(pid > 0)
        {
            wait(NULL);
        }


    }
    else if (pid > 0)
    {
        wait(NULL);
        pid = fork();
        if(pid == 0)
        {
            printf("Fork 2. I'm the child %d, my parent is %d.\n",getpid(),getppid());
        }
        if(pid > 0)
        {
            wait(NULL);
        }
        pid = fork();
        if(pid == 0)
        {
            printf("Fork 3. I'm the child %d, my parent is %d.\n",getpid(),getppid());
        }
        if(pid > 0)
        {
            wait(NULL);
        }
    }
    return 0;
}