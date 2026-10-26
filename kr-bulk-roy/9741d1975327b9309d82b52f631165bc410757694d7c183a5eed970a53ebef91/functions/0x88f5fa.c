
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual class std::basic_string<char,struct std::char_traits<char>,class
   std::allocator<char> > __thiscall std::collate<char>::do_transform(char const *,char const
   *)const 
   
   Library: Visual Studio 2010 Release */

char * __thiscall std::collate<char>::do_transform(collate<char> *this,char *param_1,char *param_2)

{
  size_t sVar1;
  char *pcVar2;
  char *_String1;
  char *in_stack_0000000c;
  
  param_1[0x14] = '\x0f';
  param_1[0x15] = '\0';
  param_1[0x16] = '\0';
  param_1[0x17] = '\0';
  param_1[0x10] = '\0';
  param_1[0x11] = '\0';
  param_1[0x12] = '\0';
  param_1[0x13] = '\0';
  *param_1 = '\0';
  sVar1 = 0;
  if ((int)in_stack_0000000c - (int)param_2 != 0) {
    sVar1 = (int)in_stack_0000000c - (int)param_2;
    do {
      FUN_004296e0(sVar1,0);
      pcVar2 = param_1;
      if (0xf < *(uint *)(param_1 + 0x14)) {
        pcVar2 = *(char **)param_1;
      }
      _String1 = param_1;
      if (0xf < *(uint *)(param_1 + 0x14)) {
        _String1 = *(char **)param_1;
      }
      sVar1 = __Strxfrm(_String1,pcVar2 + *(int *)(param_1 + 0x10),param_2,in_stack_0000000c,
                        (_Collvec *)(this + 8));
    } while ((*(uint *)(param_1 + 0x10) < sVar1) && (sVar1 != 0));
  }
  FUN_004296e0(sVar1,0);
  return param_1;
}

