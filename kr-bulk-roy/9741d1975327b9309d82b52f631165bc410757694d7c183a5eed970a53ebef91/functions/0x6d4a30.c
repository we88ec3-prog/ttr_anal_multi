
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006d4a30(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009268f0;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((char)param_1 != '\0') {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 0;
      FUN_006d0750(uVar4);
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    _DAT_00fb9004 = 0;
    _DAT_00fb9008 = 0;
    _DAT_00fb900c = 0;
    _DAT_00fb9010 = 0;
    _DAT_00fb9014 = 0;
    _DAT_00fb9018 = 0;
    _DAT_00fb901c = 0;
    _DAT_00fb9020 = 0;
    _DAT_00fb9024 = 0;
    _DAT_00fb9028 = 0;
    if ((DAT_00fdf3ec & 1) == 0) {
      DAT_00fdf3ec = DAT_00fdf3ec | 1;
      local_8 = 1;
      FUN_006d1da0();
      _atexit((_func_4879 *)&LAB_00bce330);
    }
    local_8 = 0xffffffff;
    FUN_00823850();
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 2;
    FUN_006d0750(uVar4);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  if (DAT_00fb8830 != 0) {
    if ((DAT_00fb7c14 & 1) == 0) {
      DAT_00fb7c14 = DAT_00fb7c14 | 1;
      local_8 = 3;
      FUN_006d0750(uVar4);
      _atexit((_func_4879 *)&LAB_00bcd530);
    }
    _DAT_00fb9004 = 0;
    _DAT_00fb9008 = 0;
    _DAT_00fb900c = 0;
    _DAT_00fb9010 = 0;
    _DAT_00fb9014 = 0;
    _DAT_00fb9018 = 0;
    _DAT_00fb901c = 0;
    _DAT_00fb9020 = 0;
    _DAT_00fb9024 = 0;
    _DAT_00fb9028 = 0;
  }
  if ((DAT_00fb7c14 & 1) == 0) {
    DAT_00fb7c14 = DAT_00fb7c14 | 1;
    local_8 = 4;
    FUN_006d0750(uVar4);
    _atexit((_func_4879 *)&LAB_00bcd530);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb8830 != 0) {
    if ((DAT_00fdf3ec & 1) == 0) {
      DAT_00fdf3ec = DAT_00fdf3ec | 1;
      local_8 = 5;
      FUN_006d1da0();
      _atexit((_func_4879 *)&LAB_00bce330);
    }
    local_8 = 0xffffffff;
    FUN_00823850();
  }
  puVar1 = (undefined4 *)*param_2;
  for (puVar2 = (undefined4 *)*puVar1; puVar2 != puVar1; puVar2 = (undefined4 *)*puVar2) {
    iVar3 = puVar2[2];
    if (iVar3 - 0x2711U < 9999) {
      if ((DAT_00fdf3ec & 1) == 0) {
        DAT_00fdf3ec = DAT_00fdf3ec | 1;
        local_8 = 6;
        FUN_006d1da0();
        _atexit((_func_4879 *)&LAB_00bce330);
        local_8 = 0xffffffff;
      }
      param_1 = iVar3;
      FUN_0082ef00(&param_1);
      if (local_14 != DAT_00fdf634) {
        *(undefined1 *)(local_14 + 0x10) = 0;
      }
    }
    else {
      if ((DAT_00fb7c14 & 1) == 0) {
        DAT_00fb7c14 = DAT_00fb7c14 | 1;
        local_8 = 7;
        FUN_006d0750();
        _atexit((_func_4879 *)&LAB_00bcd530);
        local_8 = 0xffffffff;
      }
      (&DAT_00fb9004)[iVar3] = 0;
    }
  }
  ExceptionList = local_10;
  return;
}

