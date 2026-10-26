
undefined4 FUN_0080e940(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 == 0) {
    return 0x80070057;
  }
  if (in_ECX[5] == 0) {
    return 0x80004001;
  }
  (**(code **)(*in_ECX + 0x2c))();
  in_ECX[7] = param_2;
  piVar1 = (int *)FUN_00891268(0x20);
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)0x0;
  }
  else {
    *piVar1 = (int)MoonSound::COGGStream::vftable;
    piVar1[4] = 0;
    piVar1[5] = 0;
    piVar1[6] = 0;
    piVar1[7] = 0;
  }
  iVar2 = FUN_00810710();
  if (iVar2 == 0) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = (int)MoonSound::COGGStream::vftable;
      FUN_0089120c(piVar1);
    }
    return 0x80070057;
  }
  in_ECX[4] = (int)piVar1;
  (**(code **)(*piVar1 + 8))(param_2);
  iVar2 = (**(code **)(*(int *)in_ECX[5] + 4))(piVar1);
  if (iVar2 != 0) {
    (**(code **)(*(int *)in_ECX[5] + 0xc))();
    (**(code **)(*(int *)in_ECX[5] + 0x10))();
    in_ECX[6] = 1;
    FUN_0080e8d0();
    return 0;
  }
  return 0x80004005;
}

