
void FUN_006f9d80(undefined4 param_1)

{
  undefined4 *puVar1;
  int in_EDX;
  int unaff_ESI;
  
  puVar1 = (undefined4 *)
           (((1 << (*(byte *)(unaff_ESI + 7) & 0x1f)) - 1U & *(uint *)(in_EDX + 8)) * 0x20 +
           *(int *)(unaff_ESI + 0x10));
  do {
    if (puVar1 == (undefined4 *)0x0) {
LAB_006f9dbb:
      FUN_006f9a60(param_1);
      return;
    }
    if ((puVar1[6] == 4) && (puVar1[4] == in_EDX)) {
      if (puVar1 != &DAT_00c0bfc8) {
        return;
      }
      goto LAB_006f9dbb;
    }
    puVar1 = (undefined4 *)puVar1[7];
  } while( true );
}

