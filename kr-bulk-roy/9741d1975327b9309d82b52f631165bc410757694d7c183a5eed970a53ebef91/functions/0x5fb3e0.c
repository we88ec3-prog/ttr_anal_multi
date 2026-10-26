
void FUN_005fb3e0(void)

{
  int *piVar1;
  code *pcVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 *puVar5;
  undefined1 auStack_5c [4];
  undefined4 uStack_58;
  undefined4 uStack_54;
  uint uStack_40;
  uint uStack_38;
  uint uStack_28;
  uint uStack_24;
  void *pvStack_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093ed70;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_5c;
  ExceptionList = &local_14;
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x104) + *(int *)(in_ECX + 0x118) * 4) + 0x19c))
            (DAT_00d61f20 ^ (uint)&stack0xffffff98);
  (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  FUN_00412df0();
  uStack_c = 1;
  FUN_00757710();
  uStack_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 2;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  FUN_00412df0();
  uStack_c = 3;
  FUN_00757710();
  uStack_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 4;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  FUN_00412df0();
  uStack_c = 5;
  FUN_00757710();
  uStack_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    uStack_c = 6;
    FUN_004dec90();
    _atexit((_func_4879 *)&LAB_00bcce30);
    uStack_c = 0xffffffff;
  }
  uVar3 = FUN_00412df0();
  uStack_c = 7;
  FUN_00757800(uVar3);
  uStack_c = 0xffffffff;
  if (7 < uStack_40) {
    FUN_0089120c(uStack_54);
  }
  piVar1 = (int *)**(undefined4 **)(in_ECX + 0x104);
  uStack_58 = (**(code **)(*piVar1 + 0x1a4))();
  (**(code **)(*piVar1 + 0x1a0))();
  uVar3 = FUN_0040e460(&DAT_00bf2bf8);
  uStack_c = 8;
  FUN_00757800(uVar3);
  uStack_c = 0xffffffff;
  if (7 < uStack_24) {
    FUN_0089120c(uStack_38);
  }
  uStack_38 = uStack_38 & 0xffff0000;
  uStack_24 = 7;
  uStack_28 = 0;
  (**(code **)(**(int **)(*(int *)(in_ECX + 0xf8) + 0xd8) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x134) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x130) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x138) + 200))();
  (**(code **)(**(int **)(in_ECX + 0x13c) + 200))();
  if (((*(int *)(*(int *)(in_ECX + 0xf8) + 0xcc) == 0) ||
      (*(int *)(*(int *)(in_ECX + 0xf8) + 0xd8) == 0)) || (iVar4 = FUN_005f55a0(), iVar4 != 1)) {
    pcVar2 = *(code **)(**(int **)(in_ECX + 0xfc) + 0x90);
    if (*(int *)(in_ECX + 0x140) == 0) {
      (*pcVar2)(1);
      (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(1);
      (**(code **)(**(int **)(in_ECX + 300) + 0x90))(1);
      puVar5 = (undefined4 *)(in_ECX + 0x170);
      iVar4 = 5;
      do {
        (**(code **)(*(int *)*puVar5 + 0x90))(1);
        puVar5 = puVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    else {
      (*pcVar2)(0);
      (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(0);
      (**(code **)(**(int **)(in_ECX + 300) + 0x90))(0);
      puVar5 = (undefined4 *)(in_ECX + 0x170);
      iVar4 = 5;
      do {
        (**(code **)(*(int *)*puVar5 + 0x90))(0);
        puVar5 = puVar5 + 1;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0xfc) + 0x90))(0);
    (**(code **)(**(int **)(in_ECX + 0x100) + 0x90))(0);
    (**(code **)(**(int **)(in_ECX + 300) + 0x90))(0);
    puVar5 = (undefined4 *)(in_ECX + 0x170);
    iVar4 = 5;
    do {
      (**(code **)(*(int *)*puVar5 + 0x90))(0);
      puVar5 = puVar5 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  ExceptionList = pvStack_20;
  __security_check_cookie(uStack_28 ^ (uint)&stack0xffffff98);
  return;
}

