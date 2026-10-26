
void FUN_0087b5f0(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 auStack_9c [4];
  undefined4 local_98;
  undefined4 auStack_94 [17];
  undefined4 auStack_50 [14];
  uint uStack_18;
  uint local_c;
  
  local_c = DAT_00d61f20 ^ (uint)auStack_9c;
  local_98 = param_3;
  if ((param_5 != 0) && (*(int **)(param_5 + 0x3c) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(param_5 + 0x3c) + 4))();
    if (*(int *)(iVar1 + 4) == -0x5ece0000) {
      iVar1 = FUN_00843f60(param_1);
      puVar3 = (undefined4 *)(iVar1 + 0x70);
      puVar4 = auStack_94;
      for (iVar2 = 0x11; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      puVar3 = auStack_94;
      puVar4 = auStack_50;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      (**(code **)(*param_2 + 0x98))(param_2,local_98,auStack_50);
      __security_check_cookie(uStack_18 ^ (uint)&stack0xffffff58);
      return;
    }
  }
  __security_check_cookie(local_c ^ (uint)auStack_9c);
  return;
}

