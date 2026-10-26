
void FUN_008499b0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00906c24;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = gbRenderer::vftable;
  local_8 = 4;
  FUN_0084a470(*(undefined4 *)in_ECX[0x37],(undefined4 *)in_ECX[0x37]);
  FUN_0089120c(in_ECX[0x37],uVar1);
  if (in_ECX[0xd] != 0) {
    FUN_0089120c(in_ECX[0xd],uVar1);
  }
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 0;
  if (in_ECX[9] != 0) {
    FUN_0089120c(in_ECX[9],uVar1);
  }
  in_ECX[9] = 0;
  in_ECX[10] = 0;
  in_ECX[0xb] = 0;
  if (in_ECX[5] != 0) {
    FUN_0089120c(in_ECX[5],uVar1);
  }
  in_ECX[5] = 0;
  in_ECX[6] = 0;
  in_ECX[7] = 0;
  if (in_ECX[1] != 0) {
    FUN_0089120c(in_ECX[1]);
  }
  in_ECX[1] = 0;
  in_ECX[2] = 0;
  in_ECX[3] = 0;
  ExceptionList = local_10;
  return;
}

