
void FUN_007d89b0(uint param_1,float param_2)

{
  float *pfVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 auStack_54 [15];
  undefined4 uStack_18;
  int local_14;
  
  iVar5 = param_1;
  local_14 = param_1;
  uStack_18 = 0x7d89bf;
  FUN_007d8a50();
  pfVar1 = (float *)(param_1 + 0x74);
  piVar2 = (int *)(param_1 + 0x60);
  piVar3 = (int *)(param_1 + 0x5c);
  param_1 = 0;
  param_2 = (1.0 / *pfVar1) * param_2;
  if (*piVar2 - *piVar3 >> 2 != 0) {
    do {
      piVar2 = *(int **)(*(int *)(iVar5 + 0x5c) + param_1 * 4);
      if ((float)piVar2[0x20] <= *(float *)(iVar5 + 0x6c)) {
        local_14 = *(undefined4 *)(iVar5 + 0x18);
        uStack_18 = 0x7d8a06;
        (**(code **)(*piVar2 + 8))();
        iVar4 = **(int **)(*(int *)(iVar5 + 0x5c) + param_1 * 4);
        puVar7 = (undefined4 *)(iVar5 + 0x1c);
        puVar8 = auStack_54;
        for (iVar6 = 0x10; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        (**(code **)(iVar4 + 4))(param_2);
      }
      param_1 = param_1 + 1;
    } while (param_1 < (uint)(*(int *)(iVar5 + 0x60) - *(int *)(iVar5 + 0x5c) >> 2));
  }
  *(float *)(iVar5 + 0x6c) = *(float *)(iVar5 + 0x6c) + param_2;
  return;
}

