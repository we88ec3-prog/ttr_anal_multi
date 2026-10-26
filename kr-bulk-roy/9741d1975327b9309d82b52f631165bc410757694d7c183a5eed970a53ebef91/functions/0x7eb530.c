
void FUN_007eb530(int param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  float *pfVar6;
  int *piVar7;
  char *pcVar8;
  uint uVar9;
  int *piVar10;
  int *piVar11;
  char *pcVar12;
  int iVar13;
  int *in_EDX;
  undefined4 *puVar14;
  bool bVar15;
  bool bVar16;
  float10 fVar17;
  double dVar18;
  undefined4 local_180 [26];
  undefined4 local_118 [4];
  undefined4 local_108;
  float local_104;
  float local_100;
  float local_fc;
  float local_f8;
  undefined4 local_f4;
  undefined4 local_f0;
  undefined4 local_ec;
  undefined4 local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  undefined4 local_dc;
  undefined4 local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  int *local_cc;
  float local_c4;
  float local_c0;
  float local_bc;
  uint local_b0;
  uint local_ac;
  uint local_a8;
  uint local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int local_5c;
  int local_58;
  int *local_54;
  float local_50;
  float local_4c;
  float local_48;
  float local_44;
  int local_40;
  bool local_3a;
  bool local_39;
  int *local_38;
  uint local_34;
  uint local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009146f8;
  local_10 = ExceptionList;
  local_18 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_5c = param_1;
  local_54 = in_EDX;
  if (in_EDX == (int *)0x0) goto LAB_007ebe0a;
  iVar3 = (**(code **)(*in_EDX + 0x14))(local_18);
  if (iVar3 != 0) {
    iVar3 = FUN_007300a0("BaseAmbient");
    if (iVar3 == 0) {
LAB_007eb5b5:
      uVar5 = 0;
    }
    else {
      puVar4 = (undefined4 *)(iVar3 + 0x30);
      if (0xf < *(uint *)(iVar3 + 0x44)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) goto LAB_007eb5b5;
      uVar5 = FUN_008917b4(puVar4);
    }
    iVar13 = local_40;
    iVar3 = *(int *)(*(int *)(local_5c + 4) + 0x54);
    if (*(int *)(iVar3 + 0xc) == local_40) {
      pfVar6 = *(float **)(local_40 + 8);
      if (pfVar6 == (float *)0x0) {
        pfVar6 = (float *)FUN_00891268(0x34);
        if (pfVar6 == (float *)0x0) {
          pfVar6 = (float *)0x0;
        }
        else {
          pfVar6[4] = 0.0;
          pfVar6[5] = 0.0;
          pfVar6[6] = 0.0;
          pfVar6[7] = 0.0;
          pfVar6[9] = 0.0;
          pfVar6[10] = 0.0;
          pfVar6[0xb] = 0.0;
        }
        *(float **)(local_40 + 8) = pfVar6;
      }
      local_50 = (float)(uVar5 >> 0x10 & 0xff) * 0.003921569;
      local_38 = (int *)(uVar5 >> 0x18);
      local_4c = (float)(uVar5 >> 8 & 0xff) * 0.003921569;
      *pfVar6 = local_50;
      pfVar6[1] = local_4c;
      local_48 = (float)(uVar5 & 0xff) * 0.003921569;
      pfVar6[2] = local_48;
      local_44 = (float)(int)local_38 * 0.003921569;
      pfVar6[3] = local_44;
    }
    else {
      pfVar6 = *(float **)(local_40 + 8);
      if (pfVar6 == (float *)0x0) {
        if (*(int *)(*(int *)(iVar3 + 0xc) + 8) == 0) {
          MessageBoxA((HWND)0x0,&DAT_00c50714,"Critical Error",0);
        }
        else {
          FUN_007f3c70(local_40);
          pfVar6 = *(float **)(iVar13 + 8);
        }
      }
      local_50 = (float)(uVar5 >> 0x10 & 0xff) * 0.003921569;
      local_38 = (int *)(uVar5 >> 0x18);
      local_4c = (float)(uVar5 >> 8 & 0xff) * 0.003921569;
      *pfVar6 = local_50;
      pfVar6[1] = local_4c;
      local_48 = (float)(uVar5 & 0xff) * 0.003921569;
      pfVar6[2] = local_48;
      local_44 = (float)(int)local_38 * 0.003921569;
      pfVar6[3] = local_44;
    }
  }
  local_58 = 0;
  for (piVar7 = (int *)FUN_0072e2e0("Light"); piVar7 != (int *)0x0; piVar7 = (int *)piVar7[0x10]) {
    local_b0 = 1;
    local_ac = 1;
    local_a8 = 1;
    local_a4 = 1;
    local_38 = piVar7;
    _memset(local_180,0,0x68);
    pcVar2 = *(code **)(*piVar7 + 0x14);
    puVar4 = local_180;
    puVar14 = local_118;
    for (iVar3 = 0x1a; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar14 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar14 = puVar14 + 1;
    }
    iVar3 = (*pcVar2)();
    if (iVar3 != 0) {
      iVar3 = FUN_007300a0(&DAT_00c408b8);
      if (iVar3 == 0) {
        pcVar12 = (char *)0x0;
      }
      else {
        pcVar12 = (char *)(iVar3 + 0x30);
        if (0xf < *(uint *)(iVar3 + 0x44)) {
          pcVar12 = *(char **)pcVar12;
        }
      }
      local_20 = 0xf;
      local_24 = 0;
      local_34 = local_34 & 0xffffff00;
      pcVar8 = pcVar12;
      do {
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar12,(int)pcVar8 - (int)(pcVar12 + 1));
      uVar5 = local_24;
      local_8 = 0;
      uVar9 = local_24;
      if (10 < local_24) {
        uVar9 = 0xb;
      }
      iVar3 = FUN_00407e70(uVar9);
      bVar15 = false;
      if (iVar3 == 0) {
        if (uVar5 < 0xb) {
          uVar9 = 0xffffffff;
        }
        else {
          uVar9 = (uint)(uVar5 != 0xb);
        }
        bVar15 = uVar9 == 0;
      }
      if (bVar15) {
        local_118[0] = 3;
        piVar10 = (int *)FUN_0072e2e0("Direction");
        if (piVar10 == (int *)0x0) {
          local_a0 = 0;
          local_9c = 0;
          local_98 = 0;
        }
        else {
          (**(code **)(*piVar10 + 0x14))();
          FUN_007e3f30(&local_a0);
        }
      }
      else {
        uVar9 = uVar5;
        if (4 < uVar5) {
          uVar9 = 5;
        }
        iVar3 = FUN_00407e70(uVar9);
        bVar15 = false;
        if (iVar3 == 0) {
          if (uVar5 < 5) {
            uVar5 = 0xffffffff;
          }
          else {
            uVar5 = (uint)(uVar5 != 5);
          }
          bVar15 = uVar5 == 0;
        }
        if (bVar15) {
          local_118[0] = 1;
          piVar10 = (int *)FUN_0072e2e0("Position");
          if (piVar10 == (int *)0x0) {
            local_68 = 0;
            local_64 = 0;
            local_60 = 0;
          }
          else {
            (**(code **)(*piVar10 + 0x14))();
            FUN_007e3f30(&local_68);
          }
          local_e4 = local_68;
          local_e0 = local_64;
          local_dc = local_60;
          (**(code **)(*piVar7 + 0x14))();
          iVar3 = FUN_007300a0("Range");
          if (iVar3 == 0) {
LAB_007eb935:
            local_54 = (int *)0x0;
          }
          else {
            pcVar12 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            if (pcVar12 == (char *)0x0) goto LAB_007eb935;
            dVar18 = _atof(pcVar12);
            local_54 = (int *)(float)dVar18;
          }
          local_cc = local_54;
          piVar10 = (int *)FUN_0072e2e0("Attenuation");
          if ((piVar10 != (int *)0x0) && (iVar3 = (**(code **)(*piVar10 + 0x14))(), iVar3 != 0)) {
            fVar17 = (float10)FUN_0072e690(0);
            local_c4 = (float)fVar17;
            fVar17 = (float10)FUN_0072e690(0);
            local_c0 = (float)fVar17;
            fVar17 = (float10)FUN_0072e690(0);
            local_bc = (float)fVar17;
          }
        }
      }
      local_8 = 0xffffffff;
      if (0xf < local_20) {
        FUN_0089120c(local_34);
      }
    }
    for (piVar10 = (int *)piVar7[6]; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
      piVar11 = piVar10 + 8;
      if (0xf < (uint)piVar10[0xd]) {
        piVar11 = (int *)*piVar11;
      }
      iVar3 = __stricmp((char *)piVar11,"Ambient");
      if (iVar3 == 0) {
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 0x14))();
          FUN_007f1470(&local_94);
          goto LAB_007eba11;
        }
        break;
      }
    }
    local_94 = 0;
    local_90 = 0;
    local_8c = 0;
    local_88 = 0;
