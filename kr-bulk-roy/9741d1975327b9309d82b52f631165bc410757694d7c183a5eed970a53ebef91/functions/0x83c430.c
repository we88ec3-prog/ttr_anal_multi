
undefined4 * FUN_0083c430(int param_1)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  undefined4 *puVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091cc2b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if (param_1 == 0) {
    return (undefined4 *)0x0;
  }
  puVar3 = (undefined4 *)0x0;
  ExceptionList = &local_10;
  iVar2 = FUN_0083ff20(in_ECX + 0x144,param_1);
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)FUN_00891268(0x194,uVar1);
    local_8 = 0;
    if (puVar3 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      FUN_00843940(puVar3);
      *puVar3 = gbEffectMaterial::vftable;
      puVar3[0x61] = 0;
      puVar3[0x62] = 0;
      puVar3[99] = 0;
      puVar3[0x5b] = param_1;
    }
    local_8 = 0xffffffff;
    FUN_00866d10();
  }
  ExceptionList = local_10;
  return puVar3;
}

