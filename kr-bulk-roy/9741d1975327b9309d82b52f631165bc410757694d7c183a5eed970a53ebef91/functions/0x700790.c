
int FUN_00700790(int param_1,undefined4 param_2,int *param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  int iVar4;
  int local_c;
  
  iVar1 = *param_3;
  if (iVar1 < in_EAX / 2) {
    local_c = iVar1 * 2;
    if (local_c < 4) {
      local_c = 4;
    }
  }
  else {
    local_c = in_EAX;
    if (in_EAX <= iVar1) {
      FUN_006f8b60(param_1,param_5);
    }
  }
  if ((uint)(0xfffffffd / (ulonglong)param_4) < local_c + 1U) {
    FUN_006f8b60(param_1,"memory allocation error: block too big");
    *param_3 = local_c;
    return 0;
  }
  iVar1 = *param_3;
  iVar4 = local_c * param_4;
  iVar2 = *(int *)(param_1 + 0x10);
  iVar3 = (**(code **)(iVar2 + 0xc))(*(undefined4 *)(iVar2 + 0x10),param_2,iVar1 * param_4,iVar4);
  if ((iVar3 == 0) && (iVar4 != 0)) {
    iVar3 = FUN_006fdb40(param_1,4);
  }
  *(int *)(iVar2 + 0x44) = *(int *)(iVar2 + 0x44) + (iVar4 - iVar1 * param_4);
  *param_3 = local_c;
  return iVar3;
}

