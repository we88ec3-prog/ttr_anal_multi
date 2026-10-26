
void FUN_007ee110(void)

{
  int iVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  undefined4 *unaff_EDI;
  float local_8;
  
  local_8 = 0.0;
  uVar4 = 0;
  if ((int)(unaff_EDI[4] - unaff_EDI[3]) >> 2 != 0) {
    iVar3 = unaff_EDI[3];
    do {
      (**(code **)(**(int **)(iVar3 + uVar4 * 4) + 0xc))();
      iVar3 = unaff_EDI[3];
      iVar1 = *(int *)(iVar3 + uVar4 * 4);
      fVar2 = *(float *)(iVar1 + 0x3c) + *(float *)(iVar1 + 0x38);
      if (local_8 < fVar2) {
        local_8 = fVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < (uint)(unaff_EDI[4] - iVar3 >> 2));
  }
  *unaff_EDI = 1;
  unaff_EDI[7] = local_8;
  return;
}

