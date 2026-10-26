
void FUN_00490e20(void)

{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009252d6;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 0;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  iVar1 = DAT_00fba7a4;
  if (DAT_00faadf9 != '\0') {
    *(undefined4 *)(DAT_00fba7a4 + 0x7c) = 0;
    *(undefined4 *)(iVar1 + 0x80) = 0;
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) | 0xf;
    ExceptionList = local_10;
    return;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 1;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  if (DAT_00faadf4 == '\0') {
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) & 0xfffffffd;
  }
  else {
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) | 2;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 2;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  if (DAT_00faadf5 == '\0') {
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) & 0xfffffffb;
  }
  else {
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) | 4;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 3;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  if (DAT_00faadf7 == '\0') {
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) & 0xfffffffe;
  }
  else {
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) | 1;
  }
  if ((DAT_00faadd4 & 1) == 0) {
    DAT_00faadd4 = DAT_00faadd4 | 1;
    local_8 = 4;
    FUN_00587480(uVar2);
    _atexit((_func_4879 *)&LAB_00bcccc0);
  }
  if (DAT_00faadf8 == '\0') {
    *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) & 0xfffffff7;
    ExceptionList = local_10;
    return;
  }
  *(uint *)(unaff_ESI + 0xc01c) = *(uint *)(unaff_ESI + 0xc01c) | 8;
  ExceptionList = local_10;
  return;
}

