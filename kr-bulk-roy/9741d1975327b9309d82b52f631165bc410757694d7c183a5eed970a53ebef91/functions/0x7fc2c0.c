
void FUN_007fc2c0(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00907588;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = IS3D::CItemNodeSimple::vftable;
  local_8 = 0;
  if (param_1[0xd] != 0) {
    FUN_00523e40(param_1[0xd] + 0xa8,uVar1);
  }
  if ((undefined4 *)param_1[0xd] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0xd])(1);
    param_1[0xd] = 0;
  }
  *param_1 = IS3D::CItemNode::vftable;
  if (0xf < (uint)param_1[7]) {
    FUN_0089120c(param_1[2]);
  }
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  ExceptionList = local_10;
  return;
}

