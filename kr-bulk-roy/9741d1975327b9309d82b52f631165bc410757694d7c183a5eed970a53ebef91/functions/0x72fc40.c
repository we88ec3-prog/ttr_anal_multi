
undefined4 * FUN_0072fc40(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915ad9;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0xf;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[4] = 0;
  param_1[5] = 5;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  *param_1 = TiXmlDeclaration::vftable;
  param_1[0x16] = 0xf;
  param_1[0x15] = 0;
  *(undefined1 *)(param_1 + 0x11) = 0;
  param_1[0x1d] = 0xf;
  param_1[0x1c] = 0;
  *(undefined1 *)(param_1 + 0x18) = 0;
  param_1[0x24] = 0xf;
  param_1[0x23] = 0;
  *(undefined1 *)(param_1 + 0x1f) = 0;
  local_8 = 3;
  FUN_00402a70(&DAT_00c1a86c,3);
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar2 - (int)(param_2 + 1));
  FUN_00402a70(&DAT_00bfaf5c,2);
  ExceptionList = local_10;
  return param_1;
}

