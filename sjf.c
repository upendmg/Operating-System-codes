#include<stdio.h>
int main()
{
int n,b1[12],b[12],j[12],w[12],e[12];
int i,k,t,t1;
float aw=0,ae=0;
printf("\n SHORTEST JOB FIRST\n");
printf("\nEnter no.of jobs");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n BURST TIME FOR JOB%d=",i+1);
scanf("%d",&b[i]);
b1[i]=b[i];
j[i]=1;
}
for(i=0;i<n;i++)
for(k=0;k<n;k++)
{
if(b1[i]<b1[k])
{
t=b1[i];
b1[i]=b1[k];
b1[k]=t;
}  }
printf("\n JOB\t\tBURST TIME\tWAIT TIME\t");
for(i=0;i<n;i++)
{
if(i==0)
{
w[0]=0;
e[0]=b1[0];
}
else
{
w[i]=e[i-1];
e[i]=e[i-1]+b1[i];
}
printf("\n%d\t\t%d\t\t%d\t\n",i+1,b1[i],w[i],e[i]);
aw+=w[i];
}
aw/=n;
printf("\n AVG WAITING TIME :%f",aw);
return 0;
}
