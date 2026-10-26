
undefined4 * FUN_00856470(int param_1)

{
  undefined4 *puVar1;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  local_8 = 0xffffffff;
  puStack_c = &LAB_00911229;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  puVar1 = (undefined4 *)FUN_007b2620();
  *puVar1 = *(undefined4 *)(in_ECX + 4);
  puVar1[1] = *(undefined4 *)(in_ECX + 4);
  puVar1[2] = *(undefined4 *)(in_ECX + 4);
  *(undefined2 *)(puVar1 + 0xe) = 0;
  local_8._0_1_ = 1;
  local_8._1_3_ = 0;
  if (puVar1 + 3 != (undefined4 *)0x0) {
    puVar1[8] = 0xf;
    puVar1[7] = 0;
    *(undefined1 *)(puVar1 + 3) = 0;
    FUN_00403040(param_1,0,0xffffffff);
    local_8 = CONCAT31(local_8._1_3_,2);
    FUN_00867d70(puVar1 + 10,param_1 + 0x1c);
  }
  ExceptionList = local_10;
  return puVar1;
}

