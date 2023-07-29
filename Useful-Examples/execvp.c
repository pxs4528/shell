#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>

int main( )
{
  printf("gajg");
  pid_t pid = fork( );
  if( pid == 0 )
  {

    char *arguments[4];

    arguments[0] = ( char * ) malloc( strlen( "./a.out" ) );
    arguments[1] = ( char * ) malloc( strlen( NULL ) );

    strncpy( arguments[0], "./a.out", strlen( "./a.out" ) );
    strncpy( arguments[1], NULL, strlen( "-l" ) );

    arguments[2] = NULL;

    // Notice you can add as many NULLs on the end as you want
    int ret = execvp( arguments[0], &arguments[0] );  
    if( ret == -1 )
    {
      perror("execl failed: ");
    }
  }
  else 
  {
    int status;
    wait( & status );
  }

  return 0;
}
