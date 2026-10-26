
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_005e10e0(int param_1)

{
  uint uVar1;
  int in_ECX;
  undefined2 local_c;
  undefined1 local_a;
  undefined1 local_9;
  uint local_8;
  
  if (((*(char *)(in_ECX + 0x2a8) == '\0') && (*(int *)(param_1 + 0x10) == 0x57a)) &&
     (*(int *)(param_1 + 8) != *(int *)(*(int *)(in_ECX + 0x2a4) + 0x20))) {
    if (*(int *)(in_ECX + 0x25c) != 0) {
      FUN_00414680();
      FUN_004a3890(*(undefined4 *)(in_ECX + 0x298),*(undefined4 *)(in_ECX + 0x29c));
      return;
    }
  }
  else if ((*(int *)(param_1 + 8) == *(int *)(*(int *)(in_ECX + 0x2a4) + 0x20)) &&
          (*(int *)(param_1 + 0x10) == 0x578)) {
    uVar1 = *(uint *)(*(int *)(in_ECX + 0x2a4) + 0x28);
    if ((_DAT_00fb1314 & 1) == 0) {
      _DAT_00fb1314 = _DAT_00fb1314 | 1;
      _atexit((_func_4879 *)&DAT_00bccf10);
    }
    local_a = *(undefined1 *)(in_ECX + 0x298);
    local_9 = *(undefined1 *)(in_ECX + 0x29c);
    local_c = 0xbd;
    local_8 = (uint)((uVar1 >> 9 & 1) == 0);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,&local_c,8);
    }
  }
  return;
}

