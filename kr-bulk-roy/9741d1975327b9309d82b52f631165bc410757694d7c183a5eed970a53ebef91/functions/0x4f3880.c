
void FUN_004f3880(undefined2 *param_1,char param_2,char param_3,int param_4)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short *psVar7;
  short *psVar8;
  short *psVar9;
  undefined4 local_38;
  undefined2 *local_34;
  undefined4 local_30;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00940331;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  local_34 = param_1;
  *param_1 = 0;
  local_8 = 0;
  local_14 = uVar3;
  if (param_2 == '\n') {
    iVar4 = FUN_00404ba0();
    iVar4 = *(int *)(iVar4 + 0x5f70);
    iVar5 = (iVar4 - param_4) / 0xe10;
    if (iVar5 / 0x18 + (iVar5 >> 0x1f) == iVar5 >> 0x1f) {
      if (iVar5 == 0) {
        uVar6 = 0x149;
        FUN_00585620(0x149,uVar3);
        FUN_00585330(uVar6);
        uVar6 = FUN_004068f0();
        local_8 = 3;
        FUN_00402800(uVar6);
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
      }
      else {
        uVar6 = 0x148;
        FUN_00585620(0x148,uVar3);
        FUN_00585330(uVar6);
        uVar6 = FUN_004068f0();
        local_8 = 2;
        FUN_00402800(uVar6);
        if (7 < local_1c) {
          FUN_0089120c(local_30);
        }
      }
    }
    else {
      local_38 = 0x147;
      iVar5 = FUN_00585620();
      FUN_005740f0(&local_38);
      if (iVar4 >> 0x1f == *(int *)(iVar5 + 4)) {
        pcVar2 = (code *)swi(3);
        (*pcVar2)();
        return;
      }
      uVar6 = FUN_004068f0();
      local_8 = 1;
      FUN_00402800(uVar6);
      if (7 < local_1c) {
        FUN_0089120c(local_30);
      }
    }
  }
  else {
    if (param_3 == '\0') {
      uVar6 = 0x144;
      FUN_00585620(0x144,uVar3);
      psVar7 = (short *)FUN_00585330(uVar6);
      psVar9 = psVar7 + 1;
      psVar8 = psVar7;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
    }
    else if (param_3 == '\x01') {
      uVar6 = 0x145;
      FUN_00585620(0x145,uVar3);
      psVar7 = (short *)FUN_00585330(uVar6);
      psVar9 = psVar7 + 1;
      psVar8 = psVar7;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
    }
    else {
      if (param_3 != '\x02') goto LAB_004f3aaf;
      uVar6 = 0x146;
      FUN_00585620(0x146,uVar3);
      psVar7 = (short *)FUN_00585330(uVar6);
      psVar9 = psVar7 + 1;
      psVar8 = psVar7;
      do {
        sVar1 = *psVar8;
        psVar8 = psVar8 + 1;
      } while (sVar1 != 0);
    }
    FUN_00404300(psVar7,(int)psVar8 - (int)psVar9 >> 1);
  }
LAB_004f3aaf:
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

