
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00691900(int param_1)

{
  short sVar1;
  code *pcVar2;
  short *psVar3;
  int *in_ECX;
  short *psVar4;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0092cfce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_007445d0();
  if (*(int *)(param_1 + 0x10) != 0xcb) {
    if (*(int *)(param_1 + 0x10) == 0xcc) {
      (**(code **)(*in_ECX + 0x54))();
    }
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00fe5ae4 & 1) == 0) {
    DAT_00fe5ae4 = DAT_00fe5ae4 | 1;
    local_8 = 0;
    FUN_00584c40();
    _atexit((_func_4879 *)&LAB_00bcf390);
    local_8 = 0xffffffff;
  }
  FUN_005740f0();
  if (local_14 != DAT_00fe5ac8) {
    psVar4 = (short *)(local_14 + 0x10);
    if (7 < *(uint *)(local_14 + 0x24)) {
      psVar4 = *(short **)psVar4;
    }
    psVar3 = psVar4;
    do {
      sVar1 = *psVar3;
      psVar3 = psVar3 + 1;
    } while (sVar1 != 0);
    FUN_00402160(psVar4,(int)psVar3 - (int)(psVar4 + 1) >> 1);
    if ((_DAT_00f8d910 & 1) == 0) {
      _DAT_00f8d910 = _DAT_00f8d910 | 1;
      _atexit((_func_4879 *)&DAT_00bccc60);
    }
    FUN_006cb880();
    (**(code **)(*in_ECX + 0x50))();
    ExceptionList = local_10;
    return;
  }
  pcVar2 = (code *)swi(3);
  (*pcVar2)();
  return;
}

