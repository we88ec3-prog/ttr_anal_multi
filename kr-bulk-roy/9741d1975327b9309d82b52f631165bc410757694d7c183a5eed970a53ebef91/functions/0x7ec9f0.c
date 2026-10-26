
void FUN_007ec9f0(void)

{
  int iVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  int *piVar9;
  undefined4 *puVar10;
  int in_ECX;
  uint uVar11;
  double dVar12;
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_164;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  float local_134;
  float local_12c;
  float local_124;
  bool local_11d;
  char local_11c [264];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009146be;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  piVar4 = (int *)FUN_0072e2e0();
  do {
    if (piVar4 == (int *)0x0) {
      ExceptionList = local_10;
      __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
      return;
    }
    local_12c = 1.0;
    local_124 = 0.0;
    local_11d = false;
    uVar11 = 0;
    local_134 = 1.0;
    iVar5 = (**(code **)(*piVar4 + 0x14))();
    if (iVar5 != 0) {
      iVar1 = iVar5 + 0x44;
      for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar1; iVar8 = *(int *)(iVar8 + 0x50)) {
        pcVar7 = (char *)(iVar8 + 0x14);
        if (0xf < *(uint *)(iVar8 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar6 = __stricmp(pcVar7,"StartAtBottom");
        if (iVar6 == 0) {
          if (iVar8 != 0) {
            pcVar7 = (char *)(iVar8 + 0x30);
            if (0xf < *(uint *)(iVar8 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              iVar8 = __stricmp(pcVar7,"true");
              local_11d = iVar8 == 0;
              goto LAB_007ecabe;
            }
          }
          break;
        }
      }
      local_11d = false;
LAB_007ecabe:
      for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar1; iVar8 = *(int *)(iVar8 + 0x50)) {
        pcVar7 = (char *)(iVar8 + 0x14);
        if (0xf < *(uint *)(iVar8 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar6 = __stricmp(pcVar7,"ParticleFile");
        if (iVar6 == 0) {
          if (iVar8 != 0) {
            pcVar7 = (char *)(iVar8 + 0x30);
            if (0xf < *(uint *)(iVar8 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            goto LAB_007ecaee;
          }
          break;
        }
      }
      pcVar7 = (char *)0x0;
LAB_007ecaee:
      iVar8 = -(int)pcVar7;
      do {
        cVar2 = *pcVar7;
        pcVar7[(int)(local_11c + iVar8)] = cVar2;
        pcVar7 = pcVar7 + 1;
      } while (cVar2 != '\0');
      for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar1; iVar8 = *(int *)(iVar8 + 0x50)) {
        pcVar7 = (char *)(iVar8 + 0x14);
        if (0xf < *(uint *)(iVar8 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar6 = __stricmp(pcVar7,"ParticleSize");
        if (iVar6 == 0) {
          if (iVar8 != 0) {
            pcVar7 = (char *)(iVar8 + 0x30);
            if (0xf < *(uint *)(iVar8 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              dVar12 = _atof(pcVar7);
              local_12c = (float)dVar12;
              goto LAB_007ecb36;
            }
          }
          break;
        }
      }
      local_12c = 0.0;
LAB_007ecb36:
      for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar1; iVar8 = *(int *)(iVar8 + 0x50)) {
        pcVar7 = (char *)(iVar8 + 0x14);
        if (0xf < *(uint *)(iVar8 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar6 = __stricmp(pcVar7,"ParticleCount");
        if (iVar6 == 0) {
          if (iVar8 != 0) {
            puVar10 = (undefined4 *)(iVar8 + 0x30);
            if (0xf < *(uint *)(iVar8 + 0x44)) {
              puVar10 = (undefined4 *)*puVar10;
            }
            if (puVar10 != (undefined4 *)0x0) {
              FUN_008917b4();
            }
          }
          break;
        }
      }
      for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar1; iVar8 = *(int *)(iVar8 + 0x50)) {
        pcVar7 = (char *)(iVar8 + 0x14);
        if (0xf < *(uint *)(iVar8 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar6 = __stricmp(pcVar7,"Scale");
        if (iVar6 == 0) {
          if (iVar8 != 0) {
            pcVar7 = (char *)(iVar8 + 0x30);
            if (0xf < *(uint *)(iVar8 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              dVar12 = _atof(pcVar7);
              local_124 = (float)dVar12;
              goto LAB_007ecba7;
            }
          }
          break;
        }
      }
      local_124 = 0.0;
LAB_007ecba7:
      local_134 = local_124;
      for (iVar8 = *(int *)(iVar5 + 0x94); iVar8 != iVar1; iVar8 = *(int *)(iVar8 + 0x50)) {
        pcVar7 = (char *)(iVar8 + 0x14);
        if (0xf < *(uint *)(iVar8 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar6 = __stricmp(pcVar7,"TerminalVelocity");
        if (iVar6 == 0) {
          if (iVar8 != 0) {
            pcVar7 = (char *)(iVar8 + 0x30);
            if (0xf < *(uint *)(iVar8 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              dVar12 = _atof(pcVar7);
              local_124 = (float)dVar12;
              goto LAB_007ecbef;
            }
          }
          break;
        }
      }
      local_124 = 0.0;
LAB_007ecbef:
      for (iVar5 = *(int *)(iVar5 + 0x94); iVar5 != iVar1; iVar5 = *(int *)(iVar5 + 0x50)) {
        pcVar7 = (char *)(iVar5 + 0x14);
        if (0xf < *(uint *)(iVar5 + 0x28)) {
          pcVar7 = *(char **)pcVar7;
        }
        iVar8 = __stricmp(pcVar7,"UseAddState");
        if (iVar8 == 0) {
          if (iVar5 != 0) {
            pcVar7 = (char *)(iVar5 + 0x30);
            if (0xf < *(uint *)(iVar5 + 0x44)) {
              pcVar7 = *(char **)pcVar7;
            }
            if (pcVar7 != (char *)0x0) {
              iVar5 = __stricmp(pcVar7,"true");
              uVar11 = (uint)(iVar5 == 0);
              goto LAB_007ecc25;
            }
          }
          break;
        }
      }
      uVar11 = 0;
    }
LAB_007ecc25:
    for (piVar3 = (int *)piVar4[6]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar9 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar9 = (int *)*piVar9;
      }
      iVar5 = __stricmp((char *)piVar9,"BoundSize");
      if (iVar5 == 0) {
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x14))();
          FUN_007e3f30();
        }
        break;
      }
    }
    for (piVar3 = (int *)piVar4[6]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar9 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar9 = (int *)*piVar9;
      }
      iVar5 = __stricmp((char *)piVar9,"Position");
      if (iVar5 == 0) {
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x14))();
          FUN_007e3f30();
          goto LAB_007eccaf;
        }
        break;
      }
    }
    local_14c = 0;
    local_148 = 0;
    local_144 = 0;
LAB_007eccaf:
    for (piVar3 = (int *)piVar4[6]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar9 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar9 = (int *)*piVar9;
      }
      iVar5 = __stricmp((char *)piVar9,"Rotation");
      if (iVar5 == 0) {
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x14))();
          FUN_007e3f30();
          goto LAB_007eccf2;
        }
        break;
      }
    }
    local_164 = 0;
    local_160 = 0;
    local_15c = 0;
LAB_007eccf2:
    for (piVar3 = (int *)piVar4[6]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar9 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar9 = (int *)*piVar9;
      }
      iVar5 = __stricmp((char *)piVar9,"Velocity");
      if (iVar5 == 0) {
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x14))();
          FUN_007e3f30();
        }
        break;
      }
    }
    for (piVar3 = (int *)piVar4[6]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar9 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar9 = (int *)*piVar9;
      }
      iVar5 = __stricmp((char *)piVar9,"VelocityDelta");
      if (iVar5 == 0) {
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x14))();
          FUN_007e3f30();
        }
        break;
      }
    }
    for (piVar3 = (int *)piVar4[6]; piVar3 != (int *)0x0; piVar3 = (int *)piVar3[0x10]) {
      piVar9 = piVar3 + 8;
      if (0xf < (uint)piVar3[0xd]) {
        piVar9 = (int *)*piVar9;
      }
      iVar5 = __stricmp((char *)piVar9,"Acceleration");
      if (iVar5 == 0) {
        if (piVar3 != (int *)0x0) {
          (**(code **)(*piVar3 + 0x14))();
          FUN_007e3f30();
          goto LAB_007ecdc2;
        }
        break;
      }
    }
    local_17c = 0;
    local_178 = 0;
    local_174 = 0;
