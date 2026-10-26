
void FUN_00858740(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_FS_OFFSET;
  int local_2c [4];
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908f08;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  iVar3 = (param_3 - param_1) / 0x14;
  iVar1 = (param_2 - param_1) / 0x14;
  iVar4 = iVar1;
  param_2 = iVar3;
  while (iVar2 = iVar4, iVar2 != 0) {
    iVar4 = param_2 % iVar2;
    param_2 = iVar2;
  }
  if ((param_2 < iVar3) && (0 < param_2)) {
    local_18 = iVar1 * 0x14;
    local_14 = param_1 + param_2 * 0x14;
    do {
      iVar3 = param_1;
      iVar4 = local_14;
      if (local_14 + local_18 != param_3) {
        iVar3 = local_14 + local_18;
      }
      do {
        iVar2 = iVar3;
        FUN_0052f3b0(local_2c,iVar4);
        local_1c = *(undefined4 *)(iVar4 + 0x10);
        local_8 = 0;
        FUN_006dd790(iVar2);
        *(undefined4 *)(iVar4 + 0x10) = *(undefined4 *)(iVar2 + 0x10);
        FUN_006dd790(local_2c);
        local_8 = 0xffffffff;
        *(undefined4 *)(iVar2 + 0x10) = local_1c;
        if (local_2c[0] != 0) {
          FUN_0089120c(local_2c[0]);
        }
        iVar3 = (param_3 - iVar2) / 0x14;
        if (iVar1 < iVar3) {
          iVar3 = iVar2 + local_18;
        }
        else {
          iVar3 = param_1 + (iVar1 - iVar3) * 0x14;
        }
        iVar4 = iVar2;
      } while (iVar3 != local_14);
      local_14 = local_14 + -0x14;
      param_2 = param_2 + -1;
    } while (0 < param_2);
  }
  *unaff_FS_OFFSET = local_10;
  return;
}

