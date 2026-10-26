
undefined4 FUN_005d9d30(int *param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar2 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar2 == 0xf4245) {
      cVar1 = FUN_006807d0(*(undefined4 *)(in_ECX + 0x298),*(int *)(param_1[1] + 0x20) + 1);
      if (cVar1 != '\0') {
        return 1;
      }
    }
  }
  return 0;
}

