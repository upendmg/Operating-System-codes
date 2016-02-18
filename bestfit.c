#include<stdio.h>
main()
{
int i,n,m,ps[100],bs[150],j,pi[50],bi[50],t;
printf("\n Enter the no of blocks:");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
printf("\n Enter the  block %d size :",i);
scanf("%d",&bs[i]);
bi[i]=i;
}
printf("\n Enter no of process:");
scanf("%d",&m);
for(i=1;i<=m;i++)
{
printf("\n Enter process %d size:",i);
scanf("%d",&ps[i]);
pi[i]=i;
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(bs[i]<bs[j])
{
t=bs[i];
bs[i]=bs[j];
bs[j]=t;
t=bi[i];
bi[i]=bi[j];
bi[j]=t;
}
if(ps[i]<ps[j])
{
t=ps[i];
ps[i]=ps[j];
ps[j]=t;
t=pi[i];
pi[i]=pi[j];
pi[j]=t;
}
}
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(ps[j]<=bs[i])
{
printf("process%d is allocated to block of size %d\n",pi[j],bs[i]);
ps[j]=10000;
break;
}
}
}
for(i=1;i<=m;i++)
{
if(ps[i]!=10000)
{
printf("\nprocess %d is not allowed",i);
}
}
}

