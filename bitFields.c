/* 
 * 1-bit signed field on a two's complement machine can only take the values 0 or -1.
 * Bit fields do not have addresses—you can't have pointers to them or arrays of them.
 * The unsigned definition is important - ensures that no bits are used as a  flag
 * Some bit field members are stored left to right others are stored right to left in memory
 * always explicitly mark 1-bit bit fields as unsigned
 * 
 * **************************************************************************************
 * http://www.9wy.net/onlinebook/CPrimerPlus5/ch15lev1sec4.html :
make sure the value doesn't exceed the capacity of the field.
What if the total number of bits you declare exceeds the size of an unsigned int? 
* Then the next unsigned int storage location is used. A single field is not allowed to overlap the boundary between two unsigned ints. The compiler automatically shifts an overlapping field definition so that the field is aligned with the unsigned int boundary. When this occurs, it leaves an unnamed hole in the first unsigned int.
You can "pad" a field structure with unnamed holes by using unnamed field widths. 
* Using an unnamed field width of 0 forces the next field to align with the next integer:
struct {
    unsigned int field1 : 1;
    unsigned int        : 2;
    unsigned int field2 : 1;
    unsigned int        : 0;
    unsigned int field3 : 1;
} stuff;

Here, there is a 2-bit gap between stuff.field1 and stuff.field2, and stuff.field3 is stored in the next int.
 * **************************************************************************************
 

 * 
 * 
 */
/* fields.c -- define and use fields */
#include <stdio.h>
/* opaque and show */
#define YES     1
#define NO      0
/* line styles     */
#define SOLID   0
#define DOTTED  1
#define DASHED  2
/* primary colors  */
#define BLUE    4
#define GREEN   2
#define RED     1
/* mixed colors    */
#define BLACK   0
#define YELLOW  (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN    (GREEN | BLUE)
#define WHITE   (RED | GREEN | BLUE)
const char * colors[8] = {"black", "red", "green", "yellow",
            "blue", "magenta", "cyan", "white"};

struct box_props {
    unsigned int opaque         : 1;
    unsigned int fill_color     : 3;
    unsigned int                : 4;
    unsigned int show_border    : 1;
    unsigned int border_color   : 3;
    unsigned int border_style   : 2;
    unsigned int                : 2;
};

void show_settings(const struct box_props * pb);

int main(void)
{
    /* create and initialize box_props structure */
    struct box_props box = {YES, YELLOW , YES, GREEN, DASHED};

    printf("Original box settings:\n");
    show_settings(&box);

    box.opaque = NO;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;
    printf("\nModified box settings:\n");
    show_settings(&box);

    return 0;
}

void show_settings(const struct box_props * pb)
{
    printf("Box is %s.\n",
            pb->opaque == YES? "opaque": "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n",
            pb->show_border == YES? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf ("The border style is ");
    switch(pb->border_style)
    {
        case SOLID  : printf("solid.\n"); break;
        case DOTTED : printf("dotted.\n"); break;
        case DASHED : printf("dashed.\n"); break;
        default     : printf("unknown type.\n");
    }
}
/*
Here is the output:
* * * * * * * * * * * * *
Original box settings:
Box is opaque.
The fill color is yellow.
Border shown.
The border color is green.
The border style is dashed.

Modified box settings:
Box is transparent.
The fill color is white.
Border shown.
The border color is magenta.
The border style is solid.
* * * * * * * * * * * * *

* */

