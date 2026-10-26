
int FUN_00827290(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int unaff_EDI;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908878;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 8) = 0;
  iVar3 = FUN_00891268(0x2c,uVar2);
  if (iVar3 != 0) {
    *(int *)(param_1 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(param_1 + 4) + 4) = *(int *)(param_1 + 4);
    *(int *)(*(int *)(param_1 + 4) + 8) = *(int *)(param_1 + 4);
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x28) = 1;
    *(undefined1 *)(*(int *)(param_1 + 4) + 0x29) = 1;
    local_8 = 0;
    if (param_1 != unaff_EDI) {
      FUN_00524320(*(undefined4 *)(*(int *)(param_1 + 4) + 4));
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
    ExceptionList = local_10;
    return param_1;
  }
  local_14 = (char *)0x0;
  std::exception::exception((exception *)local_20,&local_14);
  local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
  __CxxThrowException_8(local_20,&DAT_00c857a8);
}

