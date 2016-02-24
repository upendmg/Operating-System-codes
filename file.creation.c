#include<stdio.h> 
#include<unistd.h> 
#include<sys/stat.h> 
#include<sys/types.h> 
#include<fcntl.h> 
main() 
{ 
int  fd; 
char buf1[100],buf2[]="hello world",fname[30]; 
printf("Enter filename\n"); 
scanf("%s",fname); 
fd = creat(fname,S_IRWXU); 
if(fd < 0) 
{ 
printf("error in file creation"); 
} 
else 
{ 
write(fd,buf2,30); 
printf("contents written successfully\n"); 
fd=open(fname,O_RDONLY); 
read(fd,buf1,30); 
printf("contents is:\n%s\n",buf1); 
close(fd); 
} 
} 

