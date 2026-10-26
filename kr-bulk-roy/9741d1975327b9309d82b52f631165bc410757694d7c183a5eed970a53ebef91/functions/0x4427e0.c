
void FUN_004427e0(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int in_EDX;
  int local_8;
  
  local_8 = 0;
  piVar1 = (int *)(in_EDX + 0x10c);
  do {
    if ((piVar1[-1] < 0) || (*piVar1 < 0)) goto LAB_00442807;
    local_8 = local_8 + 1;
    piVar1 = piVar1 + 8;
  } while (local_8 < 2);
  local_8 = -1;
LAB_00442807:
  FUN_00442830(in_EDX,&local_8,param_1,param_2);
  return;
}

