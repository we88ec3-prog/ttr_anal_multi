
void FUN_0068c790(int param_1)

{
  ushort uVar1;
  code *pcVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  ushort *puVar7;
  undefined4 uVar8;
  bool bVar9;
  undefined4 uVar10;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00942c10;
  local_10 = ExceptionList;
  local_14 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar4 = *(int *)(param_1 + 0xf4);
  if (*(char *)(iVar4 + 0x141) != '\0') {
    FUN_006edb10("Not supported operation",local_14);
  }
  local_30 = (ushort *)((uint)local_30._2_2_ << 0x10);
  local_1c = 7;
  local_20 = 0;
  FUN_004026e0(iVar4 + 0x108,0,0xffffffff);
  local_8._0_1_ = 0;
  local_8._1_3_ = 0;
  puVar3 = local_30;
  if (local_1c < 8) {
    puVar3 = (ushort *)&local_30;
  }
  puVar7 = &DAT_00bed1fc;
  do {
    uVar1 = *puVar3;
    bVar9 = uVar1 < *puVar7;
    if (uVar1 != *puVar7) {
LAB_0068c83c:
      iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
      goto LAB_0068c841;
    }
    if (uVar1 == 0) break;
    uVar1 = puVar3[1];
    bVar9 = uVar1 < puVar7[1];
    if (uVar1 != puVar7[1]) goto LAB_0068c83c;
    puVar3 = puVar3 + 2;
    puVar7 = puVar7 + 2;
  } while (uVar1 != 0);
  iVar4 = 0;
LAB_0068c841:
  if (iVar4 == 0) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 1;
      local_8._1_3_ = 0;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_8._0_1_ = 0;
    local_38 = 0x196;
    FUN_005740f0(&local_38);
    if (local_34 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_8._0_1_ = 2;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_8._0_1_ = 0;
    }
    local_34 = 0x38;
    FUN_005740f0(&local_34);
    if (local_38 == DAT_00fe5b10) {
      pcVar2 = (code *)swi(3);
      (*pcVar2)();
      return;
    }
    if (*(uint *)(local_38 + 0x24) < 8) {
      iVar4 = local_38 + 0x10;
    }
    else {
      iVar4 = *(int *)(local_38 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_8._0_1_ = 3;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_8._0_1_ = 0;
    }
    FUN_007532b0(&DAT_00f94810,iVar4,0,0);
    goto joined_r0x0068cafe;
  }
  iVar4 = *(int *)(*(int *)(param_1 + 0xf8) + 0x24c);
  uVar8 = 4;
  if (iVar4 != 0) {
    iVar4 = *(int *)(iVar4 + 0xcc);
    if (iVar4 == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = *(int *)(iVar4 + 0xdc);
    }
    if ((iVar4 != 0) && (*(int *)(iVar4 + 0x20) != -1)) {
      iVar4 = *(int *)(*(int *)(param_1 + 0xf8) + 0x24c);
      if (iVar4 != 0) {
        iVar4 = *(int *)(iVar4 + 0xcc);
        if (iVar4 == 0) {
          iVar4 = 0;
        }
        else {
          iVar4 = *(int *)(iVar4 + 0xdc);
        }
        if (iVar4 != 0) {
          switch(*(undefined4 *)(iVar4 + 0x20)) {
          case 0:
            uVar8 = 1;
            break;
          case 1:
            uVar8 = 2;
            break;
          case 2:
            uVar8 = 3;
          }
        }
      }
      if ((DAT_00fb75c0 & 1) == 0) {
        DAT_00fb75c0 = DAT_00fb75c0 | 1;
        local_8._0_1_ = 4;
        local_8._1_3_ = 0;
        FUN_0081e5f0();
        _atexit((_func_4879 *)&LAB_00bcd250);
      }
      local_8._0_1_ = 0;
      iVar4 = FUN_0081ec70(0x73);
      if (iVar4 == 0) {
        uVar8 = 0x196;
        FUN_005854b0(0x196,0,0);
        uVar8 = FUN_00585330(uVar8);
        uVar10 = 0x32;
        FUN_005854b0(0x32,uVar8);
        uVar8 = FUN_00585330(uVar10);
        FUN_00404b10(0xca,uVar8);
        goto joined_r0x0068cafe;
      }
      iVar4 = FUN_0041a4d0();
      if (*(int *)(iVar4 + 0x5ed8) == 0) {
        FUN_0053b900(uVar8,0);
      }
      if ((*(uint *)(*(int *)(param_1 + 0xfc) + 0x28) >> 9 & 1) == 0) {
        FUN_0041a4d0();
        FUN_0053bad0();
      }
      else {
        FUN_0041a4d0();
        FUN_0053ba80();
      }
      if (*(char *)(param_1 + 0x110) == '\0') {
        puVar6 = (undefined4 *)FUN_00891268(0x14);
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = FoxUI::FXUIEvent::vftable;
          puVar6[1] = 0xffffffff;
          puVar6[2] = 0xffffffff;
          puVar6[3] = 0;
          puVar6[4] = 0xf439c;
        }
      }
      else {
        iVar4 = *(int *)(*(int *)(param_1 + 0x10c) + 0x208);
        if (iVar4 == 2) {
          puVar6 = (undefined4 *)FUN_00891268(0x18);
          if (puVar6 != (undefined4 *)0x0) {
            puVar6[3] = 0;
            puVar6[5] = 0;
            puVar6[1] = 0xffffffff;
            puVar6[2] = 0xffffffff;
            puVar6[4] = 0xf4390;
            *puVar6 = FoxUI::FXUIEventI1::vftable;
          }
          FUN_00404aa0();
          FUN_00750020();
          goto joined_r0x0068cafe;
        }
        if (iVar4 != 3) goto joined_r0x0068cafe;
        puVar6 = (undefined4 *)FUN_00891268(0x14);
        if (puVar6 != (undefined4 *)0x0) {
          *puVar6 = FoxUI::FXUIEvent::vftable;
          puVar6[1] = 0xffffffff;
          puVar6[2] = 0xffffffff;
          puVar6[3] = 0;
          puVar6[4] = 0xf4396;
        }
      }
      FUN_004072a0();
      goto joined_r0x0068cafe;
    }
  }
  local_34 = 0x196;
  iVar4 = FUN_005854b0();
  FUN_005740f0(&local_34);
  if (local_38 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  if (*(uint *)(local_38 + 0x24) < 8) {
    iVar4 = local_38 + 0x10;
  }
  else {
    iVar4 = *(int *)(local_38 + 0x10);
  }
  local_34 = 0x39;
  iVar5 = FUN_005854b0();
  FUN_005740f0(&local_34);
  if (local_38 == *(int *)(iVar5 + 4)) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  puVar6 = (undefined4 *)(local_38 + 0x10);
  if (7 < *(uint *)(local_38 + 0x24)) {
    puVar6 = (undefined4 *)*puVar6;
  }
  FUN_00404b10(0xca,puVar6,iVar4,0,0);
joined_r0x0068cafe:
  if (7 < local_1c) {
    FUN_0089120c(local_30);
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

