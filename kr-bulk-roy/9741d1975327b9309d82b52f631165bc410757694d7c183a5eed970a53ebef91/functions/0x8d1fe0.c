
undefined4
FUN_008d1fe0(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4,char param_5)

{
  undefined4 *puVar1;
  char cVar2;
  undefined4 uVar3;
  
  puVar1 = (undefined4 *)param_1;
  FUN_008d06d0(param_1);
  cVar2 = param_5;
  param_1 = (char *)*puVar1;
  if ((char *)puVar1[2] <= param_1) {
    return 0;
  }
  if (param_5 != '\0') {
    if (*param_1 != '<') {
      return 3;
    }
    param_1 = param_1 + 1;
  }
  uVar3 = FUN_008d17a0(&param_1,param_2,param_3);
  *param_4 = uVar3;
  if (cVar2 != '\0') {
    if ((param_1 < (char *)puVar1[2]) && (*param_1 != '>')) {
      return 3;
    }
    param_1 = param_1 + 1;
  }
  *puVar1 = param_1;
  return 0;
}

