
void FUN_00798900(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00915292;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)param_1[1];
  if ((param_2 < puVar1) && (puVar3 = (undefined4 *)*param_1, puVar3 <= param_2)) {
    if (puVar1 == (undefined4 *)param_1[2]) {
      FUN_007989e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    param_2 = (undefined4 *)(*param_1 + (((int)param_2 - (int)puVar3) / 0x48) * 0x48);
    puVar1 = (undefined4 *)param_1[1];
    local_8 = 0;
  }
  else {
    if (puVar1 == (undefined4 *)param_1[2]) {
      FUN_007989e0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    }
    puVar1 = (undefined4 *)param_1[1];
    local_8 = 1;
  }
  if (puVar1 != (undefined4 *)0x0) {
    puVar3 = param_2;
    puVar4 = puVar1;
    for (iVar2 = 0xb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    puVar1[0x10] = 0xf;
    puVar1[0xf] = 0;
    *(undefined1 *)(puVar1 + 0xb) = 0;
    FUN_00403040(param_2 + 0xb,0,0xffffffff);
  }
  param_1[1] = param_1[1] + 0x48;
  ExceptionList = local_10;
  return;
}

