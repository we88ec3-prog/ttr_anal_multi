
void FUN_0060d960(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int unaff_EDI;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091d8fc;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(int *)(unaff_EDI + 0x15c) == -1) {
    iVar2 = *(int *)(unaff_EDI + 0x168);
    if (((*(char *)(iVar2 + 0xa4) != '\0') && (*(int *)(iVar2 + 0x94) != 0)) &&
       (iVar5 = (**(code **)(**(int **)(iVar2 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
      iVar2 = *(int *)(iVar2 + 0x94);
      iVar5 = *(int *)(iVar2 + 0x10);
      if (iVar5 != 0) {
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
    }
  }
  else {
    if ((DAT_00f94394 & 1) == 0) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 0;
      FUN_005c3de0(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc30);
    }
    iVar2 = DAT_00f943e8;
    local_8 = 0xffffffff;
    if ((((DAT_00f943e8 == 0) ||
         (local_14 = *(undefined4 *)(unaff_EDI + 0x15c), FUN_0082ef00(&local_14),
         local_18 == *(int *)(iVar2 + 0xc))) || (*(int *)(local_18 + 0x10) == 0)) &&
       ((DAT_00f94394 & 1) == 0)) {
      DAT_00f94394 = DAT_00f94394 | 1;
      local_8 = 1;
      FUN_005c3de0(uVar4);
      _atexit((_func_4879 *)&LAB_00bccc30);
      local_8 = 0xffffffff;
    }
    FUN_00745060();
  }
  ExceptionList = local_10;
  return;
}

