
void FUN_0065d9a0(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_38 [4];
  undefined4 local_28;
  uint local_24;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009462e6;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  local_24 = 7;
  local_28 = 0;
  local_38[0] = local_38[0] & 0xffff0000;
  FUN_00402160(&DAT_00bed1fc,0);
  iVar4 = *(int *)(param_1 + 0xf8);
  local_c = 0;
  FUN_007578f0(uVar1);
  FUN_00759ed0(iVar4 + 0xe8,local_38,0x7b,0x7d);
  local_c = 0xffffffff;
  if (7 < local_24) {
    FUN_0089120c(local_38[0]);
  }
  local_28 = 0;
  local_24 = 7;
  local_38[0] = local_38[0] & 0xffff0000;
  if (*(uint *)(param_1 + 0x16c) == param_2) {
    ExceptionList = local_14;
    return;
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  if (param_2 < 10) {
    iVar4 = param_2 * 0x210;
    if (((*(int *)(iVar4 + 0x5c + DAT_00f94304) != 0) && (iVar4 + DAT_00f94304 != 0)) &&
       (*(int *)(iVar4 + DAT_00f94304 + 0x5c) != 0)) {
      iVar2 = FUN_00404ba0();
      uVar3 = 0xffffffff;
      if (99 < *(int *)((-(uint)(*(int *)(*(int *)(iVar2 + 0x6924) + 0x5c + iVar4) != 0) &
                        *(int *)(iVar2 + 0x6924) + iVar4) + 0xdc)) {
        uVar3 = 0xffff5100;
      }
      *(undefined4 *)(*(int *)(param_1 + 0xf8) + 0x154) = uVar3;
      FUN_00757710();
      FUN_00759ac0(0);
      FUN_007597b0(1);
      (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
      goto LAB_0065db66;
    }
  }
  FUN_0065def0(param_1);
  (**(code **)(**(int **)(param_1 + 0xf8) + 200))();
LAB_0065db66:
  *(uint *)(param_1 + 0x16c) = param_2;
  ExceptionList = local_14;
  return;
}

