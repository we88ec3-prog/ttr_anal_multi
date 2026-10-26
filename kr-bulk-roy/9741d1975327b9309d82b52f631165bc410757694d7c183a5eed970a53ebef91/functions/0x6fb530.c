
int FUN_006fb530(void)

{
  char cVar1;
  int iVar2;
  int in_EAX;
  
  iVar2 = *(int *)(in_EAX + 0x10);
  if (*(byte *)(iVar2 + 0x15) < 2) {
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(int *)(iVar2 + 0x20) = iVar2 + 0x1c;
    *(undefined4 *)(iVar2 + 0x24) = 0;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    *(undefined4 *)(iVar2 + 0x2c) = 0;
    *(undefined1 *)(iVar2 + 0x15) = 2;
  }
  cVar1 = *(char *)(iVar2 + 0x15);
  while (cVar1 != '\x04') {
    FUN_006fb2a0();
    cVar1 = *(char *)(iVar2 + 0x15);
  }
  FUN_006fb0c0();
  cVar1 = *(char *)(iVar2 + 0x15);
  while (cVar1 != '\0') {
    FUN_006fb2a0();
    cVar1 = *(char *)(iVar2 + 0x15);
  }
  *(uint *)(iVar2 + 0x40) = (*(uint *)(iVar2 + 0x48) / 100) * *(int *)(iVar2 + 0x50);
  return *(uint *)(iVar2 + 0x48) * 0x51eb851f;
}

