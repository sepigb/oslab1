#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc,char *argv[])
{
	if(argc<2)
		exit();
	if(argc==2)
	{
		close(1);
		int fd;
		fd=open(argv[1],O_WRONLY);
		if( fd!=-1 )
		{
			close(fd);
			unlink(argv[1]);
		}
		fd=open(argv[1],O_CREATE);
		close(fd);
		exit();
	}
	else
	{
		int i=1,n,fd;
		char buf[512];
		if( !(argv[1][0]=='-' && argv[1][1]=='w' && argv[1][2]=='\0') && 
			       !(argv[2][0]=='-' && argv[2][1]=='w' && argv[2][2]=='\0') )	
			exit();
		if( argv[1][0]=='-' && argv[1][1]=='w' && argv[1][2]=='\0' )
			i=2;
		n=read(0,buf,sizeof(buf));
		if(n<0)
			exit();
		close(1);
		fd=open(argv[i],O_WRONLY);
		if( fd!=-1 )
		{
			close(fd);
			unlink(argv[i]);
		}
		fd=open(argv[i], O_CREATE | O_WRONLY );
		write(fd,buf,n);
		close(fd);
		exit();

	}
}
