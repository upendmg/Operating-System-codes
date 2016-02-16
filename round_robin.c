#include<stdio.h>
main()
{
int a[30],b[30],n,t,i,j,ttime,c;
float tatime=0,avewt=0;
printf("Enter no.of jobs:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("Enter the burst time %d:",i);
scanf("%d",&b[i]);
a[i]=b[i];
}
printf("Enter time slice:");
scanf("%d",&t);
printf("\nProcess \t Remaining time \t total time \t waiting time\n");
j=0; ttime=0;
while(j<n)
{
for(i=1;i<=n;i++)
{
if(b[i]>0)
{
if(b[i]>t)
{ttime+=t;
b[i]=b[i]-t;
printf("%d \t\t %d \t\t\t %d \n",i,b[i],ttime);
if(b[i]==0)
j++;
}
else
{
ttime+=b[i];
b[i]=0;
c=ttime-a[i];
avewt=avewt+c;
tatime=a[i]+c;
printf("%d \t\t %d \t\t\t %d \t\t %d \n",i,b[i],ttime,c);
j++;
}}}
}
 printf("\nAverage waiting time =%f\n",avewt/n);
printf("Average turn around time =%f\n",tatime/n);
}

