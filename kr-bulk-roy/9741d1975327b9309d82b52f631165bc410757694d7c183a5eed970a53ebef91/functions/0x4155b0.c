
void FUN_004155b0(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092484e;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_008438c0(&stack0x00000004);
  if (in_ECX != *(int *)(in_ECX + 0x4a4)) {
    puVar2 = (undefined4 *)FUN_00891268(0x24,uVar1);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4308;
      *puVar2 = FUI::FXUICashShopCartOpen::vftable;
      puVar2[5] = 0;
      puVar2[6] = 0;
      puVar2[7] = 0;
    }
    FUN_004a8680();
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aa50(puVar2);
  }
  ExceptionList = local_10;
  return;
}

