
undefined4 * FUN_007e9ff0(undefined4 *param_1)

{
  char cVar1;
  char *pcVar2;
  char *unaff_EDI;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_00914778;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  *param_1 = IS3D::CMapParser2::vftable;
  param_1[7] = 0xf;
  param_1[6] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  pcVar2 = unaff_EDI;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(unaff_EDI,(int)pcVar2 - (int)(unaff_EDI + 1));
  param_1[1] = DAT_00fba838;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  ExceptionList = local_10;
  return param_1;
}

