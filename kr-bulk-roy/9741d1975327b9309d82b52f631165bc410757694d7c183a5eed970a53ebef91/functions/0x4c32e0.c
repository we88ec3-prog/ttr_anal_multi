
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c32e0(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009445cf;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (DAT_00fd2bb8 != 0) {
    _DAT_00fd2bc4 = 8;
    _DAT_00fd2bc8 = 0xf0;
    if (DAT_00fd2cd0 != (int *)0x0) {
      (**(code **)(*DAT_00fd2cd0 + 8))();
      DAT_00fd2cd0 = (int *)0x0;
    }
    _DAT_00fd2cd4 = 0;
    _DAT_00fd2bcc = 1;
    _DAT_00fd2ce8 = 1;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  DAT_00fab228 = 0;
  FUN_004e1070(&DAT_00fab148);
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 1;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004dfe90(&DAT_00fab130);
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 0) {
      FUN_00544f50();
      goto LAB_004c3462;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  iVar3 = FUN_00891268(0xb4);
  local_c = 5;
  if (iVar3 == 0) {
    DAT_00fba7a4 = (int *)0x0;
  }
  else {
    DAT_00fba7a4 = (int *)FUN_005471e0();
  }
  local_c = 0xffffffff;
  (**(code **)(*DAT_00fba7a4 + 0x24))();
LAB_004c3462:
  uVar1 = DAT_00fe1ac0 & 1;
  DAT_00fba7a4[1] = 0;
  if (uVar1 == 0) {
    DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
    local_c = 9;
    FUN_007bb970();
    _atexit((_func_4879 *)&LAB_00bceac0);
    local_c = 0xffffffff;
  }
  FUN_007bd4a0(3);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_c = 10;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
    local_c = 0xffffffff;
  }
  uVar2 = DAT_00fb906c;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0xb;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  FUN_004df510(&DAT_00fab130,uVar2);
  FUN_007b9300();
  if ((DAT_00fe1ac0 & 1) == 0) {
    DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
    local_c = 0xc;
    FUN_007bb970();
    _atexit((_func_4879 *)&LAB_00bceac0);
    local_c = 0xffffffff;
  }
  FUN_007bd4a0(2);
  if ((_DAT_00fd2b98 & 1) == 0) {
    _DAT_00fd2b98 = _DAT_00fd2b98 | 1;
    DAT_00fd2b9c = 0;
    DAT_00fd2ba0 = 0;
    DAT_00fd2ba4 = 0;
    _DAT_00fd2bac = 0;
  }
  DAT_00fd2ba8 = 1;
  _DAT_00fd2bb0 = 0xd2;
  FUN_006df020();
  ExceptionList = local_14;
  return 0;
}

