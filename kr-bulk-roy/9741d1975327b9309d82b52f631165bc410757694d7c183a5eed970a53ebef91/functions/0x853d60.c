
int FUN_00853d60(int param_1,int param_2)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_00911311;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0x18) {
    local_8 = 1;
    if (param_2 != 0) {
      FUN_0062d9b0(in_ECX);
      *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(in_ECX + 0x10);
      *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(in_ECX + 0x14);
    }
    param_2 = param_2 + 0x18;
  }
  ExceptionList = local_10;
  return param_2;
}

