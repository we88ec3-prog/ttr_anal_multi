
undefined4 * FUN_00707a00(void)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_EAX;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  if (*(uint *)(*(int *)(in_EAX + 0x10) + 0x40) <= *(uint *)(*(int *)(in_EAX + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  if (*(int *)(in_EAX + 0x14) == *(int *)(in_EAX + 0x28)) {
    uVar5 = *(undefined4 *)(in_EAX + 0x48);
  }
  else {
    uVar5 = *(undefined4 *)(**(int **)(*(int *)(in_EAX + 0x14) + 4) + 0xc);
  }
  iVar2 = *(int *)(in_EAX + 0x10);
  puVar4 = (undefined4 *)(**(code **)(iVar2 + 0xc))(*(undefined4 *)(iVar2 + 0x10),0,0,0x1c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)FUN_006fdb40();
  }
  *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + 0x1c;
  bVar1 = *(byte *)(*(int *)(in_EAX + 0x10) + 0x14);
  puVar4[3] = uVar5;
  puVar4[4] = 4;
  puVar4[2] = 0;
  *(byte *)((int)puVar4 + 5) = bVar1 & 3;
  *(undefined1 *)(puVar4 + 1) = 7;
  *puVar4 = **(undefined4 **)(*(int *)(in_EAX + 0x10) + 0x70);
  **(undefined4 **)(*(int *)(in_EAX + 0x10) + 0x70) = puVar4;
  puVar3 = *(undefined4 **)(in_EAX + 8);
  *puVar3 = puVar4;
  puVar3[2] = 7;
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  puVar4[6] = 0;
  FUN_006fec70();
  FUN_006fb850();
  *(int *)(in_EAX + 8) = *(int *)(in_EAX + 8) + 0x10;
  FUN_006f5910();
  return puVar4 + 6;
}

