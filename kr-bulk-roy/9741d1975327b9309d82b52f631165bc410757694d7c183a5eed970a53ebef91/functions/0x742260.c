
int FUN_00742260(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  int *unaff_FS_OFFSET;
  undefined **local_20 [3];
  char *local_14;
  int local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908878;
  local_10 = *unaff_FS_OFFSET;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  *unaff_FS_OFFSET = (int)&local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar3 = FUN_00891268(0xa0,uVar2);
  if (iVar3 != 0) {
    *(int *)(param_1 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x9c) = 1;
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x9d) = 1;
    local_8 = 0;
    if (param_1 != unaff_EDI) {
      FUN_0073f510(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
      *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
      *(undefined4 *)*(undefined4 *)(param_1 + 4) = *(undefined4 *)(param_1 + 4);
      *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
      *(undefined4 *)(param_1 + 8) = 0;
      uVar1 = *(undefined4 *)(param_1 + 4);
      *(undefined4 *)(param_1 + 4) = *(undefined4 *)(unaff_EDI + 4);
      *(undefined4 *)(unaff_EDI + 4) = uVar1;
      uVar1 = *(undefined4 *)(param_1 + 8);
      *(undefined4 *)(param_1 + 8) = *(undefined4 *)(unaff_EDI + 8);
      *(undefined4 *)(unaff_EDI + 8) = uVar1;
    }
    *unaff_FS_OFFSET = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

