
undefined4 * FUN_006f7390(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int in_EAX;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(in_EAX + 0x10);
  puVar4 = (undefined4 *)(**(code **)(iVar1 + 0xc))(*(undefined4 *)(iVar1 + 0x10),0,0,0x78);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_006fdb40();
  }
  *(int *)(iVar1 + 0x44) = *(int *)(iVar1 + 0x44) + 0x78;
  iVar1 = *(int *)(in_EAX + 0x10);
  *puVar4 = *(undefined4 *)(iVar1 + 0x1c);
  *(undefined4 **)(iVar1 + 0x1c) = puVar4;
  *(byte *)((int)puVar4 + 5) = *(byte *)(iVar1 + 0x14) & 3;
  *(undefined1 *)(puVar4 + 1) = 8;
  puVar4[4] = *(undefined4 *)(in_EAX + 0x10);
  puVar4[8] = 0;
  puVar4[0xb] = 0;
  puVar4[0x1c] = 0;
  puVar4[0x11] = 0;
  puVar4[0xf] = 0;
  puVar4[0x10] = 0;
  puVar4[0x1a] = 0;
  puVar4[0xc] = 0;
  *(undefined4 *)((int)puVar4 + 0x36) = 0x1000000;
  *(undefined2 *)(puVar4 + 0xd) = 0;
  *(undefined1 *)((int)puVar4 + 6) = 0;
  puVar4[5] = 0;
  puVar4[10] = 0;
  puVar4[6] = 0;
  puVar4[0x1d] = 0;
  puVar4[0x14] = 0;
  FUN_006f7200();
  puVar4[0x12] = *(undefined4 *)(in_EAX + 0x48);
  puVar4[0x13] = *(undefined4 *)(in_EAX + 0x4c);
  puVar4[0x14] = *(undefined4 *)(in_EAX + 0x50);
  *(undefined1 *)(puVar4 + 0xe) = *(undefined1 *)(in_EAX + 0x38);
  uVar2 = *(undefined4 *)(in_EAX + 0x3c);
  puVar4[0xf] = uVar2;
  uVar3 = *(undefined4 *)(in_EAX + 0x44);
  puVar4[0x10] = uVar2;
  puVar4[0x11] = uVar3;
  return puVar4;
}

