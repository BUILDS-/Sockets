#include	"unp.h"




int
main(int argc, char **argv)
{
	int					sockfd;
	struct sockaddr_in	servaddr;
	char input[50] = {0};
        char connect[] = "connect";
	char send[] = "send";

	printf("hivemind$");
	scanf("%s", input);
	

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
	  }
	}

	if (menu == 0) {
	  printf("was connect.\n");
	} else if (menu == 1) {
	  printf("was send.\n");
	} else if (menu == -1) {
	  printf("failed comparison\n");
	} else {
	  printf("wtf %d\n", menu);
	}
	scanf("%s", input);
	printf("%s\n", input);
	//Very not rooboost. (Levin-ism)
	char ip[20] = "\0";
	char port[10] = "\0";
	if (menu == 0) {
	  for(i = 0; input[i] != ':' && i < 35; i++) {
	    printf("%d %c\n", i, input[i]);
	    ip[i] = input[i];
	  }
	  int j;
	  i++;
	  for(j = 0; input[i]; i++, j++) {
	    port[j] = input[i];
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

	str_cli(stdin, sockfd);		/* do it all */

	exit(0);
}
