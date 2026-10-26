
undefined4 FUN_0067ce60(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  char cVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 in_ECX;
  int *piVar6;
  int iVar7;
  int local_58;
  int local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_38;
  int local_34;
  char local_30;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093cc0c;
  local_14 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xffffff98;
  ExceptionList = &local_14;
  FUN_0067d0a0(in_ECX,param_3);
  if ((local_48 == -1) || (local_44 == -1)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 0;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = 0xffffffff;
    }
    local_58 = 0x322;
    FUN_005740f0(&local_58);
    iVar7 = local_54;
    if (local_54 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
  else {
    iVar7 = 0;
    piVar6 = (int *)(param_1 + 300);
    while( true ) {
      if (((iVar7 == param_2) || (piVar6[-1] == -1)) || (*piVar6 == -1)) goto LAB_0067cfc5;
      if ((piVar6[-3] == local_50) && (piVar6[-2] == local_4c)) {
        local_54 = 0x323;
        iVar5 = FUN_00585620(uVar3);
        FUN_005740f0(&local_54);
        iVar7 = local_58;
        if (local_58 == *(int *)(iVar5 + 4)) {
          pcVar1 = (code *)swi(3);
          uVar4 = (*pcVar1)();
          return uVar4;
        }
        goto LAB_0067cf07;
      }
      if ((piVar6[3] != local_38) || (piVar6[4] != local_34)) break;
      if ((char)piVar6[5] != local_30) {
LAB_0067d017:
        uVar4 = 0x31c;
        FUN_00585620(0x31c);
        FUN_00585330(uVar4);
        goto LAB_0067cf39;
      }
      if (local_30 == '\0') {
        cVar2 = FUN_0067dcc0();
        if (cVar2 != '\0') goto LAB_0067d017;
      }
LAB_0067cfc5:
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 0xe;
      if (1 < iVar7) {
        ExceptionList = local_14;
        return 1;
      }
    }
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
      local_c = 0xffffffff;
    }
    local_54 = 0x31c;
    FUN_005740f0(&local_54);
    iVar7 = local_58;
    if (local_58 == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      uVar4 = (*pcVar1)();
      return uVar4;
    }
  }
LAB_0067cf07:
  if (7 < *(uint *)(iVar7 + 0x24)) {
    FUN_0067d350();
    ExceptionList = local_14;
    return 0;
  }
LAB_0067cf39:
  FUN_0067d350();
  ExceptionList = local_14;
  return 0;
}

