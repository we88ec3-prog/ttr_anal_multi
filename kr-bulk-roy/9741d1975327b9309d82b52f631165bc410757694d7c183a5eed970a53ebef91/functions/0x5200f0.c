
void FUN_005200f0(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_24;
  int local_20 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908ab8;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  iVar1 = (param_2 - param_1) / 0x14;
  iVar3 = iVar1 / 2;
  if (0 < iVar3) {
    iVar4 = param_1 + iVar3 * 0x14;
    do {
      local_24 = *(undefined4 *)(iVar4 + -0x14);
      iVar3 = iVar3 + -1;
      FUN_004fcd00(local_20,iVar4 + -0x10);
      local_8 = 0;
      FUN_005203e0(param_1,iVar1,&local_24,param_3,uVar2);
      local_8 = 0xffffffff;
      if (local_20[0] != 0) {
        FUN_0089120c(local_20[0]);
      }
      iVar4 = iVar4 + -0x14;
    } while (0 < iVar3);
  }
  ExceptionList = local_10;
  return;
}

