
void FUN_00481110(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int in_EAX;
  int unaff_ESI;
  
  cVar1 = FUN_00481e60(in_EAX,*(int *)(*(int *)(in_EAX + 0xfc) + 0x20) != unaff_ESI);
  if (cVar1 != '\0') {
    if (unaff_ESI == *(int *)(*(int *)(in_EAX + 0xfc) + 0x20)) {
      FUN_00481250(param_1,param_2);
      FUN_00481320();
      return;
    }
    if (unaff_ESI == *(int *)(*(int *)(in_EAX + 0xf8) + 0x20)) {
      FUN_00481180(param_1,param_2);
    }
  }
  return;
}

