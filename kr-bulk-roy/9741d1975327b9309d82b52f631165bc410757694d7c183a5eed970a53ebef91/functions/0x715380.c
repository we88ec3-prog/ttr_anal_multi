
void FUN_00715380(undefined4 *param_1)

{
  int iVar1;
  uint uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00912196;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *param_1 = Package::CPackage::vftable;
  local_8 = 2;
  if ((undefined4 *)param_1[0x46] != (undefined4 *)0x0) {
    (*(code *)**(undefined4 **)param_1[0x46])(1,uVar2);
    param_1[0x46] = 0;
  }
  if (param_1[0x4e] != 0) {
    (**(code **)**(undefined4 **)(param_1[0x4e] + 0x24))(0);
    iVar1 = param_1[0x4e];
    if (iVar1 != 0) {
      FUN_007185a0(iVar1);
      FUN_0089120c(iVar1);
      param_1[0x4e] = 0;
    }
  }
  if (0xf < (uint)param_1[0x5b]) {
    FUN_0089120c(param_1[0x56]);
  }
  param_1[0x5b] = 0xf;
  param_1[0x5a] = 0;
  *(undefined1 *)(param_1 + 0x56) = 0;
  if (0xf < (uint)param_1[0x54]) {
    FUN_0089120c(param_1[0x4f]);
  }
  param_1[0x54] = 0xf;
  param_1[0x53] = 0;
  *(undefined1 *)(param_1 + 0x4f) = 0;
  local_8 = 0xffffffff;
  FUN_00717960(param_1);
  ExceptionList = local_10;
  return;
}

