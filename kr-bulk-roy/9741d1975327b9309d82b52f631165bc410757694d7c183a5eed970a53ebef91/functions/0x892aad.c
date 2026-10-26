
/* WARNING: Removing unreachable block (ram,0x00892af4) */
/* Library Function - Single Match
    _wctob
   
   Libraries: Visual Studio 2008 Release, Visual Studio 2010 Release */

int __cdecl _wctob(wint_t _WCh)

{
  int iVar1;
  localeinfo_struct *unaff_ESI;
  int *unaff_EDI;
  undefined2 in_stack_00000006;
  int local_10 [2];
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (_WCh != 0xffff) {
    _wcrtomb_s_l(local_10,(char *)0x5,__WCh,L'\0',unaff_EDI,unaff_ESI);
  }
  iVar1 = __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return iVar1;
}

