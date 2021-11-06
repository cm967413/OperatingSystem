#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
    printf("I am main process, PID = %d\n",getpid());
    pid_t pid;
    printf("----------Fork0-----------\n");
    pid = fork();   //fork 0
    printf("Fork returns value = %d, and the current process is %d\n",pid,getpid());
    if(pid == 0)    //child
    {
        //printf("I am a child, my pid is %d, and my parent's pid is %d\n",getpid(),getppid());
        printf("----------Fork1----------\n");
        pid = fork();   //fork1
        printf("Fork returns value = %d, and the current process is %d\n",pid,getpid());
        if(pid > 0) //parent
        {
            //printf("I am a parent, my pid is %d, and my child's pid is %d\n",getpid(),pid);
            wait(NULL);
        }
        printf("----------Fork2----------\n");
        pid = fork();   //fork2
        printf("Fork returns value = %d, and the current process is %d\n",pid,getpid());
        if(pid > 0)
        {
            wait(NULL);
        }
    }
    else if(pid > 0)    //parent
    {
        wait(NULL);
        printf("----------Fork3----------\n");
        pid = fork();   //fork3
        printf("Fork returns value = %d, and the current process is %d\n",pid,getpid());
        if(pid > 0)
        {
            wait(NULL);
        }
    } 
    else
    {
        printf("Error!\n");
    }
    printf("----------Fork4----------\n");
    pid = fork(); //fork4
    printf("Fork returns value = %d, and the current process is %d\n",pid,getpid());
    if(pid > 0)
    {
        wait(NULL);
    }
    return 0;
}