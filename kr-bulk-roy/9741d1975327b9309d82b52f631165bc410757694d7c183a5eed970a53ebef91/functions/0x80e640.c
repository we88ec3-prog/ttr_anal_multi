
void FUN_0080e640(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
                    /* WARNING: Could not recover jumptable at 0x0080e657. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(**(int **)(iVar1 + 8) + 0x24))();
    return;
  }
  return;
}

