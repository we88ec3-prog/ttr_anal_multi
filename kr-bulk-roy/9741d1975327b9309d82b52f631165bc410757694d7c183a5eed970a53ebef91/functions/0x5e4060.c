
void FUN_005e4060(int param_1,uint param_2)

{
  short sVar1;
  ushort *puVar2;
  code *pcVar3;
  uint uVar4;
  short *psVar5;
  int iVar6;
  int *piVar7;
  short *psVar8;
  undefined4 uVar9;
  int local_5c;
  uint local_58;
  int local_54;
  char local_4d;
  uint local_30 [4];
  int local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f8ac;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_58 = param_2;
  local_14 = uVar4;
  if (*(int *)(param_1 + 0x88) == 0) {
    FUN_00404300(L"<#ff0000>",9);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_5c = 0x19a;
    FUN_005740f0(&local_5c);
    if (local_54 == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar8 = (short *)(local_54 + 0x10);
    if (7 < *(uint *)(local_54 + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    psVar5 = psVar8;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
  }
  if (*(int *)(param_1 + 0x8c) == 0) {
    FUN_00404300(L"<#ff0000>",9);
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_8 = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_8 = 0xffffffff;
    }
    local_54 = 0x19b;
    FUN_005740f0(&local_54);
    if (local_5c == DAT_00fe5ac8) {
      pcVar3 = (code *)swi(3);
      (*pcVar3)();
      return;
    }
    psVar8 = (short *)(local_5c + 0x10);
    if (7 < *(uint *)(local_5c + 0x24)) {
      psVar8 = *(short **)psVar8;
    }
    psVar5 = psVar8;
    do {
      sVar1 = *psVar5;
      psVar5 = psVar5 + 1;
    } while (sVar1 != 0);
    FUN_00404300(psVar8,(int)psVar5 - (int)(psVar8 + 1) >> 1);
  }
  if (local_58 != 0) {
    local_1c = 7;
    local_20 = 0;
    local_30[0] = local_30[0] & 0xffff0000;
    local_8 = 2;
    puVar2 = *(ushort **)(local_58 + 0x54);
    if (puVar2 != (ushort *)0x0) {
      local_58 = (uint)*puVar2;
      iVar6 = FUN_004034e0(uVar4);
      FUN_008438c0(&local_58);
      if (local_54 == *(int *)(iVar6 + 4)) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(local_54 + 0x10);
      }
      if (*puVar2 != 0) {
        if (iVar6 != 0) {
          FUN_00404420(local_30);
          uVar9 = 0x199;
          FUN_00585620(0x199);
          FUN_00585330(uVar9);
          FUN_00404420(local_30);
          local_4d = (char)puVar2[1];
          piVar7 = (int *)(iVar6 + 0x98);
          if (local_4d == '\0') {
            FUN_00404420(local_30);
          }
          else {
            if (7 < *(uint *)(iVar6 + 0xac)) {
              piVar7 = (int *)*piVar7;
            }
            uVar9 = 0x18;
            FUN_00585620(0x18,piVar7);
            FUN_00585330(uVar9);
            uVar9 = FUN_00498f10();
            local_8._0_1_ = 3;
            FUN_004041f0(uVar9,0,0xffffffff);
            local_8 = CONCAT31(local_8._1_3_,2);
            FUN_004fa440();
          }
        }
        FUN_00404420(local_30);
      }
      if (local_20 != 0) {
        FUN_004041f0(local_30,0,0xffffffff);
      }
      if (7 < local_1c) {
        FUN_0089120c(local_30[0]);
      }
    }
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

