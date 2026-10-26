
/* WARNING: Removing unreachable block (ram,0x004e2562) */
/* WARNING: Removing unreachable block (ram,0x004e2576) */

undefined4 FUN_004e2440(byte *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_14 = ExceptionList;
  local_c = 0xffffffff;
  puStack_10 = &LAB_00924abe;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffffc8;
  ExceptionList = &local_14;
  if (param_2 < 6) {
    local_2c = 0;
  }
  else {
    local_2c = (param_2 - 6) / 6;
  }
  local_28 = *(int **)(*(int *)(in_ECX + 0x6920) + 0x50f0);
  iVar2 = *(int *)(param_1 + 2);
  if (iVar2 == 0) {
    if (*(int *)(in_ECX + 0x6998) != *(int *)(in_ECX + 0x699c)) {
      *(int *)(in_ECX + 0x699c) = *(int *)(in_ECX + 0x6998);
    }
    for (local_2c = local_2c & 0xffff; local_2c != 0; local_2c = local_2c - 1) {
      FUN_004e71d0(uVar4);
    }
  }
  else if (iVar2 == 1) {
    local_2c = local_2c & 0xffff;
    if (local_2c != 0) {
      param_1 = param_1 + 7;
      do {
        bVar1 = param_1[-1];
        iVar2 = *(int *)(in_ECX + 0x6998);
        local_20._0_2_ = CONCAT11(param_1[4],bVar1);
        uVar3 = *(undefined4 *)param_1;
        *(undefined4 *)(iVar2 + -8 + (uint)bVar1 * 8) = local_20;
        *(undefined4 *)(iVar2 + -4 + (uint)bVar1 * 8) = uVar3;
        if (local_28 != (int *)0x0) {
          (**(code **)(*local_28 + 8))(uVar3,1);
        }
        param_1 = param_1 + 6;
        local_2c = local_2c - 1;
      } while (local_2c != 0);
    }
  }
  else if (iVar2 == 2) {
    for (local_2c = local_2c & 0xffff; local_2c != 0; local_2c = local_2c - 1) {
      param_1 = param_1 + 6;
      bVar1 = *param_1;
      iVar2 = *(int *)(in_ECX + 0x6998);
      uVar4 = (uint)local_28 >> 0x10;
      local_28._2_2_ = (undefined2)uVar4;
      local_28._0_2_ = (ushort)bVar1;
      *(int **)(iVar2 + -8 + (uint)bVar1 * 8) = local_28;
      *(undefined4 *)(iVar2 + -4 + (uint)bVar1 * 8) = 0;
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058aad0(0xf4365);
  ExceptionList = local_14;
  return 0;
}

