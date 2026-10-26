
void FUN_005de0a0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int in_EAX;
  undefined4 *puVar2;
  
  if ((*(char *)(in_EAX + 0x2a1) == '\0') && (*(char *)(in_EAX + 0x2cc) == '\0')) {
    puVar2 = (undefined4 *)FUN_00891268(0x24);
    if (puVar2 != (undefined4 *)0x0) {
      iVar1 = *(int *)(in_EAX + 0x20);
      puVar2[5] = *(undefined4 *)(in_EAX + 0x2d0);
      puVar2[6] = iVar1 + 1;
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4372;
      *puVar2 = FoxUI::FXUIEventI4::vftable;
      puVar2[7] = param_1;
      puVar2[8] = param_2;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

