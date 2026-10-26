
void FUN_0066d7c0(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  undefined **local_24 [3];
  char *local_18;
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908231;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 1U) {
    FUN_00507d30(param_1);
  }
  iVar4 = *(int *)(param_1 + 0xc);
  if (iVar4 == 0) {
    iVar4 = *(int *)(param_1 + 8);
  }
  iVar4 = iVar4 + -1;
  if (*(int *)(*(int *)(param_1 + 4) + iVar4 * 4) == 0) {
    iVar2 = FUN_00891268(0x50,uVar1);
    if (iVar2 == 0) {
      local_14 = (char *)0x0;
      std::exception::exception((exception *)local_24,&local_14);
      local_24[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_24,&DAT_00c857a8);
    }
    *(int *)(*(int *)(param_1 + 4) + iVar4 * 4) = iVar2;
  }
  local_18 = *(char **)(*(int *)(param_1 + 4) + iVar4 * 4);
  local_8 = 0;
  if (local_18 != (char *)0x0) {
    *(undefined4 *)local_18 = *param_2;
    puVar3 = param_2 + 0x10;
    iVar2 = 0xf;
    pcVar5 = local_18;
    while( true ) {
      pcVar5 = pcVar5 + 4;
      param_2 = param_2 + 1;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      *(undefined4 *)pcVar5 = *param_2;
    }
    local_14 = local_18;
    FUN_00507f70(local_18 + 0x40,puVar3);
  }
  *(int *)(param_1 + 0xc) = iVar4;
  *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
  ExceptionList = local_10;
  return;
}

