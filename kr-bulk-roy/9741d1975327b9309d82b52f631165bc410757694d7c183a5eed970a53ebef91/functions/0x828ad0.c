
undefined4 * FUN_00828ad0(void)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  int in_EDX;
  short unaff_SI;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puVar3 = (undefined4 *)(*(undefined4 **)(in_EDX + 4))[1];
  cVar1 = *(char *)((int)puVar3 + 0x95);
  local_8 = *(undefined4 **)(in_EDX + 4);
  while (cVar1 == '\0') {
    if (*(short *)(puVar3 + 3) < unaff_SI) {
      puVar2 = (undefined4 *)puVar3[2];
      puVar3 = local_8;
    }
    else {
      puVar2 = (undefined4 *)*puVar3;
    }
    local_8 = puVar3;
    puVar3 = puVar2;
    cVar1 = *(char *)((int)puVar2 + 0x95);
  }
  local_c = *(undefined4 **)(in_EDX + 4);
  if ((local_8 == local_c) || (unaff_SI < *(short *)(local_8 + 3))) {
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

