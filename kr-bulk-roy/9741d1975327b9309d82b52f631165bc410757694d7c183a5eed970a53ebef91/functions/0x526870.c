
undefined2 * FUN_00526870(undefined2 *param_1)

{
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_0091b4a3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  *(undefined4 *)(param_1 + 10) = 7;
  *(undefined4 *)(param_1 + 8) = 0;
  *param_1 = 0;
  FUN_004026e0(in_ECX,0,0xffffffff);
  local_8 = 0;
  FUN_00527300(param_1 + 0xe,in_ECX + 0x1c);
  local_8 = CONCAT31(local_8._1_3_,1);
  FUN_00527570(param_1 + 0x14,in_ECX + 0x28);
  ExceptionList = local_10;
  return param_1;
}

