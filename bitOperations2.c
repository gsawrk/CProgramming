/* Bit Masking */
/* http://www.indiabix.com/technical/c/bits-and-bytes/ */
/* Bit masking can be used to switch a character
   between lowercase and uppercase 
*/

#define SET_FLAG(N, P)        ( (N) | (1U << (P)) )
#define CLR_FLAG(N, P)        ( (N) & ~(1U << (P)) )
#define TST_FLAG(N, P)        ( (N) & (1U << (P)) )
#define TOG_FLAG(N, P)        ( (N) ^ (1U << (P)) )

/*
#define BIT_POS(N)            ( 1U << (N) )
#define SET_FLAG(N, F)        ( (N) | (F) )
#define CLR_FLAG(N, F)        ( (N) & ~(F) )
#define TST_FLAG(N, F)        ( (N) & (F) )
#define TOG_FLAG(N, F)        ( (N) ^ (F) )
*/

#define BIT_RANGE(N, M)       ( BIT_POS((M)+1 - (N))-1 << (N) )
#define BIT_SHIFTL(B, N)      ( (unsigned)(B) << (N) )
#define BIT_SHIFTR(B, N)      ( (unsigned)(B) >> (N) )
#define SET_MFLAG(N, F, V)    ( CLR_FLAG(N, F), SET_FLAG(N, V) )
#define CLR_MFLAG(N, F)       ( (N) &= ~(F) )
#define GET_MFLAG(N, F)       ( (N) & (F) )
#include <stdio.h>
void main()
{
  unsigned char ascii_char = 0x41;        /*  A: char = 8 bits only */
  int test_nbr = 10;
  printf("Starting character = %c\n", ascii_char);
  /*  The 5th bit position determines if the character is
      uppercase or lowercase.
      5th bit = 0  - Uppercase
      5th bit = 1  - Lowercase      
  printf("\nTurn 5th bit on = %c\n", SET_FLAG(ascii_char, BIT_POS(5)) );
  printf("Turn 5th bit off = %c\n\n", CLR_FLAG(ascii_char, BIT_POS(5)) );
  printf("Toggle 5th bit = %c\n\n", TOG_FLAG(ascii_char, BIT_POS(5)) );
  
  
  printf("Look at shifting bits\n");
  printf("=====================\n");
  printf("Current value = %d\n", test_nbr);
  printf("Shifting one position left = %d\n",
         test_nbr = BIT_SHIFTL(test_nbr, 1) );
  printf("Shifting two positions right = %d\n",
         BIT_SHIFTR(test_nbr, 2) );
*/

  printf("\nTurn 5th bit on in %c = %c\n",ascii_char, SET_FLAG(ascii_char, (5)) );
  printf("Turn 5th bit off in %c = %c\n\n",ascii_char, CLR_FLAG(ascii_char, (5)) );
  printf("Test 5th bit  in %c = %d\n\n",ascii_char, TST_FLAG(ascii_char, (5)) );
  printf("Toggle 5th bit in %c = %c\n\n",ascii_char, TOG_FLAG(ascii_char, (5)) );

}
/*
 * Output:
aadishri@smartplayfi07-OptiPlex-380:~/gsa/compile$ gcc -o Bit2 bitOperations2.c aadishri@smartplayfi07-OptiPlex-380:~/gsa/compile$ ./Bit2 
Starting character = A

Turn 5th bit on = a
Turn 5th bit off = A

Toggle 5th bit = a

Look at shifting bits
=====================
Current value = 10
Shifting one position left = 20
Shifting two positions right = 5
* 
* * [http://lwn.net/Kernel/LDD3/ Linux Device Drivers, Third Edition]
*/

