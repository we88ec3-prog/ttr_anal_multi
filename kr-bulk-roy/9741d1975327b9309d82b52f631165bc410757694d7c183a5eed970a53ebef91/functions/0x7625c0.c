
void FUN_007625c0(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  
  FUN_007445d0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xc9) {
    FUN_00761800();
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 1000;
      FUN_00748900();
      return;
    }
  }
  else {
    if (*(int *)(param_1 + 0x10) != 0xca) {
      return;
    }
    *(undefined4 *)(in_ECX + 0x160) = *(undefined4 *)(in_ECX + 0x14c);
    *(undefined4 *)(in_ECX + 0x164) = *(undefined4 *)(in_ECX + 0x14c);
    FUN_00761800();
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0x3e9;
      FUN_00748900();
      return;
    }
  }
  FUN_00748900();
  return;
}

