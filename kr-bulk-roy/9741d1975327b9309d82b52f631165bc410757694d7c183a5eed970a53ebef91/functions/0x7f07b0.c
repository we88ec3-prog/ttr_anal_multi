
void FUN_007f07b0(int param_1)

{
  int *piVar1;
  int in_ECX;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093491a;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if (*(int *)(in_ECX + 0x128) != 0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0x124) + 0xc))
                              (DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    iVar4 = in_ECX + 0x10c;
    uVar2 = 0;
    (**(code **)(*piVar1 + 0x30))(0,iVar4,in_ECX + 0x28);
    FUN_007fc380(param_1,piVar1,uVar2,iVar4);
    *(undefined4 *)(param_1 + 0x28) = *(undefined4 *)(in_ECX + 0x3c);
    FUN_00403040(in_ECX + 0x98,0,0xffffffff);
    if ((DAT_00fb79e8 & 1) == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0();
      _atexit((_func_4879 *)&LAB_00bcd2e0);
      local_8 = 0xffffffff;
    }
    uVar2 = *(undefined4 *)(param_1 + 0x34);
    if (DAT_00fb774c == 3) {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 1;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      pcVar3 = "SHADER-Cell";
    }
    else {
      if ((DAT_00fb79e8 & 1) == 0) {
        DAT_00fb79e8 = DAT_00fb79e8 | 1;
        local_8 = 2;
        FUN_00798de0();
        _atexit((_func_4879 *)&LAB_00bcd2e0);
        local_8 = 0xffffffff;
      }
      pcVar3 = "Fixed";
    }
    FUN_007b31f0(DAT_00fb7744,pcVar3,uVar2);
  }
  ExceptionList = local_10;
  return;
}

