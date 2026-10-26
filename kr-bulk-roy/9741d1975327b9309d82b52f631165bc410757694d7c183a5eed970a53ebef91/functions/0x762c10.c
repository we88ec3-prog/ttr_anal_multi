
void FUN_00762c10(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (0 < param_1) {
    puVar2 = (undefined4 *)FUN_00891268(0x14);
    if (puVar2 != (undefined4 *)0x0) {
      *puVar2 = FoxUI::FXUIEvent::vftable;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0x3ec;
    }
    FUN_00748900();
    uVar1 = *(undefined4 *)(in_ECX + 0x14c);
    if (*(char *)(in_ECX + 0x141) != '\0') {
      FUN_00757e40(param_1,uVar1);
      FUN_006ee170(uVar1);
      return;
    }
    FUN_00757e40(param_1,uVar1);
  }
  return;
}

