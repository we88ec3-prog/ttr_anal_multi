
void FUN_005b2b10(int param_1)

{
  int *in_ECX;
  int *piVar1;
  int iVar2;
  
  FUN_005b7750(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf42d9:
    iVar2 = *(int *)in_ECX[0xc0];
    if (((uint)((int *)in_ECX[0xc0])[10] >> 8 & 1) == 0) {
      (**(code **)(iVar2 + 0xd0))();
      return;
    }
    (**(code **)(iVar2 + 0xd4))();
    return;
  case 0xf42da:
    iVar2 = *(int *)in_ECX[0xc1];
    if (((uint)((int *)in_ECX[0xc1])[10] >> 8 & 1) != 0) {
      (**(code **)(iVar2 + 0xd4))();
      return;
    }
    goto LAB_005b2bd2;
  default:
    goto switchD_005b2b38_caseD_f42db;
  case 0xf42e6:
    piVar1 = (int *)in_ECX[199];
    break;
  case 0xf430b:
    piVar1 = (int *)in_ECX[0xc2];
    if (((uint)piVar1[10] >> 8 & 1) != 0) {
      if (((uint)piVar1[10] >> 8 & 1) == 0) {
        return;
      }
      (**(code **)(*piVar1 + 0xd4))();
      return;
    }
    break;
  case 0xf430c:
    (**(code **)(*in_ECX + 0x19c))(9);
    iVar2 = *(int *)in_ECX[0xc3];
LAB_005b2bd2:
    (**(code **)(iVar2 + 0xd0))();
    return;
  case 0xf431a:
    (**(code **)(*(int *)in_ECX[0xc4] + 0xd0))();
    return;
  case 0xf431b:
    (**(code **)(*(int *)in_ECX[0xc5] + 0xd0))();
    return;
  }
  FUN_00596e00(in_ECX,piVar1);
switchD_005b2b38_caseD_f42db:
  return;
}

