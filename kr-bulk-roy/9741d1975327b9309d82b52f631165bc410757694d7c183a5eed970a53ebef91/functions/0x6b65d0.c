
void FUN_006b65d0(void)

{
  code *UNRECOVERED_JUMPTABLE;
  int in_ECX;
  
  UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(in_ECX + 0x80) + 0x128);
  (*(int **)(in_ECX + 0x80))[0x34] = 0x42c80000;
  (*UNRECOVERED_JUMPTABLE)();
  UNRECOVERED_JUMPTABLE = *(code **)(**(int **)(in_ECX + 0x84) + 0x128);
  (*(int **)(in_ECX + 0x84))[0x34] = 0x42c80000;
                    /* WARNING: Could not recover jumptable at 0x006b6612. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

