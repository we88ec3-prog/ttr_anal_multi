
void FUN_00520060(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 *in_ECX;
  undefined4 *unaff_ESI;
  int local_20 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090b278;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  uVar1 = *in_ECX;
  FUN_004fcd00(local_20,in_ECX + 1);
  local_8 = 0;
  *in_ECX = *unaff_ESI;
  FUN_004fcdc0(unaff_ESI + 1);
  *unaff_ESI = uVar1;
  FUN_004fcdc0(local_20);
  if (local_20[0] != 0) {
    FUN_0089120c(local_20[0],uVar2);
  }
  ExceptionList = local_10;
  return;
}

