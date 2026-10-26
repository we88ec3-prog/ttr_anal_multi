
undefined4 FUN_00872bf0(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  uint uVar3;
  uint uVar4;
  undefined4 local_c [2];
  
  FUN_008445a0(param_1);
  uVar3 = 0;
  uVar4 = 0;
  local_c[0] = 0;
  FUN_006ddcc0(*(undefined4 *)(param_1 + 0x84),local_c,4);
  if (uVar4 != 0) {
    do {
      iVar1 = *in_ECX;
      uVar2 = FUN_00781f20();
      (**(code **)(iVar1 + 0x98))(uVar2);
      uVar3 = uVar3 + 1;
    } while (uVar3 < uVar4);
  }
  return 1;
}

