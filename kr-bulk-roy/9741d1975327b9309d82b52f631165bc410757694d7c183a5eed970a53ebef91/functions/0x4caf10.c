
undefined4 FUN_004caf10(void)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00929dfe;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  if ((DAT_00fdf6dc & 1) == 0) {
    DAT_00fdf6dc = DAT_00fdf6dc | 1;
    local_8 = 0;
    FUN_00550820(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bce6b0);
  }
  local_8 = 0xffffffff;
  uVar1 = (uint)*(ushort *)(in_ECX + 1);
  (**(code **)(*in_ECX + 0x4c))(uVar1);
  iVar2 = FUN_00551ff0(uVar1);
  in_ECX[0x3c] = iVar2;
  *(ushort *)((int)in_ECX + 0xe2) = *(ushort *)((int)in_ECX + 0xe2) | 0x8000;
  *(char *)(in_ECX + 0x39) = (char)in_ECX[0x2c];
  (**(code **)(*in_ECX + 0x58))((char)in_ECX[0x2c]);
  ExceptionList = local_10;
  return 1;
}

