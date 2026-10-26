
void FUN_00405b20(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00927e56;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faaf34 & 1) == 0) {
    DAT_00faaf34 = DAT_00faaf34 | 1;
    local_8 = 0;
    FUN_004073c0(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccd0);
  }
  if (DAT_00faaf44 != '\0') {
    if ((DAT_00faaf34 & 1) == 0) {
      DAT_00faaf34 = DAT_00faaf34 | 1;
      local_8 = 1;
      FUN_004073c0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcccd0);
    }
    uVar1 = DAT_00faaf3c;
    if ((DAT_00faaf34 & 1) == 0) {
      DAT_00faaf34 = DAT_00faaf34 | 1;
      local_8 = 2;
      FUN_004073c0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcccd0);
    }
    if (*(char *)(param_1 + 0xf4) != DAT_00faaf38) {
      if ((DAT_00faaf34 & 1) == 0) {
        DAT_00faaf34 = DAT_00faaf34 | 1;
        local_8 = 3;
        FUN_004073c0(uVar2);
        _atexit((_func_4879 *)&LAB_00bcccd0);
      }
      *(char *)(param_1 + 0xf4) = DAT_00faaf38;
    }
    iVar3 = 1;
    uVar4 = 2;
    do {
      *(bool *)(param_1 + 0x254 + iVar3) =
           (uVar1 & (uVar4 >> 1 | (uint)((uVar4 & 1) != 0) << 0x1f)) != 0;
      iVar3 = iVar3 + 1;
      uVar4 = uVar4 << 1 | (uint)((int)uVar4 < 0);
    } while (iVar3 < 0x1d);
    if ((DAT_00faaf34 & 1) == 0) {
      DAT_00faaf34 = DAT_00faaf34 | 1;
      local_8 = 4;
      FUN_004073c0(uVar2);
      _atexit((_func_4879 *)&LAB_00bcccd0);
    }
    DAT_00faaf44 = '\0';
  }
  ExceptionList = local_10;
  return;
}

