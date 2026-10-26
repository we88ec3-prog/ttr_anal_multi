
void FUN_0072d8c0(int param_1)

{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined1 *in_ECX;
  
  iVar2 = FUN_0072d860();
  *(undefined4 *)(iVar2 + 0x16b4) = 8;
  *(byte *)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 8)) = (byte)param_1;
  *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
  bVar3 = (byte)((uint)param_1 >> 8);
  *(byte *)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 8)) = bVar3;
  *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
  *(byte *)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 8)) = ~(byte)param_1;
  *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
  *(byte *)(*(int *)(iVar2 + 0x14) + *(int *)(iVar2 + 8)) = ~bVar3;
  *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
  iVar1 = *(int *)(iVar2 + 0x14);
  for (; param_1 != 0; param_1 = param_1 + -1) {
    *(undefined1 *)(iVar1 + *(int *)(iVar2 + 8)) = *in_ECX;
    *(int *)(iVar2 + 0x14) = *(int *)(iVar2 + 0x14) + 1;
    iVar1 = *(int *)(iVar2 + 0x14);
    in_ECX = in_ECX + 1;
  }
  return;
}

