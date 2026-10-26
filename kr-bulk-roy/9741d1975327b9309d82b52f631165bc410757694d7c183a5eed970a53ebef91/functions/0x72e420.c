
undefined4 * FUN_0072e420(undefined4 *param_1,char *param_2)

{
  undefined4 *puVar1;
  char cVar2;
  char *pcVar3;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00915b53;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  param_1[2] = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[3] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0xf;
  *(undefined1 *)(param_1 + 8) = 0;
  param_1[4] = 0;
  param_1[5] = 1;
  param_1[0xf] = 0;
  param_1[0x10] = 0;
  puVar1 = param_1 + 0x11;
  *param_1 = TiXmlElement::vftable;
  param_1[0x13] = 0xffffffff;
  param_1[0x12] = 0xffffffff;
  param_1[0x14] = 0;
  *puVar1 = TiXmlAttribute::vftable;
  param_1[0x1b] = 0xf;
  param_1[0x1a] = 0;
  *(undefined1 *)(param_1 + 0x16) = 0;
  param_1[0x22] = 0xf;
  param_1[0x21] = 0;
  *(undefined1 *)(param_1 + 0x1d) = 0;
  param_1[0x15] = 0;
  param_1[0x25] = puVar1;
  param_1[0x24] = puVar1;
  local_8 = 1;
  param_1[7] = 0;
  param_1[6] = 0;
  pcVar3 = param_2;
  do {
    cVar2 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar2 != '\0');
  FUN_00402a70(param_2,(int)pcVar3 - (int)(param_2 + 1));
  ExceptionList = local_10;
  return param_1;
}

