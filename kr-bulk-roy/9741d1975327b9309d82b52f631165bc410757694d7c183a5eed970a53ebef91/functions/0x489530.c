
void FUN_00489530(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  float *pfVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009311dc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  uVar2 = DAT_00fb90a4;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  *(undefined4 *)(DAT_00fb76e8 + 0x28) = uVar2;
  iVar4 = 0;
  pfVar3 = (float *)(param_1 + 4);
  do {
    if (pfVar3[-1] != 0.0) {
      FUN_00489650();
      fVar1 = *pfVar3;
      *pfVar3 = fVar1 + 1.0471976;
      if (pfVar3[1] < fVar1 + 1.0471976) {
        pfVar3[-1] = 0.0;
      }
    }
    iVar4 = iVar4 + 1;
    pfVar3 = pfVar3 + 5;
  } while (iVar4 < 0x20);
  ExceptionList = local_10;
  return;
}

