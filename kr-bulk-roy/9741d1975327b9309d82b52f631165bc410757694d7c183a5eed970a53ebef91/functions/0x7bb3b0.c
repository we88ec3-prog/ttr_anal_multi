
void FUN_007bb3b0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  float10 fVar8;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  double local_14;
  int *local_c;
  undefined4 *local_8;
  
  iVar5 = (int)param_3 - (int)param_1;
  puVar3 = param_3;
  do {
    if (iVar5 >> 2 < 0x21) {
      FUN_007bb790(puVar3,param_4,param_5,param_6);
      return;
    }
    local_18 = param_6;
    param_3 = param_1 + (iVar5 >> 2) / 2;
    local_20 = param_4;
    local_1c = param_5;
    FUN_007bb6a0(param_3,puVar3 + -1,param_4,param_5,param_6);
    puVar7 = param_3 + 1;
    local_8 = puVar7;
    if (param_1 < param_3) {
      while( true ) {
        local_c = (int *)*param_3;
        fVar8 = (float10)(**(code **)(*(int *)param_3[-1] + 8))(&local_20);
        local_14 = (double)fVar8;
        fVar8 = (float10)(**(code **)(*local_c + 8))(&local_20);
        if ((float10)local_14 < fVar8) break;
        local_c = (int *)param_3[-1];
        fVar8 = (float10)(**(code **)(*(int *)*param_3 + 8))(&local_20);
        local_14 = (double)fVar8;
        fVar8 = (float10)(**(code **)(*local_c + 8))(&local_20);
        if (((float10)local_14 < fVar8) || (param_3 = param_3 + -1, param_3 <= param_1)) break;
      }
    }
    puVar4 = local_8;
    puVar6 = param_3;
    if (puVar7 < puVar3) {
      while( true ) {
        piVar1 = (int *)*param_3;
        fVar8 = (float10)(**(code **)(*(int *)*puVar7 + 8))(&local_20);
        local_14 = (double)fVar8;
        fVar8 = (float10)(**(code **)(*piVar1 + 8))(&local_20);
        puVar4 = puVar7;
        if ((float10)local_14 < fVar8) break;
        piVar1 = (int *)*puVar7;
        fVar8 = (float10)(**(code **)(*(int *)*param_3 + 8))(&local_20);
        local_14 = (double)fVar8;
        fVar8 = (float10)(**(code **)(*piVar1 + 8))(&local_20);
        if (((float10)local_14 < fVar8) || (puVar7 = puVar7 + 1, puVar4 = puVar7, puVar3 <= puVar7))
        break;
      }
    }
joined_r0x007bb4e3:
    local_8 = puVar4;
    if (puVar7 < puVar3) {
      local_c = (int *)*puVar7;
      fVar8 = (float10)(**(code **)(*(int *)*param_3 + 8))(&local_20);
      local_14 = (double)fVar8;
      fVar8 = (float10)(**(code **)(*local_c + 8))(&local_20);
      if (fVar8 <= (float10)local_14) {
        local_c = (int *)*param_3;
        fVar8 = (float10)(**(code **)(*(int *)*puVar7 + 8))(&local_20);
        local_14 = (double)fVar8;
        fVar8 = (float10)(**(code **)(*local_c + 8))(&local_20);
        if ((float10)local_14 < fVar8) goto joined_r0x007bb55d;
        uVar2 = *local_8;
        *local_8 = *puVar7;
        *puVar7 = uVar2;
        local_8 = local_8 + 1;
      }
      puVar7 = puVar7 + 1;
      puVar4 = local_8;
      goto joined_r0x007bb4e3;
    }
joined_r0x007bb55d:
    for (; param_1 < puVar6; puVar6 = puVar6 + -1) {
      local_c = (int *)*param_3;
      fVar8 = (float10)(**(code **)(*(int *)puVar6[-1] + 8))(&local_20);
      local_14 = (double)fVar8;
      fVar8 = (float10)(**(code **)(*local_c + 8))(&local_20);
      if (fVar8 <= (float10)local_14) {
        local_c = (int *)puVar6[-1];
        fVar8 = (float10)(**(code **)(*(int *)*param_3 + 8))(&local_20);
        local_14 = (double)fVar8;
        fVar8 = (float10)(**(code **)(*local_c + 8))(&local_20);
        if ((float10)local_14 < fVar8) break;
        uVar2 = param_3[-1];
        param_3 = param_3 + -1;
        *param_3 = puVar6[-1];
        puVar6[-1] = uVar2;
      }
    }
    if (puVar6 != param_1) {
      puVar6 = puVar6 + -1;
      if (puVar7 == puVar3) {
        param_3 = param_3 + -1;
        if (puVar6 != param_3) {
          uVar2 = *puVar6;
          *puVar6 = *param_3;
          *param_3 = uVar2;
        }
        uVar2 = *param_3;
        *param_3 = local_8[-1];
        local_8[-1] = uVar2;
        puVar4 = local_8 + -1;
      }
      else {
        uVar2 = *puVar7;
        *puVar7 = *puVar6;
        *puVar6 = uVar2;
        puVar7 = puVar7 + 1;
        puVar4 = local_8;
      }
      goto joined_r0x007bb4e3;
    }
    if (puVar7 != puVar3) {
      if (local_8 != puVar7) {
        uVar2 = *param_3;
        *param_3 = *local_8;
        *local_8 = uVar2;
      }
      local_c = (int *)*param_3;
      *param_3 = *puVar7;
      param_3 = param_3 + 1;
      *puVar7 = local_c;
      puVar7 = puVar7 + 1;
      puVar4 = local_8 + 1;
      goto joined_r0x007bb4e3;
    }
    if (param_2 < local_8) {
      if (param_3 <= param_2) {
        return;
      }
    }
    else {
      param_1 = local_8;
      param_3 = puVar3;
    }
    iVar5 = (int)param_3 - (int)param_1;
    puVar3 = param_3;
  } while( true );
}

