
void FUN_00867630(undefined4 *param_1)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 8) == 0) {
    puVar1 = (undefined4 *)FUN_00891268(4);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = 0;
      *(undefined4 **)(unaff_ESI + 8) = puVar1;
      *puVar1 = *param_1;
      return;
    }
    *(undefined4 *)(unaff_ESI + 8) = 0;
  }
  **(undefined4 **)(unaff_ESI + 8) = *param_1;
  return;
}

