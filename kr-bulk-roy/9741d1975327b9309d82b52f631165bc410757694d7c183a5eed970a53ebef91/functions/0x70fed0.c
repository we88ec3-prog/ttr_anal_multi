
void FUN_0070fed0(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int local_48 [2];
  int local_40;
  undefined4 local_28 [2];
  int local_20;
  undefined4 local_18;
  undefined4 local_14;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(param_2 + 8) < 6) || (9 < *(int *)(param_2 + 8))) {
                    /* WARNING: Subroutine does not return */
    FUN_006ff130(param_1,"syntax error",*(undefined4 *)(param_1 + 0x10));
  }
  if (*(int *)(param_1 + 0x10) == 0x2c) {
    iVar2 = FUN_0070d800();
    if (iVar2 == 0) goto LAB_0070ff66;
    local_48[0] = param_2;
    FUN_0070f580(param_1);
    if (local_40 == 6) {
      FUN_0070fe40();
    }
    if ((int)(200 - (uint)*(ushort *)(*(int *)(param_1 + 0x34) + 0x34)) < param_3) {
      param_1 = *(int *)(param_1 + 0x30);
      param_3 = FUN_0070d7c0();
    }
    FUN_0070fed0(param_1,local_48,param_3 + 1);
  }
  else {
LAB_0070ff66:
    FUN_0070d850();
    iVar2 = FUN_0070f1c0(param_1);
    if (iVar2 == param_3) {
      FUN_00712250();
      goto LAB_0070ffc5;
    }
    FUN_0070dda0(param_3,iVar2);
    if (param_3 < iVar2) {
      piVar1 = (int *)(*(int *)(param_1 + 0x30) + 0x24);
      *piVar1 = *piVar1 + (param_3 - iVar2);
    }
  }
  local_20 = *(int *)(*(int *)(param_1 + 0x30) + 0x24) + -1;
  local_18 = 0xffffffff;
  local_14 = 0xffffffff;
  local_28[0] = 0xc;
LAB_0070ffc5:
  FUN_00712880(local_28);
  __security_check_cookie(local_c ^ (uint)&stack0xfffffffc);
  return;
}

