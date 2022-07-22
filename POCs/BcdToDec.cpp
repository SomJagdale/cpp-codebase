#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Maximum number of digits for conversion*/
#define BUFFSIZE    10
/* Zero character*/
#define ZERO_CHAR   '0'
/* New line*/
#define NEWLINE     '\n'
/* Newline*/
#define ENDOFLINE   '\0'
/* Decimal zero*/
#define ZERO         0
void BcdToAscii(unsigned char* bcd_text, unsigned char* ascii_text)
{
    size_t bcd_length = strlen((char*)bcd_text);
    printf("bcd lentght is %d \n",bcd_length);

    for (size_t i=0, j=0; (i < bcd_length) && (j < bcd_length*2); ++j, i++)
    {
        ascii_text[j] = bcd_text[i] & 0xF0;
        j++;
        ascii_text[j] = bcd_text[i] & 0x0F;
    }
}
int main()
{
    unsigned char input_bcd[5] = {1,2,3,4};
    unsigned char output_ascii[BUFFSIZE] = {0};
    BcdToAscii(input_bcd,output_ascii);
    printf("bcd is  %s and ascii is %s \n",input_bcd,output_ascii);
    printf("length bcd is  %d and ascii is %d \n",strlen((const char*)input_bcd),strlen((const char*)output_ascii));
    printf("bcd is   %s \n",input_bcd);
    for (size_t i = 0; i < 4; i ++)
    {
        printf(" %02x", input_bcd[i]);
    }
    printf("\nascii is %s \n",output_ascii);
    for (size_t i = 0; i < BUFFSIZE; i ++)
    {
        printf(" %02x", output_ascii[i]);
    }
    return 0;
}
      
