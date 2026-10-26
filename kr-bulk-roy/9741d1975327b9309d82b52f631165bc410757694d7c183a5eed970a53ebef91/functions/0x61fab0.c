
void FUN_0061fab0(void)

{
  uint uVar1;
  int *piVar2;
  int in_ECX;
  short *psVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009125da;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if (DAT_00fb92c9 == ' ') {
    piVar2 = (int *)(DAT_00fb1318 + 0xbfec);
  }
  else {
    piVar2 = (int *)(DAT_00fb1318 + 0xbffc);
  }
  psVar3 = (short *)(in_ECX * 0x10 + *piVar2);
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 1;
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  DAT_00fb92aa = *psVar3;
  if (DAT_00fb92ae < *psVar3) {
    DAT_00fb92aa = DAT_00fb92ae;
  }
  if (DAT_00fb92aa < DAT_00fb92ac) {
    DAT_00fb92aa = DAT_00fb92ac;
  }
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 2;
    FUN_0054f850(uVar1);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  local_8 = 0xffffffff;
  DAT_00fb92ba = psVar3[2];
  if (DAT_00fb92be < psVar3[2]) {
    DAT_00fb92ba = DAT_00fb92be;
  }
  if (DAT_00fb92ba < DAT_00fb92bc) {
    DAT_00fb92ba = DAT_00fb92bc;
  }
  FUN_006dedf0(*(undefined4 *)psVar3,*(undefined4 *)(psVar3 + 2),
               (-(uint)(*(int *)(psVar3 + 6) != 0x16) & 0xfffffff0) + 0x20);
  FUN_006e32a0();
  ExceptionList = local_10;
  return;
}

