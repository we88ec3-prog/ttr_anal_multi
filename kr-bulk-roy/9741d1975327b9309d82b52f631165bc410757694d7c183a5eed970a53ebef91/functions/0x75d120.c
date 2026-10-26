
void FUN_0075d120(int param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  FUN_00744ca0(param_1);
  if (*(int *)(param_1 + 0x10) == 100) {
    (**(code **)(*in_ECX + 0x198))();
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0x642;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

