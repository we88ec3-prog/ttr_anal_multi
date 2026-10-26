
/* WARNING: Removing unreachable block (ram,0x004d098e) */
/* WARNING: Removing unreachable block (ram,0x004d09a1) */

void FUN_004d0930(float param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d8de;
  local_10 = ExceptionList;
  uVar2 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(float *)(in_ECX + 0xb4) = param_1;
  if (*(int *)(in_ECX + 0xf0) != 0) {
    if ((DAT_00fb7c18 & 1) == 0) {
      DAT_00fb7c18 = DAT_00fb7c18 | 1;
      FUN_004449d0(uVar2);
    }
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    iVar1 = *(int *)(in_ECX + 0xf0);
    param_1 = DAT_00fb90bc * param_1;
    *(undefined4 *)(iVar1 + 0x70) = 1;
    *(float *)(iVar1 + 0x18) = param_1;
  }
  ExceptionList = local_10;
  return;
}

