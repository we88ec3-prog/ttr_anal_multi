
void FUN_005a55e0(int param_1)

{
  uint *puVar1;
  uint uVar2;
  undefined1 in_CL;
  int in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009360dc;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(int *)(in_EDX + 0x158) = param_1;
  *(undefined1 *)(in_EDX + 0x15c) = in_CL;
  if (param_1 == 1) {
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 0;
      FUN_004d4d10(uVar2);
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = 0xffffffff;
    DAT_00fb11e8 = 1;
    (**(code **)(**(int **)(in_EDX + 0x148) + 0xd4))();
    uVar2 = *(uint *)(*(int *)(in_EDX + 0x148) + 0x28);
    if ((uVar2 & 0x80000) != 0) {
      *(uint *)(*(int *)(in_EDX + 0x148) + 0x28) = uVar2 ^ 0x80000;
    }
    (**(code **)(**(int **)(in_EDX + 0x140) + 0xd0))();
    FUN_00645250(*(undefined4 *)(in_EDX + 0x140));
  }
  else if (param_1 == 2) {
    if ((DAT_00fb11e0 & 1) == 0) {
      DAT_00fb11e0 = DAT_00fb11e0 | 1;
      local_8 = 1;
      FUN_004d4d10(uVar2);
      _atexit((_func_4879 *)&LAB_00bccef0);
    }
    local_8 = 0xffffffff;
    DAT_00fb11e8 = 2;
    (**(code **)(**(int **)(in_EDX + 0x140) + 0xd4))();
    (**(code **)(**(int **)(in_EDX + 0x148) + 0xd0))();
    if (*(int *)(*(int *)(in_EDX + 0x148) + 0xec) != 0) {
      FUN_006482c0();
    }
    puVar1 = (uint *)(*(int *)(in_EDX + 0x148) + 0x28);
    *puVar1 = *puVar1 | 0x80000;
    if (*(int *)(*(int *)(in_EDX + 0x148) + 0x60) != 0) {
      FUN_0074a010(*(int *)(in_EDX + 0x148));
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}

