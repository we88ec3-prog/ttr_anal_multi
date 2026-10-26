
undefined4 FUN_0067a970(undefined4 param_1)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int in_EDX;
  uint uVar5;
  undefined4 *puVar6;
  int local_24;
  undefined4 local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093cc4c;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_EDX == 1) && (DAT_00f94300 + 0x16f8 != 0)) {
    if (in_ECX - 1U < 100) {
      puVar6 = (undefined4 *)(in_ECX * 0x20 + DAT_00f94300 + 0x16f8);
      if (((puVar6[3] != 0) && (puVar6[2] != 0)) && (puVar6 != (undefined4 *)0x0)) {
        switch(*puVar6) {
        case 2:
        case 0x28:
        case 0x29:
        case 0x2a:
        case 0x2b:
          local_24 = puVar6[4];
          local_20 = puVar6[5];
          uVar5 = 0;
          iVar3 = FUN_00409560();
          FUN_004dd400(iVar3,local_1c,&local_24);
          if ((local_1c[0] != *(int *)(iVar3 + 4)) &&
             (iVar3 = *(int *)(local_1c[0] + 0x18), iVar3 != 0)) {
            uVar5 = *(int *)(iVar3 + 0x48) - *(int *)(iVar3 + 0x44) >> 3;
          }
          local_1c[0] = puVar6[1];
          iVar3 = FUN_004034e0();
          FUN_008438c0(local_1c);
          if (((local_24 != *(int *)(iVar3 + 4)) && (*(int *)(local_24 + 0x10) != 0)) &&
             (uVar4 = FUN_00520e70(), uVar5 < uVar4)) {
            ExceptionList = local_14;
            return 1;
          }
          uVar2 = 0x299;
          FUN_00585620(0x299);
          FUN_00585330(uVar2);
          break;
        default:
          uVar2 = 0x299;
          FUN_00585620(0x299);
          FUN_00585330(uVar2);
        }
        goto LAB_0067abb8;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    local_1c[0] = 0x321;
    iVar3 = FUN_00585620();
    FUN_005740f0(local_1c);
    if (local_24 == *(int *)(iVar3 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
  }
  else {
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
  }
LAB_0067abb8:
  FUN_0067b560(param_1);
  ExceptionList = local_14;
  return 0;
}

