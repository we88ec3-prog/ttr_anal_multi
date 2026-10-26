
void FUN_0076d7e0(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  FUN_0075ad60(param_1);
  if ((*(int *)(in_ECX + 0x60) != 0) && (*(int *)(param_1 + 0x10) == 0x578)) {
    iVar1 = *(int *)(param_1 + 8);
    if (iVar1 == 1) {
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x4b2;
        FUN_00748900();
        return;
      }
    }
    else if (iVar1 == 2) {
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x4b1;
        FUN_00748900();
        return;
      }
    }
    else {
      if (iVar1 != 3) {
        return;
      }
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0x4b0;
        FUN_00748900();
        return;
      }
    }
    FUN_00748900();
  }
  return;
}

