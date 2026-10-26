
undefined4 FUN_00632cd0(void)

{
  int in_ECX;
  int iVar1;
  
  if (*(int *)(in_ECX + 0xf8) == 2) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x124) + 0xcc);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    else {
      iVar1 = *(int *)(iVar1 + 0xdc);
      if (iVar1 == 0) {
        iVar1 = -1;
      }
      else {
        iVar1 = *(int *)(iVar1 + 0x20);
      }
    }
    if ((*(int *)(in_ECX + 0xfc) == -1) ||
       ((*(int *)(in_ECX + 0x144) == 0 &&
        ((iVar1 == -1 || ((*(int *)(in_ECX + 0x140) != 0 && (*(int *)(in_ECX + 0x140) <= iVar1))))))
       )) {
      return 0;
    }
  }
  return 1;
}

