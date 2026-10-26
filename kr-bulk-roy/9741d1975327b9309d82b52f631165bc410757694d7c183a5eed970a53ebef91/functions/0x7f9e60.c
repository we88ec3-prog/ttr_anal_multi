
void FUN_007f9e60(void)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar4 = 0;
  if (*(int *)(in_ECX + 0xcc) != 0) {
    iVar3 = 0;
    do {
      iVar1 = *(int *)(in_ECX + 200);
      if (*(char *)(iVar3 + 0x58 + iVar1) == '\0') {
        puVar5 = (undefined4 *)(*(int *)(in_ECX + 0xcc) * 0x5c + -0x5c + iVar1);
        puVar6 = (undefined4 *)(iVar3 + iVar1);
        for (iVar2 = 0x17; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        *(undefined1 *)(*(int *)(in_ECX + 0xcc) * 0x5c + -4 + *(int *)(in_ECX + 200)) = 0;
        *(int *)(in_ECX + 0xcc) = *(int *)(in_ECX + 0xcc) + -1;
      }
      uVar4 = uVar4 + 1;
      iVar3 = iVar3 + 0x5c;
    } while (uVar4 < *(uint *)(in_ECX + 0xcc));
  }
  return;
}

