/*
 * We can turn a bit on by a bitwise OR ( | ) with 1 in the relevant position.
 * We can test whether a bit is set by a bitwise AND (&) with 1 in the relevant position.
 * We can turn a bit off by a bitwise AND (&) with NOT (∼) 1 in the relevant position.
We can toggle a bit by a bitwise XOR (^) with 1 in the relevant position.
*/

/* Bit Masking */
/* http://www.indiabix.com/technical/c/bits-and-bytes/ */
/* Bit masking can be used to switch a character
   between lowercase and uppercase 
*/

#define SET_FLAG(N, P)        ( (N) | (1U << (P)) )
#define CLR_FLAG(N, P)        ( (N) & ~(1U << (P)) )
#define TST_FLAG(N, P)        ( (N) & (1U << (P)) )
#define TOG_FLAG(N, P)        ( (N) ^ (1U << (P)) )


#include <stdio.h>
void main()
{
  unsigned char ascii_char = 0x41;        /*  A: char = 8 bits only */
  
  printf("Starting character = %c\n", ascii_char);
  /*  The 5th bit position determines if the character is
      uppercase or lowercase.
      5th bit = 0  - Uppercase
      5th bit = 1  - Lowercase   
*/

  printf("\nTurn 5th bit on in %c = %c\n",ascii_char, SET_FLAG(ascii_char, (5)) );
  printf("Turn 5th bit off in %c = %c\n\n",ascii_char, CLR_FLAG(ascii_char, (5)) );
  printf("Test 5th bit  in %c = %d\n\n",ascii_char, TST_FLAG(ascii_char, (5)) );
  printf("Toggle 5th bit in %c = %c\n\n",ascii_char, TOG_FLAG(ascii_char, (5)) );

}

/*
 * Output:
aadishri@smartplayfi07-OptiPlex-380:~/gsa/compile$ gcc bitOperations.c 
aadishri@smartplayfi07-OptiPlex-380:~/gsa/compile$ ./a.out
Starting character = A

Turn 5th bit on in A = a
Turn 5th bit off in A = A

Test 5th bit  in A = 0

Toggle 5th bit in A = a

* 
* * [http://lwn.net/Kernel/LDD3/ Linux Device Drivers, Third Edition]
*/

