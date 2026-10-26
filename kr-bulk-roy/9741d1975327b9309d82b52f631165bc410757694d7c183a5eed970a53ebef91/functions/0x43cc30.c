
void FUN_0043cc30(int param_1)

{
  int iVar1;
  void **ppvVar2;
  undefined4 *puVar3;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092598e;
  local_10 = ExceptionList;
  if (*(int *)(param_1 + 0x10) != 0x578) {
    return;
  }
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == *(int *)(in_ECX[0x3e] + 0x20)) {
    ExceptionList = &local_10;
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf42d3;
      FUN_0058b1a0(0x12f,puVar3);
      ppvVar2 = ExceptionList;
      goto LAB_0043cd48;
    }
  }
  else {
    if (iVar1 != *(int *)(in_ECX[0x3f] + 0x20)) {
      ppvVar2 = &local_10;
      if (iVar1 != *(int *)(in_ECX[0x40] + 0x20)) {
        return;
      }
      goto LAB_0043cd48;
    }
    ExceptionList = &local_10;
    FUN_004054c0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    puVar3 = (undefined4 *)FUN_00891268(0x14);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = FoxUI::FXUIEvent::vftable;
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf443b;
      FUN_0058b1a0(0x12f,puVar3);
      ppvVar2 = ExceptionList;
      goto LAB_0043cd48;
    }
  }
  FUN_0058b1a0(0x12f,0);
  ppvVar2 = ExceptionList;
LAB_0043cd48:
  ExceptionList = ppvVar2;
  (**(code **)(*in_ECX + 0xd4))();
  ExceptionList = local_10;
  return;
}

