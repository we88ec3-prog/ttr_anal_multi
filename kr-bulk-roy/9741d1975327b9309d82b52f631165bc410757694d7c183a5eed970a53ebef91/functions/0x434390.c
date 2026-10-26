
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00434390(void)

{
  uint uVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00944548;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 0;
    FUN_00560170(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_8 = 0xffffffff;
  FUN_005624b0(0);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_8 = 1;
    FUN_00560170(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_8 = 0xffffffff;
  }
  FUN_00562250();
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 2;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  *(undefined4 *)(in_ECX + 0x5eac) = *(undefined4 *)(DAT_00fb76e8 + 0x24);
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  FUN_005449a0(&DAT_00fb79f0);
  *(undefined4 *)(in_ECX + 0x5eb0) = 1;
  FUN_006df020();
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 3;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  if (DAT_00faadec != 0x14) {
    _DAT_00faadf0 = 0x14;
    ExceptionList = local_10;
    return 0;
  }
  FUN_0058a9a0();
  ExceptionList = local_10;
  return 0;
}

