
void FUN_0059b8c0(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 == 0xf434e) {
    FUN_006bd720();
  }
  else if (iVar1 == 0xf4350) {
    FUN_00597110(in_ECX);
  }
  else if (iVar1 == 0xf4355) {
    FUN_00597250(in_ECX);
  }
  switch(*(undefined4 *)(param_1 + 0x10)) {
  case 0xf434b:
    FUN_00599cc0();
    return;
  case 0xf434c:
    FUN_0059dc30();
    return;
  case 0xf434f:
    if (((uint)((int *)in_ECX[0x85])[10] >> 8 & 1) != 0) {
      (**(code **)(*(int *)in_ECX[0x85] + 0xd4))();
      return;
    }
    break;
  case 0xf4352:
    (**(code **)(*in_ECX + 0x1a0))(0);
    return;
  case 0xf4353:
    iVar1 = FUN_004adcd0();
    *(undefined1 *)(iVar1 + 0x19) = 0;
    (**(code **)(**(int **)(in_ECX[0x59] + 0x2f8) + 0x94))(0);
    break;
  case 0xf4354:
    (**(code **)(*(int *)in_ECX[0x5e] + 0xd4))();
    return;
  case 0xf4358:
    FUN_0059c690(in_ECX);
    return;
  }
  return;
}

