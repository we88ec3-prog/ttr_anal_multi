
/* Library Function - Multiple Matches With Same Base Name
    private: char * __cdecl std::num_put<char,class std::ostreambuf_iterator<char,struct
   std::char_traits<char> > >::_Ffmt(char *,char,int)const 
    private: char * __cdecl std::num_put<unsigned short,class std::ostreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> > >::_Ffmt(char *,char,int)const 
    private: char * __cdecl std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct
   std::char_traits<wchar_t> > >::_Ffmt(char *,char,int)const 
   
   Library: Visual Studio 2010 Release */

void Ffmt(undefined4 param_1,undefined1 *param_2,char param_3,uint param_4)

{
  undefined2 *puVar1;
  char *pcVar2;
  char cVar3;
  
  *param_2 = 0x25;
  puVar1 = (undefined2 *)(param_2 + 1);
  if ((param_4 & 0x20) != 0) {
    *(undefined1 *)puVar1 = 0x2b;
    puVar1 = (undefined2 *)(param_2 + 2);
  }
  if ((param_4 & 0x10) != 0) {
    *(undefined1 *)puVar1 = 0x23;
    puVar1 = (undefined2 *)((int)puVar1 + 1);
  }
  *puVar1 = 0x2a2e;
  pcVar2 = (char *)(puVar1 + 1);
  if (param_3 != '\0') {
    *pcVar2 = param_3;
    pcVar2 = (char *)((int)puVar1 + 3);
  }
  param_4 = param_4 & 0x3000;
  if (param_4 == 0x2000) {
    cVar3 = 'f';
  }
  else if (param_4 == 0x3000) {
    cVar3 = 'a';
  }
  else {
    cVar3 = (param_4 != 0x1000) * '\x02' + 'e';
  }
  *pcVar2 = cVar3;
  pcVar2[1] = '\0';
  return;
}

