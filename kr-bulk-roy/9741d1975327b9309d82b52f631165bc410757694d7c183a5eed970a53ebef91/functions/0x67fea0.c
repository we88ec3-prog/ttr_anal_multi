
void FUN_0067fea0(int param_1,undefined4 param_2)

{
  code *pcVar1;
  char cVar2;
  int iVar3;
  int *piVar4;
  int in_EDX;
  undefined4 uVar5;
  undefined1 auStack_84 [4];
  int local_80;
  int local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  undefined4 local_60;
  uint local_4c;
  int local_44;
  int local_40;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00942d04;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_84;
  ExceptionList = &local_14;
  if ((*(int *)(in_EDX + 0x120) == -1) || (*(int *)(in_EDX + 0x124) == -1)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_7c = 0x312;
    FUN_005740f0(&local_7c);
    if (local_80 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_80 + 0x24) < 8) {
      FUN_006803d0(in_EDX);
    }
    else {
      FUN_006803d0(in_EDX);
    }
    goto LAB_006801c2;
  }
  if ((param_1 != 0) && ((*(int *)(in_EDX + 0x178) == -1 || (*(int *)(in_EDX + 0x17c) == -1)))) {
    uVar5 = 0x313;
    FUN_00585620(0x313,DAT_00d61f20 ^ (uint)&stack0xffffff70);
    FUN_00585330(uVar5);
    FUN_006803d0(in_EDX);
    goto LAB_006801c2;
  }
  FUN_0067f930(&local_78,param_2);
  local_c = 1;
  if ((local_70 == -1) || (local_6c == -1)) {
    local_80 = 0x322;
    iVar3 = FUN_00585620();
    FUN_005740f0(&local_80);
    if (local_7c == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    FUN_006803d0(in_EDX);
    if (7 < local_4c) {
      FUN_0089120c(local_60);
    }
    goto LAB_006801c2;
  }
  if (local_44 == 0xb) {
    switch(local_28) {
    case 0:
      switch(*(undefined4 *)(in_EDX + 0x14c)) {
      case 0x13:
      case 0x20:
      case 0x28:
      case 0x2a:
        break;
      default:
switchD_006800cd_caseD_3:
        uVar5 = 0x314;
        goto LAB_0068008f;
      }
    case 1:
      switch(*(undefined4 *)(in_EDX + 0x14c)) {
      case 1:
      case 0x11:
      case 0x24:
      case 0x29:
        break;
      default:
        goto switchD_006800cd_caseD_3;
      }
    case 2:
      switch(*(undefined4 *)(in_EDX + 0x14c)) {
      case 2:
      case 0x12:
      case 0x25:
      case 0x2b:
        break;
      default:
        goto switchD_006800cd_caseD_3;
      }
    case 4:
      if (*(int *)(in_EDX + 0x14c) != 1) goto switchD_006800cd_caseD_3;
      break;
    case 5:
      if ((*(int *)(in_EDX + 0x14c) != 2) && (*(int *)(in_EDX + 0x14c) != 0x2b))
      goto switchD_006800cd_caseD_3;
    }
    if (param_1 == 0) {
      if (*(int *)(in_EDX + 0x22c) != -1) {
        iVar3 = 0;
        piVar4 = (int *)(in_EDX + 0x1b0);
        do {
          if ((((local_30 != piVar4[2]) || (local_2c != piVar4[3])) || (local_38 != *piVar4)) ||
             ((local_34 != piVar4[1] || (local_40 != piVar4[-2])))) {
            if ((DAT_00fe5ae4 & 1) == 0) {
              DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
              local_c._0_1_ = 2;
              local_c._1_3_ = 0;
              FUN_00584c40(&DAT_00fe5ac4);
              _atexit((_func_4879 *)&LAB_00bcf390);
              local_c = CONCAT31(local_c._1_3_,1);
            }
            local_80 = 0x315;
            FUN_005740f0(&local_80);
            if (local_7c == DAT_00fe5ac8) {
              pcVar1 = (code *)swi(3);
              (*pcVar1)();
              return;
            }
            FUN_006803d0(in_EDX);
            if (7 < local_4c) {
              FUN_0089120c(local_60);
            }
            goto LAB_006801c2;
          }
          iVar3 = iVar3 + 1;
          piVar4 = piVar4 + 0x16;
        } while (iVar3 < 3);
      }
    }
    else {
      cVar2 = FUN_0067dcc0();
      if (cVar2 != '\0') {
LAB_0068012a:
        uVar5 = 0x315;
        goto LAB_0068008f;
      }
      if (local_40 != *(int *)(in_EDX + 0x1a8)) {
        uVar5 = 0x315;
        goto LAB_0068008f;
      }
LAB_00680178:
      iVar3 = 0;
      piVar4 = (int *)(in_EDX + 0x17c);
      do {
        if (((piVar4[-1] != -1) && (*piVar4 != -1)) &&
           ((iVar3 != param_1 && ((piVar4[-3] == local_78 && (piVar4[-2] == local_74)))))) {
          uVar5 = 0x322;
          goto LAB_0068008f;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 0x16;
      } while (iVar3 < 3);
    }
    if (7 < local_4c) {
      FUN_0089120c(local_60);
    }
  }
  else {
    if (param_1 == 0) {
      uVar5 = 0x316;
    }
    else {
      if ((8 < local_44) && (local_44 < 0xb)) {
        if (local_40 == *(int *)(in_EDX + 0x1a8)) goto LAB_00680178;
        goto LAB_0068012a;
      }
      uVar5 = 0x317;
    }
LAB_0068008f:
    FUN_00585620(uVar5);
    FUN_00585330(uVar5);
    FUN_006803d0(in_EDX);
    FUN_0067dea0();
  }
LAB_006801c2:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_84);
  return;
}

