
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00561760(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  undefined4 **ppuVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  HANDLE hHandle;
  int in_ECX;
  undefined4 *puVar10;
  undefined4 *local_64;
  int local_60;
  int *local_5c;
  undefined4 *local_58;
  uint local_54;
  undefined4 local_44;
  uint local_40;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  uint local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093fd2c;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)&local_64;
  ExceptionList = &local_14;
  if (DAT_00fbab18 != 0) {
    _DAT_00fbab24 = 0;
    iVar4 = FUN_0040f060();
    *(undefined4 *)(iVar4 + 0xac) = 0x3dcccccd;
  }
  *(undefined1 *)(in_ECX + 0x89) = 0;
  if (*(int *)(in_ECX + 0x28) == 0) {
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_c = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
      local_c = 0xffffffff;
    }
    if ((((DAT_00fb92f1 == '\0') || (param_1 != 0)) ||
        ((iVar4 = FUN_00404ba0(), *(int *)(iVar4 + 0x5f4c) != 9 &&
         ((iVar4 = FUN_00404ba0(), *(int *)(iVar4 + 0x5f4c) != 4 &&
          (iVar4 = FUN_00404ba0(), *(int *)(iVar4 + 0x5f4c) != 0x19)))))) ||
       (iVar4 = *(int *)(in_ECX + 0x78), piVar5 = (int *)FUN_004364c0(), *piVar5 == iVar4)) {
      uVar2 = DAT_00faadd4 & 1;
      *(int *)(in_ECX + 0x38) = param_1;
      *(int *)(in_ECX + 0x3c) = param_2;
      *(undefined4 *)(in_ECX + 0x28) = 1;
      if (uVar2 == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 2;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      if ((DAT_00faadd0 & 1) == 0) {
        DAT_00faadd0 = DAT_00faadd0 | 1;
        local_c = 3;
        FUN_0074d990();
        _atexit((_func_4879 *)&LAB_00bccc70);
        local_c = 0xffffffff;
      }
      uVar2 = DAT_00f94390 & 1;
      local_60 = DAT_00f95bbc;
      local_5c = DAT_00f95bc0;
      *(int *)(in_ECX + 0x84) = DAT_00f95bbc;
      if (uVar2 == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 4;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      uVar2 = DAT_00faadd4 & 1;
      *(undefined1 *)(in_ECX + 0x88) = DAT_00f942a4;
      if (uVar2 == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_c = 5;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
        local_c = 0xffffffff;
      }
      FUN_0058aad0();
      if ((DAT_00f94390 & 1) == 0) {
        DAT_00f94390 = DAT_00f94390 | 1;
        local_c = 6;
        FUN_004e1590();
        _atexit((_func_4879 *)&LAB_00bccc80);
        local_c = 0xffffffff;
      }
      DAT_00f942a4 = 1;
      FUN_00402a70();
      puVar9 = *(undefined4 **)(in_ECX + 0xc);
      cVar3 = *(char *)((int)puVar9[1] + 0x31);
      local_58 = puVar9;
      puVar10 = (undefined4 *)puVar9[1];
      while (cVar3 == '\0') {
        if (((int)puVar10[3] < param_1) ||
           (((int)puVar10[3] <= param_1 && ((int)puVar10[4] < param_2)))) {
          puVar6 = (undefined4 *)puVar10[2];
          puVar10 = local_58;
        }
        else {
          puVar6 = (undefined4 *)*puVar10;
        }
        local_58 = puVar10;
        puVar10 = puVar6;
        cVar3 = *(char *)((int)puVar6 + 0x31);
      }
      if (((local_58 == puVar9) || (param_1 < (int)local_58[3])) ||
         ((param_1 <= (int)local_58[3] && (param_2 < (int)local_58[4])))) {
        local_64 = puVar9;
        ppuVar7 = &local_64;
      }
      else {
        ppuVar7 = &local_58;
      }
      puVar9 = *ppuVar7;
      if (puVar9 == *(undefined4 **)(in_ECX + 0xc)) {
        FUN_00561db0();
      }
      else {
        local_40 = 0xf;
        local_44 = 0;
        local_54 = local_54 & 0xffffff00;
        FUN_00402a70();
        local_c = 7;
        FUN_00401ed0(puVar9 + 5);
        FUN_00401fc0();
        FUN_0055c5a0();
        uVar8 = FUN_0055d6a0();
        *(undefined4 *)(in_ECX + 0x70) = uVar8;
        puVar9 = (undefined4 *)FUN_00891268();
        if (puVar9 != (undefined4 *)0x0) {
          *puVar9 = 0;
          *(undefined1 *)(puVar9 + 2) = 1;
          puVar9[3] = 0;
          puVar9[4] = 0;
          puVar9[5] = 0;
        }
        local_60 = 0;
        local_5c = (int *)0x0;
        FUN_0047c0d0();
        iVar4 = local_60;
        local_c = CONCAT31(local_c._1_3_,8);
        *(undefined4 *)(local_60 + 4) = 3;
        *(undefined1 *)(local_60 + 8) = 1;
        local_58 = (undefined4 *)**(undefined4 **)(*(int *)(in_ECX + 0x70) + 4);
        if (local_58 != *(undefined4 **)(*(int *)(in_ECX + 0x70) + 4)) {
          do {
            local_64 = (undefined4 *)(uint)*(ushort *)local_58[4];
            FUN_004a8680();
            FUN_0049e6a0();
          } while (local_58 != *(undefined4 **)(*(int *)(in_ECX + 0x70) + 4));
        }
        local_64 = (undefined4 *)&stack0xffffff84;
        puVar9 = (undefined4 *)&stack0xffffff84;
        if ((local_5c != (int *)0x0) && (cVar3 = FUN_0047c250(), puVar9 = local_64, cVar3 != '\0'))
        {
          FUN_007a31c0(iVar4,local_5c);
          puVar9 = local_64;
        }
        local_64 = puVar9;
        uVar2 = local_c >> 8;
        if ((DAT_00fc0f60 & 1) == 0) {
          DAT_00fc0f60 = DAT_00fc0f60 | 1;
          local_c._0_1_ = 10;
          FUN_0079cf40();
          _atexit((_func_4879 *)&LAB_00bcdb80);
          uVar2 = (uint)local_c._1_3_;
        }
        local_c._1_3_ = (uint3)uVar2;
        local_c._0_1_ = 8;
        hHandle = (HANDLE)FUN_0079dce0();
        WaitForSingleObject(hHandle,0xffffffff);
        CloseHandle(hHandle);
        if ((DAT_00fe1770 & 1) == 0) {
          DAT_00fe1770 = DAT_00fe1770 | 1;
          local_c._0_1_ = 0xb;
          FUN_007b7da0();
          _atexit((_func_4879 *)&LAB_00bce790);
          local_c._0_1_ = 8;
        }
        iVar4 = DAT_00fe173c;
        piVar5 = (int *)**(int **)(DAT_00fe173c + 4);
        if (piVar5 != *(int **)(DAT_00fe173c + 4)) {
          do {
            if (((int *)piVar5[9])[1] == 0) {
              (**(code **)(*(int *)piVar5[9] + 4))();
            }
            piVar5 = (int *)*piVar5;
          } while (piVar5 != (int *)*(int *)(iVar4 + 4));
        }
        FUN_006f4a50();
        if ((_DAT_00fb79ec & 1) == 0) {
          _DAT_00fb79ec = _DAT_00fb79ec | 1;
          DAT_00fb79f0 = CCheckPointMgr::vftable;
          DAT_00fb79f4 = 0;
          DAT_00fb79f8 = 0;
          DAT_00fb79fc = 0;
          DAT_00fb7a04 = 1;
          _atexit((_func_4879 *)&LAB_00bcd270);
        }
        DAT_00fb7a04 = 0;
        if ((DAT_00fc0f60 & 1) == 0) {
          DAT_00fc0f60 = DAT_00fc0f60 | 1;
          local_c._0_1_ = 0xc;
          FUN_0079cf40();
          _atexit((_func_4879 *)&LAB_00bcdb80);
          local_c._0_1_ = 8;
        }
        FUN_0079d9c0();
        if ((DAT_00fd94d8 & 1) == 0) {
          DAT_00fd94d8 = DAT_00fd94d8 | 1;
          local_c._0_1_ = 0xd;
          FUN_007b5430();
          _atexit((_func_4879 *)&LAB_00bce660);
        }
        piVar5 = local_5c;
        local_c = CONCAT31(local_c._1_3_,7);
        _DAT_00fd94b0 = 2;
        if (local_5c != (int *)0x0) {
          LOCK();
          iVar4 = local_5c[1] + -1;
          local_5c[1] = iVar4;
          UNLOCK();
          if (iVar4 == 0) {
            (**(code **)*local_5c)();
            piVar1 = piVar5 + 2;
            LOCK();
            iVar4 = *piVar1 + -1;
            *piVar1 = iVar4;
            UNLOCK();
            if (iVar4 == 0) {
              (**(code **)(*piVar5 + 4))();
            }
          }
        }
        if (0xf < local_40) {
          FUN_0089120c();
        }
      }
    }
    else {
      FUN_005855b0();
      FUN_00585330();
      FUN_00402250();
      local_c = 1;
      FUN_0040f8c0();
      FUN_004d6b30();
      local_c = 0xffffffff;
      FUN_004fa440();
      FUN_00414680();
      FUN_004a39a0();
      FUN_005620b0();
    }
  }
  else {
    FUN_006edb60(&DAT_00c106ac);
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)&local_64);
  return;
}

