
undefined4 FUN_007f3540(void)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009348ce;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((*(int *)(unaff_ESI + 4) != 0) && (*(int *)(unaff_ESI + 8) != 0)) {
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar1 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    (**(code **)(*piVar1 + 0x164))(piVar1,*(undefined4 *)(unaff_ESI + 0xc));
    if ((*(uint *)(unaff_ESI + 0x14) <= *(uint *)(unaff_ESI + 0x24)) ||
       (*(uint *)(unaff_ESI + 0x1c) <= *(uint *)(unaff_ESI + 0x2c))) {
      *(undefined4 *)(unaff_ESI + 0x2c) = 0;
      *(undefined4 *)(unaff_ESI + 0x24) = 0;
    }
    iVar2 = (**(code **)(**(int **)(unaff_ESI + 4) + 0x2c))
                      (*(int **)(unaff_ESI + 4),
                       *(int *)(unaff_ESI + 0x10) * *(int *)(unaff_ESI + 0x24),
                       *(int *)(unaff_ESI + 0x28) * *(int *)(unaff_ESI + 0x10),unaff_ESI + 0x34,
                       (-(uint)(*(int *)(unaff_ESI + 0x24) != 0) & 0xfffff000) + 0x2000);
    if ((-1 < iVar2) && (*(int *)(unaff_ESI + 0x34) != 0)) {
      iVar2 = (**(code **)(**(int **)(unaff_ESI + 8) + 0x2c))
                        (*(int **)(unaff_ESI + 8),*(int *)(unaff_ESI + 0x2c) * 2,
                         *(int *)(unaff_ESI + 0x30) * 2,(int *)(unaff_ESI + 0x38),
                         (-(uint)(*(int *)(unaff_ESI + 0x2c) != 0) & 0xfffff000) + 0x2000);
      if ((-1 < iVar2) && (*(int *)(unaff_ESI + 0x38) != 0)) {
        *(int *)(unaff_ESI + 0x24) = *(int *)(unaff_ESI + 0x24) + *(int *)(unaff_ESI + 0x28);
        *(int *)(unaff_ESI + 0x2c) = *(int *)(unaff_ESI + 0x2c) + *(int *)(unaff_ESI + 0x30);
        ExceptionList = local_10;
        return 0;
      }
    }
  }
  ExceptionList = local_10;
  return 0x80004005;
}

