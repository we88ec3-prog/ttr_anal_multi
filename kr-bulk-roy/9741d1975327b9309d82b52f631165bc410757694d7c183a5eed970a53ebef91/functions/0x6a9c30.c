
undefined4 FUN_006a9c30(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093b6dc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fbad10 & 1) == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_8 = 0;
    FUN_004e8010(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  uVar3 = DAT_00fc0bc8 - DAT_00fc0bc4 >> 2;
  uVar2 = 0;
  if (uVar3 != 0) {
    do {
      iVar1 = *(int *)(DAT_00fc0bc4 + uVar2 * 4);
      if (*(int *)(iVar1 + 4) == param_2) {
        if (iVar1 == 0) {
          ExceptionList = local_10;
          return 0;
        }
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_8 = 1;
          FUN_004f3d80();
          _atexit((_func_4879 *)&LAB_00bcd1e0);
        }
        local_8 = 0xffffffff;
        FUN_004f6a30(param_2);
        FUN_00757710();
        (**(code **)(**(int **)(param_1 + 0xf4) + 0xa0))(*(byte *)(iVar1 + 0x14) & 1);
        (**(code **)(**(int **)(param_1 + 0xf8) + 0xa0))(*(byte *)(iVar1 + 0x14) >> 1 & 1);
        (**(code **)(**(int **)(param_1 + 0xfc) + 0xa0))(*(byte *)(iVar1 + 0x14) >> 2 & 1);
        *(int *)(param_1 + 0x108) = param_2;
        ExceptionList = local_10;
        return 1;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < uVar3);
  }
  ExceptionList = local_10;
  return 0;
}

