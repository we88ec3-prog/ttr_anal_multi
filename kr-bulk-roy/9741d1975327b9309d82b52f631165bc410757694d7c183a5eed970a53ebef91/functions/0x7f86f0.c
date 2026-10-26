
void FUN_007f86f0(void)

{
  uint uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined1 local_d4 [64];
  undefined1 local_94 [64];
  undefined1 local_54 [64];
  uint local_14;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00934718;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  local_14 = uVar1;
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
  (**(code **)(*piVar2 + 0xb4))(piVar2,2,local_d4);
  (**(code **)(*piVar2 + 0xb4))(piVar2,3,local_54);
  D3DXMatrixMultiply(local_94,local_d4,local_54);
  (**(code **)(**(int **)(in_ECX + 4) + 0x98))(*(int **)(in_ECX + 4),"worldViewProj",local_94);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 3;
    FUN_00798de0();
    _atexit((_func_4879 *)&LAB_00bcd2e0);
    local_8 = 0xffffffff;
  }
  FUN_0079be00("SYSTEM_LIGHTMAP");
  puVar3 = (undefined4 *)FUN_0083b440();
  *(undefined4 *)(in_ECX + 0xa8) = *puVar3;
  ExceptionList = local_10;
  __security_check_cookie(local_14 ^ (uint)&stack0xfffffffc);
  return;
}

