
int FUN_00559e90(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_14;
  int *local_10;
  uint local_8;
  
  iVar4 = 0;
  iVar5 = 0;
  FUN_004d8460();
  FUN_00542210();
  for (; local_8 != local_14; local_8 = local_8 + 1) {
    if (local_10 == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *local_10;
    }
    uVar1 = local_8;
    if (*(uint *)(iVar2 + 8) <= local_8) {
      uVar1 = local_8 - *(uint *)(iVar2 + 8);
    }
    iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 4) + uVar1 * 4) + 0x10);
    if (0x16 < iVar2) {
      iVar3 = (iVar2 - 0x17U) / 0x16 + 1;
      iVar4 = iVar4 + iVar3;
      iVar5 = 0x16;
      iVar2 = iVar2 + iVar3 * -0x16;
    }
    if (iVar2 != 0) {
      if (iVar5 <= iVar2) {
        iVar5 = iVar2;
      }
      iVar4 = iVar4 + 1;
    }
  }
  if (param_1 != (int *)0x0) {
    *param_1 = iVar5;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar4;
  }
  return iVar4;
}

