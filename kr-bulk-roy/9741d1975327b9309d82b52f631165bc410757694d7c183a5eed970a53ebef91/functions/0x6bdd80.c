
undefined4 * FUN_006bdd80(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  piVar1 = DAT_00fe317c;
  uVar2 = *param_1;
  DAT_00fe3194 = FUN_006bd720;
  FUN_006f5680();
  puVar3 = *(undefined **)(*piVar1 + 8);
  if ((puVar3 == &DAT_00c0bfd8) || (*(int *)(puVar3 + -8) != 5)) {
    FID_conflict__wprintf("Error UseTable \'%s\'\n",uVar2);
    piVar1 = (int *)(*piVar1 + 8);
    *piVar1 = *piVar1 + -0x10;
  }
  piVar1 = DAT_00fe317c;
  FUN_006f5510(&DAT_00d63dac);
  FUN_006f55b0(FUN_006be030,0);
  FUN_006f57f0(*piVar1);
  *(int *)(*DAT_00fe317c + 8) = *(int *)(*DAT_00fe317c + 8) + -0x10;
  return param_1;
}

