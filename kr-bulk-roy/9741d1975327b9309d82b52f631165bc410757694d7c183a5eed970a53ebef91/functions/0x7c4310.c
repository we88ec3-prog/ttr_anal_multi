
void FUN_007c4310(int param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  char *pcVar7;
  char *****pppppcVar8;
  char *in_ECX;
  int iVar9;
  char *in_EDX;
  char *****pppppcVar10;
  undefined4 *****pppppuVar11;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  undefined4 local_94;
  char *local_90;
  uint local_8c;
  undefined1 local_85;
  int *local_84;
  int *local_80;
  uint local_7c;
  undefined4 local_6c;
  uint local_68;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 ****local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  char ****local_34 [3];
  int local_28;
  int local_24;
  uint local_20;
  undefined4 local_1c;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  local_8 = 0xff;
  uStack_7 = 0xffffff;
  puStack_c = &LAB_00937d1d;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = uVar2;
  if (*(char *)(param_1 + 0x60) == '\0') {
    local_68 = 0xf;
    local_6c = 0;
    local_7c = local_7c & 0xffffff00;
    pcVar3 = in_ECX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00402a70(in_ECX,(int)pcVar3 - (int)(in_ECX + 1));
    local_8 = 0;
    uStack_7 = 0;
    pcVar3 = in_EDX;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    FUN_00401fc0(in_EDX,(int)pcVar3 - (int)(in_EDX + 1));
    if ((DAT_00fe321c & 1) == 0) {
      DAT_00fe321c = DAT_00fe321c | 1;
      local_8 = 1;
      FUN_007d0fb0(&local_85);
      _atexit((_func_4879 *)&LAB_00bd09c0);
      local_8 = 0;
    }
    iVar4 = FUN_007d0920(0);
    *(int *)(param_1 + 0xec) = iVar4;
    if (iVar4 != 0) {
      if ((*(int *)(iVar4 + 0xdc) - *(int *)(iVar4 + 0xd8) & 0xfffffffcU) != 0) {
        local_84 = (int *)FUN_00891268(0xe8,uVar2);
        local_8 = 2;
        if (local_84 == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          piVar5 = (int *)FUN_0077ebb0();
        }
        local_8 = 0;
        (**(code **)(*piVar5 + 0x40))(*(undefined4 *)(param_1 + 0xec));
        *(int **)(param_1 + 0xec) = piVar5;
      }
      iVar9 = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x84);
      iVar4 = iVar9 >> 0x1f;
      if (iVar9 / 0x38 + iVar4 == iVar4) {
        FUN_007c7030(*(undefined4 *)(param_1 + 0xec),2);
      }
      else {
        FUN_007c7030(*(undefined4 *)(param_1 + 0xec),3);
        uVar6 = (**(code **)(**(int **)(param_1 + 0xec) + 0xc))();
        if (*(undefined4 **)(param_1 + 0xec) != (undefined4 *)0x0) {
          (**(code **)**(undefined4 **)(param_1 + 0xec))(1);
          *(undefined4 *)(param_1 + 0xec) = 0;
        }
        *(undefined4 *)(param_1 + 0xec) = uVar6;
        piVar5 = (int *)FUN_006dd910();
        local_28 = 0;
        local_24 = 0;
        local_20 = 0;
        _local_8 = CONCAT31(uStack_7,3);
        local_84 = piVar5;
        FUN_007c7dd0(*(undefined4 *)(param_1 + 0xec),&local_28);
        local_80 = (int *)0x0;
        if (local_24 - local_28 >> 2 != 0) {
          do {
            local_94 = *(undefined4 *)(local_28 + (int)local_80 * 4);
            local_90 = (char *)0x0;
            iVar4 = FUN_00843ef0();
            local_98 = *(undefined4 *)(iVar4 + 0xb8);
            (**(code **)(*piVar5 + 0x58))(&local_98,&local_90);
            iVar9 = *(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x84);
            iVar4 = iVar9 >> 0x1f;
            local_8c = 0;
            if (iVar9 / 0x38 + iVar4 != iVar4) {
              iVar4 = 0;
              do {
                pcVar3 = (char *)(*(int *)(param_1 + 0x84) + iVar4);
                if (0xf < *(uint *)(pcVar3 + 0x14)) {
                  pcVar3 = *(char **)pcVar3;
                }
                iVar9 = __stricmp(pcVar3,local_90);
                if (iVar9 == 0) {
                  iVar9 = *(int *)(param_1 + 0x84);
                  if (*(uint *)(iVar9 + 0x30 + iVar4) < 0x10) {
                    iVar9 = iVar9 + 0x1c + iVar4;
                  }
                  else {
                    iVar9 = *(int *)(iVar9 + 0x1c + iVar4);
                  }
                  if ((DAT_00fb79e8 & 1) == 0) {
                    DAT_00fb79e8 = DAT_00fb79e8 | 1;
                    local_8 = 4;
                    FUN_00798de0();
                    _atexit((_func_4879 *)&LAB_00bcd2e0);
                    _local_8 = CONCAT31(uStack_7,3);
                  }
                  FUN_0079be00(iVar9);
                  iVar9 = FUN_00843ef0();
                  *(undefined4 *)(iVar9 + 0xb8) = local_9c;
                }
                local_8c = local_8c + 1;
                iVar4 = iVar4 + 0x38;
                piVar5 = local_84;
              } while (local_8c <
                       (uint)((*(int *)(param_1 + 0x88) - *(int *)(param_1 + 0x84)) / 0x38));
            }
            local_80 = (int *)((int)local_80 + 1);
          } while (local_80 < (int *)(local_24 - local_28 >> 2));
        }
        local_8 = 0;
        if (local_28 != 0) {
          FUN_0089120c(local_28);
        }
      }
      iVar4 = FUN_007c6430(*(undefined4 *)(param_1 + 0xec),&DAT_00c4fde8,0,0);
      local_60 = 0;
      local_5c = 0;
      local_58 = 0;
      local_38 = 1;
      local_54 = 0;
      local_50 = (undefined4 *****)0x0;
      local_4c = 0;
      local_48 = 0x3f800000;
      local_44 = 0x3f800000;
      local_40 = 0x3f800000;
      local_3c = 0x3f800000;
      if ((iVar4 == 0) ||
         (iVar4 = FUN_007c6880(*(undefined4 *)(param_1 + 0xec),&DAT_00c4fde8,&local_60),
         uVar6 = local_58, iVar4 == 0)) {
        local_24 = 0;
        local_20 = 0;
        local_1c = 0;
        local_a8 = 0;
        local_a4 = 0;
        local_a0 = 0;
        local_84 = (int *)0x1;
        FUN_007c73a0(*(undefined4 *)(param_1 + 0xec),&local_24,&local_a8,&local_84);
        uVar6 = local_a0;
      }
      *(undefined4 *)(param_1 + 0xf0) = uVar6;
      piVar5 = (int *)FUN_007c6700(*(undefined4 *)(param_1 + 0xec),"Face.SKIN");
      if (piVar5 != (int *)0x0) {
        uVar6 = (**(code **)(*piVar5 + 0xc))();
        FUN_007d6510(*(undefined4 *)(param_1 + 0xe4),1,uVar6);
      }
      pcVar3 = (char *)FUN_007c5670(&local_50);
      local_8 = 5;
      if (0xf < *(uint *)(pcVar3 + 0x14)) {
        pcVar3 = *(char **)pcVar3;
      }
      pcVar7 = pcVar3;
      do {
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      FUN_00402a70(pcVar3,(int)pcVar7 - (int)(pcVar3 + 1));
      local_8 = 0;
      if (0xf < local_3c) {
        FUN_0089120c(local_50);
      }
      FUN_007d6190();
      if (*(int *)(param_1 + 0xec) != 0) {
        local_84 = *(int **)(param_1 + 0x78);
        local_80 = *(int **)(param_1 + 0x74);
        if (local_80 != local_84) {
          do {
            local_20 = 0xf;
            local_24 = 0;
            local_34[0] = (char ****)((uint)local_34[0] & 0xffffff00);
            FUN_00403040(local_80,0,0xffffffff);
            local_8 = 6;
            FUN_007c5600(&local_50);
            local_8 = 7;
            pppppcVar10 = (char *****)local_34[0];
            if (local_20 < 0x10) {
              pppppcVar10 = local_34;
            }
            pppppcVar8 = pppppcVar10;
            do {
              cVar1 = *(char *)pppppcVar8;
              pppppcVar8 = (char *****)((int)pppppcVar8 + 1);
            } while (cVar1 != '\0');
            FUN_00401fc0(pppppcVar10,(int)pppppcVar8 - (int)((int)pppppcVar10 + 1));
            pppppuVar11 = (undefined4 *****)local_50;
            if (local_3c < 0x10) {
              pppppuVar11 = &local_50;
            }
            pppppcVar10 = (char *****)local_34[0];
            if (local_20 < 0x10) {
              pppppcVar10 = local_34;
            }
            if ((DAT_00fe1ac0 & 1) == 0) {
              DAT_00fe1ac0 = DAT_00fe1ac0 | 1;
              local_8 = 8;
              FUN_007bb970();
              _atexit((_func_4879 *)&LAB_00bceac0);
              local_8 = 7;
            }
            EnterCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
            (*DAT_00fe1ae0)(pppppcVar10,pppppuVar11);
            SetEvent(DAT_00fe1b2c);
            LeaveCriticalSection((LPCRITICAL_SECTION)&DAT_00fe1b08);
            if (0xf < local_3c) {
              FUN_0089120c(local_50);
            }
            local_8 = 0;
            if (0xf < local_20) {
              FUN_0089120c(local_34[0]);
            }
            local_80 = local_80 + 7;
          } while (local_80 != local_84);
        }
        if ((*(int *)(param_1 + 0xbc) != 0) ||
           (*(int *)(param_1 + 0x84) != *(int *)(param_1 + 0x88))) {
          FUN_007c7030(*(undefined4 *)(param_1 + 0xec),3);
        }
      }
      *(undefined1 *)(param_1 + 0x60) = 1;
    }
    if (0xf < local_68) {
      FUN_0089120c(local_7c);
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

