
undefined4 FUN_0041f800(int *param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  undefined4 local_8;
  
  piVar1 = param_1;
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar3 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar3 == 0xf4245) {
      local_8 = *(undefined4 *)(piVar1[1] + 0x2d0);
      param_1 = (int *)(*(int *)(piVar1[1] + 0x20) + 1);
      if (-1 < *(int *)(in_ECX + 0x29c)) {
        cVar2 = FUN_00442fa0(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x29c,&param_1);
        if (cVar2 != '\0') {
          FUN_00442830(*(undefined4 *)(in_ECX + 0x298),in_ECX + 0x29c,&local_8,&param_1);
          return 1;
        }
      }
    }
  }
  return 0;
}

