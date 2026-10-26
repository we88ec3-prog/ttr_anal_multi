
/* WARNING: Removing unreachable block (ram,0x004c5b40) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004c59d0(void)

{
  uint uVar1;
  int *piVar2;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0094580f;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0;
    FUN_00560170(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_c = 0xffffffff;
  FUN_005624b0(0);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 1;
    FUN_00560170(uVar1);
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
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 1) {
      FUN_00544f50();
      goto LAB_004c5bd7;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  piVar2 = (int *)FUN_00891268(0xb4);
  local_c = 5;
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    FUN_00544c40(piVar2);
    *piVar2 = (int)CMissionRoomController::vftable;
    DAT_00fba7ac = 1;
  }
  local_c = 0xffffffff;
  DAT_00fba7a4 = piVar2;
  (**(code **)(*piVar2 + 0x24))();
LAB_004c5bd7:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xc;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 0xd) {
    FUN_0058a9a0();
    ExceptionList = local_14;
    return 0;
  }
  _DAT_00faadf0 = 0xd;
  ExceptionList = local_14;
  return 0;
}

