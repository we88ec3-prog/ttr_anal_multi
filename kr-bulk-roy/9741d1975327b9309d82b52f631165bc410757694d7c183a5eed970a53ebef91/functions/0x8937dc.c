
/* Library Function - Single Match
    __cinit
   
   Library: Visual Studio 2010 Release */

int __cdecl __cinit(int param_1)

{
  BOOL BVar1;
  int iVar2;
  undefined4 *puVar3;
  
  BVar1 = __IsNonwritableInCurrentImage((PBYTE)&PTR___fpmath_00bd43b0);
  if (BVar1 != 0) {
    __fpmath(param_1);
  }
  __initp_misc_cfltcvt_tab();
  iVar2 = __initterm_e(&DAT_00bd2ba4,&DAT_00bd2bc8);
  if (iVar2 == 0) {
    _atexit((_func_4879 *)&LAB_008a7741);
    puVar3 = &DAT_00bd26ec;
    do {
      if ((code *)*puVar3 != (code *)0x0) {
        (*(code *)*puVar3)();
      }
      puVar3 = puVar3 + 1;
    } while (puVar3 < &DAT_00bd2ba0);
    if ((DAT_00fe83d4 != (code *)0x0) &&
       (BVar1 = __IsNonwritableInCurrentImage((PBYTE)&DAT_00fe83d4), BVar1 != 0)) {
      (*DAT_00fe83d4)(0,2,0);
    }
    iVar2 = 0;
  }
  return iVar2;
}

