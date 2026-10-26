
void FUN_00511880(int *param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  undefined1 local_c [4];
  int *local_8;
  
  if (DAT_00fe3718 == 0) {
    FUN_00511a70(unaff_ESI,1);
    return;
  }
  if (param_1 == (int *)*DAT_00fe3714) {
    if (*(int *)(in_EAX + 0xc) < param_1[3]) {
LAB_005118bc:
      FUN_00511a70(unaff_ESI,1);
      return;
    }
  }
  else if (param_1 == DAT_00fe3714) {
    if (*(int *)(DAT_00fe3714[2] + 0xc) < *(int *)(in_EAX + 0xc)) {
      FUN_00511a70(unaff_ESI,0);
      return;
    }
  }
  else {
    if (*(int *)(in_EAX + 0xc) < param_1[3]) {
      local_8 = param_1;
      FUN_0053f8a0();
      if (local_8[3] < *(int *)(in_EAX + 0xc)) {
        if (*(char *)(local_8[2] + 0x15) != '\0') {
          FUN_00511a70(unaff_ESI,0);
          return;
        }
        goto LAB_005118bc;
      }
    }
    if (param_1[3] < *(int *)(in_EAX + 0xc)) {
      local_8 = param_1;
      FUN_0049e6a0();
      if ((local_8 == DAT_00fe3714) || (*(int *)(in_EAX + 0xc) < local_8[3])) {
        if (*(char *)(param_1[2] + 0x15) != '\0') {
          FUN_00511a70(unaff_ESI,0);
          return;
        }
        FUN_00511a70(unaff_ESI,1);
        return;
      }
    }
  }
  puVar1 = (undefined4 *)FUN_005119a0(local_c,in_EAX);
  *unaff_ESI = *puVar1;
  return;
}

