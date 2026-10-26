
undefined4 FUN_0079d8e0(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  int unaff_ESI;
  uint in_stack_0000001c;
  int local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090c5c8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_18 = FUN_007d0110(&param_2);
  if (local_18 != *(int *)(unaff_ESI + 0x14)) {
    cVar1 = FUN_0049ae30(uVar2);
    if (cVar1 == '\0') {
      piVar3 = &local_18;
      goto LAB_0079d93f;
    }
  }
  local_14 = *(int *)(unaff_ESI + 0x14);
  piVar3 = &local_14;
LAB_0079d93f:
  if (*piVar3 != *(int *)(unaff_ESI + 0x14)) {
    piVar3 = (int *)FUN_00515790(&param_1);
    if (*(int *)(unaff_ESI + 4) == *piVar3) {
      FUN_007a0c70();
      FUN_007a0da0();
      if (0xf < in_stack_0000001c) {
        FUN_0089120c(param_2);
      }
      ExceptionList = local_10;
      return 1;
    }
  }
  if (0xf < in_stack_0000001c) {
    FUN_0089120c(param_2);
  }
  ExceptionList = local_10;
  return 0;
}

