
void FUN_00764520(int *param_1,int param_2,int *param_3)

{
  char cVar1;
  undefined4 ***pppuVar2;
  int iVar3;
  int in_ECX;
  int in_EDX;
  undefined4 local_30;
  int *local_2c;
  int *local_28;
  undefined4 **local_24 [4];
  undefined4 local_14;
  uint local_10;
  uint local_8;
  
  local_8 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  local_2c = param_1;
  local_28 = param_3;
  if (in_EDX != 0) {
    FUN_004297b0();
    pppuVar2 = (undefined4 ***)local_24[0];
    if (local_10 < 0x10) {
      pppuVar2 = local_24;
    }
    iVar3 = FUN_0072e2e0(pppuVar2);
    if (0xf < local_10) {
      FUN_0089120c(local_24[0]);
    }
    local_10 = 0xf;
    local_14 = 0;
    local_24[0] = (undefined4 **)((uint)local_24[0] & 0xffffff00);
    if (iVar3 != 0) {
      local_30 = 0;
      FUN_00429860(&local_30);
      if (param_3 == (int *)0x0) {
        param_3 = (int *)(**(code **)(*local_2c + 0x2c))(local_30);
        local_28 = param_3;
        if (param_3 == (int *)0x0) goto LAB_00764623;
      }
      param_3[6] = (int)param_3;
      cVar1 = FUN_00776c60();
      if (cVar1 != '\0') {
        FUN_0044e6c0(param_2,param_3);
        param_3[8] = param_2;
        if (in_ECX != 0) {
          FUN_00443d10();
        }
        __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
        return;
      }
      goto LAB_00764623;
    }
  }
  if (param_3 != (int *)0x0) {
    (**(code **)(*param_3 + 0x1c))(1);
  }
LAB_00764623:
  __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc);
  return;
}

