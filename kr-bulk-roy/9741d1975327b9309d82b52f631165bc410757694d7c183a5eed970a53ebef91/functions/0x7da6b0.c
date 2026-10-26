
void FUN_007da6b0(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 in_ECX;
  undefined8 uVar4;
  uint uVar5;
  undefined4 local_30;
  uint local_1c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_009284c8;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  puVar3 = param_2;
  if (0xf < (uint)param_2[5]) {
    puVar3 = (undefined4 *)*param_2;
  }
  uVar5 = uVar1;
  iVar2 = FUN_007da880(puVar3,param_2[4]);
  puVar3 = param_2;
  if (0xf < (uint)param_2[5]) {
    puVar3 = (undefined4 *)*param_2;
  }
  uVar4 = FUN_007da800(in_ECX,puVar3,param_2[4]);
  while( true ) {
    if (((int)uVar4 == -1) && (iVar2 == -1)) break;
    FUN_007da7d0((int)uVar4 - iVar2);
    local_8 = 0;
    FUN_00556090(uVar5);
    local_8 = 0xffffffff;
    if (0xf < local_1c) {
      FUN_0089120c(local_30);
    }
    puVar3 = param_2;
    if (0xf < (uint)param_2[5]) {
      puVar3 = (undefined4 *)*param_2;
    }
    iVar2 = FUN_007da880(puVar3,param_2[4]);
    puVar3 = param_2;
    if (0xf < (uint)param_2[5]) {
      puVar3 = (undefined4 *)*param_2;
    }
    uVar4 = FUN_007da800(in_ECX,puVar3,param_2[4]);
  }
  ExceptionList = local_10;
  __security_check_cookie(uVar1 ^ (uint)&stack0xfffffffc,(int)((ulonglong)uVar4 >> 0x20),param_1);
  return;
}

