
void FUN_008c1360(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *in_EDX;
  int iVar4;
  
  iVar4 = *in_EDX;
  if (in_EDX[6] < *in_EDX) {
    iVar4 = in_EDX[6];
  }
  piVar1 = (int *)(in_EDX[0x14c] + in_EDX[1] * 4);
  piVar3 = (int *)*piVar1;
  while ((piVar3 != (int *)0x0 && (*piVar3 <= iVar4))) {
    if (*piVar3 == iVar4) {
      return;
    }
    piVar1 = piVar3 + 3;
    piVar3 = (int *)*piVar1;
  }
  iVar2 = in_EDX[0xd];
  if (iVar2 < in_EDX[0xc]) {
    piVar3 = (int *)(iVar2 * 0x10 + in_EDX[0xb]);
    in_EDX[0xd] = iVar2 + 1;
    *piVar3 = iVar4;
    piVar3[2] = 0;
    piVar3[1] = 0;
    piVar3[3] = *piVar1;
    *piVar1 = (int)piVar3;
    return;
  }
                    /* WARNING: Subroutine does not return */
  FID_conflict____longjmp_internal(in_EDX + 0x13a,1);
}

