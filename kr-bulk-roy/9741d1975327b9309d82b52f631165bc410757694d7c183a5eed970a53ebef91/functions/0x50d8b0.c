
undefined4 * FUN_0050d8b0(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 *local_8;
  
  puVar5 = (undefined4 *)(*(undefined4 **)(unaff_EDI + 0x14))[1];
  cVar1 = *(char *)((int)puVar5 + 0x69);
  puVar2 = *(undefined4 **)(unaff_EDI + 0x14);
  while (cVar1 == '\0') {
    if (((int)puVar5[3] < unaff_ESI) ||
       (((int)puVar5[3] <= unaff_ESI && ((int)puVar5[4] < (int)param_1)))) {
      puVar3 = (undefined4 *)puVar5[2];
      puVar5 = puVar2;
    }
    else {
      puVar3 = (undefined4 *)*puVar5;
    }
    puVar2 = puVar5;
    puVar5 = puVar3;
    cVar1 = *(char *)((int)puVar3 + 0x69);
  }
  local_8 = *(undefined4 **)(unaff_EDI + 0x14);
  if (((puVar2 == local_8) || (unaff_ESI < (int)puVar2[3])) ||
     ((unaff_ESI <= (int)puVar2[3] && ((int)param_1 < (int)puVar2[4])))) {
    ppuVar4 = &local_8;
  }
  else {
    ppuVar4 = &param_1;
  }
  if (*ppuVar4 == local_8) {
    return (undefined4 *)0x0;
  }
  return *ppuVar4 + 5;
}

