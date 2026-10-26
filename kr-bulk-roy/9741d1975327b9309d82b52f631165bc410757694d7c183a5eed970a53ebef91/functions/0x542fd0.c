
undefined4 FUN_00542fd0(int param_1)

{
  long lVar1;
  long *unaff_ESI;
  int local_c;
  
  if (param_1 == 0) {
    return 0;
  }
  if (unaff_ESI != (long *)0x0) {
    FUN_0071baa0(&DAT_00c0f770);
    if (local_c != 0) {
      if (*(char **)(local_c + 8) != (char *)0x0) {
        lVar1 = _strtol(*(char **)(local_c + 8),(char **)0x0,10);
        *unaff_ESI = lVar1;
        return 1;
      }
      *unaff_ESI = 0;
    }
  }
  return 1;
}

