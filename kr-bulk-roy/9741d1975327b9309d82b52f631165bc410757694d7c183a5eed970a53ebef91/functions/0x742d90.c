
undefined2 * FUN_00742d90(undefined2 *param_1)

{
  short sVar1;
  short *psVar2;
  short *in_EDX;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f028;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  if (7 < *(uint *)(in_EDX + 10)) {
    in_EDX = *(short **)in_EDX;
  }
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  psVar2 = in_EDX;
  do {
    sVar1 = *psVar2;
    psVar2 = psVar2 + 1;
  } while (sVar1 != 0);
  FUN_00741900(in_EDX,(int)psVar2 - (int)(in_EDX + 1) >> 1);
  local_8 = 0;
  FUN_00742cc0(param_1 + 0xe);
  *unaff_FS_OFFSET = local_10;
  return param_1;
}

