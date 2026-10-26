
uint FUN_00768190(void)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x110);
  iVar3 = *(int *)(in_ECX + 0x114);
  if (iVar2 == iVar3) {
    return CONCAT31((int3)((uint)iVar3 >> 8),1);
  }
  puVar4 = *(uint **)(iVar2 + -4 + (iVar3 - iVar2 >> 2) * 4);
  puVar1 = puVar4 + 4;
  if (*puVar1 != 0) {
    if (7 < puVar4[5]) {
      puVar4 = (uint *)*puVar4;
    }
    return CONCAT31((int3)((uint)puVar4 >> 8),*(short *)(((int)puVar4 - 2U) + *puVar1 * 2) == 10);
  }
  return (uint)puVar4 & 0xffffff00;
}

