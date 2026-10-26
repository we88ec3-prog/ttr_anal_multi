
void FUN_006f7ec0(void)

{
  int in_EAX;
  undefined *puVar1;
  int in_ECX;
  
  if (*(char *)(in_EAX + 6) != '\0') {
    *(undefined4 *)(in_ECX + 0x1c) = 0xffffffff;
    *(undefined4 *)(in_ECX + 0x20) = 0xffffffff;
    *(undefined **)(in_ECX + 0x10) = &DAT_00c428c8;
    *(undefined **)(in_ECX + 0xc) = &DAT_00c428d0;
    FUN_006f7c50(in_ECX + 0x24);
    return;
  }
  *(int *)(in_ECX + 0x10) = *(int *)(*(int *)(in_EAX + 0x10) + 0x20) + 0x10;
  *(undefined4 *)(in_ECX + 0x1c) = *(undefined4 *)(*(int *)(in_EAX + 0x10) + 0x3c);
  *(undefined4 *)(in_ECX + 0x20) = *(undefined4 *)(*(int *)(in_EAX + 0x10) + 0x40);
  puVar1 = &DAT_00c428d4;
  if (*(int *)(in_ECX + 0x1c) != 0) {
    puVar1 = &DAT_00c424d8;
  }
  *(undefined **)(in_ECX + 0xc) = puVar1;
  FUN_006f7c50(in_ECX + 0x24);
  return;
}

