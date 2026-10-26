
void FUN_0080d8b0(void)

{
  int in_ECX;
  
  if (((*(int *)(in_ECX + 8) == 0) && (*(int *)(in_ECX + 0xc) == 0)) &&
     (*(int *)(in_ECX + 0x10) == 0)) {
    InterlockedExchange((LONG *)(in_ECX + 0xc),1);
                    /* WARNING: Could not recover jumptable at 0x0080d8db. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(in_ECX + -4) + 4))();
    return;
  }
  return;
}

