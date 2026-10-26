
void FUN_008fd1c0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x10) != 0) {
                    /* WARNING: Could not recover jumptable at 0x008fd1d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*(int *)(in_EAX + 0x10) + 8) + 4))();
    return;
  }
  return;
}

