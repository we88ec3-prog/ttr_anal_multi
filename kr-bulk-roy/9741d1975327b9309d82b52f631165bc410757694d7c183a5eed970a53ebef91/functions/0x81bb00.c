
undefined4 * FUN_0081bb00(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  byte in_DL;
  int unaff_ESI;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar3 = (undefined4 *)(*(undefined4 **)(unaff_ESI + 4))[1];
  cVar1 = *(char *)((int)puVar3 + 0x41);
  local_8 = *(undefined4 **)(unaff_ESI + 4);
  while (cVar1 == '\0') {
    if (*(byte *)(puVar3 + 3) < in_DL) {
      puVar2 = (undefined4 *)puVar3[2];
      puVar3 = local_8;
    }
    else {
      puVar2 = (undefined4 *)*puVar3;
    }
    local_8 = puVar3;
    puVar3 = puVar2;
    cVar1 = *(char *)((int)puVar2 + 0x41);
  }
  local_c = *(undefined4 **)(unaff_ESI + 4);
  if ((local_8 == local_c) || (in_DL < *(byte *)(local_8 + 3))) {
    ppuVar4 = &local_c;
  }
  else {
    ppuVar4 = &local_8;
  }
  if (*ppuVar4 == local_c) {
    return (undefined4 *)0x0;
  }
  return *ppuVar4 + 4;
}

