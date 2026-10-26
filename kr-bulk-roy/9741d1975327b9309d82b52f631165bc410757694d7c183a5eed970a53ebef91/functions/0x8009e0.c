
undefined4 FUN_008009e0(float param_1,undefined4 *param_2)

{
  uint **ppuVar1;
  uint **ppuVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  float fVar5;
  undefined4 *puVar6;
  float fVar7;
  float fVar8;
  int *piVar9;
  int iVar10;
  uint *puVar11;
  int iVar12;
  int iVar13;
  int *_Str1;
  char *pcVar14;
  int iVar15;
  double dVar16;
  float local_14;
  float local_10;
  int local_c;
  uint *local_8;
  
  if (param_2 == (undefined4 *)0x0) {
    return 1;
  }
  piVar9 = (int *)FUN_0072e2e0("GravitonPoint");
joined_r0x00800a03:
  if (piVar9 != (int *)0x0) {
    iVar10 = (**(code **)(*piVar9 + 0x14))();
    puVar11 = (uint *)FUN_00891268(0x34);
    if (puVar11 == (uint *)0x0) {
      puVar11 = (uint *)0x0;
    }
    else {
      *puVar11 = (uint)IS3D::CGravitonPoint::vftable;
    }
    iVar15 = iVar10 + 0x44;
    for (iVar13 = *(int *)(iVar10 + 0x94); iVar13 != iVar15; iVar13 = *(int *)(iVar13 + 0x50)) {
      pcVar14 = (char *)(iVar13 + 0x14);
      if (0xf < *(uint *)(iVar13 + 0x28)) {
        pcVar14 = *(char **)pcVar14;
      }
      iVar12 = __stricmp(pcVar14,"Z");
      if (iVar12 == 0) {
        if (iVar13 != 0) {
          pcVar14 = (char *)(iVar13 + 0x30);
          if (0xf < *(uint *)(iVar13 + 0x44)) {
            pcVar14 = *(char **)pcVar14;
          }
          if (pcVar14 != (char *)0x0) {
            dVar16 = _atof(pcVar14);
            local_14 = (float)dVar16;
            goto LAB_00800a6d;
          }
        }
        break;
      }
    }
    local_14 = 0.0;
LAB_00800a6d:
    for (iVar13 = *(int *)(iVar10 + 0x94); iVar13 != iVar15; iVar13 = *(int *)(iVar13 + 0x50)) {
      pcVar14 = (char *)(iVar13 + 0x14);
      if (0xf < *(uint *)(iVar13 + 0x28)) {
        pcVar14 = *(char **)pcVar14;
      }
      iVar12 = __stricmp(pcVar14,"Y");
      if (iVar12 == 0) {
        if (iVar13 != 0) {
          pcVar14 = (char *)(iVar13 + 0x30);
          if (0xf < *(uint *)(iVar13 + 0x44)) {
            pcVar14 = *(char **)pcVar14;
          }
          if (pcVar14 != (char *)0x0) {
            dVar16 = _atof(pcVar14);
            local_10 = (float)dVar16;
            goto LAB_00800aa1;
          }
        }
        break;
      }
    }
    local_10 = 0.0;
LAB_00800aa1:
    for (iVar13 = *(int *)(iVar10 + 0x94); iVar13 != iVar15; iVar13 = *(int *)(iVar13 + 0x50)) {
      pcVar14 = (char *)(iVar13 + 0x14);
      if (0xf < *(uint *)(iVar13 + 0x28)) {
        pcVar14 = *(char **)pcVar14;
      }
      iVar12 = __stricmp(pcVar14,"X");
      if (iVar12 == 0) {
        if (iVar13 != 0) {
          pcVar14 = (char *)(iVar13 + 0x30);
          if (0xf < *(uint *)(iVar13 + 0x44)) {
            pcVar14 = *(char **)pcVar14;
          }
          if (pcVar14 != (char *)0x0) {
            dVar16 = _atof(pcVar14);
            local_8 = (uint *)(float)dVar16;
            goto LAB_00800add;
          }
        }
        break;
      }
    }
    local_8 = (uint *)0x0;
LAB_00800add:
    puVar11[1] = (uint)local_8;
    puVar11[2] = (uint)local_10;
    puVar11[3] = (uint)local_14;
    for (iVar13 = *(int *)(iVar10 + 0x94); iVar13 != iVar15; iVar13 = *(int *)(iVar13 + 0x50)) {
      pcVar14 = (char *)(iVar13 + 0x14);
      if (0xf < *(uint *)(iVar13 + 0x28)) {
        pcVar14 = *(char **)pcVar14;
      }
      iVar12 = __stricmp(pcVar14,"Accel");
      if (iVar12 == 0) {
        if (iVar13 != 0) {
          pcVar14 = (char *)(iVar13 + 0x30);
          if (0xf < *(uint *)(iVar13 + 0x44)) {
            pcVar14 = *(char **)pcVar14;
          }
          if (pcVar14 != (char *)0x0) {
            dVar16 = _atof(pcVar14);
            local_14 = (float)dVar16;
            goto LAB_00800b3d;
          }
        }
        break;
      }
    }
    local_14 = 0.0;
LAB_00800b3d:
    puVar11[6] = (uint)local_14;
    for (iVar13 = *(int *)(iVar10 + 0x94); iVar13 != iVar15; iVar13 = *(int *)(iVar13 + 0x50)) {
      pcVar14 = (char *)(iVar13 + 0x14);
      if (0xf < *(uint *)(iVar13 + 0x28)) {
        pcVar14 = *(char **)pcVar14;
      }
      iVar12 = __stricmp(pcVar14,"Attenuation");
      if (iVar12 == 0) {
        if (iVar13 != 0) {
          pcVar14 = (char *)(iVar13 + 0x30);
          if (0xf < *(uint *)(iVar13 + 0x44)) {
            pcVar14 = *(char **)pcVar14;
          }
          if (pcVar14 != (char *)0x0) {
            dVar16 = _atof(pcVar14);
            local_14 = (float)dVar16;
            goto LAB_00800b7d;
          }
        }
        break;
      }
    }
    local_14 = 0.0;
LAB_00800b7d:
    puVar11[7] = (uint)local_14;
    for (iVar10 = *(int *)(iVar10 + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
      pcVar14 = (char *)(iVar10 + 0x14);
      if (0xf < *(uint *)(iVar10 + 0x28)) {
        pcVar14 = *(char **)pcVar14;
      }
      iVar13 = __stricmp(pcVar14,"Range");
      if (iVar13 == 0) {
        if (iVar10 != 0) {
          pcVar14 = (char *)(iVar10 + 0x30);
          if (0xf < *(uint *)(iVar10 + 0x44)) {
            pcVar14 = *(char **)pcVar14;
          }
          if (pcVar14 != (char *)0x0) {
            dVar16 = _atof(pcVar14);
            local_14 = (float)dVar16;
            goto LAB_00800bbd;
          }
        }
        break;
      }
    }
    local_14 = 0.0;
LAB_00800bbd:
    puVar11[4] = (uint)local_14;
    puVar11[5] = (uint)(local_14 * local_14);
    ppuVar1 = *(uint ***)((int)param_1 + 0x5c);
    local_8 = puVar11;
    if (&local_8 < ppuVar1) {
      ppuVar2 = *(uint ***)((int)param_1 + 0x58);
      if (&local_8 < ppuVar2) goto LAB_00800d1e;
      if (ppuVar1 == *(uint ***)((int)param_1 + 0x60)) {
        FUN_00797930();
      }
      if (*(undefined4 **)((int)param_1 + 0x5c) != (undefined4 *)0x0) {
        **(undefined4 **)((int)param_1 + 0x5c) =
             *(undefined4 *)
              (*(int *)((int)param_1 + 0x58) + ((int)&local_8 - (int)ppuVar2 >> 2) * 4);
      }
    }
    else {
LAB_00800d1e:
      if (ppuVar1 == *(uint ***)((int)param_1 + 0x60)) {
        FUN_00797930();
      }
      if (*(undefined4 **)((int)param_1 + 0x5c) != (undefined4 *)0x0) {
        **(undefined4 **)((int)param_1 + 0x5c) = puVar11;
      }
    }
    *(int *)((int)param_1 + 0x5c) = *(int *)((int)param_1 + 0x5c) + 4;
    for (piVar9 = (int *)piVar9[0x10]; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[0x10]) {
      _Str1 = piVar9 + 8;
      if (0xf < (uint)piVar9[0xd]) {
        _Str1 = (int *)*_Str1;
      }
      iVar10 = __stricmp((char *)_Str1,"GravitonPoint");
      if (iVar10 == 0) goto joined_r0x00800a03;
    }
    piVar9 = (int *)0x0;
    goto joined_r0x00800a03;
  }
  local_c = FUN_0072e360();
  if (local_c != 0) {
    local_8 = (uint *)((int)param_1 + 0x58);
    do {
      param_2 = (undefined4 *)FUN_00891268(0x5c);
      if (param_2 == (undefined4 *)0x0) {
        param_2 = (undefined4 *)0x0;
      }
      else {
        *param_2 = IS3D::CGravitonSpear::vftable;
      }
      iVar15 = local_c + 0x44;
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"EndZ");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              local_10 = (float)dVar16;
              goto LAB_00800dfc;
            }
          }
          break;
        }
      }
      local_10 = 0.0;
