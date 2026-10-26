
void FUN_0064f2c0(void)

{
  short sVar1;
  code *pcVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  short *psVar6;
  short *psVar7;
  int *in_ECX;
  uint uVar8;
  int *piVar9;
  short *psVar10;
  char *pcVar11;
  int *piVar12;
  undefined4 local_8c;
  char local_85;
  int *local_84;
  int local_80;
  int local_7c;
  int *local_78;
  int *local_74;
  int *local_70;
  char *local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  uint local_38 [4];
  int local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093d72c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_8c;
  ExceptionList = &local_14;
  local_78 = in_ECX;
  cVar3 = FUN_0064e8a0(DAT_00d61f20 ^ (uint)&stack0xffffff68);
  if (cVar3 == '\0') goto LAB_0064f9f6;
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 0;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_c = 0xffffffff;
  }
  if (in_ECX[0x2a] == 0) {
    piVar12 = (int *)0x0;
  }
  else {
    piVar12 = *(int **)(in_ECX[0x2a] + 0x40);
  }
  local_85 = '\0';
  in_ECX[0x2b] = (int)((float)in_ECX[0x2b] + 0.033333335);
  if (piVar12 == (int *)0x0) {
LAB_0064f9c7:
    if (((uint)((int *)local_78[0x116])[10] >> 8 & 1) != 0) {
      (**(code **)(*(int *)local_78[0x116] + 0x94))(0);
    }
  }
  else {
    iVar4 = FUN_0040f060();
    local_84 = *(int **)(iVar4 + 0x94);
    piVar9 = (int *)*piVar12;
    uVar5 = piVar12[1] - (int)piVar9 >> 4;
    uVar8 = 0;
    if (uVar5 != 0) {
      do {
        if ((int *)(uint)*(ushort *)(piVar9 + 2) == local_84) {
          local_68 = *piVar9;
          local_64 = piVar9[1];
          break;
        }
        uVar8 = uVar8 + 1;
        piVar9 = piVar9 + 4;
      } while (uVar8 < uVar5);
    }
    iVar4 = FUN_008fed10();
    in_ECX[0x40] = iVar4;
    iVar4 = FUN_008fed10();
    in_ECX[0x41] = iVar4;
    in_ECX[0x42] = in_ECX[0x40] + 0x20;
    in_ECX[0x43] = in_ECX[0x41] + 0x17;
    local_3c = DAT_00f948b8 - in_ECX[0xb];
    local_84 = in_ECX + 0x45;
    local_60 = DAT_00f948bc - in_ECX[0xc];
    local_70 = in_ECX + 0xf3;
    local_6c = (char *)((int)piVar12 + 0x1a);
    local_80 = 0;
    do {
      local_7c = 0;
      local_40 = FUN_008fed10();
      local_74 = local_70;
      pcVar11 = local_6c;
      piVar12 = local_84;
      do {
        iVar4 = FUN_008fed10();
        piVar12[-1] = iVar4;
        *piVar12 = local_40;
        piVar12[1] = iVar4 + 0x20;
        piVar12[2] = *piVar12 + 0x17;
        local_74[-0x23] = (int)*pcVar11;
        *local_74 = (int)pcVar11[1];
        if ((((piVar12[-1] <= local_3c) && (local_3c <= piVar12[1])) && (*piVar12 <= local_60)) &&
           (local_60 <= piVar12[2])) {
          local_24 = 7;
          local_28 = 0;
          local_38[0] = local_38[0] & 0xffff0000;
          FUN_00402160(&DAT_00bed1fc,0);
          local_c = 1;
          cVar3 = pcVar11[1];
          local_c._1_3_ = 0;
          if (cVar3 == '\x01') {
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 2;
              FUN_00584c40(&DAT_00fe5ac4);
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c = CONCAT31(local_c._1_3_,1);
            }
            local_8c = 0x225;
            FUN_005740f0(&local_8c);
            if (local_4c == DAT_00fe5ac8) {
              pcVar2 = (code *)swi(3);
              (*pcVar2)();
              return;
            }
            if (*(uint *)(local_4c + 0x24) < 8) {
              psVar10 = (short *)(local_4c + 0x10);
            }
            else {
              psVar10 = *(short **)(local_4c + 0x10);
            }
            psVar7 = psVar10 + 1;
            psVar6 = psVar10;
            do {
              sVar1 = *psVar6;
              psVar6 = psVar6 + 1;
            } while (sVar1 != 0);
LAB_0064f6ab:
            FUN_00402160(psVar10,(int)psVar6 - (int)psVar7 >> 1);
          }
          else {
            if (cVar3 == '\x02') {
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 3;
                FUN_00584c40(&DAT_00fe5ac4);
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c = CONCAT31(local_c._1_3_,1);
              }
              local_8c = 0x226;
              FUN_005740f0(&local_8c);
              if (local_44 == DAT_00fe5ac8) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              if (*(uint *)(local_44 + 0x24) < 8) {
                psVar10 = (short *)(local_44 + 0x10);
              }
              else {
                psVar10 = *(short **)(local_44 + 0x10);
              }
              psVar7 = psVar10 + 1;
              psVar6 = psVar10;
              do {
                sVar1 = *psVar6;
                psVar6 = psVar6 + 1;
              } while (sVar1 != 0);
              goto LAB_0064f6ab;
            }
            if (cVar3 == '\x03') {
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 4;
                local_c._1_3_ = 0;
                FUN_00584c40(&DAT_00fe5ac4);
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c = CONCAT31(local_c._1_3_,1);
              }
              local_8c = 0x227;
              FUN_005740f0(&local_8c);
              if (local_54 == DAT_00fe5ac8) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              if (*(uint *)(local_54 + 0x24) < 8) {
                psVar10 = (short *)(local_54 + 0x10);
              }
              else {
                psVar10 = *(short **)(local_54 + 0x10);
              }
              psVar7 = psVar10 + 1;
              psVar6 = psVar10;
              do {
                sVar1 = *psVar6;
                psVar6 = psVar6 + 1;
              } while (sVar1 != 0);
              goto LAB_0064f6ab;
            }
          }
          if (*pcVar11 == '\x02') {
            if (local_28 == 0) {
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 5;
                FUN_00584c40(&DAT_00fe5ac4);
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c = CONCAT31(local_c._1_3_,1);
              }
              local_8c = 0x224;
              FUN_005740f0(&local_8c);
              if (local_5c == DAT_00fe5ac8) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              if (*(uint *)(local_5c + 0x24) < 8) {
                psVar10 = (short *)(local_5c + 0x10);
              }
              else {
                psVar10 = *(short **)(local_5c + 0x10);
              }
              psVar7 = psVar10;
              do {
                sVar1 = *psVar7;
                psVar7 = psVar7 + 1;
              } while (sVar1 != 0);
              FUN_00402160(psVar10,(int)psVar7 - (int)(psVar10 + 1) >> 1);
            }
            else {
              FUN_00404300(&DAT_00c02b94,2);
              if ((DAT_00fe5ae4 & 1) == 0) {
                DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
                local_c._0_1_ = 6;
                FUN_00584c40(&DAT_00fe5ac4);
                _atexit((_func_4879 *)&LAB_00bcf390);
                local_c = CONCAT31(local_c._1_3_,1);
              }
              local_8c = 0x224;
              FUN_005740f0(&local_8c);
              if (local_58 == DAT_00fe5ac8) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              if (*(uint *)(local_58 + 0x24) < 8) {
                psVar10 = (short *)(local_58 + 0x10);
              }
              else {
                psVar10 = *(short **)(local_58 + 0x10);
              }
              psVar7 = psVar10;
              do {
                sVar1 = *psVar7;
                psVar7 = psVar7 + 1;
              } while (sVar1 != 0);
              FUN_00404300(psVar10,(int)psVar7 - (int)(psVar10 + 1) >> 1);
            }
          }
          if ((local_68 == local_7c) && (local_64 == local_80)) {
            if (local_28 == 0) {
              local_8c = 0x228;
              iVar4 = FUN_00585620();
              FUN_005740f0(&local_8c);
              if (local_50 == *(int *)(iVar4 + 4)) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              if (*(uint *)(local_50 + 0x24) < 8) {
                psVar10 = (short *)(local_50 + 0x10);
              }
              else {
                psVar10 = *(short **)(local_50 + 0x10);
              }
              psVar7 = psVar10;
              do {
                sVar1 = *psVar7;
                psVar7 = psVar7 + 1;
              } while (sVar1 != 0);
              FUN_00402160(psVar10,(int)psVar7 - (int)(psVar10 + 1) >> 1);
            }
            else {
              FUN_00404300(&DAT_00c02b94,2);
              local_8c = 0x228;
              iVar4 = FUN_00585620();
              FUN_005740f0(&local_8c);
              if (local_48 == *(int *)(iVar4 + 4)) {
                pcVar2 = (code *)swi(3);
                (*pcVar2)();
                return;
              }
              if (*(uint *)(local_48 + 0x24) < 8) {
                psVar10 = (short *)(local_48 + 0x10);
              }
              else {
                psVar10 = *(short **)(local_48 + 0x10);
              }
              psVar7 = psVar10;
              do {
                sVar1 = *psVar7;
                psVar7 = psVar7 + 1;
              } while (sVar1 != 0);
              FUN_00404300(psVar10,(int)psVar7 - (int)(psVar10 + 1) >> 1);
            }
          }
          if (local_28 != 0) {
            FUN_00757800(local_38);
            (**(code **)(*(int *)local_78[0x116] + 0x94))(1);
            local_85 = '\x01';
          }
          local_c = 0xffffffff;
          if (7 < local_24) {
            FUN_0089120c(local_38[0]);
          }
          local_24 = 7;
          local_28 = 0;
          local_38[0] = local_38[0] & 0xffff0000;
        }
        local_74 = local_74 + 7;
        local_7c = local_7c + 1;
        piVar12 = piVar12 + 0x1c;
        pcVar11 = pcVar11 + 0x70;
      } while (local_7c < 5);
      local_70 = local_70 + 1;
      local_6c = local_6c + 0x10;
      local_84 = local_84 + 4;
      local_80 = local_80 + 1;
    } while (local_80 < 7);
    if (local_85 == '\0') goto LAB_0064f9c7;
  }
  (**(code **)(*local_78 + 200))();
LAB_0064f9f6:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_8c);
  return;
}

