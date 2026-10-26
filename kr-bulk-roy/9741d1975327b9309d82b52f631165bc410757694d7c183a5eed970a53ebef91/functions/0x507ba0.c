
void FUN_00507ba0(char *param_1,undefined4 *param_2)

{
  char *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  char *pcVar6;
  undefined **local_20 [3];
  char *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  pcVar1 = param_1;
  local_8 = 0xffffffff;
  puStack_c = &LAB_009064b1;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 1U) {
    FUN_00507d30(param_1);
  }
  uVar4 = *(int *)(pcVar1 + 0xc) + *(int *)(pcVar1 + 0x10);
  if (*(uint *)(pcVar1 + 8) <= uVar4) {
    uVar4 = uVar4 - *(uint *)(pcVar1 + 8);
  }
  if (*(int *)(*(int *)(pcVar1 + 4) + uVar4 * 4) == 0) {
    iVar3 = FUN_00891268(0x50,uVar2);
    if (iVar3 == 0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_20,&param_1);
      local_20[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_20,&DAT_00c857a8);
    }
    *(int *)(*(int *)(pcVar1 + 4) + uVar4 * 4) = iVar3;
  }
  param_1 = *(char **)(*(int *)(pcVar1 + 4) + uVar4 * 4);
  local_8 = 0;
  if (param_1 != (char *)0x0) {
    *(undefined4 *)param_1 = *param_2;
    iVar3 = 0xf;
    puVar5 = param_2;
    pcVar6 = param_1;
    while( true ) {
      pcVar6 = pcVar6 + 4;
      puVar5 = puVar5 + 1;
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      *(undefined4 *)pcVar6 = *puVar5;
    }
    local_14 = param_1;
    FUN_00507f70(param_1 + 0x40,param_2 + 0x10);
  }
  *(int *)(pcVar1 + 0x10) = *(int *)(pcVar1 + 0x10) + 1;
  ExceptionList = local_10;
  return;
}

