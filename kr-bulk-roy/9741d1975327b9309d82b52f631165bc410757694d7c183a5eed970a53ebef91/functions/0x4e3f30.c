
undefined4 FUN_004e3f30(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)(in_ECX + 0x6957);
    for (iVar2 = 9; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar1 = *param_1;
      param_1 = param_1 + 1;
      puVar1 = puVar1 + 1;
    }
    *(undefined2 *)puVar1 = *(undefined2 *)param_1;
    puVar1 = (undefined4 *)FUN_00891268(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42b6;
      *puVar1 = FoxUI::FXUIEventP1::vftable;
      puVar1[5] = (undefined4 *)(in_ECX + 0x6957);
      FUN_0058aa50(puVar1);
      return 0;
    }
    FUN_0058aa50(0);
  }
  return 0;
}

