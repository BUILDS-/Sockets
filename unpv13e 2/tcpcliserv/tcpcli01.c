#include	"unp.h"
#include <string.h>



void 
sendtext(char* fp, int sockfd)
{
  printf("%s", fp);
  
  char sendline[MAXLINE], recvline[MAXLINE];
 
        printf("%s", sendline);

/*while(Fgets(sendline, MAXLINE, fp) != NULL) 
{
printf("%s\n", "inside while");
	Writen(sockfd, sendline, strlen(sendline));
	printf("%s\n", "after writen");
	if (Readline(sockfd, recvline, MAXLINE) == 0)
	err_quit("str_cli: server terminated prematurely");

	Fputs(recvline, stdout);
}*/

 
 // while(1)
   // {
      	int lengths = strlen(fp);
//	printf("%d", lengths);
	Writen(sockfd, fp, lengths);
//	printf("%s\n", "under writen");
      if(Readline(sockfd, recvline, lengths+1) == 0)
	{
	  err_quit("send: server terminated prematurely");
	}
	printf("%s", recvline);
	//Fputs(recvline, stdout);
//	if(fp[s]='\0') 
//		break;
    //}
}
int
main(int argc, char **argv)
{
  //Checks to see if the socket has been connected yet or not.
  int connected = 0;
  int sockfd;
  struct sockaddr_in	servaddr;
  
  //Global strings to compare inputs against.
  char connect[] = "connect";
  char send[] = "send";
  
  //Prompt user with our username.
  printf("hivemind$");
  
  //While true loop
  while(1){
    
    //Sets input and input2 to take in scanfs and sets them to the null set.
    char input[50]={0};
    char input2[200]={0};
    
    //Scans word one to input
    scanf("%s", input);
    
    //If already connected. (for formatting purposes.)
    //HEY GUYS! WHY CAN'T WE JUST USE %[^\n]s IN BOTH CASES?
    //ALSO, I'M NOT REALLY IN THE STATE TO KNOW HOW TO ELIMINATE THE
    //DAMN SPACE AT THE BEGINNING OF EVERY DAMN ECHO. KILL IT.
    if(connected==1)
      scanf("%[^\n]s", input2);
    else
      //otherwise, just run this.
      scanf("%s", input2);
    
    
    //Initializes the integer that stores whether the user wants to connect
    //or send a string. Not hard coded.
    int menu = -1;
    
    int i;
    
    //if the first word is "connect" menu is set to 0. Else set to -1.
    for (i = 0; connect[i] != '\0'; i++) {
      char x = connect[i];
      if (x != input[i]) {
	menu = -1;
	break;
      }
      menu = 0;
      connected = 1;
    }
    
    //if the word isn't "connect" check to see if it's "send".
    //if it is send, set menu to 1. Else set to -1.
    if(menu != 0) {
      for (i = 0; send[i] != '\0'; i++) {
	char x = send[i];
	if (x != input[i]) {
	  menu = -1;
	  break;
	}
	menu = 1;
	
      }
    }
    
    
    
    if (menu == 0) {
      //printf("debug: was connect.\n");
      
      //printf("%s\n", input);
      
      //Very not rooboost. (Levin-ism)
      
      //where the entered ip address will be stored.
      char ip[20] = "\0";
      //where the entered port will be stored.
      char port[10] = "\0";
      
      //If the user wanted to connect. Read the ip address and
      //the port number in.
      if (menu == 0) {
	for(i = 0; input2[i] != ':' && i < 35; i++) {
	  //printf("debug: %d %c\n", i, input2[i]);
	  ip[i] = input2[i];
	}
	int j;
	i++;
	for(j = 0; input2[i]; i++, j++) {
	  port[j] = input2[i];
	}
      }
      
      //Translates the string of the port into an int
      int i_port = atoi(port);
      
      //printf("debug: ip = %s \n", ip);
      

      sockfd = Socket(AF_INET, SOCK_STREAM, 0);
      
      bzero(&servaddr, sizeof(servaddr));
      servaddr.sin_family = AF_INET;
      servaddr.sin_port = htons(i_port);
      Inet_pton(AF_INET, ip, &servaddr.sin_addr);
	  
      Connect(sockfd, (SA *) &servaddr, sizeof(servaddr));
      

      //Else, if the user wanted to send a string.
    } else if (menu == 1) {
      
 
      //printf("debug: was send.\n");

      //printf("debug: input2 = %s \n", input2);
      sendtext(input2,sockfd);

      printf("\n");
      //If the user printed neither "connect" nor "send"
    } else if (menu == -1) {
      printf("failed comparison\n");
    } else {
      //If it gets here, something is very wrong.
      printf("wtf: %d\n", menu);
    }
    //	sendtext(input2, sockfd);		/* do it all */
    
    //	exit(0);
  }
}
