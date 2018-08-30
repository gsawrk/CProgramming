#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define UBX 0x0623
#define UBX_CLID(x)   ((x >> 8) & 0xFF)
#define UBX_MSGID(x)  (x  & 0xFF)

// Function to convert an unput hex string to a stream of hex numbers
int getHexNum(char * hexstr){
    char i, j, cl, ch, cx;
    int len;
    
    printf("Input hex string %s\n", hexstr);
    len = strlen(hexstr);
    if(len % 2){
        printf("Invalid input hex string length\n");
        return -1;
    }
        
    for(i=j=0;i < len;i++, j++){
        ch = hexstr[i];
        cl = hexstr[i+1];
        if (ch >= 'a' &&  ch <= 'f') ch -= 32;
        if (cl >= 'a' &&  cl <= 'f') cl -= 32;
        if(ch < '0' || ch > 'F' || cl < '0' || cl > 'F' || (ch > '9' && ch < 'A') || (cl > '9' && cl < 'A')){
            printf("Non hex character\n");
            return -1;
        }
        if (cl >= 'A' &&  cl <= 'F') cl -= 7;
        if (ch >= 'A' &&  ch <= 'F') ch -= 7;
        //printf("i = %d, j = %d, %02X \n",i, j, hexstr[j]);
        hexstr[j] = (((ch - '0') << 4)  | (cl - '0')) & 0xFF;
        i++;
        
    }
    printf("\n");
    
    if (j != len/2){
        printf("Invalid output hex string length %02X", hexstr[j]);
        return -1;
    }

    return j;
}

//Function to validate and write hex input string
int write_hex_string( char * header_str, char * hex_string, short hex_len){

    if(!strcmp(header_str, "CFG_NAVX5")){
        if((hex_string[0] != UBX_CLID(UBX)) || (hex_string[1] != UBX_MSGID(UBX))){
        //if((short)*hex_string != UBX){

            printf("Invalid output hex string UBXID_CFG_NAV5 %x-%x, UBX -> %x-%x\n", hex_string[0], hex_string[1], UBX_CLID(UBX), UBX_MSGID(UBX));
            return -1;
        }
        return 0; 
    }
}


int main()
{
        char input_cfg[] = "CFG_NAVX5-062328000000FFFF1F00000003020314060000010000DC060000000001010000006464000001100000000000";
    //28000000FFFF1F00000003020314060000010000DC060000000001010000006464000001100000000000
        char header_str[20];
        char * hex_string = NULL;
        short i = 0, hex_len;

        if(input_cfg == NULL){
            printf("The input configuration NULL");
            return;
        }
            
        printf("The input configuration string is %s\n", input_cfg);

        while((input_cfg[i] != '-') && i < 20){
            header_str[i] = input_cfg[i];
            i++;
        }
        header_str[i] = '\0';
        printf("header_str = %s\n", header_str);
        hex_string = &input_cfg[i+1];
        hex_len = getHexNum(hex_string);
        if (i < 0){
            printf("getHexNum : Error returned\n");
            return;
        }
        else
            printf("Hex String length = %d and class = %02X : msgid = %02X\n", hex_len, 0xFF & hex_string[0], 0xFF & hex_string[1]);
        write_hex_string( header_str, hex_string, hex_len);
        
        
}

