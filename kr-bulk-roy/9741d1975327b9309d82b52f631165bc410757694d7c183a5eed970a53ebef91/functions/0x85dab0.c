
/* WARNING: Removing unreachable block (ram,0x0085dbf8) */
/* WARNING: Removing unreachable block (ram,0x0085dc06) */
/* WARNING: Removing unreachable block (ram,0x0085dc70) */
/* WARNING: Removing unreachable block (ram,0x0085dc57) */
/* WARNING: Removing unreachable block (ram,0x0085dca1) */

void FUN_0085dab0(int *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *in_ECX;
  float local_70;
  float local_6c;
  undefined4 local_60;
  float local_5c;
  undefined4 local_58;
  float local_4c;
  undefined4 local_48;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00918088;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  (**(code **)(*in_ECX + 0x110))();
  local_8 = 0;
  iVar3 = FUN_008714b0();
  if (iVar3 != 0) {
    local_60 = FUN_00858c00();
  }
  local_5c = 0.0;
  local_4c = 0.0;
  FUN_00871670();
  FUN_00871670();
  iVar3 = FUN_008718f0();
  if (iVar3 != 0) {
    local_5c = local_70;
    local_4c = local_6c;
  }
  local_48 = (undefined4)(longlong)ROUND(local_5c);
  local_58 = (undefined4)(longlong)ROUND(local_4c);
  iVar3 = FUN_008718f0();
  if (iVar3 == 0) {
    iVar3 = FUN_00865740(0,local_48,local_58,local_60,0,0);
  }
  else {
    iVar3 = FUN_008657c0(0x3f800000,0x3f800000,local_60,0,0,0);
  }
  if (((iVar3 == 0) && (param_1 != (int *)0x0)) && (piVar1 = (int *)*param_1, piVar1 != (int *)0x0))
  {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar2 ^ (uint)&stack0xfffffffc);
  return;
}

