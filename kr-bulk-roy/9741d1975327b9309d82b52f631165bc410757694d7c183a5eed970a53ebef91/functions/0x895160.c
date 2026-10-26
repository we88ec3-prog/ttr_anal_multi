
/* WARNING: Function: __SEH_prolog4 replaced with injection: SEH_prolog4 */
/* WARNING: Function: __SEH_epilog4 replaced with injection: EH_epilog3 */
/* Library Function - Single Match
    __setmaxstdio
   
   Library: Visual Studio 2010 Release */

int __cdecl __setmaxstdio(int _Max)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  int local_20;
  
  if (0x7ec < _Max - 0x14U) {
    piVar1 = __errno();
    *piVar1 = 0x16;
    FUN_00893343();
    return -1;
  }
  __lock(1);
  if (DAT_00fe83c0 < _Max) {
    pvVar2 = __recalloc_crt(DAT_00fe73ac,_Max,4);
    if (pvVar2 == (void *)0x0) {
LAB_00895234:
      local_20 = -1;
      goto LAB_00895238;
    }
    for (; DAT_00fe83c0 < _Max; DAT_00fe83c0 = DAT_00fe83c0 + 1) {
      *(undefined4 *)((int)pvVar2 + DAT_00fe83c0 * 4) = 0;
    }
  }
  else {
    iVar3 = DAT_00fe83c0;
    if (_Max == DAT_00fe83c0) {
      local_20 = DAT_00fe83c0;
      goto LAB_00895238;
    }
    while( true ) {
      local_20 = _Max;
      iVar3 = iVar3 + -1;
      if (iVar3 < _Max) break;
      piVar1 = (int *)((int)DAT_00fe73ac + iVar3 * 4);
      if (*piVar1 != 0) {
        pvVar2 = (void *)*piVar1;
        if ((*(byte *)((int)pvVar2 + 0xc) & 0x83) != 0) goto LAB_00895234;
        _free(pvVar2);
      }
    }
    if (_Max == -1) goto LAB_00895238;
    pvVar2 = __recalloc_crt(DAT_00fe73ac,_Max,4);
    if (pvVar2 == (void *)0x0) goto LAB_00895234;
  }
  DAT_00fe83c0 = _Max;
  DAT_00fe73ac = pvVar2;
  local_20 = DAT_00fe83c0;
LAB_00895238:
  FUN_0089524d();
  return local_20;
}

