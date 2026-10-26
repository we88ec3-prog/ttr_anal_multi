
undefined4 * FUN_0072da90(undefined4 *param_1,char *param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915b8e;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  *param_1 = TiXmlAttribute::vftable;
  param_1[10] = 0xf;
  param_1[9] = 0;
  *(undefined1 *)(param_1 + 5) = 0;
  param_1[0x11] = 0xf;
  param_1[0x10] = 0;
  *(undefined1 *)(param_1 + 0xc) = 0;
  local_8 = 2;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar2 - (int)(param_2 + 1));
  pcVar2 = param_3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_3,(int)pcVar2 - (int)(param_3 + 1));
  param_1[4] = 0;
  param_1[0x14] = 0;
  param_1[0x13] = 0;
  ExceptionList = local_10;
  return param_1;
}

