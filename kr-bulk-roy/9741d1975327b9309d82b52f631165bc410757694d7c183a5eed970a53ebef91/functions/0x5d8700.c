
undefined4 FUN_005d8700(int *param_1)

{
  char cVar1;
  int iVar2;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar2 = (**(code **)(*(int *)param_1[1] + 8))();
    if ((iVar2 == 0xf4245) && (param_1[1] != 0)) {
      cVar1 = FUN_005ddfc0();
      if (cVar1 != '\0') {
        FUN_005ddf50();
        return 1;
      }
    }
  }
  return 0;
}

