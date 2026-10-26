
void FUN_00746f70(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(in_ECX + 0x30) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(in_ECX + 0x14);
  if (*(int *)(in_ECX + 0x60) != 0) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x60) + 0x2c);
    *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + iVar1;
    *(int *)(in_ECX + 0x34) = *(int *)(in_ECX + 0x34) + iVar1;
    iVar1 = *(int *)(*(int *)(in_ECX + 0x60) + 0x30);
    *(int *)(in_ECX + 0x30) = *(int *)(in_ECX + 0x30) + iVar1;
    *(int *)(in_ECX + 0x38) = *(int *)(in_ECX + 0x38) + iVar1;
  }
  puVar2 = *(undefined4 **)(in_ECX + 100);
  for (puVar3 = (undefined4 *)*puVar2; puVar3 != puVar2; puVar3 = (undefined4 *)*puVar3) {
    FUN_00746f70();
  }
  return;
}

