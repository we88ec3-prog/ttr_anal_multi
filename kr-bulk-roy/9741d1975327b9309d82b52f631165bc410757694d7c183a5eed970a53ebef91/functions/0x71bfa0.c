
undefined4 * FUN_0071bfa0(undefined4 *param_1)

{
  char cVar1;
  undefined4 uVar2;
  char *in_EDX;
  
  if (*in_EDX != '\0') {
    do {
      cVar1 = *in_EDX;
      in_EDX = in_EDX + 1;
    } while (cVar1 != '\0');
    uVar2 = FUN_0071bf40();
    *param_1 = uVar2;
    *(undefined1 *)(param_1 + 1) = 1;
    return param_1;
  }
  *param_1 = &DAT_00bf2375;
  *(undefined1 *)(param_1 + 1) = 0;
  return param_1;
}

