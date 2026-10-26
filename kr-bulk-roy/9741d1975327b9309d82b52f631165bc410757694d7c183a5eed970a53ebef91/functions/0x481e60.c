
undefined4 FUN_00481e60(undefined4 param_1,char param_2)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
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
  if ((in_EDX == 1) && (iVar2 = DAT_00f94300 + 0x16f8, iVar2 != 0)) {
    if (in_ECX - 1U < 100) {
      iVar4 = in_ECX * 0x20 + iVar2;
      if (((*(int *)(in_ECX * 0x20 + 0xc + iVar2) != 0) && (*(int *)(iVar4 + 8) != 0)) &&
         (iVar4 != 0)) {
        if ((DAT_00f8d9a4 & 1) == 0) {
          DAT_00f8d9a4 = DAT_00f8d9a4 | 1;
          local_c = 2;
          FUN_0051c120();
          _atexit((_func_4879 *)&LAB_00bccc90);
        }
        local_c = 0xffffffff;
        local_1c[0] = *(int *)(iVar4 + 0xc);
        FUN_008438c0(local_1c);
        if (((local_20 != DAT_00f8d91c) && (*(int *)(local_20 + 0x10) != 0)) &&
           (iVar2 = *(int *)(*(int *)(local_20 + 0x10) + 0x54), iVar2 != 0)) {
          iVar5 = FUN_00520ee0();
          if (iVar5 == 0) {
            uVar3 = 0x322;
          }
          else {
            if (param_2 == '\0') {
              if (*(int *)(iVar2 + 0x88) == 0) {
                uVar3 = 0x171;
                FUN_005854b0(0x171);
                goto LAB_00482080;
              }
            }
            else if ((param_2 == '\x01') && (*(int *)(iVar2 + 0x8c) == 0)) {
              uVar3 = 0x170;
              FUN_005854b0(0x170);
              goto LAB_00482080;
            }
            uVar3 = *(undefined4 *)(iVar4 + 0x14);
            uVar7 = *(undefined4 *)(iVar4 + 0x10);
            FUN_00409560(uVar7,uVar3);
            iVar4 = FUN_004dc700(uVar7,uVar3);
            if ((iVar4 == 0) ||
               ((**(short **)(iVar4 + 0x54) == 0 && ((char)(*(short **)(iVar4 + 0x54))[1] == '\0')))
               ) {
              iVar4 = FUN_004034e0();
              local_24 = *(undefined1 *)(iVar2 + 0x5c);
              local_28[0] = *(undefined1 *)(iVar2 + 8);
              FUN_00827050(iVar4 + 0x10,local_28);
              piVar6 = (int *)FUN_008271c0();
              if (*piVar6 != 0) {
                ExceptionList = local_14;
                return 1;
              }
              goto LAB_0048204e;
            }
            uVar3 = 0x31b;
          }
          FUN_00585620(uVar3);
LAB_00482080:
          FUN_00585330(uVar3);
          FUN_00482420();
          ExceptionList = local_14;
          return 0;
        }
LAB_0048204e:
        uVar3 = 0x322;
        FUN_00585620(0x322);
        FUN_00585330(uVar3);
        goto LAB_00481f72;
      }
    }
    else {
      FUN_006edb60(&DAT_00c0ddc0);
    }
    local_1c[0] = 0x321;
    iVar4 = FUN_00585620();
    FUN_005740f0(local_1c);
    iVar2 = local_20;
    if (local_20 == *(int *)(iVar4 + 4)) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
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
    local_20 = 0x321;
    FUN_005740f0(&local_20);
    iVar2 = local_1c[0];
    if (local_1c[0] == DAT_00fe5ac8) {
      pcVar1 = (code *)swi(3);
      uVar3 = (*pcVar1)();
      return uVar3;
    }
  }
  if (7 < *(uint *)(iVar2 + 0x24)) {
    FUN_00482470();
    ExceptionList = local_14;
    return 0;
  }
LAB_00481f72:
  FUN_00482470();
  ExceptionList = local_14;
  return 0;
}

