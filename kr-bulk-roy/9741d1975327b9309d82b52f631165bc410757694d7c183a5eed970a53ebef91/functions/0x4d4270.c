
/* WARNING: Removing unreachable block (ram,0x004d42a2) */
/* WARNING: Removing unreachable block (ram,0x004d42a3) */
/* WARNING: Removing unreachable block (ram,0x004d42b7) */

void FUN_004d4270(void)

{
  int *piVar1;
  byte in_AL;
  int in_EDX;
  
  if ((in_AL < 7) && (piVar1 = (int *)(in_EDX + 0x110 + (uint)in_AL * 0x1c), piVar1 != (int *)0x0))
  {
    piVar1[5] = 0;
    if (*piVar1 != piVar1[1]) {
      piVar1[1] = *piVar1;
    }
  }
  return;
}

