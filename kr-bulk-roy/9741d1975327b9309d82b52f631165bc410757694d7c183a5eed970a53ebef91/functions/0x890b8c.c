
float10 FUN_00890b8c(undefined4 param_1,undefined4 param_2,int param_3,int *param_4)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  undefined8 local_c;
  
  piVar2 = __errno();
  iVar1 = *piVar2;
  piVar2 = __errno();
  *piVar2 = 0;
  fVar3 = (float10)FUN_00898a3f(param_1,param_2);
  local_c = (double)fVar3;
  piVar2 = __errno();
  *param_4 = *piVar2;
  piVar2 = __errno();
  *piVar2 = iVar1;
  for (; 0 < param_3; param_3 = param_3 + -1) {
    local_c = local_c * 10.0;
  }
  if (param_3 < 0) {
    param_3 = -param_3;
    do {
      param_3 = param_3 + -1;
      local_c = local_c / 10.0;
    } while (param_3 != 0);
  }
  return (float10)local_c;
}

