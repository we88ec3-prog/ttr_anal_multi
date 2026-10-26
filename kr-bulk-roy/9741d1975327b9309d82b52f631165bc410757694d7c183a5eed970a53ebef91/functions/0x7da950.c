
undefined4 * FUN_007da950(undefined4 *param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_009149f3;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 0;
  param_1[1] = IS3D::AnimationLoadEventReciver::vftable;
  *param_1 = IS3D::CMotion::vftable;
  param_1[1] = IS3D::CMotion::vftable;
  FUN_007d8ef0(param_1 + 2);
  param_1[0x2b] = *(undefined4 *)(in_ECX + 0xa4);
  param_1[0x2c] = *(undefined4 *)(in_ECX + 0xa8);
  local_8 = CONCAT31(local_8._1_3_,1);
  param_1[0x32] = 0xf;
  param_1[0x31] = 0;
  *(undefined1 *)(param_1 + 0x2d) = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar2 - (int)(param_2 + 1));
  param_1[0x34] = 0;
  param_1[0x35] = 0;
  ExceptionList = local_10;
  return param_1;
}

