
undefined4 FUN_007ec080(int param_1)

{
  undefined1 **ppuVar1;
  undefined1 **ppuVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  char *pcVar6;
  int *piVar7;
  int *piVar8;
  int in_ECX;
  double dVar9;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined1 *local_18 [4];
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  local_18[3] = &LAB_009187cb;
  local_18[2] = ExceptionList;
  if (in_ECX == 0) {
    return 0;
  }
  ExceptionList = local_18 + 2;
  FUN_007b8f30(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  piVar3 = (int *)FUN_0072e2e0("Camera");
joined_r0x007ec0e1:
  do {
    if (piVar3 == (int *)0x0) {
      ExceptionList = local_18[2];
      return 1;
    }
    puVar4 = (undefined4 *)FUN_00891268(0x48);
    local_8 = 0;
    local_18[0] = (undefined1 *)puVar4;
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      *puVar4 = 0;
      puVar4[1] = 0;
      puVar4[2] = 0;
      puVar4[3] = 0x3fc90fdb;
      puVar4[4] = 0;
      puVar4[5] = 0;
      puVar4[6] = 0;
      puVar4[7] = 0;
      puVar4[8] = 0x3f800000;
      puVar4[9] = 0x43fa0000;
      puVar4[10] = 0x3f91361e;
      puVar4[0x10] = 0xf;
      puVar4[0xf] = 0;
      *(undefined1 *)(puVar4 + 0xb) = 0;
      FUN_00402a70("Default",7);
    }
    local_8 = 0xffffffff;
    iVar5 = (**(code **)(*piVar3 + 0x14))();
    if (iVar5 != 0) {
      iVar5 = FUN_007300a0(&DAT_00c507ec);
      if (iVar5 == 0) {
LAB_007ec1a4:
        local_18[0] = (undefined1 *)0x0;
      }
      else {
        pcVar6 = (char *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          pcVar6 = *(char **)pcVar6;
        }
        if (pcVar6 == (char *)0x0) goto LAB_007ec1a4;
        dVar9 = _atof(pcVar6);
        local_18[0] = (undefined1 *)(float)dVar9;
      }
      puVar4[10] = local_18[0];
      iVar5 = FUN_007300a0("VisionDistance");
      if (iVar5 == 0) {
LAB_007ec1da:
        local_18[0] = (undefined1 *)0x0;
      }
      else {
        pcVar6 = (char *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          pcVar6 = *(char **)pcVar6;
        }
        if (pcVar6 == (char *)0x0) goto LAB_007ec1da;
        dVar9 = _atof(pcVar6);
        local_18[0] = (undefined1 *)(float)dVar9;
      }
      puVar4[9] = local_18[0];
      iVar5 = FUN_007300a0("PivotRange");
      if (iVar5 == 0) {
LAB_007ec210:
        local_18[0] = (undefined1 *)0x0;
      }
      else {
        pcVar6 = (char *)(iVar5 + 0x30);
        if (0xf < *(uint *)(iVar5 + 0x44)) {
          pcVar6 = *(char **)pcVar6;
        }
        if (pcVar6 == (char *)0x0) goto LAB_007ec210;
        dVar9 = _atof(pcVar6);
        local_18[0] = (undefined1 *)(float)dVar9;
      }
      puVar4[6] = local_18[0];
    }
    for (piVar8 = (int *)piVar3[6]; piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x10]) {
      piVar7 = piVar8 + 8;
      if (0xf < (uint)piVar8[0xd]) {
        piVar7 = (int *)*piVar7;
      }
      iVar5 = __stricmp((char *)piVar7,"Position");
      if (iVar5 == 0) {
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 0x14))();
          FUN_007e3f30(&local_2c);
          goto LAB_007ec255;
        }
        break;
      }
    }
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
LAB_007ec255:
    *puVar4 = local_2c;
    puVar4[1] = local_28;
    puVar4[2] = local_24;
    for (piVar8 = (int *)piVar3[6]; piVar8 != (int *)0x0; piVar8 = (int *)piVar8[0x10]) {
      piVar7 = piVar8 + 8;
      if (0xf < (uint)piVar8[0xd]) {
        piVar7 = (int *)*piVar7;
      }
      iVar5 = __stricmp((char *)piVar7,"Direction");
      if (iVar5 == 0) {
        if (piVar8 != (int *)0x0) {
          (**(code **)(*piVar8 + 0x14))();
          FUN_007f13c0(&local_20);
          goto LAB_007ec29c;
        }
        break;
      }
    }
    local_20 = 0;
    local_1c = 0;
LAB_007ec29c:
    puVar4[5] = local_20;
    puVar4[3] = local_1c;
    iVar5 = *(int *)(param_1 + 4);
    ppuVar1 = *(undefined1 ***)(iVar5 + 0x48);
    local_18[0] = (undefined1 *)puVar4;
    if (local_18 < ppuVar1) {
      ppuVar2 = *(undefined1 ***)(iVar5 + 0x44);
      if (local_18 < ppuVar2) goto LAB_007ec32a;
      if (ppuVar1 == *(undefined1 ***)(iVar5 + 0x4c)) {
        FUN_00797930();
      }
      if (*(undefined4 **)(iVar5 + 0x48) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar5 + 0x48) =
             *(undefined4 *)(*(int *)(iVar5 + 0x44) + ((int)local_18 - (int)ppuVar2 >> 2) * 4);
      }
    }
    else {
LAB_007ec32a:
      if (ppuVar1 == *(undefined1 ***)(iVar5 + 0x4c)) {
        FUN_00797930();
      }
      if (*(undefined4 **)(iVar5 + 0x48) != (undefined4 *)0x0) {
        **(undefined4 **)(iVar5 + 0x48) = puVar4;
      }
    }
    *(int *)(iVar5 + 0x48) = *(int *)(iVar5 + 0x48) + 4;
    for (piVar3 = (int *)piVar3[0x10]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar8 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar8 = (int *)*piVar8;
      }
      iVar5 = __stricmp((char *)piVar8,"Camera");
      if (iVar5 == 0) goto joined_r0x007ec0e1;
    }
    piVar3 = (int *)0x0;
  } while( true );
}

