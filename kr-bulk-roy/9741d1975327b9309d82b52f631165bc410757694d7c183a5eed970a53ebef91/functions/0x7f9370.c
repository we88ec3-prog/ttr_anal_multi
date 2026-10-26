
void FUN_007f9370(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00937bae;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  local_8 = 0xffffffff;
  piVar1 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
  *(int **)(in_ECX + 4) = piVar1;
  iVar2 = (**(code **)(*piVar1 + 0x68))
                    (piVar1,*(int *)(in_ECX + 0xd8) << 4,0x248,0x42,0,in_ECX + 0xd4,0);
  if (iVar2 < 0) {
    MessageBoxA((HWND)0x0,"CreateVertexBuffer() - FAILED","PSystem",0);
  }
  ExceptionList = local_10;
  return;
}

