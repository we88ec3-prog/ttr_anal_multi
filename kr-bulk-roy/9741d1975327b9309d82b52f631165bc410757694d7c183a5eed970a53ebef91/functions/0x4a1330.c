
void FUN_004a1330(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090ab2e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_006dedf0(param_1,param_2,param_3);
  FUN_006e71f0(1,1,uVar3);
  cVar1 = FUN_006ea3d0();
  if (cVar1 == '\0') {
    FUN_006e32a0();
  }
  else {
    FUN_006e2e20();
  }
  FUN_006e71f0(0,0);
  bVar2 = FUN_006ea3d0();
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850();
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  if (DAT_00fb91d3 < bVar2) {
    bVar2 = DAT_00fb91d3;
  }
  DAT_00fb91d1 = DAT_00fb91d2;
  if (DAT_00fb91d2 <= bVar2) {
    DAT_00fb91d1 = bVar2;
  }
  ExceptionList = local_10;
  return;
}

