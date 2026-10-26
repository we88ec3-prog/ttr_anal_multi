
void FUN_008f3d30(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint unaff_EBX;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 1;
  uVar4 = uVar3;
  if (1 < unaff_EBX) {
joined_r0x008f3d44:
    do {
      if (uVar3 != 0) {
        iVar1 = *(int *)(in_ECX + -4 + uVar3 * 4);
        iVar2 = *(int *)(in_ECX + uVar3 * 4);
        if (iVar2 < iVar1) {
          uVar3 = uVar3 - 1;
          *(int *)(in_ECX + 4 + uVar3 * 4) = iVar1;
          *(int *)(in_ECX + uVar3 * 4) = iVar2;
          goto joined_r0x008f3d44;
        }
      }
      uVar3 = uVar4 + 1;
      uVar4 = uVar3;
    } while (uVar3 < unaff_EBX);
  }
  return;
}

