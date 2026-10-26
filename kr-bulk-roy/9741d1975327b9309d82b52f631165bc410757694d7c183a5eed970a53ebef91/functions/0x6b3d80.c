
void FUN_006b3d80(void)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_EAX + 8);
  if (iVar1 == *(int *)(*(int *)(in_ECX + 0x80) + 0x20)) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf42e7;
      FUN_004072a0();
      return;
    }
  }
  else if (iVar1 == *(int *)(*(int *)(in_ECX + 0x84) + 0x20)) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf439e;
      FUN_004072a0();
      return;
    }
  }
  else {
    if (iVar1 != *(int *)(*(int *)(in_ECX + 0x88) + 0x20)) {
      return;
    }
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf42e8;
      *puVar2 = FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(puVar2 + 5) = 0;
      FUN_004072a0();
      return;
    }
  }
  FUN_004072a0();
  return;
}

