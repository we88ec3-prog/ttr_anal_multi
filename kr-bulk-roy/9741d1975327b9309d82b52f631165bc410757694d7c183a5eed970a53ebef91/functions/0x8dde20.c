
int FUN_008dde20(uint param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *unaff_EDI;
  int local_8;
  
  uVar4 = 0;
  if ((unaff_EDI == (int *)0x0) || ((uint)unaff_EDI[2] <= param_1)) {
    return 6;
  }
  iVar2 = unaff_EDI[6];
  iVar1 = *unaff_EDI;
  if (iVar2 == 0) {
    iVar2 = FUN_008b97e0(iVar1,unaff_EDI[1] + 3 + *(byte *)(unaff_EDI + 3) * param_1);
    if (iVar2 != 0) {
      return iVar2;
    }
    uVar3 = FUN_008dd9a0();
    if (uVar3 != 0) {
      do {
        param_1 = param_1 + 1;
        uVar4 = FUN_008dd9a0();
        if (uVar4 != 0) break;
      } while (param_1 < (uint)unaff_EDI[2]);
    }
  }
  else {
    uVar3 = *(uint *)(iVar2 + param_1 * 4);
    iVar2 = iVar2 + param_1 * 4;
    if (uVar3 != 0) {
      do {
        uVar4 = *(uint *)(iVar2 + 4);
        iVar2 = iVar2 + 4;
        param_1 = param_1 + 1;
        if (uVar4 != 0) break;
      } while (param_1 < (uint)unaff_EDI[2]);
    }
  }
  local_8 = 0;
  iVar2 = *(int *)(iVar1 + 4);
  if ((iVar2 + 1U < uVar4) || ((iVar2 - uVar4) + 1 < (uint)unaff_EDI[4])) {
    uVar4 = (iVar2 - unaff_EDI[4]) + 1;
  }
  if ((uVar3 != 0) && (uVar3 < uVar4)) {
    *param_3 = uVar4 - uVar3;
    if (unaff_EDI[7] == 0) {
      local_8 = FUN_008b97e0(iVar1,unaff_EDI[4] + -1 + uVar3);
      if (local_8 == 0) {
        iVar2 = FUN_008bc7a0(iVar1,uVar4 - uVar3,param_2);
        return iVar2;
      }
    }
    else {
      *param_2 = unaff_EDI[7] + -1 + uVar3;
    }
    return local_8;
  }
  *param_2 = 0;
  *param_3 = 0;
  return 0;
}

