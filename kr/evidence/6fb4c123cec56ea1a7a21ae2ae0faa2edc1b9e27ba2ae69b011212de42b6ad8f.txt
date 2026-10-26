
undefined4 FUN_004ad0a0(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  FUN_006f5680();
  if ((*(undefined **)(*param_1 + 8) != &DAT_00c0bfd8) &&
     (*(int *)(*(undefined **)(*param_1 + 8) + -8) == 6)) {
    iVar1 = FUN_006f5a70(0);
    if (iVar1 == 0) {
      param_1[1] = param_2;
      return 1;
    }
    uVar2 = FUN_006f4830(param_1,param_3);
    return uVar2;
  }
  FID_conflict__wprintf
            ("Error running function \'%s\' : Attempt to call non-function object\n",param_3);
  *(int *)(*param_1 + 8) = *(int *)(*param_1 + 8) + -0x10;
  return 0;
}

