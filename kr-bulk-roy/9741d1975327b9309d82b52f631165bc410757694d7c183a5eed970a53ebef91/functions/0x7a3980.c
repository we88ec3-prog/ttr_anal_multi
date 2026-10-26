
undefined1 * FUN_007a3980(undefined1 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  char cVar3;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911a48;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  FUN_00403040(param_2,0,0xffffffff);
  local_8 = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar1 = param_3[1];
  uVar2 = *param_3;
  if (iVar1 != 0) {
    cVar3 = FUN_0047c250(uVar4);
    if (cVar3 != '\0') {
      FUN_007a31c0(uVar2,iVar1);
    }
  }
  ExceptionList = local_10;
  return param_1;
}

