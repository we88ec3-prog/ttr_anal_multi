
undefined4 FUN_00705ad0(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  char *pcVar3;
  int iVar4;
  double *pdVar5;
  undefined4 *puVar6;
  double local_18;
  undefined4 local_10;
  
  iVar4 = *(int *)(param_1 + 0xc);
  puVar2 = (undefined4 *)(iVar4 + 0x10);
  if (puVar2 < *(undefined4 **)(param_1 + 8)) {
    if ((puVar2 == &DAT_00c0bfc8) || (*(int *)(iVar4 + 0x18) != 5)) {
      if ((*(undefined4 **)(param_1 + 8) <= puVar2) ||
         ((puVar2 == &DAT_00c0bfc8 || (*(int *)(iVar4 + 0x18) == -1)))) goto LAB_00705b0c;
      pcVar3 = (&PTR_DAT_00c0be1c)[*(int *)(iVar4 + 0x18)];
      goto LAB_00705b1a;
    }
  }
  else {
LAB_00705b0c:
    pcVar3 = "no value";
LAB_00705b1a:
    FUN_006f5580(param_1,"%s expected, got %s","table",pcVar3);
    FUN_006f5da0(2);
  }
  FUN_00705970(0);
  puVar2 = *(undefined4 **)(param_1 + 8);
  puVar6 = (undefined4 *)(*(int *)(param_1 + 0xc) + 0x10);
  if (puVar2 <= puVar6) {
    puVar6 = &DAT_00c0bfc8;
  }
  *puVar2 = *puVar6;
  puVar2[1] = puVar6[1];
  puVar2[2] = puVar6[2];
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
  if (*(undefined4 **)(param_1 + 8) <= puVar2) {
    puVar2 = &DAT_00c0bfc8;
  }
  if ((puVar2[2] == 3) || ((puVar2[2] == 4 && (iVar4 = FUN_006f7760(), iVar4 != 0)))) {
    pdVar5 = *(double **)(param_1 + 0xc);
    if (*(double **)(param_1 + 8) <= pdVar5) {
      pdVar5 = (double *)&DAT_00c0bfc8;
    }
    if (*(int *)(pdVar5 + 1) != 3) {
      if ((*(int *)(pdVar5 + 1) != 4) || (iVar4 = FUN_006f7760(), iVar4 == 0)) goto LAB_00705be9;
      local_10 = 3;
      pdVar5 = &local_18;
    }
    if (*pdVar5 == 0.0) {
LAB_00705be9:
      piVar1 = *(int **)(param_1 + 8);
      *piVar1 = param_1;
      piVar1[2] = 8;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 0x10;
      FUN_006f52b0();
      FUN_006f59b0();
      return 0;
    }
  }
  if (((*(int *)(*(int *)(param_1 + 8) + -0x18) != 6) ||
      (*(char *)(*(int *)(*(int *)(param_1 + 8) + -0x20) + 6) == '\0')) &&
     (iVar4 = FUN_006f59b0(), iVar4 != 0)) {
    return 1;
  }
  FUN_006f5f30(param_1,"\'setfenv\' cannot change environment of given object");
  return 1;
}

