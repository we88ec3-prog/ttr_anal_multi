
void FUN_0070d6f0(void)

{
  undefined4 uVar1;
  int in_EAX;
  undefined4 *puVar2;
  
  if ((*(int *)(in_EAX + 0x10) == 0x11d) || (*(int *)(in_EAX + 0x10) == 0x11e)) {
    uVar1 = *(undefined4 *)(in_EAX + 0x34);
    FUN_006fec70(uVar1,*(int *)(in_EAX + 0x18) + 0x10,*(undefined4 *)(*(int *)(in_EAX + 0x18) + 0xc)
                );
    puVar2 = (undefined4 *)FUN_006f9d80(uVar1);
    if (puVar2[2] == 0) {
      *puVar2 = 1;
      puVar2[2] = 1;
    }
  }
  return;
}

