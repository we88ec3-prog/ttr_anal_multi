
undefined4 * FUN_008204e0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 **ppuVar3;
  undefined4 *puVar4;
  byte in_DL;
  int unaff_ESI;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar4 = (undefined4 *)(*(undefined4 **)(unaff_ESI + 0x14))[1];
  cVar1 = *(char *)((int)puVar4 + 0x25);
  local_8 = *(undefined4 **)(unaff_ESI + 0x14);
  while (cVar1 == '\0') {
    if (*(byte *)(puVar4 + 3) < in_DL) {
      puVar2 = (undefined4 *)puVar4[2];
      puVar4 = local_8;
    }
    else {
      puVar2 = (undefined4 *)*puVar4;
    }
    local_8 = puVar4;
    puVar4 = puVar2;
    cVar1 = *(char *)((int)puVar2 + 0x25);
  }
  if ((local_8 == *(undefined4 **)(unaff_ESI + 0x14)) || (in_DL < *(byte *)(local_8 + 3))) {
    local_c = *(undefined4 **)(unaff_ESI + 0x14);
    ppuVar3 = &local_c;
  }
  else {
    ppuVar3 = &local_8;
  }
  if (*ppuVar3 == *(undefined4 **)(unaff_ESI + 0x14)) {
    return (undefined4 *)0x0;
  }
  return *ppuVar3 + 4;
}

