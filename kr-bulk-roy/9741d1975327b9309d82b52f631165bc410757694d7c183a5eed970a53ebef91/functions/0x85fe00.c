
undefined4 * FUN_0085fe00(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined1 local_14 [4];
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091805f;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  FUN_007846f0(param_1);
  puVar1 = param_1 + 0x1e;
  *param_1 = gbSkeletal::vftable;
  *puVar1 = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  local_8 = 3;
  param_1[0x1d] = 0;
  if (*(int *)(param_2 + 0x74) != 0) {
    uVar4 = (**(code **)(**(int **)(param_2 + 0x74) + 0xc))(uVar3);
    param_1[0x1d] = uVar4;
    FUN_00872580(uVar4,0x10);
    FUN_00872580(param_1[0x1d],0x101);
  }
  param_1[0x2a] = *(undefined4 *)(param_2 + 0xa8);
  uVar4 = *(undefined4 *)(param_2 + 0x7c);
  uVar2 = *(undefined4 *)(param_2 + 0x78);
  FUN_00860810(puVar1,local_14,*puVar1,param_1[0x1f]);
  FUN_0077fae0(*puVar1,uVar2,uVar4,uVar4);
  ExceptionList = local_10;
  return param_1;
}

