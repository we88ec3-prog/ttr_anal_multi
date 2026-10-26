
undefined1 * FUN_006ccc00(undefined1 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_0090818a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 0x14) = 0xf;
  *(undefined4 *)(param_1 + 0x10) = 0;
  *param_1 = 0;
  *(undefined4 *)(param_1 + 0x30) = 0xf;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  param_1[0x1c] = 0;
  local_8 = 1;
  uStack_7 = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  uVar2 = FUN_00820120(uVar1);
  *(undefined4 *)(param_1 + 0x44) = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(int *)(*(int *)(param_1 + 0x44) + 4) = *(int *)(param_1 + 0x44);
  *(int *)(*(int *)(param_1 + 0x44) + 8) = *(int *)(param_1 + 0x44);
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x18) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x44) + 0x19) = 1;
  local_8 = 2;
  *(undefined4 *)(param_1 + 0x58) = 0;
  uVar2 = FUN_00820120();
  *(undefined4 *)(param_1 + 0x54) = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(int *)(*(int *)(param_1 + 0x54) + 4) = *(int *)(param_1 + 0x54);
  *(int *)(*(int *)(param_1 + 0x54) + 8) = *(int *)(param_1 + 0x54);
  *(undefined1 *)(*(int *)(param_1 + 0x54) + 0x18) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x54) + 0x19) = 1;
  local_8 = 3;
  *(undefined4 *)(param_1 + 0x68) = 0;
  uVar2 = FUN_00820120();
  *(undefined4 *)(param_1 + 100) = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(int *)(*(int *)(param_1 + 100) + 4) = *(int *)(param_1 + 100);
  *(int *)(*(int *)(param_1 + 100) + 8) = *(int *)(param_1 + 100);
  *(undefined1 *)(*(int *)(param_1 + 100) + 0x18) = 1;
  *(undefined1 *)(*(int *)(param_1 + 100) + 0x19) = 1;
  _local_8 = CONCAT31(uStack_7,4);
  *(undefined4 *)(param_1 + 0x78) = 0;
  uVar2 = FUN_00820120();
  *(undefined4 *)(param_1 + 0x74) = uVar2;
  *(undefined4 *)uVar2 = uVar2;
  *(int *)(*(int *)(param_1 + 0x74) + 4) = *(int *)(param_1 + 0x74);
  *(int *)(*(int *)(param_1 + 0x74) + 8) = *(int *)(param_1 + 0x74);
  *(undefined1 *)(*(int *)(param_1 + 0x74) + 0x18) = 1;
  *(undefined1 *)(*(int *)(param_1 + 0x74) + 0x19) = 1;
  ExceptionList = local_10;
  return param_1;
}

