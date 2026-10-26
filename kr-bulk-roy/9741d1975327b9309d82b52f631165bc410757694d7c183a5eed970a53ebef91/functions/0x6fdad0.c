
void FUN_006fdad0(void)

{
  undefined4 uVar1;
  int in_EAX;
  
  *(undefined4 **)(in_EAX + 0x14) = *(undefined4 **)(in_EAX + 0x28);
  uVar1 = **(undefined4 **)(in_EAX + 0x28);
  *(undefined4 *)(in_EAX + 0xc) = uVar1;
  FUN_006fd860(uVar1);
  FUN_006fda60();
  *(undefined2 *)(in_EAX + 0x34) = *(undefined2 *)(in_EAX + 0x36);
  *(undefined1 *)(in_EAX + 0x39) = 1;
  if ((20000 < *(int *)(in_EAX + 0x30)) &&
     ((*(int *)(in_EAX + 0x14) - *(int *)(in_EAX + 0x28)) / 0x18 + 1 < 20000)) {
    FUN_006fdd10();
  }
  *(undefined4 *)(in_EAX + 0x74) = 0;
  *(undefined4 *)(in_EAX + 0x70) = 0;
  return;
}

