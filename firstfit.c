#include<stdio.h>
main()
{
int i,n,m,ps[100],bs[150],j;
printf("Enter the no of blocks\n");
scanf("%d",&n);
             for(i=1;i<=n;i++)
{
printf("\n Enter the block %d size: ",i);
scanf("%d",&bs[i]);
}
printf("\n Enter the no of process:");
scanf("%d",&m);
for(i=1;i<=m;i++)
{
printf("\n Enter the process %d size:",i);
scanf("%d",&ps[i]);
}
for(i=1;i<=n;i++)
{
for(j=1;j<=m;j++)
{
if(ps[j]<=bs[i])
{
printf("process %d is allocated to block of size %d\n",j,bs[i]);
ps[j]=10000;
break;
}
}
}
for(i=1;i<=m;i++)
{
if(ps[i]!=10000)
{
printf("\n process %d is not allowed",i);
}
}
}

