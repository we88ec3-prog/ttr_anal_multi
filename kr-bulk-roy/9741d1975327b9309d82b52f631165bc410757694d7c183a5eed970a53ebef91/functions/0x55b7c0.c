
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0055b7c0(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*DAT_00fd8eb0;
  *DAT_00fd8eb0 = (int)DAT_00fd8eb0;
  DAT_00fd8eb0[1] = (int)DAT_00fd8eb0;
  _DAT_00fd8eb4 = 0;
  if (piVar2 != DAT_00fd8eb0) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != DAT_00fd8eb0);
  }
  return;
}

