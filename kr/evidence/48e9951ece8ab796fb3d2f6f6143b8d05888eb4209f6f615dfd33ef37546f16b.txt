
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004b2af0(undefined1 *param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int local_20 [3];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00929f3b;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd0;
  ExceptionList = &local_14;
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = (int *)0x0;
    DAT_00fb79f8 = (int *)0x0;
    DAT_00fb79fc = (int *)0x0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  FUN_005449a0(&DAT_00fb79f0);
  if (param_2 < 2) {
    local_20[1] = 0;
  }
  else {
    local_20[1] = (param_2 - 2) / 0x12;
  }
  for (; local_20[1] != 0; local_20[1] = local_20[1] - 1) {
    local_20[0] = FUN_00891268(0x108,uVar1);
    local_c = 0;
    if (local_20[0] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = FUN_00543700(local_20[0],(short)(char)param_1[4],*(undefined2 *)(param_1 + 2),
                           *(undefined4 *)(param_1 + 0xe),param_1[5],param_1[0x12],param_1[0x13]);
    }
    local_c = 0xffffffff;
    if ((_DAT_00fb79ec & 1) == 0) {
      _DAT_00fb79ec = _DAT_00fb79ec | 1;
      DAT_00fb79f0 = CCheckPointMgr::vftable;
      DAT_00fb79f4 = (int *)0x0;
      DAT_00fb79f8 = (int *)0x0;
      DAT_00fb79fc = (int *)0x0;
      DAT_00fb7a04 = 1;
      _atexit((_func_4879 *)&LAB_00bcd270);
    }
    local_20[0] = iVar2;
    if ((local_20 < DAT_00fb79f8) && (DAT_00fb79f4 <= local_20)) {
      iVar2 = (int)local_20 - (int)DAT_00fb79f4;
      if (DAT_00fb79f8 == DAT_00fb79fc) {
        FUN_004deab0();
      }
      if (DAT_00fb79f8 != (int *)0x0) {
        *DAT_00fb79f8 = DAT_00fb79f4[iVar2 >> 2];
      }
    }
    else {
      if (DAT_00fb79f8 == DAT_00fb79fc) {
        FUN_004deab0();
      }
      if (DAT_00fb79f8 != (int *)0x0) {
        *DAT_00fb79f8 = iVar2;
      }
    }
    DAT_00fb79f8 = DAT_00fb79f8 + 1;
    param_1 = param_1 + 0x12;
  }
  ExceptionList = local_14;
  return 0;
}

