
undefined4 * FUN_00567140(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  piVar1 = DAT_00fe2774;
  uVar2 = *param_1;
  DAT_00fe27f0 = FUN_005636f0;
  FUN_006f5680();
  puVar3 = *(undefined **)(*piVar1 + 8);
  if ((puVar3 == &DAT_00c0bfd8) || (*(int *)(puVar3 + -8) != 5)) {
    FID_conflict__wprintf("Error UseTable \'%s\'\n",uVar2);
    piVar1 = (int *)(*piVar1 + 8);
    *piVar1 = *piVar1 + -0x10;
  }
  piVar1 = DAT_00fe2774;
  FUN_006f5510(s_SpeedObject_00d6a3f8);
  FUN_006f55b0(FUN_00569520,0);
  FUN_006f57f0(*piVar1);
  *(int *)(*DAT_00fe2774 + 8) = *(int *)(*DAT_00fe2774 + 8) + -0x10;
  return param_1;
}

