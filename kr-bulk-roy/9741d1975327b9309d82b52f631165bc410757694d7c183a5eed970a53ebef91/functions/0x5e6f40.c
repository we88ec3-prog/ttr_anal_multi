
void FUN_005e6f40(int param_1,int param_2)

{
  short sVar1;
  code *pcVar2;
  uint uVar3;
  short *psVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  uint uVar8;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009165d6;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8._0_1_ = 1;
    local_8._1_3_ = 0;
    FUN_00584c40(&DAT_00fe5ac4);
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = (uint)local_8._1_3_ << 8;
  }
  local_14 = 0x1a8;
  FUN_005740f0(&local_14);
  if (local_18 == DAT_00fe5ac8) {
    pcVar2 = (code *)swi(3);
    (*pcVar2)();
    return;
  }
  psVar7 = (short *)(local_18 + 0x10);
  if (7 < *(uint *)(local_18 + 0x24)) {
    psVar7 = *(short **)psVar7;
  }
  psVar4 = psVar7;
  do {
    sVar1 = *psVar4;
    psVar4 = psVar4 + 1;
  } while (sVar1 != 0);
  FUN_00404300(psVar7,(int)psVar4 - (int)(psVar7 + 1) >> 1);
  local_14 = 0;
  if (param_2 - param_1 >> 2 != 0) {
    do {
      switch(*(undefined4 *)(param_1 + local_14 * 4)) {
      case 1:
        local_18 = 0x1a9;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_1c == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_1c + 0x10);
        if (7 < *(uint *)(local_1c + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 2:
        local_18 = 0x1aa;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_20 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_20 + 0x10);
        if (7 < *(uint *)(local_20 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 3:
        local_18 = 0x1ab;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_24 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_24 + 0x10);
        if (7 < *(uint *)(local_24 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 4:
        local_18 = 0x1ac;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_28 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_28 + 0x10);
        if (7 < *(uint *)(local_28 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 5:
        local_18 = 0x1ad;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_2c == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_2c + 0x10);
        if (7 < *(uint *)(local_2c + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 6:
        local_18 = 0x1ae;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_30 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_30 + 0x10);
        if (7 < *(uint *)(local_30 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 7:
        local_18 = 0x1af;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_34 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_34 + 0x10);
        if (7 < *(uint *)(local_34 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 8:
        local_18 = 0x1b0;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_38 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_38 + 0x10);
        if (7 < *(uint *)(local_38 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 9:
        local_18 = 0x1b1;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_3c == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_3c + 0x10);
        if (7 < *(uint *)(local_3c + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 10:
        local_18 = 0x1b6;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_40 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_40 + 0x10);
        if (7 < *(uint *)(local_40 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 0xb:
        local_18 = 0x1b7;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_44 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_44 + 0x10);
        if (7 < *(uint *)(local_44 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 0xc:
        local_18 = 0x1b2;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_48 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_48 + 0x10);
        if (7 < *(uint *)(local_48 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 0xd:
        local_18 = 0x1b3;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_4c == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_4c + 0x10);
        if (7 < *(uint *)(local_4c + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 0xe:
        local_18 = 0x1b4;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_50 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_50 + 0x10);
        if (7 < *(uint *)(local_50 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      case 0xf:
        local_18 = 0x1b5;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_18);
        if (local_54 == *(int *)(iVar5 + 4)) {
          pcVar2 = (code *)swi(3);
          (*pcVar2)();
          return;
        }
        psVar7 = (short *)(local_54 + 0x10);
        if (7 < *(uint *)(local_54 + 0x24)) {
          psVar7 = *(short **)psVar7;
        }
        psVar4 = psVar7 + 1;
        psVar6 = psVar7;
        do {
          sVar1 = *psVar6;
          psVar6 = psVar6 + 1;
        } while (sVar1 != 0);
        break;
      default:
        goto switchD_005e7020_default;
      }
      FUN_00404300(psVar7,(int)psVar6 - (int)psVar4 >> 1);
switchD_005e7020_default:
      uVar8 = local_14 + 1;
      if (uVar8 < (uint)(param_2 - param_1 >> 2)) {
        FUN_00404300(&DAT_00c02b94,2);
      }
      local_14 = uVar8;
    } while (uVar8 < (uint)(param_2 - param_1 >> 2));
  }
  FUN_00404300(L"<br>",4);
  if (param_1 != 0) {
    FUN_0089120c(param_1);
  }
  ExceptionList = local_10;
  return;
}

