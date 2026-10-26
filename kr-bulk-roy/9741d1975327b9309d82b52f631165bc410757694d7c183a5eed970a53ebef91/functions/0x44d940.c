
void FUN_0044d940(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0x3ea) {
    iVar1 = *(int *)(param_1 + 8);
    if ((((iVar1 == *(int *)(*(int *)(in_ECX + 0xf4) + 0x20)) ||
         (iVar1 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20))) ||
        (iVar1 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20))) ||
       (iVar1 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20))) {
      iVar1 = *(int *)(in_ECX + 0x24);
      *(undefined4 *)(iVar1 + 0x13dc) = 0;
      *(undefined1 *)(iVar1 + 0x13d9) = 1;
      return;
    }
  }
  else if (iVar1 == 0x3eb) {
    iVar1 = *(int *)(in_ECX + 0xf4);
    iVar2 = *(int *)(param_1 + 8);
    if (iVar2 == *(int *)(iVar1 + 0x20)) {
      iVar1 = *(int *)(in_ECX + 0x24);
      uVar3 = *(undefined4 *)(in_ECX + 0xf8);
      *(undefined1 *)(iVar1 + 0x13d9) = 1;
      *(undefined4 *)(iVar1 + 0x13dc) = uVar3;
      return;
    }
    if (iVar2 == *(int *)(*(int *)(in_ECX + 0xf8) + 0x20)) {
      iVar1 = *(int *)(in_ECX + 0x24);
      *(undefined4 *)(iVar1 + 0x13dc) = *(undefined4 *)(in_ECX + 0xfc);
      *(undefined1 *)(iVar1 + 0x13d9) = 1;
    }
    else {
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0xfc) + 0x20)) {
        iVar1 = *(int *)(in_ECX + 0x24);
        *(undefined4 *)(iVar1 + 0x13dc) = *(undefined4 *)(in_ECX + 0x100);
        *(undefined1 *)(iVar1 + 0x13d9) = 1;
        return;
      }
      if (iVar2 == *(int *)(*(int *)(in_ECX + 0x100) + 0x20)) {
        iVar2 = *(int *)(in_ECX + 0x24);
        *(undefined1 *)(iVar2 + 0x13d9) = 1;
        *(int *)(iVar2 + 0x13dc) = iVar1;
        return;
      }
    }
  }
  else if ((iVar1 == 0x578) && (*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x104) + 0x20)))
  {
    FUN_0044d6f0();
    return;
  }
  return;
}

