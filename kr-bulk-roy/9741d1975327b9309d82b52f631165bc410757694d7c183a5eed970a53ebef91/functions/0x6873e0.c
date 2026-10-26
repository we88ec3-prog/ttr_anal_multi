
undefined4 FUN_006873e0(undefined4 param_1,int param_2)

{
  int iVar1;
  code *pcVar2;
  undefined4 uVar3;
  int in_ECX;
  int iVar4;
  undefined8 uVar5;
  undefined4 uVar6;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093ccea;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((param_2 != 1) || (DAT_00f94300 + 0x16f8 == 0)) {
    if ((DAT_00fe5ae4 & 1) == 0) {
      DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5ac4);
      _atexit((_func_4879 *)&LAB_00bcf390);
    }
    local_c = 0xffffffff;
    local_20 = 0x321;
    FUN_005740f0(&local_20);
    if (local_1c[0] == DAT_00fe5ac8) {
      pcVar2 = (code *)swi(3);
      uVar3 = (*pcVar2)();
      return uVar3;
    }
    goto LAB_00687632;
  }
  if (in_ECX - 1U < 100) {
    iVar4 = in_ECX * 0x20 + DAT_00f94300 + 0x16f8;
    if (((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 8) != 0)) && (iVar4 != 0)) {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 2;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
      }
      local_c = 0xffffffff;
      local_1c[0] = *(int *)(iVar4 + 0xc);
      FUN_008438c0(local_1c);
      if (((local_20 == DAT_00f8d91c) || (*(int *)(local_20 + 0x10) == 0)) ||
         (iVar1 = *(int *)(*(int *)(local_20 + 0x10) + 0x54), iVar1 == 0)) {
LAB_00687593:
        uVar3 = 0x322;
      }
      else {
        uVar5 = FUN_00520e10();
        if (((int)uVar5 != 0) && (*(int *)((int)((ulonglong)uVar5 >> 0x20) + 0x40) == 0)) {
          uVar3 = *(undefined4 *)(iVar4 + 0x14);
          uVar6 = *(undefined4 *)(iVar4 + 0x10);
          FUN_00409560(uVar6,uVar3);
          FUN_004dc700(uVar6,uVar3);
          if (*(int *)(iVar1 + 8) - 1U < 0x2b) {
            local_20 = FUN_00520f40();
          }
          else {
            local_20 = 0;
          }
          FUN_0067a460();
          iVar4 = FUN_00514ea0();
          if (iVar4 != 0) {
            ExceptionList = local_14;
            return 1;
          }
          goto LAB_00687593;
        }
        uVar3 = 0x326;
      }
      FUN_00585620(uVar3);
      FUN_00585330(uVar3);
      goto LAB_00687632;
    }
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
  }
  local_1c[0] = 0x321;
  iVar4 = FUN_00585620();
  FUN_005740f0(local_1c);
  if (local_20 == *(int *)(iVar4 + 4)) {
    pcVar2 = (code *)swi(3);
    uVar3 = (*pcVar2)();
    return uVar3;
  }
LAB_00687632:
  FUN_00687e10();
  ExceptionList = local_14;
  return 0;
}

