
undefined4 FUN_008fba60(int param_1)

{
  char *in_EAX;
  int iVar1;
  int in_ECX;
  int in_EDX;
  
  if (((in_EAX == (char *)0x0) || (*in_EAX != '1')) || (param_1 != 0x38)) {
    return 0xfffffffa;
  }
  if (in_EDX == 0) {
    return 0xfffffffe;
  }
  *(undefined4 *)(in_EDX + 0x18) = 0;
  if (*(int *)(in_EDX + 0x20) == 0) {
    *(code **)(in_EDX + 0x20) = FUN_008fb5f0;
    *(undefined4 *)(in_EDX + 0x28) = 0;
  }
  if (*(int *)(in_EDX + 0x24) == 0) {
    *(code **)(in_EDX + 0x24) = FUN_008fb600;
  }
  iVar1 = (**(code **)(in_EDX + 0x20))(*(undefined4 *)(in_EDX + 0x28),1,0x18);
  *(int *)(in_EDX + 0x1c) = iVar1;
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x14) = 0;
    *(undefined4 *)(*(int *)(in_EDX + 0x1c) + 0xc) = 0;
    if (in_ECX < 0) {
      in_ECX = -in_ECX;
      *(undefined4 *)(*(int *)(in_EDX + 0x1c) + 0xc) = 1;
    }
    if (7 < in_ECX - 8U) {
      FUN_008fb070();
      return 0xfffffffe;
    }
    *(int *)(*(int *)(in_EDX + 0x1c) + 0x10) = in_ECX;
    iVar1 = FUN_008fa540(~-(uint)(*(int *)(*(int *)(in_EDX + 0x1c) + 0xc) != 0) & 0x8fb480);
    *(int *)(*(int *)(in_EDX + 0x1c) + 0x14) = iVar1;
    if (iVar1 != 0) {
      FUN_008fb030();
      return 0;
    }
    FUN_008fb070();
  }
  return 0xfffffffc;
}

