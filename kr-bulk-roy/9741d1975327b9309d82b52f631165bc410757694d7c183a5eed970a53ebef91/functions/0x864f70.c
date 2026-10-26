
void FUN_00864f70(int *param_1)

{
  int iVar1;
  undefined4 *unaff_ESI;
  undefined4 local_2c;
  undefined4 local_28 [2];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  unaff_ESI[0xb] = 0;
  unaff_ESI[0xc] = 0;
  *unaff_ESI = param_1;
  if (param_1 == (int *)0x0) goto LAB_008650a6;
  (**(code **)(*param_1 + 4))(param_1);
  unaff_ESI[10] = 0;
  unaff_ESI[1] = 0;
  unaff_ESI[2] = 0;
  unaff_ESI[3] = 0;
  unaff_ESI[4] = 1;
  unaff_ESI[5] = 0;
  unaff_ESI[6] = 0x16;
  unaff_ESI[7] = 1;
  iVar1 = (**(code **)(*(int *)*unaff_ESI + 0x28))((int *)*unaff_ESI);
  if (iVar1 == 3) {
    unaff_ESI[8] = 1;
    iVar1 = (**(code **)(*(int *)*unaff_ESI + 0x44))((int *)*unaff_ESI,0,&local_2c);
    if (iVar1 < 0) goto LAB_008650a6;
    unaff_ESI[6] = local_2c;
    unaff_ESI[1] = local_14;
    local_1c = local_20;
    local_14 = local_10;
  }
  else {
    if (iVar1 != 4) {
      if (iVar1 != 5) {
        unaff_ESI[8] = 5;
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
      unaff_ESI[8] = 4;
      iVar1 = (**(code **)(*(int *)*unaff_ESI + 0x44))((int *)*unaff_ESI,0,&local_2c);
      if (-1 < iVar1) {
        unaff_ESI[6] = local_2c;
        unaff_ESI[2] = local_10;
        unaff_ESI[1] = local_14;
        unaff_ESI[7] = local_20;
        __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
        return;
      }
      goto LAB_008650a6;
    }
    unaff_ESI[8] = 3;
    iVar1 = (**(code **)(*(int *)*unaff_ESI + 0x44))((int *)*unaff_ESI,0,local_28);
    if (iVar1 < 0) goto LAB_008650a6;
    unaff_ESI[1] = local_18;
    unaff_ESI[6] = local_28[0];
    unaff_ESI[3] = local_10;
  }
  unaff_ESI[7] = local_1c;
  unaff_ESI[2] = local_14;
LAB_008650a6:
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

