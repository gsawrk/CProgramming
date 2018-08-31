#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/errno.h>

#define tog(v,n) (v ^ (1<<n))

unsigned short toggleBits ( unsigned short a_val) {
  int val;
  val = tog(a_val,3);

  return val;
   return (0xffff ^ a_val);
   
};
 //  for(i = 0; i < 4; i++)^ a_val
int main(int argc, char **argv) {
unsigned short int val = 0, i,bit_tog;
   if(argc < 3) exit(1);
   val = (unsigned short) atoi(argv[1]);
   bit_tog = (unsigned short) atoi(argv[2]);
   printf(" val == %u\n" , val);
 {
      val = tog(val,bit_tog);
      printf(" tog val == %u\n" , val);
   } 
   return 0;
}
