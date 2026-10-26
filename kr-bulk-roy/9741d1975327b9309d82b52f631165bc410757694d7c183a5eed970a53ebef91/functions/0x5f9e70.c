
void FUN_005f9e70(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  code *pcVar1;
  int iVar2;
  int in_ECX;
  int *piVar3;
  int iVar4;
  int local_20;
  int local_1c [2];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009416c8;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  iVar4 = 0;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  if ((in_ECX == 1) && (DAT_00f94300 != -0x16f8)) {
    iVar4 = 1;
    if (0 < *(int *)(DAT_00f94300 + 0x2398)) {
      piVar3 = (int *)(DAT_00f94300 + 0x1720);
      do {
        if ((piVar3[1] == 0) && (*piVar3 == 0)) goto LAB_005f9f18;
        iVar4 = iVar4 + 1;
        piVar3 = piVar3 + 8;
      } while (iVar4 <= *(int *)(DAT_00f94300 + 0x2398));
    }
    iVar4 = 0;
  }
LAB_005f9f18:
  if ((in_ECX == 0) || (iVar4 == 0)) {
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 1;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
    }
    local_c = 0xffffffff;
    local_20 = 0x196;
    FUN_005740f0(&local_20);
    if (local_1c[0] == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if ((DAT_00fe5b2c & 1) == 0) {
      DAT_00fe5b2c = DAT_00fe5b2c | 1;
      local_c = 2;
      FUN_00584c40(&DAT_00fe5b0c);
      _atexit(FUN_00bcf370);
      local_c = 0xffffffff;
    }
    local_1c[0] = 0xbe;
    FUN_005740f0(local_1c);
    if (local_20 == DAT_00fe5b10) {
      pcVar1 = (code *)swi(3);
      (*pcVar1)();
      return;
    }
    if (*(uint *)(local_20 + 0x24) < 8) {
      iVar4 = local_20 + 0x10;
    }
    else {
      iVar4 = *(int *)(local_20 + 0x10);
    }
    if ((DAT_00faadd0 & 1) == 0) {
      DAT_00faadd0 = DAT_00faadd0 | 1;
      local_c = 3;
      FUN_0074d990();
      _atexit((_func_4879 *)&LAB_00bccc70);
      local_c = 0xffffffff;
    }
    FUN_007532b0(&DAT_00f94810,iVar4,0,0);
  }
  else {
    iVar2 = FUN_00404ba0();
    iVar2 = FUN_00509350(*(int *)(iVar2 + 0x6920) + 0x23a0);
    if (iVar2 != 0) {
      iVar2 = *(int *)(iVar2 + 8);
      if (1 < iVar2) {
        FUN_005f5d20(param_1,0xf4371,iVar2,iVar2,param_2,param_3,in_ECX,iVar4);
        ExceptionList = local_14;
        return;
      }
      FUN_005fa0f0(param_2,param_3,1);
      ExceptionList = local_14;
      return;
    }
  }
  ExceptionList = local_14;
  return;
}

