
void FUN_00841fc0(int param_1,float param_2,float param_3,float param_4)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  float *pfVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 local_64 [20];
  float local_14;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  iVar1 = (in_EAX - param_1) / 0x50;
  local_8 = iVar1 / 2;
  if (0 < local_8) {
    local_10 = local_8 * 2 + 2;
    local_c = (undefined4 *)(local_8 * 0x50 + param_1);
    do {
      local_c = local_c + -0x14;
      iVar3 = local_8 + -1;
      puVar5 = local_c;
      puVar7 = local_64;
      for (iVar6 = 0x14; iVar2 = iVar3, iVar8 = local_10 + -2, iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      for (; iVar8 < iVar1; iVar8 = iVar8 * 2 + 2) {
        pfVar4 = (float *)(iVar8 * 0x50 + param_1);
        local_14 = pfVar4[2] * param_4 + param_2 * *pfVar4 + pfVar4[1] * param_3;
        if (local_14 <
            pfVar4[-0x12] * param_4 +
            pfVar4[-0x14] * param_2 + *(float *)(iVar8 * 0x50 + -0x4c + param_1) * param_3) {
          iVar8 = iVar8 + -1;
        }
        puVar5 = (undefined4 *)(iVar8 * 0x50 + param_1);
        puVar7 = (undefined4 *)(iVar2 * 0x50 + param_1);
        if (puVar7 != puVar5) {
          *puVar7 = *puVar5;
          puVar7[1] = puVar5[1];
          puVar7[2] = puVar5[2];
          if (puVar7 + 3 != puVar5 + 3) {
            puVar7[6] = puVar5[6];
            puVar7[3] = puVar5[3];
            puVar7[4] = puVar5[4];
            puVar7[5] = puVar5[5];
          }
          puVar7[7] = puVar5[7];
          puVar7[8] = puVar5[8];
          puVar7[9] = puVar5[9];
          puVar7[10] = puVar5[10];
        }
        puVar7[0xb] = puVar5[0xb];
        puVar7[0xc] = puVar5[0xc];
        puVar7[0xd] = puVar5[0xd];
        puVar7[0xe] = puVar5[0xe];
        puVar7[0xf] = puVar5[0xf];
        puVar7[0x10] = puVar5[0x10];
        puVar7[0x11] = puVar5[0x11];
        puVar7[0x12] = puVar5[0x12];
        puVar7[0x13] = puVar5[0x13];
        iVar2 = iVar8;
      }
      if (iVar8 == iVar1) {
        puVar5 = (undefined4 *)(param_1 + -0x50 + iVar1 * 0x50);
        puVar7 = (undefined4 *)(iVar2 * 0x50 + param_1);
        if (puVar7 != puVar5) {
          *puVar7 = *puVar5;
          puVar7[1] = puVar5[1];
          puVar7[2] = puVar5[2];
          if (puVar7 + 3 != puVar5 + 3) {
            puVar7[6] = puVar5[6];
            puVar7[3] = puVar5[3];
            puVar7[4] = puVar5[4];
            puVar7[5] = puVar5[5];
          }
          puVar7[7] = puVar5[7];
          puVar7[8] = puVar5[8];
          puVar7[9] = puVar5[9];
          puVar7[10] = puVar5[10];
        }
        puVar7[0xb] = puVar5[0xb];
        puVar7[0xc] = puVar5[0xc];
        puVar7[0xd] = puVar5[0xd];
        puVar7[0xe] = puVar5[0xe];
        puVar7[0xf] = puVar5[0xf];
        puVar7[0x10] = puVar5[0x10];
        puVar7[0x11] = puVar5[0x11];
        puVar7[0x12] = puVar5[0x12];
        puVar7[0x13] = puVar5[0x13];
      }
      local_10 = local_10 + -2;
      local_8 = iVar3;
      FUN_00842c30(param_1,iVar3,param_2,param_3,param_4);
    } while (0 < local_8);
  }
  return;
}

