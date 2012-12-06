/*Testdec.c 
Creates a shell script that runs 100 iterations of the cpabe-dec
In both horizontal and vertical attribute trees
Note: Requires the script from testenc.c to be run first.

Russ Martin
12/6/12
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

int main(int argc, char** argv)
{
  FILE* file;
  int i,j;
  
  file=fopen("testdec.sh","w");
  for(i=1; i<=100; i++)
  {
    //Horizontal
    fprintf(file,"%s%d%s","echo i=",i,"\n");
    fprintf(file,"%s%d %s","cpabe-keygen -o priv",i,"pub_key master_key ");
    j=1;
    while(j<=i)
    {
      fprintf(file,"%s%d","prop",j);
      if(j<i)
      {
        fprintf(file,"%s"," ");
      }
      j++;
    }
    fprintf(file,"%s","\n");
    
    //Vertical
    fprintf(file,"%s%d%s","cpabe-keygen -o priv",i,"n pub_key master_key ");
    if(i<64)
    {
      fprintf(file,"%s%d%s","\"prop = 1#",i,"\"\n");
    }
    else
    {
      fprintf(file,"%s%d%s","\"prop = 1#63\" \"prop2 = 1#",i-63,"\"\n");
    }
  }
  fclose(file);
  return 0;
}