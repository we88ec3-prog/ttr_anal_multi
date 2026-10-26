
int FUN_008c7390(void)

{
  int *piVar1;
  int in_EDX;
  int unaff_ESI;
  
  piVar1 = &DAT_00bd8280;
  while ((*piVar1 != unaff_ESI || ((piVar1[1] != in_EDX && (piVar1[1] != -1))))) {
    piVar1 = piVar1 + 3;
    if (&UNK_00bd8303 < piVar1) {
      return 0;
    }
  }
  return piVar1[2];
}

