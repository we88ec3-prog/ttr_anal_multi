
void FUN_005e1770(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  int in_ECX;
  undefined4 *extraout_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091f8ee;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  FUN_0046b6f0(*(int *)(in_ECX + 0x15c) + 100,DAT_00d61f20 ^ (uint)&stack0xfffffffc);
  FUN_0043c570(*(int *)(in_ECX + 0x15c) + 200);
  FUN_0043c570(*(int *)(in_ECX + 0x15c) + 300);
  FUN_0043c570(*(int *)(in_ECX + 0x15c) + 400);
  iVar1 = *(int *)(in_ECX + 0x18c);
  FUN_007444b0(0xbf6b);
  *(undefined1 *)(iVar1 + 0xa4) = 1;
  iVar1 = *(int *)(in_ECX + 0x18c);
  if (((*(char *)(iVar1 + 0xa4) != '\0') && (*(int *)(iVar1 + 0x94) != 0)) &&
     (iVar5 = (**(code **)(**(int **)(iVar1 + 0x94) + 4))(), iVar5 == 0xbf6b)) {
    *(undefined1 *)(*(int *)(iVar1 + 0x94) + 0x4c) = 1;
  }
  uVar4 = DAT_00faadd0 & 1;
  *(int *)(in_ECX + 0x170) =
       *(int *)(*(int *)(in_ECX + 400) + 0x14) - *(int *)(*(int *)(in_ECX + 400) + 0xc);
  if (uVar4 == 0) {
    DAT_00faadd0 = DAT_00faadd0 | 1;
    local_8 = 0;
    FUN_0074d990();
    _atexit((_func_4879 *)&LAB_00bccc70);
    local_8 = 0xffffffff;
  }
  *(undefined **)(in_ECX + 0x24) = &DAT_00f94810;
  if ((*(int *)(in_ECX + 0x3c) != 0) && ((*(uint *)(in_ECX + 0x28) & 0x40000) == 0)) {
    FUN_007486f0(&DAT_00f94810);
  }
  puVar2 = *(undefined4 **)(in_ECX + 100);
  puVar3 = (undefined4 *)*puVar2;
  while (puVar3 != puVar2) {
    FUN_007486f0(*(undefined4 *)(in_ECX + 0x24));
    puVar3 = (undefined4 *)*extraout_EDX;
  }
  ExceptionList = local_10;
  return;
}

