
void FUN_0066c830(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00908292;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)param_1[1];
  if ((param_2 < puVar1) && (puVar3 = (undefined4 *)*param_1, puVar3 <= param_2)) {
    if (puVar1 == (undefined4 *)param_1[2]) {
      FUN_0066c920(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)param_1[1];
    param_2 = (undefined4 *)((((int)param_2 - (int)puVar3) / 0x50) * 0x50 + *param_1);
    local_8 = 0;
    if (puVar1 == (undefined4 *)0x0) goto LAB_0066c900;
    *puVar1 = *param_2;
    iVar2 = 0xf;
    puVar3 = param_2;
    puVar4 = puVar1;
    while( true ) {
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      *puVar4 = *puVar3;
    }
  }
  else {
    if (puVar1 == (undefined4 *)param_1[2]) {
      FUN_0066c920(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)param_1[1];
    local_8 = 1;
    if (puVar1 == (undefined4 *)0x0) goto LAB_0066c900;
    *puVar1 = *param_2;
    iVar2 = 0xf;
    puVar3 = param_2;
    puVar4 = puVar1;
    while( true ) {
      puVar4 = puVar4 + 1;
      puVar3 = puVar3 + 1;
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      *puVar4 = *puVar3;
    }
  }
  FUN_00507f70(puVar1 + 0x10,param_2 + 0x10);
LAB_0066c900:
  param_1[1] = param_1[1] + 0x50;
  ExceptionList = local_10;
  return;
}

