
void FUN_0058d950(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  undefined4 ****ppppuVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined1 **ppuVar7;
  undefined4 uVar8;
  char *_Str1;
  int iVar9;
  int iVar10;
  char ****_Str2;
  undefined1 local_140 [8];
  undefined **local_138 [4];
  undefined1 *local_128;
  char *local_124;
  undefined1 *local_120;
  int local_11c;
  undefined **local_118 [19];
  uint local_cc;
  undefined4 local_bc;
  uint local_b8;
  undefined4 ***local_9c [4];
  undefined4 local_8c;
  uint local_88;
  undefined2 local_80 [8];
  undefined4 local_70;
  char ***local_6c [2];
  undefined **local_64;
  undefined1 local_60 [4];
  undefined4 local_5c;
  uint local_58;
  undefined4 ***local_50 [4];
  undefined4 local_40;
  uint local_3c;
  undefined4 ***local_34 [2];
  undefined **local_2c;
  undefined1 local_28 [4];
  undefined4 *local_24;
  uint local_20;
  uint local_18;
  void *local_10;
  undefined1 *puStack_c;
  uint local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009270ce;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_11c = param_1;
  local_18 = uVar2;
  FUN_0072ed80(local_118);
  local_8 = 0;
  FUN_0047f540(L"./UIHistory.dll",uVar2);
  local_8._0_1_ = 1;
  cVar1 = FUN_0072f110(1);
  local_8 = (uint)local_8._1_3_ << 8;
  if (0xf < local_58) {
    FUN_0089120c(local_6c[0]);
  }
  if (cVar1 == '\0') {
    local_8 = 0xffffffff;
    local_118[0] = TiXmlDocument::vftable;
    if (0xf < local_b8) {
      FUN_0089120c(local_cc);
    }
    local_b8 = 0xf;
    local_bc = 0;
    local_cc = local_cc & 0xffffff00;
    FUN_0072e040();
  }
  else {
    FUN_004297b0();
    ppppuVar4 = (undefined4 ****)local_50[0];
    if (local_3c < 0x10) {
      ppppuVar4 = local_50;
    }
    iVar3 = FUN_0072e2e0(ppppuVar4);
    if (0xf < local_3c) {
      FUN_0089120c(local_50[0]);
    }
    local_3c = 0xf;
    local_40 = 0;
    local_50[0] = (undefined4 ***)((uint)local_50[0] & 0xffffff00);
    if (iVar3 != 0) {
      FUN_004297b0();
      ppppuVar4 = (undefined4 ****)local_34[0];
      if (local_20 < 0x10) {
        ppppuVar4 = local_34;
      }
      iVar3 = FUN_0072e2e0(ppppuVar4);
      if (0xf < local_20) {
        FUN_0089120c(local_34[0]);
      }
      local_20 = 0xf;
      local_24 = (undefined4 *)0x0;
      local_34[0] = (undefined4 ***)((uint)local_34[0] & 0xffffff00);
      if (iVar3 != 0) {
        FUN_0058d1b0(local_11c + 4);
      }
      FUN_004297b0();
      ppppuVar4 = (undefined4 ****)local_9c[0];
      if (local_88 < 0x10) {
        ppppuVar4 = local_9c;
      }
      iVar3 = FUN_0072e2e0(ppppuVar4);
      if (0xf < local_88) {
        FUN_0089120c(local_9c[0]);
      }
      local_88 = 0xf;
      local_8c = 0;
      local_9c[0] = (undefined4 ***)((uint)local_9c[0] & 0xffffff00);
      while (iVar3 != 0) {
        FUN_00764d80(local_50,&DAT_00bed1fc);
        iVar9 = local_11c;
        iVar10 = local_11c + 0x44;
        local_8 = CONCAT31(local_8._1_3_,2);
        local_120 = (undefined1 *)FUN_0058f630();
        if (local_120 == *(undefined1 **)(iVar9 + 0x48)) {
LAB_0058dbad:
          local_128 = *(undefined1 **)(iVar9 + 0x48);
          ppuVar7 = &local_128;
        }
        else {
          puVar5 = (undefined4 *)(local_120 + 0xc);
          if (7 < *(uint *)(local_120 + 0x20)) {
            puVar5 = (undefined4 *)*puVar5;
          }
          iVar6 = FUN_0044df20(0,puVar5,*(undefined4 *)(local_120 + 0x1c));
          if (iVar6 < 0) goto LAB_0058dbad;
          ppuVar7 = &local_120;
        }
        if (*ppuVar7 == *(undefined1 **)(local_11c + 0x48)) {
          local_2c = FUI::FXUIAttributeHistory::vftable;
          local_20 = 0;
          puVar5 = (undefined4 *)FUN_00891268(0x48);
          if (puVar5 == (undefined4 *)0x0) {
            local_124 = (char *)0x0;
            std::exception::exception((exception *)local_138,&local_124);
            local_138[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
            __CxxThrowException_8(local_138,&DAT_00c857a8);
          }
          *puVar5 = puVar5;
          puVar5[1] = puVar5;
          puVar5[2] = puVar5;
          *(undefined1 *)(puVar5 + 0x11) = 1;
          *(undefined1 *)((int)puVar5 + 0x45) = 1;
          local_8._0_1_ = 3;
          local_24 = puVar5;
          FUN_0058d1b0(&local_2c);
          local_6c[0] = (char ***)0x7;
          local_70 = 0;
          local_80[0] = 0;
          FUN_004026e0(local_50,0,0xffffffff);
          local_8._0_1_ = 4;
          local_64 = FUI::FXUIAttributeHistory::vftable;
          FUN_0051abd0(local_60,local_28);
          local_8._0_1_ = 5;
          uVar8 = FUN_0058ff30(local_80);
          FUN_0058fb80(iVar10,local_140,uVar8);
          local_8._0_1_ = 3;
          FUN_00590100(local_80);
          local_120 = local_28;
          local_2c = FUI::FXUIAttributeHistory::vftable;
          local_8._0_1_ = 6;
          FUN_0051af60(*local_24,local_24);
          local_8 = CONCAT31(local_8._1_3_,2);
          FUN_0089120c(local_24);
        }
        else {
          FUN_0058d1b0(*ppuVar7 + 0x28);
        }
        FUN_004297b0();
        _Str2 = (char ****)local_6c[0];
        if (local_58 < 0x10) {
          _Str2 = local_6c;
        }
        for (iVar3 = *(int *)(iVar3 + 0x40); iVar3 != 0; iVar3 = *(int *)(iVar3 + 0x40)) {
          _Str1 = (char *)(iVar3 + 0x20);
          if (0xf < *(uint *)(iVar3 + 0x34)) {
            _Str1 = *(char **)_Str1;
          }
          iVar9 = __stricmp(_Str1,(char *)_Str2);
          if (iVar9 == 0) goto LAB_0058dcff;
        }
        iVar3 = 0;
LAB_0058dcff:
        if (0xf < local_58) {
          FUN_0089120c(local_6c[0]);
        }
        local_8 = local_8 & 0xffffff00;
        local_58 = 0xf;
        local_5c = 0;
        local_6c[0] = (char ***)((uint)local_6c[0] & 0xffffff00);
        if (7 < local_3c) {
          FUN_0089120c(local_50[0]);
        }
        local_3c = 7;
        local_40 = 0;
        local_50[0] = (undefined4 ***)((uint)local_50[0] & 0xffff0000);
      }
    }
    local_8 = 0xffffffff;
    local_118[0] = TiXmlDocument::vftable;
    if (0xf < local_b8) {
      FUN_0089120c(local_cc);
    }
    local_b8 = 0xf;
    local_bc = 0;
    local_cc = local_cc & 0xffffff00;
    FUN_0072e040();
  }
  ExceptionList = local_10;
  __security_check_cookie(local_18 ^ (uint)&stack0xfffffffc);
  return;
}

