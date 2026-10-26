
void FUN_005ddf50(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  undefined4 *puVar3;
  
  if ((*(char *)(in_EAX + 0x2a1) == '\0') && (*(char *)(in_EAX + 0x2cc) == '\0')) {
    puVar3 = (undefined4 *)FUN_00891268(0x1c);
    if (puVar3 != (undefined4 *)0x0) {
      iVar1 = *(int *)(in_EAX + 0x20);
      uVar2 = *(undefined4 *)(in_EAX + 0x2d0);
      puVar3[1] = 0xffffffff;
      puVar3[2] = 0xffffffff;
      puVar3[3] = 0;
      puVar3[4] = 0xf436c;
      *puVar3 = FoxUI::FXUIEventI2::vftable;
      puVar3[5] = uVar2;
      puVar3[6] = iVar1 + 1;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

