
ulonglong * FUN_0052ead0(ulonglong *param_1,int param_2)

{
  int in_EAX;
  ulonglong uVar1;
  ulonglong uVar2;
  
  if (0x7f < param_2) {
    *(undefined4 *)param_1 = 0;
    *(undefined4 *)((int)param_1 + 4) = 0;
    *(undefined4 *)(param_1 + 1) = 0;
    *(undefined4 *)((int)param_1 + 0xc) = 0;
    return param_1;
  }
  if (param_2 == 0x40) {
    uVar1 = *(ulonglong *)(in_EAX + 8);
    uVar2 = 0;
  }
  else if (param_2 < 0x41) {
    uVar1 = __aullshr();
    uVar2 = __allshl();
    uVar1 = uVar1 | uVar2;
    uVar2 = __allshl();
  }
  else {
    uVar1 = __allshl();
    uVar2 = 0;
  }
  *param_1 = uVar1;
  param_1[1] = uVar2;
  return param_1;
}

