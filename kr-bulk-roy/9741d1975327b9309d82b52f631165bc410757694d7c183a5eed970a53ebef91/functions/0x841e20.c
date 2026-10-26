
int FUN_00841e20(int param_1,int param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00904f21;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x78) {
    local_8 = 1;
    if (param_2 != 0) {
      FUN_00839330(param_2,in_ECX);
    }
    param_2 = param_2 + 0x78;
  }
  ExceptionList = local_10;
  return param_2;
}

