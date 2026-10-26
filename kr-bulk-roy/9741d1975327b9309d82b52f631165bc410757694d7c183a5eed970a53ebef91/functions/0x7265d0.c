
void FUN_007265d0(undefined4 param_1,undefined4 param_2)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  int iStack0000000c;
  int local_1c;
  int local_18 [3];
  int local_c;
  int local_8;
  
  iVar2 = *in_EAX;
  do {
    if (iVar2 == 0) {
      local_c = 0;
      piVar1 = &local_c;
    }
    else {
      local_8 = *(int *)(iVar2 + 0x10);
      piVar1 = &local_8;
    }
    if (*piVar1 == 0) {
      if (iVar2 != 0) {
        iStack0000000c = *(int *)(iVar2 + 0x18);
        if (iStack0000000c != 0) goto LAB_0072665e;
        if (iVar2 == 0) {
          local_1c = 0;
          piVar1 = &local_1c;
          goto LAB_0072664a;
        }
        do {
          if (*(int *)(iVar2 + 0x18) != 0) {
            iStack0000000c = *(int *)(iVar2 + 0x18);
            goto LAB_00726657;
          }
          local_18[0] = *(int *)(iVar2 + 4);
          piVar1 = local_18;
LAB_0072664a:
          iVar2 = *piVar1;
        } while (iVar2 != 0);
      }
      iStack0000000c = 0;
LAB_00726657:
      if (iStack0000000c == 0) {
        return;
      }
    }
    else if (iVar2 == 0) {
      local_18[1] = 0;
      iStack0000000c = 0;
    }
    else {
      iStack0000000c = *(int *)(iVar2 + 0x10);
      local_18[2] = iStack0000000c;
    }
LAB_0072665e:
    iVar2 = iStack0000000c;
    FUN_0071d780(param_2,&stack0x0000000c);
  } while( true );
}

