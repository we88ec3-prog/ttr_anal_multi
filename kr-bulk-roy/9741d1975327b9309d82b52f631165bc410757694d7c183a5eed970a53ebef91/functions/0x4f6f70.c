
undefined4 * FUN_004f6f70(void)

{
  char cVar1;
  undefined4 **ppuVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  char in_DL;
  int unaff_ESI;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(unaff_ESI + 0xa4))[1];
  cVar1 = *(char *)((int)puVar4 + 0x2d);
  local_8 = *(undefined4 **)(unaff_ESI + 0xa4);
  while (cVar1 == '\0') {
    if (*(char *)(puVar4 + 3) < in_DL) {
      puVar3 = (undefined4 *)puVar4[2];
      puVar4 = local_8;
    }
    else {
      puVar3 = (undefined4 *)*puVar4;
    }
    local_8 = puVar4;
    puVar4 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x2d);
  }
  if ((local_8 == *(undefined4 **)(unaff_ESI + 0xa4)) || (in_DL < *(char *)(local_8 + 3))) {
    local_c = *(undefined4 **)(unaff_ESI + 0xa4);
    ppuVar2 = &local_c;
  }
  else {
    ppuVar2 = &local_8;
  }
  puVar4 = *ppuVar2;
  if (puVar4 != *(undefined4 **)(unaff_ESI + 0xa4)) {
    puVar3 = puVar4 + 4;
    if (0xf < (uint)puVar4[9]) {
      puVar3 = (undefined4 *)*puVar3;
    }
    return puVar3;
  }
  return (undefined4 *)0x0;
}

