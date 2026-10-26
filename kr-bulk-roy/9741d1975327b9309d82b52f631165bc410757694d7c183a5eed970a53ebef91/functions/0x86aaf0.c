
undefined4 FUN_0086aaf0(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  int unaff_ESI;
  int iStack_54;
  int iStack_50;
  int iStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  undefined4 *puStack_3c;
  int iStack_38;
  int iStack_34;
  undefined4 uStack_30;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 local_c [2];
  
  uStack_30 = *(undefined4 *)(param_1 + 0x88);
  uStack_24 = 0;
  local_c[0] = *(undefined4 *)(in_ECX + 0x18);
  uStack_28 = 4;
  puStack_2c = local_c;
  puVar2 = (undefined4 *)(in_ECX + 8);
  iStack_34 = 0x86ab20;
  FUN_00721910();
  if (0xf < *(uint *)(in_ECX + 0x1c)) {
    puVar2 = (undefined4 *)*puVar2;
  }
  if ((puVar2 != (undefined4 *)0x0) && (unaff_ESI != 0)) {
    iStack_34 = 0;
    iStack_40 = *(undefined4 *)(param_1 + 0x88);
    iStack_44 = 0x86ab44;
    puStack_3c = puVar2;
    FUN_00721910();
  }
  iStack_34 = param_1;
  iStack_38 = 0x86ab50;
  (**(code **)(*(int *)(in_ECX + 0x28) + 0xc))();
  iStack_38 = param_1;
  puStack_3c = (undefined4 *)0x86ab5c;
  (**(code **)(*(int *)(in_ECX + 100) + 0xc))();
  puStack_3c = (undefined4 *)param_1;
  iStack_40 = 0x86ab6e;
  (**(code **)(*(int *)(in_ECX + 0xa0) + 0xc))();
  iStack_40 = param_1;
  iStack_44 = 0x86ab80;
  (**(code **)(*(int *)(in_ECX + 0xdc) + 0xc))();
  iStack_44 = param_1;
  iStack_48 = 0x86ab92;
  (**(code **)(*(int *)(in_ECX + 0x118) + 0xc))();
  iStack_48 = param_1;
  iStack_4c = 0x86aba4;
  (**(code **)(*(int *)(in_ECX + 0x154) + 0xc))();
  iStack_4c = param_1;
  iStack_50 = 0x86abb6;
  (**(code **)(*(int *)(in_ECX + 400) + 0xc))();
  iStack_50 = param_1;
  iStack_54 = 0x86abc8;
  (**(code **)(*(int *)(in_ECX + 0x1cc) + 0xc))();
  iStack_54 = param_1;
  (**(code **)(*(int *)(in_ECX + 0x208) + 0xc))();
  (**(code **)(*(int *)(in_ECX + 0x244) + 0xc))(param_1);
  (**(code **)(*(int *)(in_ECX + 0x280) + 0xc))(param_1);
  (**(code **)(*(int *)(in_ECX + 700) + 0xc))(param_1);
  if (in_ECX + 0x2f8 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x2f8,4,0);
  }
  (**(code **)(*(int *)(in_ECX + 0x2fc) + 0xc))(param_1);
  if (in_ECX + 0x338 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x338,4,0);
  }
  if (in_ECX + 0x33c != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x33c,4,0);
  }
  iVar1 = in_ECX + 0x340;
  if (iVar1 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar1,0x1c,0);
  }
  if (in_ECX + 0x364 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),in_ECX + 0x364,4,0);
  }
  if (iVar1 != 0) {
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),iVar1,0x1c,0);
  }
  iStack_54 = 0;
  if (*(int *)(in_ECX + 0x35c) != 0) {
    iStack_54 = *(int *)(*(int *)(in_ECX + 0x35c) + 4);
    FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_54,4,0);
    (**(code **)(**(int **)(in_ECX + 0x35c) + 0x18))(param_1);
    return 1;
  }
  FUN_00721910(*(undefined4 *)(param_1 + 0x88),&iStack_54,4,0);
  return 1;
}

