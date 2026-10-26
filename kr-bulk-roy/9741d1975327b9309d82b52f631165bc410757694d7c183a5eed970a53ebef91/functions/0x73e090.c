
undefined4 * FUN_0073e090(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_FS_OFFSET;
  undefined **local_20 [3];
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090f0cd;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  *param_1 = 0;
  param_1[3] = 0;
  uVar2 = FUN_007b2620(uVar1);
  param_1[2] = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(undefined4 *)(param_1[2] + 4) = param_1[2];
  *(undefined4 *)(param_1[2] + 8) = param_1[2];
  *(undefined1 *)(param_1[2] + 0x38) = 1;
  *(undefined1 *)(param_1[2] + 0x39) = 1;
  local_8 = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  iVar3 = FUN_00891268(0x18);
  if (iVar3 != 0) {
    param_1[7] = iVar3;
    *(int *)iVar3 = iVar3;
    *(undefined4 *)(param_1[7] + 4) = param_1[7];
    *(undefined4 *)(param_1[7] + 8) = param_1[7];
    *(undefined1 *)(param_1[7] + 0x14) = 1;
    *(undefined1 *)(param_1[7] + 0x15) = 1;
    *unaff_FS_OFFSET = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

