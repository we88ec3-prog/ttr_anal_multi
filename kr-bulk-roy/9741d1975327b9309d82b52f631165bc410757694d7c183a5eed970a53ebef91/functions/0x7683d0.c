
void FUN_007683d0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  FUN_007445d0(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x82) {
    FUN_007682e0();
  }
  else {
    if (iVar1 == 0xc9) {
      (**(code **)(*in_ECX + 0x1b0))();
      return;
    }
    if (iVar1 == 0xca) {
      (**(code **)(*in_ECX + 0x1b0))();
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x44c;
        FUN_00748900();
        return;
      }
      FUN_00748900();
      return;
    }
  }
  return;
}

