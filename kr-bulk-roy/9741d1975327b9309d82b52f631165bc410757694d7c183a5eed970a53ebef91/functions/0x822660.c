
int FUN_00822660(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 **ppuVar4;
  undefined4 *puVar5;
  int unaff_EDI;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = *(undefined4 **)(unaff_EDI + 0x18);
  iVar2 = 8;
  while( true ) {
    cVar1 = *(char *)((int)local_c[1] + 0x19);
    local_8 = local_c;
    puVar5 = (undefined4 *)local_c[1];
    while (cVar1 == '\0') {
      if ((int)puVar5[3] < iVar2) {
        puVar3 = (undefined4 *)puVar5[2];
        puVar5 = local_8;
      }
      else {
        puVar3 = (undefined4 *)*puVar5;
      }
      local_8 = puVar5;
      puVar5 = puVar3;
      cVar1 = *(char *)((int)puVar3 + 0x19);
    }
    if ((local_8 == local_c) || (iVar2 < (int)local_8[3])) {
      ppuVar4 = &local_c;
    }
    else {
      ppuVar4 = &local_8;
    }
    if ((*ppuVar4 != local_c) && ((int)(*ppuVar4)[4] <= param_1)) break;
    iVar2 = iVar2 + -1;
    if (iVar2 < 1) {
      return 0;
    }
  }
  return iVar2;
}

