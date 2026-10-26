
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005585b0(void)

{
  int *piVar1;
  int *piVar2;
  
  piVar2 = (int *)*DAT_00fc1ac4;
  *DAT_00fc1ac4 = (int)DAT_00fc1ac4;
  DAT_00fc1ac4[1] = (int)DAT_00fc1ac4;
  _DAT_00fc1ac8 = 0;
  if (piVar2 != DAT_00fc1ac4) {
    do {
      piVar1 = (int *)*piVar2;
      FUN_0089120c(piVar2);
      piVar2 = piVar1;
    } while (piVar1 != DAT_00fc1ac4);
  }
  return;
}

