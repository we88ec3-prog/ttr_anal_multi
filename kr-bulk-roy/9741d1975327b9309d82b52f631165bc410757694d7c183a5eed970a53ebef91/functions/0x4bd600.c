
int FUN_004bd600(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  int local_24;
  uint uStack_20;
  int aiStack_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_00935cec;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  local_24 = 0;
  iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
  if (iVar2 != 0) {
    uVar1 = *(ushort *)(iVar2 + 4);
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      uStack_c = 0;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
      uStack_c = 0xffffffff;
    }
    uStack_20 = (uint)uVar1;
    FUN_0082ef00(&uStack_20);
    if (((aiStack_1c[0] != DAT_00fab13c) && (*(int *)(aiStack_1c[0] + 0x10) != 0)) &&
       (*(char *)(*(int *)(aiStack_1c[0] + 0x10) + 0xbc) != '\0')) {
      if ((DAT_00fab22c & 1) == 0) {
        DAT_00fab22c = DAT_00fab22c | 1;
        uStack_c = 1;
        FUN_004dec90();
        _atexit((_func_4879 *)&LAB_00bcce30);
        uStack_c = 0xffffffff;
      }
      aiStack_1c[0] = *(int *)(in_ECX + 0xbfa8);
      FUN_008438c0(aiStack_1c);
      if (uStack_20 == DAT_00fab14c) {
        ExceptionList = local_14;
        return 0;
      }
      if (*(int *)(uStack_20 + 0x10) == 0) {
        ExceptionList = local_14;
        return 0;
      }
      aiStack_1c[0] = *(int *)(*(int *)(uStack_20 + 0x10) + 4);
      iVar2 = FUN_0040f060();
      FUN_0082ef00(aiStack_1c);
      if (uStack_20 == *(uint *)(iVar2 + 0xc)) {
        ExceptionList = local_14;
        return 0;
      }
      iVar2 = *(int *)(uStack_20 + 0x10);
      if (iVar2 == 0) {
        ExceptionList = local_14;
        return 0;
      }
      *(uint *)(in_ECX + 0x5ee0) = (uint)*(ushort *)(iVar2 + 0x88);
      if ((*(int *)(iVar2 + 0x15c) != 0) && (*(int *)(iVar2 + 0x370) != 0)) {
        FUN_007a76b0(*(int *)(iVar2 + 0x15c));
      }
      *(undefined4 *)(in_ECX + 0x5ed0) = 1;
      ExceptionList = local_14;
      return 1;
    }
  }
  iVar4 = 0;
  iVar2 = in_ECX + 0x5ee8;
  do {
    iVar3 = (**(code **)(*DAT_00fba7a4 + 0x1c))(iVar4);
    if (iVar3 != 0) {
      *(uint *)(iVar2 + -8) = (uint)*(ushort *)(iVar3 + 0x88);
      if ((*(int *)(iVar3 + 0x15c) != 0) && (*(int *)(iVar3 + 0x370) != 0)) {
        FUN_007a76b0(*(int *)(iVar3 + 0x15c));
      }
      local_24 = local_24 + 1;
      *(undefined4 *)(iVar2 + -0x18) = 1;
    }
    iVar4 = iVar4 + 1;
    iVar2 = iVar2 + 0x38;
  } while (iVar4 < 3);
  ExceptionList = local_14;
  return local_24;
}

