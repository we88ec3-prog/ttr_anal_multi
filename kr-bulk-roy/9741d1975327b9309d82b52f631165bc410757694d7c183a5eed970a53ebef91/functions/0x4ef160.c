
undefined4 FUN_004ef160(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint local_14;
  int *local_10;
  uint local_8;
  
  FUN_004d8460();
  FUN_00542210();
  while( true ) {
    if (local_8 == local_14) {
      return 0;
    }
    if (local_10 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *local_10;
    }
    uVar2 = local_8 >> 2;
    if (*(uint *)(iVar3 + 8) <= uVar2) {
      uVar2 = uVar2 - *(uint *)(iVar3 + 8);
    }
    piVar1 = *(int **)(*(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + (local_8 & 3) * 4);
    if ((*piVar1 == param_1) && (piVar1[1] == param_2)) break;
    local_8 = local_8 + 1;
  }
  if (local_10 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *local_10;
  }
  uVar2 = local_8 >> 2;
  if (*(uint *)(iVar3 + 8) <= uVar2) {
    uVar2 = uVar2 - *(uint *)(iVar3 + 8);
  }
  return *(undefined4 *)(*(int *)(*(int *)(iVar3 + 4) + uVar2 * 4) + (local_8 & 3) * 4);
}

