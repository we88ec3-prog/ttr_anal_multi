
void FUN_0056bd50(char *param_1,undefined4 *param_2)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined **local_10 [3];
  
  pcVar1 = param_1;
  if (*(uint *)(param_1 + 8) <= *(int *)(param_1 + 0x10) + 1U) {
    FUN_0056bdf0(param_1);
  }
  uVar3 = *(int *)(pcVar1 + 0xc) + *(int *)(pcVar1 + 0x10);
  if (*(uint *)(pcVar1 + 8) <= uVar3) {
    uVar3 = uVar3 - *(uint *)(pcVar1 + 8);
  }
  if (*(int *)(*(int *)(pcVar1 + 4) + uVar3 * 4) == 0) {
    iVar2 = FUN_00891268(0x210);
    if (iVar2 == 0) {
      param_1 = (char *)0x0;
      std::exception::exception((exception *)local_10,&param_1);
      local_10[0] = std::bad_alloc::vftable;
                    /* WARNING: Subroutine does not return */
      __CxxThrowException_8(local_10,&DAT_00c857a8);
    }
    *(int *)(*(int *)(pcVar1 + 4) + uVar3 * 4) = iVar2;
  }
  puVar4 = *(undefined4 **)(*(int *)(pcVar1 + 4) + uVar3 * 4);
  if (puVar4 != (undefined4 *)0x0) {
    for (iVar2 = 0x84; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *param_2;
      param_2 = param_2 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  *(int *)(pcVar1 + 0x10) = *(int *)(pcVar1 + 0x10) + 1;
  return;
}

