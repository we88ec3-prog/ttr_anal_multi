
void FUN_0047f840(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf0) + 0x20)) {
      FUN_0047f710(in_ECX);
      FUN_007612c0();
      (**(code **)(**(int **)(in_ECX + 0xf8) + 200))();
      return;
    }
    if (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) {
      FUN_004054c0();
      puVar1 = (undefined4 *)FUN_00891268(0x14);
      if (puVar1 != (undefined4 *)0x0) {
        *puVar1 = FoxUI::FXUIEvent::vftable;
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0xf442a;
        FUN_0058aa50(puVar1);
        return;
      }
      FUN_0058aa50(0);
    }
  }
  return;
}

