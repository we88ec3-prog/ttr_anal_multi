
void FUN_008fd1a0(void)

{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x10) != 0) {
                    /* WARNING: Could not recover jumptable at 0x008fd1b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*(int *)(in_EAX + 0x10) + 8) + 8))();
    return;
  }
  return;
}

