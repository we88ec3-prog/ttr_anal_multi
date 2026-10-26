
undefined4 * FUN_0073fd00(undefined4 *param_1,char *param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 in_ECX;
  undefined4 in_EDX;
  int *unaff_FS_OFFSET;
  undefined **local_1c [3];
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090591d;
  local_10 = *unaff_FS_OFFSET;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  param_1[2] = param_2;
  param_1[3] = in_ECX;
  *param_1 = CFTType::vftable;
  param_1[1] = 1;
  param_1[4] = in_EDX;
  param_1[5] = param_3;
  param_1[6] = param_4;
  param_1[9] = 0;
  iVar2 = FUN_00891268(0x18,uVar1);
  if (iVar2 != 0) {
    param_1[8] = iVar2;
    *(int *)iVar2 = iVar2;
    *(undefined4 *)(param_1[8] + 4) = param_1[8];
    *(undefined4 *)(param_1[8] + 8) = param_1[8];
    *(undefined1 *)(param_1[8] + 0x14) = 1;
    *(undefined1 *)(param_1[8] + 0x15) = 1;
    local_8 = 0;
    if ((undefined4 *)param_1[2] != (undefined4 *)0x0) {
      (*(code *)**(undefined4 **)param_1[2])();
    }
    *unaff_FS_OFFSET = local_10;
    return param_1;
  }
  param_2 = (char *)0x0;
  std::exception::exception((exception *)local_1c,&param_2);
  local_1c[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_1c,&DAT_00c857a8);
}

