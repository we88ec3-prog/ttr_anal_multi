
undefined4 FUN_0073a620(int param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091946c;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((param_1 == -1) || (param_2 == -1)) {
    iVar4 = *(int *)(in_ECX + 0xc);
    iVar5 = *(int *)(in_ECX + 0x10);
  }
  else {
    iVar4 = 1;
    do {
      iVar4 = iVar4 * 2;
    } while (iVar4 < param_1);
    iVar5 = 1;
    do {
      iVar5 = iVar5 * 2;
    } while (iVar5 < param_2);
  }
  if ((*(int *)(in_ECX + 0xc) != iVar4) || (*(int *)(in_ECX + 0x10) != iVar5)) {
    *(int *)(in_ECX + 0xc) = iVar4;
    *(int *)(in_ECX + 0x10) = iVar5;
    if (*(int *)(in_ECX + 0x4c) != 0) {
      (**(code **)(*(int *)(in_ECX + 8) + 8))(uVar3);
    }
    (**(code **)(*(int *)(in_ECX + 8) + 4))();
  }
  if (*(int *)(in_ECX + 0x4c) != 0) {
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_8 = 0;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_8 = 0xffffffff;
    }
    piVar2 = DAT_00fcde2c;
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_8 = 1;
      FUN_00736880();
      _atexit(FUN_00bce6f0);
      local_8 = 0xffffffff;
    }
    piVar1 = DAT_00fcde28;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x98))(piVar2,0,in_ECX + 0x74);
      (**(code **)(*piVar2 + 0x94))(piVar2,0,*(undefined4 *)(in_ECX + 0x70));
      (**(code **)(*piVar2 + 0xa0))(piVar2,in_ECX + 0x78);
      (**(code **)(*piVar2 + 0x9c))(piVar2,0);
      (**(code **)(*piVar2 + 0xac))(piVar2,0,0,1,0,0,0);
      iVar4 = (**(code **)(*piVar2 + 0xa4))(piVar2);
      if ((-1 < iVar4) && (iVar4 = (**(code **)(*piVar1 + 0x20))(piVar1,0x10), -1 < iVar4)) {
        (**(code **)(*piVar2 + 0xe8))(piVar2,0xce,in_ECX + 0x7c);
        (**(code **)(*piVar2 + 0xe8))(piVar2,0xd0,in_ECX + 0x80);
        (**(code **)(*piVar2 + 0xe8))(piVar2,0xcf,in_ECX + 0x84);
        (**(code **)(*piVar2 + 0xe8))(piVar2,7,in_ECX + 0x88);
        (**(code **)(*piVar2 + 0xe8))(piVar2,0xe,in_ECX + 0x8c);
        (**(code **)(*piVar2 + 0xe8))(piVar2,0x17,in_ECX + 0x90);
        (**(code **)(*piVar2 + 0xe4))(piVar2,7,0);
        (**(code **)(*piVar2 + 0xe4))(piVar2,0xe,0);
        (**(code **)(*piVar2 + 0xe4))(piVar2,0x17,8);
        (**(code **)(*piVar2 + 0xe4))(piVar2,0xce,1);
        (**(code **)(*piVar2 + 0xe4))(piVar2,0xd0,2);
        (**(code **)(*piVar2 + 0xe4))(piVar2,0xcf,2);
        ExceptionList = local_10;
        return 1;
      }
    }
  }
  ExceptionList = local_10;
  return 0;
}

