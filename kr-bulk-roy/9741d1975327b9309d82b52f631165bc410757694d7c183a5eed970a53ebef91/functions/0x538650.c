
void FUN_00538650(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  int *unaff_ESI;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00908428;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_8 = 0;
  FUN_008438c0(&param_1);
  iVar2 = local_14;
  if (local_14 == *(int *)(in_ECX + 0x14)) {
    *unaff_ESI = 0;
    unaff_ESI[1] = 0;
    unaff_ESI[2] = 0;
    if (unaff_ESI != &local_24) {
      *unaff_ESI = 0;
      unaff_ESI[1] = 0;
      unaff_ESI[2] = 0;
    }
  }
  else {
    piVar4 = (int *)FUN_008438c0(&stack0x00000008);
    if (*piVar4 == *(int *)(*(int *)(iVar2 + 0x10) + 0x30)) {
      *unaff_ESI = 0;
      unaff_ESI[1] = 0;
      unaff_ESI[2] = 0;
      if (unaff_ESI != &local_24) {
        *unaff_ESI = 0;
        unaff_ESI[1] = 0;
        unaff_ESI[2] = 0;
      }
    }
    else {
      puVar1 = *(undefined4 **)(*(int *)(*piVar4 + 0x10) + 0x30);
      param_1 = (undefined4 *)*puVar1;
      while (param_1 != puVar1) {
        FUN_004a8680(uVar3);
        FUN_0049e6a0();
      }
      *unaff_ESI = 0;
      unaff_ESI[1] = 0;
      unaff_ESI[2] = 0;
      if (unaff_ESI == &local_24) {
        if (local_24 != 0) {
          FUN_0089120c(local_24);
        }
      }
      else {
        *unaff_ESI = local_24;
        unaff_ESI[1] = local_20;
        unaff_ESI[2] = local_1c;
      }
    }
  }
  ExceptionList = local_10;
  return;
}

