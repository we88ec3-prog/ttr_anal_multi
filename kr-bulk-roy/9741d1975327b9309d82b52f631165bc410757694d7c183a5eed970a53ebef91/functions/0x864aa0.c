
undefined4 * FUN_00864aa0(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  void *_Dst;
  int unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00904588;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = gbDxMeshBuffer::vftable;
  piVar1 = *(int **)(unaff_EDI + 4);
  param_1[1] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1,uVar2);
  }
  uVar2 = *(uint *)(unaff_EDI + 8);
  param_1[2] = uVar2;
  if (uVar2 != 0) {
    _Dst = (void *)FUN_0087dc3d(-(uint)((int)((ulonglong)uVar2 * 0x14 >> 0x20) != 0) |
                                (uint)((ulonglong)uVar2 * 0x14));
    param_1[3] = _Dst;
    FID_conflict__memcpy(_Dst,*(void **)(unaff_EDI + 0xc),param_1[2] * 0x14);
  }
  param_1[4] = *(undefined4 *)(unaff_EDI + 0x10);
  piVar1 = *(int **)(unaff_EDI + 0x14);
  param_1[5] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  piVar1 = *(int **)(unaff_EDI + 0x18);
  param_1[6] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  piVar1 = *(int **)(unaff_EDI + 0x1c);
  param_1[7] = piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  param_1[8] = *(undefined4 *)(unaff_EDI + 0x20);
  ExceptionList = local_10;
  return param_1;
}

