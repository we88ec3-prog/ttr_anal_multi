
void FUN_00652ac0(void)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  uint local_20;
  void *local_1c;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  puStack_10 = &LAB_0093605e;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  if ((DAT_00fab22c & 1) == 0) {
    DAT_00fab22c = DAT_00fab22c | 1;
    local_c = 0;
    FUN_004dec90(DAT_00d61f20 ^ (uint)&stack0xffffffd8);
    _atexit((_func_4879 *)&LAB_00bcce30);
  }
  iVar3 = DAT_00fab134;
  local_c = 0xffffffff;
  if ((DAT_00fab134 != 0) && ((char)*(ushort *)(DAT_00fab134 + 0x32) == '\x01')) {
    local_20 = (uint)*(ushort *)(DAT_00fab134 + 0x32);
    iVar4 = FUN_0040f060();
    FUN_0082ef00(&local_20);
    if ((local_1c != *(void **)(iVar4 + 0xc)) &&
       (piVar1 = *(int **)((int)local_1c + 0x10), piVar1 != (int *)0x0)) {
      (**(code **)(**(int **)(unaff_EDI + 0x90) + 0x94))(1);
      (**(code **)(**(int **)(unaff_EDI + 0x9c) + 0x94))(1);
      iVar4 = (**(code **)(*piVar1 + 0x74))();
      pcVar2 = *(code **)(**(int **)(unaff_EDI + 0x98) + 0x128);
      (*(int **)(unaff_EDI + 0x98))[0x34] = (int)((float)iVar4 * 0.01 * 0.01);
      (*pcVar2)();
      FUN_00425330();
      FUN_004f7a70();
      FUN_00757710();
      (**(code **)(**(int **)(unaff_EDI + 0x90) + 200))();
      iVar4 = *(int *)(unaff_EDI + 0x9c);
      *(uint *)(iVar4 + 0xe4) = (uint)*(ushort *)(iVar3 + 0x32);
      *(undefined4 *)(iVar4 + 0xdc) = 3;
      FUN_0068b260(*(undefined4 *)(unaff_EDI + 0x9c));
      ExceptionList = local_1c;
      return;
    }
  }
  (**(code **)(**(int **)(unaff_EDI + 0x90) + 0x94))(0);
  (**(code **)(**(int **)(unaff_EDI + 0x9c) + 0x94))(0);
  ExceptionList = local_1c;
  return;
}

