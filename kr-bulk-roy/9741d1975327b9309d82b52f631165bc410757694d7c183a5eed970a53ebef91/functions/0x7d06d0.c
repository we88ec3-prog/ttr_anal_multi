
void FUN_007d06d0(undefined4 *param_1)

{
  undefined4 *puVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puVar1 = param_1;
  puStack_c = &LAB_00914b94;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CSmartNode::vftable;
  local_8 = 1;
  if ((DAT_00fe321c & 1) == 0) {
    DAT_00fe321c = DAT_00fe321c | 1;
    local_8._0_1_ = 2;
    local_8._1_3_ = 0;
    FUN_007d0fb0((int)&param_1 + 3);
    _atexit((_func_4879 *)&LAB_00bd09c0);
    local_8 = CONCAT31(local_8._1_3_,1);
  }
  FUN_007d0e10(uVar2);
  if (0xf < (uint)puVar1[0x3f]) {
    FUN_0089120c(puVar1[0x3a]);
  }
  puVar1[0x3f] = 0xf;
  puVar1[0x3e] = 0;
  *(undefined1 *)(puVar1 + 0x3a) = 0;
  local_8 = 0xffffffff;
  FUN_0077ee00();
  ExceptionList = local_10;
  return;
}

