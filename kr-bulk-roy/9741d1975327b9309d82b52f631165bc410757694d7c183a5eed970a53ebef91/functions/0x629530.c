
void FUN_00629530(int param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  FUN_00744ca0(param_1);
  if (*(int *)(param_1 + 0x10) == 0xc9) {
    puVar1 = (undefined4 *)FUN_00891268(0x14);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = FoxUI::FXUIEvent::vftable;
      puVar1[1] = 0xffffffff;
      puVar1[2] = 0xffffffff;
      puVar1[3] = 0;
      puVar1[4] = 0xf43c9;
    }
    FUN_00748900();
    (**(code **)(*in_ECX + 0xa0))(1);
  }
  else if (*(int *)(param_1 + 0x10) == 0xca) {
    FUN_006295b0();
    (**(code **)(*in_ECX + 0xa0))(0);
    return;
  }
  return;
}

