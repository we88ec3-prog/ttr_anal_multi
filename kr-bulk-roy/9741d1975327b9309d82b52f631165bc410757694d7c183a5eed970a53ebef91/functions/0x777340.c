
uint FUN_00777340(int *param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  uint *unaff_ESI;
  ushort *unaff_EDI;
  
  uVar1 = *unaff_EDI;
  if (uVar1 < 0xe01) {
    return 1;
  }
  if (0xe5b < uVar1) {
    return 1;
  }
  if (uVar1 < 0xe2f) {
    return 1;
  }
  iVar2 = FUN_00777240(param_2);
  if (iVar2 < 0) {
    if (iVar2 != -1) {
      return 0xffffffff;
    }
    iVar2 = FUN_00777150();
    if ((iVar2 == 0) && (iVar2 = FUN_00777180(), iVar2 == 0)) {
      if (*unaff_EDI < 0xe50) {
        return 0xffffffff;
      }
      if (0xe59 < *unaff_EDI) {
        return 0xffffffff;
      }
    }
    return 1;
  }
  uVar3 = *unaff_ESI;
  if (param_1[1] == 0) {
    if (-1 < (int)(uVar3 - (uVar3 - 1))) {
      return (uint)(uVar3 <= *(uint *)(param_2 + 0x10));
    }
  }
  else {
    iVar2 = FUN_00777530(uVar3 - 1,param_2,unaff_EDI);
    if (iVar2 != 0) {
      return 1;
    }
    if (*param_1 != 0) {
      uVar3 = FUN_00777780(param_2,unaff_EDI,unaff_ESI);
      return uVar3;
    }
  }
  return 0;
}

