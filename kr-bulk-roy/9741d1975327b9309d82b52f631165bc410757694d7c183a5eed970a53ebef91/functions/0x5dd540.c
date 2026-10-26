
void FUN_005dd540(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  FUN_005d6fb0(param_1);
  if ((((*(int *)(in_ECX + 0x25c) != 0) && (*(char *)(in_ECX + 0x2a1) == '\0')) &&
      (*(char *)(in_ECX + 0x2cc) == '\0')) && (*(int *)(param_1 + 0x10) == 0x7c)) {
    puVar2 = (undefined4 *)FUN_00891268(0x18);
    if (puVar2 != (undefined4 *)0x0) {
      iVar1 = *(int *)(in_ECX + 0x20);
      puVar2[1] = 0xffffffff;
      puVar2[2] = 0xffffffff;
      puVar2[3] = 0;
      puVar2[4] = 0xf4376;
      *puVar2 = FoxUI::FXUIEventI1::vftable;
      puVar2[5] = iVar1 + 1;
      FUN_00748900();
      return;
    }
    FUN_00748900();
  }
  return;
}

