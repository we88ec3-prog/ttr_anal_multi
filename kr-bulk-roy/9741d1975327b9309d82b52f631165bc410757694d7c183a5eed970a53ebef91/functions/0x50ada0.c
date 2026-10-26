
undefined4 FUN_0050ada0(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int *local_38;
  int local_30;
  int *local_28;
  int local_20;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092413e;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffb8;
  ExceptionList = &local_14;
  if (param_3 < 2) {
    uVar4 = 0;
  }
  else {
    uVar4 = (param_3 - 2) / 0x13;
  }
  if (uVar4 != 0) {
    puVar5 = (undefined4 *)(param_2 + 2);
    do {
      if (puVar5[2] == 0) {
        FUN_005093f0(param_1 + 0x50c0,*puVar5,puVar5[1]);
      }
      else {
        FUN_0050b070(puVar5);
      }
      puVar5 = (undefined4 *)((int)puVar5 + 0x13);
      uVar4 = uVar4 - 1;
    } while (uVar4 != 0);
  }
  FUN_004d8460(uVar1);
  FUN_00542210();
  if (((local_38 == (int *)0x0) || ((int *)*local_38 == (int *)0x0)) ||
     (puVar5 = *(undefined4 **)*local_38, puVar5 == (undefined4 *)0x0)) {
    uVar2 = 0;
  }
  else {
    uVar2 = *puVar5;
  }
  if (((local_28 == (int *)0x0) || ((int *)*local_28 == (int *)0x0)) ||
     (puVar5 = *(undefined4 **)*local_28, puVar5 == (undefined4 *)0x0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = *puVar5;
  }
  FUN_0050b610(uVar3,local_20,uVar2,local_30,local_30 - local_20,FUN_005094b0);
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  FUN_0058afa0(0xf1,0xf429f);
  ExceptionList = local_14;
  return 0;
}

