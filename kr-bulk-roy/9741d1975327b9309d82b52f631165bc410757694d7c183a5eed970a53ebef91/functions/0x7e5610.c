
void FUN_007e5610(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  longlong lVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  int *local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009378bc;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
  }
  iVar5 = DAT_00fb76a8;
  local_8 = 0xffffffff;
  if (*(int *)(DAT_00fb76a8 + 0xec) != 0) {
    (**(code **)(**(int **)(DAT_00fb76a8 + 0xec) + 4))(*(int **)(DAT_00fb76a8 + 0xec));
    local_14 = *(int **)(iVar5 + 0xec);
  }
  if (*(int *)(in_ECX + 0x174) == 0) {
    MessageBoxA((HWND)0x0,&DAT_00c50530,"Error",0);
    ExceptionList = local_10;
    return;
  }
  FUN_007e57c0(in_ECX);
  FUN_007e5430();
  FUN_007e54a0();
  FUN_007e5050();
  lVar4 = (ulonglong)*(uint *)(in_ECX + 0x174) * 0xc;
  iVar5 = FUN_0087dc3d(-(uint)((int)((ulonglong)lVar4 >> 0x20) != 0) | (uint)lVar4);
  uVar8 = 0;
  if (*(int *)(in_ECX + 0x174) != 0) {
    iVar6 = 0;
    do {
      iVar3 = *(int *)(in_ECX + 0x16c);
      uVar8 = uVar8 + 1;
      iVar7 = iVar6 + 0xc;
      uVar1 = *(undefined4 *)(iVar3 + -8 + iVar7);
      uVar2 = *(undefined4 *)(iVar3 + -4 + iVar7);
      *(undefined4 *)(iVar6 + iVar5) = *(undefined4 *)(iVar3 + iVar6);
      *(undefined4 *)(iVar6 + 4 + iVar5) = uVar1;
      *(undefined4 *)(iVar6 + 8 + iVar5) = uVar2;
      iVar6 = iVar7;
    } while (uVar8 < *(uint *)(in_ECX + 0x174));
  }
  FUN_007f7450(*(undefined4 *)(in_ECX + 0x24),*(int *)(in_ECX + 0x154) + 1,iVar5);
  if (iVar5 != 0) {
    FUN_00891d3d(iVar5);
  }
  if (*(int *)(in_ECX + 0x19c) != 0) {
    FUN_007f8270();
  }
  (**(code **)(*local_14 + 8))(local_14);
  ExceptionList = local_10;
  return;
}

