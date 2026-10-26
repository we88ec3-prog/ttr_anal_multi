
void FUN_00574940(undefined4 *param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  undefined4 uVar3;
  uint local_30 [4];
  undefined4 local_20;
  uint local_1c;
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00916b68;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar3 = 0;
  local_1c = 0xf;
  local_20 = 0;
  local_30[0] = local_30[0] & 0xffffff00;
  local_14 = uVar1;
  FUN_00403040(param_2,0,0xffffffff);
  local_8 = 0;
  *unaff_ESI = *param_1;
  unaff_ESI[6] = 0xf;
  unaff_ESI[5] = 0;
  *(undefined1 *)(unaff_ESI + 1) = 0;
  FUN_00402bb0(local_30);
  uVar2 = extraout_EDX;
  if (0xf < local_1c) {
    FUN_0089120c(local_30[0],uVar1);
    uVar2 = extraout_EDX_00;
  }
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc,uVar2,uVar3);
  return;
}

