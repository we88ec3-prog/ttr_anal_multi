
undefined4 FUN_006807d0(undefined4 param_1,int param_2)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int in_ECX;
  int local_24;
  undefined4 local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_0093cc4c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((in_ECX == -1) && (param_2 == -1)) {
LAB_0068099f:
    local_1c[0] = 0x331;
    iVar4 = FUN_00585620();
    FUN_005740f0(local_1c);
    if (local_24 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
  }
  else {
    if ((DAT_00f94390 & 1) == 0) {
      DAT_00f94390 = DAT_00f94390 | 1;
      local_c = 0;
      FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
      _atexit((_func_4879 *)&LAB_00bccc80);
    }
    local_c = 0xffffffff;
    if ((in_ECX != 1) || (DAT_00f94300 + 0x16f8 == 0)) {
      if ((DAT_00fe5ae4 & 1) == 0) {
        DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
        local_c = 1;
        FUN_00584c40(&DAT_00fe5ac4);
        _atexit((_func_4879 *)&LAB_00bcf390);
      }
      local_c = 0xffffffff;
      local_24 = 0x321;
      FUN_005740f0(&local_24);
      if (local_1c[0] == DAT_00fe5ac8) {
        pcVar1 = (code *)swi(3);
        uVar2 = (*pcVar1)();
        return uVar2;
      }
      goto LAB_006809da;
    }
    if (param_2 - 1U < 100) {
      puVar3 = (undefined4 *)(DAT_00f94300 + 0x16f8 + param_2 * 0x20);
      if (((puVar3[3] != 0) && (puVar3[2] != 0)) && (puVar3 != (undefined4 *)0x0)) {
        switch(*puVar3) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x1b:
        case 0x20:
        case 0x24:
        case 0x25:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
          local_24 = puVar3[4];
          local_20 = puVar3[5];
          iVar4 = FUN_00409560();
          FUN_004dd400(iVar4,local_1c,&local_24);
          if ((local_1c[0] != *(int *)(iVar4 + 4)) && (*(int *)(local_1c[0] + 0x18) != 0)) {
            iVar4 = FUN_004dc9a0();
            if (iVar4 != 0) {
              ExceptionList = local_14;
              return 1;
            }
            goto LAB_0068099f;
          }
        }
        uVar2 = 0x330;
        FUN_00585620(0x330);
        FUN_00585330(uVar2);
        goto LAB_006809da;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    local_1c[0] = 0x321;
    iVar4 = FUN_00585620();
    FUN_005740f0(local_1c);
    if (local_24 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
  }
LAB_006809da:
  FUN_00681950();
  ExceptionList = local_14;
  return 0;
}

