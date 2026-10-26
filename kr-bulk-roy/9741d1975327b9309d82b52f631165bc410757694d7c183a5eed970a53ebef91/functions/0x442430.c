
void FUN_00442430(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0xf8) != 0) {
    if ((*(uint *)(*(int *)(in_EAX + 0xf8) + 0x28) >> 8 & 1) != 0) {
                    /* WARNING: Could not recover jumptable at 0x00442456. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(**(int **)(in_EAX + 0xf8) + 0xd4))();
      return;
    }
    (**(code **)(**(int **)(in_EAX + 0xf8) + 0xd0))();
    FUN_004423e0();
  }
  return;
}

