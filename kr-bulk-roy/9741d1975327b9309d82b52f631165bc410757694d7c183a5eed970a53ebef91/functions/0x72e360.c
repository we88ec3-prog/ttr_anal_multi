
undefined4 FUN_0072e360(void)

{
  int *piVar1;
  int iVar2;
  int *_Str1;
  undefined4 uVar3;
  char *unaff_EDI;
  
  piVar1 = (int *)FUN_0072e2e0(unaff_EDI);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  do {
    iVar2 = (**(code **)(*piVar1 + 0x18))();
    if (iVar2 != 0) {
                    /* WARNING: Could not recover jumptable at 0x0072e3bd. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar3 = (**(code **)(*piVar1 + 0x18))();
      return uVar3;
    }
    piVar1 = (int *)piVar1[0x10];
    while( true ) {
      if (piVar1 == (int *)0x0) {
        return 0;
      }
      _Str1 = piVar1 + 8;
      if (0xf < (uint)piVar1[0xd]) {
        _Str1 = (int *)*_Str1;
      }
      iVar2 = __stricmp((char *)_Str1,unaff_EDI);
      if (iVar2 == 0) break;
      piVar1 = (int *)piVar1[0x10];
    }
  } while (piVar1 != (int *)0x0);
  return 0;
}

