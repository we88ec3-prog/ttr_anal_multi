
void FUN_0087caa0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined1 auStack_114 [4];
  undefined4 local_110;
  undefined4 local_10c [17];
  undefined4 local_c8 [30];
  undefined4 local_50 [14];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_114;
  local_110 = param_3;
  if (((param_4 != 0) && (param_2 != (int *)0x0)) && (param_5 != 0)) {
    puVar2 = (undefined4 *)(param_4 + 0x54);
    puVar4 = local_c8;
    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar2 = (undefined4 *)(param_4 + 0x98);
    puVar4 = local_10c;
    for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    uVar1 = FUN_007e7dd0(param_5 + 4);
    puVar2 = (undefined4 *)FUN_0087b030(uVar1);
    puVar4 = local_50;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    (**(code **)(*param_2 + 0x98))(param_2,local_110,local_50);
    __security_check_cookie(uStack_18 ^ (uint)&stack0xfffffee0);
    return;
  }
  __security_check_cookie(local_c ^ (uint)auStack_114);
  return;
}

