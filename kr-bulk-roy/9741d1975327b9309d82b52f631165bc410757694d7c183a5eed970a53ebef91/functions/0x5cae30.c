
void FUN_005cae30(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x38) != 0) {
    (**(code **)(**(int **)(in_ECX + 0x38) + 0xe4))(*(int **)(in_ECX + 0x38),0x1b,1);
    (**(code **)(**(int **)(in_ECX + 0x38) + 0xe4))(*(int **)(in_ECX + 0x38),0x13,5);
    (**(code **)(**(int **)(in_ECX + 0x38) + 0xe4))(*(int **)(in_ECX + 0x38),0x14,6);
    if (*(int *)(in_ECX + 0x24) != 0) {
                    /* WARNING: Could not recover jumptable at 0x005cae7e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(in_ECX + 0x24) + 0x14))();
      return;
    }
  }
  return;
}

