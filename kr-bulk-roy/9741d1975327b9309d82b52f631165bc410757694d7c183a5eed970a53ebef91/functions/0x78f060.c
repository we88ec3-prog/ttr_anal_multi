
void FUN_0078f060(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  undefined4 *local_8;
  
  if ((param_1 != param_2) && (local_8 = param_1 + 7, local_8 != param_2)) {
    puVar7 = param_1 + 9;
    do {
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0x3f800000;
      if (&local_20 != puVar7 + -1) {
        local_14 = puVar7[2];
        local_20 = puVar7[-1];
        local_1c = *puVar7;
        local_18 = puVar7[1];
      }
      iVar2 = puVar7[3];
      local_c = puVar7[4];
      if (iVar2 < (int)param_1[5]) {
        local_10 = iVar2;
        FUN_007907c0(param_1);
        if (param_1 + 1 != &local_20) {
          param_1[4] = local_14;
          param_1[1] = local_20;
          param_1[2] = local_1c;
          param_1[3] = local_18;
        }
        param_1[5] = iVar2;
        param_1[6] = local_c;
      }
      else {
        iVar1 = puVar7[-4];
        puVar6 = puVar7 + -9;
        puVar4 = local_8;
        puVar5 = puVar7;
        while (puVar3 = puVar6, iVar2 < iVar1) {
          if (puVar4 + 1 != puVar5 + -8) {
            puVar4[4] = puVar5[-5];
            puVar4[1] = puVar5[-8];
            puVar4[2] = puVar5[-7];
            puVar4[3] = puVar5[-6];
          }
          puVar4[5] = puVar5[-4];
          puVar4[6] = puVar5[-3];
          iVar1 = puVar5[-0xb];
          puVar6 = puVar3 + -7;
          puVar4 = puVar3;
          puVar5 = puVar5 + -7;
        }
        if (puVar4 + 1 != &local_20) {
          puVar4[4] = local_14;
          puVar4[1] = local_20;
          puVar4[2] = local_1c;
          puVar4[3] = local_18;
        }
        puVar4[5] = iVar2;
        puVar4[6] = local_c;
      }
      local_8 = local_8 + 7;
      puVar7 = puVar7 + 7;
    } while (local_8 != param_2);
  }
  return;
}

