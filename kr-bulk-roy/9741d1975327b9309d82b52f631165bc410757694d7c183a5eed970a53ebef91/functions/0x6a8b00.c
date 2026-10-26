
void FUN_006a8b00(void)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  short *psVar7;
  int *in_ECX;
  uint uVar8;
  int iVar9;
  int *piVar10;
  short *psVar11;
  undefined2 local_a4 [8];
  undefined4 local_94;
  undefined2 *local_90;
  undefined2 local_88 [8];
  undefined4 local_78;
  int local_74;
  int iStack_70;
  int iStack_6c;
  int local_54;
  undefined1 *local_50;
  undefined1 *local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_3c;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093c344;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_54;
  ExceptionList = &local_14;
  uVar8 = DAT_00fbad10 & 1;
  in_ECX[0x43] = -1;
  local_3c = in_ECX;
  if (uVar8 == 0) {
    DAT_00fbad10 = DAT_00fbad10 | 1;
    local_c = 0;
    FUN_004e8010();
    iStack_6c = 0x6a8b6f;
    _atexit((_func_4879 *)&LAB_00bcd6b0);
  }
  if ((DAT_00fc16e8 & 1) == 0) {
    DAT_00fc16e8 = DAT_00fc16e8 | 1;
    local_c = 1;
    FUN_0082aa80();
    iStack_6c = 0x6a8b98;
    _atexit(FUN_00bce450);
  }
  local_c = 0xffffffff;
  piVar6 = (int *)*DAT_00fc16f0;
  local_54 = 6;
  if (DAT_00fc0be8 + 1 < 7) {
    local_54 = DAT_00fc0be8 + 1;
  }
  if (piVar6 != DAT_00fc16f0) {
    do {
      local_48 = piVar6[4];
      local_44 = piVar6[5];
      local_40 = piVar6[6];
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 2;
        FUN_004e1590();
        iStack_6c = 0x6a8c0c;
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      local_4c = (undefined1 *)0x0;
      if (DAT_00f94300 != -0x16f8) {
        local_4c = (undefined1 *)FUN_005090e0();
      }
      iVar4 = DAT_00fc0c40 - (int)DAT_00fc0c3c >> 0x1f;
      iVar9 = (DAT_00fc0c40 - (int)DAT_00fc0c3c) / 0xc + iVar4;
      uVar8 = 0;
      piVar10 = DAT_00fc0c3c;
      if (iVar9 != iVar4) {
        do {
          if (*piVar10 == local_54) break;
          uVar8 = uVar8 + 1;
          piVar10 = piVar10 + 3;
        } while (uVar8 < (uint)(iVar9 - iVar4));
      }
      if (local_4c != (undefined1 *)0x0) {
        in_ECX[0x43] = local_48;
        if (DAT_00fc0be8 == 6) {
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c = 3;
            iStack_6c = 0x6a8e0b;
            FUN_00584c40();
            iStack_6c = 0x6a8e15;
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c = 0xffffffff;
          }
          local_54 = 0xe;
          iStack_6c = 0x6a8e37;
          FUN_005740f0();
          if (local_50 == (undefined1 *)DAT_00fe5ac8) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          FUN_004ed610();
          local_c = 4;
          iStack_6c = 0x6a8e82;
          FUN_00757800();
        }
        else {
          if ((DAT_00fe5ae4 & 1) == 0) {
            DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
            local_c = 5;
            iStack_6c = 0x6a8ec0;
            FUN_00584c40();
            iStack_6c = 0x6a8eca;
            _atexit((_func_4879 *)&LAB_00bcf390);
            local_c = 0xffffffff;
          }
          local_50 = (undefined1 *)0xe;
          iStack_6c = 0x6a8eec;
          FUN_005740f0();
          if (local_54 == DAT_00fe5ac8) {
            pcVar3 = (code *)swi(3);
            (*pcVar3)();
            return;
          }
          FUN_004068f0();
          local_c = 6;
          iStack_6c = 0x6a8f34;
          FUN_00757800();
        }
        local_c = 0xffffffff;
        if (7 < local_24) {
          local_c = 0xffffffff;
          iStack_6c = 0x6a8f4c;
          FUN_0089120c();
        }
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_c = 7;
          iStack_6c = 0x6a8f71;
          FUN_00584c40();
          iStack_6c = 0x6a8f7b;
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_c = 0xffffffff;
        }
        local_50 = (undefined1 *)0xf;
        iStack_6c = 0x6a8fa1;
        FUN_005740f0();
        if (local_54 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        FUN_004068f0();
        local_c = 8;
        iStack_6c = 0x6a8fe8;
        FUN_00757800();
        local_c = 0xffffffff;
        if (7 < local_24) {
          iStack_6c = 0x6a9000;
          FUN_0089120c();
        }
        (**(code **)(*(int *)in_ECX[0x3e] + 200))();
        (**(code **)(*(int *)in_ECX[0x3d] + 200))();
        if ((DAT_00fe5ae4 & 1) == 0) {
          DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
          local_c = 9;
          iStack_6c = 0x6a9045;
          FUN_00584c40();
          iStack_6c = 0x6a904f;
          _atexit((_func_4879 *)&LAB_00bcf390);
          local_c = 0xffffffff;
        }
        local_50 = (undefined1 *)0x10;
        iStack_6c = 0x6a9075;
        FUN_005740f0();
        if (local_54 == DAT_00fe5ac8) {
          pcVar3 = (code *)swi(3);
          (*pcVar3)();
          return;
        }
        FUN_004068f0();
        local_c = 10;
        iStack_6c = 0x6a90c0;
        FUN_00757800();
        local_c = 0xffffffff;
        if (7 < local_24) {
          iStack_6c = 0x6a90d8;
          FUN_0089120c();
        }
        (**(code **)(*(int *)in_ECX[0x3f] + 200))();
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 0xb;
          FUN_0051c120();
          iStack_6c = 0x6a9118;
          _atexit((_func_4879 *)&LAB_00bccc90);
          local_c = 0xffffffff;
        }
        iVar4 = local_48;
        iStack_6c = 0x6a9132;
        piVar6 = (int *)FUN_0051d700();
        if (piVar6 != (int *)0x0) {
          local_74 = *piVar6;
          iStack_6c = 0;
          iStack_70 = iVar4;
          local_78 = 0x6a9145;
          FUN_005d7240();
          iStack_6c = 0x6a9151;
          FUN_005d7af0();
        }
        (**(code **)(*(int *)in_ECX[0x42] + 200))();
        in_ECX[10] = in_ECX[10] | 0x100;
        if ((((in_ECX[9] != 0) && (0 < in_ECX[0xd] - in_ECX[0xb])) &&
            (0 < in_ECX[0xe] - in_ECX[0xc])) && ((in_ECX[10] & 0x100000U) == 0)) {
          local_74 = in_ECX[0xb];
          iStack_70 = in_ECX[0xc];
          iStack_6c = in_ECX[0xd];
          local_78 = 0x6a91ae;
          FUN_00753020();
        }
        if ((*(byte *)(in_ECX + 10) & 0x10) == 0) {
          if (in_ECX[0x18] == 0) goto LAB_006a924c;
          in_ECX = (int *)FUN_00745c20();
        }
        if (((in_ECX != (int *)0x0) && (in_ECX[0x18] != 0)) && (((uint)in_ECX[10] >> 0xc & 1) == 0))
        {
          iStack_6c = 0x6a91e8;
          FUN_0074a010();
        }
        goto LAB_006a924c;
      }
      if (*(char *)((int)piVar6 + 0x1d) == '\0') {
        piVar10 = (int *)piVar6[2];
        if (*(char *)((int)piVar10 + 0x1d) == '\0') {
          cVar1 = *(char *)(*piVar10 + 0x1d);
          piVar6 = piVar10;
          piVar10 = (int *)*piVar10;
          while (cVar1 == '\0') {
            cVar1 = *(char *)(*piVar10 + 0x1d);
            piVar6 = piVar10;
            piVar10 = (int *)*piVar10;
          }
        }
        else {
          cVar1 = *(char *)(piVar6[1] + 0x1d);
          piVar5 = (int *)piVar6[1];
          piVar10 = piVar6;
          while ((piVar6 = piVar5, cVar1 == '\0' && (piVar10 == (int *)piVar6[2]))) {
            cVar1 = *(char *)(piVar6[1] + 0x1d);
            piVar5 = (int *)piVar6[1];
            piVar10 = piVar6;
          }
        }
      }
    } while (piVar6 != DAT_00fc16f0);
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_c = 0xc;
    FUN_00587480();
    iStack_6c = 0x6a8d15;
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_c = 0xffffffff;
  }
  iStack_6c = 0;
  local_4c = (undefined1 *)local_88;
  local_74 = 7;
  local_78 = 0;
  local_90 = &DAT_00bed1fc;
  local_88[0] = 0;
  local_94 = 0x6a8d48;
  FUN_00402160();
  local_c = 0xd;
  if ((DAT_00fe5b2c & 1) == 0) {
    DAT_00fe5b2c = DAT_00fe5b2c | 1;
    local_c._0_1_ = 0xe;
    local_c._1_3_ = 0;
    local_90 = (undefined2 *)0x6a8d73;
    FUN_00584c40();
    local_90 = (undefined2 *)0x6a8d7d;
    _atexit(FUN_00bcf370);
    local_c = CONCAT31(local_c._1_3_,0xd);
  }
  local_50 = (undefined1 *)0x90;
  local_90 = (undefined2 *)0x6a8d9f;
  FUN_005740f0();
  if (local_54 == DAT_00fe5b10) {
    pcVar3 = (code *)swi(3);
    (*pcVar3)();
    return;
  }
  psVar11 = (short *)(local_54 + 0x10);
  if (7 < *(uint *)(local_54 + 0x24)) {
    psVar11 = *(short **)psVar11;
  }
  local_50 = (undefined1 *)local_a4;
  local_90 = (undefined2 *)0x7;
  local_94 = 0;
  local_a4[0] = 0;
  psVar7 = psVar11;
  do {
    sVar2 = *psVar7;
    psVar7 = psVar7 + 1;
  } while (sVar2 != 0);
  FUN_00402160(psVar11,(int)psVar7 - (int)(psVar11 + 1) >> 1);
  local_c = 0xffffffff;
  FUN_0058b270(0xca);
  (**(code **)(*local_3c + 0xd4))();
LAB_006a924c:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_54);
  return;
}

