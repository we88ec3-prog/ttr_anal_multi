
bool FUN_008629e0(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int unaff_ESI;
  undefined4 local_8;
  
  if (unaff_ESI != 0) {
    if (*(int *)(unaff_ESI + 0x40) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = FUN_00857160(*(int *)(unaff_ESI + 0x40));
    }
    iVar1 = *(int *)(unaff_ESI + 0x4c);
    iVar2 = *(int *)(unaff_ESI + 0x48);
    *param_3 = iVar4;
    iVar4 = (**(code **)(*param_1 + 0x68))(param_1,((iVar1 - iVar2) / 0x18) * iVar4,8,0,1,param_2,0)
    ;
    if (-1 < iVar4) {
      local_8 = 0;
      iVar4 = (**(code **)(*(int *)*param_2 + 0x2c))((int *)*param_2,0,0,&local_8,0);
      if (-1 < iVar4) {
        iVar4 = FUN_00862570(local_8,0);
        piVar3 = (int *)*param_2;
        if (iVar4 != 0) {
          iVar4 = (**(code **)(*piVar3 + 0x30))(piVar3);
          return -1 < iVar4;
        }
        (**(code **)(*piVar3 + 0x30))(piVar3);
      }
    }
  }
  return false;
}

