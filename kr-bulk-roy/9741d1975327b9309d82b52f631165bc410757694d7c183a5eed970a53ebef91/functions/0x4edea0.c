
void FUN_004edea0(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,code *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char cVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar9 = param_2 + (((int)param_3 - (int)param_2) / 0x18) * 3;
  FUN_004ee160(puVar9,param_3 + -3,param_4);
  puVar1 = puVar9;
  while (puVar7 = puVar1, param_2 < puVar7) {
    puVar1 = puVar7 + -3;
    cVar5 = (*param_4)(puVar1,puVar7);
    if ((cVar5 != '\0') || (cVar5 = (*param_4)(puVar7,puVar1), cVar5 != '\0')) break;
  }
  do {
    puVar9 = puVar9 + 3;
    puVar1 = puVar9;
    local_8 = puVar9;
    local_c = puVar7;
    puVar10 = puVar7;
    if (param_3 <= puVar9) break;
    cVar5 = (*param_4)(puVar9,puVar7);
    if ((cVar5 != '\0') || (cVar5 = (*param_4)(puVar7,puVar9), cVar5 != '\0')) break;
  } while( true );
joined_r0x004edf53:
  puVar11 = puVar7;
  if (param_3 <= puVar1) {
joined_r0x004edfaf:
    while (puVar6 = puVar7, param_2 < puVar7) {
      puVar8 = puVar11 + -3;
      cVar5 = (*param_4)(puVar8,puVar10);
      puVar6 = puVar10;
      puVar9 = local_8;
      if (cVar5 == '\0') {
        cVar5 = (*param_4)(puVar10,puVar8);
        puVar6 = local_c;
        if (cVar5 != '\0') break;
        uVar2 = puVar10[-1];
        uVar3 = puVar10[-3];
        uVar4 = puVar10[-2];
        puVar6 = puVar10 + -3;
        *puVar6 = *puVar8;
        puVar10[-2] = puVar11[-2];
        puVar10[-1] = puVar11[-1];
        *puVar8 = uVar3;
        puVar11[-2] = uVar4;
        puVar11[-1] = uVar2;
      }
      local_c = local_c + -3;
      puVar11 = puVar8;
      puVar10 = puVar6;
      puVar7 = local_c;
    }
    if (puVar6 == param_2) {
      if (puVar1 == param_3) {
        *param_1 = puVar10;
        param_1[1] = puVar9;
        return;
      }
      if (puVar9 != puVar1) {
        uVar2 = puVar10[1];
        uVar3 = *puVar10;
        uVar4 = puVar10[2];
        *puVar10 = *puVar9;
        puVar10[1] = puVar9[1];
        puVar10[2] = puVar9[2];
        *puVar9 = uVar3;
        puVar9[1] = uVar2;
        puVar9[2] = uVar4;
      }
      uVar2 = *puVar10;
      uVar3 = puVar10[1];
      uVar4 = puVar10[2];
      *puVar10 = *puVar1;
      puVar10[1] = puVar1[1];
      puVar10[2] = puVar1[2];
      *puVar1 = uVar2;
      puVar1[1] = uVar3;
      puVar9 = puVar9 + 3;
      puVar1[2] = uVar4;
      puVar7 = puVar6;
      puVar1 = puVar1 + 3;
      local_8 = puVar9;
      puVar10 = puVar10 + 3;
    }
    else {
      puVar7 = puVar6 + -3;
      local_c = puVar7;
      if (puVar1 == param_3) {
        puVar11 = puVar10 + -3;
        if (puVar7 != puVar11) {
          uVar2 = puVar6[-2];
          uVar3 = *puVar7;
          uVar4 = puVar6[-1];
          *puVar7 = *puVar11;
          puVar6[-2] = puVar10[-2];
          puVar6[-1] = puVar10[-1];
          *puVar11 = uVar3;
          puVar10[-2] = uVar2;
          puVar10[-1] = uVar4;
        }
        uVar2 = puVar10[-2];
        uVar3 = *puVar11;
        uVar4 = puVar10[-1];
        local_8 = puVar9 + -3;
        *puVar11 = *local_8;
        puVar10[-2] = puVar9[-2];
        puVar10[-1] = puVar9[-1];
        *local_8 = uVar3;
        puVar9[-2] = uVar2;
        puVar9[-1] = uVar4;
        puVar9 = local_8;
        puVar10 = puVar11;
      }
      else {
        uVar2 = puVar1[1];
        uVar3 = *puVar1;
        uVar4 = puVar1[2];
        *puVar1 = *puVar7;
        puVar1[1] = puVar6[-2];
        puVar1[2] = puVar6[-1];
        *puVar7 = uVar3;
        puVar6[-2] = uVar2;
        puVar6[-1] = uVar4;
        puVar1 = puVar1 + 3;
      }
    }
    goto joined_r0x004edf53;
  }
  cVar5 = (*param_4)(puVar10,puVar1);
  puVar7 = local_c;
  if (cVar5 == '\0') {
    cVar5 = (*param_4)(puVar1,puVar10);
    puVar11 = local_c;
    local_8 = puVar9;
    if (cVar5 != '\0') goto joined_r0x004edfaf;
    uVar2 = puVar9[1];
    uVar3 = *puVar9;
    uVar4 = puVar9[2];
    *puVar9 = *puVar1;
    puVar9[1] = puVar1[1];
    puVar9[2] = puVar1[2];
    *puVar1 = uVar3;
    puVar1[1] = uVar2;
    puVar9 = puVar9 + 3;
    puVar1[2] = uVar4;
  }
  puVar1 = puVar1 + 3;
  local_8 = puVar9;
  goto joined_r0x004edf53;
}

