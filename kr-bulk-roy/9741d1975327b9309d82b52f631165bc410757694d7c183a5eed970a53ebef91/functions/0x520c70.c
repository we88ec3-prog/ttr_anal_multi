
void FUN_00520c70(int param_1)

{
  int *piVar1;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090b220;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  piVar1 = (int *)(param_1 + 0x148);
  local_8 = 7;
  FUN_00523e40(piVar1,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  if (*piVar1 != 0) {
    FUN_0089120c(*piVar1);
  }
  *piVar1 = 0;
  *(undefined4 *)(param_1 + 0x14c) = 0;
  *(undefined4 *)(param_1 + 0x150) = 0;
  if (*(int *)(param_1 + 0x138) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x138));
  }
  *(undefined4 *)(param_1 + 0x138) = 0;
  *(undefined4 *)(param_1 + 0x13c) = 0;
  *(undefined4 *)(param_1 + 0x140) = 0;
  if (*(int *)(param_1 + 0x128) != 0) {
    FUN_0089120c(*(int *)(param_1 + 0x128));
  }
  *(undefined4 *)(param_1 + 0x128) = 0;
  *(undefined4 *)(param_1 + 300) = 0;
  *(undefined4 *)(param_1 + 0x130) = 0;
  if (7 < *(uint *)(param_1 + 0x120)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0x10c));
  }
  *(undefined4 *)(param_1 + 0x120) = 7;
  *(undefined4 *)(param_1 + 0x11c) = 0;
  *(undefined2 *)(param_1 + 0x10c) = 0;
  if (7 < *(uint *)(param_1 + 0x104)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0xf0));
  }
  *(undefined4 *)(param_1 + 0x104) = 7;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(undefined2 *)(param_1 + 0xf0) = 0;
  if (7 < *(uint *)(param_1 + 0xe4)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0xd0));
  }
  *(undefined4 *)(param_1 + 0xe4) = 7;
  *(undefined4 *)(param_1 + 0xe0) = 0;
  *(undefined2 *)(param_1 + 0xd0) = 0;
  if (7 < *(uint *)(param_1 + 200)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0xb4));
  }
  *(undefined4 *)(param_1 + 200) = 7;
  *(undefined4 *)(param_1 + 0xc4) = 0;
  *(undefined2 *)(param_1 + 0xb4) = 0;
  if (7 < *(uint *)(param_1 + 0xac)) {
    FUN_0089120c(*(undefined4 *)(param_1 + 0x98));
  }
  *(undefined4 *)(param_1 + 0xac) = 7;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined2 *)(param_1 + 0x98) = 0;
  ExceptionList = local_10;
  return;
}

