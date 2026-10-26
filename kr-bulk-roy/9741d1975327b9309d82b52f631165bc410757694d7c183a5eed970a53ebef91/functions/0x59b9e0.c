
void FUN_0059b9e0(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  FUN_005a44e0(param_1);
  iVar2 = param_1[4];
  switch(iVar2) {
  case 0xf424b:
  case 0xf424c:
  case 0xf424d:
  case 0xf424e:
  case 0xf424f:
  case 0xf4250:
  case 0xf4251:
  case 0xf4252:
  case 0xf4253:
  case 0xf4254:
  case 0xf4255:
    FUN_0059c610();
    return;
  case 0xf4257:
  case 0xf4259:
    if (iVar2 == 0xf4257) {
      FUN_006a4f60();
      return;
    }
    if ((iVar2 == 0xf4259) && ((*(uint *)(in_ECX[0x6d] + 0x28) >> 8 & 1) != 0)) {
      FUN_006a51d0();
      return;
    }
    break;
  case 0xf425e:
    piVar1 = (int *)in_ECX[0x6d];
    if ((((uint)piVar1[10] >> 8 & 1) != 0) && (((uint)piVar1[10] >> 8 & 1) != 0)) {
      (**(code **)(*piVar1 + 0xd4))();
      return;
    }
    break;
  case 0xf4270:
  case 0xf4274:
    FUN_0059c650();
    return;
  case 0xf4271:
    FUN_0059c7c0();
    return;
  case 0xf4272:
    FUN_00668190(in_ECX[0x74]);
    return;
  case 0xf4273:
    FUN_00668190(in_ECX[0x74]);
    return;
  case 0xf4275:
    FUN_0066b440();
    return;
  case 0xf4276:
    (**(code **)(*in_ECX + 0x1a0))(0);
    (**(code **)(*(int *)in_ECX[0x73] + 0xd4))();
    return;
  case 0xf4277:
    (**(code **)(*(int *)in_ECX[0x59] + 0x198))();
    return;
  case 0xf4278:
    FUN_0059d0a0(in_ECX);
    return;
  case 0xf4279:
    FUN_0059c770(in_ECX);
    return;
  case 0xf4280:
    FUN_0059c1b0(in_ECX);
    return;
  case 0xf4281:
    FUN_0059c1b0(in_ECX);
    return;
  case 0xf4282:
    FUN_0059c1b0(in_ECX);
    return;
  case 0xf4286:
    FUN_0059c2f0(in_ECX);
    return;
  case 0xf4287:
    FUN_00699260(in_ECX[0x65]);
    return;
  case 0xf4288:
    FUN_00418d70(*(undefined4 *)(in_ECX[99] + 0x84));
    return;
  case 0xf428e:
    iVar2 = (**(code **)(*param_1 + 4))();
    if (iVar2 != 0x105b9) {
      MessageBoxW((HWND)0x0,L"Wrong EventCasting",L"Error",0);
      return;
    }
    break;
  case 0xf428f:
    FUN_0059dcc0(in_ECX);
    return;
  case 0xf4290:
    FUN_0059dc70(in_ECX);
    return;
  case 0xf42a2:
    FUN_0059cf60();
    return;
  case 0xf42a4:
    FUN_0059d240();
    return;
  case 0xf42a8:
    FUN_0059d2d0(param_1);
    return;
  case 0xf42ab:
    FUN_0059d510(in_ECX);
    return;
  case 0xf42ac:
    FUN_0059d560(in_ECX);
    return;
  case 0xf42b2:
    iVar2 = FUN_005a3810();
    FUN_0059d5f0(*(undefined1 *)(iVar2 + 0x14));
    return;
  case 0xf42b8:
    FUN_0059d790();
    return;
  case 0xf42ba:
    FUN_0059d860();
    return;
  case 0xf42bb:
    FUN_0059d620();
    return;
  case 0xf42bc:
    FUN_0059d6f0();
    return;
  case 0xf42c9:
    FUN_0059dd10(in_ECX);
  }
  return;
}

