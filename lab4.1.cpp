#include "sdt.h"

void print_in_binary(uint8_t byte)
{
    for(int i=0; i<8; i++)
    {
      if ((byte) & (128>>i))
            cout << '1';
      else
            cout << '0';
    }
}

//для print_in_hexNEW
void print(string str)
{
   if (str == "0000") cout <<'0';
   if (str == "0001") cout <<'1';
   if (str == "0010") cout <<'2';
   if (str == "0011") cout <<'3';
   if (str == "0100") cout <<'4';
   if (str == "0101") cout <<'5';
   if (str == "0110") cout <<'6';
   if (str == "0111") cout <<'7';
   if (str == "1000") cout <<'8';
   if (str == "1001") cout <<'9';
   if (str == "1010") cout <<'A';
   if (str == "1011") cout <<'B';
   if (str == "1100") cout <<'C';
   if (str == "1101") cout <<'D';
   if (str == "1110") cout <<'E';
   if (str == "1111") cout <<'F';
}

void print_in_hexNEW(uint8_t byte)
{
    string s1,s2;
    for(int i=0; i<4; i++)
    {
      if ((byte) & (1 <<i))  s1='1'+s1;
      else                    s1='0'+s1;
    }

    for(int i=4; i<8; i++)
    {
      if ((byte) & (1<<i))    s2='1'+s2;
      else                    s2='0'+s2;
    }
    print(s2);
    print(s1);
}
//коротко и сурово, но работает некорректно
void print_in_hex(uint8_t byte)
{
    const int sixteen=16;
    string s;
    if (byte==0) s="00";
    while (byte)
    {
       s="0123456789ABCDEF"[byte%sixteen]+s;
        byte/=sixteen;
    }
    cout <<s;
}

void print_in_binaryA(const void* data, size_t size)
{
    uint8_t* one=(uint8_t*)data;
    for(int i=0; i<size; i++)
    {
      print_in_binary(*one);
      cout<<' ';
      one+=1;
    }
}

void print_in_hexA(const void* data, size_t size)
{
    uint8_t* one=(uint8_t*)data;
    for(int i=0; i<size; i++)
    {
      print_in_hexNEW(*one);
      cout<<' ';
      one+=1;
    }
}

int main()
{
    uint16_t x;
    cin >> x;
    cout <<"in binary (one byte)"<<endl;
    print_in_binary(x);
    cout <<"\nin hex (one byte)"<<endl;
    print_in_hexNEW(x);
    cout <<"\n\nin binary (all byte)"<<endl;
    print_in_binaryA(&x,sizeof(x));
    cout <<"\n\nin hex (all byte)"<<endl;
    print_in_hexA(&x,sizeof(x));
}
