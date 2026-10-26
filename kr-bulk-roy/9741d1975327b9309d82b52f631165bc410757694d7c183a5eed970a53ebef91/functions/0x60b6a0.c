
void FUN_0060b6a0(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int unaff_EDI;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d6fc;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (*(char *)(unaff_EDI + 0x248) == '\0') {
    iVar2 = *(int *)(unaff_EDI + 0x250);
    if (*(char *)(iVar2 + 0xa4) == '\0') {
      return;
    }
    if (*(int *)(iVar2 + 0x94) == 0) {
      return;
    }
    ExceptionList = &local_10;
    iVar5 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))();
    if (iVar5 != 0xbf6b) {
      ExceptionList = local_10;
      return;
    }
    iVar2 = *(int *)(iVar2 + 0x94);
    iVar5 = *(int *)(iVar2 + 0x10);
    if (iVar5 == 0) {
      ExceptionList = local_10;
      return;
    }
    piVar3 = *(int **)(iVar5 + 8);
    if (piVar3 != (int *)0x0) {
      piVar1 = piVar3 + 0x27;
      *piVar1 = *piVar1 + -1;
      if (*piVar1 == 0) {
        (**(code **)(*piVar3 + 0x28))();
      }
    }
    *(undefined4 *)(iVar2 + 0x10) = 0;
    ExceptionList = local_10;
    return;
  }
  ExceptionList = &local_10;
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 0;
    FUN_005c3de0(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc30);
  }
  iVar2 = DAT_00f943f0;
  local_8 = 0xffffffff;
  if (DAT_00f943f0 != 0) {
    local_14 = (uint)*(byte *)(unaff_EDI + 0x248) * 10000 + (uint)*(byte *)(unaff_EDI + 0x249);
    FUN_0082ef00(&local_14);
    if ((local_18 != *(int *)(iVar2 + 0xc)) && (*(int *)(local_18 + 0x10) != 0)) goto LAB_0060b7f3;
  }
  if ((DAT_00f94394 & 1) == 0) {
    DAT_00f94394 = DAT_00f94394 | 1;
    local_8 = 1;
    FUN_005c3de0(uVar4);
    _atexit((_func_4879 *)&LAB_00bccc30);
    local_8 = 0xffffffff;
  }
LAB_0060b7f3:
  FUN_00745060();
  ExceptionList = local_10;
  return;
}

