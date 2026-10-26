
int FUN_004fd960(int param_1,int param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009105e1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x58) {
    local_8 = 1;
    if (param_2 != 0) {
      FUN_004fd8b0(param_2);
    }
    param_2 = param_2 + 0x58;
  }
  ExceptionList = local_10;
  return param_2;
}

