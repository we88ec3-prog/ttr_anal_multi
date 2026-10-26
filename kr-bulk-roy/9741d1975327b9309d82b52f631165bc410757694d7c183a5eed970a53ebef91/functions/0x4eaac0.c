
undefined4 FUN_004eaac0(int param_1)

{
  char cVar1;
  short sVar2;
  code *pcVar3;
  undefined4 uVar4;
  short *psVar5;
  uint uVar6;
  int iVar7;
  short *psVar8;
  int in_ECX;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092fd30;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == '\0') {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 0;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
    }
    local_8 = 0xffffffff;
    FUN_00402160();
    local_8 = 1;
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 2;
      local_8._1_3_ = 0;
      FUN_00584c40();
      _atexit(FUN_00bcf370);
      local_8 = CONCAT31(local_8._1_3_,1);
    }
    FUN_005740f0();
    if (local_14 == DAT_00fe5b10) {
      pcVar3 = (code *)swi(3);
      uVar4 = (*pcVar3)();
      return uVar4;
    }
    psVar5 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar5 = *(short **)psVar5;
    }
    psVar8 = psVar5;
    do {
      sVar2 = *psVar8;
      psVar8 = psVar8 + 1;
    } while (sVar2 != 0);
    FUN_00402160(psVar5,(int)psVar8 - (int)(psVar5 + 1) >> 1);
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
    psVar5 = (short *)(param_1 + 3);
    do {
      sVar2 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar2 != 0);
    FUN_00402160();
    uVar6 = 0;
    if (*(int *)(in_ECX + 0x5f04) != 0) {
      do {
        if (*(uint *)(in_ECX + 0x5f08) < 8) {
          iVar7 = in_ECX + 0x5ef4;
        }
        else {
          iVar7 = *(int *)(in_ECX + 0x5ef4);
        }
        if (*(short *)(iVar7 + uVar6 * 2) == 0xb4) {
          if (*(uint *)(in_ECX + 0x5f08) < 8) {
            iVar7 = in_ECX + 0x5ef4;
          }
          else {
            iVar7 = *(int *)(in_ECX + 0x5ef4);
          }
          *(undefined2 *)(iVar7 + uVar6 * 2) = 0x27;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < *(uint *)(in_ECX + 0x5f04));
    }
  }
  else {
    if (cVar1 == '\x01') {
      if ((DAT_00faadd4 & 1) == 0) {
        DAT_00faadd4 = DAT_00faadd4 | 1;
        local_8 = 3;
        FUN_00587480();
        _atexit((_func_4879 *)&LAB_00bcccc0);
      }
      local_8 = 0xffffffff;
      FUN_00402160();
      local_8 = 4;
      iVar7 = FUN_005854b0();
      FUN_005740f0();
      if (in_ECX == *(int *)(iVar7 + 4)) {
        pcVar3 = (code *)swi(3);
        uVar4 = (*pcVar3)();
        return uVar4;
      }
      psVar5 = (short *)(in_ECX + 0x10);
      if (7 < *(uint *)(in_ECX + 0x24)) {
        psVar5 = *(short **)psVar5;
      }
      psVar8 = psVar5;
      do {
        sVar2 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar2 != 0);
      FUN_00402160(psVar5,(int)psVar8 - (int)(psVar5 + 1) >> 1);
    }
    else {
      if (cVar1 != '\x02') goto LAB_004eada1;
      FUN_004054c0();
      FUN_00402250();
      local_8 = 5;
      FUN_005854b0();
      uVar4 = FUN_00585330();
      FUN_00402250(uVar4);
    }
    local_8 = 0xffffffff;
    FUN_0058b270(0xca);
  }
LAB_004eada1:
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 6;
    FUN_00587480();
    _atexit((_func_4879 *)&LAB_00bcccc0);
    local_8 = 0xffffffff;
  }
  FUN_0058aad0();
  ExceptionList = local_10;
  return 0;
}

