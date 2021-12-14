#include "Wx_Encryption_H.h"

void GET_MESSEGE(char *);
void private_a_key_ENC(char *);
void private_a_key_DEC(char *);

void public_key_ENC(char *);
void public_key_DEC(char *);

void print_test(char *);

#define MAX_WORD 50

int main(void)
{
  char
      messege_a[MAX_WORD],
      messege_b[MAX_WORD],
      messege_dec[MAX_WORD];

  while(1)
  {
    // Send the messege for Device A to B
    printf("\n Message_A: ");
    GET_MESSEGE(messege_a);
    printf("\n");

    // Private Encrypt Message A
    printf("\n Private A ENC: ");
    private_a_key_ENC(messege_a);
    print_test(messege_a); // printing messege (A) after Prvt.E
    // Public Encrypt Message A
    public_key_ENC(messege_a);
    printf("\n Public A ENC: ");
    print_test(messege_a); // printing messege (A) after Pub.E
    printf("\n");

    printf("\n Public A DEC: ");
    public_key_DEC(messege_a);
    print_test(messege_a);

    printf("\n Private A DEC: ");
    private_a_key_DEC(messege_a);
    print_test(messege_a);
    printf("\n");
    /*
    // Send the messege for Device A to B
    printf("\n Message_B: ");
    GET_MESSEGE(messege_b);
    printf("\n");

    // Private Encrypt Message B
    printf("\n Private B ENC: ");
    private_b_key(messege_b);
    print_test(messege_b); // printing messege (B) after Prvt.E
    // Public Encrypt Message B
    printf("\n Public B ENC: ");
    public_key(messege_b);
    print_test(messege_b); // printing messege (B) after Pub.E
    printf("\n");
    */

  }

  printf("\n");
  return 0;
}

void print_test(char *messege_ptr)
{
  uint8_t counter = 0;

  while((*(messege_ptr+counter)) != '\0')
  {
    printf("%c", (*(messege_ptr+counter)));
    counter++;
  }
}

// MESSEGE SYSTEM:
void GET_MESSEGE(char *messege_ptr)
{
  uint8_t counter = 0;
  char  messege_temp;

  while(1)
  {
    messege_temp = getch();

    if(messege_temp == ENTER)
    {
      *(messege_ptr+counter) = '\0';
      break;
    }

    else if(messege_temp == BKSP)
    {
      if(counter > 0)
      {
        counter--;
        *(messege_ptr+counter) = '\0';
        printf("\b \b");
      }
    }

    else if(messege_temp == TAB || messege_temp == ESC || messege_temp == SPACE)
    {
      continue;
    }

    else
    {
      *(messege_ptr+counter) = messege_temp;
      printf("%c",*(messege_ptr+counter));
      counter++;
    }

    if(counter > MAX_WORD) {break;}
  }//end while.
}// end func.


// SECURING SYSTEM:
#define CPK_ENC 2

void public_key_ENC(char *messege_ptr)
{
  uint8_t counter = 0;

  while((*(messege_ptr+counter)) != '\0')
  {
    (*(messege_ptr+counter)) += CPK_ENC;
    counter++;
  }//end while.
}
void public_key_DEC(char *messege_ptr)
{
  uint8_t counter = 0;

  while((*(messege_ptr+counter)) != '\0')
  {
    (*(messege_ptr+counter)) -= CPK_ENC;
    counter++;
  }//end while.
}

#define CPAK_ENC 1

void private_a_key_ENC(char *messege_ptr)
{
  uint8_t counter = 0;

  while((*(messege_ptr+counter)) != '\0')
  {
    (*(messege_ptr+counter)) += CPAK_ENC;
    counter++;
  }//end while.
}

void private_a_key_DEC(char *messege_ptr)
{
  uint8_t counter = 0;

  while((*(messege_ptr+counter)) != '\0')
  {
    (*(messege_ptr+counter)) -= CPAK_ENC;
    counter++;
  }//end while.
}
