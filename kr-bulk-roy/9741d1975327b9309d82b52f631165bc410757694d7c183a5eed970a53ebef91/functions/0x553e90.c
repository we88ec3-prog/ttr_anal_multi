
undefined4 *
FUN_00553e90(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  undefined4 in_ECX;
  char *in_EDX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00916d08;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[7] = in_ECX;
  param_1[8] = param_3;
  param_1[10] = in_ECX;
  param_1[0xb] = param_3;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[9] = 0;
  param_1[0xc] = param_2;
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = 0;
  param_1[0xf] = param_4;
  param_1[4] = 0;
  param_1[3] = 0;
  param_1[5] = 1;
  param_1[6] = 0;
  local_8 = 0;
  *param_1 = FlyingObject::CFadeObject::vftable;
  param_1[0x11] = 0;
  param_1[0x17] = 0xf;
  param_1[0x16] = 0;
  *(undefined1 *)(param_1 + 0x12) = 0;
  pcVar2 = in_EDX;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_EDX,(int)pcVar2 - (int)(in_EDX + 1));
  param_1[0x19] = 0;
  ExceptionList = local_10;
  return param_1;
}

