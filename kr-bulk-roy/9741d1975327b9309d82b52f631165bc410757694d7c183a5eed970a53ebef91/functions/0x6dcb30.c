
void FUN_006dcb30(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0093273e;
  local_10 = ExceptionList;
  uVar3 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  if (*in_ECX < 3) {
    uVar2 = DAT_00fb79e8 & 1;
    *in_ECX = 2;
    if (uVar2 == 0) {
      DAT_00fb79e8 = DAT_00fb79e8 | 1;
      local_8 = 0;
      FUN_00798de0(uVar3);
      _atexit((_func_4879 *)&LAB_00bcd2e0);
    }
    local_8 = 0xffffffff;
    piVar4 = (int *)FUN_0079a5f0(&DAT_00fb76a8);
    iVar5 = D3DXCreateTexture(piVar4,0x200,0x200,1,1,0x15,0,in_ECX + 0x21);
    if (iVar5 == 0) {
      piVar1 = (int *)in_ECX[0x21];
      (**(code **)(*piVar1 + 0x48))(piVar1,0,in_ECX + 0x22);
      (**(code **)(*piVar4 + 0x74))(piVar4,0x200,0x200,0x4b,0,0,1,in_ECX + 0x23,0);
    }
  }
  ExceptionList = local_10;
  return;
}