LAB_007eba11:
    piVar10 = (int *)piVar7[6];
    local_f4 = local_94;
    local_f0 = local_90;
    local_ec = local_8c;
    local_e8 = local_88;
    for (; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
      piVar11 = piVar10 + 8;
      if (0xf < (uint)piVar10[0xd]) {
        piVar11 = (int *)*piVar11;
      }
      iVar3 = __stricmp((char *)piVar11,"Diffuse");
      if (iVar3 == 0) {
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 0x14))();
          FUN_007f1470(&local_84);
          goto LAB_007eba7d;
        }
        break;
      }
    }
    local_84 = 0;
    local_80 = 0;
    local_7c = 0;
    local_78 = 0;
LAB_007eba7d:
    piVar10 = (int *)piVar7[6];
    local_118[1] = local_84;
    local_118[2] = local_80;
    local_118[3] = local_7c;
    local_108 = local_78;
    for (; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
      piVar11 = piVar10 + 8;
      if (0xf < (uint)piVar10[0xd]) {
        piVar11 = (int *)*piVar11;
      }
      iVar3 = __stricmp((char *)piVar11,"Specular");
      if (iVar3 == 0) {
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 0x14))();
          FUN_007f1470(&local_50);
          goto LAB_007ebadd;
        }
        break;
      }
    }
    local_50 = 0.0;
    local_4c = 0.0;
    local_48 = 0.0;
    local_44 = 0.0;
