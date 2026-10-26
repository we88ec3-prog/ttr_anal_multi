
void FUN_004c9140(int param_1,int param_2)

{
  float fVar1;
  float fVar2;
  int in_EAX;
  uint unaff_EDI;
  int iVar3;
  undefined4 uVar4;
  float local_18;
  float local_14;
  float local_10;
  
  iVar3 = *(int *)(param_1 + 0x15c);
  if (iVar3 == 0) {
    return;
  }
  if (*(int *)(param_1 + 0x370) == 0) {
    return;
  }
  if (in_EAX != 0) {
    if (in_EAX == 1) {
      if (unaff_EDI == 0) {
        FUN_007a7bf0(0x3fd9999a,0,0,0x3f800000);
        FUN_007a7cc0(*(undefined4 *)(param_1 + 0x15c),1);
        return;
      }
      if (unaff_EDI == param_2 - 1U) goto LAB_004c91ee;
      fVar1 = (float)(int)unaff_EDI;
      if ((int)unaff_EDI < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      local_14 = (float)param_2;
      if (param_2 < 0) {
        local_14 = local_14 + 4.2949673e+09;
      }
      local_14 = (fVar1 * 0.5) / local_14;
      if (0.5 < local_14) {
        local_14 = 0.5;
      }
      local_18 = 1.7;
      local_10 = local_14;
    }
    else {
      if (in_EAX != 2) {
        if (in_EAX == 3) {
          return;
        }
        if (in_EAX != 4) {
          if (in_EAX != 10) {
            return;
          }
          if (unaff_EDI != 0) {
            if (unaff_EDI != param_2 - 1U) {
              fVar1 = (float)param_2;
              if (param_2 < 0) {
                fVar1 = fVar1 + 4.2949673e+09;
              }
              FUN_007a7bf0(0x3f800000,0x3f800000,0x3f800000,
                           1.0 - (float)(int)(((int)(unaff_EDI - 0x14) < 1) - 1 & unaff_EDI - 0x14)
                                 / fVar1);
              return;
            }
            fVar1 = (float)((float10)0.003921568859368563 * (float10)0.0);
            FUN_007a7bf0(fVar1,fVar1,fVar1,fVar1);
            return;
          }
          FUN_007a7e70(iVar3);
          FUN_007a7cc0(*(undefined4 *)(param_1 + 0x15c),0);
          return;
        }
        if (unaff_EDI == 0) {
          FUN_007a7e70(iVar3);
          FUN_007a7cc0(*(undefined4 *)(param_1 + 0x15c),1);
        }
        goto LAB_004c91e2;
      }
      if (unaff_EDI == 0) {
        FUN_007a7bf0(0,0x3f800000,0,0x3f800000);
        goto LAB_004c9328;
      }
      if (unaff_EDI == param_2 - 1U) goto LAB_004c91ee;
      fVar1 = (float)(int)unaff_EDI;
      if ((int)unaff_EDI < 0) {
        fVar1 = fVar1 + 4.2949673e+09;
      }
      fVar2 = (float)param_2;
      if (param_2 < 0) {
        fVar2 = fVar2 + 4.2949673e+09;
      }
      local_18 = (fVar1 / 1.6) / fVar2 + 0.3;
      if (1.0 < local_18) {
        local_18 = 1.0;
      }
      local_14 = 1.0;
      local_10 = local_18;
    }
    FUN_007a7bf0(local_18,local_14,local_10,0x3f800000);
    if (1 < unaff_EDI) {
      return;
    }
LAB_004c9328:
    FUN_007a7cc0(*(undefined4 *)(param_1 + 0x15c),1);
    return;
  }
  if (unaff_EDI == 0) {
    FUN_007a7bf0(0x3fd9999a,0x3fd9999a,0x3fd9999a,0x3f800000);
    iVar3 = *(int *)(param_1 + 0x15c);
    uVar4 = 1;
LAB_004c91d7:
    FUN_007a7cc0(iVar3,uVar4);
  }
  else if (unaff_EDI == 2) {
    uVar4 = 0;
    goto LAB_004c91d7;
  }
LAB_004c91e2:
  if (unaff_EDI != param_2 - 1U) {
    return;
  }
LAB_004c91ee:
  FUN_007a7eb0();
  return;
}

