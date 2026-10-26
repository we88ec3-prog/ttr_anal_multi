
undefined4 FUN_004e3eb0(undefined4 *param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (param_1 != (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 0x6949) = *param_1;
    *(undefined4 *)(in_ECX + 0x694d) = param_1[1];
    *(undefined4 *)(in_ECX + 0x6951) = param_1[2];
    *(undefined2 *)(in_ECX + 0x6955) = *(undefined2 *)(param_1 + 3);
    puVar1 = (undefined4 *)FUN_00891268(0x18);
    if (puVar1 != (undefined4 *)0x0) {
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf42b7;
      *puVar1 = FoxUI::FXUIEventP1::vftable;
      puVar1[5] = (undefined4 *)(in_ECX + 0x6949);
      FUN_0058aa50(puVar1);
      return 0;
    }
    FUN_0058aa50(0);
  }
  return 0;
}

