
undefined4 FUN_004a90c0(ushort param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined2 *puVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  int in_ECX;
  int *piVar8;
  uint local_18;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00929f87;
  local_10 = ExceptionList;
  uVar5 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_18 = (uint)param_1;
  FUN_004aa530(&local_18);
  piVar4 = local_14;
  if ((local_14 != (int *)*(int *)(in_ECX + 0x28)) &&
     (piVar8 = (int *)0x0, local_14 != (int *)0xfffffff0)) {
    piVar6 = (int *)FUN_00891268(0x108,uVar5);
    local_8 = 0;
    if (piVar6 != (int *)0x0) {
      puVar1 = (undefined4 *)((int)local_14 + 0x20);
      puVar2 = (undefined4 *)((int)local_14 + 0x1c);
      puVar3 = (undefined2 *)((int)local_14 + 0x12);
      local_14 = piVar6;
      piVar8 = (int *)FUN_00543700(piVar6,4,*puVar3,*puVar2,1,*puVar1,0);
      piVar6 = local_14;
    }
    local_14 = piVar6;
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 1;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    local_18 = (int)piVar4 + 0x24;
    local_14 = (int *)DAT_00fb90bc;
    if (0xf < *(uint *)((int)piVar4 + 0x38)) {
      local_18 = *(uint *)local_18;
    }
    if ((DAT_00fdf6dc & 1) == 0) {
      DAT_00fdf6dc = DAT_00fdf6dc | 1;
      local_8 = 2;
      FUN_00550820();
      _atexit((_func_4879 *)&LAB_00bce6b0);
    }
    local_8 = 0xffffffff;
    uVar7 = (**(code **)(*piVar8 + 0x4c))();
    local_14 = (int *)(*(float *)((int)piVar4 + 0x1c) * (float)local_14);
    FUN_00551b80(0xffffffff,0xffffffff);
    uVar7 = FUN_00551dd0(&DAT_00fdf680,0,uVar7,0,local_14,0);
    FUN_005447f0(piVar8,uVar7);
    local_14 = piVar8;
    FUN_00434250();
    FUN_00443d10();
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

