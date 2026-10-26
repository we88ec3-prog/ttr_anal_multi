
void FUN_00430ee0(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar4;
  undefined2 *unaff_ESI;
  undefined4 uVar5;
  uint local_4c [4];
  undefined4 local_3c;
  uint local_38;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091bd88;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar5 = 0;
  local_14 = uVar2;
  if (((*(uint *)(param_1 + 0x40) & 2) == 0) && (**(uint **)(param_1 + 0x24) != 0)) {
    uVar1 = **(uint **)(param_1 + 0x24);
    uVar3 = *(uint *)(param_1 + 0x3c);
    if (*(uint *)(param_1 + 0x3c) < uVar1) {
      uVar3 = uVar1;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (uint)local_30._2_2_ << 0x10;
    FUN_00402160(**(int **)(param_1 + 0x14),(int)(uVar3 - **(int **)(param_1 + 0x14)) >> 1);
    local_8 = 0;
  }
  else {
    if (((*(uint *)(param_1 + 0x40) & 4) != 0) || (**(int **)(param_1 + 0x20) == 0)) {
      local_38 = 7;
      local_3c = 0;
      local_4c[0] = local_4c[0] & 0xffff0000;
      local_8 = 2;
      *(undefined4 *)(unaff_ESI + 10) = 7;
      *(undefined4 *)(unaff_ESI + 8) = 0;
      *unaff_ESI = 0;
      FUN_00402800(local_4c);
      uVar4 = extraout_EDX_00;
      uVar1 = local_4c[0];
      uVar3 = local_38;
      goto joined_r0x00430fee;
    }
    local_1c = 7;
    local_20 = 0;
    local_30 = (uint)local_30._2_2_ << 0x10;
    FUN_00402160(**(int **)(param_1 + 0x10),
                 (**(int **)(param_1 + 0x20) + **(int **)(param_1 + 0x30) * 2) -
                 **(int **)(param_1 + 0x10) >> 1);
    local_8 = 1;
  }
  *(undefined4 *)(unaff_ESI + 10) = 7;
  *(undefined4 *)(unaff_ESI + 8) = 0;
  *unaff_ESI = 0;
  FUN_00402800(&local_30);
  uVar4 = extraout_EDX;
  uVar1 = local_30;
  uVar3 = local_1c;
joined_r0x00430fee:
  if (7 < uVar3) {
    FUN_0089120c(uVar1,uVar2);
    uVar4 = extraout_EDX_01;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar4,uVar5);
  return;
}

