
undefined4 FUN_007a7b30(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float fVar3;
  int iVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  float10 fVar6;
  
  if (((*(int *)(unaff_EDI + 0xac) != 0) && (*(int *)(unaff_EDI + 0x1c) != 0)) &&
     (*(int *)(*(int *)(unaff_EDI + 0x1c) + 0x14) != 0)) {
    iVar4 = (**(code **)(**(int **)(unaff_EDI + 0xac) + 0x40))();
    if ((*(char *)(iVar4 + 0x20) != '\0') || (param_2 != 0)) {
      puVar5 = (undefined4 *)FUN_007d4430();
      *param_1 = *puVar5;
      param_1[1] = puVar5[1];
      param_1[2] = puVar5[2];
      return 1;
    }
  }
  iVar4 = *(int *)(unaff_EDI + 0x1c);
  if (iVar4 != 0) {
    uVar1 = *(undefined4 *)(iVar4 + 0x28);
    uVar2 = *(undefined4 *)(iVar4 + 0x2c);
    fVar3 = *(float *)(iVar4 + 0x30);
    fVar6 = (float10)FUN_007a7100();
    *param_1 = uVar1;
    param_1[1] = uVar2;
    param_1[2] = (float)(fVar6 * (float10)0.5 + (float10)fVar3);
    return 1;
  }
  return 0;
}

