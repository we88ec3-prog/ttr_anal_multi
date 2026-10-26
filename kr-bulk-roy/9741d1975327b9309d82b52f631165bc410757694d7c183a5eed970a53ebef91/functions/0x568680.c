
undefined4 * FUN_00568680(int param_1,undefined4 *param_2)

{
  bool bVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  undefined4 local_8;
  
  puVar2 = param_2;
  param_2 = *(undefined4 **)(param_1 + 4);
  bVar1 = true;
  local_8 = 1;
  if (*(char *)((int)param_2[1] + 0x31) == '\0') {
    puVar3 = (undefined4 *)param_2[1];
    do {
      param_2 = puVar3;
      if ((*(int *)(unaff_ESI + 0xc) < (int)param_2[3]) ||
         ((*(int *)(unaff_ESI + 0xc) <= (int)param_2[3] &&
          (*(int *)(unaff_ESI + 0x10) < (int)param_2[4])))) {
        puVar3 = (undefined4 *)*param_2;
        bVar1 = true;
        local_8 = 1;
      }
      else {
        puVar3 = (undefined4 *)param_2[2];
        bVar1 = false;
        local_8 = 0;
      }
    } while (*(char *)((int)puVar3 + 0x31) == '\0');
  }
  if (bVar1) {
    if (param_2 == (undefined4 *)**(int **)(param_1 + 4)) {
      puVar3 = (undefined4 *)FUN_005687b0(&param_1,1,unaff_ESI);
      *puVar2 = *puVar3;
      *(undefined1 *)(puVar2 + 1) = 1;
      return puVar2;
    }
    FUN_00536ea0();
  }
  if ((*(int *)(unaff_ESI + 0xc) <= (int)param_2[3]) &&
     ((*(int *)(unaff_ESI + 0xc) < (int)param_2[3] ||
      (*(int *)(unaff_ESI + 0x10) <= (int)param_2[4])))) {
    if (0xf < *(uint *)(unaff_ESI + 0x28)) {
      FUN_0089120c(*(undefined4 *)(unaff_ESI + 0x14));
    }
    *(undefined4 *)(unaff_ESI + 0x28) = 0xf;
    *(undefined4 *)(unaff_ESI + 0x24) = 0;
    *(undefined1 *)(unaff_ESI + 0x14) = 0;
    FUN_0089120c();
    *puVar2 = param_2;
    *(undefined1 *)(puVar2 + 1) = 0;
    return puVar2;
  }
  puVar3 = (undefined4 *)FUN_005687b0(&param_1,local_8,unaff_ESI);
  *puVar2 = *puVar3;
  *(undefined1 *)(puVar2 + 1) = 1;
  return puVar2;
}

