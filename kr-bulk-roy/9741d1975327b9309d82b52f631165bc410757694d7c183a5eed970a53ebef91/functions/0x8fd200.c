
void FUN_008fd200(void)

{
  int *in_EAX;
  
  if (*in_EAX != 0) {
                    /* WARNING: Could not recover jumptable at 0x008fd20f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(*(int *)(*in_EAX + 4) + 4))();
    return;
  }
  return;
}