LAB_007ecdc2:
    iVar5 = FUN_00891268();
    local_8 = 0;
    if (iVar5 == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = FUN_007f89b0(iVar5,local_12c);
    }
    local_8 = 0xffffffff;
    *(undefined4 *)(iVar5 + 0x24) = local_14c;
    *(undefined4 *)(iVar5 + 0x28) = local_148;
    *(undefined4 *)(iVar5 + 0x2c) = local_144;
    FUN_007f9280();
    *(undefined4 *)(iVar5 + 0x30) = local_164;
    *(undefined4 *)(iVar5 + 0x34) = local_160;
    *(undefined4 *)(iVar5 + 0x38) = local_15c;
    FUN_007f9280();
    *(float *)(iVar5 + 0x3c) = local_134;
    FUN_007f9280();
    *(float *)(iVar5 + 0x124) = local_124;
    *(undefined4 *)(iVar5 + 0x118) = local_17c;
    *(uint *)(iVar5 + 0xfc) = (uint)local_11d;
    *(undefined4 *)(iVar5 + 0x11c) = local_178;
    pcVar7 = local_11c;
    *(undefined4 *)(iVar5 + 0x120) = local_174;
    do {
      cVar2 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
    FUN_00402a70();
    *(uint *)(iVar5 + 0x128) = uVar11;
    *(int *)(in_ECX + 0x10) = iVar5;
    piVar4 = (int *)piVar4[0x10];
  } while( true );
}

