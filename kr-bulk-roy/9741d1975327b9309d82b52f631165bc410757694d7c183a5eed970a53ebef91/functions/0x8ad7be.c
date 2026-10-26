
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    ___tzset
   
   Library: Visual Studio 2010 Release */

void __cdecl ___tzset(void)

{
  if (DAT_00f8d73c == 0) {
    __lock(6);
    if (DAT_00f8d73c == 0) {
      FUN_008ad0dd();
      DAT_00f8d73c = DAT_00f8d73c + 1;
    }
    FUN_008ad804();
  }
  return;
}

