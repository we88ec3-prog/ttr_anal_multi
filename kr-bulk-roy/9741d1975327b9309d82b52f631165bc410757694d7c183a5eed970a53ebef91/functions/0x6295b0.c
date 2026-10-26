
void FUN_006295b0(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_EAX;
  undefined4 *puVar4;
  
  if (*(int *)(in_EAX + 0x254) != *(int *)(in_EAX + 0x250)) {
    puVar4 = (undefined4 *)FUN_00891268(0x24);
    if (puVar4 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_EAX + 0x248);
      uVar2 = *(undefined4 *)(in_EAX + 0x250);
      uVar3 = *(undefined4 *)(in_EAX + 0x24c);
      puVar4[6] = *(undefined4 *)(in_EAX + 0x254);
      puVar4[5] = uVar3;
      puVar4[1] = 0xffffffff;
      puVar4[2] = 0xffffffff;
      puVar4[3] = 0;
      puVar4[4] = 0xf43cb;
      *puVar4 = FoxUI::FXUIEventD4::vftable;
      puVar4[7] = uVar2;
      puVar4[8] = uVar1;
    }
    FUN_00748900();
  }
  puVar4 = (undefined4 *)FUN_00891268(0x14);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_00748900();
    return;
  }
  *puVar4 = FoxUI::FXUIEvent::vftable;
  puVar4[1] = 0xffffffff;
  puVar4[2] = 0xffffffff;
  puVar4[3] = 0;
  puVar4[4] = 0xf43ca;
  FUN_00748900();
  return;
}

