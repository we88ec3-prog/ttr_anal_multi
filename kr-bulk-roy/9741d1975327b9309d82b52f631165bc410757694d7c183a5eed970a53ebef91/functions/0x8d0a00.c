
void FUN_008d0a00(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    puVar2 = *(undefined4 **)(param_1 + 0x10);
    *(undefined4 *)(iVar1 + 0x6c) = *puVar2;
    *(undefined4 *)(iVar1 + 0x70) = puVar2[1];
    *(undefined4 *)(iVar1 + 0x74) = puVar2[2];
    *(undefined4 *)(iVar1 + 0x78) = puVar2[3];
    *(undefined4 *)(iVar1 + 0x7c) = puVar2[4];
  }
  return;
}

