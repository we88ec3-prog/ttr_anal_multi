
void FUN_007d18a0(undefined4 param_1)

{
  int iVar1;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093481e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  FUN_0079b520(&DAT_00fb76a8,2);
  iVar1 = 0;
  if (*(int *)(unaff_EDI + 0xc014) < 1) {
    *(undefined4 *)(unaff_EDI + 0xc014) = 0;
    ExceptionList = local_10;
    return;
  }
  do {
    (**(code **)(**(int **)(unaff_EDI + 0xa014 + iVar1 * 4) + 0xc))(param_1,5);
    iVar1 = iVar1 + 1;
  } while (iVar1 < *(int *)(unaff_EDI + 0xc014));
  *(undefined4 *)(unaff_EDI + 0xc014) = 0;
  ExceptionList = local_10;
  return;
}

