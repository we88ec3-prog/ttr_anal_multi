
undefined4 * FUN_004f7370(undefined4 param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_c;
  
  FUN_008438c0(&param_1);
  if (local_c == *(int *)(in_EAX + 0x124)) {
    FUN_004a8680();
    puVar1 = (undefined4 *)FUN_00891268(0x20);
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      puVar1[5] = 7;
      puVar1[4] = 0;
      *(undefined2 *)puVar1 = 0;
    }
    if ((uint)puVar1[4] < 0x14) {
      FUN_00440010(0x14 - puVar1[4],0);
    }
    else {
      FUN_00402400(0x14,0xffffffff);
    }
    FUN_004026e0(&DAT_00e2aa9c,0,0xffffffff);
    puVar1[7] = 0;
    uVar2 = FUN_0057ef20();
    FUN_0057e850(in_EAX + 0x120,uVar2);
    if (7 < (uint)puVar1[5]) {
      return (undefined4 *)*puVar1;
    }
  }
  else {
    puVar1 = *(undefined4 **)(local_c + 0x10);
    if (7 < (uint)puVar1[5]) {
      return (undefined4 *)*puVar1;
    }
  }
  return puVar1;
}

