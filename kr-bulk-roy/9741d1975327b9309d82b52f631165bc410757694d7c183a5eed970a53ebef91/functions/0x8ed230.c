
void FUN_008ed230(void)

{
  int in_EAX;
  int iVar1;
  
  if (*(int *)(in_EAX + 0x1ac) < 1) {
    *(undefined4 *)(in_EAX + 0xc) = 0x88;
    return;
  }
  iVar1 = *(int *)(in_EAX + 0x1ac) + -1;
  *(int *)(in_EAX + 0x1ac) = iVar1;
  iVar1 = iVar1 * 0x10 + *(int *)(in_EAX + 0x1b4);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -1;
  *(undefined1 *)(in_EAX + 0x178) = 0;
  if (0 < *(int *)(iVar1 + 8)) {
    *(int *)(in_EAX + 0x1ac) = *(int *)(in_EAX + 0x1ac) + 1;
    *(undefined4 *)(in_EAX + 0x168) = *(undefined4 *)(*(int *)(iVar1 + 0xc) + 4);
    return;
  }
  FUN_008ec690();
  return;
}

