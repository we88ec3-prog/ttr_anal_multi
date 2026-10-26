
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_004e06d0(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  bool bVar4;
  void *pvVar5;
  int *piVar6;
  char cVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  uint uVar13;
  uint uVar14;
  float10 fVar15;
  int *local_64;
  int local_60;
  float fStack_58;
  float fStack_54;
  int local_50;
  float local_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float local_38;
  float local_34;
  undefined1 local_30 [12];
  undefined1 local_24 [16];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00944348;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  fVar1 = *(float *)(DAT_00fb1318 + 0xc00c);
  fVar2 = *(float *)(DAT_00fb1318 + 0xc010);
  local_38 = fVar1;
  local_34 = fVar2;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_c = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xffffff90);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_c = 0xffffffff;
  FUN_0079a7a0(&DAT_00fb76a8,local_24,fVar1,fVar2);
  local_60 = 0;
  if (DAT_00fba80c == 0) {
    iVar8 = FUN_00891268(0x57c);
    if (iVar8 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  iVar8 = DAT_00fb1318;
  if (*(int *)(DAT_00fba80c + 0x20) == 0) {
    cVar7 = '\0';
  }
  else {
    cVar7 = *(char *)(DAT_00fba80c + 0x369);
  }
  if (cVar7 == '\x01') {
    if ((_DAT_00fe48d4 & 1) == 0) {
      _DAT_00fe48d4 = _DAT_00fe48d4 | 1;
      DAT_00fe3728 = 0;
      _atexit((_func_4879 *)&DAT_00bced20);
    }
    DAT_00fe3720 = *(int *)(iVar8 + 0xc00c);
    DAT_00fe3724 = *(int *)(iVar8 + 0xc010);
    DAT_00fe3728 = 0;
  }
  else if (cVar7 == '\x02') {
    if ((_DAT_00fe48d4 & 1) == 0) {
      _DAT_00fe48d4 = _DAT_00fe48d4 | 1;
      DAT_00fe3728 = 0;
      _atexit((_func_4879 *)&DAT_00bced20);
    }
    uVar9 = DAT_00fe3720 - *(int *)(iVar8 + 0xc00c);
    uVar13 = (int)uVar9 >> 0x1f;
    uVar10 = DAT_00fe3724 - *(int *)(iVar8 + 0xc010);
    uVar14 = (int)uVar10 >> 0x1f;
    if (8 < (int)(((uVar10 ^ uVar14) - uVar14) + ((uVar9 ^ uVar13) - uVar13))) {
      DAT_00fe3728 = 1;
    }
    DAT_00fe3720 = *(int *)(iVar8 + 0xc00c);
    DAT_00fe3724 = *(int *)(iVar8 + 0xc010);
  }
  else if (cVar7 == '\x03') {
    if ((_DAT_00fe48d4 & 1) == 0) {
      _DAT_00fe48d4 = _DAT_00fe48d4 | 1;
      DAT_00fe3728 = 0;
      _atexit((_func_4879 *)&DAT_00bced20);
    }
    uVar9 = DAT_00fe3720 - *(int *)(iVar8 + 0xc00c);
    uVar13 = (int)uVar9 >> 0x1f;
    uVar10 = DAT_00fe3724 - *(int *)(iVar8 + 0xc010);
    uVar14 = (int)uVar10 >> 0x1f;
    if (8 < (int)(((uVar10 ^ uVar14) - uVar14) + ((uVar9 ^ uVar13) - uVar13))) {
      DAT_00fe3728 = 1;
    }
    local_60 = DAT_00fe3728;
  }
  if (DAT_00fba80c == 0) {
    iVar8 = FUN_00891268(0x57c);
    if (iVar8 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  if ((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x369) == '\x03')) {
    if ((_DAT_00fc0d5c & 1) == 0) {
      _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
      DAT_00fc0d60 = (void *)0x0;
      DAT_00fc0d64 = (void *)0x0;
      _DAT_00fc0d68 = 0;
      _atexit((_func_4879 *)&LAB_00bcd8c0);
    }
    pvVar5 = DAT_00fc0d60;
    if (DAT_00fc0d60 != DAT_00fc0d64) {
      FID_conflict__memcpy(DAT_00fc0d60,DAT_00fc0d64,0);
      DAT_00fc0d64 = pvVar5;
    }
  }
  local_50 = 0;
  bVar4 = false;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 1;
    FUN_004e1590();
    _atexit((_func_4879 *)&LAB_00bccc80);
    local_c = 0xffffffff;
  }
  switch(DAT_00f9392c) {
  case 3:
  case 5:
  case 7:
  case 8:
  case 0x15:
  case 0x17:
  case 0x18:
    break;
  default:
    bVar4 = true;
  }
  if ((DAT_00fb1378 & 1) == 0) {
    DAT_00fb1378 = DAT_00fb1378 | 1;
    local_c = 2;
    FUN_00539c20();
    _atexit((_func_4879 *)&LAB_00bccfb0);
    local_c = 0xffffffff;
  }
  if (DAT_00fb7258 != 0) {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 3;
      FUN_004e1590();
      _atexit((_func_4879 *)&LAB_00bccc80);
      local_c = 0xffffffff;
    }
    iVar8 = FUN_00539aa0(DAT_00f93930);
    if (((iVar8 != 0) && (*(char *)(iVar8 + 6) == '\0')) && (*(char *)(iVar8 + 8) != '\0')) {
      bVar4 = true;
    }
  }
  local_64 = (int *)**(int **)(param_1 + 0xc);
  if (local_64 != *(int **)(param_1 + 0xc)) {
    do {
      iVar8 = local_64[4];
      local_4c = (float)(uint)*(ushort *)(iVar8 + 4);
      cVar7 = (char)*(ushort *)(iVar8 + 4);
      if (cVar7 == '\0') {
        if (!bVar4) {
          iVar8 = (**(code **)(*DAT_00fba7a4 + 0x20))();
          if (local_4c._0_2_ != *(short *)(iVar8 + 4)) {
            iVar8 = local_64[4];
            iVar11 = (**(code **)(*DAT_00fba7a4 + 0x20))();
            fStack_40 = *(float *)(iVar11 + 0xa0) - *(float *)(iVar8 + 0xa0);
            fStack_3c = *(float *)(iVar11 + 0xa4) - *(float *)(iVar8 + 0xa4);
            local_4c = fStack_3c * fStack_3c + fStack_40 * fStack_40;
            fVar15 = (float10)FUN_008ff870();
            local_4c = (float)fVar15;
            if ((*(int *)(iVar8 + 0x15c) != 0) && (iVar11 = FUN_007a7f00(local_24), iVar11 != 0)) {
              if ((*(int *)(iVar8 + 0x15c) == 0) || (*(int *)(iVar8 + 0x370) == 0)) {
                fStack_54 = 0.0;
              }
              else {
                fVar15 = (float10)FUN_007a7100();
                fStack_54 = (float)fVar15;
              }
              if (local_4c < fStack_54) {
                if (((local_60 != 0) || (iVar11 = FUN_00443dc0(), *(int *)(iVar11 + 0x20) == 0)) ||
                   (*(char *)(iVar11 + 0x369) != '\x03')) goto LAB_004e0b66;
                local_4c = *(float *)(local_64[4] + 0x9c);
                FUN_00464f70();
                FUN_004a8680();
                local_50 = 1;
              }
            }
          }
        }
      }
      else if (cVar7 == '\x06') {
        iVar11 = (**(code **)(*DAT_00fba7a4 + 0x20))();
        fStack_48 = *(float *)(iVar11 + 0xa0) - *(float *)(iVar8 + 0xa0);
        fStack_44 = *(float *)(iVar11 + 0xa4) - *(float *)(iVar8 + 0xa4);
        local_4c = fStack_48 * fStack_48 + fStack_44 * fStack_44;
        fVar15 = (float10)FUN_008ff870();
        local_4c = (float)fVar15;
        if ((*(int *)(iVar8 + 0x15c) != 0) && (iVar11 = FUN_007a7f00(local_24), iVar11 != 0)) {
          if ((*(int *)(iVar8 + 0x15c) == 0) || (*(int *)(iVar8 + 0x370) == 0)) {
            fStack_58 = 0.0;
          }
          else {
            fVar15 = (float10)FUN_007a7100();
            fStack_58 = (float)fVar15;
          }
          if (local_4c < fStack_58) {
            if (((local_60 == 0) && (iVar11 = FUN_00443dc0(), *(int *)(iVar11 + 0x20) != 0)) &&
               (*(char *)(iVar11 + 0x369) == '\x03')) goto LAB_004e0eb8;
LAB_004e0b66:
            if (*(int *)(iVar8 + 0x15c) != 0) {
              *(undefined4 *)(*(int *)(iVar8 + 0x15c) + 0x148) = 1;
            }
            *(undefined4 *)(param_1 + 0xb4) = 1;
          }
        }
      }
      if (*(char *)((int)local_64 + 0x15) == '\0') {
        piVar3 = (int *)local_64[2];
        if (*(char *)((int)piVar3 + 0x15) == '\0') {
          cVar7 = *(char *)(*piVar3 + 0x15);
          local_64 = piVar3;
          piVar3 = (int *)*piVar3;
          while (cVar7 == '\0') {
            cVar7 = *(char *)(*piVar3 + 0x15);
            local_64 = piVar3;
            piVar3 = (int *)*piVar3;
          }
        }
        else {
          cVar7 = *(char *)(local_64[1] + 0x15);
          piVar6 = (int *)local_64[1];
          piVar3 = local_64;
          while ((local_64 = piVar6, cVar7 == '\0' && (piVar3 == (int *)local_64[2]))) {
            cVar7 = *(char *)(local_64[1] + 0x15);
            piVar6 = (int *)local_64[1];
            piVar3 = local_64;
          }
        }
      }
    } while (local_64 != *(int **)(param_1 + 0xc));
    if (local_50 != 0) {
      if ((_DAT_00fc0d5c & 1) == 0) {
        _DAT_00fc0d5c = _DAT_00fc0d5c | 1;
        DAT_00fc0d60 = (void *)0x0;
        DAT_00fc0d64 = (void *)0x0;
        _DAT_00fc0d68 = 0;
        _atexit((_func_4879 *)&LAB_00bcd8c0);
      }
      if (DAT_00fc0d60 == DAT_00fc0d64) {
        ExceptionList = local_14;
        return 1;
      }
      puVar12 = (undefined4 *)FUN_00891268(0x20);
      if (puVar12 != (undefined4 *)0x0) {
        puVar12[1] = 0xffffffff;
        puVar12[2] = 0xffffffff;
        puVar12[3] = 0;
        puVar12[7] = 0;
        puVar12[4] = 0xf431d;
        *puVar12 = FoxUI::FXUIEventI3::vftable;
        puVar12[5] = local_38;
        puVar12[6] = local_34;
        FUN_004072a0();
        ExceptionList = local_14;
        return 1;
      }
      FUN_004072a0();
      ExceptionList = local_14;
      return 1;
    }
  }
  local_50 = 0;
  if ((_DAT_00fb79ec & 1) == 0) {
    _DAT_00fb79ec = _DAT_00fb79ec | 1;
    DAT_00fb79f0 = CCheckPointMgr::vftable;
    DAT_00fb79f4 = 0;
    DAT_00fb79f8 = 0;
    DAT_00fb79fc = 0;
    DAT_00fb7a04 = 1;
    _atexit((_func_4879 *)&LAB_00bcd270);
  }
  iVar8 = FUN_00544bc0(&DAT_00fb79f0,local_24,local_30,&local_50);
  if (iVar8 != 0) {
    iVar8 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    local_38 = *(float *)(local_50 + 0xa0) - *(float *)(iVar8 + 0xa0);
    local_34 = *(float *)(local_50 + 0xa4) - *(float *)(iVar8 + 0xa4);
    local_4c = local_38 * local_38 + local_34 * local_34;
    if ((local_4c < *(float *)(local_50 + 0xfc) * *(float *)(local_50 + 0xfc)) && (local_60 == 0)) {
      if (DAT_00fba80c == 0) {
        iVar8 = FUN_00891268(0x57c);
        if (iVar8 == 0) {
          DAT_00fba80c = 0;
        }
        else {
          DAT_00fba80c = FUN_006f1370();
        }
      }
      if ((*(int *)(DAT_00fba80c + 0x20) != 0) && (*(char *)(DAT_00fba80c + 0x369) == '\x03')) {
LAB_004e0eb8:
        FUN_00444960();
        local_38 = 1.82169e-44;
        local_34 = 1.4013e-45;
        FUN_0041e560();
      }
    }
  }
  ExceptionList = local_14;
  return 1;
}

