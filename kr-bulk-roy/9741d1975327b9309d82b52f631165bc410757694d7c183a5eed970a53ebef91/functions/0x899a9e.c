
/* Library Function - Single Match
    _idtab
   
   Library: Visual Studio 2008 Release */

int * __cdecl idtab(void)

{
  uint uVar1;
  void *pvVar2;
  int *piVar3;
  int unaff_EDI;
  
  for (piVar3 = DAT_00f8cb6c; (piVar3 < DAT_00f8cb6c + DAT_00f8cb68 * 2 && (*piVar3 != unaff_EDI));
      piVar3 = piVar3 + 2) {
  }
  if (DAT_00f8cb6c + DAT_00f8cb68 * 2 <= piVar3) {
    if (((unaff_EDI == 0) && (uVar1 = DAT_00f8cb68 + 1, DAT_00f8cb68 <= uVar1)) &&
       (uVar1 < 0x1fffffff)) {
      pvVar2 = __recalloc_crt(DAT_00f8cb6c,uVar1,8);
      uVar1 = DAT_00f8cb68;
      if (pvVar2 != (void *)0x0) {
        DAT_00f8cb68 = DAT_00f8cb68 + 1;
        DAT_00f8cb6c = pvVar2;
        return (int *)((int)pvVar2 + uVar1 * 8);
      }
    }
    piVar3 = (int *)0x0;
  }
  return piVar3;
}

