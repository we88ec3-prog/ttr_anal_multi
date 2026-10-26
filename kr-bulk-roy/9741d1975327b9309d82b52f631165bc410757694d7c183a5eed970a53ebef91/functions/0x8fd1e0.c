
void FUN_008fd1e0(void)

{
  int *in_EAX;
  
  if (*in_EAX != 0) {
                    /* WARNING: Could not recover jumptable at 0x008fd1ef. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*in_EAX + 4) + 8))();
    return;
  }
  return;
}

