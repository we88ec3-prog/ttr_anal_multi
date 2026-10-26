
/* Library Function - Multiple Matches With Same Base Name
    private: char * __cdecl std::num_put<char,class std::ostreambuf_iterator<char,struct
   std::char_traits<char> > >::_Ifmt(char *,char const *,int)const 
    private: char * __cdecl std::num_put<unsigned short,class std::ostreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Ifmt(char *,char const *,int)const 
    private: char * __cdecl std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Ifmt(char *,char const *,int)const 
   
   Library: Visual Studio 2010 Release */

void Ifmt(undefined4 param_1,undefined1 *param_2,char *param_3,uint param_4)

{
  char *pcVar1;
  byte *pbVar2;
  byte bVar3;
  
  *param_2 = 0x25;
  pcVar1 = param_2 + 1;
  if ((param_4 & 0x20) != 0) {
    *pcVar1 = '+';
    pcVar1 = param_2 + 2;
  }
  if ((param_4 & 8) != 0) {
    *pcVar1 = '#';
    pcVar1 = pcVar1 + 1;
  }
  if (*param_3 == 'L') {
    pcVar1[0] = 'I';
    pcVar1[1] = '6';
    pcVar1[2] = '4';
    pbVar2 = (byte *)(pcVar1 + 3);
  }
  else {
    *pcVar1 = *param_3;
    pbVar2 = (byte *)(pcVar1 + 1);
  }
  if ((param_4 & 0xe00) == 0x400) {
    bVar3 = 0x6f;
  }
  else if ((param_4 & 0xe00) == 0x800) {
    bVar3 = ~((char)param_4 << 3) & 0x20U | 0x58;
  }
  else {
    bVar3 = param_3[1];
  }
  *pbVar2 = bVar3;
  pbVar2[1] = 0;
  return;
}

