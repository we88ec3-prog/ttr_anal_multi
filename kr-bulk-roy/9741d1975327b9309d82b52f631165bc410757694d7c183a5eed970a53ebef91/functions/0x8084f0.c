
void FUN_008084f0(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined **local_28 [3];
  int local_1c;
  char *local_18;
  int local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00909816;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar2 = FUN_00891268(0x10,uVar1);
  local_8 = 0;
  local_1c = iVar2;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 8) = 0;
    iVar3 = FUN_00891268(0x30,uVar1);
    if (iVar3 == 0) {
      local_18 = (char *)0x0;
      std::exception::exception((exception *)local_28,&local_18);
      local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_28,&DAT_00c857a8);
    }
    *(int *)(iVar2 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(iVar2 + 4) + 4) = *(int *)(iVar2 + 4);
    *(int *)(*(int *)(iVar2 + 4) + 8) = *(int *)(iVar2 + 4);
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0x2c) = 1;
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0x2d) = 1;
  }
  local_8 = 0xffffffff;
  *(int *)(local_14 + 0x14) = iVar2;
  iVar2 = FUN_00891268(0x10,uVar1);
  local_8 = 1;
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    *(undefined4 *)(iVar2 + 8) = 0;
    local_1c = iVar2;
    iVar3 = FUN_00891268(0x30,uVar1);
    if (iVar3 == 0) {
      local_18 = (char *)0x0;
      std::exception::exception((exception *)local_28,&local_18);
      local_28[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_28,&DAT_00c857a8);
    }
    *(int *)(iVar2 + 4) = iVar3;
    *(int *)iVar3 = iVar3;
    *(int *)(*(int *)(iVar2 + 4) + 4) = *(int *)(iVar2 + 4);
    *(int *)(*(int *)(iVar2 + 4) + 8) = *(int *)(iVar2 + 4);
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0x2c) = 1;
    *(undefined1 *)(*(int *)(iVar2 + 4) + 0x2d) = 1;
  }
  *(int *)(local_14 + 0x18) = iVar2;
  ExceptionList = local_10;
  return;
}

