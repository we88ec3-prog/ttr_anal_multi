
void FUN_006472f0(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00765de0();
  FUN_00767f50();
  iVar1 = *(int *)(in_ECX + 0x10c);
  *(undefined1 *)(in_ECX + 0x120) = 1;
  iVar2 = *(int *)(iVar1 + 8);
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -iVar2;
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -iVar2;
  iVar2 = *(int *)(iVar1 + 0xc);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + -iVar2;
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x14) + -iVar2;
  FUN_00746f70();
                    /* WARNING: Could not recover jumptable at 0x00647334. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x10c) + 200))();
  return;
}

