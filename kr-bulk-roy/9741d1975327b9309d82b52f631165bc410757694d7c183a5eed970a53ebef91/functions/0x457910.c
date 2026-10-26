
void FUN_00457910(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  undefined2 local_a;
  int local_8;
  
  if (*(int *)(param_1 + 0x10) == 0x578) {
    iVar1 = *(int *)(param_1 + 8);
    iVar2 = 0;
    piVar3 = in_ECX + 0x45;
    do {
      if (iVar1 == *(int *)(*piVar3 + 0x20)) {
        local_8 = in_ECX[iVar2 + 0x4f];
        in_ECX[0x55] = local_8;
        goto LAB_004579d7;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 1;
    } while (iVar2 < 5);
    if (iVar1 == *(int *)(in_ECX[0x4c] + 0x20)) {
      if (in_ECX[0x55] + 1 < in_ECX[0x54]) {
        in_ECX[0x55] = in_ECX[0x55] + 1;
      }
    }
    else if (iVar1 == *(int *)(in_ECX[0x4a] + 0x20)) {
      if (0 < in_ECX[0x55]) {
        in_ECX[0x55] = in_ECX[0x55] + -1;
      }
    }
    else {
      if (iVar1 != *(int *)(in_ECX[0x4d] + 0x20)) {
        if (iVar1 == *(int *)(in_ECX[0x4b] + 0x20)) {
          in_ECX[0x55] = ((int)(in_ECX[0x55] - 5U) < 1) - 1 & in_ECX[0x55] - 5U;
          FUN_00458110();
          return;
        }
        if (iVar1 != *(int *)(in_ECX[0x4e] + 0x20)) {
          return;
        }
        (**(code **)(*in_ECX + 0xd4))();
        return;
      }
      if (in_ECX[0x55] + 5 < in_ECX[0x54]) {
        in_ECX[0x55] = in_ECX[0x55] + 5;
      }
      else {
        in_ECX[0x55] = in_ECX[0x54] + -1;
      }
    }
    local_8 = in_ECX[0x55];
LAB_004579d7:
    local_a = 0xf4;
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_a,6);
      return;
    }
  }
  return;
}

