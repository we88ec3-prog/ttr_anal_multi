
void FUN_00717960(undefined4 *param_1)

{
  uint uVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091214f;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = Package::DirectoryNode::vftable;
  local_8 = 1;
  if ((undefined4 *)param_1[0x46] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x46])(1,uVar1);
    param_1[0x46] = 0;
  }
  local_8 = CONCAT31(local_8._1_3_,2);
  FUN_0057ffd0(*(undefined4 *)param_1[0x49],(undefined4 *)param_1[0x49]);
  FUN_0089120c(param_1[0x49]);
  local_8 = 0xffffffff;
  FUN_00717050();
  ExceptionList = local_10;
  return;
}

