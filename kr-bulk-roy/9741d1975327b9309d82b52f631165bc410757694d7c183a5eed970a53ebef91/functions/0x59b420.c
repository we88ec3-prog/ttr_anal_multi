
void FUN_0059b420(int param_1)

{
  int *piVar1;
  int in_ECX;
  
  if (*(int *)(param_1 + 0x10) == 0xf431d) {
    FUN_005a59e0();
  }
  else if (*(int *)(param_1 + 0x10) == 0xf4328) {
    FUN_005a57d0();
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf42d8:
    FUN_00599970(in_ECX);
    return;
  case 0xf42dc:
    FUN_0059a3a0();
    return;
  case 0xf42de:
    FUN_00599d00(in_ECX);
    return;
  case 0xf42eb:
    FUN_00599c60();
    return;
  case 0xf42ec:
    FUN_00599c00();
    return;
  case 0xf42ed:
    FUN_0059ab90();
    return;
  case 0xf42ee:
    FUN_0059aad0(param_1);
    return;
  case 0xf42ef:
    FUN_0059a4e0(in_ECX);
    return;
  case 0xf42f7:
    FUN_00599b70();
    return;
  case 0xf42f8:
    FUN_00599ba0();
    return;
  case 0xf42f9:
    FUN_0059c430();
    return;
  case 0xf42fa:
    (**(code **)(**(int **)(in_ECX + 0x1a8) + 0xd0))();
    return;
  case 0xf42fb:
    (**(code **)(**(int **)(in_ECX + 0x1ac) + 0xd0))();
    return;
  case 0xf42fc:
    (**(code **)(**(int **)(in_ECX + 0x1b0) + 0xd0))();
    return;
  case 0xf42fd:
    FUN_0059c460();
    return;
  case 0xf42fe:
    (**(code **)(**(int **)(in_ECX + 0x1b8) + 0xd0))();
    return;
  case 0xf42ff:
    FUN_0059c510();
    return;
  case 0xf4300:
    (**(code **)(**(int **)(in_ECX + 0x1c0) + 0xd0))();
    return;
  case 0xf4301:
    (**(code **)(**(int **)(in_ECX + 0x1c4) + 0xd0))();
    return;
  case 0xf4307:
    FUN_0059c210();
    return;
  case 0xf4308:
    FUN_00699130(*(undefined4 *)(in_ECX + 0x194));
    (**(code **)(**(int **)(in_ECX + 0x194) + 0xd0))();
    return;
  case 0xf4309:
    piVar1 = *(int **)(*(int *)(in_ECX + 0x20c) + 0x118);
    FUN_0045ffa0(piVar1);
    (**(code **)(*piVar1 + 4))();
    return;
  case 0xf430a:
    FUN_0059c400();
    return;
  case 0xf430d:
    if (((uint)(*(int **)(in_ECX + 0x198))[10] >> 8 & 1) == 0) {
      (**(code **)(**(int **)(in_ECX + 0x198) + 0xd0))();
      return;
    }
    break;
  case 0xf430e:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x19c));
    return;
  case 0xf430f:
    FUN_0059c2c0();
    return;
  case 0xf4310:
    FUN_0059c330();
    return;
  case 0xf4311:
    FUN_0059c3a0();
    return;
  case 0xf4314:
    FUN_0059a3d0();
    return;
  case 0xf4315:
    FUN_0059a400();
    return;
  case 0xf4316:
    FUN_0059a490();
    return;
  case 0xf4317:
    FUN_00667c50();
    (**(code **)(**(int **)(in_ECX + 0x1d0) + 0xd0))();
    return;
  case 0xf431e:
    (**(code **)(**(int **)(in_ECX + 0x174) + 0xd0))();
    return;
  case 0xf4320:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x214));
    return;
  case 0xf4324:
    FUN_0059a540(in_ECX);
    return;
  case 0xf4327:
    FUN_0059a5b0(in_ECX);
    return;
  case 0xf432a:
    FUN_0059a620();
    return;
  case 0xf432b:
    FUN_0059a6c0();
    return;
  case 0xf432c:
    FUN_0059a670();
    return;
  case 0xf4330:
    FUN_0059a710();
    return;
  case 0xf4331:
    FUN_0059a770(in_ECX);
    return;
  case 0xf433b:
    FUN_0059db20();
    return;
  case 0xf433c:
    FUN_0059de60();
    return;
  case 0xf433f:
    FUN_0059e030();
    break;
  case 0xf4340:
    FUN_0059dfd0();
    return;
  }
  return;
}

