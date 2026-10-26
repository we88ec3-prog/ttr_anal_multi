
void FUN_005c80f0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091aa93;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::FXUIXMLImageSetParser::vftable;
  local_8 = 1;
  FUN_005c8f90(*(undefined4 *)in_ECX[9],(undefined4 *)in_ECX[9]);
  FUN_0089120c(in_ECX[9],uVar1);
  if (0xf < (uint)in_ECX[6]) {
    FUN_0089120c(in_ECX[1],uVar1);
  }
  in_ECX[6] = 0xf;
  in_ECX[5] = 0;
  *(undefined1 *)(in_ECX + 1) = 0;
  ExceptionList = local_10;
  return;
}

