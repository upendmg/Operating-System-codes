#include<stdio.h>
int main()
{
int i,j,n,temp,start[10],pri[10],finish[10],burst[10],sw=0,st=0,bu=0;
printf("\n priority scheduling");
printf("\n Enter the no of jobs:");
scanf("%d",&n);
start[0]=0;
for(i=0;i<n;i++)
{
printf("\n enter the burst time & priority of job %d:",i+1);
scanf("%d%d",&burst[i],&pri[i]);
}
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
if(pri[j]<pri[i])
{
temp=pri[i];
pri[i]=pri[j];
pri[j]=temp;
temp=burst[i];
burst[i]=burst[j];
burst[j]=temp;
}
printf("\n bursttime \t priority \t starttime \t finishtime");
for(i=0;i<n;i++)
{
start[i+1]=finish[i]=start[i]+burst[i];
st+=finish[i];
sw+=start[i];
bu+=burst[i];
printf("\n%d\t\t%d\t\t%d\t\t%d",burst[i],pri[i],start[i],finish[i]);
}
printf("\n average turnaround time is :%f",(float)st/n);
printf("\n average waiting time is :%f",(float)sw/n);
printf("\n average burst time is :%f",(float)bu/n);
return 0;
}

