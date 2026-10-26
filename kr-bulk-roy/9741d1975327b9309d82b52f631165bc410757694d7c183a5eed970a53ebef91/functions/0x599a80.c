
void FUN_00599a80(void)

{
  code *pcVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  void *pvStack_18;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093f80e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  (**(code **)(**(int **)(unaff_ESI + 0x168) + 0x1b4))(DAT_00d61f20 ^ (uint)&pvStack_18);
  (**(code **)(**(int **)(unaff_ESI + 0x168) + 0x1b0))();
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    uStack_c = 0;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    uStack_c = 0xffffffff;
  }
  iVar3 = *(int *)(DAT_00f94300 + 0x2398);
  iVar4 = 0;
  if (0 < iVar3) {
    piVar2 = (int *)(DAT_00f94300 + 0x1720);
    do {
      if ((piVar2[1] == 0) && (*piVar2 == 0)) {
        iVar4 = iVar4 + 1;
      }
      piVar2 = piVar2 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  pcVar1 = *(code **)(**(int **)(*(int *)(unaff_ESI + 0x164) + 0x100) + 0x98);
  if (iVar4 == 0) {
    (*pcVar1)(1);
    ExceptionList = pvStack_18;
    return;
  }
  (*pcVar1)(0);
  ExceptionList = pvStack_18;
  return;
}

