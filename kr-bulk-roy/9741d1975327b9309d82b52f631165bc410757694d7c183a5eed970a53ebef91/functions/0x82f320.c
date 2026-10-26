
undefined4 * FUN_0082f320(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 *in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined1 local_8;
  undefined3 uStack_7;
  
  puStack_c = &LAB_009094b1;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  uStack_7 = 0;
  for (; in_ECX != param_1; in_ECX = in_ECX + 0xe) {
    local_8 = 1;
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *in_ECX;
      FUN_007e8a90(param_2 + 1,in_ECX + 1);
      param_2[5] = in_ECX[5];
      param_2[6] = in_ECX[6];
      param_2[7] = in_ECX[7];
      param_2[8] = in_ECX[8];
      param_2[9] = in_ECX[9];
      param_2[10] = in_ECX[10];
      param_2[0xb] = in_ECX[0xb];
      param_2[0xc] = in_ECX[0xc];
      param_2[0xd] = in_ECX[0xd];
    }
    param_2 = param_2 + 0xe;
  }
  ExceptionList = local_10;
  return param_2;
}

