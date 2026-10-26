
int * FUN_0052f3b0(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int *unaff_FS_OFFSET;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00906330;
  local_10 = *unaff_FS_OFFSET;
  *unaff_FS_OFFSET = (int)&local_10;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  uVar1 = (param_2[1] - *param_2) / 0xc;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  if (uVar1 != 0) {
    if (0x15555555 < uVar1) {
                    /* WARNING: Subroutine does not return */
      FUN_0087db30("vector<T> too long");
    }
    iVar2 = FUN_0085e740();
    param_1[2] = iVar2 + uVar1 * 0xc;
    local_8 = 0;
    *param_1 = iVar2;
    param_1[1] = iVar2;
    iVar2 = FUN_00825d90(*param_2,param_2[1],param_1);
    param_1[1] = iVar2;
  }
  *unaff_FS_OFFSET = local_10;
  return param_1;
}

