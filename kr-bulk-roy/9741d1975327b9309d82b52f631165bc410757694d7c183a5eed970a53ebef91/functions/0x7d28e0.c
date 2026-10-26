
void FUN_007d28e0(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  int in_EDX;
  
  if (*(int *)(param_1 + 0x18) == 0) {
    *(int *)(param_1 + 0x1c) = in_ECX;
    *(int *)(param_1 + 0x20) = in_EDX;
    uVar1 = (&DAT_00fbab80)[in_EDX + in_ECX * 6];
    *(undefined4 *)(param_1 + 0x18) = 1;
    *(undefined4 *)(param_1 + 0x24) = uVar1;
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
    *(undefined4 *)(param_1 + 0x2c) = 0;
  }
  else if (*(int *)(param_1 + 0x34) != 0) {
    *(float *)(param_1 + 0x24) =
         *(float *)(param_1 + 0x24) -
         (*(float *)(param_1 + 0x24) - *(float *)(param_1 + 0x28)) * 0.5;
    return;
  }
  return;
}

