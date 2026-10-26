
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00494a90(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009370f8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  _DAT_00fd2cec = 0;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_c = 0xffffffff;
  }
  if (DAT_00fb76e8 != 0) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    iVar2 = *(int *)(DAT_00fb76e8 + 0xa4);
    puVar1 = (undefined4 *)(DAT_00fb76e8 + 0xa4);
    if (*(int *)(DAT_00fb76e8 + 0xa0) != iVar2) {
      uVar3 = FUN_00798bb0(iVar2,iVar2,*(int *)(DAT_00fb76e8 + 0xa0),in_ECX);
      FUN_00798c00(in_ECX);
      *puVar1 = uVar3;
    }
  }
  if ((DAT_00fc18fc & 1) == 0) {
    DAT_00fc18fc = DAT_00fc18fc | 1;
    local_c = 2;
    FUN_005548f0();
    _atexit((_func_4879 *)&LAB_00bcdcd0);
    local_c = 0xffffffff;
  }
  if (DAT_00fc1984 != 0) {
    FUN_005558c0();
  }
  *(undefined4 *)(in_ECX + 0xbfd4) = 0;
  FUN_006df020();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 3;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004e0590();
  ExceptionList = local_14;
  return 0x100;
}

