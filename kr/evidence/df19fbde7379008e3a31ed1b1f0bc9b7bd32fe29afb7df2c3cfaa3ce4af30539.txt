
/* WARNING: Removing unreachable block (ram,0x004bcd6b) */
/* WARNING: Removing unreachable block (ram,0x004bcd70) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004bcba0(void)

{
  int *piVar1;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_009447fd;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((_DAT_00fd2cf0 & 1) == 0) {
    _DAT_00fd2cf0 = _DAT_00fd2cf0 | 1;
    FUN_00738090(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&DAT_00bce680);
  }
  if (DAT_00fd2bb8 != 0) {
    _DAT_00fd2bc4 = 1;
    _DAT_00fd2bc8 = 200;
    if (DAT_00fd2cd0 != (int *)0x0) {
      (**(code **)(*DAT_00fd2cd0 + 8))();
      DAT_00fd2cd0 = (int *)0x0;
    }
    _DAT_00fd2cd4 = 0;
    _DAT_00fd2bcc = 1;
    _DAT_00fd2ce8 = 1;
  }
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_005624b0(0);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 1;
    FUN_00560170();
    _atexit((_func_4879 *)&LAB_00bcd110);
    local_c = 0xffffffff;
  }
  FUN_00562250();
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
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 4;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if (*(int *)(DAT_00fab130 + 0x5ed8) != *(int *)(DAT_00fab130 + 0x5edc)) {
    *(int *)(DAT_00fab130 + 0x5edc) = *(int *)(DAT_00fab130 + 0x5ed8);
  }
  if ((DAT_00fe18c8 & 1) == 0) {
    DAT_00fe18c8 = DAT_00fe18c8 | 1;
    local_c = 5;
    FUN_0053f970();
    _atexit((_func_4879 *)&LAB_00bce810);
    local_c = 0xffffffff;
  }
  if (DAT_00fe18cc != DAT_00fe18d0) {
    DAT_00fe18d0 = DAT_00fe18cc;
  }
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 1) {
      FUN_00544f50();
      goto LAB_004bce47;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  piVar1 = (int *)FUN_00891268(0xb4);
  local_c = 6;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    FUN_00544c40(piVar1);
    *piVar1 = (int)CMissionRoomController::vftable;
    DAT_00fba7ac = 1;
  }
  local_c = 0xffffffff;
  DAT_00fba7a4 = piVar1;
  (**(code **)(*piVar1 + 0x24))();
LAB_004bce47:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xd;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 4) {
    FUN_0058a9a0();
  }
  else {
    _DAT_00faadf0 = 4;
  }
  FUN_0054c410(&DAT_00fbaaf8);
  ExceptionList = local_14;
  return 0;
}

