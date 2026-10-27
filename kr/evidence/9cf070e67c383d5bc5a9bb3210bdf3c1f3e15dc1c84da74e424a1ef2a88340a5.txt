
void FUN_005b7750(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = param_1;
  FUN_0059b420(param_1);
  switch(*(undefined4 *)(iVar1 + 0x10)) {
  case 0xf42db:
    FUN_005b75e0();
    return;
  case 0xf42dc:
  case 0xf42de:
  case 0xf42e6:
  case 0xf42e7:
  case 0xf42eb:
  case 0xf42ec:
  case 0xf42ed:
  case 0xf42ee:
  case 0xf42ef:
  case 0xf42f0:
  case 0xf42f1:
  case 0xf42f7:
  case 0xf42f8:
  case 0xf42f9:
  case 0xf42fa:
  case 0xf42fb:
  case 0xf42fc:
  case 0xf42fd:
  case 0xf42fe:
  case 0xf42ff:
  case 0xf4300:
  case 0xf4301:
  case 0xf4304:
  case 0xf4307:
  case 0xf4308:
  case 0xf4309:
  case 0xf430a:
  case 0xf430b:
  case 0xf430c:
  case 0xf430d:
  case 0xf430e:
  case 0xf430f:
  case 0xf4310:
  case 0xf4311:
  case 0xf4314:
  case 0xf4315:
  case 0xf4316:
  case 0xf4317:
  case 0xf4318:
  case 0xf4319:
  case 0xf431a:
  case 0xf431b:
  case 0xf431d:
  case 0xf431e:
  case 0xf431f:
  case 0xf4320:
  case 0xf4321:
  case 0xf4322:
  case 0xf4324:
  case 0xf4327:
  case 0xf4328:
  case 0xf4329:
  case 0xf432a:
  case 0xf432b:
  case 0xf432c:
  case 0xf432d:
  case 0xf432e:
  case 0xf432f:
  case 0xf4330:
  case 0xf4331:
  case 0xf4332:
  case 0xf4338:
  case 0xf4339:
  case 0xf433a:
  case 0xf433b:
  case 0xf433c:
  case 0xf433f:
  case 0xf4340:
    break;
  case 0xf42dd:
    FUN_005b8b40();
    return;
  case 0xf42df:
    iVar1 = FUN_0040afc0();
    FUN_005b7300(*(undefined4 *)(iVar1 + 0x14));
    return;
  case 0xf42e0:
    iVar1 = FUN_005c22a0();
    FUN_005b7440(in_ECX,*(undefined1 *)(iVar1 + 0x14));
    return;
  case 0xf42e1:
    FUN_005b7590(in_ECX);
    return;
  case 0xf42e2:
    (**(code **)(**(int **)(in_ECX + 0x240) + 0xd0))();
    return;
  case 0xf42e3:
    (**(code **)(**(int **)(in_ECX + 0x23c) + 0xd0))();
    return;
  case 0xf42e4:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x234));
    return;
  case 0xf42e5:
    FUN_005b71d0(in_ECX);
    return;
  case 0xf42e8:
    FUN_005bc0a0(in_ECX);
    break;
  case 0xf42e9:
    FUN_005bbf70();
    return;
  case 0xf42ea:
    FUN_005b8540();
    return;
  case 0xf42f2:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x268));
    return;
  case 0xf42f3:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x26c));
    return;
  case 0xf42f4:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x270));
    return;
  case 0xf42f5:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x260));
    return;
  case 0xf42f6:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x264));
    return;
  case 0xf4302:
    FUN_005b85a0();
    return;
  case 0xf4303:
    FUN_005b8670();
    return;
  case 0xf4305:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x280));
    return;
  case 0xf4306:
    FUN_005b9080(in_ECX);
    return;
  case 0xf4312:
    FUN_005b8710();
    return;
  case 0xf4313:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x278));
    return;
  case 0xf431c:
    FUN_005b9fa0();
    return;
  case 0xf4323:
    FUN_005b7610();
    return;
  case 0xf4325:
    FUN_005b7670(in_ECX);
    return;
  case 0xf4326:
    FUN_005b76e0(in_ECX);
    return;
  case 0xf4333:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 600));
    return;
  case 0xf4334:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x25c));
    return;
  case 0xf4335:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x29c));
    return;
  case 0xf4336:
    FUN_005bad90(in_ECX);
    return;
  case 0xf4337:
    FUN_005baf70();
    return;
  case 0xf433d:
    param_1 = CONCAT22(0xf3,(undefined2)param_1);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2);
      return;
    }
    break;
  case 0xf433e:
    FUN_005bb5b0();
    return;
  case 0xf4341:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x2a4));
    return;
  case 0xf4342:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x2a8));
    return;
  case 0xf4343:
    param_1 = CONCAT22(0xfc,(undefined2)param_1);
    if (DAT_00fba798 == 0) {
      (**(code **)(*DAT_00fba854 + 0x10))(0,(int)&param_1 + 2,2);
      return;
    }
    break;
  case 0xf4344:
    FUN_005bb770();
    return;
  case 0xf4345:
    FUN_005bbca0();
    return;
  case 0xf4346:
    FUN_005bbdb0();
    return;
  case 0xf4347:
    FUN_005bbe10();
    return;
  case 0xf4348:
    if (((uint)(*(int **)(in_ECX + 0x2d0))[10] >> 8 & 1) == 0) {
      (**(code **)(**(int **)(in_ECX + 0x2d0) + 0xd0))();
      return;
    }
    break;
  case 0xf4349:
    if ((*(uint *)(*(int *)(in_ECX + 0x2d4) + 0x28) >> 8 & 1) == 0) {
      FUN_00596e00(in_ECX,*(int *)(in_ECX + 0x2d4));
      return;
    }
    break;
  default:
    goto switchD_005b7779_default;
  }
switchD_005b7779_default:
  return;
}

