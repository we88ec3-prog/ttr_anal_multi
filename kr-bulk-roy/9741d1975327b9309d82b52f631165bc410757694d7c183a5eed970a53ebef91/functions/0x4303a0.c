
uint FUN_004303a0(undefined4 param_1,undefined4 param_2,_Cvtvec *param_3)

{
  mbstate_t local_c;
  uint local_8;
  
  local_8 = 0;
  local_c = 0;
  __Mbrtowc((wchar_t *)&local_8,(char *)&param_1,1,&local_c,param_3);
  return local_8 & 0xffff;
}

