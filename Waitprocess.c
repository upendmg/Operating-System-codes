#include<stdio.h>
int main()
{
int pid,dip,cpid;
pid=fork();
if(pid==0)
{
printf("1st child process is %d \n",getpid());
printf("1st child process terminating from the memory\n");
}
else
{
dip=fork();
if(dip==0)
{
printf("2 set child process id is %d\n",getpid());
printf("2 set child process erminating from the memory\n");
}
else
{
cpid=wait(0);
printf("child with pid:%d is died\n",cpid);
cpid=wait(0);
printf("child with pid %d is died\n",cpid);
}
}
return 0;
}
