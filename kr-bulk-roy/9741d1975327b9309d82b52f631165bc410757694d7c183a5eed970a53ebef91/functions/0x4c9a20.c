
float10 FUN_004c9a20(void)

{
  int in_EAX;
  int *piVar1;
  float10 fVar2;
  
  if ((*(int *)(in_EAX + 0x15c) != 0) && (*(int *)(in_EAX + 0x370) != 0)) {
    piVar1 = (int *)FUN_007a7800(*(undefined4 *)(*(int *)(in_EAX + 0x15c) + 0xa8));
    if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004c9a4f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      fVar2 = (float10)(**(code **)(*piVar1 + 0x18))();
      return fVar2;
    }
    return (float10)30.0;
  }
  return (float10)0;
}

