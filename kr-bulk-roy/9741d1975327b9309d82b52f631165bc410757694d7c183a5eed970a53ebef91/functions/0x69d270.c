
void FUN_0069d270(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093c77e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)) {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 0;
        FUN_00587480(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      FUN_0058aad0(0xf430c);
      ExceptionList = local_10;
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
      if (*(int *)(in_ECX + 0xf4) == 0) {
        FUN_006a0f50(*(undefined4 *)(in_ECX + 0xfc));
      }
      else if (*(int *)(in_ECX + 0xf4) == 1) {
        FUN_0069e870(*(undefined4 *)(in_ECX + 0x100));
        ExceptionList = local_10;
        return;
      }
    }
  }
  else if ((*(int *)(param_1 + 0x10) == 0x76c) &&
          (iVar1 = *(int *)(in_ECX + 0xf8), *(int *)(param_1 + 8) == *(int *)(iVar1 + 0x20))) {
    if ((*(int *)(iVar1 + 0xcc) == 0) || (*(int *)(iVar1 + 0xd8) == 0)) {
      iVar1 = -1;
    }
    else {
      iVar1 = FUN_005f55a0();
    }
    if (iVar1 == 0) {
      FUN_004e14f0();
      FUN_00534200();
      uVar2 = 0xcc;
      *(undefined4 *)(in_ECX + 0xf4) = 0;
      FUN_005854b0(0xcc);
      FUN_00585330(uVar2);
      FUN_00757710();
      (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
      FUN_006a0110(*(undefined4 *)(in_ECX + 0xfc));
      ExceptionList = local_10;
      return;
    }
    if (iVar1 == 1) {
      FUN_004e14f0();
      FUN_00534850();
      uVar2 = 0xd4;
      *(undefined4 *)(in_ECX + 0xf4) = 1;
      FUN_005854b0(0xd4);
      FUN_00585330(uVar2);
      FUN_00757710();
      (**(code **)(**(int **)(in_ECX + 0x108) + 200))();
      FUN_0069e760(*(undefined4 *)(in_ECX + 0x100));
      ExceptionList = local_10;
      return;
    }
  }
  ExceptionList = local_10;
  return;
}

