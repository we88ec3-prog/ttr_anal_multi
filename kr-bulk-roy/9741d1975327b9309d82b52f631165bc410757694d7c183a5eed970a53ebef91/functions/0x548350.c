
undefined4 FUN_00548350(void)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 uVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094787e;
  local_10 = ExceptionList;
  if (*(int *)(in_ECX + 4) == 0) {
    return 0;
  }
  ExceptionList = &local_10;
  uVar1 = FUN_005452c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (*(int *)(in_ECX + 0xc) == 0) {
    ExceptionList = local_10;
    return 0;
  }
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_8 = 0;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_8 = 0xffffffff;
  }
  if (DAT_00fb7258 == 0) {
    ExceptionList = local_10;
    return 0;
  }
  iVar2 = FUN_00443dc0();
  if ((*(int *)(iVar2 + 0x20) == 0) || (*(char *)(iVar2 + 0x17d) == '\0')) {
    uVar5 = 0x9d;
    FUN_00443dc0(0x9d);
    iVar2 = FUN_006f1b90(uVar5);
    if (iVar2 == 0) goto LAB_0054848c;
  }
  iVar2 = FUN_00443dc0();
  if ((*(int *)(iVar2 + 0x20) != 0) && (*(char *)(iVar2 + 0x199) == '\x01')) {
    iVar2 = FUN_00404ba0();
    iVar2 = *(int *)(iVar2 + 0x5f4c);
    piVar3 = (int *)FUN_00444960();
    if ((*piVar3 == 0) && ((((iVar2 == 3 || (iVar2 == 8)) || (iVar2 == 0x1b)) || (iVar2 == 5)))) {
      puVar4 = (undefined4 *)FUN_00891268(0x14);
      if (puVar4 != (undefined4 *)0x0) {
        *puVar4 = FoxUI::FXUIEvent::vftable;
        puVar4[1] = 0xffffffff;
        puVar4[2] = 0xffffffff;
        puVar4[3] = 0;
        puVar4[4] = 0xf439e;
      }
      FUN_00404aa0();
      FUN_00750020();
    }
  }
LAB_0054848c:
  iVar2 = FUN_00404ba0();
  if ((*(int *)(iVar2 + 0x5f4c) == 3) || (iVar2 = FUN_00404ba0(), *(int *)(iVar2 + 0x5f4c) == 8)) {
    iVar2 = FUN_00404ba0();
    iVar2 = FUN_00539aa0(*(undefined4 *)(iVar2 + 0x5f50));
    if ((iVar2 != 0) && ((*(char *)(iVar2 + 6) == '\0' && (*(char *)(iVar2 + 8) != '\0')))) {
      ExceptionList = local_10;
      return 0;
    }
  }
  iVar2 = FUN_00444960();
  if (*(char *)(iVar2 + 0x7e1) == '\x01') {
    uVar5 = 1;
    FUN_00434250(1);
    iVar2 = FUN_00544a00(uVar5);
    if (iVar2 == 0) {
      uVar5 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x4c))();
      FUN_0048a360(uVar5);
      FUN_004fdcd0(uVar5);
      ExceptionList = local_10;
      return uVar1;
    }
  }
  else {
    uVar5 = 0;
    FUN_00434250(0);
    FUN_00544a00(uVar5);
  }
  ExceptionList = local_10;
  return uVar1;
}

