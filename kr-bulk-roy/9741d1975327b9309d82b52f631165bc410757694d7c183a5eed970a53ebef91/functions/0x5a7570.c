
void FUN_005a7570(int param_1)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  undefined4 *puVar4;
  undefined4 uStack_58;
  undefined4 uStack_48;
  uint uStack_44;
  undefined4 uStack_38;
  undefined4 uStack_28;
  uint uStack_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f6dc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffff98);
    _atexit((_func_4879 *)&LAB_00bccc80);
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
  }
  local_c = 0xffffffff;
  DAT_00f9429c = 0xffff;
  if (DAT_00f93954 == 0) {
    (**(code **)(**(int **)(param_1 + 0x13c) + 0xd0))();
  }
  else {
    (**(code **)(**(int **)(param_1 + 0x13c) + 0xd0))();
    (**(code **)(**(int **)(param_1 + 0x140) + 0xd0))();
    uStack_38 = (uint)uStack_38._2_2_ << 0x10;
    uStack_24 = 7;
    uStack_28 = 0;
    psVar2 = &DAT_00f93958;
    do {
      psVar3 = psVar2;
      psVar2 = psVar3 + 1;
    } while (*psVar3 != 0);
    FUN_00402160(&DAT_00f93958,(int)(psVar3 + -0x7c9cac) >> 1);
    iVar1 = *(int *)(param_1 + 0x140);
    local_c = 2;
    FUN_00757800(&uStack_38);
    (**(code **)(**(int **)(iVar1 + 0xf0) + 200))();
    local_c = 0xffffffff;
    if (7 < uStack_24) {
      FUN_0089120c(uStack_38);
    }
    uStack_58 = (undefined4 *)((uint)uStack_58._2_2_ << 0x10);
    uStack_44 = 7;
    uStack_48 = 0;
    psVar2 = &DAT_00f939bc;
    do {
      psVar3 = psVar2;
      psVar2 = psVar3 + 1;
    } while (*psVar3 != 0);
    FUN_00402160(&DAT_00f939bc,(int)(psVar3 + -0x7c9cde) >> 1);
    iVar1 = *(int *)(param_1 + 0x140);
    local_c = 3;
    puVar4 = uStack_58;
    if (uStack_44 < 8) {
      puVar4 = &uStack_58;
    }
    FUN_00765f70(*(undefined4 *)(iVar1 + 0xf4),puVar4);
    (**(code **)(**(int **)(iVar1 + 0xf4) + 200))();
    local_c = 0xffffffff;
    if (7 < uStack_44) {
      FUN_0089120c(uStack_58);
    }
    uStack_44 = 7;
    uStack_48 = 0;
    uStack_58 = (undefined4 *)((uint)uStack_58 & 0xffff0000);
    FUN_005a83f0();
  }
  if ((*(uint *)(*(int *)(param_1 + 0x13c) + 0x28) >> 8 & 1) != 0) {
    (**(code **)(**(int **)(param_1 + 0x148) + 0xd4))();
    (**(code **)(**(int **)(param_1 + 0x14c) + 0xd4))();
  }
  ExceptionList = local_14;
  return;
}

