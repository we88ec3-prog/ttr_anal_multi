
/* WARNING: Function: __EH_prolog3 replaced with injection: EH_prolog3 */
/* WARNING: Function: __EH_epilog3 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    protected: virtual class std::basic_string<wchar_t,struct std::char_traits<wchar_t>,class
   std::allocator<wchar_t> > __thiscall std::collate<wchar_t>::do_transform(wchar_t const *,wchar_t
   const *)const 
   
   Library: Visual Studio 2010 Release */

wchar_t * __thiscall
std::collate<wchar_t>::do_transform(collate<wchar_t> *this,wchar_t *param_1,wchar_t *param_2)

{
  size_t sVar1;
  size_t sVar2;
  wchar_t *pwVar3;
  wchar_t *_String1;
  wchar_t *in_stack_0000000c;
  
  param_1[10] = L'\a';
  param_1[0xb] = L'\0';
  param_1[8] = L'\0';
  param_1[9] = L'\0';
  *param_1 = L'\0';
  sVar1 = (int)in_stack_0000000c - (int)param_2 >> 1;
  sVar2 = 0;
  if (sVar1 != 0) {
    sVar2 = sVar1;
    do {
      FUN_004400d0(sVar2,0);
      pwVar3 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        pwVar3 = *(wchar_t **)param_1;
      }
      _String1 = param_1;
      if (7 < *(uint *)(param_1 + 10)) {
        _String1 = *(wchar_t **)param_1;
      }
      sVar2 = __Wcsxfrm(_String1,pwVar3 + *(int *)(param_1 + 8),param_2,in_stack_0000000c,
                        (_Collvec *)(this + 8));
    } while ((*(uint *)(param_1 + 8) < sVar2) && (sVar2 != 0));
  }
  FUN_004400d0(sVar2,0);
  return param_1;
}

