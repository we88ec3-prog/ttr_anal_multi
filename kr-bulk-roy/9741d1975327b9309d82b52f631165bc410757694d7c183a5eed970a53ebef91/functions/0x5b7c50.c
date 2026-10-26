
void FUN_005b7c50(int param_1)

{
  int in_ECX;
  
  FUN_0059b9e0(param_1);
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf425a:
    FUN_005b86d0();
    return;
  case 0xf4263:
    FUN_00596e00(in_ECX,*(undefined4 *)(in_ECX + 0x280));
    return;
  case 0xf4264:
    FUN_00605410();
    return;
  case 0xf4265:
    if (((uint)(*(int **)(in_ECX + 0x280))[10] >> 8 & 1) != 0) {
      (**(code **)(**(int **)(in_ECX + 0x280) + 0xd4))();
      return;
    }
    break;
  case 0xf427a:
    FUN_005b8760(in_ECX);
    return;
  case 0xf427b:
    FUN_005b8bc0(in_ECX);
    return;
  case 0xf427c:
    FUN_005b8cc0(in_ECX);
    return;
  case 0xf427d:
    FUN_005b8d10(in_ECX);
    return;
  case 0xf427e:
    FUN_005b8db0(in_ECX);
    return;
  case 0xf427f:
    FUN_005b8d60(in_ECX);
    return;
  case 0xf4283:
    FUN_005b7280();
    return;
  case 0xf4289:
    FUN_005b90d0(in_ECX);
    return;
  case 0xf428a:
    FUN_005b9120(in_ECX);
    return;
  case 0xf428b:
    FUN_005b9180();
    return;
  case 0xf428c:
    FUN_005b9850(in_ECX);
    return;
  case 0xf428d:
    FUN_005b9b10(in_ECX);
    return;
  case 0xf4298:
    FUN_005ba510(in_ECX);
    return;
  case 0xf42a0:
    FUN_0068e6f0();
    FUN_0042b8c0(*(undefined4 *)(in_ECX + 0x2e0));
    return;
  case 0xf42a9:
    FUN_005baa50(in_ECX);
    return;
  case 0xf42aa:
    FUN_005baaa0(in_ECX);
    return;
  case 0xf42bd:
    FUN_005babc0(in_ECX);
    return;
  case 0xf42be:
    FUN_005bac10(in_ECX);
    return;
  case 0xf42bf:
    FUN_005bade0(in_ECX);
    return;
  case 0xf42c0:
    FUN_005bae80(in_ECX);
    return;
  case 0xf42c1:
    FUN_005baf20(in_ECX);
    return;
  case 0xf42cb:
    FUN_0059e060(in_ECX);
    return;
  case 0xf42cc:
    FUN_005bb230();
    return;
  case 0xf42cd:
    FUN_005bb610();
    return;
  case 0xf42ce:
    FUN_005bb7a0(in_ECX);
    return;
  case 0xf42cf:
    FUN_005bbb70(in_ECX);
    return;
  case 0xf42d0:
    FUN_005bbc00(in_ECX);
    return;
  case 0xf42d2:
    FUN_005bbd40();
    return;
  case 0xf42d4:
    FUN_005bbf90();
    return;
  case 0xf42d6:
    FUN_005bbf20(in_ECX);
  }
  return;
}

