
void FUN_0061a500(void)

{
  int in_EAX;
  int iVar1;
  
  if ((*(int *)(*(int *)(in_EAX + 0xf4) + 0xcc) == 0) ||
     (*(int *)(*(int *)(in_EAX + 0xf4) + 0xd8) == 0)) {
    iVar1 = -1;
  }
  else {
    iVar1 = FUN_005f55a0();
  }
  if (iVar1 == 0) {
    FUN_0061b0b0(*(undefined1 *)(in_EAX + 0x104));
  }
  else {
    if (iVar1 == 1) {
      FUN_00619150(*(undefined1 *)(in_EAX + 0x104));
      return;
    }
    if (iVar1 == 2) {
      FUN_00617b70(*(undefined4 *)(in_EAX + 0x100),*(undefined1 *)(in_EAX + 0x104));
      return;
    }
  }
  return;
}

