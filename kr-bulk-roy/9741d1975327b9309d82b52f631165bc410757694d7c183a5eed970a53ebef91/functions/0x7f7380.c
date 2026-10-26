
void FUN_007f7380(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int unaff_ESI;
  undefined4 local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093481e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar2 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  piVar1 = (int *)(unaff_ESI + 8);
  (**(code **)(*piVar2 + 0x6c))(piVar2,*(int *)(unaff_ESI + 4) * 2,0x208,0x65,0,piVar1,0);
  piVar2 = (int *)*piVar1;
  *(undefined4 *)(unaff_ESI + 0x10) = 0;
  *(undefined4 *)(unaff_ESI + 0xc) = 0;
  local_14 = 0;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x2c))(piVar2,0,0,&local_14,0x2000);
    uVar3 = FUN_007ffbc0(0,local_14);
    *(undefined4 *)(unaff_ESI + 0x10) = uVar3;
    (**(code **)(*(int *)*piVar1 + 0x30))((int *)*piVar1);
    *(undefined4 *)(unaff_ESI + 0xc) = 0;
  }
  ExceptionList = local_10;
  return;
}

