
void FUN_0071cf80(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 8) == *(int *)(unaff_ESI + 0xc)) {
    uVar2 = *(int *)(unaff_ESI + 0xc) - *(int *)(unaff_ESI + 4) >> 3;
    iVar3 = FUN_0071be00(*(int *)(unaff_ESI + 4),uVar2 * 8);
    *(uint *)(unaff_ESI + 0xc) = ((uVar2 >> 1) + 1 + uVar2) * 8 + iVar3;
    *(uint *)(unaff_ESI + 8) = uVar2 * 8 + iVar3;
    *(int *)(unaff_ESI + 4) = iVar3;
  }
  puVar1 = *(undefined4 **)(unaff_ESI + 8);
  *puVar1 = *param_1;
  puVar1[1] = param_1[1];
  *(int *)(unaff_ESI + 8) = *(int *)(unaff_ESI + 8) + 8;
  return;
}

