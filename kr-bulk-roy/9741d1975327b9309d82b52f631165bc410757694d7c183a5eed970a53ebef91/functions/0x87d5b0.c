
void FUN_0087d5b0(undefined4 param_1,int *param_2,undefined4 param_3,int param_4)

{
  code *pcVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_dc;
  undefined4 local_d8 [34];
  undefined4 local_50 [14];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)&local_dc;
  local_dc = param_3;
  if ((param_4 != 0) && (param_2 != (int *)0x0)) {
    puVar2 = (undefined4 *)(param_4 + 0x54);
    puVar4 = local_d8;
    for (iVar3 = 0x11; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar2 = (undefined4 *)(param_4 + 0x98);
    puVar4 = local_50;
    for (iVar3 = 0xd; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar2 = (undefined4 *)FUN_0087b030(local_50);
    pcVar1 = *(code **)(*param_2 + 0x98);
    puVar4 = local_50;
    for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar4 = puVar4 + 1;
    }
    (*pcVar1)(param_2,local_dc,local_50);
    __security_check_cookie(uStack_18 ^ (uint)&stack0xffffff18);
    return;
  }
  __security_check_cookie(local_c ^ (uint)&local_dc);
  return;
}

