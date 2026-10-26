
void FUN_006f5220(void)

{
  int in_EAX;
  int in_ECX;
  int iVar1;
  
  if (in_ECX < 0) {
    *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + in_ECX * 0x10 + 0x10;
    return;
  }
  iVar1 = in_ECX * 0x10;
  if (*(uint *)(in_EAX + 8) < (uint)(*(int *)(in_EAX + 0xc) + iVar1)) {
    do {
      *(undefined4 *)(*(int *)(in_EAX + 8) + 8) = 0;
      *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
    } while (*(uint *)(in_EAX + 8) < (uint)(*(int *)(in_EAX + 0xc) + iVar1));
  }
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 0xc) + iVar1;
  return;
}

