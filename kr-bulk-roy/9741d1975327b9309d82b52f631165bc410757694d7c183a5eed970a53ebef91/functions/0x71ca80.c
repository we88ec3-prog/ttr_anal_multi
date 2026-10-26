
undefined1 * FUN_0071ca80(void)

{
  undefined1 *puVar1;
  int *in_ECX;
  
  if (in_ECX[1] == 0) {
    if (*in_ECX == 0) goto LAB_0071caa4;
    puVar1 = *(undefined1 **)(*in_ECX + 8);
  }
  else {
    puVar1 = *(undefined1 **)(in_ECX[1] + 4);
  }
  if (puVar1 != (undefined1 *)0x0) {
    return puVar1;
  }
LAB_0071caa4:
  return &DAT_00bf2375;
}

