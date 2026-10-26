
void FUN_00511da0(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b370;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = CCashShopTable::vftable;
  local_8 = 1;
  FUN_00823850(uVar2);
  piVar1 = in_ECX + 1;
  FUN_00512ef0(piVar1);
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_005540c0(*(undefined4 *)in_ECX[6],(undefined4 *)in_ECX[6]);
  FUN_0089120c(in_ECX[6]);
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1);
  }
  *piVar1 = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  ExceptionList = local_10;
  return;
}

