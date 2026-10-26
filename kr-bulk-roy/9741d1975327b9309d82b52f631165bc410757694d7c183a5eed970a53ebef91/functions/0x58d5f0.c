
void FUN_0058d5f0(void)

{
  uint uVar1;
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091690b;
  local_10 = ExceptionList;
  uVar1 = DAT_00d61f20 ^ (uint)&stack0xfffffffc;
  ExceptionList = &local_10;
  *in_ECX = FUI::FXUIHistory::vftable;
  local_8 = 3;
  FUN_0058f570(*(undefined4 *)in_ECX[0x12],(undefined4 *)in_ECX[0x12]);
  FUN_0089120c(in_ECX[0x12],uVar1);
  if (7 < (uint)in_ECX[0xf]) {
    FUN_0089120c(in_ECX[10],uVar1);
  }
  in_ECX[0xf] = 7;
  in_ECX[0xe] = 0;
  *(undefined2 *)(in_ECX + 10) = 0;
  local_8 = CONCAT31(local_8._1_3_,4);
  FUN_00737010(*(undefined4 *)in_ECX[7],(undefined4 *)in_ECX[7]);
  FUN_0089120c(in_ECX[7],uVar1);
  in_ECX[1] = FUI::FXUIAttributeHistory::vftable;
  local_8 = 5;
  FUN_0051af60(*(undefined4 *)in_ECX[3],(undefined4 *)in_ECX[3]);
  FUN_0089120c(in_ECX[3]);
  ExceptionList = local_10;
  return;
}

