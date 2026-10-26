
undefined4 FUN_0070bab0(int param_1)

{
  double dVar1;
  char *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  double *pdVar5;
  double local_28;
  double local_18;
  undefined4 local_10;
  
  local_28 = 0.0;
  puVar3 = *(undefined4 **)(param_1 + 0xc);
  if (puVar3 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar3 != &DAT_00c0bfc8) && (puVar3[2] == 5)) goto LAB_0070bb1d;
    if ((*(undefined4 **)(param_1 + 8) <= puVar3) ||
       ((puVar3 == &DAT_00c0bfc8 || (puVar3[2] == -1)))) goto LAB_0070baef;
    pcVar2 = (&PTR_DAT_00c0be1c)[puVar3[2]];
  }
  else {
LAB_0070baef:
    pcVar2 = "no value";
  }
  FUN_006f5580(param_1,"%s expected, got %s","table",pcVar2);
  FUN_006f5da0(1);
LAB_0070bb1d:
  *(undefined4 *)(*(int *)(param_1 + 8) + 8) = 0;
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  do {
    do {
      puVar3 = *(undefined4 **)(param_1 + 0xc);
      if (*(undefined4 **)(param_1 + 8) <= puVar3) {
        puVar3 = &DAT_00c0bfc8;
      }
      iVar4 = FUN_006f9270(*puVar3);
      if (iVar4 == 0) {
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -0x10;
        pdVar5 = *(double **)(param_1 + 8);
        *pdVar5 = local_28;
        *(undefined4 *)(pdVar5 + 1) = 3;
        *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
        return 1;
      }
      iVar4 = *(int *)(param_1 + 8);
      *(int *)(param_1 + 8) = iVar4;
      pdVar5 = (double *)(iVar4 + -0x10);
    } while ((pdVar5 == (double *)&DAT_00c0bfc8) || (*(int *)(iVar4 + -8) != 3));
    if (*(int *)(iVar4 + -8) == 3) {
LAB_0070bb9e:
      dVar1 = *pdVar5;
    }
    else {
      if ((*(int *)(iVar4 + -8) == 4) && (iVar4 = FUN_006f7760(), iVar4 != 0)) {
        local_10 = 3;
        pdVar5 = &local_18;
        goto LAB_0070bb9e;
      }
      dVar1 = 0.0;
    }
    if (local_28 < dVar1) {
      local_28 = dVar1;
    }
  } while( true );
}

