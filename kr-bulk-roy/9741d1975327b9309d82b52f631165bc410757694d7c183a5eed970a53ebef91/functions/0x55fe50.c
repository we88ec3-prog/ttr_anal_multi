
undefined4 * FUN_0055fe50(undefined4 *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  piVar1 = DAT_00fe2764;
  uVar2 = *param_1;
  DAT_00fe276c = &LAB_0055f950;
  FUN_006f5680();
  puVar3 = *(undefined **)(*piVar1 + 8);
  if ((puVar3 == &DAT_00c0bfd8) || (*(int *)(puVar3 + -8) != 5)) {
    FID_conflict__wprintf("Error UseTable \'%s\'\n",uVar2);
    piVar1 = (int *)(*piVar1 + 8);
    *piVar1 = *piVar1 + -0x10;
  }
  piVar1 = DAT_00fe2764;
  FUN_006f5510(s_OnClose_00d6a5bc);
  FUN_006f55b0(FUN_0055ff10,0);
  FUN_006f57f0(*piVar1);
  *(int *)(*DAT_00fe2764 + 8) = *(int *)(*DAT_00fe2764 + 8) + -0x10;
  return param_1;
}

