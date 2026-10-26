
void FUN_004cb130(float param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0090d90e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *(float *)(in_ECX + 0xb4) = param_1;
  if ((*(int *)(in_ECX + 0xf0) != 0) && (*(int *)(*(int *)(in_ECX + 0xf0) + 0x24) != 0)) {
    uVar4 = DAT_00fb7c18;
    if ((DAT_00fb7c18 & 1) == 0) {
      uVar4 = DAT_00fb7c18 | 1;
      DAT_00fb7c18 = uVar4;
      FUN_004449d0(uVar3);
    }
    bVar1 = *(byte *)(in_ECX + 0xb0);
    if ((uVar4 & 1) == 0) {
      DAT_00fb7c18 = uVar4 | 1;
      FUN_004449d0(uVar3);
    }
    FUN_004bb450((&DAT_00fb7c20)[bVar1]);
    if ((DAT_00fb8828 & 1) == 0) {
      DAT_00fb8828 = DAT_00fb8828 | 1;
      local_8 = 0;
      FUN_0054f850();
      _atexit((_func_4879 *)&LAB_00bcd580);
    }
    param_1 = DAT_00fb90bc * param_1;
    iVar2 = *(int *)(*(int *)(in_ECX + 0xf0) + 0x24);
    *(undefined4 *)(iVar2 + 0x70) = 1;
    *(float *)(iVar2 + 0x18) = param_1;
  }
  ExceptionList = local_10;
  return;
}

