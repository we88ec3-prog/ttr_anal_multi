
undefined4 FUN_0050ac70(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint in_ECX;
  uint uVar4;
  int *local_28;
  int local_20;
  int *local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092416e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007b6d70(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (in_ECX < 2) {
    uVar4 = 0;
  }
  else {
    uVar4 = (in_ECX - 2) / 0x13;
  }
  if (uVar4 != 0) {
    param_1 = param_1 + 2;
    do {
      FUN_0050b070(param_1);
      param_1 = param_1 + 0x13;
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  FUN_004d8460();
  FUN_00542210();
  if (((local_1c == (int *)0x0) || ((int *)*local_1c == (int *)0x0)) ||
     (puVar1 = *(undefined4 **)*local_1c, puVar1 == (undefined4 *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *puVar1;
  }
  if (((local_28 == (int *)0x0) || ((int *)*local_28 == (int *)0x0)) ||
     (puVar1 = *(undefined4 **)*local_28, puVar1 == (undefined4 *)0x0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *puVar1;
  }
  FUN_0050b610(uVar3,local_20,uVar2,local_14,local_14 - local_20,FUN_005094b0);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058afa0(0xf1,0xf429f);
  ExceptionList = local_10;
  return 0;
}

