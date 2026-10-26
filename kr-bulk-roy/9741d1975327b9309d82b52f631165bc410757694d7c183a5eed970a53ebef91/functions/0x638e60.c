
void FUN_00638e60(undefined4 param_1,undefined4 param_2)

{
  uint3 uVar5;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  code *pcVar6;
  bool bVar7;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 uStack_c;
  
  uStack_c = 0xffffffff;
  puStack_10 = &LAB_0093dcdc;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if (*(int *)(in_ECX + 4) != 0) {
    local_1c = (void *)CONCAT31(local_1c._1_3_,*(undefined1 *)(*(int *)(in_ECX + 4) + 0xb4));
    (**(code **)(**(int **)(in_ECX + 0x14) + 0x94))(local_1c,DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    (**(code **)(**(int **)(in_ECX + 0x18) + 0x94))(*(undefined1 *)(*(int *)(in_ECX + 4) + 0xb5));
    uVar5 = (uint3)((uint)*(int *)(in_ECX + 0x1c) >> 8);
    if (((*(uint *)(*(int *)(in_ECX + 0x1c) + 0x28) >> 8 & 1) == 0) ||
       (*(char *)(*(int *)(in_ECX + 4) + 0x8c) == '\0')) {
      iVar1 = (uint)uVar5 << 8;
    }
    else {
      iVar1 = CONCAT31(uVar5,1);
    }
    (**(code **)(**(int **)(in_ECX + 0x1c) + 0x94))(iVar1);
  }
  (**(code **)(**(int **)(in_ECX + 0xc) + 0x94))(param_1);
  (**(code **)(**(int **)(in_ECX + 0x10) + 0x94))(param_2);
  if (*(char *)(in_ECX + 0x17c) == '\a') {
    if ((DAT_00fbad10 & 1) == 0) {
      DAT_00fbad10 = DAT_00fbad10 | 1;
      local_14 = (void *)0x0;
      FUN_004e8010();
      _atexit((_func_4879 *)&LAB_00bcd6b0);
      local_14 = (void *)0xffffffff;
    }
    bVar7 = DAT_00fc0bd8 != 0;
    pcVar6 = *(code **)(**(int **)(in_ECX + 0x4c) + 0x94);
    if (bVar7) {
      (*pcVar6)(0);
      (**(code **)(**(int **)(in_ECX + 0x50) + 0x94))(1);
      (**(code **)(**(int **)(in_ECX + 0x58) + 0x94))(1);
    }
    else {
      (*pcVar6)(1);
      (**(code **)(**(int **)(in_ECX + 0x50) + 0x94))(0);
      (**(code **)(**(int **)(in_ECX + 0x58) + 0x94))(0);
    }
    (**(code **)(**(int **)(in_ECX + 0x5c) + 0x94))(bVar7);
    pcVar6 = *(code **)(**(int **)(in_ECX + 0x54) + 0x94);
    bVar7 = true;
  }
  else {
    if (*(char *)(in_ECX + 0x17c) != '\b') goto LAB_00639038;
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_14 = (void *)0x1;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_14 = (void *)0xffffffff;
    }
    iVar1 = **(int **)(in_ECX + 0x40);
    iVar2 = FUN_004e2e70(&DAT_00f8d9e0,1);
    bVar7 = iVar2 != 0;
    pcVar6 = *(code **)(iVar1 + 0x90);
  }
  (*pcVar6)(bVar7);
LAB_00639038:
  iVar1 = in_ECX + 0xb0;
  FUN_0075d790();
  if (*(int *)(in_ECX + 0xc0) == 0) {
    FUN_0075d470(iVar1,0);
  }
  else if (*(int *)(in_ECX + 0xc0) == 1) {
    FUN_0075d540(iVar1,0);
  }
  iVar2 = *(int *)(in_ECX + 8);
  if ((int *)**(int **)(in_ECX + 0xb4) != *(int **)(in_ECX + 0xb4)) {
    iVar3 = (*(int *)(iVar2 + 0x14) - *(int *)(iVar2 + 0xc)) + -0x3c;
    iVar4 = FUN_0075d610(iVar3);
    FUN_00749a00(((*(int *)(iVar2 + 0x10) - *(int *)(iVar2 + 8)) - iVar4) + -0x14,iVar3);
    if (*(int *)(in_ECX + 0xc0) == 0) {
      FUN_0075d470(iVar1,0);
      ExceptionList = local_1c;
      return;
    }
    if (*(int *)(in_ECX + 0xc0) == 1) {
      FUN_0075d540(iVar1,0);
    }
  }
  ExceptionList = local_1c;
  return;
}

