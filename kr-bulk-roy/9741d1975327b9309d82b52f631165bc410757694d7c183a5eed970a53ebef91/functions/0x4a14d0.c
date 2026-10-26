
void FUN_004a14d0(undefined4 *param_1,int *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  iVar1 = *param_2;
  DAT_00fe1774 = param_2;
  DAT_00fe1778 = &DAT_00fe7224;
  if (*(uint *)(*(int *)(iVar1 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar1 + 0x10) + 0x44)) {
    FUN_006fb3a0();
  }
  puVar2 = *(undefined4 **)(iVar1 + 8);
  uVar3 = FUN_006f99a0(iVar1,0,0);
  *puVar2 = uVar3;
  puVar2[2] = 5;
  *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 0x10;
  FUN_006f5790();
  FUN_006f5680();
  if ((*(undefined **)(*param_2 + 8) == &DAT_00c0bfd8) ||
     (*(int *)(*(undefined **)(*param_2 + 8) + -8) != 5)) {
    FID_conflict__wprintf("Error UseTable \'%s\'\n",&DAT_00c06220);
    *(int *)(*param_2 + 8) = *(int *)(*param_2 + 8) + -0x10;
  }
  FUN_006f5510("Rebind");
  FUN_006f55b0(&LAB_004a1e70,0);
  FUN_006f57f0(*param_2);
  *(int *)(*param_2 + 8) = *(int *)(*param_2 + 8) + -0x10;
  *param_1 = &DAT_00c06220;
  return;
}

