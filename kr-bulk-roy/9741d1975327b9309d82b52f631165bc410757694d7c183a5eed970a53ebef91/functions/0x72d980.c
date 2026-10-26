
undefined4 FUN_0072d980(void)

{
  int *in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  while( true ) {
    if (in_EAX == (int *)0x0) {
      return 0;
    }
    iVar1 = (**(code **)(*in_EAX + 0x10))();
    if (iVar1 != 0) break;
    in_EAX = (int *)in_EAX[4];
  }
                    /* WARNING: Could not recover jumptable at 0x0072d9a7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = (**(code **)(*in_EAX + 0x10))();
  return uVar2;
}

