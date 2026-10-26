
void FUN_006b18d0(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009358ea;
  local_14 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xffffffd8;
  ExceptionList = &local_14;
  iVar3 = *(int *)(*(int *)(param_1 + 0xfc) + 0xcc);
  if (iVar3 == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar3 = *(int *)(iVar3 + 0xdc);
    if (iVar3 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      uVar6 = *(undefined4 *)(iVar3 + 0x20);
    }
  }
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(uVar2);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  if ((DAT_00fe17b8 & 1) == 0) {
    DAT_00fe17b8 = DAT_00fe17b8 | 1;
    local_c = 1;
    FUN_0050caf0();
    _atexit((_func_4879 *)&LAB_00bce7e0);
  }
  local_c = 0xffffffff;
  iVar3 = FUN_0050d8b0(uVar6);
  if (iVar3 != 0) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 2;
      FUN_004dec90(uVar2);
      _atexit((_func_4879 *)&LAB_00bcce30);
      local_c = 0xffffffff;
    }
    iVar1 = *(int *)(DAT_00fab130 + 0x5eac);
    uVar2 = 0;
    piVar5 = (int *)(param_1 + 0x124);
    do {
      if ((*(uint *)(*piVar5 + 0x28) >> 9 & 1) != 0) goto LAB_006b1a20;
      uVar2 = uVar2 + 1;
      piVar5 = piVar5 + 1;
    } while (uVar2 < 4);
    uVar2 = 4;
LAB_006b1a20:
    if (uVar2 < (uint)(*(int *)(iVar3 + 0x48) - *(int *)(iVar3 + 0x44) >> 2)) {
      iVar4 = FUN_0040f060();
      if (((*(int *)(iVar4 + 0xf8) != 0) && (*(char *)(*(int *)(iVar4 + 0xf8) + 0x28) != '\0')) &&
         (iVar3 = **(int **)(*(int *)(iVar3 + 0x44) + uVar2 * 4), iVar1 != iVar3)) {
        FUN_0040f060();
        FUN_004dd9b0(iVar3);
      }
      ExceptionList = local_14;
      return;
    }
  }
  FUN_006edb60(&DAT_00c3cf4c);
  ExceptionList = local_14;
  return;
}

