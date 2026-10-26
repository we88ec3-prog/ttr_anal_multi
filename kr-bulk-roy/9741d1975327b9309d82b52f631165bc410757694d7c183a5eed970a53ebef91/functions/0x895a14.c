
/* Library Function - Multiple Matches With Different Base Names
    _swscanf
    _swscanf_s
   
   Library: Visual Studio 2010 Release */

int __cdecl FID_conflict__swscanf(wchar_t *_Src,wchar_t *_Format,...)

{
  int iVar1;
  
  iVar1 = vscan_fn(__winput_s_l,_Format,0,&stack0x0000000c);
  return iVar1;
}

