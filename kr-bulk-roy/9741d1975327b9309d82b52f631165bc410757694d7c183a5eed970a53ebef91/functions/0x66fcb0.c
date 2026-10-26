
void FUN_0066fcb0(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xcc);
  if (iVar1 != 0) {
    iVar1 = *(int *)(iVar1 + 0xdc);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0x20);
    }
    if ((iVar1 != -1) &&
       (iVar1 = *(int *)(*(int *)(in_ECX + 0x114 + iVar1 * 4) + 0x248), iVar1 != 0)) {
      puVar2 = (undefined4 *)FUN_00891268(0x18);
      if (puVar2 != (undefined4 *)0x0) {
        puVar2[5] = iVar1;
        puVar2[1] = 0xffffffff;
        puVar2[2] = 0xffffffff;
        puVar2[3] = 0;
        puVar2[4] = 0xf4378;
        *puVar2 = FoxUI::FXUIEventI1::vftable;
        FUN_004072a0();
        return;
      }
      FUN_004072a0();
    }
  }
  return;
}

