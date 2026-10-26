
/* WARNING: Removing unreachable block (ram,0x0045bb7e) */

void FUN_0045ba90(void)

{
  int iVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009317ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (DAT_00f7fc70 != 0) {
    DAT_00f7fc70 = 0;
  }
  local_8 = 1;
  FUN_0045c650(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_005a9f40(in_ECX + 0x108);
  FUN_0040b670(in_ECX);
  iVar1 = *(int *)(*(int *)(in_ECX + 0xf8) + 0xd8);
  if (iVar1 != 0) {
    FUN_0040acb0(iVar1,0,*(undefined4 *)(in_ECX + 0x108));
  }
  FUN_00749920(*(undefined4 *)(in_ECX + 0xf8));
  FUN_0040b5b0(0);
  if ((DAT_00faaf7c & 1) == 0) {
    DAT_00faaf7c = DAT_00faaf7c | 1;
    local_8._0_1_ = 2;
    FUN_0058d410();
    _atexit((_func_4879 *)&LAB_00bccdc0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_0058e1c0(in_ECX);
  ExceptionList = local_10;
  return;
}

