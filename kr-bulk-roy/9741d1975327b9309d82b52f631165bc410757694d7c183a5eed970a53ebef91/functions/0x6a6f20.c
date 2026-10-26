
void FUN_006a6f20(void)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(in_EAX + 0xec) + 0xcc);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0xdc);
    if (iVar2 == 0) {
      iVar2 = -1;
    }
    else {
      iVar2 = *(int *)(iVar2 + 0x20);
    }
    if (iVar2 != -1) {
      puVar1 = (undefined4 *)FUN_00891268(0x18);
      if (puVar1 != (undefined4 *)0x0) {
        puVar1[5] = iVar2;
        puVar1[1] = 0xffffffff;
        puVar1[2] = 0xffffffff;
        puVar1[3] = 0;
        puVar1[4] = 0xf4378;
        *puVar1 = FoxUI::FXUIEventI1::vftable;
        FUN_004072a0();
        return;
      }
      FUN_004072a0();
    }
  }
  return;
}

