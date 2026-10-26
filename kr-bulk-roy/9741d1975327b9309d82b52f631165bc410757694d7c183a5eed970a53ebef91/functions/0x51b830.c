
void FUN_0051b830(int *param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  undefined1 local_c [4];
  int *local_8;
  
  if (DAT_00fe3708 == 0) {
    FUN_0051b950(unaff_ESI,1);
    return;
  }
  if (param_1 == (int *)*DAT_00fe3704) {
    if (*(int *)(in_EAX + 0xc) < param_1[3]) {
LAB_0051b86c:
      FUN_0051b950(unaff_ESI,1);
      return;
    }
  }
  else if (param_1 == DAT_00fe3704) {
    if (*(int *)(DAT_00fe3704[2] + 0xc) < *(int *)(in_EAX + 0xc)) {
      FUN_0051b950(unaff_ESI,0);
      return;
    }
  }
  else {
    if (*(int *)(in_EAX + 0xc) < param_1[3]) {
      local_8 = param_1;
      FUN_00532f90();
      if (local_8[3] < *(int *)(in_EAX + 0xc)) {
        if (*(char *)(local_8[2] + 0x55) != '\0') {
          FUN_0051b950(unaff_ESI,0);
          return;
        }
        goto LAB_0051b86c;
      }
    }
    if (param_1[3] < *(int *)(in_EAX + 0xc)) {
      local_8 = param_1;
      FUN_0051b140();
      if ((local_8 == DAT_00fe3704) || (*(int *)(in_EAX + 0xc) < local_8[3])) {
        if (*(char *)(param_1[2] + 0x55) != '\0') {
          FUN_0051b950(unaff_ESI,0);
          return;
        }
        FUN_0051b950(unaff_ESI,1);
        return;
      }
    }
  }
  puVar1 = (undefined4 *)FUN_0051b750(local_c,in_EAX);
  *unaff_ESI = *puVar1;
  return;
}

