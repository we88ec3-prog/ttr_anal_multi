
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_007ac300(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*DAT_00fd92a0;
  *DAT_00fd92a0 = (int)DAT_00fd92a0;
  DAT_00fd92a0[1] = (int)DAT_00fd92a0;
  _DAT_00fd92a4 = 0;
  if (piVar2 != DAT_00fd92a0) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != DAT_00fd92a0);
  }
  return;
}

