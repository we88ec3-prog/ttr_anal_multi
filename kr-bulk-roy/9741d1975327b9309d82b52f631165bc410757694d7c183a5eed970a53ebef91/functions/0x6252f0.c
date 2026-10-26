
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_006252f0(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00926dca;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *(uint *)(*(int *)(param_1 + 0xec) + 0x28);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  DAT_00fb9111 = (uVar1 >> 9 & 1) != 0;
  if (DAT_00fb9113 < DAT_00fb9111) {
    DAT_00fb9111 = DAT_00fb9113;
  }
  if (DAT_00fb9111 < DAT_00fb9112) {
    DAT_00fb9111 = DAT_00fb9112;
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850(uVar2);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8 = 0xffffffff;
  if (DAT_00fb9111 == 0) {
    if ((_DAT_00fc1a6c & 1) == 0) {
      _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
      _atexit((_func_4879 *)&DAT_00bce3b0);
    }
    if (DAT_00fba80c == 0) {
      iVar3 = FUN_00891268(0x57c);
      if (iVar3 == 0) {
        DAT_00fba80c = 0;
      }
      else {
        DAT_00fba80c = FUN_006f1370();
      }
    }
    piVar4 = (int *)FUN_006f1640(DAT_00fba80c);
    if (piVar4 != (int *)0x0) {
      (**(code **)(*piVar4 + 0x28))(0);
    }
    ExceptionList = local_10;
    return;
  }
  if ((_DAT_00fc1a6c & 1) == 0) {
    _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
    _atexit((_func_4879 *)&DAT_00bce3b0);
  }
  if (DAT_00fba80c == 0) {
    iVar3 = FUN_00891268(0x57c);
    if (iVar3 == 0) {
      DAT_00fba80c = 0;
    }
    else {
      DAT_00fba80c = FUN_006f1370();
    }
  }
  piVar4 = (int *)FUN_006f1640(DAT_00fba80c);
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 0x28))(1);
  }
  if ((_DAT_00fc1a6c & 1) == 0) {
    _DAT_00fc1a6c = _DAT_00fc1a6c | 1;
    _atexit((_func_4879 *)&DAT_00bce3b0);
  }
  FUN_006f3690();
  if ((DAT_00fc1724 & 1) == 0) {
    DAT_00fc1724 = DAT_00fc1724 | 1;
    local_8 = 2;
    FUN_006ccd20();
    _atexit((_func_4879 *)&LAB_00bce3c0);
    local_8 = 0xffffffff;
  }
  FUN_006ccfc0();
  ExceptionList = local_10;
  return;
}

