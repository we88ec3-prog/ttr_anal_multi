
void FUN_0075ba00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_007445d0(param_1);
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x65) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x385;
      FUN_00748900();
      return;
    }
  }
  else if (iVar1 == 0x67) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x386;
      FUN_00748900();
      return;
    }
  }
  else {
    if (iVar1 != 0x66) {
      return;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 900;
      FUN_00748900();
      return;
    }
  }
  FUN_00748900();
  return;
}

