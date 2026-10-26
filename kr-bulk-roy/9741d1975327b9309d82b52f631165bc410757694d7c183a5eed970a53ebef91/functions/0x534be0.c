
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00534be0(uint param_1)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  undefined1 *puVar4;
  DWORD DVar5;
  short *psVar6;
  uint in_ECX;
  short *psVar7;
  int in_EDX;
  int iVar8;
  char local_f4 [16];
  undefined4 local_e4;
  undefined2 *local_e0;
  char **ppcStack_dc;
  undefined2 local_d8 [8];
  undefined4 local_c8;
  int local_c4;
  char **ppcStack_c0;
  undefined ***pppuStack_bc;
  char *local_a4;
  uint local_a0;
  int local_9c;
  char *local_98;
  uint local_94;
  undefined1 local_90 [4];
  undefined4 *local_8c;
  int local_88;
  undefined1 *local_80;
  undefined4 *local_7c;
  int local_78;
  undefined1 *local_70;
  int local_6c;
  undefined **local_68 [3];
  undefined4 local_5c;
  undefined4 local_58;
  undefined **local_54 [7];
  uint local_38;
  int local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0092f45e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_a4;
  ExceptionList = &local_14;
  local_a0 = in_ECX;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0;
    FUN_00587480();
    pppuStack_bc = (undefined ***)0x534c50;
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  if ((DAT_00faadd0 & 1) == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_c = 1;
    FUN_0074d990();
    pppuStack_bc = (undefined ***)0x534c8c;
    _atexit((_func_4879 *)&LAB_00bccc70);
  }
  local_c = 0xffffffff;
  pppuStack_bc = (undefined ***)0x534ca9;
  FUN_00753440();
  *(uint *)(in_ECX + 0x3c) = (uint)*(ushort *)(in_EDX + 2);
  *(uint *)(in_ECX + 0x40) = (uint)*(ushort *)(in_EDX + 4);
  *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(in_EDX + 6);
  pppuStack_bc = *(undefined ****)(in_ECX + 0x4c);
  local_c4 = in_ECX + 0x4c;
  ppcStack_c0 = &local_98;
  local_c8 = 0x534cd7;
  local_6c = local_c4;
  FUN_005359f0();
  local_88 = 0;
  pppuStack_bc = (undefined ***)0x534ce2;
  local_8c = (undefined4 *)FUN_00891268();
  if (local_8c == (undefined4 *)0x0) {
    local_a4 = (char *)0x0;
    pppuStack_bc = (undefined ***)0x5351bc;
    std::exception::exception((exception *)local_68,&local_a4);
    pppuStack_bc = local_68;
    local_68[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    ppcStack_c0 = (char **)&UNK_005351d3;
    __CxxThrowException_8();
  }
  *local_8c = local_8c;
  local_8c[1] = local_8c;
  local_8c[2] = local_8c;
  *(undefined1 *)(local_8c + 4) = 1;
  *(undefined1 *)((int)local_8c + 0x11) = 1;
  local_c = 2;
  local_78 = 0;
  pppuStack_bc = (undefined ***)0x534d27;
  local_7c = (undefined4 *)FUN_00891268();
  if (local_7c == (undefined4 *)0x0) {
    local_98 = (char *)0x0;
    pppuStack_bc = (undefined ***)0x535193;
    std::exception::exception((exception *)local_54,&local_98);
    pppuStack_bc = local_54;
    local_54[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
    ppcStack_c0 = (char **)0x5351aa;
    __CxxThrowException_8();
  }
  *local_7c = local_7c;
  local_7c[1] = local_7c;
  local_7c[2] = local_7c;
  *(undefined1 *)(local_7c + 6) = 1;
  *(undefined1 *)((int)local_7c + 0x19) = 1;
  local_c._0_1_ = 3;
  if ((param_1 < 10) || (local_94 = (param_1 - 10) / 0x1f, local_94 == 0)) {
    if (*(char *)(local_a0 + 0x48) == '\0') {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c._0_1_ = 7;
        FUN_00587480();
        pppuStack_bc = (undefined ***)0x534fe1;
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_c._0_1_ = 3;
      pppuStack_bc = (undefined ***)0x0;
      local_70 = (undefined1 *)local_d8;
      ppcStack_dc = (char **)0x0;
      local_c4 = 7;
      local_c8 = 0;
      local_e0 = &DAT_00bed1fc;
      local_d8[0] = 0;
      local_e4 = 0x535012;
      FUN_00402160();
      local_c._0_1_ = 8;
      local_a4 = &DAT_000000ca;
      ppcStack_dc = (char **)0x535027;
      iVar8 = FUN_005854b0();
      ppcStack_dc = &local_a4;
      local_e0 = (undefined2 *)0x535039;
      FUN_005740f0();
      if (local_94 == *(uint *)(iVar8 + 4)) {
        pcVar3 = (code *)swi(3);
        (*pcVar3)();
        return;
      }
      psVar7 = (short *)(local_94 + 0x10);
      if (7 < *(uint *)(local_94 + 0x24)) {
        psVar7 = *(short **)psVar7;
      }
      local_a4 = local_f4;
      local_e0 = (undefined2 *)0x7;
      local_e4 = 0;
      local_f4[0] = '\0';
      local_f4[1] = '\0';
      psVar6 = psVar7;
      do {
        sVar1 = *psVar6;
        psVar6 = psVar6 + 1;
      } while (sVar1 != 0);
      FUN_00402160(psVar7,(int)psVar6 - (int)(psVar7 + 1) >> 1);
      local_c._0_1_ = 3;
      FUN_0058b270(0xca);
    }
    *(undefined1 *)(local_a0 + 0x48) = 0;
  }
  else {
    local_a0 = 0;
    if (local_94 != 0) {
      iVar8 = in_EDX + 0x1a;
      do {
        pppuStack_bc = (undefined ***)0x534db1;
        local_9c = iVar8;
        FUN_00535980();
        if ((DAT_00fb75b0 & 1) == 0) {
          DAT_00fb75b0 = DAT_00fb75b0 | 1;
          local_c._0_1_ = 4;
          FUN_004f3d80();
          pppuStack_bc = (undefined ***)0x534dd8;
          _atexit((_func_4879 *)&LAB_00bcd1e0);
          local_c._0_1_ = 3;
        }
        pppuStack_bc = (undefined ***)0x534df0;
        pppuStack_bc = (undefined ***)FUN_004f6a30();
        local_38 = local_38 & 0xffff0000;
        local_24 = 7;
        local_28 = 0;
        psVar7 = (short *)pppuStack_bc;
        do {
          sVar1 = *psVar7;
          psVar7 = psVar7 + 1;
        } while (sVar1 != 0);
        ppcStack_c0 = (char **)0x534e2d;
        FUN_00402160();
        local_c._0_1_ = 5;
        if (local_28 == 0) {
          pppuStack_bc = (undefined ***)0x534e48;
          FUN_006bde40();
          ppcStack_c0 = (char **)0x534e55;
          pppuStack_bc = (undefined ***)local_90;
          FUN_0044bbd0();
        }
        if ((DAT_00fab0d8 & 1) == 0) {
          DAT_00fab0d8 = DAT_00fab0d8 | 1;
          local_c._0_1_ = 6;
          _DAT_00fab0e4 = 0;
          pppuStack_bc = (undefined ***)0x534e7a;
          puVar4 = (undefined1 *)FUN_00891268();
          if (puVar4 == (undefined1 *)0x0) {
            local_a4 = (char *)0x0;
            pppuStack_bc = (undefined ***)0x534f95;
            std::exception::exception((exception *)local_68,&local_a4);
            pppuStack_bc = local_68;
            local_68[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            ppcStack_c0 = (char **)0x534fac;
            __CxxThrowException_8();
          }
          DAT_00fab0e0 = puVar4;
          *(undefined1 **)puVar4 = puVar4;
          *(undefined1 **)(DAT_00fab0e0 + 4) = DAT_00fab0e0;
          *(undefined1 **)(DAT_00fab0e0 + 8) = DAT_00fab0e0;
          DAT_00fab0e0[0x20] = 1;
          DAT_00fab0e0[0x21] = 1;
          DAT_00fab0ec = 0;
          _DAT_00fab0f0 = 0;
          _DAT_00fab0f4 = 0;
          pppuStack_bc = (undefined ***)0x534ecb;
          _atexit((_func_4879 *)&LAB_00bccdb0);
          local_c._0_1_ = 5;
        }
        local_5c = *(undefined4 *)(iVar8 + -8);
        local_58 = *(undefined4 *)(iVar8 + -4);
        pppuStack_bc = (undefined ***)&local_70;
        ppcStack_c0 = (char **)&DAT_00fab0dc;
        local_c4 = 0x534ef8;
        FUN_004dd400();
        puVar4 = local_70;
        if (local_70 == DAT_00fab0e0) {
LAB_00534f2c:
          FUN_00536170();
          ppcStack_c0 = (char **)0x534f45;
          pppuStack_bc = (undefined ***)&local_80;
          FUN_00535f20();
        }
        else {
          iVar8 = *(int *)(local_70 + 0x18);
          iVar2 = *(int *)(iVar8 + 0x20);
          DVar5 = timeGetTime();
          if (0x1e < (int)(DVar5 - iVar2)) {
            DVar5 = timeGetTime();
            *(DWORD *)(iVar8 + 0x20) = DVar5;
            goto LAB_00534f2c;
          }
          if (*(int *)(puVar4 + 0x18) == 0) goto LAB_00534f2c;
        }
        local_c._0_1_ = 3;
        if (7 < local_24) {
          pppuStack_bc = (undefined ***)0x534f61;
          FUN_0089120c();
        }
        iVar8 = local_9c + 0x1f;
        local_a0 = local_a0 + 1;
        local_9c = iVar8;
      } while (local_a0 < local_94);
    }
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c._0_1_ = 9;
    FUN_00587480();
    pppuStack_bc = (undefined ***)0x5350ca;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c._0_1_ = 3;
  }
  pppuStack_bc = (undefined ***)0x5350df;
  FUN_0058aad0();
  if (local_88 != 0) {
    pppuStack_bc = (undefined ***)0x5350f2;
    FUN_00534960();
  }
  if (local_78 != 0) {
    pppuStack_bc = (undefined ***)0x535102;
    FUN_00534880();
  }
  local_c = CONCAT31(local_c._1_3_,10);
  pppuStack_bc = (undefined ***)*local_7c;
  ppcStack_c0 = (char **)0x53511f;
  FUN_00535ac0();
  pppuStack_bc = (undefined ***)0x535129;
  FUN_0089120c();
  local_c = 0xb;
  pppuStack_bc = (undefined ***)*local_8c;
  ppcStack_c0 = (char **)0x53514c;
  FUN_004ca160();
  pppuStack_bc = (undefined ***)0x535156;
  FUN_0089120c();
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_a4);
  return;
}

