
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00651e20(void)

{
  code *pcVar1;
  int iVar2;
  undefined4 in_ECX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iStack_20;
  int aiStack_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093d576;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar5 = 1;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  if ((DAT_00f9392c == 4) || (DAT_00f9392c == 9)) {
    if ((DAT_00fab22c & 1) == 0) {
      DAT_00fab22c = DAT_00fab22c | 1;
      local_c = 1;
      FUN_004dec90();
      _atexit((_func_4879 *)&LAB_00bcce30);
    }
    local_c = 0xffffffff;
    iVar2 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    if ((iVar2 != 0) &&
       ((*(int *)(iVar2 + 0x158) == 0 || (*(int *)(*(int *)(iVar2 + 0x158) + 0x34) != 0)))) {
      iVar2 = FUN_00404ba0();
      iVar3 = 0;
      switch(in_ECX) {
      case 0:
        iVar3 = 0xb7;
        break;
      case 1:
        iVar3 = 0x9f7;
        break;
      case 2:
        iVar3 = 0xb8;
        break;
      case 3:
        iVar3 = 0xf8;
      }
      piVar4 = (int *)(*(int *)(iVar2 + 0x6920) + 0x1724);
      do {
        if (iVar5 - 1U < 100) {
          if ((((*piVar4 != 0) && (piVar4[-1] != 0)) && (piVar4 != (int *)0xc)) &&
             (*piVar4 == iVar3)) {
            if ((_DAT_00fb1314 & 1) == 0) {
              _DAT_00fb1314 = _DAT_00fb1314 | 1;
              _atexit((_func_4879 *)&DAT_00bccf10);
            }
            FUN_004a39f0(1,iVar5,*piVar4,0);
          }
        }
        else {
          FUN_006edb60(&DAT_00c0ddc0);
        }
        iVar5 = iVar5 + 1;
        piVar4 = piVar4 + 8;
      } while (iVar5 < 0x65);
      ExceptionList = local_14;
      return;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 2;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    iStack_20 = 0x196;
    FUN_005740f0(&iStack_20);
    if (aiStack_1c[0] == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 3;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    aiStack_1c[0] = 0x1ab;
    FUN_005740f0(aiStack_1c);
    if (iStack_20 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(iStack_20 + 0x24) < 8) {
      iVar5 = iStack_20 + 0x10;
    }
    else {
      iVar5 = *(int *)(iStack_20 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 4;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar5,0,0);
  }
  ExceptionList = local_14;
  return;
}

