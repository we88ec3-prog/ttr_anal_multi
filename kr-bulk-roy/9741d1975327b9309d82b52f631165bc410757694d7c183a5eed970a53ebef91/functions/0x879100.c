
void FUN_00879100(void)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int unaff_EDI;
  float10 extraout_ST0;
  int local_20;
  int local_1c;
  float local_14;
  float local_10;
  float local_c;
  
  iVar3 = (*(int *)(unaff_EDI + 0x2c) - *(int *)(unaff_EDI + 0x28)) / 0xc;
  local_20 = 0;
  if (0 < iVar3 + -1) {
    local_1c = 0;
    do {
      uVar4 = FUN_008fed10();
      local_14 = (float)extraout_ST0;
      local_10 = (float)extraout_ST0;
      local_c = (float)extraout_ST0;
      if (*(int *)(unaff_EDI + 8) == 2) {
        FUN_00791e20(uVar4,&local_14);
      }
      else if (*(int *)(unaff_EDI + 8) == 4) {
        FUN_00791a80(uVar4,&local_14);
      }
      else {
        FUN_00791730(uVar4,&local_14,1);
      }
      iVar2 = *(int *)(unaff_EDI + 0x28);
      *(float *)(iVar2 + local_1c) = local_14;
      *(float *)(iVar2 + 4 + local_1c) = local_10;
      *(float *)(iVar2 + 8 + local_1c) = local_c;
      local_20 = local_20 + 1;
      local_1c = local_1c + 0xc;
    } while (local_20 < iVar3 + -1);
  }
  local_14 = 0.0;
  local_10 = 0.0;
  local_c = 0.0;
  if (*(int *)(unaff_EDI + 8) == 2) {
    FUN_00791e20(1000,&local_14);
  }
  else if (*(int *)(unaff_EDI + 8) == 4) {
    FUN_00791a80(1000,&local_14);
  }
  else {
    FUN_00791730(1000,&local_14,1);
  }
  pfVar1 = (float *)(*(int *)(unaff_EDI + 0x28) + -0xc + iVar3 * 0xc);
  *pfVar1 = local_14;
  pfVar1[1] = local_10;
  pfVar1[2] = local_c;
  return;
}

