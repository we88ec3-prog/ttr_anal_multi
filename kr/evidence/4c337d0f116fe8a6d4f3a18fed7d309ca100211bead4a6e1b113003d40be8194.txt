
void FUN_0059bd80(int param_1)

{
  int iVar1;
  int in_ECX;
  
  FUN_005a4310(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf4361:
    FUN_0059d4c0(in_ECX);
    return;
  case 0xf4362:
    FUN_0059d470(in_ECX);
    return;
  case 0xf4365:
    FUN_00599a80();
    return;
  case 0xf4368:
    FUN_0059ce80(in_ECX);
    return;
  case 0xf4369:
    FUN_0059cf10(in_ECX);
    return;
  case 0xf436a:
    FUN_005fd250();
    return;
  case 0xf43b0:
    FUN_0059aa60();
    return;
  case 0xf43d1:
    FUN_0059d5b0();
    return;
  case 0xf43d2:
    FUN_0059d930();
    return;
  case 0xf43d3:
    FUN_0059c930(in_ECX);
    return;
  case 0xf43d4:
    FUN_0059c980(in_ECX);
    return;
  case 0xf43df:
    FUN_0059c9e0(in_ECX);
    return;
  case 0xf4403:
    FUN_00650e00(*(undefined4 *)(in_ECX + 0x16c));
    (**(code **)(**(int **)(in_ECX + 0x16c) + 200))();
    (**(code **)(**(int **)(in_ECX + 0x164) + 200))();
    return;
  case 0xf4408:
    FUN_0059dd70(in_ECX);
    return;
  case 0xf440b:
    if (*(int *)(in_ECX + 0x214) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x214) + 200))();
      return;
    }
    break;
  case 0xf4410:
    if ((*(uint *)(*(int *)(in_ECX + 0x1e0) + 0x28) >> 8 & 1) != 0) {
      FUN_0061c660();
      return;
    }
    if ((*(uint *)(*(int *)(in_ECX + 0x1e8) + 0x28) >> 8 & 1) != 0) {
      FUN_00410af0();
      return;
    }
    break;
  case 0xf4415:
    FUN_0059dbe0();
    return;
  case 0xf4416:
    if ((*(uint *)(*(int *)(in_ECX + 0x1e4) + 0x28) >> 8 & 1) != 0) {
      FUN_00615960(*(int *)(in_ECX + 0x1e4));
      return;
    }
    break;
  case 0xf4417:
    if ((*(uint *)(*(int *)(in_ECX + 0x1f0) + 0x28) >> 8 & 1) != 0) {
      FUN_0061a500();
      return;
    }
    break;
  case 0xf4429:
    FUN_0059dab0(in_ECX);
    return;
  case 0xf4432:
    FUN_00615960(*(undefined4 *)(in_ECX + 0x1e4));
    return;
  case 0xf4433:
    if ((*(uint *)(*(int *)(in_ECX + 0x208) + 0x28) >> 8 & 1) != 0) {
      FUN_00406050(*(int *)(in_ECX + 0x208));
      return;
    }
    break;
  case 0xf4436:
    iVar1 = FUN_00412b10();
    FUN_00476b20(*(undefined4 *)(in_ECX + 0x1f8),*(undefined4 *)(iVar1 + 0x14),
                 *(undefined4 *)(iVar1 + 0x18));
    return;
  case 0xf4437:
    iVar1 = FUN_0040afc0();
    FUN_00477b20();
    FUN_004777b0(*(undefined4 *)(in_ECX + 0x1f8),*(undefined4 *)(iVar1 + 0x14));
    return;
  case 0xf4438:
    FUN_0040afc0();
    FUN_00477b20();
    FUN_00477680();
    return;
  case 0xf4439:
    iVar1 = FUN_00412ae0();
    FUN_00477ef0(*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),
                 *(undefined4 *)(iVar1 + 0x1c));
    FUN_00477b20();
  }
  return;
}

