
void FUN_006528c0(int param_1)

{
  int *piVar1;
  int iVar2;
  uint local_24;
  int local_20;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_00936a1e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd0);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  local_c = 0xffffffff;
  local_1c = DAT_00fab134;
  if ((DAT_00fab134 != (void *)0x0) && ((char)*(ushort *)((int)DAT_00fab134 + 0x30) == '\x01')) {
    local_24 = (uint)*(ushort *)((int)DAT_00fab134 + 0x30);
    iVar2 = FUN_0040f060();
    FUN_0082ef00(&local_24);
    if ((local_20 != *(int *)(iVar2 + 0xc)) &&
       (piVar1 = *(int **)(local_20 + 0x10), piVar1 != (int *)0x0)) {
      if ((*(int **)(param_1 + 0xa0) != piVar1) &&
         (FUN_00652fb0(*(undefined4 *)(param_1 + 0x84)),
         *(char *)(*(int *)(param_1 + 0x84) + 300) != '\0')) {
        *(int **)(param_1 + 0xa0) = piVar1;
      }
      (**(code **)(**(int **)(param_1 + 0x80) + 0x94))(1);
      (**(code **)(**(int **)(param_1 + 0x8c) + 0x94))(1);
      iVar2 = (**(code **)(*piVar1 + 0x74))();
      FUN_00653190((float)iVar2 * 0.01 * 0.01);
      FUN_00425330();
      FUN_004f7a70();
      FUN_00757710();
      (**(code **)(**(int **)(param_1 + 0x80) + 200))();
      iVar2 = *(int *)(param_1 + 0x8c);
      *(uint *)(iVar2 + 0xe4) = (uint)*(ushort *)(local_24 + 0x30);
      *(undefined4 *)(iVar2 + 0xdc) = 3;
      FUN_0068b260(*(undefined4 *)(param_1 + 0x8c));
      ExceptionList = local_1c;
      return;
    }
  }
  (**(code **)(**(int **)(param_1 + 0x80) + 0x94))(0);
  (**(code **)(**(int **)(param_1 + 0x8c) + 0x94))(0);
  ExceptionList = local_1c;
  return;
}

