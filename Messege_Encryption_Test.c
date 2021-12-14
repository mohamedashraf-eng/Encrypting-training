#include "Wx_Encryption_H.h"

uint16_t FIB_ENCRYPTION_KEY(uint16_t );
void  MESSEGE_ENCRYPTOR(char *);
void  messege();

#define MAX_WORD_LENGTH 7
char *m_ptr  = NULL;
char *em_ptr = NULL;

int main(void)
{
  uint8_t c = 0;

  while(1)
  {
    printf("\n Messege: ");
    messege();

    printf("\n Encrypted messege: ");
    MESSEGE_ENCRYPTOR(m_ptr);
    while(*(em_ptr+c) != '\0')
    {
      printf("%c", *(em_ptr+c));
      c++;
    }
    c = 0;
    printf("\n \n");
  }

  printf("\n");
  return 0;
}

void messege()
{
  static char messege[MAX_WORD_LENGTH];
  m_ptr = messege;
  char charbychar;
  uint8_t counter = 0;

  while(1)
  {
    charbychar = getch();

    if(charbychar == ENTER)
      {
        messege[counter+1] = '\0';
        break;
      }
    else if(charbychar == BKSP)
    {
      if(counter > 0)
      {
        counter--;
        messege[counter] = '\0';
        printf("\b \b");
      }
    }
    else if(charbychar == TAB || charbychar == ESC)
    {
      continue;
    }
    else
    {
      messege[counter] = charbychar;
      printf("%c", charbychar);
      counter += 1;
    }
  }
}

uint16_t FIB_ENCRYPTION_KEY(uint16_t Enc_Limit)
{
  uint16_t F[2] = {0 , 1};
  uint16_t F_NUM = 0;

  uint16_t counter = 0;

  if(Enc_Limit == 1 || Enc_Limit == 2){return 1;}
  else if(Enc_Limit == 0) {return 0;}
  else
  {
    while(counter < Enc_Limit)
    {
      F_NUM = F[0] + F[1];
      F[0] = F[1];
      F[1] = F_NUM;
      counter += 1;
    }
  }
  return F_NUM;
}

void MESSEGE_ENCRYPTOR(char *messege)
{
  uint16_t counter   = 0;
  static char enc_messege[MAX_WORD_LENGTH];
  em_ptr = enc_messege;

  static uint8_t Key_Factor = 3;

  while(*(messege+counter) != '\0')
  {
    *(em_ptr+counter) = ((*(messege+counter)) ^ FIB_ENCRYPTION_KEY(Key_Factor)) >> 2;
    counter += 1;
  }

  Key_Factor += 3;
}
