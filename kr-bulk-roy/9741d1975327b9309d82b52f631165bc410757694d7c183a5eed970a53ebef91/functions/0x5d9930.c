
undefined4 FUN_005d9930(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  int in_ECX;
  
  if ((param_1[1] != 0) && (*param_1 == 100)) {
    iVar3 = (**(code **)(*(int *)param_1[1] + 8))();
    if (iVar3 == 0xf4245) {
      uVar1 = *(undefined4 *)(param_1[1] + 0x2d0);
      iVar3 = *(int *)(param_1[1] + 0x20) + 1;
      cVar2 = FUN_0067ce60(*(undefined4 *)(in_ECX + 0x29c),*(undefined4 *)(in_ECX + 0x298),iVar3);
      if (cVar2 != '\0') {
        FUN_0067c960(*(undefined4 *)(in_ECX + 0x29c),*(undefined4 *)(in_ECX + 0x298),uVar1,iVar3);
        return 1;
      }
    }
  }
  return 0;
}

