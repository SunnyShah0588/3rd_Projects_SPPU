#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

using namespace std;
int main()
{

    cout<<"\n List of processes :";
    int pid;
    pid=fork();
    if(pid==0)
    {
        system("ps -al");
        cout<<"\n THE PROCESS IS CREATED \n PROCESS ID IS "<<getpid();
        cout<<"\n THE PROCESS IS CREATED \n PROCESS ID IS "<<getppid();



    }else if(pid<0)
    {
      cout<<"\n process is not created";
      exit(1);

    }
}


