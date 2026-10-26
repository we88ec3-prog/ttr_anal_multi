
void FUN_0054e270(void)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[0x10] != 0) {
    iVar1 = in_ECX[3] - in_ECX[2] >> 2;
    if ((iVar1 == 0) || (in_ECX[0x11] <= *(int *)(*(int *)(in_ECX[2] + -4 + iVar1 * 4) + 0x24))) {
      FUN_00797790();
      in_ECX[0x11] = in_ECX[0x11] + 1;
    }
    else {
      in_ECX[0x10] = 0;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x0054e2b3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 4))();
  return;
}

