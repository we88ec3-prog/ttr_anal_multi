
void FUN_007ead30(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 *puVar5;
  int *piVar6;
  char *pcVar7;
  uint *puVar8;
  undefined4 uVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  double dVar13;
  undefined1 local_98 [12];
  undefined1 local_8c [12];
  undefined1 local_80 [20];
  uint local_6c;
  undefined4 local_68;
  int local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  int *local_3c;
  float local_38;
  uint local_34;
  uint local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091c688;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_64 = param_1;
  local_14 = uVar2;
  if ((param_2 != 0) && (local_3c = (int *)FUN_0072e2e0("Object"), local_3c != (int *)0x0)) {
    local_68 = 1;
    do {
      piVar11 = local_3c;
      local_1c = 0xf;
      local_20 = 0;
      local_30 = local_30 & 0xffffff00;
      local_8 = 0;
      local_38 = 0.0;
      uVar12 = 0;
      local_34 = 0;
      iVar3 = (**(code **)(*local_3c + 0x14))(uVar2);
      if (iVar3 != 0) {
        iVar3 = FUN_007300a0(&DAT_00c408c0);
        if (iVar3 == 0) {
          pcVar7 = (char *)0x0;
        }
        else if (*(uint *)(iVar3 + 0x44) < 0x10) {
          pcVar7 = (char *)(iVar3 + 0x30);
        }
        else {
          pcVar7 = *(char **)(iVar3 + 0x30);
        }
        pcVar4 = pcVar7;
        do {
          cVar1 = *pcVar4;
          pcVar4 = pcVar4 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar7,(int)pcVar4 - (int)(pcVar7 + 1));
        iVar3 = FUN_007300a0("Handle");
        if (iVar3 != 0) {
          puVar5 = (undefined4 *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          if (puVar5 != (undefined4 *)0x0) {
            uVar12 = FUN_008917b4(puVar5);
            local_34 = uVar12;
            goto LAB_007eae32;
          }
        }
        uVar12 = 0;
        local_34 = uVar12;
      }
LAB_007eae32:
      for (piVar10 = (int *)piVar11[6]; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
        piVar6 = piVar10 + 8;
        if (0xf < (uint)piVar10[0xd]) {
          piVar6 = (int *)*piVar6;
        }
        iVar3 = __stricmp((char *)piVar6,"Position");
        if (iVar3 == 0) {
          if (piVar10 != (int *)0x0) {
            (**(code **)(*piVar10 + 0x14))();
            puVar5 = (undefined4 *)FUN_007e3f30(local_80);
            local_54 = *puVar5;
            local_50 = puVar5[1];
            local_4c = puVar5[2];
          }
          break;
        }
      }
      for (piVar10 = (int *)piVar11[6]; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
        piVar6 = piVar10 + 8;
        if (0xf < (uint)piVar10[0xd]) {
          piVar6 = (int *)*piVar6;
        }
        iVar3 = __stricmp((char *)piVar6,"Rotation");
        if (iVar3 == 0) {
          if (piVar10 != (int *)0x0) {
            (**(code **)(*piVar10 + 0x14))();
            puVar5 = (undefined4 *)FUN_007e3f30(local_98);
            local_60 = *puVar5;
            local_5c = puVar5[1];
            local_58 = puVar5[2];
          }
          break;
        }
      }
      for (piVar10 = (int *)piVar11[6]; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
        piVar6 = piVar10 + 8;
        if (0xf < (uint)piVar10[0xd]) {
          piVar6 = (int *)*piVar6;
        }
        iVar3 = __stricmp((char *)piVar6,"Scale");
        if (iVar3 == 0) {
          if (piVar10 != (int *)0x0) {
            (**(code **)(*piVar10 + 0x14))();
            puVar5 = (undefined4 *)FUN_007e3f30(local_8c);
            local_48 = *puVar5;
            local_44 = puVar5[1];
            local_40 = puVar5[2];
          }
          break;
        }
      }
      for (piVar11 = (int *)piVar11[6]; piVar11 != (int *)0x0; piVar11 = (int *)piVar11[0x10]) {
        piVar10 = piVar11 + 8;
        if (0xf < (uint)piVar11[0xd]) {
          piVar10 = (int *)*piVar10;
        }
        iVar3 = __stricmp((char *)piVar10,"Speed");
        if (iVar3 == 0) {
          if ((piVar11 == (int *)0x0) || (iVar3 = (**(code **)(*piVar11 + 0x14))(), iVar3 == 0))
          break;
          iVar3 = FUN_007300a0("Ratio");
          if (iVar3 != 0) {
            pcVar7 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              dVar13 = _atof(pcVar7);
              local_38 = (float)dVar13;
              uVar12 = local_34;
              break;
            }
          }
          local_38 = 0.0;
          uVar12 = local_34;
          break;
        }
      }
      iVar3 = local_64;
      FUN_007b9160(*(undefined4 *)(local_64 + 4),local_54,local_50,local_4c,local_60,local_5c,
                   local_58,local_48,local_44,local_40,local_38,uVar12);
      if (*(uint *)(iVar3 + 0x2c) < uVar12) {
        *(uint *)(iVar3 + 0x2c) = uVar12;
      }
      puVar8 = (uint *)FUN_007b88a0();
      local_6c = uVar12;
      uVar9 = FUN_0057ef20();
      FUN_0082f200(puVar8 + 1,uVar9);
      if (*puVar8 < local_34) {
        *puVar8 = local_34;
      }
      for (piVar11 = (int *)local_3c[0x10]; piVar11 != (int *)0x0; piVar11 = (int *)piVar11[0x10]) {
        piVar10 = piVar11 + 8;
        if (0xf < (uint)piVar11[0xd]) {
          piVar10 = (int *)*piVar10;
        }
        iVar3 = __stricmp((char *)piVar10,"Object");
        if (iVar3 == 0) goto LAB_007eb08b;
      }
      piVar11 = (int *)0x0;
LAB_007eb08b:
      local_8 = 0xffffffff;
      local_3c = piVar11;
      if (0xf < local_1c) {
        FUN_0089120c(local_30);
      }
    } while (piVar11 != (int *)0x0);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

