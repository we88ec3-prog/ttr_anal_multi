
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0086ad30(int param_1,int param_2,int param_3,float *param_4,undefined4 param_5)

{
  float fVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  float10 extraout_ST0;
  undefined4 auStack_d4 [16];
  undefined4 uStack_94;
  int iStack_90;
  undefined4 *puStack_8c;
  int iStack_88;
  float local_84;
  int local_70;
  undefined4 local_60 [23];
  
  if ((*(float *)(param_2 + 0x98) < *(float *)(param_2 + 0xa0) ==
       (*(float *)(param_2 + 0x98) == *(float *)(param_2 + 0xa0))) ||
     (*(float *)(param_2 + 0x9c) <= *(float *)(param_2 + 0xa0))) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (*(float *)(param_2 + 0x98) < *(float *)(param_2 + 0xa0) ==
      (*(float *)(param_2 + 0x98) == *(float *)(param_2 + 0xa0))) {
    fVar1 = 0.0;
  }
  else {
    fVar1 = (*(float *)(param_2 + 0xa0) - *(float *)(param_2 + 0x98)) /
            (*(float *)(param_2 + 0x9c) - *(float *)(param_2 + 0x98));
  }
  if (*(int *)(param_1 + 0x33c) == 0) {
    if ((*(int *)(param_2 + 0xa8) != 0) && (bVar2)) {
      iStack_88 = 0x86ae40;
      local_84 = fVar1;
      FUN_00879260();
      local_84 = 1.2368508e-38;
      local_70 = FUN_008fed10();
      local_60[10] = 1;
      *param_4 = (float)(extraout_ST0 - (float10)local_70);
      local_60[0] = 0;
      local_60[1] = 0;
      local_60[2] = 0;
      local_60[3] = 0;
      local_60[4] = 0;
      local_60[5] = 0;
      local_60[6] = 0x3f800000;
      local_60[7] = 0x3f800000;
      local_60[8] = 0x3f800000;
      local_60[9] = 0x3f800000;
      local_60[0xb] = 0;
      local_60[0xc] = 0;
      local_60[0xd] = 0;
      if (0 < local_70) {
        do {
          iStack_88 = param_5;
          puStack_8c = local_60;
          iStack_90 = param_1;
          uStack_94 = 0x86aecd;
          local_84 = fVar1;
          FUN_0086af50();
          puVar4 = local_60;
          puVar5 = auStack_d4;
          for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar5 = *puVar4;
            puVar4 = puVar4 + 1;
            puVar5 = puVar5 + 1;
          }
          FUN_0086be90();
          local_70 = local_70 + -1;
        } while (local_70 != 0);
      }
    }
  }
  else if (((*(int *)(param_2 + 0xa8) != 0) && (bVar2)) && (*(int *)(param_3 + 4) == 0)) {
    local_84 = 1.2368327e-38;
    FUN_0086af10();
    iStack_88 = param_5;
    puStack_8c = local_60;
    iStack_90 = param_1;
    uStack_94 = 0x86adfa;
    local_84 = fVar1;
    FUN_0086af50();
    puVar4 = local_60;
    puVar5 = auStack_d4;
    for (iVar3 = 0x15; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    FUN_0086be90();
  }
  local_84 = (float)param_5;
  iStack_88 = param_3;
  puStack_8c = (undefined4 *)param_2;
  iStack_90 = param_1;
  uStack_94 = 0x86aefd;
  FUN_0086b490();
  return;
}

