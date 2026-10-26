
int FUN_008baf40(int param_1,int param_2,int param_3,int param_4,int param_5,undefined4 *param_6)

{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  if (((-1 < param_3) && (-1 < param_4)) && (-1 < param_2)) {
    if ((param_4 != 0) && (param_2 != 0)) {
      if ((int)(0x7fffffff / (longlong)param_2) < param_4) {
        *param_6 = 10;
        return param_5;
      }
      if (param_3 == 0) {
        iVar1 = FUN_008baee0(param_1,param_2 * param_4,&local_8);
      }
      else {
        iVar1 = (**(code **)(param_1 + 0xc))(param_1,param_2 * param_3,param_2 * param_4,param_5);
        if (iVar1 == 0) {
          *param_6 = 0x40;
          return param_5;
        }
      }
      *param_6 = local_8;
      return iVar1;
    }
    FUN_008b9f80(param_1,param_5);
    *param_6 = local_8;
    return 0;
  }
  *param_6 = 6;
  return param_5;
}

