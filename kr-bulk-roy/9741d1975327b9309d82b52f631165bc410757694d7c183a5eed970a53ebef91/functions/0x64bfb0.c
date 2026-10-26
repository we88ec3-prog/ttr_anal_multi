
void FUN_0064bfb0(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  float fVar5;
  float fVar6;
  float local_28;
  float local_24;
  float local_14;
  float local_10;
  
  iVar4 = (**(code **)(*DAT_00fba7a4 + 0x20))();
  fVar5 = (float)(*(int *)(unaff_ESI + 0x10) - *(int *)(unaff_ESI + 8));
  iVar3 = *(int *)(DAT_00fba838 + 0x40);
  fVar6 = (float)(*(int *)(unaff_ESI + 0x14) - *(int *)(unaff_ESI + 0xc));
  if (iVar3 == 0) {
    local_24 = 0.0;
    local_28 = 0.0;
  }
  else {
    local_24 = *(float *)(iVar3 + 0x158);
    local_28 = *(float *)(iVar3 + 0x15c);
  }
  fVar1 = *(float *)(iVar4 + 0xa0);
  fVar2 = *(float *)(iVar4 + 0xa4);
  local_10 = 0.0;
  local_14 = 0.0;
  if (fVar5 * 2.0 < local_24) {
    if (fVar1 + fVar5 <= local_24) {
      if (fVar1 - fVar5 < 0.0) {
        local_10 = fVar5 - fVar1;
      }
    }
    else {
      local_10 = local_24 - (fVar1 + fVar5);
    }
  }
  else {
    fVar1 = local_24 * 0.5;
  }
  if (fVar6 * 2.0 < local_28) {
    if (fVar2 + fVar6 <= local_28) {
      if (fVar2 - fVar6 < 0.0) {
        local_14 = fVar6 - fVar2;
      }
    }
    else {
      local_14 = local_28 - (fVar2 + fVar6);
    }
  }
  else {
    fVar2 = local_28 * 0.5;
  }
  *(float *)(unaff_ESI + 0xac) = local_10 + fVar1;
  *(float *)(unaff_ESI + 0xb0) = fVar2 + local_14;
  return;
}

