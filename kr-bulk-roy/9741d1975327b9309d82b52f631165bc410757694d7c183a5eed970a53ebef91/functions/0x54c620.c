
void FUN_0054c620(void)

{
  float fVar1;
  byte bVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092ee5a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  uVar3 = DAT_00fb9094;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  piVar4 = DAT_00fba7a4;
  iVar5 = DAT_00fb76e8;
  local_8 = 0xffffffff;
  *(undefined4 *)(DAT_00fb76e8 + 0x18) = uVar3;
  *(undefined4 *)(iVar5 + 0xcc) = 0;
  iVar5 = (**(code **)(*piVar4 + 0x20))();
  if (iVar5 != 0) {
    iVar5 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    bVar2 = *(byte *)(iVar5 + 0xb0);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    fVar1 = (float)(&DAT_00fb7c20)[bVar2];
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 2;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    iVar5 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0xcc) = 0;
    *(float *)(iVar5 + 0x20) = fVar1 + 3.1415927;
  }
  ExceptionList = local_10;
  return;
}

