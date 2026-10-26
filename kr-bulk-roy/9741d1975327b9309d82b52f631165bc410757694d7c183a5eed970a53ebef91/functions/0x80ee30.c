
undefined4 FUN_0080ee30(int *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x0080ee44. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(*param_1 + 0x30))();
  return uVar1;
}

