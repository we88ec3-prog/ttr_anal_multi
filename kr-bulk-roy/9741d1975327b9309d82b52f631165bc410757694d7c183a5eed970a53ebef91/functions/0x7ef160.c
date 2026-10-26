
void FUN_007ef160(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00920726;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CItemBaseNodeSimple::vftable;
  param_1[0x10] = IS3D::CItemBaseNodeSimple::vftable;
  uStack_7 = 0;
  if ((DAT_00fd94d8 & 1) == 0) {
    DAT_00fd94d8 = DAT_00fd94d8 | 1;
    local_8 = 9;
    uStack_7 = 0;
    FUN_007b5430(uVar1);
    _atexit((_func_4879 *)&LAB_00bce660);
  }
  local_8 = 8;
  FUN_007b5f30(param_1 + 0x10);
  FUN_007f0500();
  FUN_007f0bd0(*(undefined4 *)(param_1[0x44] + 4));
  *(undefined4 *)(param_1[0x44] + 4) = param_1[0x44];
  *(undefined4 *)param_1[0x44] = param_1[0x44];
  *(undefined4 *)(param_1[0x44] + 8) = param_1[0x44];
  param_1[0x45] = 0;
  _local_8 = CONCAT31(uStack_7,10);
  FUN_007f0c30(*(undefined4 *)param_1[0x44],(undefined4 *)param_1[0x44]);
  FUN_0089120c(param_1[0x44]);
  if (0xf < (uint)param_1[0x41]) {
    FUN_0089120c(param_1[0x3c]);
  }
  param_1[0x41] = 0xf;
  param_1[0x40] = 0;
  *(undefined1 *)(param_1 + 0x3c) = 0;
  if (0xf < (uint)param_1[0x39]) {
    FUN_0089120c(param_1[0x34]);
  }
  param_1[0x39] = 0xf;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  if (0xf < (uint)param_1[0x32]) {
    FUN_0089120c(param_1[0x2d]);
  }
  param_1[0x32] = 0xf;
  param_1[0x31] = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  if (0xf < (uint)param_1[0x2b]) {
    FUN_0089120c(param_1[0x26]);
  }
  param_1[0x2b] = 0xf;
  param_1[0x2a] = 0;
  *(undefined1 *)(param_1 + 0x26) = 0;
  if (0xf < (uint)param_1[0x24]) {
    FUN_0089120c(param_1[0x1f]);
  }
  param_1[0x24] = 0xf;
  param_1[0x23] = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  if (0xf < (uint)param_1[0x1d]) {
    FUN_0089120c(param_1[0x18]);
  }
  param_1[0x1d] = 0xf;
  param_1[0x1c] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  if (0xf < (uint)param_1[0x16]) {
    FUN_0089120c(param_1[0x11]);
  }
  param_1[0x16] = 0xf;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  *param_1 = IS3D::CItemBaseNode::vftable;
  if (param_1[10] != 0) {
    FUN_00440a80();
    FUN_0089120c(param_1[10]);
  }
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  ExceptionList = local_10;
  return;
}

