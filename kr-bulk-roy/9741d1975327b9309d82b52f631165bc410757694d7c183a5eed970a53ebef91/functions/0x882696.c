
/* Library Function - Multiple Matches With Same Base Name
    private: class std::ostreambuf_iterator<unsigned short,struct std::char_traits<unsigned short> >
   __cdecl std::num_put<unsigned short,class std::ostreambuf_iterator<unsigned short,struct
   std::char_traits<unsigned short> > >::_Putgrouped(class std::ostreambuf_iterator<unsigned
   short,struct std::char_traits<unsigned short> >,char const *,unsigned int,unsigned short)const 
    private: class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> > __cdecl
   std::num_put<wchar_t,class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >
   >::_Putgrouped(class std::ostreambuf_iterator<wchar_t,struct std::char_traits<wchar_t> >,char
   const *,unsigned int,wchar_t)const 
   
   Library: Visual Studio 2010 Release */

undefined4 *
Putgrouped(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
          void *param_5,size_t param_6,undefined4 param_7)

{
  undefined4 uVar1;
  void *pvVar2;
  undefined4 *puVar3;
  size_t sVar4;
  undefined1 local_14 [8];
  undefined4 local_c;
  undefined4 local_8;
  
  while( true ) {
    pvVar2 = _memchr(param_5,0,param_6);
    sVar4 = param_6;
    if (pvVar2 != (void *)0x0) {
      sVar4 = (int)pvVar2 - (int)param_5;
    }
    puVar3 = (undefined4 *)Putc(param_1,local_14,param_3,param_4,param_5,sVar4);
    param_3 = *puVar3;
    param_4 = puVar3[1];
    if (param_6 - sVar4 == 0) break;
    if ((short)param_7 != 0) {
      local_c = *puVar3;
      local_8 = puVar3[1];
      FID_conflict_operator_(param_7);
      param_3 = local_c;
      param_4 = local_8;
    }
    param_5 = (void *)((int)param_5 + sVar4 + 1);
    param_6 = (param_6 - sVar4) - 1;
  }
  uVar1 = *puVar3;
  param_2[1] = puVar3[1];
  *param_2 = uVar1;
  return param_2;
}

