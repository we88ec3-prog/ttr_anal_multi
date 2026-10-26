
void FUN_006565e0(int param_1,undefined1 param_2)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  *(undefined1 *)(iVar2 + 0xa9) = param_2;
  *(int *)(iVar2 + 0xd4) = in_EAX;
  FUN_00654b00(iVar2);
  *(int *)(param_1 + 0x138) = in_EAX;
  _param_2 = (in_EAX * -0xb4 + 800) / 2;
  iVar2 = 0;
  piVar3 = (int *)(param_1 + 200);
  do {
    bVar1 = iVar2 < *(int *)(param_1 + 0x138);
    if (bVar1) {
      FUN_00749a00(_param_2,*(undefined4 *)(*piVar3 + 0xc));
    }
    (**(code **)(*(int *)*piVar3 + 0x94))(bVar1);
    _param_2 = _param_2 + 0xb4;
    iVar2 = iVar2 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar2 < 4);
  return;
}

