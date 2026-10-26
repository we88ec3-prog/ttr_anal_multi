
void FUN_006f47a0(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(undefined **)(iVar2 + 8) == &DAT_00c0bfd8) {
    return;
  }
  iVar1 = *(int *)(*(undefined **)(iVar2 + 8) + -8);
  if ((iVar1 != 4) && (iVar1 != 3)) {
    return;
  }
  iVar1 = *(int *)(iVar2 + 8);
  if (*(int *)(iVar1 + -8) != 4) {
    iVar1 = FUN_006fb5d0();
    if (iVar1 == 0) {
      iVar2 = 0;
      goto LAB_006f47fc;
    }
    if (*(uint *)(*(int *)(iVar2 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar2 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar1 = *(int *)(iVar2 + 8);
  }
  iVar2 = *(int *)(iVar1 + -0x10) + 0x10;
LAB_006f47fc:
  FID_conflict__wprintf("%s\n",iVar2);
  FID_conflict__wprintf(" - Running \'%s\'\n",param_2);
  *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + -0x10;
  return;
}

