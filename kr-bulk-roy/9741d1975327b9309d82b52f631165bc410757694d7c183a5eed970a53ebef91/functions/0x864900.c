
undefined4 * FUN_00864900(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090ba68;
  local_10 = ExceptionList;
  uVar4 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = gbDxMeshBuffer::vftable;
  param_1[1] = param_2;
  (**(code **)(*param_2 + 4))(param_2,uVar4);
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[2] = 0;
  param_1[8] = 0;
  if (in_ECX != 0) {
    if (*(int *)(in_ECX + 0x40) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00857160(*(int *)(in_ECX + 0x40));
    }
    puVar1 = param_1 + 4;
    *puVar1 = uVar5;
    if (*(int *)(in_ECX + 0x40) == 0) {
      uVar5 = 0;
    }
    else {
      uVar5 = FUN_00857160(*(int *)(in_ECX + 0x40));
    }
    *puVar1 = uVar5;
    FUN_008629e0(param_1[1],param_1 + 5,puVar1);
    piVar2 = (int *)param_1[6];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      param_1[6] = 0;
    }
    FUN_00862b60(param_1[1]);
    iVar3 = *(int *)(in_ECX + 0x40);
    if (iVar3 != 0) {
      piVar2 = (int *)param_1[7];
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 8))(piVar2);
        param_1[7] = 0;
      }
      FUN_00862aa0(param_1[1],iVar3,param_1 + 7);
    }
    FUN_00864d50(*(int *)(in_ECX + 0x58),(*(int *)(in_ECX + 0x5c) - *(int *)(in_ECX + 0x58)) / 0x14)
    ;
  }
  ExceptionList = local_10;
  return param_1;
}

