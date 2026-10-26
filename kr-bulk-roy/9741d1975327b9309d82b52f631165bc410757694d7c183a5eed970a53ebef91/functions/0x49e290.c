
/* WARNING: Removing unreachable block (ram,0x0049e469) */
/* WARNING: Removing unreachable block (ram,0x0049e475) */
/* WARNING: Removing unreachable block (ram,0x0049e472) */

int FUN_0049e290(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009222da;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar5 = 0;
  local_14 = 0;
  iVar4 = 0;
  puVar3 = param_1;
  if ((int)(param_1[2] - param_1[1]) / 0x24 != 0) {
    do {
      iVar4 = param_1[1];
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        local_8 = 0;
        FUN_00734ef0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        local_8 = 0xffffffff;
      }
      FUN_00735ba0((int)*(float *)(iVar5 + iVar4) + -1,(int)((float *)(iVar5 + iVar4))[1] + -1,1,
                   0xff000000,0xff000000);
      iVar4 = param_1[1];
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        local_8 = 1;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        local_8 = 0xffffffff;
      }
      FUN_00735ba0((int)*(float *)(iVar5 + iVar4) + 1,(int)((float *)(iVar5 + iVar4))[1] + 1,1,
                   0xff000000,0xff000000);
      puVar3 = (undefined4 *)(param_1[1] + iVar5 + 8);
      if (7 < *(uint *)(param_1[1] + iVar5 + 0x1c)) {
        puVar3 = (undefined4 *)*puVar3;
      }
      iVar4 = param_1[1];
      if ((DAT_00fb7bc8 & 1) == 0) {
        DAT_00fb7bc8 = DAT_00fb7bc8 | 1;
        local_8 = 2;
        FUN_00734ef0();
        _atexit((_func_4879 *)&LAB_00bcd4f0);
        local_8 = 0xffffffff;
      }
      FUN_00735ba0((int)*(float *)(iVar5 + iVar4),(int)((float *)(iVar5 + iVar4))[1],1,0xffffffff,
                   0xff000000);
      iVar4 = (param_1[2] - param_1[1]) * 0x38e38e39;
      local_14 = local_14 + 1;
      iVar5 = iVar5 + 0x24;
    } while (local_14 < (uint)((int)(param_1[2] - param_1[1]) / 0x24));
  }
  param_1 = puVar3;
  iVar5 = puVar1[1];
  if (iVar5 != puVar1[2]) {
    iVar4 = FUN_0049ad50(param_1);
    puVar1[2] = iVar5;
  }
  ExceptionList = local_10;
  return iVar4;
}

