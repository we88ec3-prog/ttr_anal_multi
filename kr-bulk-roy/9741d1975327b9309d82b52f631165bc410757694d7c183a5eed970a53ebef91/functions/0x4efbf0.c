
void FUN_004efbf0(int param_1)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  short *psVar8;
  undefined4 uVar9;
  undefined2 local_9c [8];
  undefined4 local_8c;
  undefined2 *local_88;
  undefined2 local_80 [8];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 uStack_68;
  undefined4 uStack_64;
  undefined1 auStack_4c [4];
  undefined1 *local_48;
  int local_44;
  undefined1 *local_40;
  undefined4 local_3c;
  uint local_38;
  undefined4 local_28;
  uint local_24;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0092f9d4;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_4c;
  ExceptionList = &local_14;
  local_44 = param_1;
  if (*(int *)(param_1 + 10) == 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 0;
      FUN_00587480();
      uStack_64 = 0x4efc60;
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_c = 0xffffffff;
    uStack_64 = 0;
    local_40 = (undefined1 *)local_80;
    local_6c = 7;
    local_70 = 0;
    local_88 = &DAT_00bed1fc;
    local_80[0] = 0;
    local_8c = 0x4efc9b;
    FUN_00402160();
    local_c = 1;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c._0_1_ = 2;
      local_c._1_3_ = 0;
      local_88 = (undefined2 *)0x4efcbd;
      FUN_00584c40();
      local_88 = (undefined2 *)0x4efcc7;
      _atexit(FUN_00bcf370);
      local_c = CONCAT31(local_c._1_3_,1);
    }
    local_3c = 0xab;
    local_88 = (undefined2 *)0x4efcea;
    FUN_005740f0();
    if (local_48 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    psVar8 = (short *)(local_48 + 0x10);
    if (7 < *(uint *)(local_48 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    local_48 = (undefined1 *)local_9c;
    local_88 = (undefined2 *)0x7;
    local_8c = 0;
    local_9c[0] = 0;
    psVar3 = psVar8;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar8,(int)psVar3 - (int)(psVar8 + 1) >> 1);
    local_c = 0xffffffff;
    FUN_0058b270(0xca);
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 3;
      FUN_00587480();
      uStack_64 = 0x4efd77;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    uStack_64 = *(undefined4 *)(local_44 + 2);
    uStack_68 = 0xf4272;
    local_6c = 0x4efd94;
    FUN_0058aee0();
    uStack_64 = 0x4efd9e;
    piVar4 = (int *)FUN_00891268();
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4[1] = -1;
      piVar4[2] = -1;
      piVar4[3] = 0;
      piVar4[4] = 0xf4279;
      *piVar4 = (int)FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(piVar4 + 5) = 0;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 4;
      FUN_0074d990();
      uStack_64 = 0x4efdf0;
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      uStack_64 = 0x4efe0c;
      (**(code **)(*DAT_00f95bd4 + 0x15c))();
    }
    if (piVar4 != (int *)0x0) {
      uStack_64 = 0x4efe1f;
      (**(code **)(*piVar4 + 0x10))();
    }
  }
  else {
    uStack_64 = *(undefined4 *)(param_1 + 2);
    uStack_68 = 0x4efe33;
    iVar5 = FUN_004ef160();
    if (iVar5 != 0) {
      if (*(char *)(in_ECX + 0x1a) == '\0') {
        FUN_004054c0();
        uStack_64 = 0;
        local_40 = (undefined1 *)local_80;
        local_88 = (undefined2 *)0x4efe60;
        FUN_00402250();
        local_48 = (undefined1 *)local_9c;
        local_c = 5;
        FUN_00412df0();
        uVar9 = 0xac;
        local_c._0_1_ = 6;
        FUN_005854b0(0xac);
        uVar9 = FUN_00585330(uVar9);
        local_c._0_1_ = 5;
        puVar6 = (undefined4 *)FUN_00424c80(uVar9);
        local_c._0_1_ = 7;
        if (7 < (uint)puVar6[5]) {
          puVar6 = (undefined4 *)*puVar6;
        }
        local_48 = (undefined1 *)local_9c;
        FUN_00402250(puVar6);
        local_c = CONCAT31(local_c._1_3_,8);
        FUN_0058b270(0xca);
        local_c = 0xffffffff;
        if (7 < local_24) {
          uStack_64 = 0x4efef6;
          FUN_0089120c();
        }
        local_24 = 7;
        local_28 = 0;
        local_38 = local_38 & 0xffff0000;
      }
      else {
        *(int *)(in_ECX + 0x20) = *(int *)(in_ECX + 0x20) + 1;
        if (*(int *)(in_ECX + 0x1c) == 0) {
          uStack_64 = 0x4eff23;
          iVar7 = FUN_00891268();
          if (iVar7 != 0) {
            uStack_64 = 1;
            uStack_68 = 0x4eff3a;
            FUN_00753d00();
          }
        }
        else {
          uStack_64 = 0x4eff43;
          iVar7 = FUN_00891268();
          if (iVar7 != 0) {
            uStack_64 = 0;
            uStack_68 = 0x4eff59;
            FUN_00753d00();
          }
        }
        FUN_00404aa0();
        FUN_00750020();
      }
      *(undefined4 *)(iVar5 + 100) = 0;
    }
    uStack_64 = 0x4eff73;
    piVar4 = (int *)FUN_00891268();
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4[1] = -1;
      piVar4[2] = -1;
      piVar4[3] = 0;
      piVar4[4] = 0xf4279;
      *piVar4 = (int)FoxUI::FXUIEventB1::vftable;
      *(undefined1 *)(piVar4 + 5) = 1;
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 9;
      FUN_0074d990();
      uStack_64 = 0x4effc4;
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    if (DAT_00f95bd4 != (int *)0x0) {
      uStack_64 = 0x4effe4;
      (**(code **)(*DAT_00f95bd4 + 0x15c))();
    }
    if (piVar4 != (int *)0x0) {
      uStack_64 = 0x4efff3;
      (**(code **)(*piVar4 + 0x10))();
    }
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_c = 10;
      FUN_00587480();
      uStack_64 = 0x4f001a;
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_c = 0xffffffff;
    }
    uStack_64 = *(undefined4 *)(local_44 + 2);
    uStack_68 = 0xf4272;
    local_6c = 0x4f003b;
    FUN_0058aee0();
  }
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_4c);
  return;
}

