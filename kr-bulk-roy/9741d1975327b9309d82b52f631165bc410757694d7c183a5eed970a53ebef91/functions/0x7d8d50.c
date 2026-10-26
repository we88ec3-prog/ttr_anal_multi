
/* WARNING: Removing unreachable block (ram,0x007d8e5c) */

undefined4 * FUN_007d8d50(undefined4 *param_1,char *param_2,int param_3)

{
  char cVar1;
  char *pcVar2;
  int in_ECX;
  char *in_stack_0000001c;
  void *local_10;
  undefined1 *puStack_c;
  undefined4 local_8;
  
  puStack_c = &LAB_0091ca2c;
  local_10 = ExceptionList;
  ExceptionList = &local_10;
  local_8 = 1;
  param_1[1] = IS3D::AnimationLoadEventReciver::vftable;
  *param_1 = IS3D::CSpliteMotion::vftable;
  param_1[1] = IS3D::CSpliteMotion::vftable;
  FUN_007b18b0(param_1 + 2,&param_3);
  local_8._0_1_ = 2;
  FUN_007d8ef0(param_1 + 6);
  local_8._0_1_ = 3;
  param_1[0x2f] = *(undefined4 *)(in_ECX + 0xa4);
  FUN_007da5a0(param_1 + 0x30,in_ECX + 0xa8);
  local_8._0_1_ = 4;
  param_1[0x39] = 0xf;
  param_1[0x38] = 0;
  *(undefined1 *)(param_1 + 0x34) = 0;
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(param_2,(int)pcVar2 - (int)(param_2 + 1));
  local_8 = CONCAT31(local_8._1_3_,5);
  param_1[0x40] = 0xf;
  param_1[0x3f] = 0;
  *(undefined1 *)(param_1 + 0x3b) = 0;
  pcVar2 = in_stack_0000001c;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  FUN_00402a70(in_stack_0000001c,(int)pcVar2 - (int)(in_stack_0000001c + 1));
  param_1[0x42] = 0;
  param_1[0x44] = 0;
  param_1[0x45] = 0;
  param_1[0x46] = 0;
  param_1[0x47] = 0;
  if (param_3 != 0) {
    FUN_007b2b40(param_2);
    FUN_0089120c(param_3);
  }
  ExceptionList = local_10;
  return param_1;
}

