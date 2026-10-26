
void FUN_00808bd0(undefined4 param_1)

{
  char cVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  int unaff_EDI;
  uint in_stack_00000018;
  undefined4 in_stack_00000020;
  undefined1 local_40 [4];
  int local_3c;
  int local_38;
  uint local_34 [4];
  undefined4 local_24;
  uint local_20;
  undefined4 local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00914490;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  local_14 = uVar2;
  local_38 = FUN_00552550(&param_1);
  if ((local_38 == *(int *)(unaff_EDI + 0x20)) || (cVar1 = FUN_0049ae30(uVar2), cVar1 != '\0')) {
    local_3c = *(int *)(unaff_EDI + 0x20);
    piVar3 = &local_3c;
  }
  else {
    piVar3 = &local_38;
  }
  if (*piVar3 == *(int *)(unaff_EDI + 0x20)) {
    local_20 = 0xf;
    local_24 = 0;
    local_34[0] = local_34[0] & 0xffffff00;
    FUN_00403040(&param_1,0,0xffffffff);
    local_18 = in_stack_00000020;
    local_8 = CONCAT31(local_8._1_3_,1);
    uVar4 = FUN_00552de0(local_34);
    FUN_00552980(unaff_EDI + 0x1c,local_40,uVar4);
    if (0xf < local_20) {
      FUN_0089120c(local_34[0]);
    }
    if (0xf < in_stack_00000018) {
      FUN_0089120c(param_1);
    }
  }
  else if (0xf < in_stack_00000018) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

