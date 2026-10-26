
undefined4 FUN_00782bc0(void)

{
  int *piVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x8d) == '\0') &&
     (piVar1 = *(int **)(in_ECX + 0x88), *(int *)(*(int *)(*piVar1 + 4) + 0xc + (int)piVar1) == 0))
  {
    FUN_007825d0(piVar1);
    FUN_00782550(in_ECX);
    FUN_007824d0();
    *(undefined1 *)(in_ECX + 0x8d) = 1;
    return 1;
  }
  return 0;
}

