
void FUN_0054c410(int param_1)

{
  float fVar1;
  byte bVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0092eed4;
  local_10 = ExceptionList;
  uVar6 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00fb8828 & 1) == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 0;
    FUN_0054f850(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  uVar4 = DAT_00fb9094;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 1;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  iVar7 = DAT_00fb76e8;
  uVar3 = DAT_00fb8828 & 1;
  *(undefined4 *)(DAT_00fb76e8 + 0x18) = uVar4;
  *(undefined4 *)(iVar7 + 0xcc) = 0;
  if (uVar3 == 0) {
    DAT_00fb8828 = DAT_00fb8828 | 1;
    local_8 = 2;
    FUN_0054f850(uVar6);
    _atexit((_func_4879 *)&LAB_00bcd580);
  }
  uVar4 = DAT_00fb907c;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 3;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  piVar5 = DAT_00fba7a4;
  iVar7 = DAT_00fb76e8;
  local_8 = 0xffffffff;
  *(undefined4 *)(DAT_00fb76e8 + 0x24) = uVar4;
  *(undefined4 *)(iVar7 + 0xcc) = 0;
  iVar7 = (**(code **)(*piVar5 + 0x20))();
  if (iVar7 != 0) {
    iVar7 = (**(code **)(*DAT_00fba7a4 + 0x20))();
    bVar2 = *(byte *)(iVar7 + 0xb0);
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0();
    }
    fVar1 = (float)(&DAT_00fb7c20)[bVar2];
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 4;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    iVar7 = DAT_00fb76e8;
    *(undefined4 *)(DAT_00fb76e8 + 0xcc) = 0;
    *(float *)(iVar7 + 0x20) = fVar1 + 3.1415927;
  }
  if (*(int *)(param_1 + 0x40) != 0) {
    if ((DAT_00faadd4 & 1) == 0) {
      DAT_00faadd4 = DAT_00faadd4 | 1;
      local_8 = 5;
      FUN_00587480();
      _atexit((_func_4879 *)&LAB_00bcccc0);
      local_8 = 0xffffffff;
    }
    FUN_0058aad0(0xf4358);
  }
  ExceptionList = local_10;
  return;
}

