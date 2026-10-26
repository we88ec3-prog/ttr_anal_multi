
void FUN_005a67d0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0094a148;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) == 0xf42a3) {
    FUN_00597a30();
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4245:
    iVar1 = FUN_0040afc0();
    FUN_00672570();
    if (*(int *)(iVar1 + 0x14) == 1) {
      FUN_005f4910();
      FUN_005f4950();
      *(undefined4 *)(in_ECX + 0x144) = 1;
      ExceptionList = local_10;
      return;
    }
    break;
  case 0xf4246:
    FUN_0040afc0();
    FUN_00672f00();
    (**(code **)(**(int **)(in_ECX + 0x138) + 0xd0))();
    ExceptionList = local_10;
    return;
  case 0xf4247:
    (**(code **)(**(int **)(in_ECX + 0x138) + 0xd4))();
    ExceptionList = local_10;
    return;
  case 0xf4248:
    FUN_005a64b0();
    break;
  case 0xf4278:
    iVar1 = FUN_0040afc0();
    if (*(int *)(iVar1 + 0x14) == 0) {
      FUN_00672f00();
      (**(code **)(**(int **)(in_ECX + 0x13c) + 0xd4))();
      FUN_004054c0();
      FUN_00402250();
      local_8 = 0;
      FUN_005854b0();
      uVar2 = FUN_00585330();
      FUN_00402250(uVar2);
      local_8 = 0xffffffff;
      FUN_0058b270(0xca);
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}

