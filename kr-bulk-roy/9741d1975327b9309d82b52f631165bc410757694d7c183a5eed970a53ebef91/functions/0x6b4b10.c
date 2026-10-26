
void FUN_006b4b10(void)

{
  int in_EAX;
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != *(int *)(*(int *)(in_EAX + 0xf8) + 0x20)) {
    if (*(int *)(in_ECX + 8) == *(int *)(*(int *)(in_EAX + 0x18c) + 0x20)) {
      iVar1 = *(int *)(*(int *)(in_EAX + 0x18c) + 0xcc);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 0xdc) != 0)) {
        FUN_006b5670();
        return;
      }
      FUN_006b5670();
    }
    return;
  }
  iVar1 = 0;
  do {
    if (*(char *)(in_EAX + 0x1d8 + iVar1) == '\0') break;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  FUN_006b56e0();
  FUN_006b4bb0(in_EAX);
  FUN_006b4f80(in_EAX);
  return;
}

