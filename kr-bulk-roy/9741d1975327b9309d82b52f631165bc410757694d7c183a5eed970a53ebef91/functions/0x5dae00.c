
void FUN_005dae00(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *unaff_ESI;
  undefined1 auStack_30 [8];
  int local_28;
  int local_20;
  uint local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093f16e;
  local_14 = ExceptionList;
  local_1c = DAT_00d61f20 ^ (uint)auStack_30;
  ExceptionList = &local_14;
  if ((DAT_00f94390 & 1) == 0) {
    DAT_00f94390 = DAT_00f94390 | 1;
    local_c = 0;
    FUN_004e1590(DAT_00d61f20 ^ (uint)&stack0xffffffc8);
    _atexit((_func_4879 *)&LAB_00bccc80);
  }
  local_c = 0xffffffff;
  piVar3 = (int *)(unaff_ESI[0xa8] * 0x10 + DAT_00f942fc);
  iVar1 = *piVar3;
  local_28 = piVar3[1];
  iVar2 = piVar3[2];
  local_20 = piVar3[3];
  if (((unaff_ESI[0xae] != iVar1) || (unaff_ESI[0xb0] != iVar2)) || (unaff_ESI[0xaf] != local_28)) {
    if ((iVar1 == 0) && (iVar2 == 0)) {
      FUN_005d7240(0xffffffff,0xffffffff,0,0);
      (**(code **)(*(int *)unaff_ESI[0xa6] + 0x94))(0);
    }
    else {
      FUN_005d7240(iVar1,iVar2,0,0);
      FUN_005d7af0(local_28);
    }
    unaff_ESI[0xae] = iVar1;
    unaff_ESI[0xaf] = local_28;
    unaff_ESI[0xb0] = iVar2;
    unaff_ESI[0xb1] = local_20;
    (**(code **)(*unaff_ESI + 200))();
  }
  FUN_005daf60(unaff_ESI);
  FUN_005db3a0(unaff_ESI);
  uVar4 = unaff_ESI[10];
  if (((uVar4 >> 7 & 1) == 0) || (unaff_ESI[0x97] == 0)) {
    if ((uVar4 & 8) == 0) goto LAB_005daf40;
    uVar4 = uVar4 ^ 8;
  }
  else {
    uVar4 = uVar4 | 8;
  }
  unaff_ESI[10] = uVar4;
LAB_005daf40:
  ExceptionList = local_14;
  __security_check_cookie(local_1c ^ (uint)auStack_30);
  return;
}

