
void FUN_005b6fa0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_ESI;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d77c;
  local_14 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xffffffe0;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(uVar1);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if (DAT_00f94388 != 0x17) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 1;
      FUN_004e1590(uVar1);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if (DAT_00f94388 != 0x18) {
      iVar2 = FUN_00404ba0();
      if (*(int *)(iVar2 + 0x69a8) != 7) {
        ExceptionList = local_14;
        return;
      }
      piVar4 = *(int **)(unaff_ESI + 0x228);
      if ((piVar4[10] & 0x100U) == 0) {
        FUN_00596e00(unaff_ESI,piVar4);
        if ((*(uint *)(*(int *)(unaff_ESI + 0x228) + 0x28) & 0x100) == 0) {
          ExceptionList = local_14;
          return;
        }
        FUN_005a55e0(2);
        FUN_005a5760(unaff_ESI);
        FUN_005a57a0();
        ExceptionList = local_14;
        return;
      }
      if ((piVar4[10] & 0x100U) != 0) {
        (**(code **)(*piVar4 + 0xd4))();
      }
      FUN_005a55e0(1);
      ExceptionList = local_14;
      return;
    }
  }
  local_c = 0xffffffff;
  piVar4 = *(int **)(unaff_ESI + 0x22c);
  if ((piVar4[10] & 0x100U) != 0) {
    if ((piVar4[10] & 0x100U) != 0) {
      (**(code **)(*piVar4 + 0xd4))();
    }
    FUN_005a55e0(1);
    ExceptionList = local_14;
    return;
  }
  FUN_00596e00(unaff_ESI,piVar4);
  if ((*(uint *)(*(int *)(unaff_ESI + 0x22c) + 0x28) & 0x100) == 0) {
    ExceptionList = local_14;
    return;
  }
  FUN_005a55e0(2);
  if (*(int *)(unaff_ESI + 0x158) == 1) {
    iVar2 = *(int *)(unaff_ESI + 0x140);
  }
  else {
    if (*(int *)(unaff_ESI + 0x158) != 2) goto LAB_005b7185;
    iVar2 = *(int *)(unaff_ESI + 0x148);
  }
  iVar3 = 0x19 - *(int *)(iVar2 + 8);
  *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + iVar3;
  *(int *)(iVar2 + 0x10) = *(int *)(iVar2 + 0x10) + iVar3;
  iVar3 = 0x37 - *(int *)(iVar2 + 0xc);
  *(int *)(iVar2 + 0xc) = *(int *)(iVar2 + 0xc) + iVar3;
  *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + iVar3;
  FUN_00746f70();
LAB_005b7185:
  if (*(int *)(unaff_ESI + 0x158) == 1) {
    piVar4 = *(int **)(unaff_ESI + 0x140);
  }
  else {
    if (*(int *)(unaff_ESI + 0x158) != 2) {
      ExceptionList = local_14;
      return;
    }
    piVar4 = *(int **)(unaff_ESI + 0x148);
  }
  (**(code **)(*piVar4 + 0xb4))(0xc9);
  ExceptionList = local_14;
  return;
}

