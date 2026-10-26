
undefined4 FUN_008d66e0(int *param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = param_1;
  uVar2 = FUN_008bbed0(*(undefined4 *)(*param_1 + 500),&param_1);
  piVar1[0xb] = (int)param_1;
  FUN_008b8e60(param_1);
  return uVar2;
}

