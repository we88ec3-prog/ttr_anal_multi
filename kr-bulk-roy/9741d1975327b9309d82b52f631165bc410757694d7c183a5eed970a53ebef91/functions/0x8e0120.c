
void FUN_008e0120(void)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EDX;
  
  iVar1 = *(int *)(in_EDX + 8);
  if (iVar1 != 0) {
    puVar2 = *(undefined4 **)(in_EDX + 0x10);
    *(undefined4 *)(iVar1 + 0x6c) = *puVar2;
    *(undefined4 *)(iVar1 + 0x70) = puVar2[1];
    *(undefined4 *)(iVar1 + 0x74) = puVar2[2];
    *(undefined4 *)(iVar1 + 0x78) = puVar2[3];
    *(undefined4 *)(iVar1 + 0x7c) = puVar2[4];
  }
  return;
}

