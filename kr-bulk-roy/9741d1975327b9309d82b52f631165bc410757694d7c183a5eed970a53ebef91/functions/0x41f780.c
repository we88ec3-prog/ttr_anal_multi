
undefined4 FUN_0041f780(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  piVar1 = param_1;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar3 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar3 == 0xf4245) {
      param_1 = (int *)(*(int *)(piVar1[1] + 0x20) + 1);
      if (-1 < *(int *)(in_ECX + 0x29c)) {
        cVar2 = FUN_00442fa0(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x29c,&param_1);
        if (cVar2 != '\0') {
          return 1;
        }
      }
    }
  }
  return 0;
}

