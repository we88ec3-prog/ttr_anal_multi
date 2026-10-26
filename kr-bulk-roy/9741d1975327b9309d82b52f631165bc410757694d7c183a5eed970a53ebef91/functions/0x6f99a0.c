
undefined4 * FUN_006f99a0(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)FUN_00700880(param_1,0,0,0x20);
  iVar2 = *(int *)(param_1 + 0x10);
  *puVar3 = *(undefined4 *)(iVar2 + 0x1c);
  bVar1 = *(byte *)(iVar2 + 0x14);
  *(undefined4 **)(iVar2 + 0x1c) = puVar3;
  puVar3[2] = 0;
  puVar3[3] = 0;
  puVar3[7] = 0;
  *(byte *)((int)puVar3 + 5) = bVar1 & 3;
  *(undefined1 *)(puVar3 + 1) = 5;
  *(undefined2 *)((int)puVar3 + 6) = 0xff;
  puVar3[4] = &DAT_00c0bfa8;
  FUN_006f9500();
  FUN_006f9560(param_1);
  return puVar3;
}

