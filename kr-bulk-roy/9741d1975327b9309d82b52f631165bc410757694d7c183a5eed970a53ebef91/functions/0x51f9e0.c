
void FUN_0051f9e0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  char cVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_30 [4];
  undefined4 *local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d258;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar2 = param_2 + (((int)param_3 - (int)param_2) / 0x28) * 5;
  FUN_0051fe70(puVar2,param_3 + -5,param_4,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  puVar8 = puVar2;
  while (puVar6 = puVar8, param_2 < puVar6) {
    local_18 = puVar6 + -5;
    cVar3 = (*param_4)(local_18,puVar6);
    if ((cVar3 != '\0') || (cVar3 = (*param_4)(puVar6,local_18), puVar8 = local_18, cVar3 != '\0'))
    break;
  }
  do {
    puVar2 = puVar2 + 5;
    puVar8 = puVar2;
    local_14 = puVar6;
    if (param_3 <= puVar2) break;
    cVar3 = (*param_4)(puVar2,puVar6);
    if ((cVar3 != '\0') || (cVar3 = (*param_4)(puVar6,puVar2), cVar3 != '\0')) break;
  } while( true );
joined_r0x0051fa9e:
  if (param_3 <= puVar8) {
LAB_0051fb1f:
    if (param_2 < local_14) {
      local_18 = local_14 + -5;
      puVar5 = puVar6;
      do {
        cVar3 = (*param_4)(local_18,puVar5);
        puVar6 = puVar5;
        if (cVar3 == '\0') {
          cVar3 = (*param_4)(puVar5,local_18);
          if (cVar3 != '\0') break;
          uVar1 = puVar5[-5];
          puVar6 = puVar5 + -5;
          local_1c = puVar5 + -4;
          FUN_004fcd00(local_30,local_1c);
          local_8 = 1;
          *puVar6 = *local_18;
          FUN_004fcdc0(local_18 + 1);
          *local_18 = uVar1;
          FUN_004fcdc0(local_30);
          local_8 = 0xffffffff;
          if (local_30[0] != 0) {
            FUN_0089120c(local_30[0]);
          }
        }
        local_18 = local_18 + -5;
        local_14 = local_14 + -5;
        puVar5 = puVar6;
      } while (param_2 < local_14);
    }
    if (local_14 == param_2) {
      if (puVar8 == param_3) {
        *param_1 = puVar6;
        param_1[1] = puVar2;
        ExceptionList = local_10;
        return;
      }
      if (puVar2 != puVar8) {
        uVar1 = *puVar6;
        FUN_004fcd00(local_30,puVar6 + 1);
        local_8 = 2;
        *puVar6 = *puVar2;
        FUN_004fcdc0(puVar2 + 1);
        *puVar2 = uVar1;
        FUN_004fcdc0(local_30);
        local_8 = 0xffffffff;
        if (local_30[0] != 0) {
          FUN_0089120c(local_30[0]);
        }
      }
      uVar1 = *puVar6;
      local_20 = puVar6 + 1;
      puVar5 = puVar2 + 5;
      puVar7 = puVar6 + 5;
      local_1c = puVar6;
      local_18 = puVar8;
      FUN_004fcd00(local_30,local_20);
      local_8 = 3;
      *local_1c = *local_18;
      local_1c = local_18 + 1;
      FUN_004fcdc0(local_18 + 1);
      *local_18 = uVar1;
      puVar8 = puVar8 + 5;
    }
    else {
      puVar5 = local_14 + -5;
      if (puVar8 != param_3) {
        uVar1 = *puVar8;
        local_14 = puVar5;
        FUN_004fcd00(local_30,puVar8 + 1);
        local_8 = 6;
        local_20 = local_14 + 1;
        *puVar8 = *local_14;
        FUN_004fcdc0(local_20);
        *local_14 = uVar1;
        FUN_004fcdc0(local_30);
        local_8 = 0xffffffff;
        if (local_30[0] != 0) {
          FUN_0089120c(local_30[0]);
        }
        puVar8 = puVar8 + 5;
        goto joined_r0x0051fa9e;
      }
      puVar7 = puVar6 + -5;
      if (puVar5 != puVar7) {
        uVar1 = *puVar5;
        puVar4 = local_14 + -4;
        local_14 = puVar5;
        FUN_004fcd00(local_30,puVar4);
        local_8 = 4;
        *local_14 = *puVar7;
        FUN_004fcdc0(puVar6 + -4);
        *puVar7 = uVar1;
        FUN_004fcdc0(local_30);
        local_8 = 0xffffffff;
        puVar5 = local_14;
        if (local_30[0] != 0) {
          FUN_0089120c(local_30[0]);
          puVar5 = local_14;
        }
      }
      local_14 = puVar5;
      uVar1 = *puVar7;
      puVar5 = puVar2 + -5;
      FUN_004fcd00(local_30,puVar6 + -4);
      local_8 = 5;
      *puVar7 = *puVar5;
      local_20 = puVar2 + -4;
      FUN_004fcdc0(local_20);
      *puVar5 = uVar1;
    }
    FUN_004fcdc0(local_30);
    local_8 = 0xffffffff;
    puVar2 = puVar5;
    puVar6 = puVar7;
    if (local_30[0] != 0) {
      FUN_0089120c(local_30[0]);
    }
    goto joined_r0x0051fa9e;
  }
  cVar3 = (*param_4)(puVar6,puVar8);
  puVar5 = puVar2;
  if (cVar3 == '\0') {
    cVar3 = (*param_4)(puVar8,puVar6);
    if (cVar3 != '\0') goto LAB_0051fb1f;
    uVar1 = *puVar2;
    local_1c = puVar2 + 1;
    puVar5 = puVar2 + 5;
    local_18 = puVar2;
    FUN_004fcd00(local_30,local_1c);
    local_8 = 0;
    *local_18 = *puVar8;
    FUN_004fcdc0(puVar8 + 1);
    *puVar8 = uVar1;
    FUN_004fcdc0(local_30);
    local_8 = 0xffffffff;
    if (local_30[0] != 0) {
      FUN_0089120c(local_30[0]);
    }
  }
  puVar2 = puVar5;
  puVar8 = puVar8 + 5;
  goto joined_r0x0051fa9e;
}

