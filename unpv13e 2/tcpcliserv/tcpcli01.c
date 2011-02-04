#include	"unp.h"
#include <string.h>



void 
sendtext(char* fp, int sockfd)
{
printf("%s", fp);
       // printf("%s\n", input);
      //  printf("%s\n", input);
char sendline[MAXLINE], recvline[MAXLINE];
int s =0;
while(fp[s-1]!='\0')
{
	Writen(sockfd, fp[s],1);
	if(Readline(sockfd, recvline, MAXLINE) == 0)
	{
	err_quit("send: server terminated prematurely");
	}
	Fputs(recvline, stdout);
	s++;
}
	}
int
main(int argc, char **argv)
{
	int c = 0;
	int c2 = 0;
	char test[200];
	int connected = 0;
	int					sockfd;
	struct sockaddr_in	servaddr;
	//char input[50] = {0};
        //char input2[160] = {0};
	char connect[] = "connect";
	char send[] = "send";

	printf("hivemind$");
while(1){
	char input[50]={0};
	char input2[200]={0};
	scanf("%s", input);
if(connected==1)
	scanf("%[^\n]s", input2);
else
	scanf("%s", input2);
	
        printf("%s\n", input);
	 printf("%s\n", input2);

	int menu = -1;
        int i;
	
	for (i = 0; connect[i] != '\0'; i++) {
	  char x = connect[i];
	  if (x != input[i]) {
	    menu = -1;
	    break;
	  }
	  menu = 0;
	}

	if(menu != 0) {
	  for (i = 0; send[i] != '\0'; i++) {
	    char x = send[i];
	    if (x != input[i]) {
	      menu = -1;
	      break;
	    }
		 menu = 1;
		connected=1;	
  }
	}

	if (menu == 0) {
	  printf("was connect.\n");
       // scanf("%s", input2);
	printf("%s\n", input);
	
	//Very not rooboost. (Levin-ism)
	char ip[20] = "\0";
	char port[10] = "\0";
	if (menu == 0) {
	  for(i = 0; input2[i] != ':' && i < 35; i++) {
	    printf("%d %c\n", i, input2[i]);
	    ip[i] = input2[i];
	  }
	  int j;
	  i++;
	  for(j = 0; input2[i]; i++, j++) {
	    port[j] = input2[i];
	  }
	}
	int i_port = atoi(port);

	printf("ip = %s \n", ip);

	sockfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(i_port);
	Inet_pton(AF_INET, ip, &servaddr.sin_addr);

	Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));

	//scanf("%s", input2);

	} else if (menu == 1) {
	
       // scanf("%s", input2);
  //printf("was send.\n");
//	printf("i1%s\n", input);
//	printf("i2%s\n", input2);
//	printf("input 2 is equal to \n %s", input2);
	 sendtext(input2,sockfd);
//	printf("TEST");
	} else if (menu == -1) {
	  printf("failed comparison\n");
	} else {
	  printf("wtf %d\n", menu);
	}
//	sendtext(input2, sockfd);		/* do it all */

//	exit(0);
}}
