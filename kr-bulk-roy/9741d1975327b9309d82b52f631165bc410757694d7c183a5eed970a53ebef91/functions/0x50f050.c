
undefined4 * FUN_0050f050(undefined4 *param_1,int *param_2)

{
  int in_EAX;
  undefined4 *puVar1;
  
  if (DAT_00fe17c8 == 0) {
LAB_0050f06c:
    FUN_0050f520(param_1,1);
    return param_1;
  }
  if (param_2 == (int *)*DAT_00fe17c4) {
    if (*(int *)(in_EAX + 0xc) < param_2[3]) {
LAB_0050f092:
      FUN_0050f520(param_1,1);
      return param_1;
    }
  }
  else if (param_2 == DAT_00fe17c4) {
    if (*(int *)(DAT_00fe17c4[2] + 0xc) < *(int *)(in_EAX + 0xc)) {
      FUN_0050f520(param_1,0);
      return param_1;
    }
  }
  else {
    if (*(int *)(in_EAX + 0xc) < param_2[3]) {
      FUN_0050fbf0();
      if (param_2[3] < *(int *)(in_EAX + 0xc)) {
        if (*(char *)(param_2[2] + 0x49) != '\0') {
          FUN_0050f520(param_1,0);
          return param_1;
        }
        goto LAB_0050f092;
      }
    }
    if (param_2[3] < *(int *)(in_EAX + 0xc)) {
      FUN_0050eed0();
      if ((param_2 == DAT_00fe17c4) || (*(int *)(in_EAX + 0xc) < param_2[3])) {
        if (*(char *)(param_2[2] + 0x49) != '\0') {
          FUN_0050f520(param_1,0);
          return param_1;
        }
        goto LAB_0050f06c;
      }
    }
  }
  puVar1 = (undefined4 *)FUN_0050f440(in_EAX);
  *param_1 = *puVar1;
  return param_1;
}