LAB_007ebadd:
    piVar10 = (int *)piVar7[6];
    local_104 = local_50;
    local_100 = local_4c;
    local_fc = local_48;
    local_f8 = local_44;
    for (; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
      piVar11 = piVar10 + 8;
      if (0xf < (uint)piVar10[0xd]) {
        piVar11 = (int *)*piVar11;
      }
      iVar3 = __stricmp((char *)piVar11,"Direction");
      if (iVar3 == 0) {
        if (piVar10 != (int *)0x0) {
          (**(code **)(*piVar10 + 0x14))();
          FUN_007e3f30(&local_74);
          goto LAB_007ebb3a;
        }
        break;
      }
    }
    local_74 = 0;
    local_70 = 0;
    local_6c = 0;
LAB_007ebb3a:
    piVar10 = (int *)piVar7[6];
    local_d8 = local_74;
    local_d4 = local_70;
    local_d0 = local_6c;
    for (; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[0x10]) {
      piVar11 = piVar10 + 8;
      if (0xf < (uint)piVar10[0xd]) {
        piVar11 = (int *)*piVar11;
      }
      iVar3 = __stricmp((char *)piVar11,"Affection");
      if (iVar3 == 0) {
        if ((piVar10 != (int *)0x0) && (iVar3 = (**(code **)(*piVar10 + 0x14))(), iVar3 != 0)) {
          iVar3 = FUN_007300a0("Character");
          if (iVar3 == 0) {
LAB_007ebc6a:
            local_3a = false;
          }
          else {
            pcVar12 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            if (pcVar12 == (char *)0x0) goto LAB_007ebc6a;
            iVar3 = __stricmp(pcVar12,"true");
            local_3a = iVar3 == 0;
          }
          iVar3 = FUN_007300a0("Field");
          if (iVar3 == 0) {
LAB_007ebca0:
            local_39 = false;
          }
          else {
            pcVar12 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            if (pcVar12 == (char *)0x0) goto LAB_007ebca0;
            iVar3 = __stricmp(pcVar12,"true");
            local_39 = iVar3 == 0;
          }
          iVar3 = FUN_007300a0("Lightmap");
          if (iVar3 == 0) {
LAB_007ebcd5:
            bVar15 = false;
          }
          else {
            pcVar12 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            if (pcVar12 == (char *)0x0) goto LAB_007ebcd5;
            iVar3 = __stricmp(pcVar12,"true");
            bVar15 = iVar3 == 0;
          }
          iVar3 = FUN_007300a0("FieldObject");
          if (iVar3 == 0) {
LAB_007ebd09:
            bVar16 = false;
          }
          else {
            pcVar12 = (char *)(iVar3 + 0x30);
            if (0xf < *(uint *)(iVar3 + 0x44)) {
              pcVar12 = *(char **)pcVar12;
            }
            if (pcVar12 == (char *)0x0) goto LAB_007ebd09;
            iVar3 = __stricmp(pcVar12,"true");
            bVar16 = iVar3 == 0;
          }
          local_b0 = (uint)local_3a;
          local_a4 = (uint)local_39;
          local_ac = (uint)bVar15;
          local_a8 = (uint)bVar16;
          piVar7 = local_38;
        }
        break;
      }
    }
    iVar13 = local_40;
    iVar3 = *(int *)(*(int *)(*(int *)(local_5c + 4) + 0x54) + 0xc);
    if (iVar3 == local_40) {
      iVar3 = *(int *)(local_40 + 8);
      if (iVar3 == 0) {
        iVar3 = FUN_00891268(0x34);
        if (iVar3 != 0) {
          *(undefined4 *)(iVar3 + 0x10) = 0;
          *(undefined4 *)(iVar3 + 0x14) = 0;
          *(undefined4 *)(iVar3 + 0x18) = 0;
          *(undefined4 *)(iVar3 + 0x1c) = 0;
          *(undefined4 *)(iVar3 + 0x24) = 0;
          *(undefined4 *)(iVar3 + 0x28) = 0;
          *(undefined4 *)(iVar3 + 0x2c) = 0;
          *(int *)(iVar13 + 8) = iVar3;
          puVar4 = (undefined4 *)FUN_007f3f10(iVar3,local_118[0]);
          goto LAB_007ebde7;
        }
        iVar3 = 0;
        *(undefined4 *)(iVar13 + 8) = 0;
      }
      puVar4 = (undefined4 *)FUN_007f3f10(iVar3,local_118[0]);
    }
    else {
      iVar13 = *(int *)(local_40 + 8);
      if (iVar13 == 0) {
        iVar3 = *(int *)(iVar3 + 8);
        if (iVar3 == 0) {
          MessageBoxA((HWND)0x0,&DAT_00c50714,"Critical Error",0);
        }
        else {
          iVar13 = FUN_007f3e80();
          FUN_007f40b0(iVar13,iVar3);
          *(int *)(local_40 + 8) = iVar13;
        }
      }
      puVar4 = *(undefined4 **)(*(int *)(iVar13 + 0x24) + local_58 * 4);
    }
LAB_007ebde7:
    local_58 = local_58 + 1;
    puVar14 = local_118;
    for (iVar3 = 0x1e; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar14;
      puVar14 = puVar14 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  local_38 = (int *)0x0;
LAB_007ebe0a:
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

