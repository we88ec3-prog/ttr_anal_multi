
void FUN_00846070(void)

{
  int *piVar1;
  void *_Dst;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  int local_8;
  
  puStack_c = &LAB_009114f7;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbGeometry::vftable;
  local_8 = 4;
  in_ECX[0x24] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x26] = 0;
  in_ECX[0x2b] = 0;
  if (in_ECX[0x1f] != in_ECX[0x20]) {
    uVar4 = FUN_00848b00(in_ECX[0x20],in_ECX[0x1f]);
    FUN_00848b60(in_ECX);
    in_ECX[0x20] = uVar4;
  }
  _Dst = (void *)in_ECX[0x27];
  if (_Dst != (void *)in_ECX[0x28]) {
    FID_conflict__memcpy(_Dst,(void *)in_ECX[0x28],0);
    in_ECX[0x28] = _Dst;
  }
  in_ECX[0x2f] = 0;
  if (in_ECX[0x27] != 0) {
    FUN_0089120c(in_ECX[0x27],uVar3);
  }
  in_ECX[0x27] = 0;
  in_ECX[0x28] = 0;
  in_ECX[0x29] = 0;
  if (in_ECX[0x1f] != 0) {
    FUN_00848b60(in_ECX);
    FUN_0089120c(in_ECX[0x1f]);
  }
  in_ECX[0x1f] = 0;
  in_ECX[0x20] = 0;
  in_ECX[0x21] = 0;
  local_8._0_1_ = 1;
  puVar2 = (undefined4 *)in_ECX[0x1e];
  if (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  local_8 = (uint)local_8._1_3_ << 8;
  puVar2 = (undefined4 *)in_ECX[0x1d];
  if (puVar2 != (undefined4 *)0x0) {
    piVar1 = puVar2 + 1;
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)*puVar2)(1);
    }
  }
  local_8 = 0xffffffff;
  *in_ECX = gbObject3d::vftable;
  FUN_00780000();
  ExceptionList = local_10;
  return;
}

