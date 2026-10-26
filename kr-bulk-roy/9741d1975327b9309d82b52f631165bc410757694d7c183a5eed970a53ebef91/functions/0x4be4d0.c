
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004be4d0(void)

{
  void *_Dst;
  int iVar1;
  uint uVar2;
  int *piVar3;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009446ed;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 0;
    FUN_00560170(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd110);
  }
  local_c = 0xffffffff;
  FUN_005624b0(0);
  if ((DAT_00fb73b8 & 1) == 0) {
    DAT_00fb73b8 = DAT_00fb73b8 | 1;
    local_c = 1;
    FUN_00560170(uVar2);
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
  iVar1 = DAT_00fab130;
  FUN_00797a00();
  _Dst = *(void **)(iVar1 + 0x5ee8);
  if (_Dst != *(void **)(iVar1 + 0x5eec)) {
    FID_conflict__memcpy(_Dst,*(void **)(iVar1 + 0x5eec),0);
    *(void **)(iVar1 + 0x5eec) = _Dst;
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 5;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    local_c = 0xffffffff;
  }
  if (DAT_00fba7a4 != (int *)0x0) {
    if (DAT_00fba7ac == 1) {
      FUN_00544f50();
      goto LAB_004be721;
    }
    (**(code **)(*DAT_00fba7a4 + 0x28))();
    if (DAT_00fba7a4 != (int *)0x0) {
      (**(code **)*DAT_00fba7a4)(1);
    }
  }
  piVar3 = (int *)FUN_00891268(0xb4);
  local_c = 6;
  if (piVar3 == (int *)0x0) {
    piVar3 = (int *)0x0;
  }
  else {
    FUN_00544c40(piVar3);
    *piVar3 = (int)CMissionRoomController::vftable;
    DAT_00fba7ac = 1;
  }
  local_c = 0xffffffff;
  DAT_00fba7a4 = piVar3;
  (**(code **)(*piVar3 + 0x24))();
LAB_004be721:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xd;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  if (DAT_00faadec == 9) {
    FUN_0058a9a0();
    ExceptionList = local_14;
    return 0;
  }
  _DAT_00faadf0 = 9;
  ExceptionList = local_14;
  return 0;
}

