
void FUN_007f40b0(int param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  iVar3 = *(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 2;
  if ((iVar3 == *(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x24) >> 2) && (uVar4 = 0, iVar3 != 0)
     ) {
    do {
      puVar1 = *(undefined4 **)(*(int *)(param_2 + 0x24) + uVar4 * 4);
      puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x24) + uVar4 * 4);
      puVar5 = puVar1;
      puVar6 = puVar2;
      for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      puVar2[0x1f] = puVar1[0x1f];
      puVar2[0x1e] = puVar1[0x1e];
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(*(int *)(param_1 + 0x28) - *(int *)(param_1 + 0x24) >> 2));
  }
  return;
}

