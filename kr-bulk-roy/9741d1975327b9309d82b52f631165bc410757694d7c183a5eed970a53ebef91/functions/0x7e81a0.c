
void FUN_007e81a0(void)

{
  int in_ECX;
  void *local_14;
  undefined1 *puStack_10;
  undefined4 local_c;
  
  local_c = 0xffffffff;
  puStack_10 = &LAB_00937885;
  local_14 = ExceptionList;
  ExceptionList = &local_14;
  FUN_008380b0(DAT_00d61f20 ^ (uint)&stack0xffffffe0);
  local_c = 0;
  if (*(int *)(in_ECX + 0xc) != 0) {
    FUN_007d81d0();
    FUN_007e8420(in_ECX,in_ECX + 4);
    FUN_007d8810();
  }
  if (*(int *)(in_ECX + 0x1c) != 0) {
    FUN_007d84f0();
    FUN_007e8420(in_ECX,in_ECX + 0x14);
    FUN_007d8810();
  }
  FUN_00837fd0();
  PTR_PTR_00d639fc = *(undefined **)(PTR_PTR_00d639fc + 4);
  ExceptionList = local_14;
  return;
}

