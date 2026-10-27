
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c15c0(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094465d;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0;
    FUN_00560170(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_c = 0xffffffff;
  FUN_005624b0(0);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 1;
    FUN_00560170(uVar3);
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_00562250();
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090();
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (DAT_00fd2bb8 != 0) {
    _DAT_00fd2bc8 = DAT_00fd2bc0;
    _DAT_00fd2bc4 = DAT_00fd2bbc;
    if (DAT_00fd2cd0 != (int *)0x0) {
      (**(code **)(*DAT_00fd2cd0 + 8))();
      DAT_00fd2cd0 = (int *)0x0;
    }
    _DAT_00fd2cd4 = 0;
    _DAT_00fd2bcc = 1;
    _DAT_00fd2ce8 = 1;
  }
  (**(code **)(*DAT_00fba7a4 + 0x14))();
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 2;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004dfe90(&DAT_00fab130);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 3;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  DAT_00fab228 = 0;
  FUN_004e1070(&DAT_00fab148);
  FUN_004c0bd0(in_ECX);
  piVar4 = (int *)FUN_004c2880();
  iVar5 = *piVar4;
  FUN_004c0ec0(iVar5);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 4;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004df510(&DAT_00fab130,iVar5 + 60000);
  if ((*(int *)(DAT_00fba838 + 0x48) - *(int *)(DAT_00fba838 + 0x44) >> 2 != 0) &&
     (iVar5 = **(int **)(DAT_00fba838 + 0x44), iVar5 != 0)) {
    uVar1 = *(undefined4 *)(iVar5 + 0xc);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 5;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    iVar2 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0x18) = uVar1;
    *(undefined4 *)(iVar2 + 0xcc) = 0;
    uVar1 = *(undefined4 *)(iVar5 + 0x18);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_c = 6;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_c = 0xffffffff;
    }
    iVar5 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0x24) = uVar1;
    *(undefined4 *)(iVar5 + 0xcc) = 0;
  }
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 0) {
      FUN_00544f50();
      DAT_00fba7a4[1] = 1;
      ExceptionList = local_14;
      return 0;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  iVar5 = FUN_00891268(0xb4);
  local_c = 10;
  if (iVar5 == 0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_005471e0();
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
  DAT_00fba7a4[1] = 1;
  ExceptionList = local_14;
  return 0;
}

