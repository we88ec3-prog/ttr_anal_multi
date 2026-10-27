
void FUN_007f2520(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0093273e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  iVar4 = *(int *)(in_ECX + 0x88);
  uVar1 = *(undefined4 *)(iVar4 + 0x68);
  uVar2 = *(undefined4 *)(iVar4 + 0x6c);
  uVar3 = *(undefined4 *)(iVar4 + 0x70);
  if ((DAT_00fb79e8 & 1) == 0) {
    DAT_00fb79e8 = DAT_00fb79e8 | 1;
    local_8 = 0;
    FUN_00798de0(DAT_00d61f20 ^ (uint)&stack0xfffffffc);
    _atexit((_func_4879 *)&LAB_00bcd2e0);
  }
  if (DAT_00fb76e4 == 0) {
    iVar4 = 1;
  }
  else {
    iVar4 = FUN_00838860(uVar1,uVar2,uVar3,*(undefined4 *)(in_ECX + 0xb0));
  }
  *(uint *)(in_ECX + 0x80) = (uint)(iVar4 == 0);
  ExceptionList = local_10;
  return;
}

