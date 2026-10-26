
undefined4 FUN_006f4830(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 8);
  if (*(int *)(iVar1 + -8) != 4) {
    iVar1 = FUN_006fb5d0();
    if (iVar1 == 0) {
      iVar2 = 0;
      goto LAB_006f4872;
    }
    if (*(uint *)(*(int *)(iVar2 + 0x10) + 0x40) <= *(uint *)(*(int *)(iVar2 + 0x10) + 0x44)) {
      FUN_006fb3a0();
    }
    iVar1 = *(int *)(iVar2 + 8);
  }
  iVar2 = *(int *)(iVar1 + -0x10) + 0x10;
LAB_006f4872:
  FID_conflict__wprintf("Error running function \'%s\' : %s\n",param_2,iVar2);
  *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + -0x10;
  return 0;
}

