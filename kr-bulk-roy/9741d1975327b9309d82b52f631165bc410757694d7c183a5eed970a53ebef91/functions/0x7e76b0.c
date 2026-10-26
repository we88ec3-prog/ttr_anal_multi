
void FUN_007e76b0(undefined2 *param_1,int param_2,int *param_3)

{
  undefined2 *puVar1;
  uint uVar2;
  undefined2 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int unaff_ESI;
  uint uVar9;
  
  iVar4 = FUN_008fed10();
  iVar5 = FUN_008fed10();
  uVar9 = ((int)(iVar5 - 1U) < 0) - 1 & iVar5 - 1U;
  iVar6 = FUN_008fed10();
  iVar7 = FUN_008fed10();
  iVar5 = iVar6 + 1;
  if (*(int *)(unaff_ESI + 0x150) < iVar6 + 1) {
    iVar5 = *(int *)(unaff_ESI + 0x150);
  }
  iVar6 = *(int *)(unaff_ESI + 0x154);
  if (iVar7 + 1 <= *(int *)(unaff_ESI + 0x154)) {
    iVar6 = iVar7 + 1;
  }
  puVar1 = param_1 + param_2;
  *param_3 = 0;
  do {
    uVar2 = ((int)(iVar4 - 1U) < 0) - 1 & iVar4 - 1U;
    puVar3 = param_1;
    if (iVar6 <= (int)uVar9) {
      return;
    }
    for (; (int)uVar2 < iVar5; uVar2 = uVar2 + 1) {
      if (puVar1 <= puVar3 + 6) {
        return;
      }
      iVar8 = *(int *)(unaff_ESI + 0x150) * uVar9 + uVar2;
      iVar7 = iVar8 * 0xc;
      *param_1 = *(undefined2 *)(iVar7 + *(int *)(unaff_ESI + 0x178));
      param_1[1] = *(undefined2 *)(*(int *)(unaff_ESI + 0x178) + 2 + iVar7);
      param_1[2] = *(undefined2 *)(*(int *)(unaff_ESI + 0x178) + 4 + iVar7);
      *param_3 = *param_3 + 1;
      iVar7 = (iVar8 * 6 + 3) * 2;
      param_1[3] = *(undefined2 *)(iVar7 + *(int *)(unaff_ESI + 0x178));
      param_1[4] = *(undefined2 *)(*(int *)(unaff_ESI + 0x178) + 2 + iVar7);
      param_1[5] = *(undefined2 *)(*(int *)(unaff_ESI + 0x178) + 4 + iVar7);
      *param_3 = *param_3 + 1;
      param_1 = param_1 + 6;
      puVar3 = puVar3 + 6;
    }
    uVar9 = uVar9 + 1;
  } while( true );
}

