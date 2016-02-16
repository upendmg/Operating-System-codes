#include<stdio.h>
int main()
{
int n,i,b[10],w[10],t[10];
float ae,aw,at;
printf("\n\t\t first come first serve");
printf("\n\n Enter the number of jobs\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n\nEnter the burst time for the jobs%d:",i+1);
scanf("%d",&b[i]);
if(i==0)
{
w[0]=0;
t[0]=b[0];
}
else
{
w[i]=t[i-1];
t[i]=t[i-1]+b[i];
}
}
printf("\n job\tBurst time\t waiting time\n");
            for(i=0;i<n;i++)
{
printf("\n%d\t\t%d\t\t%d\n",i+1,b[i],w[i],t[i]);
ae+=b[i];
aw+=w[i];
at+=t[i];
}
ae/=n;
aw/=n;
printf("\nAverage burst time is :%f",(float)ae);
printf("\nAverage  waiting time is :%f",(float)aw);
return 0;
}

