
undefined4 FUN_0073a8b0(void)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091946c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 0;
    FUN_00736880(uVar3);
    _atexit(FUN_00bce6f0);
  }
  piVar2 = DAT_00fcde2c;
  if ((DAT_00fcde40 & 1) == 0) {
    DAT_00fcde40 = DAT_00fcde40 | 1;
    local_8 = 1;
    FUN_00736880(uVar3);
    _atexit(FUN_00bce6f0);
  }
  local_8 = 0xffffffff;
  if ((*(int *)(in_ECX + 0x4c) != 0) && (piVar2 != (int *)0x0)) {
    (**(code **)(*DAT_00fcde28 + 0x2c))(DAT_00fcde28);
    (**(code **)(*piVar2 + 0xa8))(piVar2);
    (**(code **)(*piVar2 + 0x94))(piVar2,0,*(undefined4 *)(in_ECX + 0x74));
    piVar1 = *(int **)(in_ECX + 0x74);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(in_ECX + 0x74) = 0;
    }
    (**(code **)(*piVar2 + 0x9c))(piVar2,*(undefined4 *)(in_ECX + 0x78));
    piVar1 = *(int **)(in_ECX + 0x78);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
      *(undefined4 *)(in_ECX + 0x78) = 0;
    }
    *(undefined4 *)(in_ECX + 0x94) = 0;
    (**(code **)(*piVar2 + 0xe4))(piVar2,7,1);
    (**(code **)(*piVar2 + 0xe4))(piVar2,0xce,*(undefined4 *)(in_ECX + 0x7c));
    (**(code **)(*piVar2 + 0xe4))(piVar2,0xd0,*(undefined4 *)(in_ECX + 0x80));
    (**(code **)(*piVar2 + 0xe4))(piVar2,0xcf,*(undefined4 *)(in_ECX + 0x84));
    (**(code **)(*piVar2 + 0xe4))(piVar2,7,*(undefined4 *)(in_ECX + 0x88));
    (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,*(undefined4 *)(in_ECX + 0x8c));
    (**(code **)(*piVar2 + 0xe4))(piVar2,0x17,*(undefined4 *)(in_ECX + 0x90));
    if (*(int *)(in_ECX + 0x98) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x4c) + 0x40))(*(int **)(in_ECX + 0x4c));
    }
    ExceptionList = local_10;
    return 1;
  }
  ExceptionList = local_10;
  return 0;
}

