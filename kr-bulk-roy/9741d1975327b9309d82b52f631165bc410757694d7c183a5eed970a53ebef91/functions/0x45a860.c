
void FUN_0045a860(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 in_stack_00000024;
  uint in_stack_00000038;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54 [5];
  uint local_40;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_0091bb00;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = 0;
  if (*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2 != 0) {
    do {
      iVar1 = *(int *)(*(int *)(param_1 + 0xec) + 0xcc);
      if (iVar1 != 0) {
        for (piVar3 = *(int **)(iVar1 + 0xa8); piVar3 != *(int **)(iVar1 + 0xac);
            piVar3 = piVar3 + 1) {
          iVar4 = *piVar3;
          if (*(uint *)(iVar4 + 0x20) == local_14) goto LAB_0045a8e4;
        }
      }
      iVar4 = 0;
LAB_0045a8e4:
      if (*(int *)(iVar4 + 0x20) == param_2) {
        FUN_00609da0(uVar2);
        iVar1 = *(int *)(*(int *)(param_1 + 0xf0) + local_14 * 4);
        local_8._0_1_ = 1;
        *(undefined4 *)(iVar1 + 0x2b0) = local_6c;
        *(undefined4 *)(iVar1 + 0x2b4) = local_68;
        *(undefined4 *)(iVar1 + 0x2b8) = local_64;
        *(undefined4 *)(iVar1 + 700) = local_60;
        *(undefined4 *)(iVar1 + 0x2c0) = local_5c;
        *(undefined4 *)(iVar1 + 0x2c4) = local_58;
        FUN_004026e0(local_54,0,0xffffffff);
        *(undefined4 *)(iVar1 + 0x2e4) = local_38;
        *(undefined4 *)(iVar1 + 0x2e8) = local_34;
        *(undefined4 *)(iVar1 + 0x2f0) = local_2c;
        *(undefined4 *)(iVar1 + 0x2f4) = local_28;
        *(undefined4 *)(iVar1 + 0x2f8) = local_24;
        *(undefined4 *)(iVar1 + 0x2fc) = local_20;
        *(undefined4 *)(iVar1 + 0x300) = local_1c;
        local_8 = (uint)local_8._1_3_ << 8;
        if (7 < local_40) {
          FUN_0089120c(local_54[0]);
        }
      }
      local_14 = local_14 + 1;
    } while (local_14 < (uint)(*(int *)(param_1 + 0xf4) - *(int *)(param_1 + 0xf0) >> 2));
  }
  if (7 < in_stack_00000038) {
    FUN_0089120c(in_stack_00000024);
  }
  ExceptionList = local_10;
  return;
}