LAB_00800dfc:
      fVar8 = local_10;
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"EndY");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              local_14 = (float)dVar16;
              goto LAB_00800e2f;
            }
          }
          break;
        }
      }
      local_14 = 0.0;
LAB_00800e2f:
      fVar7 = local_14;
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"EndX");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              param_1 = (float)dVar16;
              goto LAB_00800e62;
            }
          }
          break;
        }
      }
      param_1 = 0.0;
LAB_00800e62:
      fVar5 = param_1;
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"StartZ");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              local_10 = (float)dVar16;
              goto LAB_00800eac;
            }
          }
          break;
        }
      }
      local_10 = 0.0;
LAB_00800eac:
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"StartY");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              local_14 = (float)dVar16;
              goto LAB_00800edf;
            }
          }
          break;
        }
      }
      local_14 = 0.0;
LAB_00800edf:
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"StartX");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              param_1 = (float)dVar16;
              goto LAB_00800f12;
            }
          }
          break;
        }
      }
      param_1 = 0.0;
LAB_00800f12:
      param_2[1] = param_1;
      param_2[2] = local_14;
      param_2[4] = fVar5;
      param_2[3] = local_10;
      param_2[5] = fVar7;
      param_2[6] = fVar8;
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"Accel");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              param_1 = (float)dVar16;
              goto LAB_00800f7e;
            }
          }
          break;
        }
      }
      param_1 = 0.0;
