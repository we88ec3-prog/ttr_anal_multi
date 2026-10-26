
int FUN_00719d80(void)

{
  undefined1 uVar1;
  int iVar2;
  uint3 uVar3;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0xc);
  uVar3 = (uint3)((uint)iVar2 >> 8);
  if (*(int *)(in_ECX + 8) < iVar2 + 1) {
    *(undefined1 *)(in_ECX + 0x10) = 1;
    return (uint)uVar3 << 8;
  }
  uVar1 = *(undefined1 *)(iVar2 + *(int *)(in_ECX + 4));
  *(int *)(in_ECX + 0xc) = iVar2 + 1;
  return CONCAT31(uVar3,uVar1);
}

