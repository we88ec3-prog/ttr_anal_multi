
void FUN_007ec3a0(int *param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  int *piVar7;
  char *pcVar8;
  char ****ppppcVar9;
  char ****ppppcVar10;
  uint uVar11;
  int *_Str1;
  double dVar12;
  undefined4 local_d8;
  float local_d4;
  int local_d0;
  char ***local_cc [4];
  uint local_bc;
  uint local_b8;
  char ***local_b0 [4];
  int *local_a0;
  uint local_9c;
  char local_94 [128];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093886d;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar3 = FUN_00891268(0x358,local_14);
  if (iVar3 == 0) {
    local_d0 = 0;
  }
  else {
    local_d0 = FUN_007f4170();
  }
  (**(code **)(*param_1 + 0x14))();
  iVar3 = FUN_007300a0("Enable");
  if (iVar3 == 0) {
LAB_007ec442:
    uVar5 = 1;
  }
  else {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 == (undefined4 *)0x0) goto LAB_007ec442;
    uVar5 = FUN_008917b4(puVar4);
  }
  *(undefined4 *)(local_d0 + 0x354) = uVar5;
  iVar3 = FUN_007300a0("Altitude");
  if (iVar3 == 0) {
LAB_007ec47b:
    local_d4 = -25.0;
  }
  else {
    pcVar6 = (char *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      pcVar6 = *(char **)pcVar6;
    }
    if (pcVar6 == (char *)0x0) goto LAB_007ec47b;
    dVar12 = _atof(pcVar6);
    local_d4 = (float)dVar12;
  }
  *(float *)(local_d0 + 0x348) = local_d4;
  if (*(char *)(local_d0 + 0x34c) != '\0') {
    FUN_007f4bf0();
    FUN_007f4260();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
  }
  iVar3 = FUN_007300a0(&DAT_00c506ac);
  if (iVar3 == 0) {
LAB_007ec512:
    local_d4 = 250.0;
  }
  else {
    pcVar6 = (char *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      pcVar6 = *(char **)pcVar6;
    }
    if (pcVar6 == (char *)0x0) goto LAB_007ec512;
    dVar12 = _atof(pcVar6);
    local_d4 = (float)dVar12;
  }
  *(float *)(local_d0 + 0x340) = local_d4;
  if (*(char *)(local_d0 + 0x34c) != '\0') {
    FUN_007f4bf0();
    FUN_007f4260();
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
  }
  piVar7 = (int *)FUN_0072e2e0(&DAT_00c060e4);
  if (piVar7 != (int *)0x0) {
    bVar2 = true;
    local_d8 = 0;
    do {
      iVar3 = (**(code **)(*piVar7 + 0x14))();
      if (iVar3 != 0) {
        iVar3 = FUN_007300a0("Texture");
        if (iVar3 == 0) {
          pcVar6 = (char *)0x0;
        }
        else {
          pcVar6 = (char *)(iVar3 + 0x30);
          if (0xf < *(uint *)(iVar3 + 0x44)) {
            pcVar6 = *(char **)pcVar6;
          }
        }
        local_b8 = 0xf;
        local_bc = 0;
        local_cc[0] = (char ***)((uint)local_cc[0] & 0xffffff00);
        pcVar8 = pcVar6;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(pcVar6,(int)pcVar8 - (int)(pcVar6 + 1));
        local_8 = 4;
        if (local_bc != 0) {
          if (bVar2) {
            bVar2 = false;
            ppppcVar10 = (char ****)local_cc[0];
            if (local_b8 < 0x10) {
              ppppcVar10 = local_cc;
            }
            iVar3 = -(int)ppppcVar10;
            do {
              cVar1 = *(char *)ppppcVar10;
              *(char *)((int)ppppcVar10 + (int)(local_94 + iVar3)) = cVar1;
              ppppcVar10 = (char ****)((int)ppppcVar10 + 1);
            } while (cVar1 != '\0');
            pcVar6 = _strstr(local_94,"up");
            if (((pcVar6 == (char *)0x0) && (pcVar6 = _strstr(local_94,"Up"), pcVar6 == (char *)0x0)
                ) && (pcVar6 = _strstr(local_94,"UP"), pcVar6 == (char *)0x0)) {
              pcVar6 = _strstr(local_94,"0");
              if (pcVar6 != (char *)0x0) {
                local_d8 = 2;
              }
            }
            else {
              local_d8 = 1;
            }
          }
          else {
            uVar11 = 0;
            do {
              if (uVar11 < local_bc) {
                ppppcVar10 = (char ****)local_cc[0];
                if (local_b8 < 0x10) {
                  ppppcVar10 = local_cc;
                }
                if (local_94[uVar11] != *(char *)((int)ppppcVar10 + uVar11)) goto LAB_007ec8d1;
              }
              else {
LAB_007ec8d1:
                local_94[uVar11] = '\0';
              }
              uVar11 = uVar11 + 1;
            } while (uVar11 < 0x7f);
          }
        }
        local_8 = 0xffffffff;
        if (0xf < local_b8) {
          FUN_0089120c(local_cc[0]);
        }
        local_bc = 0;
        local_b8 = 0xf;
        local_cc[0] = (char ***)((uint)local_cc[0] & 0xffffff00);
      }
      if (!bVar2) {
        pcVar6 = local_94;
        do {
          cVar1 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar1 != '\0');
        FUN_00402a70(local_94,(int)pcVar6 - (int)(local_94 + 1));
        *(undefined4 *)(local_d0 + 0x33c) = local_d8;
      }
      for (piVar7 = (int *)piVar7[0x10]; piVar7 != (int *)0x0; piVar7 = (int *)piVar7[0x10]) {
        _Str1 = piVar7 + 8;
        if (0xf < (uint)piVar7[0xd]) {
          _Str1 = (int *)*_Str1;
        }
        iVar3 = __stricmp((char *)_Str1,"Face");
        if (iVar3 == 0) goto LAB_007ec98c;
      }
      piVar7 = (int *)0x0;
LAB_007ec98c:
    } while (piVar7 != (int *)0x0);
    goto LAB_007ec99a;
  }
  local_9c = 0xf;
  local_b0[0] = (char ***)((uint)local_b0[0] & 0xffffff00);
  local_a0 = piVar7;
  FUN_00402a70("Prefix",6);
  local_8 = 2;
  iVar3 = FUN_007ed6a0(local_b0,local_94);
  local_8 = 0xffffffff;
  if (0xf < local_9c) {
    FUN_0089120c(local_b0[0]);
  }
  if (iVar3 == 0) {
    iVar3 = FUN_007300a0("PrefixRule");
    if (iVar3 == 0) {
LAB_007ec638:
      uVar5 = 0;
    }
    else {
      puVar4 = (undefined4 *)(iVar3 + 0x30);
      if (0xf < *(uint *)(iVar3 + 0x44)) {
        puVar4 = (undefined4 *)*puVar4;
      }
      if (puVar4 == (undefined4 *)0x0) goto LAB_007ec638;
      uVar5 = FUN_008917b4(puVar4);
    }
    iVar3 = FUN_007300a0("Prefix");
    if (iVar3 == 0) {
      pcVar6 = (char *)0x0;
    }
    else {
      pcVar6 = (char *)(iVar3 + 0x30);
      if (0xf < *(uint *)(iVar3 + 0x44)) {
        pcVar6 = *(char **)pcVar6;
      }
    }
    local_9c = 0xf;
    local_a0 = (int *)0x0;
    local_b0[0] = (char ***)((uint)local_b0[0] & 0xffffff00);
    pcVar8 = pcVar6;
    do {
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(pcVar6,(int)pcVar8 - (int)(pcVar6 + 1));
    local_8 = 3;
    ppppcVar10 = (char ****)local_b0[0];
    if (local_9c < 0x10) {
      ppppcVar10 = local_b0;
    }
    ppppcVar9 = ppppcVar10;
    do {
      cVar1 = *(char *)ppppcVar9;
      ppppcVar9 = (char ****)((int)ppppcVar9 + 1);
    } while (cVar1 != '\0');
    FUN_00402a70(ppppcVar10,(int)ppppcVar9 - (int)((int)ppppcVar10 + 1));
    local_8 = 0xffffffff;
    *(undefined4 *)(local_d0 + 0x33c) = uVar5;
    if (0xf < local_9c) {
      FUN_0089120c(local_b0[0]);
    }
  }
  iVar3 = FUN_007300a0("ModColor");
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)(iVar3 + 0x30);
    if (0xf < *(uint *)(iVar3 + 0x44)) {
      puVar4 = (undefined4 *)*puVar4;
    }
    if (puVar4 != (undefined4 *)0x0) {
      uVar5 = FUN_008917b4(puVar4);
      *(undefined4 *)(local_d0 + 0x350) = uVar5;
      goto LAB_007ec99a;
    }
  }
  *(undefined4 *)(local_d0 + 0x350) = 0xff7f7f7f;
LAB_007ec99a:
  if (*(int *)(param_2 + 4) != 0) {
    FUN_007f4bf0();
    if (*(undefined4 **)(param_2 + 4) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)(param_2 + 4))(1);
      *(undefined4 *)(param_2 + 4) = 0;
    }
  }
  *(int *)(param_2 + 4) = local_d0;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