LAB_00800f7e:
      param_2[9] = param_1;
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"Attenuation");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              param_1 = (float)dVar16;
              goto LAB_00800fbc;
            }
          }
          break;
        }
      }
      param_1 = 0.0;
LAB_00800fbc:
      param_2[10] = param_1;
      for (iVar10 = *(int *)(local_c + 0x94); iVar10 != iVar15; iVar10 = *(int *)(iVar10 + 0x50)) {
        pcVar14 = (char *)(iVar10 + 0x14);
        if (0xf < *(uint *)(iVar10 + 0x28)) {
          pcVar14 = *(char **)pcVar14;
        }
        iVar13 = __stricmp(pcVar14,"Range");
        if (iVar13 == 0) {
          if (iVar10 != 0) {
            pcVar14 = (char *)(iVar10 + 0x30);
            if (0xf < *(uint *)(iVar10 + 0x44)) {
              pcVar14 = *(char **)pcVar14;
            }
            if (pcVar14 != (char *)0x0) {
              dVar16 = _atof(pcVar14);
              param_1 = (float)dVar16;
              goto LAB_00800ffc;
            }
          }
          break;
        }
      }
      param_1 = 0.0;
LAB_00800ffc:
      puVar11 = local_8;
      puVar6 = param_2;
      param_2[7] = param_1;
      param_2[8] = param_1 * param_1;
      puVar3 = (undefined4 *)local_8[1];
      if (&param_2 < puVar3) {
        puVar4 = (undefined4 *)*local_8;
        if (&param_2 < puVar4) goto LAB_008011d8;
        if (puVar3 == (undefined4 *)local_8[2]) {
          FUN_00797930();
        }
        if ((undefined4 *)puVar11[1] != (undefined4 *)0x0) {
          *(undefined4 *)puVar11[1] =
               *(undefined4 *)(*puVar11 + ((int)&param_2 - (int)puVar4 >> 2) * 4);
        }
      }
      else {
LAB_008011d8:
        if (puVar3 == (undefined4 *)local_8[2]) {
          FUN_00797930();
        }
        if ((undefined4 *)puVar11[1] != (undefined4 *)0x0) {
          *(undefined4 *)puVar11[1] = puVar6;
        }
      }
      puVar11[1] = puVar11[1] + 4;
      local_c = FUN_0072e3c0();
    } while (local_c != 0);
  }
  return 1;
}

