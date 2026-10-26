
undefined4 FUN_007f33a0(void)

{
  uint uVar1;
  int *piVar2;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093489a;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  if ((*(int *)(unaff_ESI + 4) != 0) && (*(int *)(unaff_ESI + 8) != 0)) {
    ExceptionList = &local_10;
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 1;
      FUN_00798de0(uVar1);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0(uVar1);
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
    }
    if (*(int *)(unaff_ESI + 0x38) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 8) + 0x30))(*(int **)(unaff_ESI + 8));
      *(undefined4 *)(unaff_ESI + 0x38) = 0;
    }
    if (*(int *)(unaff_ESI + 0x34) != 0) {
      (**(code **)(**(int **)(unaff_ESI + 4) + 0x30))(*(int **)(unaff_ESI + 4));
      *(undefined4 *)(unaff_ESI + 0x34) = 0;
    }
    if ((*(int *)(unaff_ESI + 0x20) != 0) && (*(int *)(unaff_ESI + 0x18) != 0)) {
      (**(code **)(*piVar2 + 0x1a0))(piVar2,*(undefined4 *)(unaff_ESI + 8));
      (**(code **)(*piVar2 + 400))
                (piVar2,0,*(undefined4 *)(unaff_ESI + 4),0,*(undefined4 *)(unaff_ESI + 0x10));
      (**(code **)(*piVar2 + 0x148))
                (piVar2,4,0,*(int *)(unaff_ESI + 0x24) - *(int *)(unaff_ESI + 0x28),
                 *(undefined4 *)(unaff_ESI + 0x18),
                 *(int *)(unaff_ESI + 0x2c) - *(int *)(unaff_ESI + 0x30),
                 *(uint *)(unaff_ESI + 0x20) / 3);
      (**(code **)(*piVar2 + 0x1a0))(piVar2,0);
      (**(code **)(*piVar2 + 400))(piVar2,0,0,0,0);
    }
    *(undefined4 *)(unaff_ESI + 0x18) = 0;
    *(undefined4 *)(unaff_ESI + 0x20) = 0;
    ExceptionList = local_10;
    return 0;
  }
  return 0x80004005;
}

