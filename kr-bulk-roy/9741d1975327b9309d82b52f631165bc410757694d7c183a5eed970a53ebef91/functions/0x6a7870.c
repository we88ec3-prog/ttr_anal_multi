
void FUN_006a7870(void)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 == *(int *)(*(int *)(in_ECX + 0x108) + 0x20)) {
    return;
  }
  if (iVar1 == *(int *)(*(int *)(in_ECX + 0x10c) + 0x20)) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4301;
      FUN_004072a0();
      return;
    }
  }
  else {
    if (iVar1 != *(int *)(*(int *)(in_ECX + 0x110) + 0x20)) {
      if (iVar1 != *(int *)(*(int *)(in_ECX + 0x114) + 0x20)) {
        return;
      }
      puVar2 = (undefined4 *)FUN_00891268(0x14);
      if (puVar2 == (undefined4 *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        *puVar2 = FoxUI::FXUIEvent::vftable;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4407;
      }
      uVar3 = 0x80;
      FUN_005854b0(0x80,&DAT_00bed1fc,puVar2);
      uVar3 = FUN_00585330(uVar3);
      FUN_00404b10(0xcf,uVar3);
      return;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf42fe;
      FUN_004072a0();
      return;
    }
  }
  FUN_004072a0();
  return;
}

