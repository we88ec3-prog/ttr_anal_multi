
void FUN_0057f950(void)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093896e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(undefined4 *)(in_ECX + 0x74) = 1;
  if (*(int *)(in_ECX + 0x78) == 0) {
    if ((DAT_00fcde40 & 1) == 0) {
      DAT_00fcde40 = DAT_00fcde40 | 1;
      local_8 = 0;
      FUN_00736880(uVar3);
      _atexit(FUN_00bce6f0);
    }
    local_8 = 0xffffffff;
    FUN_0057f670(DAT_00fcde28);
  }
  if (*(int *)(in_ECX + 0x7c) == 0) {
    FUN_0057f7c0();
  }
  FUN_00580390();
  *(undefined4 *)(in_ECX + 0x70) = 0;
  iVar4 = *(int *)(in_ECX + 0x5c) - *(uint *)(in_ECX + 0x58);
  puVar1 = *(undefined4 **)(in_ECX + 0x44);
  iVar2 = iVar4 >> 0x1f;
  *(uint *)(in_ECX + 0x68) = -(uint)(iVar4 / 0x34 + iVar2 != iVar2) & *(uint *)(in_ECX + 0x58);
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  if (*(int **)(in_ECX + 0x54) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x54) + 4))();
  }
  *(undefined4 **)(in_ECX + 0x54) = puVar1;
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)*puVar1)();
  }
  ExceptionList = local_10;
  return;
}

