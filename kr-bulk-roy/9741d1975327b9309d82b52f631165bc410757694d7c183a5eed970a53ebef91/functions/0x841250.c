
void FUN_00841250(void)

{
  undefined *puVar1;
  int *in_ECX;
  undefined *puVar2;
  
  puVar2 = (undefined *)((in_ECX[1] - *in_ECX) / 0x11c);
  if (&DAT_00e6c2b3 < puVar2) {
                    /* WARNING: Subroutine does not return */
    FUN_0087db30("vector<T> too long");
  }
  puVar1 = (undefined *)((in_ECX[2] - *in_ECX) / 0x11c);
  puVar2 = puVar2 + 1;
  if (puVar1 < puVar2) {
    if (&DAT_00e6c2b4 + -((uint)puVar1 >> 1) < puVar1) {
      puVar1 = (undefined *)0x0;
    }
    else {
      puVar1 = puVar1 + ((uint)puVar1 >> 1);
    }
    if (puVar1 < puVar2) {
      puVar1 = puVar2;
    }
    FUN_00841680(puVar1);
  }
  return;
}

