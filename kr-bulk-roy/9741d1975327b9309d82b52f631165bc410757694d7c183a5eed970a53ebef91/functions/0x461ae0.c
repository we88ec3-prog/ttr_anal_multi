
uint FUN_00461ae0(int *param_1)

{
  uint in_EAX;
  uint uVar1;
  int in_ECX;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    in_EAX = (**(code **)(*(int *)param_1[1] + 8))();
    if (in_EAX == 0xf4245) {
      uVar1 = FUN_00481e60(*(undefined4 *)(in_ECX + 0x298),*(undefined1 *)(in_ECX + 0x29c));
      return uVar1;
    }
  }
  return in_EAX & 0xffffff00;
}

