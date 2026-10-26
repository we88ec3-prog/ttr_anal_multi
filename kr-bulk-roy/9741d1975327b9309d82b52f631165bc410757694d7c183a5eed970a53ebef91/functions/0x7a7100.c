
float10 FUN_007a7100(void)

{
  int iVar1;
  int unaff_ESI;
  int local_18;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093912e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fc0f60 & 1) == 0) {
    DAT_00fc0f60 = DAT_00fc0f60 | 1;
    local_8 = 0;
    FUN_0079cf40(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcdb80);
  }
  local_14 = *(undefined4 *)(unaff_ESI + 0x18);
  FUN_00515790(&local_14);
  if ((local_18 != DAT_00fc0e94) && (iVar1 = *(int *)(*(int *)(local_18 + 0x10) + 0x54), iVar1 != 0)
     ) {
    ExceptionList = local_10;
    return (float10)(*(float *)(iVar1 + 0xf0) * *(float *)(unaff_ESI + 0xf8));
  }
  ExceptionList = local_10;
  return (float10)1;
}

