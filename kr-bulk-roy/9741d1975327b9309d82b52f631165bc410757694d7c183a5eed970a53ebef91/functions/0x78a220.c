
void FUN_0078a220(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int local_5c;
  
  if ((param_1 != param_2) && (puVar11 = param_1 + 0x18, puVar11 != param_2)) {
    puVar9 = param_1 + 0x15;
    do {
      FUN_007852a0();
      uVar2 = puVar9[0x17];
      uVar3 = puVar9[0x18];
      uVar4 = puVar9[0x19];
      uVar5 = puVar9[0x1a];
      if (local_5c < (int)param_1[5]) {
        FUN_0078d750(param_1,puVar9 + 0x1b,param_1);
        FUN_00788f50();
        param_1[0x15] = uVar3;
        param_1[0x16] = uVar4;
        param_1[0x17] = uVar5;
        puVar10 = param_1;
      }
      else {
        iVar1 = puVar9[-0x10];
        puVar8 = puVar9 + -0x15;
        puVar7 = puVar9;
        puVar10 = puVar11;
        while (puVar6 = puVar8, local_5c < iVar1) {
          FUN_00788f50();
          puVar10[0x14] = puVar7[-1];
          puVar10[0x15] = *puVar7;
          puVar10[0x16] = puVar7[1];
          puVar10[0x17] = puVar7[2];
          iVar1 = puVar7[-0x28];
          puVar8 = puVar6 + -0x18;
          puVar7 = puVar7 + -0x18;
          puVar10 = puVar6;
        }
        FUN_00788f50();
        puVar10[0x15] = uVar3;
        puVar10[0x16] = uVar4;
        puVar10[0x17] = uVar5;
      }
      puVar11 = puVar11 + 0x18;
      puVar9 = puVar9 + 0x18;
      puVar10[0x14] = uVar2;
    } while (puVar11 != param_2);
  }
  return;
}

