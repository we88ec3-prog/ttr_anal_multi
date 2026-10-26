
void FUN_006ddfe0(void)

{
  int *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0090cb60;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  if ((*(byte *)(*(int *)(*in_ECX + 4) + 0x14 + (int)in_ECX) & 2) != 0) {
    FUN_006de0c0();
  }
  ExceptionList = local_10;
  return;
}

