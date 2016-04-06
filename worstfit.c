#include
#include
void main()
{
int i,j,mem[30],n,pro[30],m,temp,k,avail[5],t;
clrscr();
printf(“\n enter the no. of partition of memory:”);
scanf(“%d”,&n);
printf(“\n partitions in memory:”);
for(i=0;i
{

scanf(“%d”,&mem[i]);
}
m=n;
printf(“\n processes are:”);
for(j=0;j
{
scanf(“%d”,&pro[j]);
}
for(i=0;i
{
t=i;
for(j=i+1;j
{
if(mem[t]
{
temp=mem[j];
mem[j]=mem[t];
mem[t]=temp;
}
}
}

for(i=0;i
{
for(j=0;j
{
if(pro[i]<=mem[j])
{
printf(“\n the process %dk is placed in memory %dk”,pro[i],mem[j]);
k=j;
mem[k]=0;
avail[i]=pro[i];
break;
}
}
}
for(i=0;i
{
if(pro[i]!=avail[i])
{
printf(“\n the process %dk cannot be placed”,pro[i]);
}
}
getch();
}
