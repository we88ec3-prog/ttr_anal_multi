
undefined4 * FUN_00426d40(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  byte *unaff_EDI;
  
  puVar3 = *(undefined4 **)(unaff_ESI + 4);
  if (*(char *)((int)puVar3[1] + 0x45) == '\0') {
    puVar1 = (undefined4 *)puVar3[1];
    do {
      if (*(byte *)(puVar1 + 3) < *unaff_EDI) {
        puVar2 = (undefined4 *)puVar1[2];
      }
      else {
        puVar2 = (undefined4 *)*puVar1;
        puVar3 = puVar1;
      }
      puVar1 = puVar2;
    } while (*(char *)((int)puVar2 + 0x45) == '\0');
  }
  if ((puVar3 != *(undefined4 **)(unaff_ESI + 4)) && (*(byte *)(puVar3 + 3) <= *unaff_EDI)) {
    return puVar3 + 4;
  }
                    /* WARNING: Subroutine does not return */
  FUN_0087db7d("invalid map<K, T> key");
}

