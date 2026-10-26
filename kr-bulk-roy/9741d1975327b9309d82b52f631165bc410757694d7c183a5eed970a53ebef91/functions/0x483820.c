
undefined4 FUN_00483820(void)

{
  code *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  int in_EDX;
  undefined4 uVar7;
  undefined1 local_28 [4];
  undefined1 local_24;
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
  if ((in_EDX != 1) || (iVar3 = DAT_00f94300 + 0x16f8, iVar3 == 0)) {
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
      pcVar1 = (code *)swi(3);
      uVar2 = (*pcVar1)();
      return uVar2;
    }
    goto LAB_00483a77;
  }
  if (in_ECX - 1U < 100) {
    iVar5 = in_ECX * 0x20 + iVar3;
    if (((*(int *)(in_ECX * 0x20 + 0xc + iVar3) != 0) && (*(int *)(iVar5 + 8) != 0)) && (iVar5 != 0)
       ) {
      if ((DAT_00f8d9a4 & 1) == 0) {
        DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
        local_c = 2;
        FUN_0051c120();
        _atexit((_func_4879 *)&LAB_00bccc90);
      }
      local_c = 0xffffffff;
      local_1c[0] = *(int *)(iVar5 + 0xc);
      FUN_008438c0(local_1c);
      if (((local_20 == DAT_00f8d91c) || (*(int *)(local_20 + 0x10) == 0)) ||
         ((iVar3 = *(int *)(*(int *)(local_20 + 0x10) + 0x54), iVar3 == 0 ||
          (iVar4 = FUN_00520ee0(), iVar4 == 0)))) {
LAB_004839dc:
        uVar2 = 0x322;
      }
      else {
        uVar2 = *(undefined4 *)(iVar5 + 0x14);
        uVar7 = *(undefined4 *)(iVar5 + 0x10);
        FUN_00409560(uVar7,uVar2);
        iVar5 = FUN_004dc700(uVar7,uVar2);
        if ((iVar5 != 0) &&
           ((**(short **)(iVar5 + 0x54) != 0 || ((char)(*(short **)(iVar5 + 0x54))[1] != '\0')))) {
          iVar5 = FUN_004034e0();
          local_24 = *(undefined1 *)(iVar3 + 0x5c);
          local_28[0] = *(undefined1 *)(iVar3 + 8);
          FUN_00827050(iVar5 + 0x20,local_28);
          piVar6 = (int *)FUN_008271c0();
          if (*piVar6 != 0) {
            ExceptionList = local_14;
            return 1;
          }
          goto LAB_004839dc;
        }
        uVar2 = 0x31a;
      }
      FUN_00585620(uVar2);
      FUN_00585330(uVar2);
      goto LAB_00483a77;
    }
  }
  else {
    FUN_006edb60(&DAT_00c0ddc0);
  }
  local_1c[0] = 0x321;
  iVar3 = FUN_00585620();
  FUN_005740f0(local_1c);
  if (local_20 == *(int *)(iVar3 + 4)) {
    pcVar1 = (code *)swi(3);
    uVar2 = (*pcVar1)();
    return uVar2;
  }
LAB_00483a77:
  FUN_00483af0();
  ExceptionList = local_14;
  return 0;
}

