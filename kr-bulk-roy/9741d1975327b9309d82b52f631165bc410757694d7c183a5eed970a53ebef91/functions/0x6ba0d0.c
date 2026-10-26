
void FUN_006ba0d0(void)

{
  int iVar1;
  int unaff_ESI;
  undefined1 auStack_18 [4];
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_009461ee;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)auStack_18);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar1 = DAT_00fab130;
  *(undefined4 *)(unaff_ESI + 0x80) = *(undefined4 *)(DAT_00fab130 + 0x5f0c);
  *(undefined4 *)(unaff_ESI + 0x84) = *(undefined4 *)(iVar1 + 0x5f10);
  ExceptionList = local_14;
  return;
}

