
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005cbb20(void)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  short *psVar5;
  undefined4 ***pppuVar6;
  int iVar7;
  undefined4 ****ppppuVar8;
  int iVar9;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 uStack_e0;
  int iStack_dc;
  undefined4 ***pppuStack_d8;
  int *piStack_d4;
  float *pfStack_d0;
  short *psStack_cc;
  undefined4 ****ppppuVar10;
  undefined4 ***pppuStack_b4;
  undefined4 ***local_b0;
  int local_ac;
  int local_a8;
  float fStack_a4;
  int iStack_a0;
  int iStack_9c;
  undefined4 **ppuStack_98;
  float fStack_94;
  undefined4 ***pppuStack_90;
  undefined4 local_8c;
  undefined4 **local_84;
  undefined4 ***local_80;
  undefined4 **local_7c;
  undefined4 ***local_78;
  int iStack_74;
  int local_70;
  undefined4 ***local_6c;
  int local_68;
  int local_64;
  undefined4 ***local_60;
  undefined4 local_5c;
  uint uStack_58;
  undefined4 ***pppuStack_54;
  float *pfStack_50;
  undefined4 ***local_4c;
  float *local_48;
  undefined4 ***pppuStack_44;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00912788;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&pppuStack_b4;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xffffff40;
  ExceptionList = &local_14;
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0();
    DAT_00fc18d8 = 1;
    psStack_cc = (short *)0x5cbb8c;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  psStack_cc = DAT_00fc186c;
  if (DAT_00fc1880 < 8) {
    psStack_cc = (short *)&DAT_00fc186c;
  }
  local_5c = (undefined4 *)((uint)local_5c._2_2_ << 0x10);
  local_48 = (float *)0x7;
  local_4c = (undefined4 ****)0x0;
  psVar5 = psStack_cc;
  do {
    sVar1 = *psVar5;
    psVar5 = psVar5 + 1;
  } while (sVar1 != 0);
  pfStack_d0 = (float *)0x5cbbda;
  FUN_00402160();
  local_c = 0;
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0();
    DAT_00fc18d8 = 1;
    psStack_cc = (short *)0x5cbc05;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  local_70 = DAT_00fc18a4;
  if ((_DAT_00fc183c & 1) == 0) {
    _DAT_00fc183c = _DAT_00fc183c | 1;
    FUN_006f1ff0();
    DAT_00fc18d8 = 1;
    psStack_cc = (short *)0x5cbc36;
    _atexit((_func_4879 *)&LAB_00bce3a0);
  }
  local_ac = DAT_00fc18ac;
  iVar7 = *(int *)(local_a8 + 4);
  piVar2 = *(int **)(iVar7 + 0x14);
  local_8c = DAT_00fc18a8;
  if (piVar2 != (int *)0x0) {
    local_84 = *(undefined4 ***)(iVar7 + 4);
    local_80 = *(undefined4 ****)(iVar7 + 8);
    piVar3 = (int *)piVar2[0x3d];
    local_7c = local_84;
    local_78 = local_80;
    if (piVar3 != (int *)0x0) {
      local_b0 = (undefined4 ***)piVar3[4];
      local_60 = (undefined4 ***)0x0;
      local_64 = 0;
      local_68 = 0;
      local_6c = (undefined4 ****)0x0;
      fStack_a4 = (float)(**(code **)(*piVar2 + 0x1a8))();
      pppuVar6 = (undefined4 ***)FUN_008fed10();
      ppuStack_98 = pppuVar6;
      fStack_a4 = (float)(**(code **)(*piVar2 + 0x1ac))();
      iStack_a0 = FUN_008fed10();
      pppuStack_b4 = local_4c;
      if ((int)local_4c < 1) {
        fStack_94 = (float)(int)local_b0;
        local_6c = pppuVar6;
        local_68 = iStack_a0;
        local_64 = FUN_008fed10();
        local_64 = (int)pppuVar6 - local_64;
        iVar7 = FUN_008fed10();
        local_60 = (undefined4 ***)(iStack_a0 - iVar7);
      }
      else {
        iStack_74 = 0;
        fStack_a4 = 0.0;
        psStack_cc = (short *)local_5c;
        if (local_48 < (float *)0x8) {
          psStack_cc = (short *)&local_5c;
        }
        pfStack_d0 = &fStack_a4;
        piStack_d4 = &iStack_74;
        pppuStack_d8 = (undefined4 ***)0x5cbd1d;
        ppppuVar10 = (undefined4 ****)local_4c;
        (**(code **)(*piVar3 + 0x30))();
        fStack_a4 = (float)unaff_EDI;
        iStack_74 = (int)local_84 + (int)pppuVar6;
        local_78 = local_b0;
        pppuStack_d8 = (undefined4 ***)0x5cbd4a;
        local_7c = pppuVar6;
        iStack_a0 = FUN_008fed10();
        iStack_a0 = (int)local_b0 - iStack_a0;
        pppuStack_d8 = (undefined4 ***)0xff7d7d7d;
        iStack_dc = 0x5cbd6d;
        local_70 = iStack_a0;
        FUN_005cb290();
        iStack_dc = piVar2[0x3e];
        ppppuVar8 = (undefined4 ****)local_6c;
        if (uStack_58 < 8) {
          ppppuVar8 = &local_6c;
        }
        pppuStack_d8 = (undefined4 ****)0x1;
        uStack_e0 = 0;
        pppuVar6 = &local_7c;
        (**(code **)(*piVar3 + 0x2c))(ppppuVar8,pppuVar6);
        piStack_d4 = (int *)((int)pfStack_d0 - (int)local_b0);
        if ((int)piStack_d4 < 1) {
          pppuStack_54 = (undefined4 ****)0x0;
          pfStack_50 = (float *)0x0;
          local_48 = (float *)0x0;
          pppuStack_44 = (undefined4 ****)0x0;
          local_60 = (undefined4 ***)0x0;
          local_5c = (undefined4 *)0x0;
          local_4c = pppuStack_d8;
        }
        else {
          local_48 = pfStack_d0;
          pfStack_50 = pfStack_d0;
          local_4c = local_b0;
          pppuStack_54 = local_b0;
          local_60 = (undefined4 ***)0x2;
          pppuStack_44 = pppuStack_d8;
          local_5c = (undefined4 *)0x1;
        }
        local_5c = (undefined4 *)(uint)((int)piStack_d4 >= 1);
        local_64 = 1;
        uStack_58 = 0;
        pppuStack_d8 = (undefined4 ***)0x0;
        pfStack_50 = local_48;
        do {
          if (*(int *)((int)&local_64 + (int)pppuStack_d8) != 0) {
            iVar7 = *(int *)((int)&uStack_58 + (int)pppuStack_d8);
            iVar9 = *(int *)((int)&local_4c + (int)pppuStack_d8) - iVar7;
            if (0 < iVar9) {
              local_ac = 0;
              pfStack_d0 = (float *)0x0;
              ppppuVar8 = (undefined4 ****)local_80;
              if (local_6c < (undefined4 ****)0x8) {
                ppppuVar8 = &local_80;
              }
              (**(code **)(*piVar3 + 0x30))(&local_ac,&pfStack_d0,ppppuVar8,iVar7);
              ppppuVar8 = (undefined4 ****)pppuStack_90;
              if (local_7c < (undefined4 ***)0x8) {
                ppppuVar8 = &pppuStack_90;
              }
              (**(code **)(*piVar3 + 0x30))(&pfStack_d0,&uStack_e0,(int)ppppuVar8 + iVar7 * 2,iVar9)
              ;
              iVar7 = (int)ppppuVar10 + uVar4;
              if (*(int *)((int)&local_64 + (int)pppuStack_d8) == 1) {
                if (*(int *)(*(int *)((int)psStack_cc + 4) + 0x38) != 0) {
                  FUN_00775750(unaff_ESI + local_ac,iVar7,iVar7);
                  iStack_9c = 0x3f800000;
                  iStack_a0 = 0x3f800000;
LAB_005cbf7a:
                  FUN_00775960(0x3f800000,0x3f800000);
                }
              }
              else if ((*(int *)((int)&local_64 + (int)pppuStack_d8) == 2) &&
                      (*(int *)(*(int *)((int)psStack_cc + 4) + 0x38) != 0)) {
                FUN_00775750(unaff_ESI + local_ac,iVar7,iVar7);
                fStack_a4 = 1.0;
                local_a8 = 0x3f800000;
                goto LAB_005cbf7a;
              }
            }
          }
          pppuStack_d8 = pppuStack_d8 + 1;
        } while ((int)pppuStack_d8 < 0xc);
        if ((int)piStack_d4 < 1) {
          piStack_d4 = (int *)0x0;
          pppuStack_b4 = (undefined4 ****)0x0;
          ppppuVar8 = (undefined4 ****)local_80;
          if (local_6c < (undefined4 ****)0x8) {
            ppppuVar8 = &local_80;
          }
          (**(code **)(*piVar3 + 0x30))(&piStack_d4,&pppuStack_b4,ppppuVar8,fStack_94);
          iVar7 = iStack_a0;
          pppuVar6 = (undefined4 ***)((int)local_b0 + (int)ppuStack_98);
          local_68 = iStack_a0;
          local_6c = pppuVar6;
          local_64 = FUN_008fed10();
          local_64 = (int)pppuVar6 - local_64;
          iVar9 = FUN_008fed10();
          local_60 = (undefined4 ***)(iVar7 - iVar9);
        }
        else {
          pppuStack_d8 = (undefined4 ***)0x0;
          pfStack_d0 = (float *)0x0;
          ppppuVar8 = (undefined4 ****)local_80;
          if (local_6c < (undefined4 ****)0x8) {
            ppppuVar8 = &local_80;
          }
          (**(code **)(*piVar3 + 0x30))(&pppuStack_d8,&pfStack_d0,ppppuVar8,local_b0);
          ppppuVar8 = (undefined4 ****)pppuStack_90;
          if (local_7c < (undefined4 ***)0x8) {
            ppppuVar8 = &pppuStack_90;
          }
          (**(code **)(*piVar3 + 0x30))(&pfStack_d0,&uStack_e0,ppppuVar8,pppuVar6);
          local_6c = (undefined4 ***)((int)pppuStack_b4 + (int)ppuStack_98);
          local_68 = iStack_a0;
          local_64 = iStack_9c + (int)local_6c;
          local_60 = pppuStack_90;
        }
      }
      psStack_cc = (short *)0x5cc100;
      FUN_005cb290();
    }
  }
  if ((float *)0x7 < local_48) {
    psStack_cc = (short *)0x5cc111;
    FUN_0089120c();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&pppuStack_b4);
  return;
}

