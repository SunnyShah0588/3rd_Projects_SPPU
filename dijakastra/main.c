#include<sys/sysinfo.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
struct sysinfo c;
sysinfo(&c);
float free,total;

free=c.mem_unit*c.freeram;
total=c.mem_unit*c.totalram;

printf("\nTotal Memory is: %fB,%fKB,%fMB,%fGB",total,total/1024,total/1024/1024,total/1024/1024/1024);
printf("\nAvailable Free Memory is: %fB,%fKB,%fMB,%fGB",free,free/1024,free/1024/1024,free/1024/1024/1024);
printf("\n");
return 0;
}
